/*
 * EunetBase.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef EUNETBASE_H_
#define EUNETBASE_H_
#include "Eunet.h"

class Eunet;

class EunetBase {
protected:
	Eunet& eunet;
public:
	enum {
		INTERNET_ROUTER_INDEX = 0,
		CORE_SWITCH_INDEX = 1,
		JYOUHOKU_SWITCH_INDEX = 2,
		SHIGENOBU_SWITCH_INDEX = 3,
		TARUMI_SWITCH_INDEX = 4
	};

public:
	EunetBase(Eunet& eunet_) :
			eunet(eunet_) {
	}
	virtual ~EunetBase() {
	}

protected:
	void connectSwitchNodes(const int i_switch_1, const int i_switch_2,
			uint64_t bps, uint64_t ms);
	void connectSwitchAndWifiAp(const int i_switch_node,
			const int i_wifi_ap_node);
};

#endif /* EUNETBASE_H_ */
