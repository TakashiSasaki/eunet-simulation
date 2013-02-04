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
public:
	WifiStaNodeSet(const int number_of_wifi_sta_nodes,
			const std::string& wifi_node_prefix) :
			wifiStaNodes(number_of_wifi_sta_nodes) {
		for (size_t i = 0; i < wifiStaNodes.size(); ++i) {
			std::stringstream ss;
			ss << wifi_node_prefix << i << std::ends;
			wifiStaNodes[i] = new WifiStaNode(ss.str());
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
			assert(wifiStaNodes[i]->getMobilityModel() != NULL);
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
//WifiStaNodeSet

typedef ns3::Ptr<WifiStaNodeSet> WifiStaNodeSetP;

class WifiStaNodeSets: public std::vector<ns3::Ptr<WifiStaNodeSet> > {
public:
	WifiStaNodeSets(const size_t n_wifi_sta_node_set,
			std::string const & wifi_sta_node_set_prefix) {
		for (size_t i = 0; i < n_wifi_sta_node_set; ++i) {
			std::stringstream ss;
			ss << wifi_sta_node_set_prefix << i << std::ends;
			WifiStaNodeSetP p_wifi_sta_node_set = new WifiStaNodeSet(15,
					ss.str());
			//RandomWalkMobilityHelper random_walk_mobility_helper;
			//p_wifi_sta_node_set->install(random_walk_mobility_helper);
			ConstantPositionMobilityHelper constant_position_mobility_helper;
			p_wifi_sta_node_set->install(constant_position_mobility_helper);
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
//WifiStaNodeSets

#endif /* WIFISTANODESET_H_ */
