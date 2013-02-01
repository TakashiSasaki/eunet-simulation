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
#include "SimpleNode.h"

class TopologyHelper {
public:
	TopologyHelper();
	virtual ~TopologyHelper();
	void InstallCsmaLink(const ns3::Ptr<ns3::Node>& pn1,
			ns3::NetDeviceContainer& ndc1, const ns3::Ptr<ns3::Node>& pn2,
			ns3::NetDeviceContainer& ndc2, const uint64_t bps,
			const uint64_t ms);
	void InstallCsmaLink(const SimpleNode& internet_router1,
			const ns3::Ptr<ns3::Node> &pn2, ns3::NetDeviceContainer& ndc2,
			const uint64_t bps, const uint64_t ms);
	void InstallCsmaLink(const ns3::Ptr<ns3::Node> &p_node_1,
			ns3::NetDeviceContainer& net_device_container_1,
			const SimpleNode& internet_router2,
			const uint64_t bps, const uint64_t ms);
	void InstallCsmaLink(SimpleNode& simple_node_1,
			SimpleNode& simple_node_2, const uint64_t bps, const uint64_t ms);
};

#endif /* TOPOLOGYHELPER_H_ */
