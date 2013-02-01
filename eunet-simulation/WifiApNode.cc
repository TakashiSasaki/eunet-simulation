/*
 * WifiApNode.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */
#include <ns3/wifi-helper.h>

#include "WifiApNode.h"
//ns3::WifiHelper WifiApNode::wifiHelper = ns3::WifiHelper::Default();

bool WifiApNode::initialized = false;

ns3::NqosWifiMacHelper WifiApNode::nqosWifiMacHelper;
