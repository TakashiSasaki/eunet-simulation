/*
 * EunetJyouhoku.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef EUNETJYOUHOKU_H_
#define EUNETJYOUHOKU_H_

#include "Eunet.h"
#include "EunetBase.h"

class EunetJyouhoku: EunetBase {
public:
	EunetJyouhoku(Eunet &eunet) :
			EunetBase(eunet) {
	}
	void connectTier1() {
		connectSwitchNodes(CORE_SWITCH_INDEX, JYOUHOKU_SWITCH_INDEX,
				20000000000, 2);

		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 5, 7000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 7, 20000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 8, 7000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 9, 20000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 40, 11000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 50, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 70, 11000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 79, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 80, 20000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 113, 7000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 114, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 115, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 116, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 123, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 126, 20000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 141, 11000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 160, 7000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 161, 20000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 193, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 197, 11000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 200, 2000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 213, 7000000000, 2);
		connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 275, 20000000000, 2);

	} //connectTier1

	void connectTier2() {
		connectSwitchNodes(5, 6, 16000000000, 2);
		connectSwitchNodes(9, 11, 2000000000, 2);
		connectSwitchNodes(9, 15, 2000000000, 2);
		connectSwitchNodes(9, 17, 2000000000, 2);
		connectSwitchNodes(9, 18, 2000000000, 2);
		connectSwitchNodes(9, 19, 2000000000, 2);
		connectSwitchNodes(9, 20, 2000000000, 2);
		connectSwitchNodes(9, 29, 2000000000, 2);
		connectSwitchNodes(9, 30, 2000000000, 2);
		connectSwitchNodes(9, 33, 2000000000, 2);
		connectSwitchNodes(9, 34, 2000000000, 2);
		connectSwitchNodes(9, 35, 2000000000, 2);
		connectSwitchNodes(9, 37, 2000000000, 2);
		connectSwitchNodes(9, 38, 2000000000, 2);
		connectSwitchNodes(9, 39, 2000000000, 2);
		connectSwitchNodes(9, 10, 1000000000, 2);
		connectSwitchNodes(9, 22, 1000000000, 2);
		connectSwitchNodes(9, 23, 1000000000, 2);
		connectSwitchNodes(9, 24, 1000000000, 2);
		connectSwitchNodes(9, 31, 1000000000, 2);
		connectSwitchNodes(9, 32, 1000000000, 2);
		connectSwitchNodes(9, 36, 1000000000, 2);
		connectSwitchNodes(40, 41, 1000000000, 2);
		connectSwitchNodes(50, 51, 2000000000, 2);
		connectSwitchNodes(50, 57, 2000000000, 2);
		connectSwitchNodes(50, 58, 2000000000, 2);
		connectSwitchNodes(50, 59, 2000000000, 2);
		connectSwitchNodes(70, 71, 2000000000, 2);
		connectSwitchNodes(70, 72, 2000000000, 2);
		connectSwitchNodes(70, 74, 2000000000, 2);
		connectSwitchNodes(70, 76, 2000000000, 2);
		connectSwitchNodes(70, 78, 2000000000, 2);
		connectSwitchNodes(80, 81, 2000000000, 2);
		connectSwitchNodes(80, 85, 2000000000, 2);
		connectSwitchNodes(80, 99, 2000000000, 2);
		connectSwitchNodes(80, 91, 1000000000, 2);
		connectSwitchNodes(116, 117, 1000000000, 2);
		connectSwitchNodes(116, 118, 1000000000, 2);
		connectSwitchNodes(116, 119, 1000000000, 2);
		connectSwitchNodes(116, 120, 1000000000, 2);
		connectSwitchNodes(116, 121, 1000000000, 2);
		connectSwitchNodes(116, 122, 1000000000, 2);
		connectSwitchNodes(123, 124, 1000000000, 2);
		connectSwitchNodes(123, 125, 1000000000, 2);
		connectSwitchNodes(126, 127, 2000000000, 2);
		connectSwitchNodes(126, 128, 2000000000, 2);
		connectSwitchNodes(126, 129, 2000000000, 2);
		connectSwitchNodes(126, 130, 2000000000, 2);
		connectSwitchNodes(126, 131, 2000000000, 2);
		connectSwitchNodes(126, 132, 2000000000, 2);
		connectSwitchNodes(126, 137, 2000000000, 2);
		connectSwitchNodes(141, 142, 2000000000, 2);
		connectSwitchNodes(141, 143, 2000000000, 2);
		connectSwitchNodes(141, 144, 2000000000, 2);
		connectSwitchNodes(141, 145, 2000000000, 2);
		connectSwitchNodes(161, 165, 2000000000, 2);
		connectSwitchNodes(161, 167, 2000000000, 2);
		connectSwitchNodes(161, 178, 2000000000, 2);
		connectSwitchNodes(161, 180, 2000000000, 2);
		connectSwitchNodes(161, 183, 2000000000, 2);
		connectSwitchNodes(161, 162, 1000000000, 2);
		connectSwitchNodes(161, 163, 1000000000, 2);
		connectSwitchNodes(161, 164, 1000000000, 2);
		connectSwitchNodes(161, 166, 1000000000, 2);
		connectSwitchNodes(193, 194, 1000000000, 2);
		connectSwitchNodes(193, 195, 1000000000, 2);
		connectSwitchNodes(193, 196, 1000000000, 2);
		connectSwitchNodes(197, 198, 1000000000, 2);
		connectSwitchNodes(197, 199, 1000000000, 2);
		connectSwitchNodes(197, 343, 2000000000, 2);
		connectSwitchNodes(200, 201, 2000000000, 2);
		connectSwitchNodes(200, 206, 2000000000, 2);
		connectSwitchNodes(200, 205, 1000000000, 2);
	} //connectTier2

	void connectTier3() {
		connectSwitchNodes(11, 14, 2000000000, 2);
		connectSwitchNodes(20, 21, 2000000000, 2);
		connectSwitchNodes(24, 25, 2000000000, 2);
		connectSwitchNodes(51, 52, 2000000000, 2);
		connectSwitchNodes(51, 53, 2000000000, 2);
		connectSwitchNodes(51, 55, 2000000000, 2);
		connectSwitchNodes(59, 60, 2000000000, 2);
		connectSwitchNodes(59, 61, 2000000000, 2);
		connectSwitchNodes(59, 62, 2000000000, 2);
		connectSwitchNodes(72, 73, 2000000000, 2);
		connectSwitchNodes(74, 75, 2000000000, 2);
		connectSwitchNodes(76, 77, 2000000000, 2);
		connectSwitchNodes(81, 82, 2000000000, 2);
		connectSwitchNodes(81, 84, 2000000000, 2);
		connectSwitchNodes(132, 133, 2000000000, 2);
		connectSwitchNodes(132, 134, 2000000000, 2);
		connectSwitchNodes(132, 135, 2000000000, 2);
		connectSwitchNodes(132, 136, 2000000000, 2);
		connectSwitchNodes(142, 146, 2000000000, 2);
		connectSwitchNodes(143, 149, 2000000000, 2);
		connectSwitchNodes(145, 150, 2000000000, 2);
		connectSwitchNodes(145, 158, 2000000000, 2);
		connectSwitchNodes(167, 172, 2000000000, 2);
		connectSwitchNodes(180, 181, 2000000000, 2);
		connectSwitchNodes(201, 202, 2000000000, 2);
		connectSwitchNodes(201, 203, 2000000000, 2);
		connectSwitchNodes(201, 204, 2000000000, 2);
		connectSwitchNodes(41, 345, 2000000000, 2);
		connectSwitchNodes(41, 346, 2000000000, 2);
		connectSwitchNodes(11, 12, 1000000000, 2);
		connectSwitchNodes(11, 13, 1000000000, 2);
		connectSwitchNodes(15, 16, 1000000000, 2);
		connectSwitchNodes(24, 26, 1000000000, 2);
		connectSwitchNodes(24, 27, 1000000000, 2);
		connectSwitchNodes(24, 28, 1000000000, 2);
		connectSwitchNodes(41, 42, 1000000000, 2);
		connectSwitchNodes(41, 43, 1000000000, 2);
		connectSwitchNodes(41, 44, 1000000000, 2);
		connectSwitchNodes(41, 45, 1000000000, 2);
		connectSwitchNodes(59, 63, 1000000000, 2);
		connectSwitchNodes(59, 64, 1000000000, 2);
		connectSwitchNodes(81, 83, 1000000000, 2);
		connectSwitchNodes(85, 86, 1000000000, 2);
		connectSwitchNodes(85, 87, 1000000000, 2);
		connectSwitchNodes(85, 88, 1000000000, 2);
		connectSwitchNodes(85, 89, 1000000000, 2);
		connectSwitchNodes(91, 92, 1000000000, 2);
		connectSwitchNodes(91, 93, 1000000000, 2);
		connectSwitchNodes(91, 94, 1000000000, 2);
		connectSwitchNodes(91, 95, 1000000000, 2);
		connectSwitchNodes(91, 96, 1000000000, 2);
		connectSwitchNodes(91, 97, 1000000000, 2);
		connectSwitchNodes(91, 98, 1000000000, 2);
		connectSwitchNodes(99, 100, 1000000000, 2);
		connectSwitchNodes(99, 107, 1000000000, 2);
		connectSwitchNodes(99, 112, 1000000000, 2);
		connectSwitchNodes(137, 138, 1000000000, 2);
		connectSwitchNodes(137, 139, 1000000000, 2);
		connectSwitchNodes(137, 140, 1000000000, 2);
		connectSwitchNodes(167, 168, 1000000000, 2);
		connectSwitchNodes(167, 169, 1000000000, 2);
		connectSwitchNodes(167, 170, 1000000000, 2);
		connectSwitchNodes(167, 171, 1000000000, 2);
		connectSwitchNodes(167, 176, 1000000000, 2);
		connectSwitchNodes(178, 179, 1000000000, 2);
		connectSwitchNodes(183, 184, 1000000000, 2);
		connectSwitchNodes(183, 185, 1000000000, 2);
		connectSwitchNodes(183, 186, 1000000000, 2);
		connectSwitchNodes(183, 187, 1000000000, 2);
		connectSwitchNodes(183, 188, 1000000000, 2);
		connectSwitchNodes(183, 189, 1000000000, 2);
		connectSwitchNodes(183, 190, 1000000000, 2);
		connectSwitchNodes(183, 191, 1000000000, 2);
		connectSwitchNodes(183, 192, 1000000000, 2);
		connectSwitchNodes(206, 208, 2000000000, 2);
		connectSwitchNodes(206, 347, 2000000000, 2);
		connectSwitchNodes(206, 348, 2000000000, 2);
		connectSwitchNodes(206, 207, 1000000000, 2);
		connectSwitchNodes(206, 212, 1000000000, 2);

	} //connectTier3

	void connectTier4() {
		connectSwitchNodes(45, 46, 1000000000, 2);
		connectSwitchNodes(45, 48, 1000000000, 2);
		connectSwitchNodes(45, 49, 1000000000, 2);
		connectSwitchNodes(45, 344, 2000000000, 2);
		connectSwitchNodes(53, 54, 2000000000, 2);
		connectSwitchNodes(55, 56, 2000000000, 2);
		connectSwitchNodes(64, 65, 2000000000, 2);
		connectSwitchNodes(64, 66, 2000000000, 2);
		connectSwitchNodes(64, 68, 2000000000, 2);
		connectSwitchNodes(64, 69, 2000000000, 2);
		connectSwitchNodes(89, 90, 1000000000, 2);
		connectSwitchNodes(100, 101, 1000000000, 2);
		connectSwitchNodes(100, 102, 1000000000, 2);
		connectSwitchNodes(100, 103, 1000000000, 2);
		connectSwitchNodes(100, 104, 1000000000, 2);
		connectSwitchNodes(100, 105, 1000000000, 2);
		connectSwitchNodes(100, 106, 1000000000, 2);
		connectSwitchNodes(107, 108, 1000000000, 2);
		connectSwitchNodes(107, 109, 1000000000, 2);
		connectSwitchNodes(107, 110, 1000000000, 2);
		connectSwitchNodes(107, 111, 1000000000, 2);

		connectSwitchNodes(146, 147, 1000000000, 2);
		connectSwitchNodes(146, 148, 1000000000, 2);
		connectSwitchNodes(150, 151, 2000000000, 2);
		connectSwitchNodes(150, 154, 2000000000, 2);
		connectSwitchNodes(158, 159, 1000000000, 2);
		connectSwitchNodes(172, 173, 1000000000, 2);
		connectSwitchNodes(172, 174, 1000000000, 2);
		connectSwitchNodes(176, 177, 1000000000, 2);
		connectSwitchNodes(181, 182, 1000000000, 2);
		connectSwitchNodes(208, 209, 2000000000, 2);
		connectSwitchNodes(208, 210, 2000000000, 2);
		connectSwitchNodes(208, 211, 2000000000, 2);
	} //connectTier4

	void connectTier5() {
		connectSwitchNodes(46, 47, 1000000000, 2);
		connectSwitchNodes(66, 67, 1000000000, 2);
		connectSwitchNodes(151, 152, 1000000000, 2);
		connectSwitchNodes(151, 153, 1000000000, 2);
		connectSwitchNodes(154, 155, 1000000000, 2);
		connectSwitchNodes(154, 156, 1000000000, 2);
		connectSwitchNodes(154, 157, 1000000000, 2);
		connectSwitchNodes(174, 175, 1000000000, 2);
	} //connectTier5

	void connectAp1() {
		connectSwitchAndWifiAp(81, 1);
		connectSwitchAndWifiAp(82, 2);
		connectSwitchAndWifiAp(83, 3);
		connectSwitchAndWifiAp(85, 4);
		connectSwitchAndWifiAp(108, 5);
		connectSwitchAndWifiAp(86, 6);
		connectSwitchAndWifiAp(86, 7);
		connectSwitchAndWifiAp(87, 8);
		connectSwitchAndWifiAp(109, 9);
		connectSwitchAndWifiAp(88, 10);
		connectSwitchAndWifiAp(88, 11);
		connectSwitchAndWifiAp(111, 12);
		connectSwitchAndWifiAp(111, 13);
		connectSwitchAndWifiAp(89, 14);
		connectSwitchAndWifiAp(92, 15);
		connectSwitchAndWifiAp(101, 16);
		connectSwitchAndWifiAp(94, 17);
		connectSwitchAndWifiAp(94, 18);
		connectSwitchAndWifiAp(95, 19);
		connectSwitchAndWifiAp(103, 20);
		connectSwitchAndWifiAp(97, 21);
		connectSwitchAndWifiAp(105, 22);
		connectSwitchAndWifiAp(85, 23);
		connectSwitchAndWifiAp(86, 24);
		connectSwitchAndWifiAp(87, 25);
		connectSwitchAndWifiAp(162, 26);
		connectSwitchAndWifiAp(162, 27);
		connectSwitchAndWifiAp(162, 28);
		connectSwitchAndWifiAp(161, 29);
		connectSwitchAndWifiAp(163, 30);
		connectSwitchAndWifiAp(164, 31);
		connectSwitchAndWifiAp(165, 32);
		connectSwitchAndWifiAp(165, 33);
		connectSwitchAndWifiAp(165, 34);
		connectSwitchAndWifiAp(169, 35);
		connectSwitchAndWifiAp(169, 36);
		connectSwitchAndWifiAp(180, 37);
		connectSwitchAndWifiAp(180, 38);
		connectSwitchAndWifiAp(182, 313);
		connectSwitchAndWifiAp(183, 39);
		connectSwitchAndWifiAp(185, 40);
		connectSwitchAndWifiAp(187, 41);
		connectSwitchAndWifiAp(189, 42);
		connectSwitchAndWifiAp(191, 43);
		connectSwitchAndWifiAp(194, 44);
		connectSwitchAndWifiAp(195, 45);
		connectSwitchAndWifiAp(196, 46);
		connectSwitchAndWifiAp(196, 47);
		connectSwitchAndWifiAp(343, 48);
		connectSwitchAndWifiAp(343, 49);
		connectSwitchAndWifiAp(343, 50);
		connectSwitchAndWifiAp(343, 51);
		connectSwitchAndWifiAp(343, 52);
		connectSwitchAndWifiAp(343, 53);
		connectSwitchAndWifiAp(206, 54);
		connectSwitchAndWifiAp(205, 55);
		connectSwitchAndWifiAp(205, 56);
		connectSwitchAndWifiAp(204, 57);
		connectSwitchAndWifiAp(204, 58);
		connectSwitchAndWifiAp(211, 59);
	} //connectAp1

	void connectAp2() {
		connectSwitchAndWifiAp(138, 189);
		connectSwitchAndWifiAp(138, 190);
		connectSwitchAndWifiAp(139, 191);
		connectSwitchAndWifiAp(139, 192);
		connectSwitchAndWifiAp(140, 193);
		connectSwitchAndWifiAp(140, 194);
		connectSwitchAndWifiAp(140, 195);
		connectSwitchAndWifiAp(140, 196);
		connectSwitchAndWifiAp(126, 197);
		connectSwitchAndWifiAp(129, 198);
		connectSwitchAndWifiAp(129, 199);
		connectSwitchAndWifiAp(130, 200);
		connectSwitchAndWifiAp(136, 201);
		connectSwitchAndWifiAp(142, 202);
		connectSwitchAndWifiAp(142, 203);
		connectSwitchAndWifiAp(150, 204);
		connectSwitchAndWifiAp(150, 205);
		connectSwitchAndWifiAp(150, 206);
		connectSwitchAndWifiAp(147, 207);
		connectSwitchAndWifiAp(147, 208);
		connectSwitchAndWifiAp(146, 209);
		connectSwitchAndWifiAp(146, 210);
		connectSwitchAndWifiAp(151, 211);
		connectSwitchAndWifiAp(151, 212);
		connectSwitchAndWifiAp(148, 213);
		connectSwitchAndWifiAp(148, 214);
		connectSwitchAndWifiAp(144, 215);
		connectSwitchAndWifiAp(144, 216);
		connectSwitchAndWifiAp(144, 217);
		connectSwitchAndWifiAp(157, 218);
		connectSwitchAndWifiAp(149, 219);
		connectSwitchAndWifiAp(149, 220);
		connectSwitchAndWifiAp(158, 221);
		connectSwitchAndWifiAp(158, 222);
		connectSwitchAndWifiAp(158, 223);
		connectSwitchAndWifiAp(158, 224);
		connectSwitchAndWifiAp(158, 225);
		connectSwitchAndWifiAp(158, 226);
		connectSwitchAndWifiAp(158, 227);
		connectSwitchAndWifiAp(158, 228);
		connectSwitchAndWifiAp(158, 229);
		connectSwitchAndWifiAp(158, 230);
		connectSwitchAndWifiAp(117, 231);
		connectSwitchAndWifiAp(121, 232);
		connectSwitchAndWifiAp(122, 233);
		connectSwitchAndWifiAp(119, 234);
		connectSwitchAndWifiAp(51, 235);
		connectSwitchAndWifiAp(51, 236);
		connectSwitchAndWifiAp(52, 237);
		connectSwitchAndWifiAp(52, 238);
		connectSwitchAndWifiAp(52, 239);
		connectSwitchAndWifiAp(54, 240);
		connectSwitchAndWifiAp(56, 241);
		connectSwitchAndWifiAp(56, 242);
		connectSwitchAndWifiAp(57, 243);
		connectSwitchAndWifiAp(71, 244);
		connectSwitchAndWifiAp(71, 245);
		connectSwitchAndWifiAp(71, 246);
		connectSwitchAndWifiAp(70, 247);
		connectSwitchAndWifiAp(77, 248);
		connectSwitchAndWifiAp(77, 249);
		connectSwitchAndWifiAp(78, 250);
		connectSwitchAndWifiAp(65, 251);
		connectSwitchAndWifiAp(66, 252);
		connectSwitchAndWifiAp(69, 253);
		connectSwitchAndWifiAp(69, 254);
		connectSwitchAndWifiAp(79, 255);
		connectSwitchAndWifiAp(79, 256);
		connectSwitchAndWifiAp(41, 257);
		connectSwitchAndWifiAp(45, 258);
		connectSwitchAndWifiAp(47, 259);
		connectSwitchAndWifiAp(42, 260);
		connectSwitchAndWifiAp(49, 261);
		connectSwitchAndWifiAp(49, 262);
		connectSwitchAndWifiAp(44, 263);
		connectSwitchAndWifiAp(344, 264);
		connectSwitchAndWifiAp(345, 265);
		connectSwitchAndWifiAp(345, 266);
		connectSwitchAndWifiAp(18, 267);
		connectSwitchAndWifiAp(18, 268);
		connectSwitchAndWifiAp(18, 269);
		connectSwitchAndWifiAp(19, 270);
		connectSwitchAndWifiAp(27, 271);
		connectSwitchAndWifiAp(346, 272);
		connectSwitchAndWifiAp(346, 273);
		connectSwitchAndWifiAp(79, 274);
		connectSwitchAndWifiAp(79, 275);
		connectSwitchAndWifiAp(51, 276);
		connectSwitchAndWifiAp(51, 277);
		connectSwitchAndWifiAp(51, 278);
		connectSwitchAndWifiAp(51, 279);
		connectSwitchAndWifiAp(114, 280);
		connectSwitchAndWifiAp(114, 281);
		connectSwitchAndWifiAp(114, 282);
		connectSwitchAndWifiAp(114, 283);
		connectSwitchAndWifiAp(114, 284);
		connectSwitchAndWifiAp(57, 285);
		connectSwitchAndWifiAp(59, 286);
		connectSwitchAndWifiAp(58, 287);
		connectSwitchAndWifiAp(58, 288);
		connectSwitchAndWifiAp(114, 289);
		connectSwitchAndWifiAp(114, 290);
		connectSwitchAndWifiAp(114, 291);
		connectSwitchAndWifiAp(114, 292);
		connectSwitchAndWifiAp(347, 293);
		connectSwitchAndWifiAp(348, 294);
		connectSwitchAndWifiAp(65, 295);
		connectSwitchAndWifiAp(346, 296);
		connectSwitchAndWifiAp(346, 297);
	} //connectAp2

	virtual ~EunetJyouhoku() {
	}
};

#endif /* EUNETJYOUHOKU_H_ */
