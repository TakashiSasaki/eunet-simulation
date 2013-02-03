/*
 * EunetTarumi.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef EUNETTARUMI_H_
#define EUNETTARUMI_H_
#include "Eunet.h"

class EunetTarumi: private EunetBase {
	Eunet& eunet;
private:
	void connectSwitchNodes(const int i_switch_1, const int i_switch_2,
			uint64_t bps, uint64_t ms) {
		eunet.connectSwitchNodes(i_switch_1, i_switch_2, bps, ms);
	} //connectSwitchNodes

public:
	EunetTarumi(Eunet& eunet_) :
			eunet(eunet_) {
	}
	void connectTier1() {
		connectSwitchNodes(CORE_SWITCH_INDEX, TARUMI_SWITCH_INDEX, 22000000000,
				2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 285, 22000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 316, 8000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 333, 7000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 287, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 288, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 290, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 291, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 295, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 304, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 311, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 312, 2000000000, 2);
		connectSwitchNodes(TARUMI_SWITCH_INDEX, 286, 1000000000, 2);
	} //connectTier1

	virtual ~EunetTarumi() {
	}
};

#endif /* EUNETTARUMI_H_ */
