/*
 * WifiApNode.h
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#ifndef WIFIAPNODE_H_
#define WIFIAPNODE_H_

#include <ns3/wifi-helper.h>
#include <ns3/ap-wifi-mac.h>
#include <ns3/nqos-wifi-mac-helper.h>
#include <ns3/bridge-net-device.h>
#include <ns3/ssid.h>
#include <ns3/boolean.h>
#include <assert.h>
#include "WifiNode.h"

class WifiApNode: public WifiNode {
	ns3::NetDeviceContainer wiredNetDeviceContainer;
	static ns3::NqosWifiMacHelper nqosWifiMacHelper;
	static bool initialized;
public:
	WifiApNode() {
		if (!initialized) {
			nqosWifiMacHelper = ns3::NqosWifiMacHelper::Default();
			nqosWifiMacHelper.SetType("ns3::ApWifiMac", "Ssid",
					ns3::SsidValue(ssid), "BeaconGeneration",
					ns3::BooleanValue(true), "BeaconInterval",
					ns3::TimeValue(ns3::Seconds(2.5)));
		}
	}

	void bridge() {
		ns3::Ptr<ns3::BridgeNetDevice> p_bridge_net_device = ns3::CreateObject<
				ns3::BridgeNetDevice>();
		pNode->AddDevice(p_bridge_net_device);
		for (size_t i = 0; i < wiredNetDeviceContainer.GetN(); ++i) {
			p_bridge_net_device->AddBridgePort(wiredNetDeviceContainer.Get(i));
		}
		for (size_t i = 0; i < wifiNetDeviceContainer.GetN(); ++i) {
			p_bridge_net_device->AddBridgePort(wifiNetDeviceContainer.Get(i));
		}
	}

	void install(ns3::WifiPhyHelper& wifi_phy_helper) {
		assert(wifiNetDeviceContainer.GetN()==0);
		wifiNetDeviceContainer = wifiHelper.Install(wifi_phy_helper,
				nqosWifiMacHelper, pNode);
	}

	ns3::NetDeviceContainer& getWiredNetDeviceContainer() {
		return wiredNetDeviceContainer;
	}

	ns3::Ptr<ns3::NetDevice> getWiredNetDevice(const uint32_t i) {
		return wiredNetDeviceContainer.Get(i);
	}

	virtual ~WifiApNode() {
	}
};

typedef ns3::Ptr<WifiApNode> WifiApNodeP;

class WifiApNodes: public std::vector<WifiApNodeP> {
public:
	WifiApNodes(const size_t n) {
		for (size_t i = 0; i < n; ++i) {
			push_back(new WifiApNode);
		} //for
	} //a constructor

	void bridgeEach() {
		for (size_t i = 0; i < size(); ++i) {
			(*this)[i]->bridge();
		} //for
	} //bridgeEach
};
// WifiApNodes

#endif /* WIFIAPNODE_H_ */
