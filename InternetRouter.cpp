/*
 * InternetRouter.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "InternetRouter.h"

InternetRouter::InternetRouter() {
	this->internetrouter.Create(1);
}

ns3::Ptr<ns3::NodeContainer> InternetRouter::get() {
	return this->internetrouter.Get(0);
}

InternetRouter::~InternetRouter() {
	// TODO Auto-generated destructor stub
}

