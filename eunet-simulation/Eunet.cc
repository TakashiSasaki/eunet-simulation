/*
 * Eunet.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */
#include <ns3/ipv4-global-routing-helper.h>
#include <ns3/ipv4-static-routing-helper.h>
#include "Eunet.h"
#include "EunetBase.h"
#include "EunetTarumi.h"
#include "EunetJyouhoku.h"
#include "EunetShigenobu.h"
#include "EunetMochida.h"

#define COMPONENT_NAME "Eunet"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

void Eunet::InstallCsmaLink() {
	connectSwitchNodes(EunetBase::INTERNET_ROUTER_INDEX,
			EunetBase::CORE_SWITCH_INDEX, 1000000000, 2);
	EunetTarumi eunet_tarumi(*this);
	eunet_tarumi.connectTier1();
	eunet_tarumi.connectTier2();
	eunet_tarumi.connectTier3();
	eunet_tarumi.connectTier4();
	eunet_tarumi.connectAp();

	EunetJyouhoku eunet_jyouhoku(*this);
	eunet_jyouhoku.connectTier1();
	eunet_jyouhoku.connectTier2();
	eunet_jyouhoku.connectTier3();
	eunet_jyouhoku.connectTier4();
	eunet_jyouhoku.connectTier5();
	eunet_jyouhoku.connectAp1();
	eunet_jyouhoku.connectAp2();

	EunetShigenobu eunet_shigenobu(*this);
	eunet_shigenobu.connectTier1();
	eunet_shigenobu.connectTier2();
	eunet_shigenobu.connectTier3();
	eunet_shigenobu.connectTier4();
	eunet_shigenobu.connectAp();

	EunetMochida eunet_mochida(*this);
	eunet_mochida.connectTier1();
	eunet_mochida.connectTier2();
} //InstallCsmaLink

void Eunet::PopulateGlobalRoutingTables() {
	ns3::Ipv4GlobalRoutingHelper ipv4_global_routing_helper;

	NS_LOG_INFO(COMPONENT_NAME ": Starting to populate global routing table.");
	ipv4_global_routing_helper.PopulateRoutingTables();
	NS_LOG_INFO(COMPONENT_NAME ": Finished the population global routing table.");
}

void Eunet::DumpGlobalRoutingTableAllAt(ns3::Time time_at = ns3::Time(0.0)) {
	ns3::Ipv4GlobalRoutingHelper ipv4_global_routing_helper;
	NS_LOG_INFO(COMPONENT_NAME ": writing ipv4_global_routing_helper.0.txt.");
	ns3::OutputStreamWrapper ipv4_global_routing_help_output_stream_wrapper(
			"ipv4_global_routing_helper.0.txt", std::ios::out);
	ipv4_global_routing_helper.PrintRoutingTableAllAt(time_at,
			&ipv4_global_routing_help_output_stream_wrapper);
}

void Eunet::DumpStaticRoutingTableAllAt(ns3::Time time_at = ns3::Time(0.0)) {
	NS_LOG_INFO(COMPONENT_NAME ": writing ipv4_static_routing_helper.0.txt.");
	ns3::OutputStreamWrapper ipv4_static_routing_helper_output_stream_wrapper(
			"ipv4_static_routing_helper.0.txt", std::ios::out);
	ns3::Ipv4StaticRoutingHelper ipv4_static_routing_helper;
	ipv4_static_routing_helper.PrintRoutingTableAllAt(time_at,
			&ipv4_static_routing_helper_output_stream_wrapper);
}

void Eunet::Attach(TerminalSet & terminal_set, const int i_switch) {
	for (size_t i = 0; i < terminal_set.size(); ++i) {
		NS_LOG_INFO(COMPONENT_NAME": attaching terminal " << i << " to switch " << i_switch);
		SimpleNode & terminal = terminal_set[i];
		assert( 0 == terminal.countNetDevices());
		topology_helper.InstallCsmaLink(terminal, *switch_nodes[i_switch],
				5000000, 2);
	}	// for
}	//Attach

