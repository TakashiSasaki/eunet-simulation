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
#include "Terminal.h"

typedef ns3::Ptr<Terminal> TerminalP;

class TerminalSet: public ns3::Object {
	const std::string& description;
	std::vector<ns3::Ptr<Terminal> > terminals;
//
//private:
//	void copyNewSimpleNode(
//			const std::vector<ns3::Ptr<SimpleNode> >::iterator& i);

public:
	TerminalSet(const int number_of_terminals = 15,
			const std::string& description_ = "terminal_set");
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
	TerminalSets(const size_t n_terminal_set) {
		for (size_t i = 0; i < n_terminal_set; ++i) {
			push_back(new TerminalSet);
		} //for
	} // the constructor

	void assign(ns3::Ipv4AddressHelper& ipv4_address_helper) {
		for (size_t i = 0; i < size(); ++i) {
			TerminalSetP x = (*this)[i];
			x->Assign(ipv4_address_helper);
		} //for
	} //Assign

	Terminal const & get(const int i_terminal_set, const int i_terminal) const {
		TerminalSetP const p_terminal_set = (*this)[i_terminal_set];
		Terminal const & terminal = (*p_terminal_set)[i_terminal];
		return terminal;
	} //get

	friend std::ostream& operator<<(std::ostream& ostream,
			TerminalSets const & terminal_sets);
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
