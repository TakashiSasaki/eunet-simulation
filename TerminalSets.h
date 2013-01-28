/*
 * TerminalSets.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef TERMINALSETS_H_
#define TERMINALSETS_H_

void initTerminalSet(ns3::NodeContainer & x) {
	x.Create(15);
}

class TerminalSets {
	std::vector<ns3::NodeContainer>  terminalSets;
public:

	const ns3::NodeContainer& operator[](const int index) const {
		return terminalSets[index];
	}

	TerminalSets(const int number_of_terminal_set) :
			terminalSets(number_of_terminal_set) {
		std::for_each(terminalSets.begin(), terminalSets.end(),
				initTerminalSet);
	}
	virtual ~TerminalSets() {

	}
};

#endif /* TERMINALSETS_H_ */

#if 0
//csmaSwitch5 nodes
ns3::NodeContainer terminals5;
terminals5.Create(15);
//csmaSwitch6 nodes
ns3::NodeContainer terminals6;
terminals6.Create(15);
//csmaSwitch7 nodes
ns3::NodeContainer terminals7;
terminals7.Create(15);
//csmaSwitch8 nodes
ns3::NodeContainer terminals8;
terminals8.Create(15);
//csmaSwitch9 nodes
ns3::NodeContainer terminals9;
terminals9.Create(15);
//csmaSwitch10 nodes
ns3::NodeContainer terminals10;
terminals10.Create(15);
//csmaSwitch11 nodes
ns3::NodeContainer terminals11;
terminals11.Create(15);
//csmaSwitch12 nodes
ns3::NodeContainer terminals12;
terminals12.Create(15);
//csmaSwitch13 nodes
ns3::NodeContainer terminals13;
terminals13.Create(15);
//csmaSwitch14 nodes
ns3::NodeContainer terminals14;
terminals14.Create(15);
//csmaSwitch15 nodes
ns3::NodeContainer terminals15;
terminals15.Create(15);
//csmaSwitch16 nodes
ns3::NodeContainer terminals16;
terminals16.Create(15);
//csmaSwitch17 nodes
ns3::NodeContainer terminals17;
terminals17.Create(15);
//csmaSwitch18 nodes
ns3::NodeContainer terminals18;
terminals18.Create(15);
//csmaSwitch19 nodes
ns3::NodeContainer terminals19;
terminals19.Create(15);
//csmaSwitch20 nodes
ns3::NodeContainer terminals20;
terminals20.Create(15);
//csmaSwitch21 nodes
ns3::NodeContainer terminals21;
terminals21.Create(15);
//csmaSwitch22 nodes
ns3::NodeContainer terminals22;
terminals22.Create(15);
//csmaSwitch23 nodes
ns3::NodeContainer terminals23;
terminals23.Create(15);
//csmaSwitch24 nodes
ns3::NodeContainer terminals24;
terminals24.Create(15);
//csmaSwitch25 nodes
ns3::NodeContainer terminals25;
terminals25.Create(15);
//csmaSwitch26 nodes
ns3::NodeContainer terminals26;
terminals26.Create(15);
//csmaSwitch27 nodes
ns3::NodeContainer terminals27;
terminals27.Create(15);
//csmaSwitch28 nodes
ns3::NodeContainer terminals28;
terminals28.Create(15);
//csmaSwitch29 nodes
ns3::NodeContainer terminals29;
terminals29.Create(15);
//csmaSwitch30 nodes
ns3::NodeContainer terminals30;
terminals30.Create(15);
//csmaSwitch31 nodes
ns3::NodeContainer terminals31;
terminals31.Create(15);
//csmaSwitch32 nodes
ns3::NodeContainer terminals32;
terminals32.Create(15);
//csmaSwitch33 nodes
ns3::NodeContainer terminals33;
terminals33.Create(15);
//csmaSwitch34 nodes
ns3::NodeContainer terminals34;
terminals34.Create(15);
//csmaSwitch35 nodes
ns3::NodeContainer terminals35;
terminals35.Create(15);
//csmaSwitch36 nodes
ns3::NodeContainer terminals36;
terminals36.Create(15);
//csmaSwitch37 nodes
ns3::NodeContainer terminals37;
terminals37.Create(15);
//csmaSwitch38 nodes
ns3::NodeContainer terminals38;
terminals38.Create(15);
//csmaSwitch39 nodes
ns3::NodeContainer terminals39;
terminals39.Create(15);
//csmaSwitch40 nodes
ns3::NodeContainer terminals40;
terminals40.Create(15);
//csmaSwitch41 nodes
ns3::NodeContainer terminals41;
terminals41.Create(15);
//csmaSwitch42 nodes
ns3::NodeContainer terminals42;
terminals42.Create(15);
//csmaSwitch43 nodes
ns3::NodeContainer terminals43;
terminals43.Create(15);
//csmaSwitch44 nodes
ns3::NodeContainer terminals44;
terminals44.Create(15);
//csmaSwitch45 nodes
ns3::NodeContainer terminals45;
terminals45.Create(15);
//csmaSwitch46 nodes
ns3::NodeContainer terminals46;
terminals46.Create(15);
//csmaSwitch47 nodes
ns3::NodeContainer terminals47;
terminals47.Create(15);
//csmaSwitch48 nodes
ns3::NodeContainer terminals48;
terminals48.Create(15);
//csmaSwitch49 nodes
ns3::NodeContainer terminals49;
terminals49.Create(15);
//csmaSwitch50 nodes
ns3::NodeContainer terminals50;
terminals50.Create(15);
//csmaSwitch51 nodes
ns3::NodeContainer terminals51;
terminals51.Create(15);
//csmaSwitch52 nodes
ns3::NodeContainer terminals52;
terminals52.Create(15);
//csmaSwitch53 nodes
ns3::NodeContainer terminals53;
terminals53.Create(15);
//csmaSwitch54 nodes
ns3::NodeContainer terminals54;
terminals54.Create(15);
//csmaSwitch55 nodes
ns3::NodeContainer terminals55;
terminals55.Create(15);
//csmaSwitch56 nodes
ns3::NodeContainer terminals56;
terminals56.Create(15);
//csmaSwitch57 nodes
ns3::NodeContainer terminals57;
terminals57.Create(15);
//csmaSwitch58 nodes
ns3::NodeContainer terminals58;
terminals58.Create(15);
//csmaSwitch59 nodes
ns3::NodeContainer terminals59;
terminals59.Create(15);
//csmaSwitch60 nodes
ns3::NodeContainer terminals60;
terminals60.Create(15);
//csmaSwitch61 nodes
ns3::NodeContainer terminals61;
terminals61.Create(15);
//csmaSwitch62 nodes
ns3::NodeContainer terminals62;
terminals62.Create(15);
//csmaSwitch63 nodes
ns3::NodeContainer terminals63;
terminals63.Create(15);
//csmaSwitch64 nodes
ns3::NodeContainer terminals64;
terminals64.Create(15);
//csmaSwitch65 nodes
ns3::NodeContainer terminals65;
terminals65.Create(15);
//csmaSwitch66 nodes
ns3::NodeContainer terminals66;
terminals66.Create(15);
//csmaSwitch67 nodes
ns3::NodeContainer terminals67;
terminals67.Create(15);
//csmaSwitch68 nodes
ns3::NodeContainer terminals68;
terminals68.Create(15);
//csmaSwitch69 nodes
ns3::NodeContainer terminals69;
terminals69.Create(15);
//csmaSwitch70 nodes
ns3::NodeContainer terminals70;
terminals70.Create(15);
//csmaSwitch71 nodes
ns3::NodeContainer terminals71;
terminals71.Create(15);
//csmaSwitch72 nodes
ns3::NodeContainer terminals72;
terminals72.Create(15);
//csmaSwitch73 nodes
ns3::NodeContainer terminals73;
terminals73.Create(15);
//csmaSwitch74 nodes
ns3::NodeContainer terminals74;
terminals74.Create(15);
//csmaSwitch75 nodes
ns3::NodeContainer terminals75;
terminals75.Create(15);
//csmaSwitch76 nodes
ns3::NodeContainer terminals76;
terminals76.Create(15);
//csmaSwitch77 nodes
ns3::NodeContainer terminals77;
terminals77.Create(15);
//csmaSwitch78 nodes
ns3::NodeContainer terminals78;
terminals78.Create(15);
//csmaSwitch79 nodes
ns3::NodeContainer terminals79;
terminals79.Create(15);
//csmaSwitch81 nodes
ns3::NodeContainer terminals81;
terminals81.Create(15);
//csmaSwitch82 nodes
ns3::NodeContainer terminals82;
terminals82.Create(15);
//csmaSwitch83 nodes
ns3::NodeContainer terminals83;
terminals83.Create(15);
//csmaSwitch84 nodes
ns3::NodeContainer terminals84;
terminals84.Create(15);
//csmaSwitch85 nodes
ns3::NodeContainer terminals85;
terminals85.Create(15);
//csmaSwitch86 nodes
ns3::NodeContainer terminals86;
terminals86.Create(15);
//csmaSwitch87 nodes
ns3::NodeContainer terminals87;
terminals87.Create(15);
//csmaSwitch88 nodes
ns3::NodeContainer terminals88;
terminals88.Create(15);
//csmaSwitch89 nodes
ns3::NodeContainer terminals89;
terminals89.Create(15);
//csmaSwitch90 nodes
ns3::NodeContainer terminals90;
terminals90.Create(15);
//csmaSwitch91 nodes
ns3::NodeContainer terminals91;
terminals91.Create(15);
//csmaSwitch92 nodes
ns3::NodeContainer terminals92;
terminals92.Create(15);
//csmaSwitch93 nodes
ns3::NodeContainer terminals93;
terminals93.Create(15);
//csmaSwitch94 nodes
ns3::NodeContainer terminals94;
terminals94.Create(15);
//csmaSwitch95 nodes
ns3::NodeContainer terminals95;
terminals95.Create(15);
//csmaSwitch96 nodes
ns3::NodeContainer terminals96;
terminals96.Create(15);
//csmaSwitch97 nodes
ns3::NodeContainer terminals97;
terminals97.Create(15);
//csmaSwitch98 nodes
ns3::NodeContainer terminals98;
terminals98.Create(15);
//csmaSwitch99 nodes
ns3::NodeContainer terminals99;
terminals99.Create(15);
//csmaSwitch100 nodes
ns3::NodeContainer terminals100;
terminals100.Create(15);
//csmaSwitch101 nodes
ns3::NodeContainer terminals101;
terminals101.Create(15);
//csmaSwitch102 nodes
ns3::NodeContainer terminals102;
terminals102.Create(15);
//csmaSwitch103 nodes
ns3::NodeContainer terminals103;
terminals103.Create(15);
//csmaSwitch104 nodes
ns3::NodeContainer terminals104;
terminals104.Create(15);
//csmaSwitch105 nodes
ns3::NodeContainer terminals105;
terminals105.Create(15);
//csmaSwitch106 nodes
ns3::NodeContainer terminals106;
terminals106.Create(15);
//csmaSwitch107 nodes
ns3::NodeContainer terminals107;
terminals107.Create(15);
//csmaSwitch108 nodes
ns3::NodeContainer terminals108;
terminals108.Create(15);
//csmaSwitch109 nodes
ns3::NodeContainer terminals109;
terminals109.Create(15);
//csmaSwitch110 nodes
ns3::NodeContainer terminals110;
terminals110.Create(15);
//csmaSwitch111 nodes
ns3::NodeContainer terminals111;
terminals111.Create(15);
//csmaSwitch112 nodes
ns3::NodeContainer terminals112;
terminals112.Create(15);
//csmaSwitch114 nodes
ns3::NodeContainer terminals114;
terminals114.Create(15);
//csmaSwitch115 nodes
ns3::NodeContainer terminals115;
terminals115.Create(15);
//csmaSwitch116 nodes
ns3::NodeContainer terminals116;
terminals116.Create(15);
//csmaSwitch117 nodes
ns3::NodeContainer terminals117;
terminals117.Create(15);
//csmaSwitch118 nodes
ns3::NodeContainer terminals118;
terminals118.Create(15);
//csmaSwitch119 nodes
ns3::NodeContainer terminals119;
terminals119.Create(15);
//csmaSwitch120 nodes
ns3::NodeContainer terminals120;
terminals120.Create(15);
//csmaSwitch121 nodes
ns3::NodeContainer terminals121;
terminals121.Create(15);
//csmaSwitch122 nodes
ns3::NodeContainer terminals122;
terminals122.Create(15);
//csmaSwitch123 nodes
ns3::NodeContainer terminals123;
terminals123.Create(15);
//csmaSwitch124 nodes
ns3::NodeContainer terminals124;
terminals124.Create(15);
//csmaSwitch125 nodes
ns3::NodeContainer terminals125;
terminals125.Create(15);
//csmaSwitch126 nodes
ns3::NodeContainer terminals126;
terminals126.Create(15);
//csmaSwitch127 nodes
ns3::NodeContainer terminals127;
terminals127.Create(15);
//csmaSwitch128nodes
ns3::NodeContainer terminals128;
terminals128.Create(15);
//csmaSwitch129 nodes
ns3::NodeContainer terminals129;
terminals129.Create(15);
//csmaSwitch130 nodes
ns3::NodeContainer terminals130;
terminals130.Create(15);
//csmaSwitch131 nodes
ns3::NodeContainer terminals131;
terminals131.Create(15);
//csmaSwitch132 nodes
ns3::NodeContainer terminals132;
terminals132.Create(15);
//csmaSwitch133 nodes
ns3::NodeContainer terminals133;
terminals133.Create(15);
//csmaSwitch134 nodes
ns3::NodeContainer terminals134;
terminals134.Create(15);
//csmaSwitch135 nodes
ns3::NodeContainer terminals135;
terminals135.Create(15);
//csmaSwitch136 nodes
ns3::NodeContainer terminals136;
terminals136.Create(15);
//csmaSwitch137 nodes
ns3::NodeContainer terminals137;
terminals137.Create(15);
//csmaSwitch138 nodes
ns3::NodeContainer terminals138;
terminals138.Create(15);
//csmaSwitch139 nodes
ns3::NodeContainer terminals139;
terminals139.Create(15);
//csmaSwitch140 nodes
ns3::NodeContainer terminals140;
terminals140.Create(15);
//csmaSwitch141 nodes
ns3::NodeContainer terminals141;
terminals141.Create(15);
//csmaSwitch142 nodes
ns3::NodeContainer terminals142;
terminals142.Create(15);
//csmaSwitch143 nodes
ns3::NodeContainer terminals143;
terminals143.Create(15);
//csmaSwitch144 nodes
ns3::NodeContainer terminals144;
terminals144.Create(15);
//csmaSwitch145 nodes
ns3::NodeContainer terminals145;
terminals145.Create(15);
//csmaSwitch146 nodes
ns3::NodeContainer terminals146;
terminals146.Create(15);
//csmaSwitch147 nodes
ns3::NodeContainer terminals147;
terminals147.Create(15);
//csmaSwitch148 nodes
ns3::NodeContainer terminals148;
terminals148.Create(15);
//csmaSwitch149 nodes
ns3::NodeContainer terminals149;
terminals149.Create(15);
//csmaSwitch150 nodes
ns3::NodeContainer terminals150;
terminals150.Create(15);
//csmaSwitch151 nodes
ns3::NodeContainer terminals151;
terminals151.Create(15);
//csmaSwitch152 nodes
ns3::NodeContainer terminals152;
terminals152.Create(15);
//csmaSwitch153 nodes
ns3::NodeContainer terminals153;
terminals153.Create(15);
//csmaSwitch154 nodes
ns3::NodeContainer terminals154;
terminals154.Create(15);
//csmaSwitch155 nodes
ns3::NodeContainer terminals155;
terminals155.Create(15);
//csmaSwitch156 nodes
ns3::NodeContainer terminals156;
terminals156.Create(15);
//csmaSwitch157 nodes
ns3::NodeContainer terminals157;
terminals157.Create(15);
//csmaSwitch158 nodes
ns3::NodeContainer terminals158;
terminals158.Create(15);
//csmaSwitch159 nodes
ns3::NodeContainer terminals159;
terminals159.Create(15);
//kougakubu--sougoukenkyu
//csmaSwitch161 nodes
ns3::NodeContainer terminals161;
terminals161.Create(15);
//csmaSwitch162 nodes
ns3::NodeContainer terminals162;
terminals162.Create(15);
//csmaSwitch163 nodes
ns3::NodeContainer terminals163;
terminals163.Create(15);
//csmaSwitch164 nodes
ns3::NodeContainer terminals164;
terminals164.Create(15);
//csmaSwitch165 nodes
ns3::NodeContainer terminals165;
terminals165.Create(15);
//csmaSwitch166 nodes
ns3::NodeContainer terminals166;
terminals166.Create(15);
//csmaSwitch167 nodes
ns3::NodeContainer terminals167;
terminals167.Create(15);
//csmaSwitch168 nodes
ns3::NodeContainer terminals168;
terminals168.Create(15);
//csmaSwitch169 nodes
ns3::NodeContainer terminals169;
terminals169.Create(15);
//csmaSwitch170 nodes
ns3::NodeContainer terminals170;
terminals170.Create(15);
//csmaSwitch171 nodes
ns3::NodeContainer terminals171;
terminals171.Create(15);
//csmaSwitch172 nodes
ns3::NodeContainer terminals172;
terminals172.Create(15);
//csmaSwitch173 nodes
ns3::NodeContainer terminals173;
terminals173.Create(15);
//csmaSwitch174 nodes
ns3::NodeContainer terminals174;
terminals174.Create(15);
//csmaSwitch175 nodes
ns3::NodeContainer terminals175;
terminals175.Create(15);
//csmaSwitch176 nodes
ns3::NodeContainer terminals176;
terminals176.Create(15);
//csmaSwitch177 nodes
ns3::NodeContainer terminals177;
terminals177.Create(15);
//csmaSwitch178 nodes
ns3::NodeContainer terminals178;
terminals178.Create(15);
//csmaSwitch179 nodes
ns3::NodeContainer terminals179;
terminals179.Create(15);
//csmaSwitch180 nodes
ns3::NodeContainer terminals180;
terminals180.Create(15);
//csmaSwitch181 nodes
ns3::NodeContainer terminals181;
terminals181.Create(15);
//csmaSwitch182 nodes
ns3::NodeContainer terminals182;
terminals182.Create(15);
//csmaSwitch183 nodes
ns3::NodeContainer terminals183;
terminals183.Create(15);
//csmaSwitch184 nodes
ns3::NodeContainer terminals184;
terminals184.Create(15);
//csmaSwitch185 nodes
ns3::NodeContainer terminals185;
terminals185.Create(15);
//csmaSwitch186 nodes
ns3::NodeContainer terminals186;
terminals186.Create(15);
//csmaSwitch187 nodes
ns3::NodeContainer terminals187;
terminals187.Create(15);
//csmaSwitch188 nodes
ns3::NodeContainer terminals188;
terminals188.Create(15);
//csmaSwitch189 nodes
ns3::NodeContainer terminals189;
terminals189.Create(15);
//csmaSwitch190 nodes
ns3::NodeContainer terminals190;
terminals190.Create(15);
//csmaSwitch191 nodes
ns3::NodeContainer terminals191;
terminals191.Create(15);
//csmaSwitch192 nodes
ns3::NodeContainer terminals192;
terminals192.Create(15);
//csmaSwitch193 nodes
ns3::NodeContainer terminals193;
terminals193.Create(15);
//csmaSwitch194 nodes
ns3::NodeContainer terminals194;
terminals194.Create(15);
//csmaSwitch195 nodes
ns3::NodeContainer terminals195;
terminals195.Create(15);
//csmaSwitch196 nodes
ns3::NodeContainer terminals196;
terminals196.Create(15);
//csmaSwitch197 nodes
ns3::NodeContainer terminals197;
terminals197.Create(15);
//csmaSwitch198 nodes
ns3::NodeContainer terminals198;
terminals198.Create(15);
//csmaSwitch199 nodes
ns3::NodeContainer terminals199;
terminals199.Create(15);
//csmaSwitch200 nodes
ns3::NodeContainer terminals200;
terminals200.Create(15);
//csmaSwitch201 nodes
ns3::NodeContainer terminals201;
terminals201.Create(15);
//csmaSwitch202 nodes
ns3::NodeContainer terminals202;
terminals202.Create(15);
//csmaSwitch203 nodes
ns3::NodeContainer terminals203;
terminals203.Create(15);
//csmaSwitch204 nodes
ns3::NodeContainer terminals204;
terminals204.Create(15);
//csmaSwitch205 nodes
ns3::NodeContainer terminals205;
terminals205.Create(15);
//csmaSwitch206 nodes
ns3::NodeContainer terminals206;
terminals206.Create(15);
//csmaSwitch207 nodes
ns3::NodeContainer terminals207;
terminals207.Create(15);
//csmaSwitch208 nodes
ns3::NodeContainer terminals208;
terminals208.Create(15);
//csmaSwitch209 nodes
ns3::NodeContainer terminals209;
terminals209.Create(15);
//csmaSwitch210 nodes
ns3::NodeContainer terminals210;
terminals210.Create(15);
//csmaSwitch211 nodes
ns3::NodeContainer terminals211;
terminals211.Create(15);
//csmaSwitch212 nodes
ns3::NodeContainer terminals212;
terminals212.Create(15);
//csmaSwitch214 nodes
ns3::NodeContainer terminals214;
terminals214.Create(15);
//csmaSwitch215 nodes
ns3::NodeContainer terminals215;
terminals215.Create(15);
//csmaSwitch216 nodes
ns3::NodeContainer terminals216;
terminals216.Create(15);
//csmaSwitch217 nodes
ns3::NodeContainer terminals217;
terminals217.Create(15);
//csmaSwitch218 nodes
ns3::NodeContainer terminals218;
terminals218.Create(15);
//csmaSwitch219 nodes
ns3::NodeContainer terminals219;
terminals219.Create(15);
//csmaSwitch220 nodes
ns3::NodeContainer terminals220;
terminals220.Create(15);
//csmaSwitch221 nodes
ns3::NodeContainer terminals221;
terminals221.Create(15);
//csmaSwitch222 nodes
ns3::NodeContainer terminals222;
terminals222.Create(15);
//csmaSwitch223 nodes
ns3::NodeContainer terminals223;
terminals223.Create(15);
//csmaSwitch224 nodes
ns3::NodeContainer terminals224;
terminals224.Create(15);
//csmaSwitch225 nodes
ns3::NodeContainer terminals225;
terminals225.Create(15);
//csmaSwitch226 nodes
ns3::NodeContainer terminals226;
terminals226.Create(15);
//csmaSwitch227 nodes
ns3::NodeContainer terminals227;
terminals227.Create(15);
//csmaSwitch228 nodes
ns3::NodeContainer terminals228;
terminals228.Create(15);
//csmaSwitch229 nodes
ns3::NodeContainer terminals229;
terminals229.Create(15);
//csmaSwitch230 nodes
ns3::NodeContainer terminals230;
terminals230.Create(15);
//csmaSwitch231 nodes
ns3::NodeContainer terminals231;
terminals231.Create(15);
//csmaSwitch232 nodes
ns3::NodeContainer terminals232;
terminals232.Create(15);
//csmaSwitch233 nodes
ns3::NodeContainer terminals233;
terminals233.Create(15);
//csmaSwitch234 nodes
ns3::NodeContainer terminals234;
terminals234.Create(15);
//csmaSwitch235 nodes
ns3::NodeContainer terminals235;
terminals235.Create(15);
//csmaSwitch236 nodes
ns3::NodeContainer terminals236;
terminals236.Create(15);
//csmaSwitch237 nodes
ns3::NodeContainer terminals237;
terminals237.Create(15);
//csmaSwitch238 nodes
ns3::NodeContainer terminals238;
terminals238.Create(15);
//csmaSwitch239 nodes
ns3::NodeContainer terminals239;
terminals239.Create(15);
//csmaSwitch240 nodes
ns3::NodeContainer terminals240;
terminals240.Create(15);
//csmaSwitch241 nodes
ns3::NodeContainer terminals241;
terminals241.Create(15);
//csmaSwitch242 nodes
ns3::NodeContainer terminals242;
terminals242.Create(15);
//csmaSwitch243 nodes
ns3::NodeContainer terminals243;
terminals243.Create(15);
//csmaSwitch244 nodes
ns3::NodeContainer terminals244;
terminals244.Create(15);
//csmaSwitch245 nodes
ns3::NodeContainer terminals245;
terminals245.Create(15);
//csmaSwitch246 nodes
ns3::NodeContainer terminals246;
terminals246.Create(15);
//csmaSwitch247 nodes
ns3::NodeContainer terminals247;
terminals247.Create(15);
//csmaSwitch248 nodes
ns3::NodeContainer terminals248;
terminals248.Create(15);
//csmaSwitch284 nodes
ns3::NodeContainer terminals284;
terminals284.Create(15);
//csmaSwitch249 nodes
ns3::NodeContainer terminals249;
terminals249.Create(15);
//csmaSwitch250 nodes
ns3::NodeContainer terminals250;
terminals250.Create(15);
//csmaSwitch251 nodes
ns3::NodeContainer terminals251;
terminals251.Create(15);
//csmaSwitch252 nodes
ns3::NodeContainer terminals252;
terminals252.Create(15);
//csmaSwitch253 nodes
ns3::NodeContainer terminals253;
terminals253.Create(15);
//csmaSwitch254 nodes
ns3::NodeContainer terminals254;
terminals254.Create(15);
//csmaSwitch255 nodes
ns3::NodeContainer terminals255;
terminals255.Create(15);
//csmaSwitch256 nodes
ns3::NodeContainer terminals256;
terminals256.Create(15);
//csmaSwitch257 nodes
ns3::NodeContainer terminals257;
terminals257.Create(15);
//csmaSwitch258 nodes
ns3::NodeContainer terminals258;
terminals258.Create(15);
//csmaSwitch259 nodes
ns3::NodeContainer terminals259;
terminals259.Create(15);
//csmaSwitch260 nodes
ns3::NodeContainer terminals260;
terminals260.Create(15);
//csmaSwitch261 nodes
ns3::NodeContainer terminals261;
terminals261.Create(15);
//csmaSwitch262 nodes
ns3::NodeContainer terminals262;
terminals262.Create(15);
//csmaSwitch263 nodes
ns3::NodeContainer terminals263;
terminals263.Create(15);
//csmaSwitch264 nodes
ns3::NodeContainer terminals264;
terminals264.Create(15);
//csmaSwitch265 nodes
ns3::NodeContainer terminals265;
terminals265.Create(15);
//csmaSwitch266 nodes
ns3::NodeContainer terminals266;
terminals266.Create(15);
//csmaSwitch267 nodes
ns3::NodeContainer terminals267;
terminals267.Create(15);
//csmaSwitch268 nodes
ns3::NodeContainer terminals268;
terminals268.Create(15);
//csmaSwitch269 nodes
ns3::NodeContainer terminals269;
terminals269.Create(15);
//csmaSwitch270 nodes
ns3::NodeContainer terminals270;
terminals270.Create(15);
//csmaSwitch272 nodes
ns3::NodeContainer terminals272;
terminals272.Create(15);
//csmaSwitch273 nodes
ns3::NodeContainer terminals273;
terminals273.Create(15);
//csmaSwitch274 nodes
ns3::NodeContainer terminals274;
terminals274.Create(15);
//csmaSwitch275 nodes
ns3::NodeContainer terminals275;
terminals275.Create(15);
//csmaSwitch276 nodes
ns3::NodeContainer terminals276;
terminals276.Create(15);
//csmaSwitch277 nodes
ns3::NodeContainer terminals277;
terminals277.Create(15);
//csmaSwitch278 nodes
ns3::NodeContainer terminals278;
terminals278.Create(15);
//csmaSwitch279 nodes
ns3::NodeContainer terminals279;
terminals279.Create(15);
//csmaSwitch280 nodes
ns3::NodeContainer terminals280;
terminals280.Create(15);
//csmaSwitch281 nodes
ns3::NodeContainer terminals281;
terminals281.Create(15);
//csmaSwitch282 nodes
ns3::NodeContainer terminals282;
terminals282.Create(15);
//csmaSwitch283 nodes
ns3::NodeContainer terminals283;
terminals283.Create(15);
//csmaSwitch285 nodes
ns3::NodeContainer terminals285;
terminals285.Create(15);
//csmaSwitch286 nodes
ns3::NodeContainer terminals286;
terminals286.Create(15);
//csmaSwitch287 nodes
ns3::NodeContainer terminals287;
terminals287.Create(15);
//csmaSwitch288 nodes
ns3::NodeContainer terminals288;
terminals288.Create(15);
//csmaSwitch289 nodes
ns3::NodeContainer terminals289;
terminals289.Create(15);
//csmaSwitch290 nodes
ns3::NodeContainer terminals290;
terminals290.Create(15);
//csmaSwitch291 nodes
ns3::NodeContainer terminals291;
terminals291.Create(15);
//csmaSwitch292 nodes
ns3::NodeContainer terminals292;
terminals292.Create(15);
//csmaSwitch293 nodes
ns3::NodeContainer terminals293;
terminals293.Create(15);
//csmaSwitch294 nodes
ns3::NodeContainer terminals294;
terminals294.Create(15);
//csmaSwitch295 nodes
ns3::NodeContainer terminals295;
terminals295.Create(15);
//csmaSwitch296 nodes
ns3::NodeContainer terminals296;
terminals296.Create(15);
//csmaSwitch297 nodes
ns3::NodeContainer terminals297;
terminals297.Create(15);
//csmaSwitch298 nodes
ns3::NodeContainer terminals298;
terminals298.Create(15);
//csmaSwitch299 nodes
ns3::NodeContainer terminals299;
terminals299.Create(15);
//csmaSwitch300 nodes
ns3::NodeContainer terminals300;
terminals300.Create(15);
//csmaSwitch301 nodes
ns3::NodeContainer terminals301;
terminals301.Create(15);
//csmaSwitch302 nodes
ns3::NodeContainer terminals302;
terminals302.Create(15);
//csmaSwitch303 nodes
ns3::NodeContainer terminals303;
terminals303.Create(15);
//csmaSwitch304 nodes
ns3::NodeContainer terminals304;
terminals304.Create(15);
//csmaSwitch305 nodes
ns3::NodeContainer terminals305;
terminals305.Create(15);
//csmaSwitch306 nodes
ns3::NodeContainer terminals306;
terminals306.Create(15);
//csmaSwitch307 nodes
ns3::NodeContainer terminals307;
terminals307.Create(15);
//csmaSwitch308 nodes
ns3::NodeContainer terminals308;
terminals308.Create(15);
//csmaSwitch309 nodes
ns3::NodeContainer terminals309;
terminals309.Create(15);
//csmaSwitch310 nodes
ns3::NodeContainer terminals310;
terminals310.Create(15);
//csmaSwitch311 nodes
ns3::NodeContainer terminals311;
terminals311.Create(15);
//csmaSwitch312 nodes
ns3::NodeContainer terminals312;
terminals312.Create(15);
//csmaSwitch313 nodes
ns3::NodeContainer terminals313;
terminals313.Create(15);
//csmaSwitch314 nodes
ns3::NodeContainer terminals314;
terminals314.Create(15);
//csmaSwitch315 nodes
ns3::NodeContainer terminals315;
terminals315.Create(15);
//csmaSwitch316 nodes
ns3::NodeContainer terminals316;
terminals316.Create(15);
//csmaSwitch317 nodes
ns3::NodeContainer terminals317;
terminals317.Create(15);
//csmaSwitch318 nodes
ns3::NodeContainer terminals318;
terminals318.Create(15);
//csmaSwitch319 nodes
ns3::NodeContainer terminals319;
terminals319.Create(15);
//csmaSwitch320 nodes
ns3::NodeContainer terminals320;
terminals320.Create(15);
//csmaSwitch321 nodes
ns3::NodeContainer terminals321;
terminals321.Create(15);
//csmaSwitch322 nodes
ns3::NodeContainer terminals322;
terminals322.Create(15);
//csmaSwitch323 nodes
ns3::NodeContainer terminals323;
terminals323.Create(15);
//csmaSwitch324 nodes
ns3::NodeContainer terminals324;
terminals324.Create(15);
//csmaSwitch325 nodes
ns3::NodeContainer terminals325;
terminals325.Create(15);
//csmaSwitch326 nodes
ns3::NodeContainer terminals326;
terminals326.Create(15);
//csmaSwitch327 nodes
ns3::NodeContainer terminals327;
terminals327.Create(15);
//csmaSwitch328 nodes
ns3::NodeContainer terminals328;
terminals328.Create(15);
//csmaSwitch329 nodes
ns3::NodeContainer terminals329;
terminals329.Create(15);
//csmaSwitch330 nodes
ns3::NodeContainer terminals330;
terminals330.Create(15);
//csmaSwitch331 nodes
ns3::NodeContainer terminals331;
terminals331.Create(15);
//csmaSwitch332 nodes
ns3::NodeContainer terminals332;
terminals332.Create(15);
//csmaSwitch334 nodes
ns3::NodeContainer terminals334;
terminals334.Create(15);
//csmaSwitch335 nodes
ns3::NodeContainer terminals335;
terminals335.Create(15);
//csmaSwitch336 nodes
ns3::NodeContainer terminals336;
terminals336.Create(15);
//csmaSwitch337 nodes
ns3::NodeContainer terminals337;
terminals337.Create(15);
//csmaSwitch338 nodes
ns3::NodeContainer terminals338;
terminals338.Create(15);
//csmaSwitch339 nodes
ns3::NodeContainer terminals339;
terminals339.Create(15);
//csmaSwitch340 nodes
ns3::NodeContainer terminals340;
terminals340.Create(15);
//csmaSwitch341 nodes
ns3::NodeContainer terminals341;
terminals341.Create(15);
//csmaSwitch342 nodes
ns3::NodeContainer terminals342;
terminals342.Create(15);
//csmaSwitch343 nodes
ns3::NodeContainer terminals343;
terminals343.Create(15);
//csmaSwitch344 nodes
ns3::NodeContainer terminals344;
terminals344.Create(15);
//csmaSwitch345 nodes
ns3::NodeContainer terminals345;
terminals345.Create(15);
//csmaSwitch346 nodes
ns3::NodeContainer terminals346;
terminals346.Create(15);
//csmaSwitch347 nodes
ns3::NodeContainer terminals347;
terminals347.Create(15);
//csmaSwitch348 nodes
ns3::NodeContainer terminals348;
terminals348.Create(15);
#endif
