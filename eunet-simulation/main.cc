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
#include "ns3/object.h"
#include "ns3/uinteger.h"
#include "ns3/traced-value.h"
#include "ns3/trace-source-accessor.h"
#include "TerminalSet.h"
#include "WifiStaNodeSet.h"
#include "Eunet.h"
#include "EunetBase.h"

void MyTrace(ns3::Ptr<const ns3::Packet> oldValue) {
	std::cout << "Traced " << oldValue << std::endl;
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

	ns3::Ipv4AddressHelper ipv4_address_helper;
	ipv4_address_helper.SetBase(ns3::Ipv4Address("133.71.0.0"),
			ns3::Ipv4Mask("255.255.0.0"));
	terminal_sets.assign(ipv4_address_helper);
	wifi_sta_node_sets.assign(ipv4_address_helper);

	//Terminal & internet_terminal = terminal_sets.get(
	//		EunetBase::INTERNET_ROUTER_INDEX, 0);
	Terminal & lan_terminal = terminal_sets.get(6, 0);

	//terminal_sets.installUdpEchoClient(internet_terminal);
	//terminal_sets[5]->installUdpEchoClient(internet_terminal);
	//terminal_sets.installOnOffApplication(internet_terminal);
	//terminal_sets[5]->installOnOffApplication(lan_terminal);
	//terminal_sets[5]->installOnOffApplication(lan_terminal);

	lan_terminal.installOnOffApplication(
			terminal_sets.get(EunetBase::INTERNET_ROUTER_INDEX, 1));
	lan_terminal.getOnOffApplication()->TraceConnectWithoutContext("Tx",
			ns3::MakeCallback(&MyTrace));

	//terminal_sets.installUdpEchoClient(terminal_sets.get(EunetBase::INTERNET_ROUTER_INDEX, 0));
	//terminal_sets.installOnOffApplication(terminal_sets.get(EunetBase::INTERNET_ROUTER_INDEX, 0));

	ns3::Simulator::Stop(ns3::Seconds(10.0));
	NS_LOG_INFO(COMPONENT_NAME": simulator started");
	ns3::Simulator::Run();
	NS_LOG_INFO(COMPONENT_NAME": simulator finished");

	NS_LOG_INFO(COMPONENT_NAME": simulator is being destroyed");
	ns3::Simulator::Destroy();
	NS_LOG_INFO(COMPONENT_NAME": simulator has been destroyed");

	return EXIT_SUCCESS;
} //main
