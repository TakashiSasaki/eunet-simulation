/*
 * CoreSwitch.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "CoreSwitch.h"

CoreSwitch::CoreSwitch(const std::string& description_) :
		description(description_) {
	nodeContainer.Create(1);
}

ns3::Ptr<ns3::Node> CoreSwitch::get() const {
	return nodeContainer.Get(1);
}

CoreSwitch::operator const ns3::NodeContainer&() const {
	return this->get();
}

CoreSwitch::~CoreSwitch() {
	// TODO Auto-generated destructor stub
}

