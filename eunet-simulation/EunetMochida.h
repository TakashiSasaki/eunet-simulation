/*
 * Mochida.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef MOCHIDA_H_
#define MOCHIDA_H_

#include "EunetBase.h"
class EunetMochida: EunetBase {
public:
	EunetMochida(Eunet& eunet) :
			EunetBase(eunet) {
	}
	void connectTier1() {
		connectSwitchNodes(CORE_SWITCH_INDEX, 335, 22000000000, 2); //motida
	} //connectTier1

	void connectTier2() {
		connectSwitchNodes(335, 334, 6000000000, 2);
		connectSwitchNodes(335, 336, 1000000000, 2);
	} //connectTier2

	void connectTier3() {
		connectSwitchNodes(336, 337, 1000000000, 2);
		connectSwitchNodes(336, 338, 1000000000, 2);
		connectSwitchNodes(336, 339, 1000000000, 2);
		connectSwitchNodes(336, 340, 1000000000, 2);
		connectSwitchNodes(336, 342, 1000000000, 2);
	}

	void connectTier4() {
		connectSwitchNodes(340, 341, 1000000000, 2);

	}

	void connectAp() {
		connectSwitchAndWifiAp(339, 300);
		connectSwitchAndWifiAp(338, 301);
		connectSwitchAndWifiAp(338, 302);
		connectSwitchAndWifiAp(335, 303);
		connectSwitchAndWifiAp(335, 304);
		connectSwitchAndWifiAp(335, 305);
		connectSwitchAndWifiAp(335, 307);
		connectSwitchAndWifiAp(335, 308);
		connectSwitchAndWifiAp(342, 309);
		connectSwitchAndWifiAp(338, 310);
		connectSwitchAndWifiAp(339, 311);
		connectSwitchAndWifiAp(339, 312);
		connectSwitchAndWifiAp(342, 314);
	}
	virtual ~EunetMochida() {
	}
};

#endif /* MOCHIDA_H_ */
