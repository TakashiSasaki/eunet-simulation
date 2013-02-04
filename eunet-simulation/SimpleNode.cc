/*
 * SimpleNode.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include <cassert>
#include <iostream>
#include <ns3/internet-stack-helper.h>
#include <ns3/names.h>
#include <ns3/log.h>
#include "SimpleNode.h"

#define COMPONENT_NAME "SimpleNode"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

ns3::InternetStackHelper SimpleNode::internetStackHelper;

SimpleNode::SimpleNode(const std::string& name) {
	NS_LOG_INFO(COMPONENT_NAME ":adding new SimpleNode with the name of " << name);
	pNode = ns3::CreateObject<ns3::Node>();
	ns3::Names::Add(name, pNode);
	internetStackHelper.SetIpv6StackInstall(false);
	internetStackHelper.Install(this->operator const ns3::Ptr<ns3::Node>());
}

SimpleNode::operator const ns3::Ptr<ns3::Node>() const {
	return this->pNode;
}

SimpleNode::operator const ns3::NetDeviceContainer &() const {
	return this->netDeviceContainer;
}

SimpleNode::operator ns3::NetDeviceContainer &() {
	return this->netDeviceContainer;
}
