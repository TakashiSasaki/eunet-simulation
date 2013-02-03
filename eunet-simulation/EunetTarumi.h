/*
 * EunetTarumi.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef EUNETTARUMI_H_
#define EUNETTARUMI_H_
#include "Eunet.h"
#include "EunetBase.h"

class EunetTarumi: private EunetBase {
public:
	EunetTarumi(Eunet& eunet_) :
			EunetBase(eunet_) {
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

	void connectTier2() {
		connectSwitchNodes(316, 325, 2000000000, 2);
		connectSwitchNodes(316, 327, 2000000000, 2);
		connectSwitchNodes(316, 328, 2000000000, 2);
		connectSwitchNodes(316, 331, 2000000000, 2);
		connectSwitchNodes(288, 289, 1000000000, 2);
		connectSwitchNodes(291, 292, 1000000000, 2);
		connectSwitchNodes(291, 293, 1000000000, 2);
		connectSwitchNodes(291, 294, 2000000000, 2);
		connectSwitchNodes(295, 297, 1000000000, 2);
		connectSwitchNodes(295, 299, 1000000000, 2);
		connectSwitchNodes(295, 302, 1000000000, 2);
		connectSwitchNodes(295, 303, 1000000000, 2);
		connectSwitchNodes(304, 307, 1000000000, 2);
		connectSwitchNodes(312, 315, 1000000000, 2);
		connectSwitchNodes(312, 313, 2000000000, 2);
		connectSwitchNodes(312, 314, 2000000000, 2);
		connectSwitchNodes(316, 317, 2000000000, 2);
		connectSwitchNodes(316, 326, 1000000000, 2);
	}

	void connectTier3() {
		connectSwitchNodes(295, 296, 2000000000, 2);
		connectSwitchNodes(295, 300, 2000000000, 2);
		connectSwitchNodes(295, 301, 2000000000, 2);
		connectSwitchNodes(304, 305, 2000000000, 2);
		connectSwitchNodes(304, 306, 2000000000, 2);
		connectSwitchNodes(304, 308, 2000000000, 2);
		connectSwitchNodes(304, 309, 2000000000, 2);
		connectSwitchNodes(304, 310, 2000000000, 2);
		connectSwitchNodes(317, 318, 2000000000, 2);
		connectSwitchNodes(317, 319, 2000000000, 2);
		connectSwitchNodes(317, 320, 2000000000, 2);
		connectSwitchNodes(317, 321, 1000000000, 2);
		connectSwitchNodes(331, 332, 2000000000, 2);
		connectSwitchNodes(297, 298, 1000000000, 2);
		connectSwitchNodes(328, 329, 1000000000, 2);
		connectSwitchNodes(328, 330, 1000000000, 2);
	} //connectTier3

	void connectTier4() {
		connectSwitchNodes(321, 322, 2000000000, 2);
		connectSwitchNodes(321, 323, 2000000000, 2);
		connectSwitchNodes(321, 324, 2000000000, 2);
	} //connectTier4

	void connectAp() {
		connectSwitchAndWifiAp(295, 60);
		connectSwitchAndWifiAp(295, 61);
		connectSwitchAndWifiAp(295, 62);
		connectSwitchAndWifiAp(295, 63);
		connectSwitchAndWifiAp(295, 64);
		connectSwitchAndWifiAp(295, 65);
		connectSwitchAndWifiAp(294, 66);
		connectSwitchAndWifiAp(294, 67);
		connectSwitchAndWifiAp(288, 68);
		connectSwitchAndWifiAp(288, 69);
		connectSwitchAndWifiAp(288, 70);
		connectSwitchAndWifiAp(300, 71);
		connectSwitchAndWifiAp(299, 72);
		connectSwitchAndWifiAp(302, 73);
		connectSwitchAndWifiAp(301, 74);
		connectSwitchAndWifiAp(318, 75);
		connectSwitchAndWifiAp(318, 76);
		connectSwitchAndWifiAp(319, 77);
		connectSwitchAndWifiAp(320, 78);
		connectSwitchAndWifiAp(322, 79);
		connectSwitchAndWifiAp(308, 80);
		connectSwitchAndWifiAp(323, 81);
		connectSwitchAndWifiAp(324, 82);
		connectSwitchAndWifiAp(311, 83);
		connectSwitchAndWifiAp(311, 84);
		connectSwitchAndWifiAp(311, 85);
		connectSwitchAndWifiAp(313, 86);
		connectSwitchAndWifiAp(312, 87);
		connectSwitchAndWifiAp(312, 88);
		connectSwitchAndWifiAp(314, 89);
		connectSwitchAndWifiAp(314, 90);
		connectSwitchAndWifiAp(315, 91);
		connectSwitchAndWifiAp(315, 92);
		connectSwitchAndWifiAp(330, 93);
		connectSwitchAndWifiAp(330, 94);
		connectSwitchAndWifiAp(330, 95);
		connectSwitchAndWifiAp(330, 96);
		connectSwitchAndWifiAp(330, 97);
		connectSwitchAndWifiAp(330, 98);
		connectSwitchAndWifiAp(331, 99);
		connectSwitchAndWifiAp(331, 100);
		connectSwitchAndWifiAp(332, 101);
		connectSwitchAndWifiAp(332, 102);
		connectSwitchAndWifiAp(315, 103);
		connectSwitchAndWifiAp(315, 104);
		connectSwitchAndWifiAp(328, 105);
		connectSwitchAndWifiAp(328, 106);
		connectSwitchAndWifiAp(328, 107);
		connectSwitchAndWifiAp(328, 108);
		connectSwitchAndWifiAp(328, 109);
		connectSwitchAndWifiAp(326, 110);
		connectSwitchAndWifiAp(326, 111);
		connectSwitchAndWifiAp(326, 112);
		connectSwitchAndWifiAp(326, 113);
		connectSwitchAndWifiAp(327, 114);
		connectSwitchAndWifiAp(327, 115);
		connectSwitchAndWifiAp(327, 116);
		connectSwitchAndWifiAp(326, 117);
		connectSwitchAndWifiAp(326, 118);
		connectSwitchAndWifiAp(326, 119);
		connectSwitchAndWifiAp(326, 120);
		connectSwitchAndWifiAp(326, 121);
		connectSwitchAndWifiAp(326, 122);
		connectSwitchAndWifiAp(326, 123);
		connectSwitchAndWifiAp(294, 124);
		connectSwitchAndWifiAp(332, 125);
		connectSwitchAndWifiAp(332, 126);
		connectSwitchAndWifiAp(332, 127);
		connectSwitchAndWifiAp(332, 128);
	} //connectAp

	virtual ~EunetTarumi() {
	}
};

#endif /* EUNETTARUMI_H_ */
