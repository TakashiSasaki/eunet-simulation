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
#include "WifiApNode.h"
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
			const SimpleNode& internet_router2, const uint64_t bps,
			const uint64_t ms);
	void InstallCsmaLink(SimpleNode& simple_node_1, SimpleNode& simple_node_2,
			const uint64_t bps, const uint64_t ms);

	void InstallCsmaLink(ns3::Ptr<SimpleNode> & p_simple_node_1,
			ns3::Ptr<SimpleNode> & p_simple_node_2, const uint64_t bps,
			const uint64_t ms) {
		InstallCsmaLink(*p_simple_node_1, *p_simple_node_2, bps, ms);
	}

	void InstallCsmaLink(SimpleNode& upstream_switch, WifiApNode& wifi_ap_node,
			const uint64_t bps, const uint64_t ms);

	void InstallCsmaLink(ns3::Ptr<SimpleNode> & p_upstream_switch,
			ns3::Ptr<WifiApNode> & p_wifi_ap_node, const uint64_t bps,
			const uint64_t ms) {
		InstallCsmaLink(*p_upstream_switch, *p_wifi_ap_node, bps, ms);

	}
};

#endif /* TOPOLOGYHELPER_H_ */
