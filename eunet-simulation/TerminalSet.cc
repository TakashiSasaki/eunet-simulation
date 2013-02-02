#include <vector>
#include <algorithm>
#include <assert.h>
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

Terminal const & TerminalSet::operator[](const int index) const {
	Terminal const & terminal = *terminals[index];
	assert(1 >= terminal.operator const ns3::NetDeviceContainer &().GetN());
	return terminal;
}

Terminal& TerminalSet::operator[](const int index) {
	Terminal & terminal = *terminals[index];
	assert(1 >= terminal.operator const ns3::NetDeviceContainer &().GetN());
	return terminal;
}
