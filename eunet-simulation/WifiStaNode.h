/*
 * WifiStaNode.h
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#ifndef WIFISTANODE_H_
#define WIFISTANODE_H_

#include <ns3/boolean.h>
#include <ns3/sta-wifi-mac.h>
#include <ns3/nqos-wifi-mac-helper.h>
#include <ns3/wifi-phy.h>
#include <ns3/yans-wifi-helper.h>
#include <ns3/ssid.h>
#include <assert.h>
#include <ns3/mobility-helper.h>
#include "WifiNode.h"

class WifiStaNode: public WifiNode {
	static ns3::NqosWifiMacHelper nqosWifiMacHelper;
	static bool initialized;
public:
	WifiStaNode() {
		if (!initialized) {
			nqosWifiMacHelper = ns3::NqosWifiMacHelper::Default();
			nqosWifiMacHelper.SetType("ns3::StaWifiMac", "Ssid",
					ns3::SsidValue(ssid), "ActiveProbing",
					ns3::BooleanValue(false));
		}
	}

	void install(ns3::WifiPhyHelper& wifi_phy_helper) {
		wifiNetDeviceContainer = wifiHelper.Install(wifi_phy_helper,
				nqosWifiMacHelper, pNode);
	}

	void install(ns3::MobilityHelper& mobility_helper) {
		mobility_helper.Install(pNode);
	}

	void install(ns3::Ipv4AddressHelper& x) {
		WifiNode::install(x);
	}

	virtual ~WifiStaNode() {
	}
};

#endif /* WIFISTANODE_H_ */
