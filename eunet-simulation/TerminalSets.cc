#include <ns3/ipv4-address.h>
#include "TerminalSet.h"

NS_LOG_COMPONENT_DEFINE("TerminalSets");
void TerminalSets::installUdpEchoClient(
		ns3::Ipv4Address const & remote_ipv4_address) {
	std::stringstream ss;
	remote_ipv4_address.Print(ss);
	ss << std::ends;
	NS_LOG_INFO("TerminalSets:installUdpEchoClient to " << ss.str()
			<< " for " << this->size() << " terminal sets");
	for (size_t i = 0; i < this->size(); ++i) {
		this->operator [](i)->installUdpEchoClient(remote_ipv4_address);
	} //for
} //installUdpEchoClient
