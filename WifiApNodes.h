/*
 * WifiApNodes.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef WIFIAPNODES_H_
#define WIFIAPNODES_H_

class WifiApNodes {
	std::vector<ns3::NodeContainer> wifiApNodes;

	static void initWifiApNode(ns3::NodeContainer &x) {
		x.Create(1);
	}

public:

	ns3::NodeContainer & operator[](const int i) {
		return wifiApNodes[i];
	}

	WifiApNodes(const int number_of_ap_nodes) :
			wifiApNodes(number_of_ap_nodes) {
		std::for_each(wifiApNodes.begin(), wifiApNodes.end(), initWifiApNode);
	}
	virtual ~WifiApNodes() {
	}
};

#endif /* WIFIAPNODES_H_ */
