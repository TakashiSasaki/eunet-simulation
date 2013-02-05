#include <cassert>
#include <ns3/log.h>
#include <ns3/uinteger.h>
#include "Terminal.h"

#define COMPONENT_NAME "Terminal"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

Terminal::Terminal(const std::string name) :
		SimpleNode(name) {
	NS_LOG_INFO(COMPONENT_NAME ":creating " << name << " with PacketSink and UdpEchoServer");
	ns3::PacketSinkHelper packet_sink_helper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), discardPort));
	pPacketSink = packet_sink_helper.Install(*this).Get(0);
	pPacketSink->SetStartTime(ns3::Seconds(0.0));
	pPacketSink->SetStopTime(ns3::Seconds(10.0));

	ns3::UdpEchoServerHelper udp_echo_server_helper(echoPort);
	pUdpEchoServer = udp_echo_server_helper.Install(*this).Get(0);
	pUdpEchoServer->SetStartTime(ns3::Seconds(0.0));
	pUdpEchoServer->SetStopTime(ns3::Seconds(10.0));

//		ns3::UdpEchoClientHelper udp_echo_client_helper(*this, echoPort);
//		udpEchoClientApplications.Add(udp_echo_client_helper.Install(*this));
//
//		ns3::OnOffHelper on_off_helper("ns3::UdpSocketFactory",
//				ns3::Address(ns3::InetSocketAddress(*this, discardPort)));
//		onOffApplications.Add(on_off_helper.Install(*this));

} // a constructor

ns3::Ptr<ns3::Application> Terminal::installUdpEchoClient(
		ns3::Ipv4Address const& remote_ipv4_address,
		ns3::UintegerValue packet_size, ns3::UintegerValue max_packets,
		ns3::TimeValue interval, ns3::DataRateValue) {
	NS_LOG_INFO( COMPONENT_NAME ":installUdpEchoClientApplication with packet size " << packet_size.Get()
			<< " to " << remote_ipv4_address
			<< " on " << this->operator ns3::Ipv4Address());
	ns3::UdpEchoClientHelper udp_echo_client_helper(*this, echoPort);
	ns3::ApplicationContainer ac = udp_echo_client_helper.Install(pNode);
	assert(1==ac.GetN());
	ac.Get(0)->SetAttribute("Interval", interval);
	ac.Get(0)->SetAttribute("PacketSize", packet_size);
	ac.Get(0)->SetAttribute("MaxPackets", max_packets);
	ac.Get(0)->SetStartTime(ns3::Seconds(0.0));
	ac.Get(0)->SetStopTime(ns3::Seconds(10.0));
	udpEchoClients.Add(ac);
	const uint32_t n_applications_before = udpEchoClients.GetN();
	udpEchoClients.Add(ac);
	assert(udpEchoClients.GetN()==n_applications_before+1);
	return ac.Get(0);
} // installUdpEchoClientApplication

ns3::Ptr<ns3::Application> Terminal::installOnOffApplication(
		ns3::Ipv4Address remote_ipv4_address, ns3::UintegerValue packet_size,
		ns3::DataRateValue data_rate_value, ns3::UintegerValue max_bytes,
		ns3::StringValue on_time, ns3::StringValue off_time) {
	NS_LOG_INFO(COMPONENT_NAME ":installOnOffApplication with packet size " << packet_size.Get()
			<< " to " << remote_ipv4_address << " on " << this->operator ns3::Ipv4Address());
	ns3::OnOffHelper on_off_helper("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(remote_ipv4_address, discardPort)));
	ns3::ApplicationContainer ac = on_off_helper.Install(pNode);
	assert(1==ac.GetN());
	ac.Get(0)->SetAttribute("DataRate", data_rate_value);
	ac.Get(0)->SetAttribute("PacketSize", packet_size);
	ac.Get(0)->SetAttribute("MaxBytes", max_bytes);
	ac.Get(0)->SetAttribute("OnTime", on_time);
	ac.Get(0)->SetAttribute("OffTime", off_time);
	ac.Get(0)->SetStartTime(ns3::Seconds(0.0));
	ac.Get(0)->SetStopTime(ns3::Seconds(10.0));
	const uint32_t n_applications_before = onOffApplications.GetN();
	onOffApplications.Add(ac);
	assert(onOffApplications.GetN()==n_applications_before+1);
	return ac.Get(0);
} //installOnOffApplication

void Terminal::assign(ns3::Ipv4AddressHelper & ipv4_address_helper) {
	ipv4InterfaceContainer = ipv4_address_helper.Assign(netDeviceContainer);
	NS_LOG_INFO(COMPONENT_NAME ": assigning " << ipv4InterfaceContainer.GetAddress(0,0));
	assert(ipv4InterfaceContainer.GetN()==netDeviceContainer.GetN());
	assert(1==ipv4InterfaceContainer.GetN());
	assert(1==netDeviceContainer.GetN());
} //Assign
