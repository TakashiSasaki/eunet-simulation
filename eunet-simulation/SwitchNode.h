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
	SwitchNode(std::string const& name) :
			SimpleNode(name), pBridgeNetDevice(
					ns3::CreateObject<ns3::BridgeNetDevice>()) {
	} //default constructor
	virtual ~SwitchNode() {

	} // destructor

	void bridge() {
		//assert(1==nodeContainer.GetN());
		pNode->AddDevice(pBridgeNetDevice);
		for (size_t i = 0; i < netDeviceContainer.GetN(); ++i) {
			pBridgeNetDevice->AddBridgePort(netDeviceContainer.Get(i));
		} //for
	} //bridge
};
//SwitchNode

typedef ns3::Ptr<SwitchNode> SwitchNodeP;

class SwitchNodes: public std::vector<SwitchNodeP> {
public:
	SwitchNodes(size_t n_switch_nodes,
			std::string const& prefix = "switchNode") {
		for (size_t i = 0; i < n_switch_nodes; ++i) {
			std::stringstream ss;
			ss << prefix << i << std::ends;
			this->push_back(new SwitchNode(ss.str()));
		} //for
	} // a constructor

	SwitchNodeP Create(std::string const& s) {
		this->push_back(new SwitchNode(s));
		return *this->end();
	} // Create

	void bridgeEach() {
		for (size_t i = 0; i < size(); ++i) {
			(*this)[i]->bridge();
		} //for
	} //bridgeEach
};
//SwitchNodes

#endif /* SWITCHNODE_H_ */
