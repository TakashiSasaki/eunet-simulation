/*
 * CsmaSwitch.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef CSMASWITCH_H_
#define CSMASWITCH_H_

#include <vector>

void createCsmaSwitch(std::vector<ns3::Ptr<ns3::NodeContainer> >::iterator i) {
	ns3::Ptr<ns3::NodeContainer> & p = * i;
	p = ns3::CreateObject<ns3::NodeContainer>();
	ns3::NodeContainer & x = * p;
	x.Create(1);
}

class CsmaSwitches {
	std::vector<ns3::Ptr<ns3::NodeContainer> > csmaSwitches;
public:
	const ns3::NodeContainer& operator[](const int index) const {
		const ns3::Ptr<ns3::NodeContainer> & p = this->csmaSwitches[index];
		const ns3::NodeContainer & x = p.operator *();
		return x;
	}

	CsmaSwitches(const int number_of_csma_switches) :
			csmaSwitches(number_of_csma_switches) {
		std::for_each(csmaSwitches.begin(), csmaSwitches.end(),
				createCsmaSwitch);
	}

	virtual ~CsmaSwitches() {
	}
};

//csmaSwitches[5]
//2F networkkanrisitu WASSY buredoserver-right
//csmaSwitches[6]
//2F networkkanrisitu buredoserver-left
//csmaSwitches[7]
//2F networkkanrisitu-serversegment-sita
//csmaSwitches[8]

//sougoujouhoumediacenter 2F network-kanrisitu-sita
//csmaSwitches[9]
//sougoujouhoumediacenter 2F network-kanrisitu-sub1
//csmaSwitches[10]
//sougoujouhoumediacenter 2F network-kanrisitu-sub2
//csmaSwitches[11]
//RTX1100-1
//csmaSwitches[12]
//RTX1100-2
//csmaSwitches[13]
//2F NWkanrisitu-ehimeCATVsama
//csmaSwitches[14]
//sougoujouhoumediacenter 2F network-kanrisitu-sub3
//csmaSwitches[15]
//RTX1100-3
//csmaSwitches[16]
//sougoujouhoumediacenter 2F network-kanrisitu-sub4
//csmaSwitches[17]
//1F EPS
//csmaSwitches[18]
//1F dai5ensyusitu
//csmaSwitches[19]
//1F serverkisitu-left
//csmaSwitches[20]
//1F serverkisitu-right
//csmaSwitches[21]
//WLC-1
//csmaSwitches[22]
//WLC-2
//csmaSwitches[23]
//2F mediazikkensitu108-main
//csmaSwitches[24]
//2F mediazikkensitu108-sub1
//csmaSwitches[25]
//2F mediazikkensitu108-sub2
//csmaSwitches[26]
//2F mediazikkensitu108-sub3
//csmaSwitches[27]
//1F mediaholeEPS
//csmaSwitches[28]
//2F dai1ensyusitu-left
//csmaSwitches[29]
//2F dai1ensyusitu-right
//csmaSwitches[30]
//3F dai2ensyusitu-left
//csmaSwitches[31]
//3F dai2ensyusitu-right
//csmaSwitches[32]
//3F dai3ensyusitu-left
//csmaSwitches[33]
//3F dai3ensyusitu-right
//csmaSwitches[34]
//4F dai4ensyusitu-left
//csmaSwitches[35]
//4F dai4ensyusitu-right
//csmaSwitches[36]
//4F dai6ensyusitu-left
//csmaSwitches[37]
//4F dai6ensyusitu-right
//csmaSwitches[38]
//4F EPS
//csmaSwitches[39]

//huzokujouhoutosyokan
//2F serversitu
//csmaSwitches[40]
//1F EPS
//csmaSwitches[41]
//2F EPS-nisi
//csmaSwitches[42]
//3F EPS-nisi
//csmaSwitches[43]
//4F EPS-nisi
//csmaSwitches[44]
//6F EPS-nisi
//csmaSwitches[344]
//1F gakuseiservicecenter
//csmaSwitches[45]
//2F EPS-higasi-1
//csmaSwitches[46]
//2F EPS-higasi-2
//csmaSwitches[47]
//3F EPS-higasi
//csmaSwitches[48]
//4F EPS-higasi
//csmaSwitches[49]
//6F EPS-higasi
//csmaSwitches[345]

//nankakinenho-ru
//csmaSwitches[346]

//kyouikugakubu3goukan
//2F syoruisitu
//csmaSwitches[50]

//kyouikugakubuhonkan
//1F buppinko
//csmaSwitches[51]
//2F EPS
//csmaSwitches[52]
//3F EPS-left
//csmaSwitches[53]
//3F EPS-right
//csmaSwitches[54]
//4F EPS-left
//csmaSwitches[55]
//4F EPS-right
//csmaSwitches[56]

//kyouikugakubu3goukan
//1F chouzouzissyusitu
//csmaSwitches[57]
//3F gazousyorisitu
//csmaSwitches[58]
//2F syoruisitu
//csmaSwitches[59]
//4F syakaitosyositu
//csmaSwitches[60]
//5F youzikyouikusiryousitu
//csmaSwitches[61]
//6F 601 ongakuzissyusitu
//csmaSwitches[62]

//kyouikugakubu4goukan
//1F serversitu N0.1
//csmaSwitches[63]
//1F serversitu N0.2
//csmaSwitches[64]
//1F serversitu N0.3
//csmaSwitches[65]
//2F tikakunintizikkensitu
//csmaSwitches[66]
//yougo1
//csmaSwitches[67]
//3F chounouzissyusitu
//csmaSwitches[68]
//4F gengokunrenzissyusitu
//csmaSwitches[69]
//kyouikugakubu2goukan
//2F dai2jouhousyorizissyusitu
//csmaSwitches[70]
//1F kyousyokuinsienroom
//csmaSwitches[71]
//3F dai1jouhousyorizissyusitu-1
//csmaSwitches[72]
//3F dai1jouhousyorizissyusitu-2
//csmaSwitches[73]
//3F buturikenkyusitu-1
//csmaSwitches[74]
//3F buturikenkyusitu-2
//csmaSwitches[75]
//4F jouhoubunkazissyusitu-1
//csmaSwitches[76]
//4F jouhoubunkazissyusitu-2
//csmaSwitches[77]
//5F ongakuensyusitu
//csmaSwitches[78]
//jouhokuzimucenter-1
//1F EPS
//csmaSwitches[79]

//rigakubu
//rigakubu-80setuzoku-switch
//csmaSwitches[80]
//rigakunu2goukan
//1F rigakubu2goukan-buturikagakukatosyokan
//csmaSwitches[81]
//2F kyoudoukenkyusitu
//csmaSwitches[82]
//3F keisankisitu
//csmaSwitches[83]
//4F suurisugakukadai2ensyusitu
//csmaSwitches[84]
//rigakubuhonkan-higasi
//1F EPS
//csmaSwitches[85]
//2F EPS
//csmaSwitches[86]
//3F EPS
//csmaSwitches[87]
//4F EPS
//csmaSwitches[88]
//5F EPS
//csmaSwitches[89]
//5F jouhousyoriaitu
//csmaSwitches[90]
//sougoukenkyutou-nisi--sougoukenkyurou-higasi
//sougoukenkyutou-nisi-1F EPS
//csmaSwitches[91]
//1F EPS
//csmaSwitches[92]
//2F EPS
//csmaSwitches[93]
//3F EPS
//csmaSwitches[94]
//4F EPS
//csmaSwitches[95]
//5F EPS
//csmaSwitches[96]
//6F EPS
//csmaSwitches[97]
//7F EPS
//csmaSwitches[98]

//rigakubuhonkan1F CPUbunsitu
//csmaSwitches[99]
//sougoukenkyutou-nisi-sita
//1F EPS
//csmaSwitches[100]
//2F EPS
//csmaSwitches[101]
//3F EPS
//csmaSwitches[102]
//4F EPS
//csmaSwitches[103]
//5F EPS
//csmaSwitches[104]
//6F EPS
//csmaSwitches[105]
//7F EPS
//csmaSwitches[106]

//rigakubuhonkan-nisi-sita
//1F EPS
//csmaSwitches[107]
//2F EPS
//csmaSwitches[108]
//3F EPS
//csmaSwitches[109]
//4F EPS
//csmaSwitches[110]
//5F EPS
//csmaSwitches[111]
//sougoukagakukenkyusiencenter-jouhoku-station
//csmaSwitches[112]
//sougoujouhoumediacenter 2Fnetwork-kanrisituCATV
//csmaSwitches[113]

//jouhokuhonbu--aidaimyu-zu
//daigakuhonbu
//csmaSwitches[114]
//seibutukankyousiryoubank
//csmaSwitches[115]
//benchabizinesu+musaibouseimeikagakukenkyucenter
//1F EPS
//csmaSwitches[116]
//2F bencha-bizinesu EPS
//csmaSwitches[117]
//3F bencha-bizinesu EPS
//csmaSwitches[118]
//4F bencha-bizinesu EPS
//csmaSwitches[119]
//1F musaibouseimeikagaku EPS
//csmaSwitches[120]
//2F musaibouseimeikagaku EPS
//csmaSwitches[121]
//3F musaibouseimeikagaku EPS
//csmaSwitches[122]

//sangyoukagakugijutusiencenter
//1F  EPS
//csmaSwitches[123]
//2F EPS
//csmaSwitches[124]
//3F EPS
//csmaSwitches[125]

//hougakubuhonkan
//1F 108gousitu main
//csmaSwitches[126]
//1F syusyokusoudansitu-1
//csmaSwitches[127]
//1F syusyokusoudansitu-2
//csmaSwitches[128]
//2F EPS
//csmaSwitches[129]
//3F EPS
//csmaSwitches[130]
//4F EPS
//csmaSwitches[131]
//5F EPS-ue
//csmaSwitches[132]
//5F EPS-sita
//csmaSwitches[133]
//6F EPS
//csmaSwitches[134]
//7F EPS
//csmaSwitches[135]
//8F EPS
//csmaSwitches[136]

//houbungakubu2goukan
//1F junbisitu
//csmaSwitches[137]
//1F EPS
//csmaSwitches[138]
//2F EPS
//csmaSwitches[139]
//3F EPS
//csmaSwitches[140]

//aidaimyuzu-higasi
//aidaimyuzu-higasi 1F EPS
//csmaSwitches[141]
//1F EPS
//csmaSwitches[142]
//2F EPS-left
//csmaSwitches[143]
//3F EPS
//csmaSwitches[144]
//4F EPS
//csmaSwitches[145]
//2F EPS-right
//csmaSwitches[146]

//aidaimyuzu-minami
//1F  EPS
//csmaSwitches[147]
//2F EPS
//csmaSwitches[148]
//3F EPS
//csmaSwitches[149]

//aidaimyuzu-nisi
//1F EPS
//csmaSwitches[150]
//2F EPS
//csmaSwitches[151]
//2F M21kyousitu-1
//csmaSwitches[152]
//2F M21kyousitu-2
//csmaSwitches[153]
//3F EPS-left
//csmaSwitches[154]
//3F M31kyousitu-1
//csmaSwitches[155]
//3F M31kyousitu-2
//csmaSwitches[156]
//3F EPS-right
//csmaSwitches[157]

//kyotukyoikukougitou 1F zissyusitu--greenhole
//kyotukyoikukougitou 1F zissyusitu
//csmaSwitches[158]
//greenhole
//csmaSwitches[159]

//sougoujouhoumediacenter 2F network kanrisituCATV
//csmaSwitches[160]

//kougakubu--sougoukenkyu2
//kougakubuhonkan 2F EPS
//csmaSwitches[161]

//kougakubuhonkan-ue
//1F EPS
//csmaSwitches[162]
//3F EPS
//csmaSwitches[163]
//4F EPS
//csmaSwitches[164]
//6F EPS
//csmaSwitches[165]
//8F EPS
//csmaSwitches[166]

//kougakubu2goukan
//1F rouka joudan,migi
//csmaSwitches[167]
//1F rouka joudan,hidari
//csmaSwitches[168]
//2F rouka joudan
//csmaSwitches[169]
//3F rouka joudan
//csmaSwitches[170]
//4F rouka joudan
//csmaSwitches[171]
//5F rouka joudan,migi
//csmaSwitches[172]
//okyakusamaSW-1
//csmaSwitches[173]
//5F rouka joudan,hidari
//csmaSwitches[174]
//3F okuakusamaSW-2
//csmaSwitches[175]
//6F rouka,joudan
//csmaSwitches[176]
//okyakusamaSW-3
//csmaSwitches[177]

//kougakubu3goukan+kougakubu4goukan
//kougakubu3goukan
//3F dai7kenkyusitu-left
//csmaSwitches[178]
//3F dai7kenkyusitu-right
//csmaSwitches[179]

//kougakubu4goukan
//3F EPS
//csmaSwitches[180]
//7F EPS-left
//csmaSwitches[181]
//7F EPS-right
//csmaSwitches[182]
//kougakubu5goukan
//1F rouka joudan,migi
//csmaSwitches[183]
//2F EPS
//csmaSwitches[184]
//3F EPS
//csmaSwitches[185]
//4F EPS
//csmaSwitches[186]
//5F EPS
//csmaSwitches[187]
//6F EPS
//csmaSwitches[188]
//7F EPS
//csmaSwitches[189]
//8F EPS
//csmaSwitches[190]
//9F EPS
//csmaSwitches[191]
//10F EPS
//csmaSwitches[192]
//kougakubu1goukan
//1F EPS
//csmaSwitches[193]
//2F EPS
//csmaSwitches[194]
//4F EPS
//csmaSwitches[195]
//6F EPS
//csmaSwitches[196]
//kougakubukougitou
//1F kisokagakuzikkensitu
//csmaSwitches[197]
//24bankougisitu
//csmaSwitches[343]
//4F Dseizusitu-1
//csmaSwitches[198]
//4F Dseizusitu-2
//csmaSwitches[199]

//sougoukenkyutou
//1F EPS-main
//csmaSwitches[200]
//3F EPS-main
//csmaSwitches[201]
//3F EPS-sub-1
//csmaSwitches[202]
//3F EPS-sub-2
//csmaSwitches[203]
//3F EPS-sub-3
//csmaSwitches[204]
//2F EPS-ue
//csmaSwitches[205]
//1F EPS-sub
//csmaSwitches[206]
//2F EPS-sita
//csmaSwitches[207]
//4F EPS-main
//csmaSwitches[208]
//4F EPS-sub-1
//csmaSwitches[209]
//4F EPS-sub-2
//csmaSwitches[210]
//4F EPS-sub-3
//csmaSwitches[211]

//syakairenkeisuisinnkikou
//1F
//csmaSwitches[347]
//2F
//csmaSwitches[348]

//kougakubukikaizissyukoujoutou
//1F zimusitu
//csmaSwitches[212]
//sougoujouhoumediacenter 2F networkkanrisitu-CATVsama
//csmaSwitches[213]

//igakubutou2F
//2F EPS
	//csmaSwitches[214]
//sougoukagakukenkyusiencenter-sigenobustation
//2F kagakuzikkensitu
	//csmaSwitches[215]
//1F siryouhokanko1-EPS
	//csmaSwitches[216]
//rinsyoukenkyutou
//1F seitaijouhoukaisekikenkyusitu
	//csmaSwitches[217]
//2F josyusitu
	//csmaSwitches[218]
//3F kyoukankenkyusitu2
	//csmaSwitches[219]
//kangogakkakousya
//3F EPS
	//csmaSwitches[220]
//1F EPS
	//csmaSwitches[221]
//2F EPS
	//csmaSwitches[222]
//4F EPS
	//csmaSwitches[223]
//5F EPS
	//csmaSwitches[224]
//6F EPS
	//csmaSwitches[225]
//2F serversitu-mediacenterbunsitu-sub
	//csmaSwitches[226]
//4F ensyusitu
	//csmaSwitches[227]
//4F EPS
	//csmaSwitches[228]
//gairaitou
//1F housyasenkachouonpakensasitu
	//csmaSwitches[229]
//huzokubyouin1goukan
//2F denwakoukankisitu
	//csmaSwitches[230]
//gairaitou
//1F haidensitu1
	//csmaSwitches[231]
//1F haidensitu2
	//csmaSwitches[232]
//3F eiyousidouditu
	//csmaSwitches[233]
//huzokubyouin1goukan
//1F EPS-nisi
	//csmaSwitches[234]
//1F EPS-higasi
	//csmaSwitches[235]
//2F denwakoukankisitu
	//csmaSwitches[236]
//2F chuoukensasitu
	//csmaSwitches[237]
//2F EPS
	//csmaSwitches[238]
//3F EPS-nisi
	//csmaSwitches[239]
//3F EPS-higasi
	//csmaSwitches[240]
//4F EPS
	//csmaSwitches[241]
//5F EPS
	//csmaSwitches[242]
//6F EPS
	//csmaSwitches[243]
//7F EPS
	//csmaSwitches[244]
//8F EPS
	//csmaSwitches[245]
//9F EPS
	//csmaSwitches[246]
//222F EPS
	//csmaSwitches[247]

//huzokubyouin2goukan
//1F EPS
	//csmaSwitches[248]
//B1F EPS
	//csmaSwitches[284]
//2F EPS
	//csmaSwitches[249]
//3F EPS
	//csmaSwitches[250]
//4F EPS
	//csmaSwitches[251]
//5F EPS
	//csmaSwitches[252]
//6F EPS
	//csmaSwitches[253]
//7F EPS
	//csmaSwitches[254]
//8F EPS
	//csmaSwitches[255]

//sougoukyouikutou
//2F sosikizissyusitu-main
	//csmaSwitches[256]
//2F sosikizissyusitu-sub1
	//csmaSwitches[257]
//2F sosikizissyusitu-sub2
	//csmaSwitches[258]
//2F sosikizissyusitu-sub3
	//csmaSwitches[259]

//huzokutosyokan-igakububunya
//1F kaigisitu
	//csmaSwitches[260]

//kanritou
//2F kenkyukyouryokusitu
	//csmaSwitches[261]
//3F kaigisitu
	//csmaSwitches[262]
//hukurikaikan
//1F hendensitu
	//csmaSwitches[263]

//igakubutou2F
//2392800G-259TCL
	//csmaSwitches[264]
//2F networktanmatusitu
	//csmaSwitches[265]

//2Fserversitu-ue
	//csmaSwitches[266]
// 2392800G-72TCL
	//csmaSwitches[267]
//1F EPS
	//csmaSwitches[268]
//3F EPS
	//csmaSwitches[269]
//4F EPS
	//csmaSwitches[270]
//okyakusamaSW-1
	//csmaSwitches[272]
//5F EPS
	//csmaSwitches[273]
//Wasay buredo-server
	//csmaSwitches[274]
//2F serversitu-buredoserver
	//csmaSwitches[275]
//2Fserversitu-sita
	//csmaSwitches[276]
//6F EPS
	//csmaSwitches[277]
//7F EPS
	//csmaSwitches[278]
//okyakusamaSW-2
	//csmaSwitches[279]
//8F EPS
	//csmaSwitches[280]
//okyakusamaSW-3
	//csmaSwitches[281]
//9F EPS
	//csmaSwitches[282]

//igakubumediacenterbunsitu
	//csmaSwitches[283]

//nougakubu2goukan-2Fserversitu
//buredoserver
	//csmaSwitches[285]
//3F mediacenterbunsitu-1
	//csmaSwitches[286]
//3F mediacenterbunsitu-2
	//csmaSwitches[287]
//3F mediacenterbunsitu-3-left
	//csmaSwitches[288]
//3F mediacenterbunsitu-3-right
	//csmaSwitches[289]
//3F mediacenterbunsitu-4
	//csmaSwitches[290]

//nougakubu2goukan
//2F EPS-left
	//csmaSwitches[291]
//3F 317kougisitu
	//csmaSwitches[292]
//2F huzokutosyokan-multimediacorner
	//csmaSwitches[293]
//2F EPS-right
	//csmaSwitches[294]
//nougakubu3goukan
//4F seibutukankyoujouhousisutemugaku-conpyutasitu-left
	//csmaSwitches[295]
//1F EPS
	//csmaSwitches[296]
//2F EPS-ue
	//csmaSwitches[297]
//nougakubuseigyokazikkensisetu
//okyakusamaSW
	//csmaSwitches[298]
//2F EPS-sita
	//csmaSwitches[299]
//3F EPS
	//csmaSwitches[300]
//4F seibutukankyoujouhousisutemugaku-computersitu-right
	//csmaSwitches[301]
//5F EPS-ue
	//csmaSwitches[302]
//5F EPS-sita
	//csmaSwitches[303]

//nougakubuhonkan-minami
//3F EPS-left
	//csmaSwitches[304]
//1F EPS
	//csmaSwitches[305]
//2F EPS-ue
	//csmaSwitches[306]
//2F EPS-sita
	//csmaSwitches[307]
//3F EPS
	//csmaSwitches[308]
//4F EPS
	//csmaSwitches[309]
//5F EPS
	//csmaSwitches[310]
//sougoukagakukenkyusiencenter
//2F EPS
	//csmaSwitches[311]

//rengounougakukenkyuka
//2F inseikenkyusitu
	//csmaSwitches[312]
//1F zimusitu
	//csmaSwitches[313]
//3F senninkyoukanzikkensitu
	//csmaSwitches[314]

//yukarikaikan
//1F zimusitu
	//csmaSwitches[315]

//3F serversitu-mediacenterbunsitu-right
	//csmaSwitches[316]

//nougakubuhonkan-kita
//1F EPS-left
	//csmaSwitches[317]
//1F EPS-right
	//csmaSwitches[318]
//2F EPS
	//csmaSwitches[319]
//3F EPS
	//csmaSwitches[320]
//6F EPS-left
	//csmaSwitches[321]
//4F EPS
	//csmaSwitches[322]
//5F EPS
	//csmaSwitches[323]
//6F EPS-right
	//csmaSwitches[324]

//mikazikkensitu
//2F EPS
	//csmaSwitches[325]

//huzokukoukousya-minami
//1F EPS
	//csmaSwitches[326]
//5F jouhousiryousakuseisitu
	//csmaSwitches[327]

//huzokukoukousya-kita--huzokukoukousya-naka
//3F jouhousiryousakuseisitu
	//csmaSwitches[328]
//2F kitarouka
	//csmaSwitches[329]
//2F minamirouka
	//csmaSwitches[330]

//kankyousangyoukenkyusisetu
//1F keisankisitu
	//csmaSwitches[331]

//syokubutukoujousama
//2F serverkisitu
	//csmaSwitches[332]

//sougoujouhoumediacenter 2Fnetwork-kanrisituCATV
	//csmaSwitches[333]

//huzokusyougakkoukousya
//1F zimusitu-left
	//csmaSwitches[334]
//1F zimusitu-right
	//csmaSwitches[335]

//huzokusyougakkou-centertou 1F bunkensiryousitu
	//csmaSwitches[336]

//huzokusyougakkoukousya
//2F sichoukakusitu
	//csmaSwitches[337]

//huzokuchugakkou-honkan
//2F kaigisitu
	//csmaSwitches[338]
//1F jouhoukyouikusitu
	//csmaSwitches[339]

//huzokuyougogakkoukousya
//1F keisankisitu
	//csmaSwitches[340]
//ehimedaigakuSW
	//csmaSwitches[341]

//huzokuyoutienhonkan
//1F kyoukansitu
	//csmaSwitches[342]

#endif /* CSMASWITCH_H_ */
