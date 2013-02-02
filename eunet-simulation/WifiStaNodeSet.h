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
#include "DefaultMobilityHelper.h"

class WifiStaNodeSet: public ns3::Object {
	std::vector<ns3::Ptr<WifiStaNode> > wifiStaNodes;
	const std::string& description;
public:
	WifiStaNodeSet(const int number_of_wifi_sta_nodes = 15,
			const std::string& description_ = "wifi_sta_node_set") :
			wifiStaNodes(number_of_wifi_sta_nodes), description(description_) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i] = new WifiStaNode();
		} //for
	} //

	void install(ns3::WifiPhyHelper& wifi_phy_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i]->install(wifi_phy_helper);
		} //for
	} //install

	void install(ns3::MobilityHelper& mobility_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			wifiStaNodes[i]->install(mobility_helper);
		} //for
	} //install

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			ns3::Ptr<WifiStaNode> p_wifi_sta_node = wifiStaNodes[i];
			p_wifi_sta_node->assign(ipv4_address_helper);
		} //for
	} //assign

	virtual ~WifiStaNodeSet() {
	}
};

typedef ns3::Ptr<WifiStaNodeSet> WifiStaNodeSetP;

class WifiStaNodeSets: public std::vector<ns3::Ptr<WifiStaNodeSet> > {
public:
	WifiStaNodeSets(const size_t n_wifi_sta_node_set) {
		for (size_t i = 0; i < n_wifi_sta_node_set; ++i) {
			WifiStaNodeSetP p_wifi_sta_node_set = new WifiStaNodeSet;
			DefaultMobilityHelper default_mobility_helper;
			p_wifi_sta_node_set->install(default_mobility_helper);
			this->push_back(p_wifi_sta_node_set);

		} //for
	} // the constructor

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < size(); ++i) {
			WifiStaNodeSetP x = (*this)[i];
			x->assign(ipv4_address_helper);
		} //for
	} //assign
};

#endif /* WIFISTANODESET_H_ */
