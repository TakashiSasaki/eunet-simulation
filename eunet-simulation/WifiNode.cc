/*
 * WifiNode.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#include <ns3/wifi-helper.h>
#include <ns3/log.h>
#include "WifiNode.h"

#define COMPONENT_NAME "WifiNode"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

bool WifiNode::initialized = false;

ns3::WifiHelper WifiNode::wifiHelper;

ns3::Ssid WifiNode::ssid;

ns3::InternetStackHelper WifiNode::internetStackHelper;

WifiNode::WifiNode(const std::string& name) {
	if (!initialized) {
		wifiHelper.SetRemoteStationManager("ns3::ArfWifiManager");
	} //if
	pNode = ns3::CreateObject<ns3::Node>();
	NS_LOG_INFO(COMPONENT_NAME ":adding new WifiNode with the name of " << name);
	assert(!ns3::Names::Find<ns3::Node>(name));
	ns3::Names::Add(name, pNode);
	internetStackHelper.SetIpv6StackInstall(false);
	internetStackHelper.Install(pNode);
} // a constructor
