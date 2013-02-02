/*
 * SimpleNode.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include <cassert>
#include <ns3/internet-stack-helper.h>
#include "SimpleNode.h"

ns3::InternetStackHelper SimpleNode::internetStackHelper;

SimpleNode::SimpleNode(const std::string& description_) :
		description(description_) {
	assert(this->nodeContainer.GetN()==0);
	this->nodeContainer.Create(1);
	assert(this->nodeContainer.GetN()==1);
	internetStackHelper.Install(this->operator const ns3::Ptr<ns3::Node>());
	assert(this->nodeContainer.GetN()==1);
}

SimpleNode::operator const ns3::Ptr<ns3::Node>() const {
	assert(this->nodeContainer.GetN()==1);
	return this->nodeContainer.Get(0);
}

SimpleNode::operator const ns3::NetDeviceContainer &() const {
	assert(this->nodeContainer.GetN()==1);
	return this->netDeviceContainer;
}

SimpleNode::operator ns3::NetDeviceContainer &() {
	assert(this->nodeContainer.GetN()==1);
	return this->netDeviceContainer;
}
