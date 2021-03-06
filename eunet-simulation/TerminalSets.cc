#include <ns3/ipv4-address.h>
#include "TerminalSet.h"

#define COMPONENT_NAME "TerminalSets"
NS_LOG_COMPONENT_DEFINE(COMPONENT_NAME);

void TerminalSets::installUdpEchoClient(
		ns3::Ipv4Address const & remote_ipv4_address) {
	std::stringstream ss;
	remote_ipv4_address.Print(ss);
	ss << std::ends;
	NS_LOG_INFO(COMPONENT_NAME ":installUdpEchoClient to " << ss.str()
			<< " for " << this->size() << " terminal sets");
	for (size_t i = 0; i < this->size(); ++i) {
		this->operator [](i)->installUdpEchoClient(remote_ipv4_address);
	} //for
} //installUdpEchoClient

void TerminalSets::installOnOffApplication(
		ns3::Ipv4Address const & remote_ipv4_address) {
	std::stringstream ss;
	remote_ipv4_address.Print(ss);
	ss << std::ends;
	NS_LOG_INFO(COMPONENT_NAME ":installOnOffApplication to " << ss.str()
			<< " for " << this->size() << " terminal sets");
	for (size_t i = 0; i < this->size(); ++i) {
		this->operator [](i)->installOnOffApplication(remote_ipv4_address);
	} //for
} //installUdpEchoClient
