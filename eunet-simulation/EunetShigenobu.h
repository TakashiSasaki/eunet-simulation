/*
 * Shigenobu.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef SHIGENOBU_H_
#define SHIGENOBU_H_
#include "EunetBase.h"
class EunetShigenobu: EunetBase {
public:
	EunetShigenobu(Eunet& eunet) :
			EunetBase(eunet) {
	}
	void connectTier1() {
		connectSwitchNodes(CORE_SWITCH_INDEX, SHIGENOBU_SWITCH_INDEX,
				22000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 226, 8000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 283, 7000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 266, 4000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 276, 4000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 214, 2000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 215, 2000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 217, 2000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 220, 2000000000, 2);
		connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 264, 2000000000, 2);
	} //connectTier1

	void connectTier2() {
		connectSwitchNodes(226, 227, 2000000000, 2);
		connectSwitchNodes(226, 229, 2000000000, 2);
		connectSwitchNodes(226, 230, 2000000000, 2);
		connectSwitchNodes(226, 256, 2000000000, 2);
		connectSwitchNodes(226, 260, 2000000000, 2);
		connectSwitchNodes(215, 216, 1000000000, 2);
		connectSwitchNodes(217, 218, 1000000000, 2);
		connectSwitchNodes(217, 219, 1000000000, 2);
		connectSwitchNodes(220, 221, 1000000000, 2);
		connectSwitchNodes(220, 222, 1000000000, 2);
		connectSwitchNodes(220, 223, 1000000000, 2);
		connectSwitchNodes(220, 224, 1000000000, 2);
		connectSwitchNodes(220, 225, 1000000000, 2);
		connectSwitchNodes(226, 261, 1000000000, 2);
		connectSwitchNodes(226, 262, 1000000000, 2);
		connectSwitchNodes(226, 263, 1000000000, 2);
		connectSwitchNodes(264, 265, 1000000000, 2);
		connectSwitchNodes(266, 267, 1000000000, 2);
		connectSwitchNodes(266, 268, 1000000000, 2);
		connectSwitchNodes(266, 269, 1000000000, 2);
		connectSwitchNodes(266, 270, 1000000000, 2);
		connectSwitchNodes(266, 273, 1000000000, 2);
		connectSwitchNodes(266, 274, 1000000000, 2);
		connectSwitchNodes(276, 277, 1000000000, 2);
		connectSwitchNodes(276, 278, 1000000000, 2);
		connectSwitchNodes(276, 282, 1000000000, 2);
		connectSwitchNodes(276, 280, 1000000000, 2);
	} //connectTier2

	void connectTier3() {
		connectSwitchNodes(227, 228, 2000000000, 2);
		connectSwitchNodes(230, 233, 1000000000, 2);
		connectSwitchNodes(230, 234, 1000000000, 2);
		connectSwitchNodes(230, 235, 1000000000, 2);
		connectSwitchNodes(230, 236, 1000000000, 2);
		connectSwitchNodes(230, 237, 1000000000, 2);
		connectSwitchNodes(230, 231, 2000000000, 2);
		connectSwitchNodes(230, 248, 2000000000, 2);
		connectSwitchNodes(230, 238, 1000000000, 2);
		connectSwitchNodes(230, 239, 1000000000, 2);
		connectSwitchNodes(230, 240, 1000000000, 2);
		connectSwitchNodes(230, 241, 1000000000, 2);
		connectSwitchNodes(230, 242, 1000000000, 2);
		connectSwitchNodes(230, 243, 1000000000, 2);
		connectSwitchNodes(230, 244, 1000000000, 2);
		connectSwitchNodes(230, 245, 1000000000, 2);
		connectSwitchNodes(230, 246, 1000000000, 2);
		connectSwitchNodes(230, 247, 1000000000, 2);
		connectSwitchNodes(256, 257, 2000000000, 2);
		connectSwitchNodes(256, 258, 2000000000, 2);
		connectSwitchNodes(256, 259, 2000000000, 2);
		connectSwitchNodes(270, 272, 1000000000, 2);
		connectSwitchNodes(278, 279, 1000000000, 2);
		connectSwitchNodes(280, 281, 1000000000, 2);
	} //connectTier3

	void connectTier4() {
		connectSwitchNodes(231, 232, 1000000000, 2);
		connectSwitchNodes(248, 284, 1000000000, 2);
		connectSwitchNodes(248, 249, 1000000000, 2);
		connectSwitchNodes(248, 250, 1000000000, 2);
		connectSwitchNodes(248, 251, 1000000000, 2);
		connectSwitchNodes(248, 252, 1000000000, 2);
		connectSwitchNodes(248, 253, 1000000000, 2);
		connectSwitchNodes(248, 254, 1000000000, 2);
		connectSwitchNodes(248, 255, 1000000000, 2);
	} //connectTier4

	void connectAp() {

		connectSwitchAndWifiAp(215, 129);
		connectSwitchAndWifiAp(217, 130);
		connectSwitchAndWifiAp(218, 131);
		connectSwitchAndWifiAp(219, 132);
		connectSwitchAndWifiAp(221, 133);
		connectSwitchAndWifiAp(221, 134);
		connectSwitchAndWifiAp(222, 135);
		connectSwitchAndWifiAp(222, 136);
		connectSwitchAndWifiAp(220, 137);
		connectSwitchAndWifiAp(220, 138);
		connectSwitchAndWifiAp(227, 139);
		connectSwitchAndWifiAp(228, 140);
		connectSwitchAndWifiAp(224, 141);
		connectSwitchAndWifiAp(225, 142);
		connectSwitchAndWifiAp(225, 143);
		connectSwitchAndWifiAp(284, 144);
		connectSwitchAndWifiAp(259, 145);
		connectSwitchAndWifiAp(259, 146);
		connectSwitchAndWifiAp(260, 147);
		connectSwitchAndWifiAp(260, 148);
		connectSwitchAndWifiAp(261, 149);
		connectSwitchAndWifiAp(262, 150);
		connectSwitchAndWifiAp(262, 151);
		connectSwitchAndWifiAp(268, 152);
		connectSwitchAndWifiAp(268, 153);
		connectSwitchAndWifiAp(268, 154);
		connectSwitchAndWifiAp(268, 155);
		connectSwitchAndWifiAp(268, 156);
		connectSwitchAndWifiAp(214, 157);
		connectSwitchAndWifiAp(214, 158);
		connectSwitchAndWifiAp(214, 159);
		connectSwitchAndWifiAp(214, 160);
		connectSwitchAndWifiAp(214, 161);
		connectSwitchAndWifiAp(214, 162);
		connectSwitchAndWifiAp(214, 163);
		connectSwitchAndWifiAp(269, 164);
		connectSwitchAndWifiAp(270, 165);
		connectSwitchAndWifiAp(273, 166);
		connectSwitchAndWifiAp(277, 167);
		connectSwitchAndWifiAp(278, 168);
		connectSwitchAndWifiAp(280, 169);
		connectSwitchAndWifiAp(282, 170);
		connectSwitchAndWifiAp(263, 171);
		connectSwitchAndWifiAp(238, 172);
		connectSwitchAndWifiAp(238, 173);
		connectSwitchAndWifiAp(268, 174);
		connectSwitchAndWifiAp(268, 175);
		connectSwitchAndWifiAp(268, 176);
		connectSwitchAndWifiAp(260, 177);
		connectSwitchAndWifiAp(260, 178);
		connectSwitchAndWifiAp(260, 179);
		connectSwitchAndWifiAp(260, 180);
		connectSwitchAndWifiAp(268, 181);
		connectSwitchAndWifiAp(234, 182);
		connectSwitchAndWifiAp(235, 183);
		connectSwitchAndWifiAp(235, 184);
		connectSwitchAndWifiAp(231, 185);
		connectSwitchAndWifiAp(231, 186);
		connectSwitchAndWifiAp(231, 187);
		connectSwitchAndWifiAp(231, 188);
	} //connectAp

	virtual ~EunetShigenobu() {
	}
};

#endif /* SHIGENOBU_H_ */
