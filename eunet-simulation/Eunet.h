/*
 * Eunet.h
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#ifndef EUNET_H_
#define EUNET_H_
#include "SwitchNode.h"
#include "WifiStaNodeSet.h"
#include "WifiApNode.h"
#include "DefaultWifiPhyHelper.h"
#include "Terminal.h"

class Eunet {
public:
	enum {
		INTERNET_ROUTER_INDEX = 0,
		CORE_SWITCH_INDEX = 1,
		JYOUHOKU_SWITCH_INDEX = 2,
		SHIGENOBU_SWITCH_INDEX = 3,
		TARUMI_SWITCH_INDEX = 4
	};

private:
	TopologyHelper topology_helper;
	SwitchNodes csmaSwitches;
//	SwitchNodeP core_switch;
//	SwitchNodeP jyouhoku_switch;
//	SwitchNodeP shigenobu_switch;
//	SwitchNodeP tarumi_switch;
	std::vector<ns3::Ptr<WifiApNode> > wifi_ap_nodes;
public:
//	SwitchNodeP internet_router;
	SwitchNodeP getSwitch(const size_t i) {
		return csmaSwitches[i];
	}

	void Attach(TerminalSet & terminal_set, const int i_switch) {
		for (size_t i = 0; i < terminal_set.size(); ++i) {
			SimpleNode & terminal = terminal_set[i];
			assert( 0 == terminal.countNetDevices());
			topology_helper.InstallCsmaLink(terminal, *csmaSwitches[i_switch],
					5000000, 2);
		}	// for
	}	//Attach

	void Attach(WifiStaNodeSet & wifi_sta_node_set, const int i_wifi_ap) {
		DefaultWifiPhyHelper* p_default_wifi_phy_helper =
				new DefaultWifiPhyHelper();
		wifi_sta_node_set.install(*p_default_wifi_phy_helper);
		wifi_ap_nodes[i_wifi_ap]->install(*p_default_wifi_phy_helper);
		delete p_default_wifi_phy_helper;
	}	//Attach

	Eunet() :
			csmaSwitches(350) {
//		internet_router = csmaSwitches.Create("the most external router");
//		core_switch = csmaSwitches.Create("jouhoku--sigenobu--tarumi--motida");
//		jyouhoku_switch = csmaSwitches.Create(
//				"sougoujouhoumediacenter 2F network-kanrisitu-main");
//		shigenobu_switch = csmaSwitches.Create(
//				"2F serversitu-mediacenterbunsitu-main");
//		tarumi_switch = csmaSwitches.Create(
//				"3F serversitu-mediacenterbunsitu-left-main");
//
		for (int i = 0; i < 350; ++i) {
			wifi_ap_nodes.push_back(new WifiApNode);
		} //for

		topology_helper.InstallCsmaLink(*csmaSwitches[INTERNET_ROUTER_INDEX],
				*csmaSwitches[CORE_SWITCH_INDEX], 1000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[CORE_SWITCH_INDEX],
				*csmaSwitches[SHIGENOBU_SWITCH_INDEX], 22000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[CORE_SWITCH_INDEX],
				*csmaSwitches[TARUMI_SWITCH_INDEX], 22000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[CORE_SWITCH_INDEX],
				*csmaSwitches[335], 22000000000, 2); //motida
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[285], 22000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[CORE_SWITCH_INDEX],
				*csmaSwitches[JYOUHOKU_SWITCH_INDEX], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[9], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[7], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[80], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[126], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[161], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[275], 20000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[5], *csmaSwitches[6],
				16000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[40], 11000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[70], 11000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[141], 11000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[197], 11000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[226], 8000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[316], 8000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[5], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[8], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[113], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[160], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[213], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[283], 7000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[333], 7000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[334], *csmaSwitches[335],
				6000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[266], 4000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[276], 4000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[81], *wifi_ap_nodes[1],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[82], *wifi_ap_nodes[2],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[83], *wifi_ap_nodes[3],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *wifi_ap_nodes[4],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[108], *wifi_ap_nodes[5],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[86], *wifi_ap_nodes[6],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[86], *wifi_ap_nodes[7],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[87], *wifi_ap_nodes[8],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[109], *wifi_ap_nodes[9],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[88], *wifi_ap_nodes[10],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[88], *wifi_ap_nodes[11],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[111], *wifi_ap_nodes[12],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[111], *wifi_ap_nodes[13],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[89], *wifi_ap_nodes[14],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[92], *wifi_ap_nodes[15],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[101], *wifi_ap_nodes[16],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[94], *wifi_ap_nodes[17],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[94], *wifi_ap_nodes[18],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[95], *wifi_ap_nodes[19],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[103], *wifi_ap_nodes[20],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[97], *wifi_ap_nodes[21],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[105], *wifi_ap_nodes[22],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *wifi_ap_nodes[23],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[86], *wifi_ap_nodes[24],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[87], *wifi_ap_nodes[25],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[162], *wifi_ap_nodes[26],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[162], *wifi_ap_nodes[27],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[162], *wifi_ap_nodes[28],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[29],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[163], *wifi_ap_nodes[30],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[164], *wifi_ap_nodes[31],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[165], *wifi_ap_nodes[32],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[165], *wifi_ap_nodes[33],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[165], *wifi_ap_nodes[34],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[169], *wifi_ap_nodes[35],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[169], *wifi_ap_nodes[36],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[180], *wifi_ap_nodes[37],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[180], *wifi_ap_nodes[38],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[182], *wifi_ap_nodes[313],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *wifi_ap_nodes[39],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[185], *wifi_ap_nodes[40],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[187], *wifi_ap_nodes[41],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[189], *wifi_ap_nodes[42],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[191], *wifi_ap_nodes[43],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[194], *wifi_ap_nodes[44],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[195], *wifi_ap_nodes[45],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[196], *wifi_ap_nodes[46],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[196], *wifi_ap_nodes[47],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[48],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[49],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[50],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[51],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[52],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[343], *wifi_ap_nodes[53],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *wifi_ap_nodes[54],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[205], *wifi_ap_nodes[55],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[205], *wifi_ap_nodes[56],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[204], *wifi_ap_nodes[57],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[204], *wifi_ap_nodes[58],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[211], *wifi_ap_nodes[59],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[60],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[61],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[62],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[63],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[64],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[65],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[294], *wifi_ap_nodes[66],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[294], *wifi_ap_nodes[67],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[288], *wifi_ap_nodes[68],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[288], *wifi_ap_nodes[69],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[288], *wifi_ap_nodes[70],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[300], *wifi_ap_nodes[71],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[299], *wifi_ap_nodes[72],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[302], *wifi_ap_nodes[73],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[301], *wifi_ap_nodes[74],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[318], *wifi_ap_nodes[75],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[318], *wifi_ap_nodes[76],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[319], *wifi_ap_nodes[77],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[320], *wifi_ap_nodes[78],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[322], *wifi_ap_nodes[79],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[308], *wifi_ap_nodes[80],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[323], *wifi_ap_nodes[81],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[324], *wifi_ap_nodes[82],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[311], *wifi_ap_nodes[83],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[311], *wifi_ap_nodes[84],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[311], *wifi_ap_nodes[85],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[313], *wifi_ap_nodes[86],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[312], *wifi_ap_nodes[87],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[312], *wifi_ap_nodes[88],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[314], *wifi_ap_nodes[89],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[314], *wifi_ap_nodes[90],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[315], *wifi_ap_nodes[91],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[315], *wifi_ap_nodes[92],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[93],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[94],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[95],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[96],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[97],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[330], *wifi_ap_nodes[98],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[331], *wifi_ap_nodes[99],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[331], *wifi_ap_nodes[100],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[101],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[102],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[315], *wifi_ap_nodes[103],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[315], *wifi_ap_nodes[104],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *wifi_ap_nodes[105],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *wifi_ap_nodes[106],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *wifi_ap_nodes[107],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *wifi_ap_nodes[108],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *wifi_ap_nodes[109],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[110],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[111],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[112],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[113],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[327], *wifi_ap_nodes[114],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[327], *wifi_ap_nodes[115],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[327], *wifi_ap_nodes[116],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[117],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[118],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[119],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[120],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[121],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[122],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[326], *wifi_ap_nodes[123],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[294], *wifi_ap_nodes[124],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[125],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[126],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[127],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[332], *wifi_ap_nodes[128],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[215], *wifi_ap_nodes[129],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[217], *wifi_ap_nodes[130],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[218], *wifi_ap_nodes[131],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[219], *wifi_ap_nodes[132],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[221], *wifi_ap_nodes[133],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[221], *wifi_ap_nodes[134],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[222], *wifi_ap_nodes[135],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[222], *wifi_ap_nodes[136],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *wifi_ap_nodes[137],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *wifi_ap_nodes[138],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[227], *wifi_ap_nodes[139],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[228], *wifi_ap_nodes[140],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[224], *wifi_ap_nodes[141],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[225], *wifi_ap_nodes[142],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[225], *wifi_ap_nodes[143],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[284], *wifi_ap_nodes[144],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[259], *wifi_ap_nodes[145],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[259], *wifi_ap_nodes[146],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[147],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[148],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[261], *wifi_ap_nodes[149],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[262], *wifi_ap_nodes[150],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[262], *wifi_ap_nodes[151],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[152],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[153],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[154],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[155],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[156],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[157],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[158],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[159],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[160],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[161],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[162],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[214], *wifi_ap_nodes[163],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[269], *wifi_ap_nodes[164],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[270], *wifi_ap_nodes[165],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[273], *wifi_ap_nodes[166],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[277], *wifi_ap_nodes[167],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[278], *wifi_ap_nodes[168],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[280], *wifi_ap_nodes[169],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[282], *wifi_ap_nodes[170],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[263], *wifi_ap_nodes[171],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[238], *wifi_ap_nodes[172],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[238], *wifi_ap_nodes[173],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[174],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[175],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[176],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[177],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[178],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[179],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[260], *wifi_ap_nodes[180],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[268], *wifi_ap_nodes[181],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[234], *wifi_ap_nodes[182],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[235], *wifi_ap_nodes[183],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[235], *wifi_ap_nodes[184],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[231], *wifi_ap_nodes[185],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[231], *wifi_ap_nodes[186],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[231], *wifi_ap_nodes[187],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[231], *wifi_ap_nodes[188],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[138], *wifi_ap_nodes[189],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[138], *wifi_ap_nodes[190],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[139], *wifi_ap_nodes[191],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[139], *wifi_ap_nodes[192],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[140], *wifi_ap_nodes[193],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[140], *wifi_ap_nodes[194],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[140], *wifi_ap_nodes[195],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[140], *wifi_ap_nodes[196],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[197],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[129], *wifi_ap_nodes[198],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[129], *wifi_ap_nodes[199],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[130], *wifi_ap_nodes[200],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[136], *wifi_ap_nodes[201],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[142], *wifi_ap_nodes[202],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[142], *wifi_ap_nodes[203],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[150], *wifi_ap_nodes[204],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[150], *wifi_ap_nodes[205],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[150], *wifi_ap_nodes[206],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[147], *wifi_ap_nodes[207],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[147], *wifi_ap_nodes[208],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[146], *wifi_ap_nodes[209],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[146], *wifi_ap_nodes[210],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[151], *wifi_ap_nodes[211],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[151], *wifi_ap_nodes[212],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[148], *wifi_ap_nodes[213],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[148], *wifi_ap_nodes[214],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[144], *wifi_ap_nodes[215],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[144], *wifi_ap_nodes[216],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[144], *wifi_ap_nodes[217],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[157], *wifi_ap_nodes[218],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[149], *wifi_ap_nodes[219],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[149], *wifi_ap_nodes[220],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[221],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[222],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[223],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[224],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[225],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[226],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[227],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[228],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[229],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *wifi_ap_nodes[230],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[117], *wifi_ap_nodes[231],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[121], *wifi_ap_nodes[232],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[122], *wifi_ap_nodes[233],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[119], *wifi_ap_nodes[234],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[235],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[236],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[52], *wifi_ap_nodes[237],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[52], *wifi_ap_nodes[238],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[52], *wifi_ap_nodes[239],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[54], *wifi_ap_nodes[240],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[56], *wifi_ap_nodes[241],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[56], *wifi_ap_nodes[242],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[57], *wifi_ap_nodes[243],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[71], *wifi_ap_nodes[244],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[71], *wifi_ap_nodes[245],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[71], *wifi_ap_nodes[246],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[247],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[77], *wifi_ap_nodes[248],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[77], *wifi_ap_nodes[249],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[78], *wifi_ap_nodes[250],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[65], *wifi_ap_nodes[251],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[66], *wifi_ap_nodes[252],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[69], *wifi_ap_nodes[253],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[69], *wifi_ap_nodes[254],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[79], *wifi_ap_nodes[255],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[79], *wifi_ap_nodes[256],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *wifi_ap_nodes[257],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[45], *wifi_ap_nodes[258],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[47], *wifi_ap_nodes[259],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[42], *wifi_ap_nodes[260],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[49], *wifi_ap_nodes[261],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[49], *wifi_ap_nodes[262],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[44], *wifi_ap_nodes[263],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[344], *wifi_ap_nodes[264],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[345], *wifi_ap_nodes[265],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[345], *wifi_ap_nodes[266],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[18], *wifi_ap_nodes[267],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[18], *wifi_ap_nodes[268],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[18], *wifi_ap_nodes[269],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[19], *wifi_ap_nodes[270],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[27], *wifi_ap_nodes[271],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[346], *wifi_ap_nodes[272],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[346], *wifi_ap_nodes[273],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[79], *wifi_ap_nodes[274],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[79], *wifi_ap_nodes[275],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[276],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[277],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[278],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[279],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[280],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[281],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[282],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[283],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[284],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[57], *wifi_ap_nodes[285],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *wifi_ap_nodes[286],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[58], *wifi_ap_nodes[287],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[58], *wifi_ap_nodes[288],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[289],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[290],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[291],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[114], *wifi_ap_nodes[292],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[347], *wifi_ap_nodes[293],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[348], *wifi_ap_nodes[294],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[65], *wifi_ap_nodes[295],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[346], *wifi_ap_nodes[296],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[346], *wifi_ap_nodes[297],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[339], *wifi_ap_nodes[300],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[338], *wifi_ap_nodes[301],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[338], *wifi_ap_nodes[302],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *wifi_ap_nodes[303],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *wifi_ap_nodes[304],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *wifi_ap_nodes[305],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *wifi_ap_nodes[307],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *wifi_ap_nodes[308],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[342], *wifi_ap_nodes[309],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[338], *wifi_ap_nodes[310],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[339], *wifi_ap_nodes[311],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[339], *wifi_ap_nodes[312],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[342], *wifi_ap_nodes[314],
				2000000000, 2);

		//switch link
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[11],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[11],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[11], *wifi_ap_nodes[14],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[15],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[17],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[18],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[19],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[20],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[20], *wifi_ap_nodes[21],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[24], *wifi_ap_nodes[25],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[29],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[30],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[33],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[34],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[35],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[37],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[38],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *wifi_ap_nodes[39],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*wifi_ap_nodes[50], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[50], *wifi_ap_nodes[51],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[52],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[53],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[53], *wifi_ap_nodes[54],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[51], *wifi_ap_nodes[55],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[55], *wifi_ap_nodes[56],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[50], *wifi_ap_nodes[57],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[50], *wifi_ap_nodes[58],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[50], *wifi_ap_nodes[59],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *wifi_ap_nodes[60],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *wifi_ap_nodes[61],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *wifi_ap_nodes[62],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[64], *wifi_ap_nodes[65],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[64], *wifi_ap_nodes[66],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[64], *wifi_ap_nodes[68],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[64], *wifi_ap_nodes[69],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[71],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[72],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[72], *wifi_ap_nodes[73],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[74],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[74], *wifi_ap_nodes[75],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[76],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[76], *wifi_ap_nodes[77],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[70], *wifi_ap_nodes[78],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*wifi_ap_nodes[79], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[80], *wifi_ap_nodes[81],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[81], *wifi_ap_nodes[82],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[81], *wifi_ap_nodes[84],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[80], *wifi_ap_nodes[85],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[80], *wifi_ap_nodes[99],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[114], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[115], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[116], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[123], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[127],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[128],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[129],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[130],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[131],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[132],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[132], *wifi_ap_nodes[133],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[132], *wifi_ap_nodes[134],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[132], *wifi_ap_nodes[135],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[132], *wifi_ap_nodes[136],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[126], *wifi_ap_nodes[137],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[141], *wifi_ap_nodes[142],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[141], *wifi_ap_nodes[143],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[141], *wifi_ap_nodes[144],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[141], *wifi_ap_nodes[145],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[142], *wifi_ap_nodes[146],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[143], *wifi_ap_nodes[149],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[145], *wifi_ap_nodes[150],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[150], *wifi_ap_nodes[151],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[150], *wifi_ap_nodes[154],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[145], *wifi_ap_nodes[158],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[165],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[167],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *wifi_ap_nodes[172],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[178],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[180],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[180], *wifi_ap_nodes[181],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *wifi_ap_nodes[183],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[193], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[JYOUHOKU_SWITCH_INDEX],
				*csmaSwitches[200], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[200], *wifi_ap_nodes[201],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[201], *wifi_ap_nodes[202],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[201], *wifi_ap_nodes[203],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[201], *wifi_ap_nodes[204],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[200], *wifi_ap_nodes[206],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *wifi_ap_nodes[208],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[208], *wifi_ap_nodes[209],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[208], *wifi_ap_nodes[210],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[208], *wifi_ap_nodes[211],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[214], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[215], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[217], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[220], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *wifi_ap_nodes[227],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[227], *wifi_ap_nodes[228],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *wifi_ap_nodes[229],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *wifi_ap_nodes[230],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *wifi_ap_nodes[231],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *wifi_ap_nodes[248],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *wifi_ap_nodes[256],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[256], *wifi_ap_nodes[257],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[256], *wifi_ap_nodes[258],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[256], *wifi_ap_nodes[259],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *wifi_ap_nodes[260],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[SHIGENOBU_SWITCH_INDEX],
				*csmaSwitches[264], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[287], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[288], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[290], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[291], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[291], *wifi_ap_nodes[294],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[295], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[296],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[300],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *wifi_ap_nodes[301],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[304], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[304], *wifi_ap_nodes[305],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[304], *wifi_ap_nodes[306],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[304], *wifi_ap_nodes[308],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[304], *wifi_ap_nodes[309],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[304], *wifi_ap_nodes[310],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[311], 2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[312], 2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[312], *wifi_ap_nodes[313],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[312], *wifi_ap_nodes[314],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *wifi_ap_nodes[317],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[317], *wifi_ap_nodes[318],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[317], *wifi_ap_nodes[319],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[317], *wifi_ap_nodes[320],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[321], *wifi_ap_nodes[322],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[321], *wifi_ap_nodes[323],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[321], *wifi_ap_nodes[324],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *wifi_ap_nodes[325],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *wifi_ap_nodes[327],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *wifi_ap_nodes[328],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *wifi_ap_nodes[331],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[331], *wifi_ap_nodes[332],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[197], *wifi_ap_nodes[343],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[45], *wifi_ap_nodes[344],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *wifi_ap_nodes[345],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *wifi_ap_nodes[346],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *wifi_ap_nodes[347],
				2000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *wifi_ap_nodes[348],
				2000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[10],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[11], *csmaSwitches[12],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[11], *csmaSwitches[13],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[15], *csmaSwitches[16],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[22],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[23],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[24],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[24], *csmaSwitches[26],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[24], *csmaSwitches[27],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[24], *csmaSwitches[28],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[31],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[32],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[9], *csmaSwitches[36],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[40], *csmaSwitches[41],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *csmaSwitches[42],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *csmaSwitches[43],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *csmaSwitches[44],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[41], *csmaSwitches[45],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[45], *csmaSwitches[46],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[46], *csmaSwitches[47],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[45], *csmaSwitches[48],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[45], *csmaSwitches[49],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *csmaSwitches[63],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[59], *csmaSwitches[64],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[66], *csmaSwitches[67],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[81], *csmaSwitches[83],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *csmaSwitches[86],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *csmaSwitches[87],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *csmaSwitches[88],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[85], *csmaSwitches[89],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[89], *csmaSwitches[90],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[80], *csmaSwitches[91],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[92],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[93],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[94],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[95],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[96],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[97],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[91], *csmaSwitches[98],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[99], *csmaSwitches[100],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[101],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[102],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[103],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[104],
				1000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[105],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[100], *csmaSwitches[106],
				1000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[99], *csmaSwitches[99],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[107], *csmaSwitches[107],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[107], *csmaSwitches[107],
				1000000000, 2);

		topology_helper.InstallCsmaLink(*csmaSwitches[107], *csmaSwitches[110],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[107], *csmaSwitches[111],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[99], *csmaSwitches[112],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[117],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[118],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[119],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[120],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[121],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[116], *csmaSwitches[122],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[123], *csmaSwitches[124],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[123], *csmaSwitches[125],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[137], *csmaSwitches[138],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[137], *csmaSwitches[139],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[137], *csmaSwitches[140],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[146], *csmaSwitches[147],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[146], *csmaSwitches[148],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[151], *csmaSwitches[152],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[151], *csmaSwitches[153],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[154], *csmaSwitches[155],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[154], *csmaSwitches[156],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[154], *csmaSwitches[157],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[158], *csmaSwitches[159],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *csmaSwitches[162],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *csmaSwitches[163],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *csmaSwitches[164],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[161], *csmaSwitches[166],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *csmaSwitches[168],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *csmaSwitches[169],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *csmaSwitches[170],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *csmaSwitches[171],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[172], *csmaSwitches[173],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[172], *csmaSwitches[174],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[174], *csmaSwitches[175],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[167], *csmaSwitches[176],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[176], *csmaSwitches[177],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[178], *csmaSwitches[179],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[181], *csmaSwitches[182],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[184],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[185],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[186],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[187],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[188],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[189],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[190],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[191],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[183], *csmaSwitches[192],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[193], *csmaSwitches[194],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[193], *csmaSwitches[195],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[193], *csmaSwitches[196],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[197], *csmaSwitches[198],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[197], *csmaSwitches[199],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[200], *csmaSwitches[205],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *csmaSwitches[207],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[206], *csmaSwitches[212],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[215], *csmaSwitches[216],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[217], *csmaSwitches[218],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[217], *csmaSwitches[219],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *csmaSwitches[221],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *csmaSwitches[222],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *csmaSwitches[223],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *csmaSwitches[224],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[220], *csmaSwitches[225],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[231], *csmaSwitches[232],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[233],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[234],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[235],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[236],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[237],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[238],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[239],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[240],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[241],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[242],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[243],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[244],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[245],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[246],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[230], *csmaSwitches[247],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[284],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[249],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[250],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[251],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[252],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[253],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[254],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[248], *csmaSwitches[255],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *csmaSwitches[261],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *csmaSwitches[262],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[226], *csmaSwitches[263],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[264], *csmaSwitches[265],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[267],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[268],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[269],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[270],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[270], *csmaSwitches[272],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[273],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[266], *csmaSwitches[274],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[276], *csmaSwitches[277],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[276], *csmaSwitches[278],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[278], *csmaSwitches[279],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[276], *csmaSwitches[280],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[280], *csmaSwitches[281],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[276], *csmaSwitches[282],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[TARUMI_SWITCH_INDEX],
				*csmaSwitches[286], 1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[288], *csmaSwitches[289],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[291], *csmaSwitches[292],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[291], *csmaSwitches[293],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *csmaSwitches[297],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[297], *csmaSwitches[298],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *csmaSwitches[299],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *csmaSwitches[302],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[295], *csmaSwitches[303],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[304], *csmaSwitches[307],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[312], *csmaSwitches[315],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[317], *csmaSwitches[321],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[316], *csmaSwitches[326],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *csmaSwitches[329],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[328], *csmaSwitches[330],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[335], *csmaSwitches[336],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[336], *csmaSwitches[337],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[336], *csmaSwitches[338],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[336], *csmaSwitches[339],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[336], *csmaSwitches[340],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[340], *csmaSwitches[341],
				1000000000, 2);
		topology_helper.InstallCsmaLink(*csmaSwitches[336], *csmaSwitches[342],
				1000000000, 2);

		//apDevices switchDevices setuzoku
		for (int i = 1; i <= 315; ++i) {
			if (i == 298 || i == 299 || i == 306 || i == 315)
				continue;
			wifi_ap_nodes[i]->installBridgeDevice();
		}	//for
	}	// the default constructor
	virtual ~Eunet() {

	}
};

#endif /* EUNET_H_ */
