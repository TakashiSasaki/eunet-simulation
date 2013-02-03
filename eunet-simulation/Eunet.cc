/*
 * Eunet.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#include "Eunet.h"

void Eunet::InstallCsmaLink() {
	connectSwitchNodes(INTERNET_ROUTER_INDEX, CORE_SWITCH_INDEX, 1000000000, 2);

	connectSwitchNodes(CORE_SWITCH_INDEX, SHIGENOBU_SWITCH_INDEX, 22000000000,
			2);
	connectSwitchNodes(CORE_SWITCH_INDEX, TARUMI_SWITCH_INDEX, 22000000000, 2);
	connectSwitchNodes(CORE_SWITCH_INDEX, 335, 22000000000, 2); //motida
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 285, 22000000000, 2);
	connectSwitchNodes(CORE_SWITCH_INDEX, JYOUHOKU_SWITCH_INDEX, 20000000000,
			2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 9, 20000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 7, 20000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 80, 20000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 126, 20000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 161, 20000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 275, 20000000000, 2);
	connectSwitchNodes(5, 6, 16000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 40, 11000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 70, 11000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 141, 11000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 197, 11000000000, 2);

	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 226, 8000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 316, 8000000000, 2);

	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 5, 7000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 8, 7000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 113, 7000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 160, 7000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 213, 7000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 283, 7000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 333, 7000000000, 2);

	connectSwitchNodes(334, 335, 6000000000, 2);

	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 266, 4000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 276, 4000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[81], *wifi_ap_nodes[1],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[82], *wifi_ap_nodes[2],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[83], *wifi_ap_nodes[3],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[85], *wifi_ap_nodes[4],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[108], *wifi_ap_nodes[5],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[86], *wifi_ap_nodes[6],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[86], *wifi_ap_nodes[7],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[87], *wifi_ap_nodes[8],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[109], *wifi_ap_nodes[9],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[88], *wifi_ap_nodes[10],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[88], *wifi_ap_nodes[11],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[111], *wifi_ap_nodes[12],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[111], *wifi_ap_nodes[13],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[89], *wifi_ap_nodes[14],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[92], *wifi_ap_nodes[15],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[101], *wifi_ap_nodes[16],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[94], *wifi_ap_nodes[17],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[94], *wifi_ap_nodes[18],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[95], *wifi_ap_nodes[19],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[103], *wifi_ap_nodes[20],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[97], *wifi_ap_nodes[21],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[105], *wifi_ap_nodes[22],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[85], *wifi_ap_nodes[23],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[86], *wifi_ap_nodes[24],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[87], *wifi_ap_nodes[25],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[162], *wifi_ap_nodes[26],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[162], *wifi_ap_nodes[27],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[162], *wifi_ap_nodes[28],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[29],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[163], *wifi_ap_nodes[30],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[164], *wifi_ap_nodes[31],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[165], *wifi_ap_nodes[32],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[165], *wifi_ap_nodes[33],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[165], *wifi_ap_nodes[34],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[169], *wifi_ap_nodes[35],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[169], *wifi_ap_nodes[36],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[180], *wifi_ap_nodes[37],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[180], *wifi_ap_nodes[38],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[182], *wifi_ap_nodes[313],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[183], *wifi_ap_nodes[39],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[185], *wifi_ap_nodes[40],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[187], *wifi_ap_nodes[41],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[189], *wifi_ap_nodes[42],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[191], *wifi_ap_nodes[43],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[194], *wifi_ap_nodes[44],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[195], *wifi_ap_nodes[45],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[196], *wifi_ap_nodes[46],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[196], *wifi_ap_nodes[47],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[48],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[49],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[50],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[51],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[52],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[343], *wifi_ap_nodes[53],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[206], *wifi_ap_nodes[54],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[205], *wifi_ap_nodes[55],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[205], *wifi_ap_nodes[56],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[204], *wifi_ap_nodes[57],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[204], *wifi_ap_nodes[58],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[211], *wifi_ap_nodes[59],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[60],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[61],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[62],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[63],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[64],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[65],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[294], *wifi_ap_nodes[66],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[294], *wifi_ap_nodes[67],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[288], *wifi_ap_nodes[68],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[288], *wifi_ap_nodes[69],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[288], *wifi_ap_nodes[70],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[300], *wifi_ap_nodes[71],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[299], *wifi_ap_nodes[72],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[302], *wifi_ap_nodes[73],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[301], *wifi_ap_nodes[74],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[318], *wifi_ap_nodes[75],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[318], *wifi_ap_nodes[76],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[319], *wifi_ap_nodes[77],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[320], *wifi_ap_nodes[78],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[322], *wifi_ap_nodes[79],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[308], *wifi_ap_nodes[80],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[323], *wifi_ap_nodes[81],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[324], *wifi_ap_nodes[82],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[311], *wifi_ap_nodes[83],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[311], *wifi_ap_nodes[84],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[311], *wifi_ap_nodes[85],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[313], *wifi_ap_nodes[86],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[312], *wifi_ap_nodes[87],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[312], *wifi_ap_nodes[88],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[314], *wifi_ap_nodes[89],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[314], *wifi_ap_nodes[90],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[315], *wifi_ap_nodes[91],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[315], *wifi_ap_nodes[92],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[93],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[94],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[95],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[96],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[97],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[330], *wifi_ap_nodes[98],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[331], *wifi_ap_nodes[99],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[331], *wifi_ap_nodes[100],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[101],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[102],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[315], *wifi_ap_nodes[103],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[315], *wifi_ap_nodes[104],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[328], *wifi_ap_nodes[105],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[328], *wifi_ap_nodes[106],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[328], *wifi_ap_nodes[107],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[328], *wifi_ap_nodes[108],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[328], *wifi_ap_nodes[109],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[110],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[111],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[112],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[113],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[327], *wifi_ap_nodes[114],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[327], *wifi_ap_nodes[115],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[327], *wifi_ap_nodes[116],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[117],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[118],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[119],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[120],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[121],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[122],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[326], *wifi_ap_nodes[123],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[294], *wifi_ap_nodes[124],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[125],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[126],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[127],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[332], *wifi_ap_nodes[128],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[215], *wifi_ap_nodes[129],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[217], *wifi_ap_nodes[130],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[218], *wifi_ap_nodes[131],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[219], *wifi_ap_nodes[132],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[221], *wifi_ap_nodes[133],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[221], *wifi_ap_nodes[134],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[222], *wifi_ap_nodes[135],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[222], *wifi_ap_nodes[136],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[220], *wifi_ap_nodes[137],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[220], *wifi_ap_nodes[138],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[227], *wifi_ap_nodes[139],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[228], *wifi_ap_nodes[140],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[224], *wifi_ap_nodes[141],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[225], *wifi_ap_nodes[142],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[225], *wifi_ap_nodes[143],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[284], *wifi_ap_nodes[144],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[259], *wifi_ap_nodes[145],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[259], *wifi_ap_nodes[146],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[147],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[148],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[261], *wifi_ap_nodes[149],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[262], *wifi_ap_nodes[150],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[262], *wifi_ap_nodes[151],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[152],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[153],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[154],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[155],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[156],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[157],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[158],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[159],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[160],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[161],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[162],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[214], *wifi_ap_nodes[163],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[269], *wifi_ap_nodes[164],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[270], *wifi_ap_nodes[165],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[273], *wifi_ap_nodes[166],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[277], *wifi_ap_nodes[167],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[278], *wifi_ap_nodes[168],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[280], *wifi_ap_nodes[169],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[282], *wifi_ap_nodes[170],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[263], *wifi_ap_nodes[171],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[238], *wifi_ap_nodes[172],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[238], *wifi_ap_nodes[173],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[174],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[175],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[176],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[177],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[178],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[179],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[260], *wifi_ap_nodes[180],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[268], *wifi_ap_nodes[181],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[234], *wifi_ap_nodes[182],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[235], *wifi_ap_nodes[183],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[235], *wifi_ap_nodes[184],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[231], *wifi_ap_nodes[185],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[231], *wifi_ap_nodes[186],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[231], *wifi_ap_nodes[187],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[231], *wifi_ap_nodes[188],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[138], *wifi_ap_nodes[189],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[138], *wifi_ap_nodes[190],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[139], *wifi_ap_nodes[191],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[139], *wifi_ap_nodes[192],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[140], *wifi_ap_nodes[193],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[140], *wifi_ap_nodes[194],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[140], *wifi_ap_nodes[195],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[140], *wifi_ap_nodes[196],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[197],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[129], *wifi_ap_nodes[198],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[129], *wifi_ap_nodes[199],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[130], *wifi_ap_nodes[200],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[136], *wifi_ap_nodes[201],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[142], *wifi_ap_nodes[202],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[142], *wifi_ap_nodes[203],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[150], *wifi_ap_nodes[204],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[150], *wifi_ap_nodes[205],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[150], *wifi_ap_nodes[206],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[147], *wifi_ap_nodes[207],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[147], *wifi_ap_nodes[208],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[146], *wifi_ap_nodes[209],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[146], *wifi_ap_nodes[210],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[151], *wifi_ap_nodes[211],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[151], *wifi_ap_nodes[212],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[148], *wifi_ap_nodes[213],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[148], *wifi_ap_nodes[214],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[144], *wifi_ap_nodes[215],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[144], *wifi_ap_nodes[216],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[144], *wifi_ap_nodes[217],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[157], *wifi_ap_nodes[218],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[149], *wifi_ap_nodes[219],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[149], *wifi_ap_nodes[220],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[221],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[222],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[223],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[224],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[225],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[226],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[227],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[228],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[229],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[158], *wifi_ap_nodes[230],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[117], *wifi_ap_nodes[231],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[121], *wifi_ap_nodes[232],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[122], *wifi_ap_nodes[233],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[119], *wifi_ap_nodes[234],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[235],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[236],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[52], *wifi_ap_nodes[237],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[52], *wifi_ap_nodes[238],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[52], *wifi_ap_nodes[239],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[54], *wifi_ap_nodes[240],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[56], *wifi_ap_nodes[241],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[56], *wifi_ap_nodes[242],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[57], *wifi_ap_nodes[243],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[71], *wifi_ap_nodes[244],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[71], *wifi_ap_nodes[245],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[71], *wifi_ap_nodes[246],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[247],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[77], *wifi_ap_nodes[248],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[77], *wifi_ap_nodes[249],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[78], *wifi_ap_nodes[250],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[65], *wifi_ap_nodes[251],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[66], *wifi_ap_nodes[252],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[69], *wifi_ap_nodes[253],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[69], *wifi_ap_nodes[254],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[79], *wifi_ap_nodes[255],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[79], *wifi_ap_nodes[256],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[41], *wifi_ap_nodes[257],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[45], *wifi_ap_nodes[258],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[47], *wifi_ap_nodes[259],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[42], *wifi_ap_nodes[260],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[49], *wifi_ap_nodes[261],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[49], *wifi_ap_nodes[262],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[44], *wifi_ap_nodes[263],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[344], *wifi_ap_nodes[264],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[345], *wifi_ap_nodes[265],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[345], *wifi_ap_nodes[266],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[18], *wifi_ap_nodes[267],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[18], *wifi_ap_nodes[268],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[18], *wifi_ap_nodes[269],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[19], *wifi_ap_nodes[270],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[27], *wifi_ap_nodes[271],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[346], *wifi_ap_nodes[272],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[346], *wifi_ap_nodes[273],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[79], *wifi_ap_nodes[274],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[79], *wifi_ap_nodes[275],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[276],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[277],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[278],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[279],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[280],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[281],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[282],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[283],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[284],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[57], *wifi_ap_nodes[285],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[59], *wifi_ap_nodes[286],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[58], *wifi_ap_nodes[287],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[58], *wifi_ap_nodes[288],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[289],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[290],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[291],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[114], *wifi_ap_nodes[292],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[347], *wifi_ap_nodes[293],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[348], *wifi_ap_nodes[294],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[65], *wifi_ap_nodes[295],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[346], *wifi_ap_nodes[296],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[346], *wifi_ap_nodes[297],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[339], *wifi_ap_nodes[300],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[338], *wifi_ap_nodes[301],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[338], *wifi_ap_nodes[302],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[335], *wifi_ap_nodes[303],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[335], *wifi_ap_nodes[304],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[335], *wifi_ap_nodes[305],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[335], *wifi_ap_nodes[307],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[335], *wifi_ap_nodes[308],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[342], *wifi_ap_nodes[309],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[338], *wifi_ap_nodes[310],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[339], *wifi_ap_nodes[311],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[339], *wifi_ap_nodes[312],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[342], *wifi_ap_nodes[314],
			2000000000, 2);

	//switch link
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[11],
			2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[11],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[11], *wifi_ap_nodes[14],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[15],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[17],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[18],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[19],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[20],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[20], *wifi_ap_nodes[21],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[24], *wifi_ap_nodes[25],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[29],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[30],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[33],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[34],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[35],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[37],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[38],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[9], *wifi_ap_nodes[39],
			2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[JYOUHOKU_SWITCH_INDEX],
			*wifi_ap_nodes[50], 2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[50], *wifi_ap_nodes[51],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[52],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[53],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[53], *wifi_ap_nodes[54],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[51], *wifi_ap_nodes[55],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[55], *wifi_ap_nodes[56],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[50], *wifi_ap_nodes[57],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[50], *wifi_ap_nodes[58],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[50], *wifi_ap_nodes[59],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[59], *wifi_ap_nodes[60],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[59], *wifi_ap_nodes[61],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[59], *wifi_ap_nodes[62],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[64], *wifi_ap_nodes[65],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[64], *wifi_ap_nodes[66],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[64], *wifi_ap_nodes[68],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[64], *wifi_ap_nodes[69],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[71],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[72],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[72], *wifi_ap_nodes[73],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[74],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[74], *wifi_ap_nodes[75],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[76],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[76], *wifi_ap_nodes[77],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[70], *wifi_ap_nodes[78],
			2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[JYOUHOKU_SWITCH_INDEX],
			*wifi_ap_nodes[79], 2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[80], *wifi_ap_nodes[81],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[81], *wifi_ap_nodes[82],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[81], *wifi_ap_nodes[84],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[80], *wifi_ap_nodes[85],
			2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[80], *wifi_ap_nodes[99],
			2000000000, 2);

	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 114, 2000000000, 2);

	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 115, 2000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 116, 2000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 123, 2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[127],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[128],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[129],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[130],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[131],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[132],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[132], *wifi_ap_nodes[133],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[132], *wifi_ap_nodes[134],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[132], *wifi_ap_nodes[135],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[132], *wifi_ap_nodes[136],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[126], *wifi_ap_nodes[137],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[141], *wifi_ap_nodes[142],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[141], *wifi_ap_nodes[143],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[141], *wifi_ap_nodes[144],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[141], *wifi_ap_nodes[145],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[142], *wifi_ap_nodes[146],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[143], *wifi_ap_nodes[149],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[145], *wifi_ap_nodes[150],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[150], *wifi_ap_nodes[151],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[150], *wifi_ap_nodes[154],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[145], *wifi_ap_nodes[158],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[165],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[167],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[167], *wifi_ap_nodes[172],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[178],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[180],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[180], *wifi_ap_nodes[181],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[161], *wifi_ap_nodes[183],
			2000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 193, 2000000000, 2);
	connectSwitchNodes(JYOUHOKU_SWITCH_INDEX, 200, 2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[200], *wifi_ap_nodes[201],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[201], *wifi_ap_nodes[202],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[201], *wifi_ap_nodes[203],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[201], *wifi_ap_nodes[204],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[200], *wifi_ap_nodes[206],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[206], *wifi_ap_nodes[208],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[208], *wifi_ap_nodes[209],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[208], *wifi_ap_nodes[210],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[208], *wifi_ap_nodes[211],
			2000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 214, 2000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 215, 2000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 217, 2000000000, 2);
	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 220, 2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[226], *wifi_ap_nodes[227],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[227], *wifi_ap_nodes[228],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[226], *wifi_ap_nodes[229],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[226], *wifi_ap_nodes[230],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[230], *wifi_ap_nodes[231],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[230], *wifi_ap_nodes[248],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[226], *wifi_ap_nodes[256],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[256], *wifi_ap_nodes[257],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[256], *wifi_ap_nodes[258],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[256], *wifi_ap_nodes[259],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[226], *wifi_ap_nodes[260],
			2000000000, 2);

	connectSwitchNodes(SHIGENOBU_SWITCH_INDEX, 264, 2000000000, 2);

	connectSwitchNodes(TARUMI_SWITCH_INDEX, 287, 2000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 288, 2000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 290, 2000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 291, 2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[291], *wifi_ap_nodes[294],
			2000000000, 2);

	connectSwitchNodes(TARUMI_SWITCH_INDEX, 295, 2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[296],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[300],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[295], *wifi_ap_nodes[301],
			2000000000, 2);

	connectSwitchNodes(TARUMI_SWITCH_INDEX, 304, 2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[304], *wifi_ap_nodes[305],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[304], *wifi_ap_nodes[306],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[304], *wifi_ap_nodes[308],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[304], *wifi_ap_nodes[309],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[304], *wifi_ap_nodes[310],
			2000000000, 2);

	connectSwitchNodes(TARUMI_SWITCH_INDEX, 311, 2000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 312, 2000000000, 2);

	topology_helper.InstallCsmaLink(*switch_nodes[312], *wifi_ap_nodes[313],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[312], *wifi_ap_nodes[314],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[316], *wifi_ap_nodes[317],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[317], *wifi_ap_nodes[318],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[317], *wifi_ap_nodes[319],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[317], *wifi_ap_nodes[320],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[321], *wifi_ap_nodes[322],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[321], *wifi_ap_nodes[323],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[321], *wifi_ap_nodes[324],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[316], *wifi_ap_nodes[325],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[316], *wifi_ap_nodes[327],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[316], *wifi_ap_nodes[328],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[316], *wifi_ap_nodes[331],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[331], *wifi_ap_nodes[332],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[197], *wifi_ap_nodes[343],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[45], *wifi_ap_nodes[344],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[41], *wifi_ap_nodes[345],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[41], *wifi_ap_nodes[346],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[206], *wifi_ap_nodes[347],
			2000000000, 2);
	topology_helper.InstallCsmaLink(*switch_nodes[206], *wifi_ap_nodes[348],
			2000000000, 2);

	connectSwitchNodes(9, 10, 1000000000, 2);
	connectSwitchNodes(11, 12, 1000000000, 2);
	connectSwitchNodes(11, 13, 1000000000, 2);
	connectSwitchNodes(15, 16, 1000000000, 2);
	connectSwitchNodes(9, 22, 1000000000, 2);
	connectSwitchNodes(9, 23, 1000000000, 2);
	connectSwitchNodes(9, 24, 1000000000, 2);
	connectSwitchNodes(24, 26, 1000000000, 2);
	connectSwitchNodes(24, 27, 1000000000, 2);
	connectSwitchNodes(24, 28, 1000000000, 2);
	connectSwitchNodes(9, 31, 1000000000, 2);
	connectSwitchNodes(9, 32, 1000000000, 2);
	connectSwitchNodes(9, 36, 1000000000, 2);
	connectSwitchNodes(40, 41, 1000000000, 2);
	connectSwitchNodes(41, 42, 1000000000, 2);
	connectSwitchNodes(41, 43, 1000000000, 2);
	connectSwitchNodes(41, 44, 1000000000, 2);
	connectSwitchNodes(41, 45, 1000000000, 2);
	connectSwitchNodes(45, 46, 1000000000, 2);
	connectSwitchNodes(46, 47, 1000000000, 2);
	connectSwitchNodes(45, 48, 1000000000, 2);
	connectSwitchNodes(45, 49, 1000000000, 2);
	connectSwitchNodes(59, 63, 1000000000, 2);
	connectSwitchNodes(59, 64, 1000000000, 2);
	connectSwitchNodes(66, 67, 1000000000, 2);
	connectSwitchNodes(81, 83, 1000000000, 2);
	connectSwitchNodes(85, 86, 1000000000, 2);
	connectSwitchNodes(85, 87, 1000000000, 2);
	connectSwitchNodes(85, 88, 1000000000, 2);
	connectSwitchNodes(85, 89, 1000000000, 2);
	connectSwitchNodes(89, 90, 1000000000, 2);
	connectSwitchNodes(80, 91, 1000000000, 2);
	connectSwitchNodes(91, 92, 1000000000, 2);
	connectSwitchNodes(91, 93, 1000000000, 2);
	connectSwitchNodes(91, 94, 1000000000, 2);
	connectSwitchNodes(91, 95, 1000000000, 2);
	connectSwitchNodes(91, 96, 1000000000, 2);
	connectSwitchNodes(91, 97, 1000000000, 2);
	connectSwitchNodes(91, 98, 1000000000, 2);
	connectSwitchNodes(99, 100, 1000000000, 2);
	connectSwitchNodes(100, 101, 1000000000, 2);
	connectSwitchNodes(100, 102, 1000000000, 2);
	connectSwitchNodes(100, 103, 1000000000, 2);
	connectSwitchNodes(100, 104, 1000000000, 2);

	connectSwitchNodes(100, 105, 1000000000, 2);
	connectSwitchNodes(100, 106, 1000000000, 2);

	connectSwitchNodes(99, 99, 1000000000, 2);
	connectSwitchNodes(107, 107, 1000000000, 2);
	connectSwitchNodes(107, 107, 1000000000, 2);

	connectSwitchNodes(107, 110, 1000000000, 2);
	connectSwitchNodes(107, 111, 1000000000, 2);
	connectSwitchNodes(99, 112, 1000000000, 2);
	connectSwitchNodes(116, 117, 1000000000, 2);
	connectSwitchNodes(116, 118, 1000000000, 2);
	connectSwitchNodes(116, 119, 1000000000, 2);
	connectSwitchNodes(116, 120, 1000000000, 2);
	connectSwitchNodes(116, 121, 1000000000, 2);
	connectSwitchNodes(116, 122, 1000000000, 2);
	connectSwitchNodes(123, 124, 1000000000, 2);
	connectSwitchNodes(123, 125, 1000000000, 2);
	connectSwitchNodes(137, 138, 1000000000, 2);
	connectSwitchNodes(137, 139, 1000000000, 2);
	connectSwitchNodes(137, 140, 1000000000, 2);
	connectSwitchNodes(146, 147, 1000000000, 2);
	connectSwitchNodes(146, 148, 1000000000, 2);
	connectSwitchNodes(151, 152, 1000000000, 2);
	connectSwitchNodes(151, 153, 1000000000, 2);
	connectSwitchNodes(154, 155, 1000000000, 2);
	connectSwitchNodes(154, 156, 1000000000, 2);
	connectSwitchNodes(154, 157, 1000000000, 2);
	connectSwitchNodes(158, 159, 1000000000, 2);
	connectSwitchNodes(161, 162, 1000000000, 2);
	connectSwitchNodes(161, 163, 1000000000, 2);
	connectSwitchNodes(161, 164, 1000000000, 2);
	connectSwitchNodes(161, 166, 1000000000, 2);
	connectSwitchNodes(167, 168, 1000000000, 2);
	connectSwitchNodes(167, 169, 1000000000, 2);
	connectSwitchNodes(167, 170, 1000000000, 2);
	connectSwitchNodes(167, 171, 1000000000, 2);
	connectSwitchNodes(172, 173, 1000000000, 2);
	connectSwitchNodes(172, 174, 1000000000, 2);
	connectSwitchNodes(174, 175, 1000000000, 2);
	connectSwitchNodes(167, 176, 1000000000, 2);
	connectSwitchNodes(176, 177, 1000000000, 2);
	connectSwitchNodes(178, 179, 1000000000, 2);
	connectSwitchNodes(181, 182, 1000000000, 2);
	connectSwitchNodes(183, 184, 1000000000, 2);
	connectSwitchNodes(183, 185, 1000000000, 2);
	connectSwitchNodes(183, 186, 1000000000, 2);
	connectSwitchNodes(183, 187, 1000000000, 2);
	connectSwitchNodes(183, 188, 1000000000, 2);
	connectSwitchNodes(183, 189, 1000000000, 2);
	connectSwitchNodes(183, 190, 1000000000, 2);
	connectSwitchNodes(183, 191, 1000000000, 2);
	connectSwitchNodes(183, 192, 1000000000, 2);
	connectSwitchNodes(193, 194, 1000000000, 2);
	connectSwitchNodes(193, 195, 1000000000, 2);
	connectSwitchNodes(193, 196, 1000000000, 2);
	connectSwitchNodes(197, 198, 1000000000, 2);
	connectSwitchNodes(197, 199, 1000000000, 2);
	connectSwitchNodes(200, 205, 1000000000, 2);
	connectSwitchNodes(206, 207, 1000000000, 2);
	connectSwitchNodes(206, 212, 1000000000, 2);
	connectSwitchNodes(215, 216, 1000000000, 2);
	connectSwitchNodes(217, 218, 1000000000, 2);
	connectSwitchNodes(217, 219, 1000000000, 2);
	connectSwitchNodes(220, 221, 1000000000, 2);
	connectSwitchNodes(220, 222, 1000000000, 2);
	connectSwitchNodes(220, 223, 1000000000, 2);
	connectSwitchNodes(220, 224, 1000000000, 2);
	connectSwitchNodes(220, 225, 1000000000, 2);
	connectSwitchNodes(231, 232, 1000000000, 2);
	connectSwitchNodes(230, 233, 1000000000, 2);
	connectSwitchNodes(230, 234, 1000000000, 2);
	connectSwitchNodes(230, 235, 1000000000, 2);
	connectSwitchNodes(230, 236, 1000000000, 2);
	connectSwitchNodes(230, 237, 1000000000, 2);
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
	connectSwitchNodes(248, 284, 1000000000, 2);
	connectSwitchNodes(248, 249, 1000000000, 2);
	connectSwitchNodes(248, 250, 1000000000, 2);
	connectSwitchNodes(248, 251, 1000000000, 2);
	connectSwitchNodes(248, 252, 1000000000, 2);
	connectSwitchNodes(248, 253, 1000000000, 2);
	connectSwitchNodes(248, 254, 1000000000, 2);
	connectSwitchNodes(248, 255, 1000000000, 2);
	connectSwitchNodes(226, 261, 1000000000, 2);
	connectSwitchNodes(226, 262, 1000000000, 2);
	connectSwitchNodes(226, 263, 1000000000, 2);
	connectSwitchNodes(264, 265, 1000000000, 2);
	connectSwitchNodes(266, 267, 1000000000, 2);
	connectSwitchNodes(266, 268, 1000000000, 2);
	connectSwitchNodes(266, 269, 1000000000, 2);
	connectSwitchNodes(266, 270, 1000000000, 2);
	connectSwitchNodes(270, 272, 1000000000, 2);
	connectSwitchNodes(266, 273, 1000000000, 2);
	connectSwitchNodes(266, 274, 1000000000, 2);
	connectSwitchNodes(276, 277, 1000000000, 2);
	connectSwitchNodes(276, 278, 1000000000, 2);
	connectSwitchNodes(278, 279, 1000000000, 2);
	connectSwitchNodes(276, 280, 1000000000, 2);
	connectSwitchNodes(280, 281, 1000000000, 2);
	connectSwitchNodes(276, 282, 1000000000, 2);
	connectSwitchNodes(TARUMI_SWITCH_INDEX, 286, 1000000000, 2);
	connectSwitchNodes(288, 289, 1000000000, 2);
	connectSwitchNodes(291, 292, 1000000000, 2);
	connectSwitchNodes(291, 293, 1000000000, 2);
	connectSwitchNodes(295, 297, 1000000000, 2);
	connectSwitchNodes(297, 298, 1000000000, 2);
	connectSwitchNodes(295, 299, 1000000000, 2);
	connectSwitchNodes(295, 302, 1000000000, 2);
	connectSwitchNodes(295, 303, 1000000000, 2);
	connectSwitchNodes(304, 307, 1000000000, 2);
	connectSwitchNodes(312, 315, 1000000000, 2);
	connectSwitchNodes(317, 321, 1000000000, 2);
	connectSwitchNodes(316, 326, 1000000000, 2);
	connectSwitchNodes(328, 329, 1000000000, 2);
	connectSwitchNodes(328, 330, 1000000000, 2);
	connectSwitchNodes(335, 336, 1000000000, 2);
	connectSwitchNodes(336, 337, 1000000000, 2);
	connectSwitchNodes(336, 338, 1000000000, 2);
	connectSwitchNodes(336, 339, 1000000000, 2);
	connectSwitchNodes(336, 340, 1000000000, 2);
	connectSwitchNodes(340, 341, 1000000000, 2);
	connectSwitchNodes(336, 342, 1000000000, 2);
}
