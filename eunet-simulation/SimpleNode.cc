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
#include "SimpleNode.h"

ns3::InternetStackHelper SimpleNode::internetStackHelper;

SimpleNode::SimpleNode(const std::string& name) {
	std::cerr << "adding new SimpleNode with the name of " << name << std::endl;
	pNode = ns3::CreateObject<ns3::Node>();
	ns3::Names::Add(name, pNode);
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
