#include <vector>
#include <algorithm>
#include "TerminalSet.h"

void TerminalSet::copyNewSimpleNode(
		const std::vector<ns3::Ptr<SimpleNode> >::iterator & i) {
	*i = ns3::Ptr<SimpleNode>(new SimpleNode(this->description));
}

TerminalSet::TerminalSet(const int number_of_terminals,
		const std::string& description_) :
		description(description_), simpleNodes(number_of_terminals) {

	for (unsigned int i = 0; i < simpleNodes.size(); ++i) {
		simpleNodes[i] = new SimpleNode(this->description);
	}
}

const SimpleNode& TerminalSet::operator[](const int index) const {
	return *simpleNodes[index];
}

TerminalSet::operator const ns3::NetDeviceContainer() const {
	ns3::NetDeviceContainer net_device_container;
	for (unsigned int i = 0; i < net_device_container.GetN(); ++i) {
		net_device_container.Add(
				simpleNodes[i]->operator const ns3::NetDeviceContainer &());
	}
	return net_device_container;
}
