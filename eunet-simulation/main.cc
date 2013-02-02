#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ns3/core-module.h>
#include <ns3/network-module.h>
#include <ns3/csma-module.h>
#include <ns3/internet-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
#include <ns3/yans-wifi-helper.h>
#include <ns3/yans-wifi-phy.h>
#include <ns3/nqos-wifi-mac-helper.h>
#include <ns3/ssid.h>
#include <ns3/mobility-helper.h>
//#include <ns3/rectangle.h>
#include "SwitchDevices.h"
#include "CsmaSwitches.h"
#include "WifiApNodes.h"
#include "ApDeviceSets.h"
#include "DefaultWifiPhyHelper.h"
#include "DefaultMobilityHelper.h"
#include "WifiPhys.h"
#include "SimpleNode.h"
#include "TopologyHelper.h"
#include "TerminalSet.h"
#include "WifiStaNodeSet.h"
#include "SimpleOnOffHelper.h"
#include "SwitchNode.h"
#include "Eunet.h"

NS_LOG_COMPONENT_DEFINE("eunet-simulation");

int main(int argc, char** argv) {
	std::cout << "entered in main function." << std::endl;
	ns3::LogComponentEnable("eunet-simulation", ns3::LOG_LEVEL_INFO);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	Eunet eunet;
	std::vector<ns3::Ptr<TerminalSet> > terminal_sets;
	std::vector<ns3::Ptr<WifiStaNodeSet> > wifi_sta_node_sets;
	for (int i = 0; i < 350; ++i) {
		terminal_sets.push_back(new TerminalSet);
	} //for
	for (int j = 5; j <= 348; ++j) {
		if (j == 80 || j == 113 || j == 160 || j == 213 || j == 271 || j == 333)
			continue;
		eunet.Attach(*terminal_sets[j], j);
//		SimpleNode & csma_switch = *csmaSwitches[j];
//		TerminalSet & terminal_set = *terminal_sets[j];
//		for (int i = 0; i < 15; ++i) {
//			SimpleNode & terminal = terminal_set[i];
//			assert( 0 == terminal.countNetDevices());
//			topology_helper.InstallCsmaLink(terminal, csma_switch, 5000000, 2);
//		}	// for
	}	// for
	for (int i = 0; i < 350; ++i) {
		wifi_sta_node_sets.push_back(new WifiStaNodeSet);
	} //for
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		eunet.Attach(*wifi_sta_node_sets[i], i);
//		DefaultWifiPhyHelper* p_default_wifi_phy_helper =
//				new DefaultWifiPhyHelper();
//		wifi_sta_node_sets[i]->install(*p_default_wifi_phy_helper);
//		wifi_ap_nodes[i]->install(*p_default_wifi_phy_helper);
//		delete p_default_wifi_phy_helper;
	}	//for
	//wifi area
	std::vector<DefaultMobilityHelper> mobilities(316);
	for (int i = 0; i <= 315; ++i) {
		//		if (i==0 || i == 298 || i == 299 || i == 306 || i == 315)
		//			continue;
		DefaultMobilityHelper default_mobility_helper;
		wifi_sta_node_sets[i]->install(default_mobility_helper);
	}

// We've got the "hardware" in place.  Now we need to add IP addresses.

	ns3::Ipv4AddressHelper ipv4;
	ipv4.SetBase(ns3::Ipv4Address("133.71.0.0"), ns3::Ipv4Mask("255.255.0.0"));
	for (int i = 5; i <= 348; ++i) {
		if (i == 80 || i == 113 || i == 160 || i == 213 || i == 271 || i == 333)
			continue;
		terminal_sets[i]->Assign(ipv4);
	}	//for

	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		wifi_sta_node_sets[i]->assign(ipv4);
	}	//for

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
