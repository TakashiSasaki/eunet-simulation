/*
 * SwitchNode.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef SWITCHNODE_H_
#define SWITCHNODE_H_

#include <cassert>
#include <vector>
#include <ns3/bridge-net-device.h>
#include "SimpleNode.h"

class SwitchNode: public SimpleNode {
	ns3::Ptr<ns3::BridgeNetDevice> pBridgeNetDevice;
public:
	SwitchNode(std::string const& description_ = "switch_node") :
			SimpleNode(description_), pBridgeNetDevice(
					ns3::CreateObject<ns3::BridgeNetDevice>()) {
		assert(1==nodeContainer.GetN());
		nodeContainer.Get(0)->AddDevice(pBridgeNetDevice);
		for (size_t i = 0; i < netDeviceContainer.GetN(); ++i) {
			pBridgeNetDevice->AddBridgePort(netDeviceContainer.Get(i));
		} //for
	} //default constructor
	virtual ~SwitchNode() {

	} // destructor
};
//SwitchNode

typedef ns3::Ptr<SwitchNode> SwitchNodeP;

class SwitchNodes: public std::vector<SwitchNodeP> {
public:
	SwitchNodes(size_t n_switch_nodes) {
		for (size_t i = 0; i < n_switch_nodes; ++i) {
			this->push_back(new SwitchNode);
		} //for
	} // a constructor

	SwitchNodeP Create(std::string const& s) {
		this->push_back(new SwitchNode(s));
		return *this->end();
	} // Create
};
//SwitchNodes

#endif /* SWITCHNODE_H_ */
