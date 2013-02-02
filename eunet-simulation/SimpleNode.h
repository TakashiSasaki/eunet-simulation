/*
 * InternetRouter.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef INTERNETROUTER_H_
#define INTERNETROUTER_H_

#include <ns3/node-container.h>
#include <ns3/net-device-container.h>
#include <ns3/node.h>
#include <ns3/object.h>
#include <ns3/internet-stack-helper.h>

//internet-edge
class SimpleNode: public ns3::Object {
public:
	ns3::NodeContainer internetrouter;
	ns3::NetDeviceContainer netDeviceContainer;
	const std::string description;
	static ns3::InternetStackHelper internetStackHelper;

public:
	SimpleNode(const std::string& description_ = "simple_node");
	virtual ~SimpleNode();
	operator const ns3::Ptr<ns3::Node>() const;
	operator const ns3::NetDeviceContainer&() const;
	operator ns3::NetDeviceContainer&();
	int countNetDevices() const {
		return netDeviceContainer.GetN();
	}

private:
	SimpleNode(const SimpleNode&);
	SimpleNode& operator=(const SimpleNode&);

};

#endif /* INTERNETROUTER_H_ */
