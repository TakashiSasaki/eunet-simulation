/*
 * InternetRouter.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "SimpleNode.h"

SimpleNode::SimpleNode(const std::string& description_) :
		description(description_) {
	this->internetrouter.Create(1);
}

SimpleNode::operator ns3::Ptr<ns3::Node>() const {
	return this->internetrouter.Get(0);
}

SimpleNode::operator const ns3::NetDeviceContainer &() const {
	return this->netDeviceContainer;
}

SimpleNode::~SimpleNode() {
	// TODO Auto-generated destructor stub
}

