/*
 * TerminalSet.h
 *
 *  Created on: Feb 1, 2013
 *      Author: sasaki
 */

#ifndef TERMINALSET_H_
#define TERMINALSET_H_
#include <memory>
#include <vector>
#include <functional>
#include <ns3/net-device-container.h>
#include "SimpleNode.h"

class TerminalSet {
	const std::string& description;
	std::vector<ns3::Ptr<SimpleNode> > simpleNodes;

private:
	void copyNewSimpleNode(
			const std::vector<ns3::Ptr<SimpleNode> >::iterator& i);

public:
	TerminalSet(const int number_of_terminals = 15,
			const std::string& description_ = "terminal_set");
	const SimpleNode& operator[](const int index) const;
	operator const ns3::NetDeviceContainer() const;

	virtual ~TerminalSet() {
	}
}
;

#endif /* TERMINALSET_H_ */
