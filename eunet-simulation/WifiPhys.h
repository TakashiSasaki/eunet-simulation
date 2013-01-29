/*
 * WifiPhys.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef WIFIPHYS_H_
#define WIFIPHYS_H_

class WifiPhys {
	std::vector<DefaultWifiPhyHelper> defaultWifiPhyHelpers;
public:
	ns3::WifiPhyHelper& operator[](const int i) {
		return defaultWifiPhyHelpers[i];
	}
	WifiPhys(const int n_default_wifi_phy_helpers) :
			defaultWifiPhyHelpers(n_default_wifi_phy_helpers) {
	}
	virtual ~WifiPhys() {
	}
};

#endif /* WIFIPHYS_H_ */
