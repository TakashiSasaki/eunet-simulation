/*
 * WifiStaNodeSet.h
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#ifndef WIFISTANODESET_H_
#define WIFISTANODESET_H_

#include <ns3/ipv4-address-helper.h>
#include <ns3/mobility-helper.h>
#include <ns3/wifi-phy.h>
#include "WifiStaNode.h"

class WifiStaNodeSet: public ns3::Object {
	std::vector<ns3::Ptr<WifiStaNode> > wifiStaNodes;
	const std::string& description;
public:
	WifiStaNodeSet(const int number_of_wifi_sta_nodes = 15,
			const std::string& description_ = "wifi_sta_node_set") :
			wifiStaNodes(number_of_wifi_sta_nodes), description(description_) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i] = new WifiStaNode();
		}
	}

	void install(ns3::WifiPhyHelper& wifi_phy_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i]->install(wifi_phy_helper);
		}
	}

	void install(ns3::MobilityHelper& mobility_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i]->install(mobility_helper);
		}
	}

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			ns3::Ptr<WifiStaNode> p_wifi_sta_node = wifiStaNodes[i];
			p_wifi_sta_node->assign(ipv4_address_helper);
		}
	}

	virtual ~WifiStaNodeSet() {
	}
};

#endif /* WIFISTANODESET_H_ */
