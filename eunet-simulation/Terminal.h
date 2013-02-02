/*
 * Terminal.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <assert.h>
#include <ns3/application-container.h>
#include <ns3/ipv4-address-helper.h>
#include <ns3/packet-sink-helper.h>
#include <ns3/inet-socket-address.h>
#include "SimpleNode.h"

class Terminal: public SimpleNode {
	ns3::Ipv4InterfaceContainer ipv4InterfaceContainer;
	ns3::ApplicationContainer sinkApplicationContainer;
	static const int port = 9;
public:
	Terminal(const std::string description_) :
			SimpleNode(description_) {
		ns3::PacketSinkHelper packet_sink_helper("ns3::UdpSocketFactory",
				ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
		sinkApplicationContainer = packet_sink_helper.Install(
				this->internetrouter);
		sinkApplicationContainer.Start(ns3::Seconds(0.0));
		sinkApplicationContainer.Stop(ns3::Seconds(10.0));
	}

	virtual ~Terminal() {
	}

	void Assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		ipv4InterfaceContainer = ipv4_address_helper.Assign(netDeviceContainer);
		assert(ipv4InterfaceContainer.GetN()==netDeviceContainer.GetN());
		assert(1==ipv4InterfaceContainer.GetN());
		assert(1==netDeviceContainer.GetN());
	}
	ns3::Ipv4Address GetAddress() const {
		return ipv4InterfaceContainer.GetAddress(0, 0);
	}
};

#endif /* TERMINAL_H_ */
