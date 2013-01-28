/*
 * WifiStaNodeSets.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef WIFISTANODESETS_H_
#define WIFISTANODESETS_H_

class WifiStaNodeSets {
	std::vector<ns3::NodeContainer> wifiStaNodeSets;

	void initWifiStaNodeSet(ns3::NodeContainer x) {
		x.Create(15);
	}

public:

	ns3::NodeContainer & operator[](const int i) {
		return wifiStaNodeSets[i];
	}

	WifiStaNodeSets(const int number_of_node_sets) :
			wifiStaNodeSets(number_of_node_sets) {
		std::for_each(wifiStaNodeSets.begin(), wifiStaNodeSets.end(),
				initWifiStaNodeSet);
	}

	virtual ~WifiStaNodeSets() {
	}

};

#endif /* WIFISTANODESETS_H_ */
