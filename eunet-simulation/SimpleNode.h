/*
 * SimpleNode.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include <ns3/node-container.h>
#include <ns3/net-device-container.h>
#include <ns3/node.h>
#include <ns3/object.h>
#include <ns3/internet-stack-helper.h>

class SimpleNode: public ns3::Object {
public:
	ns3::Ptr<ns3::Node> pNode;
	ns3::NetDeviceContainer netDeviceContainer;
	static ns3::InternetStackHelper internetStackHelper;

public:
	SimpleNode(const std::string& description_ = "simple_node");
	virtual ~SimpleNode() {
	}
	operator const ns3::Ptr<ns3::Node>() const;
	operator const ns3::NetDeviceContainer&() const;
	operator ns3::NetDeviceContainer&();
	int countNetDevices() const {
		return netDeviceContainer.GetN();
	} //countNetDevices

private:
	SimpleNode(const SimpleNode&);
	SimpleNode& operator=(const SimpleNode&);

};
//class SimpleNode

#endif /* SIMPLENODE_H_ */
