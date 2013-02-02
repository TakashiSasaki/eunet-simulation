#include <vector>
#include <algorithm>
#include <cassert>
#include <ns3/net-device-container.h>
#include "TerminalSet.h"

//void TerminalSet::copyNewSimpleNode(
//		const std::vector<ns3::Ptr<SimpleNode> >::iterator & i) {
//	*i = ns3::Ptr<SimpleNode>(new SimpleNode(this->description));
//}

TerminalSet::TerminalSet(const int number_of_terminals,
		const std::string& description_) :
		description(description_), terminals(number_of_terminals) {

	for (unsigned int i = 0; i < terminals.size(); ++i) {
		terminals[i] = ns3::Ptr<Terminal>(new Terminal(this->description));
	} //for
} // default constructor

Terminal const & TerminalSet::operator[](const int i_terminal) const {
	Terminal const & terminal = *terminals[i_terminal];
	ns3::NetDeviceContainer const & net_device_container = terminal;
	assert(1 >= net_device_container.GetN());
	return terminal;
}

Terminal& TerminalSet::operator[](const int i_terminal) {
	Terminal & terminal = *terminals[i_terminal];
	ns3::NetDeviceContainer const & net_device_container = terminal;
	assert(1 >= net_device_container.GetN());
	return terminal;
}
