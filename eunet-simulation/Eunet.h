/*
 * Eunet.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef EUNET_H_
#define EUNET_H_
#include "SwitchNode.h"
#include "WifiStaNodeSet.h"
#include "WifiApNode.h"
#include "DefaultWifiPhyHelper.h"
#include "Terminal.h"
#include "TerminalSet.h"
#include "TopologyHelper.h"

class Eunet {
public:
	enum {
		INTERNET_ROUTER_INDEX = 0,
		CORE_SWITCH_INDEX = 1,
		JYOUHOKU_SWITCH_INDEX = 2,
		SHIGENOBU_SWITCH_INDEX = 3,
		TARUMI_SWITCH_INDEX = 4
	};

private:
	TopologyHelper topology_helper;
	SwitchNodes switch_nodes;
	WifiApNodes wifi_ap_nodes;

private:
	void Attach(TerminalSet & terminal_set, const int i_switch) {
		for (size_t i = 0; i < terminal_set.size(); ++i) {
			SimpleNode & terminal = terminal_set[i];
			assert( 0 == terminal.countNetDevices());
			topology_helper.InstallCsmaLink(terminal, *switch_nodes[i_switch],
					5000000, 2);
		}	// for
	}	//Attach

	void Attach(WifiStaNodeSet & wifi_sta_node_set, const int i_wifi_ap) {
		DefaultWifiPhyHelper* p_default_wifi_phy_helper =
				new DefaultWifiPhyHelper();
		wifi_sta_node_set.install(*p_default_wifi_phy_helper);
		wifi_ap_nodes[i_wifi_ap]->install(*p_default_wifi_phy_helper);
		delete p_default_wifi_phy_helper;
	}	//Attach

	void InstallCsmaLink();

public:
	SwitchNodeP getSwitch(const size_t i) {
		return switch_nodes[i];
	}	//getSwitch

	void Attach(TerminalSets& terminal_sets) {
		assert(terminal_sets.size()==switch_nodes.size());
		for (size_t i = 0; i < terminal_sets.size(); ++i) {
			Attach(*terminal_sets[i], i);
		}	//for
	}	//Attach

	void Attach(WifiStaNodeSets & wifi_sta_node_sets) {
		assert(wifi_ap_nodes.size()==wifi_sta_node_sets.size());
		for (size_t i = 0; i < wifi_sta_node_sets.size(); ++i) {
			Attach(*wifi_sta_node_sets[i], i);
		}	//for
	}	//Attach

	Eunet() :
			switch_nodes(350), wifi_ap_nodes(350) {
		InstallCsmaLink();
		switch_nodes.bridgeEach();
		wifi_ap_nodes.bridgeEach();
	}	// the default constructor
	virtual ~Eunet() {
	}	// destructor
};
//Eunet

#endif /* EUNET_H_ */
