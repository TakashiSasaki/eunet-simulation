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
#include "SimpleOnOffHelper.h"
#include "Eunet.h"

NS_LOG_COMPONENT_DEFINE("eunet-simulation");

int main(int argc, char** argv) {
	std::cout << "entered in main function." << std::endl;
	ns3::LogComponentEnable("eunet-simulation", ns3::LOG_LEVEL_INFO);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	Eunet eunet;

	TerminalSets terminal_sets(350);
	eunet.Attach(terminal_sets);

	WifiStaNodeSets wifi_sta_node_sets(350);
	eunet.Attach(wifi_sta_node_sets);

	ns3::Ipv4AddressHelper ipv4_address_helper;
	ipv4_address_helper.SetBase(ns3::Ipv4Address("133.71.0.0"),
			ns3::Ipv4Mask("255.255.0.0"));
	terminal_sets.assign(ipv4_address_helper);
	wifi_sta_node_sets.assign(ipv4_address_helper);

	SwitchNodeP internet_router = eunet.getSwitch(Eunet::INTERNET_ROUTER_INDEX);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[5])[0]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[5])[1]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[5])[2]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[5])[3]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[5])[4]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[6])[0]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[6])[1]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[6])[2]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[6])[3]);
	SimpleOnOffHelper::install(*internet_router, (*terminal_sets[6])[4]);

	std::cerr << "Populating routing table ..";
	ns3::Ipv4GlobalRoutingHelper().PopulateRoutingTables();
	std::cerr << " done." << std::endl;

	ns3::Simulator::Stop(ns3::Seconds(1.00));
	std::cerr << "Running simulator ..";
	ns3::Simulator::Run();
	std::cerr << " done." << std::endl;

	std::cerr << "Destroying simulator .. ";
	ns3::Simulator::Destroy();
	std::cerr << " done." << std::endl;

	return EXIT_SUCCESS;
} //main
