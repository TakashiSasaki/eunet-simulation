/*
 * WifiNode.h
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#ifndef WIFINODE_H_
#define WIFINODE_H_

#include <cassert>
#include <exception>
#include <ns3/wifi-helper.h>
#include <ns3/ssid.h>
#include <ns3/ipv4-address-helper.h>
#include <ns3/net-device.h>
#include <ns3/net-device-container.h>
#include <ns3/internet-stack-helper.h>
#include <ns3/object.h>
#include <ns3/names.h>

class WifiNode: public ns3::Object {
	static ns3::InternetStackHelper internetStackHelper;
	static bool initialized;
protected:
	static ns3::Ssid ssid;
	static ns3::WifiHelper wifiHelper;
	ns3::Ptr<ns3::Node> pNode;
	ns3::NetDeviceContainer wifiNetDeviceContainer;
	ns3::Ipv4InterfaceContainer wifiIpv4InterfaceContainer;
public:
	WifiNode(const std::string& name) {
		if (!initialized) {
			wifiHelper.SetRemoteStationManager("ns3::ArfWifiManager");
		} //if
		pNode = ns3::CreateObject<ns3::Node>();
		std::cerr << "adding new WifiNode with the name of " << name
				<< std::endl;
		assert(!ns3::Names::Find<ns3::Node>(name));
		ns3::Names::Add(name, pNode);
		internetStackHelper.SetIpv6StackInstall(false);
		internetStackHelper.Install(pNode);
	} // a constructor

	ns3::NetDeviceContainer& getWifiNetDeviceContainer() {
		return wifiNetDeviceContainer;
	}

	ns3::Ptr<ns3::NetDevice> getWifiNetDevice(const uint32_t i) {
		return wifiNetDeviceContainer.Get(i);
	}

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		wifiIpv4InterfaceContainer = ipv4_address_helper.Assign(
				wifiNetDeviceContainer);
	}

	operator const ns3::Ptr<ns3::Node>() const {
		return pNode;
	}

	virtual ~WifiNode() {
	}
private:
	WifiNode(const WifiNode &);
	WifiNode& operator=(const WifiNode &);
};

#endif /* WIFINODE_H_ */
