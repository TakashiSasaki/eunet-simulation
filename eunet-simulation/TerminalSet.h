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
#include <cstring>
#include <sstream>
#include <cassert>
#include <ns3/net-device-container.h>
#include <ns3/names.h>
#include <ns3/log.h>
#include "Terminal.h"

typedef ns3::Ptr<Terminal> TerminalP;

class TerminalSet: public ns3::Object {
	std::vector<ns3::Ptr<Terminal> > terminals;

public:
	TerminalSet(const std::string& prefix = "/Names/",
			const int number_of_terminals = 15) :
			terminals(number_of_terminals) {
		for (unsigned int i = 0; i < terminals.size(); ++i) {
			std::stringstream ss;
			ss << prefix << i << std::ends;
			terminals[i] = ns3::Ptr<Terminal>(new Terminal(ss.str()));
		} //for
	} // a constructor

	const Terminal& operator[](const int index) const;
	Terminal& operator[](const int index);
	size_t size() const {
		return terminals.size();
	}
	virtual ~TerminalSet() {
	}
	void Assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < terminals.size(); ++i) {
			terminals[i]->Assign(ipv4_address_helper);
		}
	}

	void installUdpEchoClient(ns3::Ipv4Address const & remote_ipv4_address) {
		for (size_t i = 0; i < terminals.size(); ++i) {
			Terminal & terminal = *terminals[i];
			terminal.installUdpEchoClient(remote_ipv4_address);
		} //for
	} //installUdpEchoClient

	void installOnOffApplication(ns3::Ipv4Address const & remote_ipv4_address) {
		for (size_t i = 0; i < terminals.size(); ++i) {
			Terminal & terminal = *terminals[i];
			terminal.installOnOffApplication(remote_ipv4_address);
		} //for
	} //installUdpEchoClient

	friend std::ostream& operator<<(std::ostream& ostream,
			TerminalSet const & terminal_set);
private:
	TerminalSet(const TerminalSet&);
	TerminalSet operator=(const TerminalSet&);
};
// TerminalSet

inline std::ostream& operator<<(std::ostream& ostream,
		TerminalSet const & terminal_set) {
	for (size_t i = 0; i < terminal_set.terminals.size(); ++i) {
		ostream << i << '\t' << *terminal_set.terminals[i];
	}
	return ostream;
}

typedef ns3::Ptr<TerminalSet> TerminalSetP;

class TerminalSets: public std::vector<ns3::Ptr<TerminalSet> > {
public:
	TerminalSets(const size_t n_terminal_set = 350, std::string const& prefix =
			"terminalSet") {
		for (size_t i = 0; i < n_terminal_set; ++i) {
			std::stringstream ss;
			ss << prefix << i << "_terminal" << std::ends;
			push_back(new TerminalSet(ss.str()));
		} //for
	} // the constructor

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < size(); ++i) {
			TerminalSetP x = (*this)[i];
			x->Assign(ipv4_address_helper);
		} //for
	} //Assign

	Terminal & get(const int i_terminal_set, const int i_terminal) {
		TerminalSetP p_terminal_set = (*this)[i_terminal_set];
		Terminal & terminal = (*p_terminal_set)[i_terminal];
		return terminal;
	} //get

	friend std::ostream& operator<<(std::ostream& ostream,
			TerminalSets const & terminal_sets);

	void installUdpEchoClient(ns3::Ipv4Address const & remote_ipv4_address);
	void installOnOffApplication(ns3::Ipv4Address const & remote_ipv4_address);
};
//TermianlSets

inline std::ostream& operator<<(std::ostream& ostream,
		TerminalSets const & terminal_sets) {
	for (size_t i = 0; i < terminal_sets.size(); ++i) {
		ostream << i << '\t' << terminal_sets[i];
	} //for
	return ostream;
} //operator <<

#endif /* TERMINALSET_H_ */
