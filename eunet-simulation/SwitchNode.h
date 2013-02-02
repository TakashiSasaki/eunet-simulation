/*
 * SwitchNode.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef SWITCHNODE_H_
#define SWITCHNODE_H_
#include <assert.h>

class SwitchNode: public SimpleNode {
	ns3::Ptr<ns3::BridgeNetDevice> pBridgeNetDevice;
public:
	SwitchNode(std::string const& description_) :
			SimpleNode(description_), pBridgeNetDevice(
					ns3::CreateObject<ns3::BridgeNetDevice>()) {
		assert(1==nodeContainer.GetN());
		nodeContainer.Get(0)->AddDevice(pBridgeNetDevice);
		for (size_t i = 0; i < netDeviceContainer.GetN(); ++i) {
			pBridgeNetDevice->AddBridgePort(netDeviceContainer.Get(i));
		} //for
	} //default constructor
	virtual ~SwitchNode() {

	}
};
//SwitchNode

#endif /* SWITCHNODE_H_ */
