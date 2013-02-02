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
	SwitchNodes csmaSwitches;
	std::vector<ns3::Ptr<WifiApNode> > wifi_ap_nodes;

private:
	void Attach(TerminalSet & terminal_set, const int i_switch) {
		for (size_t i = 0; i < terminal_set.size(); ++i) {
			SimpleNode & terminal = terminal_set[i];
			assert( 0 == terminal.countNetDevices());
			topology_helper.InstallCsmaLink(terminal, *csmaSwitches[i_switch],
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
		return csmaSwitches[i];
	}

	void Attach(TerminalSets& terminal_sets) {
		assert(terminal_sets.size()==csmaSwitches.size());
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
			csmaSwitches(350) {

		for (int i = 0; i < 350; ++i) {
			wifi_ap_nodes.push_back(new WifiApNode);
		} //for

		InstallCsmaLink();

		//apDevices switchDevices setuzoku
		for (int i = 1; i <= 315; ++i) {
			if (i == 298 || i == 299 || i == 306 || i == 315)
				continue;
			wifi_ap_nodes[i]->installBridgeDevice();
		}	//for
	}	// the default constructor
	virtual ~Eunet() {

	}
};

#endif /* EUNET_H_ */
