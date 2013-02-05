#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ns3/core-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
#include <ns3/log.h>
#include <ns3/packet.h>
#include <ns3/object.h>
#include <ns3/uinteger.h>
#include <ns3/traced-value.h>
#include <ns3/trace-source-accessor.h>
#include <ns3/ipv4-address-generator.h>
#include "TerminalSet.h"
#include "WifiStaNodeSet.h"
#include "Eunet.h"
#include "EunetBase.h"

static int tx_count = 0;
static int rx_count = 0;

void countTx(ns3::Ptr<const ns3::Packet> oldValue) {
	++tx_count;
}

void countRx(ns3::Ptr<const ns3::Packet> oldValue, const ns3::Address &) {
	++rx_count;
}

#define COMPONENT_NAME "main"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

int main(int argc, char** argv) {
	ns3::LogComponentEnable("OnOffApplication", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("PacketSink", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("UdpEchoClientApplication", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("UdpEchoServerApplication", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("main", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Eunet", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("TopologyHelper", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("Terminal", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("TerminalSets", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("Ipv4GlobalRouting", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("Simulator", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("BridgeNetDevice", ns3::LOG_LEVEL_WARN);
	ns3::LogComponentEnable("WifiNode", ns3::LOG_LEVEL_ERROR);
	NS_LOG_INFO("main: entered in main function.");
	//ns3::LogComponentEnableAll(ns3::LOG_LEVEL_ALL);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	Eunet eunet;

	TerminalSets terminal_sets(350);
	eunet.attach(terminal_sets);

	WifiStaNodeSets wifi_sta_node_sets(350, "wifiStaNodeSet");
	eunet.attach(wifi_sta_node_sets);

	eunet.bridgeEachSwitchNode();

#if 0
	ns3::Ipv4AddressGenerator::Init(ns3::Ipv4Address("33.71.0.0"),
			ns3::Ipv4Mask("/25"));
	ns3::Ipv4AddressGenerator::NextAddress(ns3::Ipv4Mask("/25")).Print(
			std::cerr);
	ns3::Ipv4AddressGenerator::NextNetwork(ns3::Ipv4Mask("/25")).Print(
			std::cerr);
	//ns3::Ipv4AddressGenerator::Init(
	//		ns3::Ipv4AddressGenerator::NextNetwork(ns3::Ipv4Mask("/25")),
	//		ns3::Ipv4Mask("/25"));
	ns3::Ipv4AddressGenerator::NextAddress(ns3::Ipv4Mask("/25")).Print(
			std::cerr);
#endif

	terminal_sets.assign(ns3::Ipv4Address("133.71.0.0"), ns3::Ipv4Mask("/26"));

	ns3::Ipv4AddressHelper ipv4_address_helper;
	ipv4_address_helper.SetBase(ns3::Ipv4Address("133.71.128.0"),
			ns3::Ipv4Mask("/17"));
	wifi_sta_node_sets.assign(ipv4_address_helper);

	Terminal & internet_terminal = terminal_sets.get(
			EunetBase::INTERNET_ROUTER_INDEX, 0);
	Terminal & lan_terminal = terminal_sets.get(6, 0);

	//terminal_sets.installUdpEchoClient(internet_terminal);
	//terminal_sets[5]->installUdpEchoClient(internet_terminal);
	//terminal_sets.installOnOffApplication(internet_terminal);
	//terminal_sets[5]->installOnOffApplication(lan_terminal);
	//terminal_sets[5]->installOnOffApplication(lan_terminal);

	lan_terminal.installOnOffApplication(internet_terminal);
	lan_terminal.getOnOffApplication()->TraceConnectWithoutContext("Tx",
			ns3::MakeCallback(&countTx));
	internet_terminal.getPacketSink()->TraceConnectWithoutContext("Rx",
			ns3::MakeCallback(&countRx));

	//terminal_sets.installUdpEchoClient(terminal_sets.get(EunetBase::INTERNET_ROUTER_INDEX, 0));
	//terminal_sets.installOnOffApplication(terminal_sets.get(EunetBase::INTERNET_ROUTER_INDEX, 0));

	ns3::Simulator::Stop(ns3::Seconds(10.0));
	NS_LOG_INFO(COMPONENT_NAME": simulator started");
	ns3::Simulator::Run();
	NS_LOG_INFO(COMPONENT_NAME": simulator finished");

	NS_LOG_INFO(COMPONENT_NAME": simulator is being destroyed");
	ns3::Simulator::Destroy();
	NS_LOG_INFO(COMPONENT_NAME": simulator has been destroyed");

	std::cout << "tx=" << tx_count << ", rx=" << rx_count << std::endl;

	return EXIT_SUCCESS;
} //main
