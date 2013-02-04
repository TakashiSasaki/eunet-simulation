#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ns3/core-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
#include "TerminalSet.h"
#include "WifiStaNodeSet.h"
#include "Eunet.h"
#include "EunetBase.h"

NS_LOG_COMPONENT_DEFINE("main");

int main(int argc, char** argv) {
	ns3::LogComponentEnable("OnOffApplication", ns3::LOG_LEVEL_ALL);
	ns3::LogComponentEnable("PacketSink", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("UdpEchoClientApplication", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("UdpEchoServerApplication", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("main", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Terminal", ns3::LOG_LEVEL_DEBUG);
	ns3::LogComponentEnable("Ipv4GlobalRouting", ns3::LOG_LEVEL_INFO);
	ns3::LogComponentEnable("Simulator", ns3::LOG_LEVEL_INFO);
	NS_LOG_INFO("main:""entered in main function.");
	//ns3::LogComponentEnable("WifiNode", ns3::LOG_LEVEL_ALL);
	//ns3::LogComponentEnableAll(ns3::LOG_LEVEL_ALL);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	Eunet eunet;

	TerminalSets terminal_sets(350);
	//std::cerr << terminal_sets;
	eunet.Attach(terminal_sets);

	WifiStaNodeSets wifi_sta_node_sets(350);
	eunet.Attach(wifi_sta_node_sets);

	ns3::Ipv4AddressHelper ipv4_address_helper;
	ipv4_address_helper.SetBase(ns3::Ipv4Address("133.71.0.0"),
			ns3::Ipv4Mask("255.255.0.0"));
	terminal_sets.assign(ipv4_address_helper);
	wifi_sta_node_sets.assign(ipv4_address_helper);

	Terminal & internet_terminal = terminal_sets.get(
			EunetBase::INTERNET_ROUTER_INDEX, 0);

#if 0
	terminal_sets.get(5, 0).installOnOffApplication(internet_terminal);
	terminal_sets.get(5, 1).installOnOffApplication(internet_terminal);
	terminal_sets.get(5, 2).installOnOffApplication(internet_terminal);
	terminal_sets.get(5, 3).installOnOffApplication(internet_terminal);
	terminal_sets.get(5, 4).installOnOffApplication(internet_terminal);
	terminal_sets.get(6, 0).installOnOffApplication(internet_terminal);
	terminal_sets.get(6, 1).installOnOffApplication(internet_terminal);
	terminal_sets.get(6, 2).installOnOffApplication(internet_terminal);
	terminal_sets.get(6, 3).installOnOffApplication(internet_terminal);
	terminal_sets.get(6, 4).installOnOffApplication(internet_terminal);
#endif

	terminal_sets.get(5, 0).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(5, 1).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(5, 2).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(5, 3).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(5, 4).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(6, 0).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(6, 1).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(6, 2).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(6, 3).installUdpEchoClientApplication(internet_terminal);
	terminal_sets.get(6, 4).installUdpEchoClientApplication(internet_terminal);

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

	ns3::Simulator::Stop(ns3::Seconds(1.00));
	NS_LOG_INFO("main:simulator started");
	ns3::Simulator::Run();
	NS_LOG_INFO("main:simulator finished");

	NS_LOG_INFO("main:simulator is being destroyed");
	ns3::Simulator::Destroy();
	NS_LOG_INFO("main:simulator has been destroyed");

	return EXIT_SUCCESS;
} //main
