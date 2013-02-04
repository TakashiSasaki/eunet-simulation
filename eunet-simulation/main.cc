#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ns3/core-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
#include <ns3/log.h>
#include "TerminalSet.h"
#include "WifiStaNodeSet.h"
#include "Eunet.h"
#include "EunetBase.h"

NS_LOG_COMPONENT_DEFINE("main");

int main(int argc, char** argv) {
	ns3::LogComponentEnable("OnOffApplication", ns3::LOG_LEVEL_ALL);
	ns3::LogComponentEnable("PacketSink", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("UdpEchoClientApplication", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("UdpEchoServerApplication", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("main", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Terminal", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("TerminalSets", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Ipv4GlobalRouting", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Simulator", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("BridgeNetDevice", ns3::LOG_LEVEL_WARN);
	ns3::LogComponentEnable("WifiNode", ns3::LOG_LEVEL_ERROR);
	NS_LOG_INFO("main: entered in main function.");
	//ns3::LogComponentEnableAll(ns3::LOG_LEVEL_ALL);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	Eunet eunet;

	TerminalSets terminal_sets(350);
	eunet.Attach(terminal_sets);

	WifiStaNodeSets wifi_sta_node_sets(350, "wifiStaNodeSet");
	eunet.Attach(wifi_sta_node_sets);

	ns3::Ipv4AddressHelper ipv4_address_helper;
	ipv4_address_helper.SetBase(ns3::Ipv4Address("133.71.0.0"),
			ns3::Ipv4Mask("255.255.0.0"));
	terminal_sets.assign(ipv4_address_helper);
	wifi_sta_node_sets.assign(ipv4_address_helper);

	Terminal & internet_terminal = terminal_sets.get(
			EunetBase::INTERNET_ROUTER_INDEX, 0);

	//terminal_sets[5]->installUdpEchoClient(internet_terminal);
	//terminal_sets[6]->installUdpEchoClient(internet_terminal);
	terminal_sets.installUdpEchoClient(internet_terminal);

	ns3::Ipv4GlobalRoutingHelper ipv4_global_routing_helper;

#if 0
	std::cerr << "Populating routing table ..";
	ipv4_global_routing_helper.PopulateRoutingTables();
	std::cerr << " done." << std::endl;
	std::cerr << terminal_sets;

	ns3::OutputStreamWrapper ipv4_global_routing_help_output_stream_wrapper(
			"ipv4_global_routing_helper.0.txt", std::ios::out);
	ipv4_global_routing_helper.PrintRoutingTableAllAt(ns3::Time(0.0),
			&ipv4_global_routing_help_output_stream_wrapper);
#endif

	ns3::OutputStreamWrapper ipv4_static_routing_helper_output_stream_wrapper(
			"ipv4_static_routing_helper.0.txt", std::ios::out);
	ns3::Ipv4StaticRoutingHelper ipv4_static_routing_helper;
	ipv4_static_routing_helper.PrintRoutingTableAllAt(ns3::Time(0.0),
			&ipv4_static_routing_helper_output_stream_wrapper);

	ns3::Simulator::Stop(ns3::Seconds(10.0));
	NS_LOG_INFO("main: simulator started");
	ns3::Simulator::Run();
	NS_LOG_INFO("main: simulator finished");

	NS_LOG_INFO("main: simulator is being destroyed");
	//ns3::Simulator::Destroy();
	NS_LOG_INFO("main: simulator has been destroyed");

	return EXIT_SUCCESS;
} //main
