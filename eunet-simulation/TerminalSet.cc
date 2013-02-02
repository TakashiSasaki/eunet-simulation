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
		description(description_), simpleNodes(number_of_terminals) {

	for (unsigned int i = 0; i < simpleNodes.size(); ++i) {
		simpleNodes[i] = ns3::Ptr<SimpleNode>(
				new SimpleNode(this->description));
	} //for
} // default constructor

SimpleNode const & TerminalSet::operator[](const int index) const {
	SimpleNode const & simple_node = *simpleNodes[index];
	assert(1 >= simple_node.operator const ns3::NetDeviceContainer &().GetN());
	return simple_node;
}

SimpleNode& TerminalSet::operator[](const int index) {
	SimpleNode & simple_node = *simpleNodes[index];
	assert(1 >= simple_node.operator const ns3::NetDeviceContainer &().GetN());
	return simple_node;
}
