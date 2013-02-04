/*
 * Terminal.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <cassert>
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
#include <ns3/uinteger.h>
#include <ns3/data-rate.h>
#include <ns3/nstime.h>
#include <ns3/pointer.h>
#include <ns3/string.h>
#include "SimpleNode.h"

class Terminal: public SimpleNode {
	ns3::Ipv4InterfaceContainer ipv4InterfaceContainer;
	ns3::Ptr<ns3::Application> pPacketSink;
	ns3::Ptr<ns3::Application> pUdpEchoServer;
	ns3::ApplicationContainer udpEchoClients;
	ns3::ApplicationContainer onOffApplications;
	static const int echoPort = 7;
	static const int discardPort = 9;
public:
	Terminal(const std::string name); // a constructor

	ns3::Ptr<ns3::Application> installUdpEchoClient(ns3::Ipv4Address const&,
			ns3::UintegerValue packet_size = 1024,
			ns3::UintegerValue max_packets = 1, ns3::TimeValue interval =
					ns3::Seconds(1),
			ns3::DataRateValue = ns3::DataRate("100kbps")); // installUdpEchoClientApplication

	ns3::Ptr<ns3::Application> installOnOffApplication(
			ns3::Ipv4Address remote_address, ns3::UintegerValue packet_size =
					1024,
			ns3::DataRateValue data_rate_value = ns3::DataRate("1000kbps"),
			ns3::UintegerValue max_bytes = 1000000000,
			ns3::StringValue on_time = ns3::StringValue(
					"ns3::ConstantRandomVariable[Constant=10]"),
			ns3::StringValue off_time = ns3::StringValue(
					"ns3::ConstantRandomVariable[Constant=0]")); //installOnOffApplication

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
		ns3::ApplicationContainer application_container = on_off_helper.Install(
				pNode);
		application_container.Start(ns3::Seconds(0.0));
	} //install

	ns3::Ptr<ns3::Ipv4StaticRouting> getStaticRouting() const {
		ns3::Ipv4StaticRoutingHelper const ipv4_static_routing_helper;
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
