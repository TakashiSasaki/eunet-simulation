/*
 * TopologyHelper.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "TopologyHelper.h"
#include <assert.h>

TopologyHelper::TopologyHelper() {
	// TODO Auto-generated constructor stub

}

TopologyHelper::~TopologyHelper() {
	// TODO Auto-generated destructor stub
}

void TopologyHelper::InstallCsmaLink(const ns3::Ptr<ns3::Node>& pn1,
		ns3::NetDeviceContainer& ndc1, const ns3::Ptr<ns3::Node>& pn2,
		ns3::NetDeviceContainer& ndc2, const uint64_t bps, const uint64_t ms) {
	assert(ndc1.GetN()>=0);
	assert(ndc2.GetN()>=0);
	ns3::CsmaHelper csma_helper;
	csma_helper.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(bps)));
	csma_helper.SetChannelAttribute("Delay",
			ns3::TimeValue(ns3::MilliSeconds(ms)));
	ns3::NetDeviceContainer csma_net_device = csma_helper.Install(
			ns3::NodeContainer(pn1, pn2));
	assert(csma_net_device.GetN() == 2);
	ndc1.Add(csma_net_device.Get(0));
	ndc2.Add(csma_net_device.Get(1));
} //InstallCsmaLink

void TopologyHelper::InstallCsmaLink(SimpleNode& simple_node_1,
		SimpleNode& simple_node_2, const uint64_t bps, const uint64_t ms) {
	this->InstallCsmaLink(simple_node_1,
			(ns3::NetDeviceContainer&) simple_node_1, simple_node_2,
			(ns3::NetDeviceContainer&) simple_node_2, bps, ms);
}

void TopologyHelper::InstallCsmaLink(const SimpleNode& simple_node_1,
		const ns3::Ptr<ns3::Node>& pn2, ns3::NetDeviceContainer& ndc2,
		const uint64_t bps, const uint64_t ms) {
	this->InstallCsmaLink(simple_node_1,
			(ns3::NetDeviceContainer&) simple_node_1, pn2, ndc2, bps, ms);

}

void TopologyHelper::InstallCsmaLink(SimpleNode& upstream_switch,
		WifiApNode& wifi_ap_node, const uint64_t bps, const uint64_t ms) {
	this->InstallCsmaLink(upstream_switch.operator const ns3::Ptr<ns3::Node>(),
			upstream_switch.operator ns3::NetDeviceContainer &(),
			wifi_ap_node.operator const ns3::Ptr<ns3::Node>(),
			wifi_ap_node.getWiredNetDeviceContainer(), bps, ms);
}
