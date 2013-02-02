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
	ns3::ApplicationContainer sinkApplicationContainer;
	static const int port = 9;
public:
	WifiStaNode() {
		if (!initialized) {
			nqosWifiMacHelper = ns3::NqosWifiMacHelper::Default();
			nqosWifiMacHelper.SetType("ns3::StaWifiMac", "Ssid",
					ns3::SsidValue(ssid), "ActiveProbing",
					ns3::BooleanValue(false));
		}
		ns3::PacketSinkHelper packet_sink_helper("ns3::UdpSocketFactory",
				ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
		sinkApplicationContainer = packet_sink_helper.Install(this->pNode);
		sinkApplicationContainer.Start(ns3::Seconds(0.0));
	} // default constructor

	void install(ns3::WifiPhyHelper& wifi_phy_helper) {
		wifiNetDeviceContainer = wifiHelper.Install(wifi_phy_helper,
				nqosWifiMacHelper, pNode);
	} //install

	void install(ns3::MobilityHelper& mobility_helper) {
		mobility_helper.Install(pNode);
	} //install

	virtual ~WifiStaNode() {
	} // destructor
};

#endif /* WIFISTANODE_H_ */
