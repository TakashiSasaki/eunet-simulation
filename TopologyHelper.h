/*
 * TopologyHelper.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef TOPOLOGYHELPER_H_
#define TOPOLOGYHELPER_H_

#include <ns3/net-device-container.h>
#include <ns3/csma-helper.h>
#include <ns3/node-container.h>

class TopologyHelper {
public:
	TopologyHelper();
	virtual ~TopologyHelper();
	void InstallCsmaLink(const ns3::NodeContainer& nc1,
			ns3::NetDeviceContainer& ndc1, const ns3::NodeContainer& nc2,
			ns3::NetDeviceContainer& ndc2, const uint64_t bps,
			const uint64_t ms) {
		ns3::CsmaHelper csma_helper;
		csma_helper.SetChannelAttribute("DataRate",
				ns3::DataRateValue(ns3::DataRate(bps)));
		csma_helper.SetChannelAttribute("Delay",
				ns3::TimeValue(ns3::MilliSeconds(ms)));
		ns3::NetDeviceContainer csma_net_device = csma_helper.Install(
				ns3::NodeContainer(nc1, nc2));
		ndc1.Add(csma_net_device.Get(0));
		ndc2.Add(csma_net_device.Get(1));
	} //InstallCsmaLink
};

#endif /* TOPOLOGYHELPER_H_ */
