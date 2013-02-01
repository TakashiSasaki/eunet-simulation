/*
 * InternetRouter.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "InternetRouter.h"

InternetRouter::InternetRouter(const std::string& description_) :
		description(description_) {
	this->internetrouter.Create(1);
}

InternetRouter::operator ns3::Ptr<ns3::Node>() const {
	return this->internetrouter.Get(0);
}

InternetRouter::operator const ns3::NetDeviceContainer &() const {
	return this->netDeviceContainer;
}

InternetRouter::~InternetRouter() {
	// TODO Auto-generated destructor stub
}

