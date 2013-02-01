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

void TopologyHelper::InstallCsmaLink(const ns3::NodeContainer& nc1,
		ns3::NetDeviceContainer& ndc1, const ns3::NodeContainer& nc2,
		ns3::NetDeviceContainer& ndc2, const uint64_t bps, const uint64_t ms) {
	assert(nc1.GetN()==1);
	assert(nc2.GetN()==1);
	assert(ndc1.GetN()>=0);
	assert(ndc2.GetN()>=0);
	ns3::CsmaHelper csma_helper;
	csma_helper.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(bps)));
	csma_helper.SetChannelAttribute("Delay",
			ns3::TimeValue(ns3::MilliSeconds(ms)));
	ns3::NetDeviceContainer csma_net_device = csma_helper.Install(
			ns3::NodeContainer(nc1, nc2));
	assert(csma_net_device.GetN()>=2);
	assert(nc1.GetN()+nc2.GetN()==csma_net_device.GetN());
	ndc1.Add(csma_net_device.Get(0));
	ndc2.Add(csma_net_device.Get(1));
} //InstallCsmaLink

void TopologyHelper::InstallCsmaLink(const InternetRouter& n1,
		const InternetRouter& n2, const uint64_t bps, const uint64_t ms) {
	this->InstallCsmaLink((ns3::NodeContainer&) n1,
			(ns3::NetDeviceContainer&) n1, (ns3::NodeContainer&) n2,
			(ns3::NetDeviceContainer&) n2, bps, ms);
}

void TopologyHelper::InstallCsmaLink(const InternetRouter& n1,
		const ns3::NodeContainer& nc2, ns3::NetDeviceContainer& ndc2,
		const uint64_t bps, const uint64_t ms) {
	this->InstallCsmaLink((ns3::NodeContainer&) n1,
			(ns3::NetDeviceContainer&) n1, nc2, ndc2, bps, ms);

}
