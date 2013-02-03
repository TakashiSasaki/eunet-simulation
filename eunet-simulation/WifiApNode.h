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
#include <ns3/mobility-helper.h>
#include <ns3/rectangle.h>
#include <ns3/double.h>
#include <ns3/string.h>
#include <assert.h>
#include "WifiNode.h"
#include "DefaultMobilityHelper.h"

class WifiApNode: public WifiNode {
	ns3::NetDeviceContainer wiredNetDeviceContainer;
	static ns3::NqosWifiMacHelper nqosWifiMacHelper;
	static bool initialized;
public:
	WifiApNode(std::string const& name) :
			WifiNode(name) {
		if (!initialized) {
			nqosWifiMacHelper = ns3::NqosWifiMacHelper::Default();
			nqosWifiMacHelper.SetType("ns3::ApWifiMac", "Ssid",
					ns3::SsidValue(ssid), "BeaconGeneration",
					ns3::BooleanValue(true), "BeaconInterval",
					ns3::TimeValue(ns3::Seconds(2.5)));
		} //if
	} // a constructor

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

	void install(ns3::MobilityHelper const & mobility_helper) {
		assert(pNode!=NULL);
		mobility_helper.Install(pNode);
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
	WifiApNodes(const size_t n, std::string const prefix = "WifiApNode_") {
		ConstantPositionMobilityHelper constant_position_mobility_helper;
//		ns3::MobilityHelper mobility_helper;
//		mobility_helper.SetPositionAllocator("ns3::GridPositionAllocator",
//				"MinX", ns3::DoubleValue(0), "MinY", ns3::DoubleValue(0),
//				"DeltaX", ns3::DoubleValue(1.0), "DeltaY",
//				ns3::DoubleValue(1.0), "GridWidth", ns3::UintegerValue(20),
//				"GridHeight", ns3::UintegerValue(20), "LayoutType",
//				ns3::StringValue("RowFirst"));
//		mobility_helper.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
//				"Bounds",
//				ns3::RectangleValue(ns3::Rectangle(-30, 30, -30, 30)));
//		mobility_helper.SetMobilityModel("ns3::ConstantPositionMobilityModel");
		for (size_t i = 0; i < n; ++i) {
			std::stringstream ss;
			ss << prefix << i << std::ends;
			WifiApNode* p_wifi_ap_node = new WifiApNode(ss.str());
			p_wifi_ap_node->install(constant_position_mobility_helper);
			push_back(p_wifi_ap_node);
		} //for
	} //a constructor

	void install(ns3::MobilityHelper const & mobility_helper) {
		for (size_t i = 0; i < size(); ++i) {
			(*this)[i]->install(mobility_helper);
		} //for
	} //install

	void bridgeEach() {
		for (size_t i = 0; i < size(); ++i) {
			(*this)[i]->bridge();
		} //for
	} //bridgeEach
};
// WifiApNodes

#endif /* WIFIAPNODE_H_ */
