/*
 * WifiNode.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#include <ns3/wifi-helper.h>
#include "WifiNode.h"

bool WifiNode::initialized = false;

ns3::WifiHelper WifiNode::wifiHelper;

ns3::Ssid WifiNode::ssid;

ns3::InternetStackHelper WifiNode::internetStackHelper;
