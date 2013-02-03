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
#include <ns3/on-off-helper.h>
#include <ns3/ipv4-routing-helper.h>
#include <ns3/ipv4-static-routing-helper.h>
#include <ns3/ipv4-route.h>
#include <ns3/ipv4-static-routing.h>
#include <ns3/udp-client-server-helper.h>
#include <ns3/udp-echo-helper.h>
#include "SimpleNode.h"

class Terminal: public SimpleNode {
	ns3::Ipv4InterfaceContainer ipv4InterfaceContainer;
	ns3::ApplicationContainer packetSinkApplicationContainer;
	ns3::ApplicationContainer udpEchoServerApplicationContainer;
	static const int echoPort = 7;
	static const int discardPort = 9;
public:
	Terminal(const std::string name) :
			SimpleNode(name) {
		ns3::PacketSinkHelper packet_sink_helper("ns3::UdpSocketFactory",
				ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(),
						discardPort));
		packetSinkApplicationContainer = packet_sink_helper.Install(
				this->pNode);
		packetSinkApplicationContainer.Start(ns3::Seconds(0.0));
		ns3::UdpEchoServerHelper udp_echo_server_helper(echoPort);
		udpEchoServerApplicationContainer = udp_echo_server_helper.Install(
				this->pNode);

		//sinkApplicationContainer.Stop(ns3::Seconds(10.0));
	} // a constructor

	virtual ~Terminal() {
	} // destructor

	void Assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		ipv4InterfaceContainer = ipv4_address_helper.Assign(netDeviceContainer);
		assert(ipv4InterfaceContainer.GetN()==netDeviceContainer.GetN());
		assert(1==ipv4InterfaceContainer.GetN());
		assert(1==netDeviceContainer.GetN());
	} //Assign

	operator ns3::Ipv4Address() const {
		return ipv4InterfaceContainer.GetAddress(0, 0);
	} //operator ns3::Ipv4Address

	void install(ns3::OnOffHelper const & on_off_helper) const {
		//assert(1==nodeContainer.GetN());
		ns3::ApplicationContainer application_container = on_off_helper.Install(
				pNode);
		application_container.Start(ns3::Seconds(0.0));
	} //install

	ns3::Ptr<ns3::Ipv4StaticRouting> getStaticRouting() const {
		ns3::Ipv4StaticRoutingHelper const ipv4_static_routing_helper;
		//assert(1 == nodeContainer.GetN());
		ns3::Ptr<ns3::Ipv4> const p_ipv4 = pNode->GetObject<ns3::Ipv4>();
		return ipv4_static_routing_helper.GetStaticRouting(p_ipv4);
	} //getStaticRouting

	friend std::ostream& operator<<(std::ostream& ostream,
			Terminal const & terminal);
};
// class Terminal

inline std::ostream& operator<<(std::ostream& ostream,
		Terminal const & terminal) {
	ostream << terminal.operator ns3::Ipv4Address()
			<< terminal.getStaticRouting();
	return ostream;
} //operator <<

#endif /* TERMINAL_H_ */
