#include <ns3/core-module.h>
#include <ns3/network-module.h>
#include <ns3/csma-module.h>
#include <ns3/internet-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
//#include <ns3/wifi-helper.h>
//#include <ns3/wifi-channel.h>
#include <ns3/yans-wifi-helper.h>
#include <ns3/yans-wifi-phy.h>
#include <ns3/nqos-wifi-mac-helper.h>
#include <ns3/ssid.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ns3/mobility-helper.h>
#include <ns3/rectangle.h>
#include "SwitchDevices.h"
#include "CsmaSwitches.h"
#include "TerminalSets.h"
#include "WifiStaNodeSets.h"
#include "WifiApNodes.h"
#include "TerminalDeviceSets.h"
#include "ApDeviceSets.h"
#include "DefaultWifiPhyHelper.h"
#include "DefaultMobilityHelper.h"
#include "WifiPhys.h"

//NS_LOG_COMPONENT_DEFINE("OnOffApplication");

int main(int argc, char** argv) {
	std::cout << "entered in main function." << std::endl;
	//ns3::LogComponentEnable("CsmaBridgeOneHopExample", ns3::LOG_LEVEL_INFO);
	ns3::CommandLine cmd;
	cmd.Parse(argc, argv);

	//internet-edge
	ns3::NodeContainer internetrouter;
	internetrouter.Create(1);

	//jouhoku--sigenobu--tarumi--motida
	ns3::NodeContainer csmaSwitchrouter;
	csmaSwitchrouter.Create(1);

	//sougoujouhoumediacenter
	//sougoujouhoumediacenter 2F network-kanrisitu-main
	ns3::NodeContainer csmaSwitch6506E;
	csmaSwitch6506E.Create(1);

	CsmaSwitches csmaSwitches(350);

	//networkkanrisitu-serversegment-ue

//2F serversitu-mediacenterbunsitu-main
	ns3::NodeContainer csmaSwitchsigenobu;
	csmaSwitchsigenobu.Create(1);

//3F serversitu-mediacenterbunsitu-left-main
	ns3::NodeContainer csmaSwitchtarumi;
//csmaSwitchtarumi = ns3::NodeContainer()
	csmaSwitchtarumi.Create(1);

	TerminalSets terminal_sets(348);

	WifiStaNodeSets wifi_sta_node_sets(350);
	WifiApNodes wifi_ap_nodes(350);

// Create the csma links, from each terminal to the switch

	ns3::NetDeviceContainer internetrouterdevices;
	ns3::NetDeviceContainer switchDevicesrouter;
	ns3::NetDeviceContainer switchDevices6506E;
	SwitchDevices switch_devices(300);

	ns3::NetDeviceContainer switchDevicessigenobu;
	ns3::NetDeviceContainer switchDevicestarumi;

	TerminalDeviceSets terminal_device_sets(348);
	ApDeviceSets ap_device_sets(348);

//wifi
	ns3::WifiHelper Wifi;
	Wifi = ns3::WifiHelper::Default();
	Wifi.SetRemoteStationManager("ns3::ArfWifiManager");

//wifi channel
	WifiPhys wifiPhys(315);

//stanodes mac
	ns3::NqosWifiMacHelper mac;
	mac = ns3::NqosWifiMacHelper::Default();
	//mac = ns.wifi.NqosWifiMacHelper.Default()
	ns3::Ssid ssid;
	ssid = ns3::Ssid("wifi-default");
	//ssid = ns.wifi.Ssid("wifi-default")
	mac.SetType("ns3::StaWifiMac", "Ssid", ns3::SsidValue(ssid),
			"ActiveProbing", ns3::BooleanValue(false));

	std::vector<ns3::NetDeviceContainer> staDeviceSets(316);
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		staDeviceSets[i] = Wifi.Install(wifiPhys[i], mac,
				wifi_sta_node_sets[i]);
	}	//for

// apnodes mac
	mac.SetType("ns3::ApWifiMac", "Ssid", ns3::SsidValue(ssid),
			"BeaconGeneration", ns3::BooleanValue(true), "BeaconInterval",
			ns3::TimeValue(ns3::Seconds(2.5)));

	std::vector<ns3::NetDeviceContainer> apDeviceSets(316);
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		apDeviceSets[i] = Wifi.Install(wifiPhys[i], mac, wifi_ap_nodes[i]);
	}	//for

//wifi area
	std::vector<DefaultMobilityHelper> mobilities(316);
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		mobilities[i].Install(wifi_sta_node_sets[i]);
	}

//channel define

	ns3::CsmaHelper csma;
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(1000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	for (int i; i < 1; ++i) {
		ns3::NetDeviceContainer nodelinkinternet;
		nodelinkinternet = csma.Install(
				ns3::NodeContainer(ns3::NodeContainer(internetrouter.Get(0)),
						csmaSwitchrouter));
		internetrouterdevices.Add(nodelinkinternet.Get(1));
		switchDevicesrouter.Add(nodelinkinternet.Get(0));
	}

	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(5000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	for (int j = 5; j <= 348; ++j) {
		if (j == 80 || j == 113 || j == 160 || j == 213 || j == 271 || j == 333)
			continue;
		for (int i = 0; i < 15; ++i) {
			ns3::NetDeviceContainer net_device_container;
			net_device_container = csma.Install(
					ns3::NodeContainer(
							ns3::NodeContainer(terminal_sets[5].Get(i)),
							csmaSwitches[5]));
			switch_devices[5].Add(net_device_container.Get(1));
			terminal_device_sets[5].Add(net_device_container.Get(0));
		}
	}

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(22000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	{
		ns3::NetDeviceContainer csma_net_devices = csma.Install(
				ns3::NodeContainer(csmaSwitchrouter, csmaSwitchsigenobu));
		switchDevicesrouter.Add(csma_net_devices.Get(0));
		switchDevicessigenobu.Add(csma_net_devices.Get(1));
	}

	ns3::NetDeviceContainer linktarumi;
	linktarumi = csma.Install(
			ns3::NodeContainer(csmaSwitchrouter, csmaSwitchtarumi));
	switchDevicesrouter.Add(linktarumi.Get(0));
	switchDevicestarumi.Add(linktarumi.Get(1));

	ns3::NetDeviceContainer linkmotida;
	linkmotida = csma.Install(
			ns3::NodeContainer(csmaSwitchrouter, csmaSwitches[335]));
	switchDevicesrouter.Add(linkmotida.Get(0));
	switch_devices[335].Add(linkmotida.Get(1));

	ns3::NetDeviceContainer link285;
	link285 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[285]));
	switchDevicestarumi.Add(link285.Get(0));
	switch_devices[285].Add(link285.Get(1));
//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(20000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link6506E;
	link6506E = csma.Install(
			ns3::NodeContainer(csmaSwitchrouter, csmaSwitch6506E));
	switchDevicesrouter.Add(link6506E.Get(0));
	switchDevices6506E.Add(link6506E.Get(1));

	ns3::NetDeviceContainer link9;
	link9 = csma.Install(ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[9]));
	switchDevices6506E.Add(link9.Get(0));
	switch_devices[9].Add(link9.Get(1));

	ns3::NetDeviceContainer link7;
	link7 = csma.Install(ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[7]));
	switchDevices6506E.Add(link7.Get(0));
	switch_devices[7].Add(link7.Get(1));

	ns3::NetDeviceContainer link80;
	link80 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[80]));
	switchDevices6506E.Add(link80.Get(0));
	switch_devices[80].Add(link80.Get(1));

	ns3::NetDeviceContainer link126;
	link126 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[126]));
	switchDevices6506E.Add(link126.Get(0));
	switch_devices[126].Add(link126.Get(1));

	ns3::NetDeviceContainer link161;
	link161 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[161]));
	switchDevices6506E.Add(link161.Get(0));
	switch_devices[161].Add(link161.Get(1));

	ns3::NetDeviceContainer link275;
	link275 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[275]));
	switchDevicessigenobu.Add(link275.Get(0));
	switch_devices[275].Add(link275.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(16000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link6;
	link6 = csma.Install(ns3::NodeContainer(csmaSwitches[5], csmaSwitches[6]));
	switch_devices[5].Add(link6.Get(0));
	switch_devices[6].Add(link6.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(11000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link40;
	link40 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[40]));
	switchDevices6506E.Add(link40.Get(0));
	switch_devices[40].Add(link40.Get(1));

	ns3::NetDeviceContainer link70;
	link70 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[70]));
	switchDevices6506E.Add(link70.Get(0));
	switch_devices[70].Add(link70.Get(1));

	ns3::NetDeviceContainer link141;
	link141 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[141]));
	switchDevices6506E.Add(link141.Get(0));
	switch_devices[141].Add(link141.Get(1));

	ns3::NetDeviceContainer link197;
	link197 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[197]));
	switchDevices6506E.Add(link197.Get(0));
	switch_devices[197].Add(link197.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(8000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link226;
	link226 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[226]));
	switchDevicessigenobu.Add(link226.Get(0));
	switch_devices[226].Add(link226.Get(1));

	ns3::NetDeviceContainer link316;
	link316 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[316]));
	switchDevicestarumi.Add(link316.Get(0));
	switch_devices[316].Add(link316.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(7000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link5;
	link5 = csma.Install(ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[5]));
	switchDevices6506E.Add(link5.Get(0));
	switch_devices[5].Add(link5.Get(1));

	ns3::NetDeviceContainer link8;
	link8 = csma.Install(ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[8]));
	switchDevices6506E.Add(link8.Get(0));
	switch_devices[8].Add(link8.Get(1));

	ns3::NetDeviceContainer link113;
	link113 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[113]));
	switchDevices6506E.Add(link113.Get(0));
	switch_devices[113].Add(link113.Get(1));

	ns3::NetDeviceContainer link160;
	link160 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[160]));
	switchDevices6506E.Add(link160.Get(0));
	switch_devices[160].Add(link160.Get(1));

	ns3::NetDeviceContainer link213;
	link213 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[213]));
	switchDevices6506E.Add(link213.Get(0));
	switch_devices[213].Add(link213.Get(1));

	ns3::NetDeviceContainer link283;
	link283 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[283]));
	switchDevicessigenobu.Add(link283.Get(0));
	switch_devices[283].Add(link283.Get(1));

	ns3::NetDeviceContainer link333;
	link333 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[333]));
	switchDevicestarumi.Add(link333.Get(0));
	switch_devices[333].Add(link333.Get(1));

//channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(6000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link335;
	link335 = csma.Install(
			ns3::NodeContainer(csmaSwitches[334], csmaSwitches[335]));
	switch_devices[334].Add(link335.Get(0));
	switch_devices[335].Add(link335.Get(1));

//channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(4000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link266;
	link266 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[266]));
	switchDevicessigenobu.Add(link266.Get(0));
	switch_devices[266].Add(link266.Get(1));

	ns3::NetDeviceContainer link276;
	link276 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[276]));
	switchDevicessigenobu.Add(link276.Get(0));
	switch_devices[276].Add(link276.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(2000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer aplink1;
	aplink1 = csma.Install(
			ns3::NodeContainer(csmaSwitches[81], wifi_ap_nodes[1]));
	switch_devices[81].Add(aplink1.Get(0));
	ap_device_sets[1].Add(aplink1.Get(1));

	ns3::NetDeviceContainer aplink2;
	aplink2 = csma.Install(
			ns3::NodeContainer(csmaSwitches[82], wifi_ap_nodes[2]));
	switch_devices[82].Add(aplink2.Get(0));
	ap_device_sets[2].Add(aplink2.Get(1));

	ns3::NetDeviceContainer aplink3;
	aplink3 = csma.Install(
			ns3::NodeContainer(csmaSwitches[83], wifi_ap_nodes[3]));
	switch_devices[83].Add(aplink3.Get(0));
	ap_device_sets[3].Add(aplink3.Get(1));

	ns3::NetDeviceContainer aplink4;
	aplink4 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], wifi_ap_nodes[4]));
	switch_devices[85].Add(aplink4.Get(0));
	ap_device_sets[4].Add(aplink4.Get(1));

	ns3::NetDeviceContainer aplink5;
	aplink5 = csma.Install(
			ns3::NodeContainer(csmaSwitches[108], wifi_ap_nodes[5]));
	switch_devices[108].Add(aplink5.Get(0));
	ap_device_sets[5].Add(aplink5.Get(1));

	ns3::NetDeviceContainer aplink6;
	aplink6 = csma.Install(
			ns3::NodeContainer(csmaSwitches[86], wifi_ap_nodes[6]));
	switch_devices[86].Add(aplink6.Get(0));
	ap_device_sets[6].Add(aplink6.Get(1));

	ns3::NetDeviceContainer aplink7;
	aplink7 = csma.Install(
			ns3::NodeContainer(csmaSwitches[86], wifi_ap_nodes[7]));
	switch_devices[86].Add(aplink7.Get(0));
	ap_device_sets[7].Add(aplink7.Get(1));

	ns3::NetDeviceContainer aplink8;
	aplink8 = csma.Install(
			ns3::NodeContainer(csmaSwitches[87], wifi_ap_nodes[8]));
	switch_devices[87].Add(aplink8.Get(0));
	ap_device_sets[8].Add(aplink8.Get(1));

	ns3::NetDeviceContainer aplink9;
	aplink9 = csma.Install(
			ns3::NodeContainer(csmaSwitches[109], wifi_ap_nodes[9]));
	switch_devices[109].Add(aplink9.Get(0));
	ap_device_sets[9].Add(aplink9.Get(1));

	ns3::NetDeviceContainer aplink10;
	aplink10 = csma.Install(
			ns3::NodeContainer(csmaSwitches[88], wifi_ap_nodes[10]));
	switch_devices[88].Add(aplink10.Get(0));
	ap_device_sets[10].Add(aplink10.Get(1));

	ns3::NetDeviceContainer aplink11;
	aplink11 = csma.Install(
			ns3::NodeContainer(csmaSwitches[88], wifi_ap_nodes[11]));
	switch_devices[88].Add(aplink11.Get(0));
	ap_device_sets[11].Add(aplink11.Get(1));

	ns3::NetDeviceContainer aplink12;
	aplink12 = csma.Install(
			ns3::NodeContainer(csmaSwitches[111], wifi_ap_nodes[12]));
	switch_devices[111].Add(aplink12.Get(0));
	ap_device_sets[12].Add(aplink12.Get(1));

	ns3::NetDeviceContainer aplink13;
	aplink13 = csma.Install(
			ns3::NodeContainer(csmaSwitches[111], wifi_ap_nodes[13]));
	switch_devices[111].Add(aplink13.Get(0));
	ap_device_sets[13].Add(aplink13.Get(1));

	ns3::NetDeviceContainer aplink14;
	aplink14 = csma.Install(
			ns3::NodeContainer(csmaSwitches[89], wifi_ap_nodes[14]));
	switch_devices[89].Add(aplink14.Get(0));
	ap_device_sets[14].Add(aplink14.Get(1));

	ns3::NetDeviceContainer aplink15;
	aplink15 = csma.Install(
			ns3::NodeContainer(csmaSwitches[92], wifi_ap_nodes[15]));
	switch_devices[92].Add(aplink15.Get(0));
	ap_device_sets[15].Add(aplink15.Get(1));

	ns3::NetDeviceContainer aplink16;
	aplink16 = csma.Install(
			ns3::NodeContainer(csmaSwitches[101], wifi_ap_nodes[16]));
	switch_devices[101].Add(aplink16.Get(0));
	ap_device_sets[16].Add(aplink16.Get(1));

	ns3::NetDeviceContainer aplink17;
	aplink17 = csma.Install(
			ns3::NodeContainer(csmaSwitches[94], wifi_ap_nodes[17]));
	switch_devices[94].Add(aplink17.Get(0));
	ap_device_sets[17].Add(aplink17.Get(1));

	ns3::NetDeviceContainer aplink18;
	aplink18 = csma.Install(
			ns3::NodeContainer(csmaSwitches[94], wifi_ap_nodes[18]));
	switch_devices[94].Add(aplink18.Get(0));
	ap_device_sets[18].Add(aplink18.Get(1));

	ns3::NetDeviceContainer aplink19;
	aplink19 = csma.Install(
			ns3::NodeContainer(csmaSwitches[95], wifi_ap_nodes[19]));
	switch_devices[95].Add(aplink19.Get(0));
	ap_device_sets[19].Add(aplink19.Get(1));

	ns3::NetDeviceContainer aplink20;
	aplink20 = csma.Install(
			ns3::NodeContainer(csmaSwitches[103], wifi_ap_nodes[20]));
	switch_devices[103].Add(aplink20.Get(0));
	ap_device_sets[20].Add(aplink20.Get(1));

	ns3::NetDeviceContainer aplink21;
	aplink21 = csma.Install(
			ns3::NodeContainer(csmaSwitches[97], wifi_ap_nodes[21]));
	switch_devices[97].Add(aplink21.Get(0));
	ap_device_sets[21].Add(aplink21.Get(1));

	ns3::NetDeviceContainer aplink22;
	aplink22 = csma.Install(
			ns3::NodeContainer(csmaSwitches[105], wifi_ap_nodes[22]));
	switch_devices[105].Add(aplink22.Get(0));
	ap_device_sets[22].Add(aplink22.Get(1));

	ns3::NetDeviceContainer aplink23;
	aplink23 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], wifi_ap_nodes[23]));
	switch_devices[85].Add(aplink23.Get(0));
	ap_device_sets[23].Add(aplink23.Get(1));

	ns3::NetDeviceContainer aplink24;
	aplink24 = csma.Install(
			ns3::NodeContainer(csmaSwitches[86], wifi_ap_nodes[24]));
	switch_devices[86].Add(aplink24.Get(0));
	ap_device_sets[24].Add(aplink24.Get(1));

	ns3::NetDeviceContainer aplink25;
	aplink25 = csma.Install(
			ns3::NodeContainer(csmaSwitches[87], wifi_ap_nodes[25]));
	switch_devices[87].Add(aplink25.Get(0));
	ap_device_sets[25].Add(aplink25.Get(1));

	ns3::NetDeviceContainer aplink26;
	aplink26 = csma.Install(
			ns3::NodeContainer(csmaSwitches[162], wifi_ap_nodes[26]));
	switch_devices[162].Add(aplink26.Get(0));
	ap_device_sets[26].Add(aplink26.Get(1));

	ns3::NetDeviceContainer aplink27;
	aplink27 = csma.Install(
			ns3::NodeContainer(csmaSwitches[162], wifi_ap_nodes[27]));
	switch_devices[162].Add(aplink27.Get(0));
	ap_device_sets[27].Add(aplink27.Get(1));

	ns3::NetDeviceContainer aplink28;
	aplink28 = csma.Install(
			ns3::NodeContainer(csmaSwitches[162], wifi_ap_nodes[28]));
	switch_devices[162].Add(aplink28.Get(0));
	ap_device_sets[28].Add(aplink28.Get(1));

	ns3::NetDeviceContainer aplink29;
	aplink29 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], wifi_ap_nodes[29]));
	switch_devices[161].Add(aplink29.Get(0));
	ap_device_sets[29].Add(aplink29.Get(1));

	ns3::NetDeviceContainer aplink30;
	aplink30 = csma.Install(
			ns3::NodeContainer(csmaSwitches[163], wifi_ap_nodes[30]));
	switch_devices[163].Add(aplink30.Get(0));
	ap_device_sets[30].Add(aplink30.Get(1));

	ns3::NetDeviceContainer aplink31;
	aplink31 = csma.Install(
			ns3::NodeContainer(csmaSwitches[164], wifi_ap_nodes[31]));
	switch_devices[164].Add(aplink31.Get(0));
	ap_device_sets[31].Add(aplink31.Get(1));

	ns3::NetDeviceContainer aplink32;
	aplink32 = csma.Install(
			ns3::NodeContainer(csmaSwitches[165], wifi_ap_nodes[32]));
	switch_devices[165].Add(aplink32.Get(0));
	ap_device_sets[32].Add(aplink32.Get(1));

	ns3::NetDeviceContainer aplink33;
	aplink33 = csma.Install(
			ns3::NodeContainer(csmaSwitches[165], wifi_ap_nodes[33]));
	switch_devices[165].Add(aplink33.Get(0));
	ap_device_sets[33].Add(aplink33.Get(1));

	ns3::NetDeviceContainer aplink34;
	aplink34 = csma.Install(
			ns3::NodeContainer(csmaSwitches[165], wifi_ap_nodes[34]));
	switch_devices[165].Add(aplink34.Get(0));
	ap_device_sets[34].Add(aplink34.Get(1));

	ns3::NetDeviceContainer aplink35;
	aplink35 = csma.Install(
			ns3::NodeContainer(csmaSwitches[169], wifi_ap_nodes[35]));
	switch_devices[169].Add(aplink35.Get(0));
	ap_device_sets[35].Add(aplink35.Get(1));

	ns3::NetDeviceContainer aplink36;
	aplink36 = csma.Install(
			ns3::NodeContainer(csmaSwitches[169], wifi_ap_nodes[36]));
	switch_devices[169].Add(aplink36.Get(0));
	ap_device_sets[36].Add(aplink36.Get(1));

	ns3::NetDeviceContainer aplink37;
	aplink37 = csma.Install(
			ns3::NodeContainer(csmaSwitches[180], wifi_ap_nodes[37]));
	switch_devices[180].Add(aplink37.Get(0));
	ap_device_sets[37].Add(aplink37.Get(1));

	ns3::NetDeviceContainer aplink38;
	aplink38 = csma.Install(
			ns3::NodeContainer(csmaSwitches[180], wifi_ap_nodes[38]));
	switch_devices[180].Add(aplink38.Get(0));
	ap_device_sets[38].Add(aplink38.Get(1));

	ns3::NetDeviceContainer aplink313;
	aplink313 = csma.Install(
			ns3::NodeContainer(csmaSwitches[182], wifi_ap_nodes[313]));
	switch_devices[182].Add(aplink313.Get(0));
	ap_device_sets[313].Add(aplink313.Get(1));

	ns3::NetDeviceContainer aplink39;
	aplink39 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], wifi_ap_nodes[39]));
	switch_devices[183].Add(aplink39.Get(0));
	ap_device_sets[39].Add(aplink39.Get(1));

	ns3::NetDeviceContainer aplink40;
	aplink40 = csma.Install(
			ns3::NodeContainer(csmaSwitches[185], wifi_ap_nodes[40]));
	switch_devices[185].Add(aplink40.Get(0));
	ap_device_sets[40].Add(aplink40.Get(1));

	ns3::NetDeviceContainer aplink41;
	aplink41 = csma.Install(
			ns3::NodeContainer(csmaSwitches[187], wifi_ap_nodes[41]));
	switch_devices[187].Add(aplink41.Get(0));
	ap_device_sets[41].Add(aplink41.Get(1));

	ns3::NetDeviceContainer aplink42;
	aplink42 = csma.Install(
			ns3::NodeContainer(csmaSwitches[189], wifi_ap_nodes[42]));
	switch_devices[189].Add(aplink42.Get(0));
	ap_device_sets[42].Add(aplink42.Get(1));

	ns3::NetDeviceContainer aplink43;
	aplink43 = csma.Install(
			ns3::NodeContainer(csmaSwitches[191], wifi_ap_nodes[43]));
	switch_devices[191].Add(aplink43.Get(0));
	ap_device_sets[43].Add(aplink43.Get(1));

	ns3::NetDeviceContainer aplink44;
	aplink44 = csma.Install(
			ns3::NodeContainer(csmaSwitches[194], wifi_ap_nodes[44]));
	switch_devices[194].Add(aplink44.Get(0));
	ap_device_sets[44].Add(aplink44.Get(1));

	ns3::NetDeviceContainer aplink45;
	aplink45 = csma.Install(
			ns3::NodeContainer(csmaSwitches[195], wifi_ap_nodes[45]));
	switch_devices[195].Add(aplink45.Get(0));
	ap_device_sets[45].Add(aplink45.Get(1));

	ns3::NetDeviceContainer aplink46;
	aplink46 = csma.Install(
			ns3::NodeContainer(csmaSwitches[196], wifi_ap_nodes[46]));
	switch_devices[196].Add(aplink46.Get(0));
	ap_device_sets[46].Add(aplink46.Get(1));

	ns3::NetDeviceContainer aplink47;
	aplink47 = csma.Install(
			ns3::NodeContainer(csmaSwitches[196], wifi_ap_nodes[47]));
	switch_devices[196].Add(aplink47.Get(0));
	ap_device_sets[47].Add(aplink47.Get(1));

	ns3::NetDeviceContainer aplink48;
	aplink48 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[48]));
	switch_devices[343].Add(aplink48.Get(0));
	ap_device_sets[48].Add(aplink48.Get(1));

	ns3::NetDeviceContainer aplink49;
	aplink49 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[49]));
	switch_devices[343].Add(aplink49.Get(0));
	ap_device_sets[49].Add(aplink49.Get(1));

	ns3::NetDeviceContainer aplink50;
	aplink50 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[50]));
	switch_devices[343].Add(aplink50.Get(0));
	ap_device_sets[50].Add(aplink50.Get(1));

	ns3::NetDeviceContainer aplink51;
	aplink51 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[51]));
	switch_devices[343].Add(aplink51.Get(0));
	ap_device_sets[51].Add(aplink51.Get(1));

	ns3::NetDeviceContainer aplink52;
	aplink52 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[52]));
	switch_devices[343].Add(aplink52.Get(0));
	ap_device_sets[52].Add(aplink52.Get(1));

	ns3::NetDeviceContainer aplink53;
	aplink53 = csma.Install(
			ns3::NodeContainer(csmaSwitches[343], wifi_ap_nodes[53]));
	switch_devices[343].Add(aplink53.Get(0));
	ap_device_sets[53].Add(aplink53.Get(1));

	ns3::NetDeviceContainer aplink54;
	aplink54 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], wifi_ap_nodes[54]));
	switch_devices[206].Add(aplink54.Get(0));
	ap_device_sets[54].Add(aplink54.Get(1));

	ns3::NetDeviceContainer aplink55;
	aplink55 = csma.Install(
			ns3::NodeContainer(csmaSwitches[205], wifi_ap_nodes[55]));
	switch_devices[205].Add(aplink55.Get(0));
	ap_device_sets[55].Add(aplink55.Get(1));

	ns3::NetDeviceContainer aplink56;
	aplink56 = csma.Install(
			ns3::NodeContainer(csmaSwitches[205], wifi_ap_nodes[56]));
	switch_devices[205].Add(aplink56.Get(0));
	ap_device_sets[56].Add(aplink56.Get(1));

	ns3::NetDeviceContainer aplink57;
	aplink57 = csma.Install(
			ns3::NodeContainer(csmaSwitches[204], wifi_ap_nodes[57]));
	switch_devices[204].Add(aplink57.Get(0));
	ap_device_sets[57].Add(aplink57.Get(1));

	ns3::NetDeviceContainer aplink58;
	aplink58 = csma.Install(
			ns3::NodeContainer(csmaSwitches[204], wifi_ap_nodes[58]));
	switch_devices[204].Add(aplink58.Get(0));
	ap_device_sets[58].Add(aplink58.Get(1));

	ns3::NetDeviceContainer aplink59;
	aplink59 = csma.Install(
			ns3::NodeContainer(csmaSwitches[211], wifi_ap_nodes[59]));
	switch_devices[211].Add(aplink59.Get(0));
	ap_device_sets[59].Add(aplink59.Get(1));

	ns3::NetDeviceContainer aplink60;
	aplink60 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[60]));
	switch_devices[295].Add(aplink60.Get(0));
	ap_device_sets[60].Add(aplink60.Get(1));

	ns3::NetDeviceContainer aplink61;
	aplink61 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[61]));
	switch_devices[295].Add(aplink61.Get(0));
	ap_device_sets[61].Add(aplink61.Get(1));

	ns3::NetDeviceContainer aplink62;
	aplink62 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[62]));
	switch_devices[295].Add(aplink62.Get(0));
	ap_device_sets[62].Add(aplink62.Get(1));

	ns3::NetDeviceContainer aplink63;
	aplink63 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[63]));
	switch_devices[295].Add(aplink63.Get(0));
	ap_device_sets[63].Add(aplink63.Get(1));

	ns3::NetDeviceContainer aplink64;
	aplink64 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[64]));
	switch_devices[295].Add(aplink64.Get(0));
	ap_device_sets[64].Add(aplink64.Get(1));

	ns3::NetDeviceContainer aplink65;
	aplink65 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], wifi_ap_nodes[65]));
	switch_devices[295].Add(aplink65.Get(0));
	ap_device_sets[65].Add(aplink65.Get(1));

	ns3::NetDeviceContainer aplink66;
	aplink66 = csma.Install(
			ns3::NodeContainer(csmaSwitches[294], wifi_ap_nodes[66]));
	switch_devices[294].Add(aplink66.Get(0));
	ap_device_sets[66].Add(aplink66.Get(1));

	ns3::NetDeviceContainer aplink67;
	aplink67 = csma.Install(
			ns3::NodeContainer(csmaSwitches[294], wifi_ap_nodes[67]));
	switch_devices[294].Add(aplink67.Get(0));
	ap_device_sets[67].Add(aplink67.Get(1));

	ns3::NetDeviceContainer aplink68;
	aplink68 = csma.Install(
			ns3::NodeContainer(csmaSwitches[288], wifi_ap_nodes[68]));
	switch_devices[288].Add(aplink68.Get(0));
	ap_device_sets[68].Add(aplink68.Get(1));

	ns3::NetDeviceContainer aplink69;
	aplink69 = csma.Install(
			ns3::NodeContainer(csmaSwitches[288], wifi_ap_nodes[69]));
	switch_devices[288].Add(aplink69.Get(0));
	ap_device_sets[69].Add(aplink69.Get(1));

	ns3::NetDeviceContainer aplink70;
	aplink70 = csma.Install(
			ns3::NodeContainer(csmaSwitches[288], wifi_ap_nodes[70]));
	switch_devices[288].Add(aplink70.Get(0));
	ap_device_sets[70].Add(aplink70.Get(1));

	ns3::NetDeviceContainer aplink71;
	aplink71 = csma.Install(
			ns3::NodeContainer(csmaSwitches[300], wifi_ap_nodes[71]));
	switch_devices[300].Add(aplink71.Get(0));
	ap_device_sets[71].Add(aplink71.Get(1));

	ns3::NetDeviceContainer aplink72;
	aplink72 = csma.Install(
			ns3::NodeContainer(csmaSwitches[299], wifi_ap_nodes[72]));
	switch_devices[299].Add(aplink72.Get(0));
	ap_device_sets[72].Add(aplink72.Get(1));

	ns3::NetDeviceContainer aplink73;
	aplink73 = csma.Install(
			ns3::NodeContainer(csmaSwitches[302], wifi_ap_nodes[73]));
	switch_devices[302].Add(aplink73.Get(0));
	ap_device_sets[73].Add(aplink73.Get(1));

	ns3::NetDeviceContainer aplink74;
	aplink74 = csma.Install(
			ns3::NodeContainer(csmaSwitches[301], wifi_ap_nodes[74]));
	switch_devices[301].Add(aplink74.Get(0));
	ap_device_sets[74].Add(aplink74.Get(1));

	ns3::NetDeviceContainer aplink75;
	aplink75 = csma.Install(
			ns3::NodeContainer(csmaSwitches[318], wifi_ap_nodes[75]));
	switch_devices[318].Add(aplink75.Get(0));
	ap_device_sets[75].Add(aplink75.Get(1));

	ns3::NetDeviceContainer aplink76;
	aplink76 = csma.Install(
			ns3::NodeContainer(csmaSwitches[318], wifi_ap_nodes[76]));
	switch_devices[318].Add(aplink76.Get(0));
	ap_device_sets[76].Add(aplink76.Get(1));

	ns3::NetDeviceContainer aplink77;
	aplink77 = csma.Install(
			ns3::NodeContainer(csmaSwitches[319], wifi_ap_nodes[77]));
	switch_devices[319].Add(aplink77.Get(0));
	ap_device_sets[77].Add(aplink77.Get(1));

	ns3::NetDeviceContainer aplink78;
	aplink78 = csma.Install(
			ns3::NodeContainer(csmaSwitches[320], wifi_ap_nodes[78]));
	switch_devices[320].Add(aplink78.Get(0));
	ap_device_sets[78].Add(aplink78.Get(1));

	ns3::NetDeviceContainer aplink79;
	aplink79 = csma.Install(
			ns3::NodeContainer(csmaSwitches[322], wifi_ap_nodes[79]));
	switch_devices[322].Add(aplink79.Get(0));
	ap_device_sets[79].Add(aplink79.Get(1));

	ns3::NetDeviceContainer aplink80;
	aplink80 = csma.Install(
			ns3::NodeContainer(csmaSwitches[308], wifi_ap_nodes[80]));
	switch_devices[308].Add(aplink80.Get(0));
	ap_device_sets[80].Add(aplink80.Get(1));

	ns3::NetDeviceContainer aplink81;
	aplink81 = csma.Install(
			ns3::NodeContainer(csmaSwitches[323], wifi_ap_nodes[81]));
	switch_devices[323].Add(aplink81.Get(0));
	ap_device_sets[81].Add(aplink81.Get(1));

	ns3::NetDeviceContainer aplink82;
	aplink82 = csma.Install(
			ns3::NodeContainer(csmaSwitches[324], wifi_ap_nodes[82]));
	switch_devices[324].Add(aplink82.Get(0));
	ap_device_sets[82].Add(aplink82.Get(1));

	ns3::NetDeviceContainer aplink83;
	aplink83 = csma.Install(
			ns3::NodeContainer(csmaSwitches[311], wifi_ap_nodes[83]));
	switch_devices[311].Add(aplink83.Get(0));
	ap_device_sets[83].Add(aplink83.Get(1));

	ns3::NetDeviceContainer aplink84;
	aplink84 = csma.Install(
			ns3::NodeContainer(csmaSwitches[311], wifi_ap_nodes[84]));
	switch_devices[311].Add(aplink84.Get(0));
	ap_device_sets[84].Add(aplink84.Get(1));

	ns3::NetDeviceContainer aplink85;
	aplink85 = csma.Install(
			ns3::NodeContainer(csmaSwitches[311], wifi_ap_nodes[85]));
	switch_devices[311].Add(aplink85.Get(0));
	ap_device_sets[85].Add(aplink85.Get(1));

	ns3::NetDeviceContainer aplink86;
	aplink86 = csma.Install(
			ns3::NodeContainer(csmaSwitches[313], wifi_ap_nodes[86]));
	switch_devices[313].Add(aplink86.Get(0));
	ap_device_sets[86].Add(aplink86.Get(1));

	ns3::NetDeviceContainer aplink87;
	aplink87 = csma.Install(
			ns3::NodeContainer(csmaSwitches[312], wifi_ap_nodes[87]));
	switch_devices[312].Add(aplink87.Get(0));
	ap_device_sets[87].Add(aplink87.Get(1));

	ns3::NetDeviceContainer aplink88;
	aplink88 = csma.Install(
			ns3::NodeContainer(csmaSwitches[312], wifi_ap_nodes[88]));
	switch_devices[312].Add(aplink88.Get(0));
	ap_device_sets[88].Add(aplink88.Get(1));

	ns3::NetDeviceContainer aplink89;
	aplink89 = csma.Install(
			ns3::NodeContainer(csmaSwitches[314], wifi_ap_nodes[89]));
	switch_devices[314].Add(aplink89.Get(0));
	ap_device_sets[89].Add(aplink89.Get(1));

	ns3::NetDeviceContainer aplink90;
	aplink90 = csma.Install(
			ns3::NodeContainer(csmaSwitches[314], wifi_ap_nodes[90]));
	switch_devices[314].Add(aplink90.Get(0));
	ap_device_sets[90].Add(aplink90.Get(1));

	ns3::NetDeviceContainer aplink91;
	aplink91 = csma.Install(
			ns3::NodeContainer(csmaSwitches[315], wifi_ap_nodes[91]));
	switch_devices[315].Add(aplink91.Get(0));
	ap_device_sets[91].Add(aplink91.Get(1));

	ns3::NetDeviceContainer aplink92;
	aplink92 = csma.Install(
			ns3::NodeContainer(csmaSwitches[315], wifi_ap_nodes[92]));
	switch_devices[315].Add(aplink92.Get(0));
	ap_device_sets[92].Add(aplink92.Get(1));

	ns3::NetDeviceContainer aplink93;
	aplink93 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[93]));
	switch_devices[330].Add(aplink93.Get(0));
	ap_device_sets[93].Add(aplink93.Get(1));

	ns3::NetDeviceContainer aplink94;
	aplink94 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[94]));
	switch_devices[330].Add(aplink94.Get(0));
	ap_device_sets[94].Add(aplink94.Get(1));

	ns3::NetDeviceContainer aplink95;
	aplink95 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[95]));
	switch_devices[330].Add(aplink95.Get(0));
	ap_device_sets[95].Add(aplink95.Get(1));

	ns3::NetDeviceContainer aplink96;
	aplink96 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[96]));
	switch_devices[330].Add(aplink96.Get(0));
	ap_device_sets[96].Add(aplink96.Get(1));

	ns3::NetDeviceContainer aplink97;
	aplink97 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[97]));
	switch_devices[330].Add(aplink97.Get(0));
	ap_device_sets[97].Add(aplink97.Get(1));

	ns3::NetDeviceContainer aplink98;
	aplink98 = csma.Install(
			ns3::NodeContainer(csmaSwitches[330], wifi_ap_nodes[98]));
	switch_devices[330].Add(aplink98.Get(0));
	ap_device_sets[98].Add(aplink98.Get(1));

	ns3::NetDeviceContainer aplink99;
	aplink99 = csma.Install(
			ns3::NodeContainer(csmaSwitches[331], wifi_ap_nodes[99]));
	switch_devices[331].Add(aplink99.Get(0));
	ap_device_sets[99].Add(aplink99.Get(1));

	ns3::NetDeviceContainer aplink100;
	aplink100 = csma.Install(
			ns3::NodeContainer(csmaSwitches[331], wifi_ap_nodes[100]));
	switch_devices[331].Add(aplink100.Get(0));
	ap_device_sets[100].Add(aplink100.Get(1));

	ns3::NetDeviceContainer aplink101;
	aplink101 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[101]));
	switch_devices[332].Add(aplink101.Get(0));
	ap_device_sets[101].Add(aplink101.Get(1));

	ns3::NetDeviceContainer aplink102;
	aplink102 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[102]));
	switch_devices[332].Add(aplink102.Get(0));
	ap_device_sets[102].Add(aplink102.Get(1));

	ns3::NetDeviceContainer aplink103;
	aplink103 = csma.Install(
			ns3::NodeContainer(csmaSwitches[315], wifi_ap_nodes[103]));
	switch_devices[315].Add(aplink103.Get(0));
	ap_device_sets[103].Add(aplink103.Get(1));

	ns3::NetDeviceContainer aplink104;
	aplink104 = csma.Install(
			ns3::NodeContainer(csmaSwitches[315], wifi_ap_nodes[104]));
	switch_devices[315].Add(aplink104.Get(0));
	ap_device_sets[104].Add(aplink104.Get(1));

	ns3::NetDeviceContainer aplink105;
	aplink105 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], wifi_ap_nodes[105]));
	switch_devices[328].Add(aplink105.Get(0));
	ap_device_sets[105].Add(aplink105.Get(1));

	ns3::NetDeviceContainer aplink106;
	aplink106 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], wifi_ap_nodes[106]));
	switch_devices[328].Add(aplink106.Get(0));
	ap_device_sets[106].Add(aplink106.Get(1));

	ns3::NetDeviceContainer aplink107;
	aplink107 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], wifi_ap_nodes[107]));
	switch_devices[328].Add(aplink107.Get(0));
	ap_device_sets[107].Add(aplink107.Get(1));

	ns3::NetDeviceContainer aplink108;
	aplink108 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], wifi_ap_nodes[108]));
	switch_devices[328].Add(aplink108.Get(0));
	ap_device_sets[108].Add(aplink108.Get(1));

	ns3::NetDeviceContainer aplink109;
	aplink109 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], wifi_ap_nodes[109]));
	switch_devices[328].Add(aplink109.Get(0));
	ap_device_sets[109].Add(aplink109.Get(1));

	ns3::NetDeviceContainer aplink110;
	aplink110 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[110]));
	switch_devices[326].Add(aplink110.Get(0));
	ap_device_sets[110].Add(aplink110.Get(1));

	ns3::NetDeviceContainer aplink111;
	aplink111 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[111]));
	switch_devices[326].Add(aplink111.Get(0));
	ap_device_sets[111].Add(aplink111.Get(1));

	ns3::NetDeviceContainer aplink112;
	aplink112 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[112]));
	switch_devices[326].Add(aplink112.Get(0));
	ap_device_sets[112].Add(aplink112.Get(1));

	ns3::NetDeviceContainer aplink113;
	aplink113 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[113]));
	switch_devices[326].Add(aplink113.Get(0));
	ap_device_sets[113].Add(aplink113.Get(1));

	ns3::NetDeviceContainer aplink114;
	aplink114 = csma.Install(
			ns3::NodeContainer(csmaSwitches[327], wifi_ap_nodes[114]));
	switch_devices[327].Add(aplink114.Get(0));
	ap_device_sets[114].Add(aplink114.Get(1));

	ns3::NetDeviceContainer aplink115;
	aplink115 = csma.Install(
			ns3::NodeContainer(csmaSwitches[327], wifi_ap_nodes[115]));
	switch_devices[327].Add(aplink115.Get(0));
	ap_device_sets[115].Add(aplink115.Get(1));

	ns3::NetDeviceContainer aplink116;
	aplink116 = csma.Install(
			ns3::NodeContainer(csmaSwitches[327], wifi_ap_nodes[116]));
	switch_devices[327].Add(aplink116.Get(0));
	ap_device_sets[116].Add(aplink116.Get(1));

	ns3::NetDeviceContainer aplink117;
	aplink117 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[117]));
	switch_devices[326].Add(aplink117.Get(0));
	ap_device_sets[117].Add(aplink117.Get(1));

	ns3::NetDeviceContainer aplink118;
	aplink118 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[118]));
	switch_devices[326].Add(aplink118.Get(0));
	ap_device_sets[118].Add(aplink118.Get(1));

	ns3::NetDeviceContainer aplink119;
	aplink119 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[119]));
	switch_devices[326].Add(aplink119.Get(0));
	ap_device_sets[119].Add(aplink119.Get(1));

	ns3::NetDeviceContainer aplink120;
	aplink120 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[120]));
	switch_devices[326].Add(aplink120.Get(0));
	ap_device_sets[120].Add(aplink120.Get(1));

	ns3::NetDeviceContainer aplink121;
	aplink121 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[121]));
	switch_devices[326].Add(aplink121.Get(0));
	ap_device_sets[121].Add(aplink121.Get(1));

	ns3::NetDeviceContainer aplink122;
	aplink122 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[122]));
	switch_devices[326].Add(aplink122.Get(0));
	ap_device_sets[122].Add(aplink122.Get(1));

	ns3::NetDeviceContainer aplink123;
	aplink123 = csma.Install(
			ns3::NodeContainer(csmaSwitches[326], wifi_ap_nodes[123]));
	switch_devices[326].Add(aplink123.Get(0));
	ap_device_sets[123].Add(aplink123.Get(1));

	ns3::NetDeviceContainer aplink124;
	aplink124 = csma.Install(
			ns3::NodeContainer(csmaSwitches[294], wifi_ap_nodes[124]));
	switch_devices[294].Add(aplink124.Get(0));
	ap_device_sets[124].Add(aplink124.Get(1));

	ns3::NetDeviceContainer aplink125;
	aplink125 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[125]));
	switch_devices[332].Add(aplink125.Get(0));
	ap_device_sets[125].Add(aplink125.Get(1));

	ns3::NetDeviceContainer aplink126;
	aplink126 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[126]));
	switch_devices[332].Add(aplink126.Get(0));
	ap_device_sets[126].Add(aplink126.Get(1));

	ns3::NetDeviceContainer aplink127;
	aplink127 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[127]));
	switch_devices[332].Add(aplink127.Get(0));
	ap_device_sets[127].Add(aplink127.Get(1));

	ns3::NetDeviceContainer aplink128;
	aplink128 = csma.Install(
			ns3::NodeContainer(csmaSwitches[332], wifi_ap_nodes[128]));
	switch_devices[332].Add(aplink128.Get(0));
	ap_device_sets[128].Add(aplink128.Get(1));

	ns3::NetDeviceContainer aplink129;
	aplink129 = csma.Install(
			ns3::NodeContainer(csmaSwitches[215], wifi_ap_nodes[129]));
	switch_devices[215].Add(aplink129.Get(0));
	ap_device_sets[129].Add(aplink129.Get(1));

	ns3::NetDeviceContainer aplink130;
	aplink130 = csma.Install(
			ns3::NodeContainer(csmaSwitches[217], wifi_ap_nodes[130]));
	switch_devices[217].Add(aplink130.Get(0));
	ap_device_sets[130].Add(aplink130.Get(1));

	ns3::NetDeviceContainer aplink131;
	aplink131 = csma.Install(
			ns3::NodeContainer(csmaSwitches[218], wifi_ap_nodes[131]));
	switch_devices[218].Add(aplink131.Get(0));
	ap_device_sets[131].Add(aplink131.Get(1));

	ns3::NetDeviceContainer aplink132;
	aplink132 = csma.Install(
			ns3::NodeContainer(csmaSwitches[219], wifi_ap_nodes[132]));
	switch_devices[219].Add(aplink132.Get(0));
	ap_device_sets[132].Add(aplink132.Get(1));

	ns3::NetDeviceContainer aplink133;
	aplink133 = csma.Install(
			ns3::NodeContainer(csmaSwitches[221], wifi_ap_nodes[133]));
	switch_devices[221].Add(aplink133.Get(0));
	ap_device_sets[133].Add(aplink133.Get(1));

	ns3::NetDeviceContainer aplink134;
	aplink134 = csma.Install(
			ns3::NodeContainer(csmaSwitches[221], wifi_ap_nodes[134]));
	switch_devices[221].Add(aplink134.Get(0));
	ap_device_sets[134].Add(aplink134.Get(1));

	ns3::NetDeviceContainer aplink135;
	aplink135 = csma.Install(
			ns3::NodeContainer(csmaSwitches[222], wifi_ap_nodes[135]));
	switch_devices[222].Add(aplink135.Get(0));
	ap_device_sets[135].Add(aplink135.Get(1));

	ns3::NetDeviceContainer aplink136;
	aplink136 = csma.Install(
			ns3::NodeContainer(csmaSwitches[222], wifi_ap_nodes[136]));
	switch_devices[222].Add(aplink136.Get(0));
	ap_device_sets[136].Add(aplink136.Get(1));

	ns3::NetDeviceContainer aplink137;
	aplink137 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], wifi_ap_nodes[137]));
	switch_devices[220].Add(aplink137.Get(0));
	ap_device_sets[137].Add(aplink137.Get(1));

	ns3::NetDeviceContainer aplink138;
	aplink138 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], wifi_ap_nodes[138]));
	switch_devices[220].Add(aplink138.Get(0));
	ap_device_sets[138].Add(aplink138.Get(1));

	ns3::NetDeviceContainer aplink139;
	aplink139 = csma.Install(
			ns3::NodeContainer(csmaSwitches[227], wifi_ap_nodes[139]));
	switch_devices[227].Add(aplink139.Get(0));
	ap_device_sets[139].Add(aplink139.Get(1));

	ns3::NetDeviceContainer aplink140;
	aplink140 = csma.Install(
			ns3::NodeContainer(csmaSwitches[228], wifi_ap_nodes[140]));
	switch_devices[228].Add(aplink140.Get(0));
	ap_device_sets[140].Add(aplink140.Get(1));

	ns3::NetDeviceContainer aplink141;
	aplink141 = csma.Install(
			ns3::NodeContainer(csmaSwitches[224], wifi_ap_nodes[141]));
	switch_devices[224].Add(aplink141.Get(0));
	ap_device_sets[141].Add(aplink141.Get(1));

	ns3::NetDeviceContainer aplink142;
	aplink142 = csma.Install(
			ns3::NodeContainer(csmaSwitches[225], wifi_ap_nodes[142]));
	switch_devices[225].Add(aplink142.Get(0));
	ap_device_sets[142].Add(aplink142.Get(1));

	ns3::NetDeviceContainer aplink143;
	aplink143 = csma.Install(
			ns3::NodeContainer(csmaSwitches[225], wifi_ap_nodes[143]));
	switch_devices[225].Add(aplink143.Get(0));
	ap_device_sets[143].Add(aplink143.Get(1));

	ns3::NetDeviceContainer aplink144;
	aplink144 = csma.Install(
			ns3::NodeContainer(csmaSwitches[284], wifi_ap_nodes[144]));
	switch_devices[284].Add(aplink144.Get(0));
	ap_device_sets[144].Add(aplink144.Get(1));

	ns3::NetDeviceContainer aplink145;
	aplink145 = csma.Install(
			ns3::NodeContainer(csmaSwitches[259], wifi_ap_nodes[145]));
	switch_devices[259].Add(aplink145.Get(0));
	ap_device_sets[145].Add(aplink145.Get(1));

	ns3::NetDeviceContainer aplink146;
	aplink146 = csma.Install(
			ns3::NodeContainer(csmaSwitches[259], wifi_ap_nodes[146]));
	switch_devices[259].Add(aplink146.Get(0));
	ap_device_sets[146].Add(aplink146.Get(1));

	ns3::NetDeviceContainer aplink147;
	aplink147 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[147]));
	switch_devices[260].Add(aplink147.Get(0));
	ap_device_sets[147].Add(aplink147.Get(1));

	ns3::NetDeviceContainer aplink148;
	aplink148 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[148]));
	switch_devices[260].Add(aplink148.Get(0));
	ap_device_sets[148].Add(aplink148.Get(1));

	ns3::NetDeviceContainer aplink149;
	aplink149 = csma.Install(
			ns3::NodeContainer(csmaSwitches[261], wifi_ap_nodes[149]));
	switch_devices[261].Add(aplink149.Get(0));
	ap_device_sets[149].Add(aplink149.Get(1));

	ns3::NetDeviceContainer aplink150;
	aplink150 = csma.Install(
			ns3::NodeContainer(csmaSwitches[262], wifi_ap_nodes[150]));
	switch_devices[262].Add(aplink150.Get(0));
	ap_device_sets[150].Add(aplink150.Get(1));

	ns3::NetDeviceContainer aplink151;
	aplink151 = csma.Install(
			ns3::NodeContainer(csmaSwitches[262], wifi_ap_nodes[151]));
	switch_devices[262].Add(aplink151.Get(0));
	ap_device_sets[151].Add(aplink151.Get(1));

	ns3::NetDeviceContainer aplink152;
	aplink152 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[152]));
	switch_devices[268].Add(aplink152.Get(0));
	ap_device_sets[152].Add(aplink152.Get(1));

	ns3::NetDeviceContainer aplink153;
	aplink153 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[153]));
	switch_devices[268].Add(aplink153.Get(0));
	ap_device_sets[153].Add(aplink153.Get(1));

	ns3::NetDeviceContainer aplink154;
	aplink154 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[154]));
	switch_devices[268].Add(aplink154.Get(0));
	ap_device_sets[154].Add(aplink154.Get(1));

	ns3::NetDeviceContainer aplink155;
	aplink155 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[155]));
	switch_devices[268].Add(aplink155.Get(0));
	ap_device_sets[155].Add(aplink155.Get(1));

	ns3::NetDeviceContainer aplink156;
	aplink156 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[156]));
	switch_devices[268].Add(aplink156.Get(0));
	ap_device_sets[156].Add(aplink156.Get(1));

	ns3::NetDeviceContainer aplink157;
	aplink157 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[157]));
	switch_devices[214].Add(aplink157.Get(0));
	ap_device_sets[157].Add(aplink157.Get(1));

	ns3::NetDeviceContainer aplink158;
	aplink158 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[158]));
	switch_devices[214].Add(aplink158.Get(0));
	ap_device_sets[158].Add(aplink158.Get(1));

	ns3::NetDeviceContainer aplink159;
	aplink159 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[159]));
	switch_devices[214].Add(aplink159.Get(0));
	ap_device_sets[159].Add(aplink159.Get(1));

	ns3::NetDeviceContainer aplink160;
	aplink160 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[160]));
	switch_devices[214].Add(aplink160.Get(0));
	ap_device_sets[160].Add(aplink160.Get(1));

	ns3::NetDeviceContainer aplink161;
	aplink161 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[161]));
	switch_devices[214].Add(aplink161.Get(0));
	ap_device_sets[161].Add(aplink161.Get(1));

	ns3::NetDeviceContainer aplink162;
	aplink162 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[162]));
	switch_devices[214].Add(aplink162.Get(0));
	ap_device_sets[162].Add(aplink162.Get(1));

	ns3::NetDeviceContainer aplink163;
	aplink163 = csma.Install(
			ns3::NodeContainer(csmaSwitches[214], wifi_ap_nodes[163]));
	switch_devices[214].Add(aplink163.Get(0));
	ap_device_sets[163].Add(aplink163.Get(1));

	ns3::NetDeviceContainer aplink164;
	aplink164 = csma.Install(
			ns3::NodeContainer(csmaSwitches[269], wifi_ap_nodes[164]));
	switch_devices[269].Add(aplink164.Get(0));
	ap_device_sets[164].Add(aplink164.Get(1));

	ns3::NetDeviceContainer aplink165;
	aplink165 = csma.Install(
			ns3::NodeContainer(csmaSwitches[270], wifi_ap_nodes[165]));
	switch_devices[270].Add(aplink165.Get(0));
	ap_device_sets[165].Add(aplink165.Get(1));

	ns3::NetDeviceContainer aplink166;
	aplink166 = csma.Install(
			ns3::NodeContainer(csmaSwitches[273], wifi_ap_nodes[166]));
	switch_devices[273].Add(aplink166.Get(0));
	ap_device_sets[166].Add(aplink166.Get(1));

	ns3::NetDeviceContainer aplink167;
	aplink167 = csma.Install(
			ns3::NodeContainer(csmaSwitches[277], wifi_ap_nodes[167]));
	switch_devices[277].Add(aplink167.Get(0));
	ap_device_sets[167].Add(aplink167.Get(1));

	ns3::NetDeviceContainer aplink168;
	aplink168 = csma.Install(
			ns3::NodeContainer(csmaSwitches[278], wifi_ap_nodes[168]));
	switch_devices[278].Add(aplink168.Get(0));
	ap_device_sets[168].Add(aplink168.Get(1));

	ns3::NetDeviceContainer aplink169;
	aplink169 = csma.Install(
			ns3::NodeContainer(csmaSwitches[280], wifi_ap_nodes[169]));
	switch_devices[280].Add(aplink169.Get(0));
	ap_device_sets[169].Add(aplink169.Get(1));

	ns3::NetDeviceContainer aplink170;
	aplink170 = csma.Install(
			ns3::NodeContainer(csmaSwitches[282], wifi_ap_nodes[170]));
	switch_devices[282].Add(aplink170.Get(0));
	ap_device_sets[170].Add(aplink170.Get(1));

	ns3::NetDeviceContainer aplink171;
	aplink171 = csma.Install(
			ns3::NodeContainer(csmaSwitches[263], wifi_ap_nodes[171]));
	switch_devices[263].Add(aplink171.Get(0));
	ap_device_sets[171].Add(aplink171.Get(1));

	ns3::NetDeviceContainer aplink172;
	aplink172 = csma.Install(
			ns3::NodeContainer(csmaSwitches[238], wifi_ap_nodes[172]));
	switch_devices[238].Add(aplink172.Get(0));
	ap_device_sets[172].Add(aplink172.Get(1));

	ns3::NetDeviceContainer aplink173;
	aplink173 = csma.Install(
			ns3::NodeContainer(csmaSwitches[238], wifi_ap_nodes[173]));
	switch_devices[238].Add(aplink173.Get(0));
	ap_device_sets[173].Add(aplink173.Get(1));

	ns3::NetDeviceContainer aplink174;
	aplink174 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[174]));
	switch_devices[268].Add(aplink174.Get(0));
	ap_device_sets[174].Add(aplink174.Get(1));

	ns3::NetDeviceContainer aplink175;
	aplink175 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[175]));
	switch_devices[268].Add(aplink175.Get(0));
	ap_device_sets[175].Add(aplink175.Get(1));

	ns3::NetDeviceContainer aplink176;
	aplink176 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[176]));
	switch_devices[268].Add(aplink176.Get(0));
	ap_device_sets[176].Add(aplink176.Get(1));

	ns3::NetDeviceContainer aplink177;
	aplink177 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[177]));
	switch_devices[260].Add(aplink177.Get(0));
	ap_device_sets[177].Add(aplink177.Get(1));

	ns3::NetDeviceContainer aplink178;
	aplink178 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[178]));
	switch_devices[260].Add(aplink178.Get(0));
	ap_device_sets[178].Add(aplink178.Get(1));

	ns3::NetDeviceContainer aplink179;
	aplink179 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[179]));
	switch_devices[260].Add(aplink179.Get(0));
	ap_device_sets[179].Add(aplink179.Get(1));

	ns3::NetDeviceContainer aplink180;
	aplink180 = csma.Install(
			ns3::NodeContainer(csmaSwitches[260], wifi_ap_nodes[180]));
	switch_devices[260].Add(aplink180.Get(0));
	ap_device_sets[180].Add(aplink180.Get(1));

	ns3::NetDeviceContainer aplink181;
	aplink181 = csma.Install(
			ns3::NodeContainer(csmaSwitches[268], wifi_ap_nodes[181]));
	switch_devices[268].Add(aplink181.Get(0));
	ap_device_sets[181].Add(aplink181.Get(1));

	ns3::NetDeviceContainer aplink182;
	aplink182 = csma.Install(
			ns3::NodeContainer(csmaSwitches[234], wifi_ap_nodes[182]));
	switch_devices[234].Add(aplink182.Get(0));
	ap_device_sets[182].Add(aplink182.Get(1));

	ns3::NetDeviceContainer aplink183;
	aplink183 = csma.Install(
			ns3::NodeContainer(csmaSwitches[235], wifi_ap_nodes[183]));
	switch_devices[235].Add(aplink183.Get(0));
	ap_device_sets[183].Add(aplink183.Get(1));

	ns3::NetDeviceContainer aplink184;
	aplink184 = csma.Install(
			ns3::NodeContainer(csmaSwitches[235], wifi_ap_nodes[184]));
	switch_devices[235].Add(aplink184.Get(0));
	ap_device_sets[184].Add(aplink184.Get(1));

	ns3::NetDeviceContainer aplink185;
	aplink185 = csma.Install(
			ns3::NodeContainer(csmaSwitches[231], wifi_ap_nodes[185]));
	switch_devices[231].Add(aplink185.Get(0));
	ap_device_sets[185].Add(aplink185.Get(1));

	ns3::NetDeviceContainer aplink186;
	aplink186 = csma.Install(
			ns3::NodeContainer(csmaSwitches[231], wifi_ap_nodes[186]));
	switch_devices[231].Add(aplink186.Get(0));
	ap_device_sets[186].Add(aplink186.Get(1));

	ns3::NetDeviceContainer aplink187;
	aplink187 = csma.Install(
			ns3::NodeContainer(csmaSwitches[231], wifi_ap_nodes[187]));
	switch_devices[231].Add(aplink187.Get(0));
	ap_device_sets[187].Add(aplink187.Get(1));

	ns3::NetDeviceContainer aplink188;
	aplink188 = csma.Install(
			ns3::NodeContainer(csmaSwitches[231], wifi_ap_nodes[188]));
	switch_devices[231].Add(aplink188.Get(0));
	ap_device_sets[188].Add(aplink188.Get(1));

	ns3::NetDeviceContainer aplink189;
	aplink189 = csma.Install(
			ns3::NodeContainer(csmaSwitches[138], wifi_ap_nodes[189]));
	switch_devices[138].Add(aplink189.Get(0));
	ap_device_sets[189].Add(aplink189.Get(1));

	ns3::NetDeviceContainer aplink190;
	aplink190 = csma.Install(
			ns3::NodeContainer(csmaSwitches[138], wifi_ap_nodes[190]));
	switch_devices[138].Add(aplink190.Get(0));
	ap_device_sets[190].Add(aplink190.Get(1));

	ns3::NetDeviceContainer aplink191;
	aplink191 = csma.Install(
			ns3::NodeContainer(csmaSwitches[139], wifi_ap_nodes[191]));
	switch_devices[139].Add(aplink191.Get(0));
	ap_device_sets[191].Add(aplink191.Get(1));

	ns3::NetDeviceContainer aplink192;
	aplink192 = csma.Install(
			ns3::NodeContainer(csmaSwitches[139], wifi_ap_nodes[192]));
	switch_devices[139].Add(aplink192.Get(0));
	ap_device_sets[192].Add(aplink192.Get(1));

	ns3::NetDeviceContainer aplink193;
	aplink193 = csma.Install(
			ns3::NodeContainer(csmaSwitches[140], wifi_ap_nodes[193]));
	switch_devices[140].Add(aplink193.Get(0));
	ap_device_sets[193].Add(aplink193.Get(1));

	ns3::NetDeviceContainer aplink194;
	aplink194 = csma.Install(
			ns3::NodeContainer(csmaSwitches[140], wifi_ap_nodes[194]));
	switch_devices[140].Add(aplink194.Get(0));
	ap_device_sets[194].Add(aplink194.Get(1));

	ns3::NetDeviceContainer aplink195;
	aplink195 = csma.Install(
			ns3::NodeContainer(csmaSwitches[140], wifi_ap_nodes[195]));
	switch_devices[140].Add(aplink195.Get(0));
	ap_device_sets[195].Add(aplink195.Get(1));

	ns3::NetDeviceContainer aplink196;
	aplink196 = csma.Install(
			ns3::NodeContainer(csmaSwitches[140], wifi_ap_nodes[196]));
	switch_devices[140].Add(aplink196.Get(0));
	ap_device_sets[196].Add(aplink196.Get(1));

	ns3::NetDeviceContainer aplink197;
	aplink197 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], wifi_ap_nodes[197]));
	switch_devices[126].Add(aplink197.Get(0));
	ap_device_sets[197].Add(aplink197.Get(1));

	ns3::NetDeviceContainer aplink198;
	aplink198 = csma.Install(
			ns3::NodeContainer(csmaSwitches[129], wifi_ap_nodes[198]));
	switch_devices[129].Add(aplink198.Get(0));
	ap_device_sets[198].Add(aplink198.Get(1));

	ns3::NetDeviceContainer aplink199;
	aplink199 = csma.Install(
			ns3::NodeContainer(csmaSwitches[129], wifi_ap_nodes[199]));
	switch_devices[129].Add(aplink199.Get(0));
	ap_device_sets[199].Add(aplink199.Get(1));

	ns3::NetDeviceContainer aplink200;
	aplink200 = csma.Install(
			ns3::NodeContainer(csmaSwitches[130], wifi_ap_nodes[200]));
	switch_devices[130].Add(aplink200.Get(0));
	ap_device_sets[200].Add(aplink200.Get(1));

	ns3::NetDeviceContainer aplink201;
	aplink201 = csma.Install(
			ns3::NodeContainer(csmaSwitches[136], wifi_ap_nodes[201]));
	switch_devices[136].Add(aplink201.Get(0));
	ap_device_sets[201].Add(aplink201.Get(1));

	ns3::NetDeviceContainer aplink202;
	aplink202 = csma.Install(
			ns3::NodeContainer(csmaSwitches[142], wifi_ap_nodes[202]));
	switch_devices[142].Add(aplink202.Get(0));
	ap_device_sets[202].Add(aplink202.Get(1));

	ns3::NetDeviceContainer aplink203;
	aplink203 = csma.Install(
			ns3::NodeContainer(csmaSwitches[142], wifi_ap_nodes[203]));
	switch_devices[142].Add(aplink203.Get(0));
	ap_device_sets[203].Add(aplink203.Get(1));

	ns3::NetDeviceContainer aplink204;
	aplink204 = csma.Install(
			ns3::NodeContainer(csmaSwitches[150], wifi_ap_nodes[204]));
	switch_devices[150].Add(aplink204.Get(0));
	ap_device_sets[204].Add(aplink204.Get(1));

	ns3::NetDeviceContainer aplink205;
	aplink205 = csma.Install(
			ns3::NodeContainer(csmaSwitches[150], wifi_ap_nodes[205]));
	switch_devices[150].Add(aplink205.Get(0));
	ap_device_sets[205].Add(aplink205.Get(1));

	ns3::NetDeviceContainer aplink206;
	aplink206 = csma.Install(
			ns3::NodeContainer(csmaSwitches[150], wifi_ap_nodes[206]));
	switch_devices[150].Add(aplink206.Get(0));
	ap_device_sets[206].Add(aplink206.Get(1));

	ns3::NetDeviceContainer aplink207;
	aplink207 = csma.Install(
			ns3::NodeContainer(csmaSwitches[147], wifi_ap_nodes[207]));
	switch_devices[147].Add(aplink207.Get(0));
	ap_device_sets[207].Add(aplink207.Get(1));

	ns3::NetDeviceContainer aplink208;
	aplink208 = csma.Install(
			ns3::NodeContainer(csmaSwitches[147], wifi_ap_nodes[208]));
	switch_devices[147].Add(aplink208.Get(0));
	ap_device_sets[208].Add(aplink208.Get(1));

	ns3::NetDeviceContainer aplink209;
	aplink209 = csma.Install(
			ns3::NodeContainer(csmaSwitches[146], wifi_ap_nodes[209]));
	switch_devices[146].Add(aplink209.Get(0));
	ap_device_sets[209].Add(aplink209.Get(1));

	ns3::NetDeviceContainer aplink210;
	aplink210 = csma.Install(
			ns3::NodeContainer(csmaSwitches[146], wifi_ap_nodes[210]));
	switch_devices[146].Add(aplink210.Get(0));
	ap_device_sets[210].Add(aplink210.Get(1));

	ns3::NetDeviceContainer aplink211;
	aplink211 = csma.Install(
			ns3::NodeContainer(csmaSwitches[151], wifi_ap_nodes[211]));
	switch_devices[151].Add(aplink211.Get(0));
	ap_device_sets[211].Add(aplink211.Get(1));

	ns3::NetDeviceContainer aplink212;
	aplink212 = csma.Install(
			ns3::NodeContainer(csmaSwitches[151], wifi_ap_nodes[212]));
	switch_devices[151].Add(aplink212.Get(0));
	ap_device_sets[212].Add(aplink212.Get(1));

	ns3::NetDeviceContainer aplink213;
	aplink213 = csma.Install(
			ns3::NodeContainer(csmaSwitches[148], wifi_ap_nodes[213]));
	switch_devices[148].Add(aplink213.Get(0));
	ap_device_sets[213].Add(aplink213.Get(1));

	ns3::NetDeviceContainer aplink214;
	aplink214 = csma.Install(
			ns3::NodeContainer(csmaSwitches[148], wifi_ap_nodes[214]));
	switch_devices[148].Add(aplink214.Get(0));
	ap_device_sets[214].Add(aplink214.Get(1));

	ns3::NetDeviceContainer aplink215;
	aplink215 = csma.Install(
			ns3::NodeContainer(csmaSwitches[144], wifi_ap_nodes[215]));
	switch_devices[144].Add(aplink215.Get(0));
	ap_device_sets[215].Add(aplink215.Get(1));

	ns3::NetDeviceContainer aplink216;
	aplink216 = csma.Install(
			ns3::NodeContainer(csmaSwitches[144], wifi_ap_nodes[216]));
	switch_devices[144].Add(aplink216.Get(0));
	ap_device_sets[216].Add(aplink216.Get(1));

	ns3::NetDeviceContainer aplink217;
	aplink217 = csma.Install(
			ns3::NodeContainer(csmaSwitches[144], wifi_ap_nodes[217]));
	switch_devices[144].Add(aplink217.Get(0));
	ap_device_sets[217].Add(aplink217.Get(1));

	ns3::NetDeviceContainer aplink218;
	aplink218 = csma.Install(
			ns3::NodeContainer(csmaSwitches[157], wifi_ap_nodes[218]));
	switch_devices[157].Add(aplink218.Get(0));
	ap_device_sets[218].Add(aplink218.Get(1));

	ns3::NetDeviceContainer aplink219;
	aplink219 = csma.Install(
			ns3::NodeContainer(csmaSwitches[149], wifi_ap_nodes[219]));
	switch_devices[149].Add(aplink219.Get(0));
	ap_device_sets[219].Add(aplink219.Get(1));

	ns3::NetDeviceContainer aplink220;
	aplink220 = csma.Install(
			ns3::NodeContainer(csmaSwitches[149], wifi_ap_nodes[220]));
	switch_devices[149].Add(aplink220.Get(0));
	ap_device_sets[220].Add(aplink220.Get(1));

	ns3::NetDeviceContainer aplink221;
	aplink221 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[221]));
	switch_devices[158].Add(aplink221.Get(0));
	ap_device_sets[221].Add(aplink221.Get(1));

	ns3::NetDeviceContainer aplink222;
	aplink222 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[222]));
	switch_devices[158].Add(aplink222.Get(0));
	ap_device_sets[222].Add(aplink222.Get(1));

	ns3::NetDeviceContainer aplink223;
	aplink223 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[223]));
	switch_devices[158].Add(aplink223.Get(0));
	ap_device_sets[223].Add(aplink223.Get(1));

	ns3::NetDeviceContainer aplink224;
	aplink224 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[224]));
	switch_devices[158].Add(aplink224.Get(0));
	ap_device_sets[224].Add(aplink224.Get(1));

	ns3::NetDeviceContainer aplink225;
	aplink225 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[225]));
	switch_devices[158].Add(aplink225.Get(0));
	ap_device_sets[225].Add(aplink225.Get(1));

	ns3::NetDeviceContainer aplink226;
	aplink226 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[226]));
	switch_devices[158].Add(aplink226.Get(0));
	ap_device_sets[226].Add(aplink226.Get(1));

	ns3::NetDeviceContainer aplink227;
	aplink227 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[227]));
	switch_devices[158].Add(aplink227.Get(0));
	ap_device_sets[227].Add(aplink227.Get(1));

	ns3::NetDeviceContainer aplink228;
	aplink228 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[228]));
	switch_devices[158].Add(aplink228.Get(0));
	ap_device_sets[228].Add(aplink228.Get(1));

	ns3::NetDeviceContainer aplink229;
	aplink229 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[229]));
	switch_devices[158].Add(aplink229.Get(0));
	ap_device_sets[229].Add(aplink229.Get(1));

	ns3::NetDeviceContainer aplink230;
	aplink230 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], wifi_ap_nodes[230]));
	switch_devices[158].Add(aplink230.Get(0));
	ap_device_sets[230].Add(aplink230.Get(1));

	ns3::NetDeviceContainer aplink231;
	aplink231 = csma.Install(
			ns3::NodeContainer(csmaSwitches[117], wifi_ap_nodes[231]));
	switch_devices[117].Add(aplink231.Get(0));
	ap_device_sets[231].Add(aplink231.Get(1));

	ns3::NetDeviceContainer aplink232;
	aplink232 = csma.Install(
			ns3::NodeContainer(csmaSwitches[121], wifi_ap_nodes[232]));
	switch_devices[121].Add(aplink232.Get(0));
	ap_device_sets[232].Add(aplink232.Get(1));

	ns3::NetDeviceContainer aplink233;
	aplink233 = csma.Install(
			ns3::NodeContainer(csmaSwitches[122], wifi_ap_nodes[233]));
	switch_devices[122].Add(aplink233.Get(0));
	ap_device_sets[233].Add(aplink233.Get(1));

	ns3::NetDeviceContainer aplink234;
	aplink234 = csma.Install(
			ns3::NodeContainer(csmaSwitches[119], wifi_ap_nodes[234]));
	switch_devices[119].Add(aplink234.Get(0));
	ap_device_sets[234].Add(aplink234.Get(1));

	ns3::NetDeviceContainer aplink235;
	aplink235 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[235]));
	switch_devices[51].Add(aplink235.Get(0));
	ap_device_sets[235].Add(aplink235.Get(1));

	ns3::NetDeviceContainer aplink236;
	aplink236 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[236]));
	switch_devices[51].Add(aplink236.Get(0));
	ap_device_sets[236].Add(aplink236.Get(1));

	ns3::NetDeviceContainer aplink237;
	aplink237 = csma.Install(
			ns3::NodeContainer(csmaSwitches[52], wifi_ap_nodes[237]));
	switch_devices[52].Add(aplink237.Get(0));
	ap_device_sets[237].Add(aplink237.Get(1));

	ns3::NetDeviceContainer aplink238;
	aplink238 = csma.Install(
			ns3::NodeContainer(csmaSwitches[52], wifi_ap_nodes[238]));
	switch_devices[52].Add(aplink238.Get(0));
	ap_device_sets[238].Add(aplink238.Get(1));

	ns3::NetDeviceContainer aplink239;
	aplink239 = csma.Install(
			ns3::NodeContainer(csmaSwitches[52], wifi_ap_nodes[239]));
	switch_devices[52].Add(aplink239.Get(0));
	ap_device_sets[239].Add(aplink239.Get(1));

	ns3::NetDeviceContainer aplink240;
	aplink240 = csma.Install(
			ns3::NodeContainer(csmaSwitches[54], wifi_ap_nodes[240]));
	switch_devices[54].Add(aplink240.Get(0));
	ap_device_sets[240].Add(aplink240.Get(1));

	ns3::NetDeviceContainer aplink241;
	aplink241 = csma.Install(
			ns3::NodeContainer(csmaSwitches[56], wifi_ap_nodes[241]));
	switch_devices[56].Add(aplink241.Get(0));
	ap_device_sets[241].Add(aplink241.Get(1));

	ns3::NetDeviceContainer aplink242;
	aplink242 = csma.Install(
			ns3::NodeContainer(csmaSwitches[56], wifi_ap_nodes[242]));
	switch_devices[56].Add(aplink242.Get(0));
	ap_device_sets[242].Add(aplink242.Get(1));

	ns3::NetDeviceContainer aplink243;
	aplink243 = csma.Install(
			ns3::NodeContainer(csmaSwitches[57], wifi_ap_nodes[243]));
	switch_devices[57].Add(aplink243.Get(0));
	ap_device_sets[243].Add(aplink243.Get(1));

	ns3::NetDeviceContainer aplink244;
	aplink244 = csma.Install(
			ns3::NodeContainer(csmaSwitches[71], wifi_ap_nodes[244]));
	switch_devices[71].Add(aplink244.Get(0));
	ap_device_sets[244].Add(aplink244.Get(1));

	ns3::NetDeviceContainer aplink245;
	aplink245 = csma.Install(
			ns3::NodeContainer(csmaSwitches[71], wifi_ap_nodes[245]));
	switch_devices[71].Add(aplink245.Get(0));
	ap_device_sets[245].Add(aplink245.Get(1));

	ns3::NetDeviceContainer aplink246;
	aplink246 = csma.Install(
			ns3::NodeContainer(csmaSwitches[71], wifi_ap_nodes[246]));
	switch_devices[71].Add(aplink246.Get(0));
	ap_device_sets[246].Add(aplink246.Get(1));

	ns3::NetDeviceContainer aplink247;
	aplink247 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], wifi_ap_nodes[247]));
	switch_devices[70].Add(aplink247.Get(0));
	ap_device_sets[247].Add(aplink247.Get(1));

	ns3::NetDeviceContainer aplink248;
	aplink248 = csma.Install(
			ns3::NodeContainer(csmaSwitches[77], wifi_ap_nodes[248]));
	switch_devices[77].Add(aplink248.Get(0));
	ap_device_sets[248].Add(aplink248.Get(1));

	ns3::NetDeviceContainer aplink249;
	aplink249 = csma.Install(
			ns3::NodeContainer(csmaSwitches[77], wifi_ap_nodes[249]));
	switch_devices[77].Add(aplink249.Get(0));
	ap_device_sets[249].Add(aplink249.Get(1));

	ns3::NetDeviceContainer aplink250;
	aplink250 = csma.Install(
			ns3::NodeContainer(csmaSwitches[78], wifi_ap_nodes[250]));
	switch_devices[78].Add(aplink250.Get(0));
	ap_device_sets[250].Add(aplink250.Get(1));

	ns3::NetDeviceContainer aplink251;
	aplink251 = csma.Install(
			ns3::NodeContainer(csmaSwitches[65], wifi_ap_nodes[251]));
	switch_devices[65].Add(aplink251.Get(0));
	ap_device_sets[251].Add(aplink251.Get(1));

	ns3::NetDeviceContainer aplink252;
	aplink252 = csma.Install(
			ns3::NodeContainer(csmaSwitches[66], wifi_ap_nodes[252]));
	switch_devices[66].Add(aplink252.Get(0));
	ap_device_sets[252].Add(aplink252.Get(1));

	ns3::NetDeviceContainer aplink253;
	aplink253 = csma.Install(
			ns3::NodeContainer(csmaSwitches[69], wifi_ap_nodes[253]));
	switch_devices[69].Add(aplink253.Get(0));
	ap_device_sets[253].Add(aplink253.Get(1));

	ns3::NetDeviceContainer aplink254;
	aplink254 = csma.Install(
			ns3::NodeContainer(csmaSwitches[69], wifi_ap_nodes[254]));
	switch_devices[69].Add(aplink254.Get(0));
	ap_device_sets[254].Add(aplink254.Get(1));

	ns3::NetDeviceContainer aplink255;
	aplink255 = csma.Install(
			ns3::NodeContainer(csmaSwitches[79], wifi_ap_nodes[255]));
	switch_devices[79].Add(aplink255.Get(0));
	ap_device_sets[255].Add(aplink255.Get(1));

	ns3::NetDeviceContainer aplink256;
	aplink256 = csma.Install(
			ns3::NodeContainer(csmaSwitches[79], wifi_ap_nodes[256]));
	switch_devices[79].Add(aplink256.Get(0));
	ap_device_sets[256].Add(aplink256.Get(1));

	ns3::NetDeviceContainer aplink257;
	aplink257 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], wifi_ap_nodes[257]));
	switch_devices[41].Add(aplink257.Get(0));
	ap_device_sets[257].Add(aplink257.Get(1));

	ns3::NetDeviceContainer aplink258;
	aplink258 = csma.Install(
			ns3::NodeContainer(csmaSwitches[45], wifi_ap_nodes[258]));
	switch_devices[45].Add(aplink258.Get(0));
	ap_device_sets[258].Add(aplink258.Get(1));

	ns3::NetDeviceContainer aplink259;
	aplink259 = csma.Install(
			ns3::NodeContainer(csmaSwitches[47], wifi_ap_nodes[259]));
	switch_devices[47].Add(aplink259.Get(0));
	ap_device_sets[259].Add(aplink259.Get(1));

	ns3::NetDeviceContainer aplink260;
	aplink260 = csma.Install(
			ns3::NodeContainer(csmaSwitches[42], wifi_ap_nodes[260]));
	switch_devices[42].Add(aplink260.Get(0));
	ap_device_sets[260].Add(aplink260.Get(1));

	ns3::NetDeviceContainer aplink261;
	aplink261 = csma.Install(
			ns3::NodeContainer(csmaSwitches[49], wifi_ap_nodes[261]));
	switch_devices[49].Add(aplink261.Get(0));
	ap_device_sets[261].Add(aplink261.Get(1));

	ns3::NetDeviceContainer aplink262;
	aplink262 = csma.Install(
			ns3::NodeContainer(csmaSwitches[49], wifi_ap_nodes[262]));
	switch_devices[49].Add(aplink262.Get(0));
	ap_device_sets[262].Add(aplink262.Get(1));

	ns3::NetDeviceContainer aplink263;
	aplink263 = csma.Install(
			ns3::NodeContainer(csmaSwitches[44], wifi_ap_nodes[263]));
	switch_devices[44].Add(aplink263.Get(0));
	ap_device_sets[263].Add(aplink263.Get(1));

	ns3::NetDeviceContainer aplink264;
	aplink264 = csma.Install(
			ns3::NodeContainer(csmaSwitches[344], wifi_ap_nodes[264]));
	switch_devices[344].Add(aplink264.Get(0));
	ap_device_sets[264].Add(aplink264.Get(1));

	ns3::NetDeviceContainer aplink265;
	aplink265 = csma.Install(
			ns3::NodeContainer(csmaSwitches[345], wifi_ap_nodes[265]));
	switch_devices[345].Add(aplink265.Get(0));
	ap_device_sets[265].Add(aplink265.Get(1));

	ns3::NetDeviceContainer aplink266;
	aplink266 = csma.Install(
			ns3::NodeContainer(csmaSwitches[345], wifi_ap_nodes[266]));
	switch_devices[345].Add(aplink266.Get(0));
	ap_device_sets[266].Add(aplink266.Get(1));

	ns3::NetDeviceContainer aplink267;
	aplink267 = csma.Install(
			ns3::NodeContainer(csmaSwitches[18], wifi_ap_nodes[267]));
	switch_devices[18].Add(aplink267.Get(0));
	ap_device_sets[267].Add(aplink267.Get(1));

	ns3::NetDeviceContainer aplink268;
	aplink268 = csma.Install(
			ns3::NodeContainer(csmaSwitches[18], wifi_ap_nodes[268]));
	switch_devices[18].Add(aplink268.Get(0));
	ap_device_sets[268].Add(aplink268.Get(1));

	ns3::NetDeviceContainer aplink269;
	aplink269 = csma.Install(
			ns3::NodeContainer(csmaSwitches[18], wifi_ap_nodes[269]));
	switch_devices[18].Add(aplink269.Get(0));
	ap_device_sets[269].Add(aplink269.Get(1));

	ns3::NetDeviceContainer aplink270;
	aplink270 = csma.Install(
			ns3::NodeContainer(csmaSwitches[19], wifi_ap_nodes[270]));
	switch_devices[19].Add(aplink270.Get(0));
	ap_device_sets[270].Add(aplink270.Get(1));

	ns3::NetDeviceContainer aplink271;
	aplink271 = csma.Install(
			ns3::NodeContainer(csmaSwitches[27], wifi_ap_nodes[271]));
	switch_devices[27].Add(aplink271.Get(0));
	ap_device_sets[271].Add(aplink271.Get(1));

	ns3::NetDeviceContainer aplink272;
	aplink272 = csma.Install(
			ns3::NodeContainer(csmaSwitches[346], wifi_ap_nodes[272]));
	switch_devices[346].Add(aplink272.Get(0));
	ap_device_sets[272].Add(aplink272.Get(1));

	ns3::NetDeviceContainer aplink273;
	aplink273 = csma.Install(
			ns3::NodeContainer(csmaSwitches[346], wifi_ap_nodes[273]));
	switch_devices[346].Add(aplink273.Get(0));
	ap_device_sets[273].Add(aplink273.Get(1));

	ns3::NetDeviceContainer aplink274;
	aplink274 = csma.Install(
			ns3::NodeContainer(csmaSwitches[79], wifi_ap_nodes[274]));
	switch_devices[79].Add(aplink274.Get(0));
	ap_device_sets[274].Add(aplink274.Get(1));

	ns3::NetDeviceContainer aplink275;
	aplink275 = csma.Install(
			ns3::NodeContainer(csmaSwitches[79], wifi_ap_nodes[275]));
	switch_devices[79].Add(aplink275.Get(0));
	ap_device_sets[275].Add(aplink275.Get(1));

	ns3::NetDeviceContainer aplink276;
	aplink276 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[276]));
	switch_devices[51].Add(aplink276.Get(0));
	ap_device_sets[276].Add(aplink276.Get(1));

	ns3::NetDeviceContainer aplink277;
	aplink277 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[277]));
	switch_devices[51].Add(aplink277.Get(0));
	ap_device_sets[277].Add(aplink277.Get(1));

	ns3::NetDeviceContainer aplink278;
	aplink278 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[278]));
	switch_devices[51].Add(aplink278.Get(0));
	ap_device_sets[278].Add(aplink278.Get(1));

	ns3::NetDeviceContainer aplink279;
	aplink279 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], wifi_ap_nodes[279]));
	switch_devices[51].Add(aplink279.Get(0));
	ap_device_sets[279].Add(aplink279.Get(1));

	ns3::NetDeviceContainer aplink280;
	aplink280 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[280]));
	switch_devices[114].Add(aplink280.Get(0));
	ap_device_sets[280].Add(aplink280.Get(1));

	ns3::NetDeviceContainer aplink281;
	aplink281 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[281]));
	switch_devices[114].Add(aplink281.Get(0));
	ap_device_sets[281].Add(aplink281.Get(1));

	ns3::NetDeviceContainer aplink282;
	aplink282 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[282]));
	switch_devices[114].Add(aplink282.Get(0));
	ap_device_sets[282].Add(aplink282.Get(1));

	ns3::NetDeviceContainer aplink283;
	aplink283 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[283]));
	switch_devices[114].Add(aplink283.Get(0));
	ap_device_sets[283].Add(aplink283.Get(1));

	ns3::NetDeviceContainer aplink284;
	aplink284 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[284]));
	switch_devices[114].Add(aplink284.Get(0));
	ap_device_sets[284].Add(aplink284.Get(1));

	ns3::NetDeviceContainer aplink285;
	aplink285 = csma.Install(
			ns3::NodeContainer(csmaSwitches[57], wifi_ap_nodes[285]));
	switch_devices[57].Add(aplink285.Get(0));
	ap_device_sets[285].Add(aplink285.Get(1));

	ns3::NetDeviceContainer aplink286;
	aplink286 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], wifi_ap_nodes[286]));
	switch_devices[59].Add(aplink286.Get(0));
	ap_device_sets[286].Add(aplink286.Get(1));

	ns3::NetDeviceContainer aplink287;
	aplink287 = csma.Install(
			ns3::NodeContainer(csmaSwitches[58], wifi_ap_nodes[287]));
	switch_devices[58].Add(aplink287.Get(0));
	ap_device_sets[287].Add(aplink287.Get(1));

	ns3::NetDeviceContainer aplink288;
	aplink288 = csma.Install(
			ns3::NodeContainer(csmaSwitches[58], wifi_ap_nodes[288]));
	switch_devices[58].Add(aplink288.Get(0));
	ap_device_sets[288].Add(aplink288.Get(1));

	ns3::NetDeviceContainer aplink289;
	aplink289 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[289]));
	switch_devices[114].Add(aplink289.Get(0));
	ap_device_sets[289].Add(aplink289.Get(1));

	ns3::NetDeviceContainer aplink290;
	aplink290 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[290]));
	switch_devices[114].Add(aplink290.Get(0));
	ap_device_sets[290].Add(aplink290.Get(1));

	ns3::NetDeviceContainer aplink291;
	aplink291 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[291]));
	switch_devices[114].Add(aplink291.Get(0));
	ap_device_sets[291].Add(aplink291.Get(1));

	ns3::NetDeviceContainer aplink292;
	aplink292 = csma.Install(
			ns3::NodeContainer(csmaSwitches[114], wifi_ap_nodes[292]));
	switch_devices[114].Add(aplink292.Get(0));
	ap_device_sets[292].Add(aplink292.Get(1));

	ns3::NetDeviceContainer aplink293;
	aplink293 = csma.Install(
			ns3::NodeContainer(csmaSwitches[347], wifi_ap_nodes[293]));
	switch_devices[347].Add(aplink293.Get(0));
	ap_device_sets[293].Add(aplink293.Get(1));

	ns3::NetDeviceContainer aplink294;
	aplink294 = csma.Install(
			ns3::NodeContainer(csmaSwitches[348], wifi_ap_nodes[294]));
	switch_devices[348].Add(aplink294.Get(0));
	ap_device_sets[294].Add(aplink294.Get(1));

	ns3::NetDeviceContainer aplink295;
	aplink295 = csma.Install(
			ns3::NodeContainer(csmaSwitches[65], wifi_ap_nodes[295]));
	switch_devices[65].Add(aplink295.Get(0));
	ap_device_sets[295].Add(aplink295.Get(1));

	ns3::NetDeviceContainer aplink296;
	aplink296 = csma.Install(
			ns3::NodeContainer(csmaSwitches[346], wifi_ap_nodes[296]));
	switch_devices[346].Add(aplink296.Get(0));
	ap_device_sets[296].Add(aplink296.Get(1));

	ns3::NetDeviceContainer aplink297;
	aplink297 = csma.Install(
			ns3::NodeContainer(csmaSwitches[346], wifi_ap_nodes[297]));
	switch_devices[346].Add(aplink297.Get(0));
	ap_device_sets[297].Add(aplink297.Get(1));

//    aplink298 = csma.Install(ns3::NodeContainer(csmaSwitches[10],wifi_ap_nodes[298]));
//    switch_devices[20].Add(aplink298.Get(0));
//    ap_device_sets[298].Add(aplink298.Get(1));
//
//    aplink299 = csma.Install(ns3::NodeContainer(csmaSwitches[11],wifi_ap_nodes[299]));
//    switch_devices[21].Add(aplink299.Get(0));
//    ap_device_sets[299].Add(aplink299.Get(1));
//
	ns3::NetDeviceContainer aplink300;
	aplink300 = csma.Install(
			ns3::NodeContainer(csmaSwitches[339], wifi_ap_nodes[300]));
	switch_devices[339].Add(aplink300.Get(0));
	ap_device_sets[300].Add(aplink300.Get(1));

	ns3::NetDeviceContainer aplink301;
	aplink301 = csma.Install(
			ns3::NodeContainer(csmaSwitches[338], wifi_ap_nodes[301]));
	switch_devices[338].Add(aplink301.Get(0));
	ap_device_sets[301].Add(aplink301.Get(1));

	ns3::NetDeviceContainer aplink302;
	aplink302 = csma.Install(
			ns3::NodeContainer(csmaSwitches[338], wifi_ap_nodes[302]));
	switch_devices[338].Add(aplink302.Get(0));
	ap_device_sets[302].Add(aplink302.Get(1));

	ns3::NetDeviceContainer aplink303;
	aplink303 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], wifi_ap_nodes[303]));
	switch_devices[335].Add(aplink303.Get(0));
	ap_device_sets[303].Add(aplink303.Get(1));

	ns3::NetDeviceContainer aplink304;
	aplink304 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], wifi_ap_nodes[304]));
	switch_devices[335].Add(aplink304.Get(0));
	ap_device_sets[304].Add(aplink304.Get(1));

	ns3::NetDeviceContainer aplink305;
	aplink305 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], wifi_ap_nodes[305]));
	switch_devices[335].Add(aplink305.Get(0));
	ap_device_sets[305].Add(aplink305.Get(1));

//    aplink306 = csma.Install(ns3::NodeContainer(csmaSwitches[335],wifi_ap_nodes[306]));
//    switch_devices[335].Add(aplink306.Get(0));
//    ap_device_sets[306].Add(aplink306.Get(1));

	ns3::NetDeviceContainer aplink307;
	aplink307 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], wifi_ap_nodes[307]));
	switch_devices[335].Add(aplink307.Get(0));
	ap_device_sets[307].Add(aplink307.Get(1));

	ns3::NetDeviceContainer aplink308;
	aplink308 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], wifi_ap_nodes[308]));
	switch_devices[335].Add(aplink308.Get(0));
	ap_device_sets[308].Add(aplink308.Get(1));

	ns3::NetDeviceContainer aplink309;
	aplink309 = csma.Install(
			ns3::NodeContainer(csmaSwitches[342], wifi_ap_nodes[309]));
	switch_devices[342].Add(aplink309.Get(0));
	ap_device_sets[309].Add(aplink309.Get(1));

	ns3::NetDeviceContainer aplink310;
	aplink310 = csma.Install(
			ns3::NodeContainer(csmaSwitches[338], wifi_ap_nodes[310]));
	switch_devices[338].Add(aplink310.Get(0));
	ap_device_sets[310].Add(aplink310.Get(1));

	ns3::NetDeviceContainer aplink311;
	aplink311 = csma.Install(
			ns3::NodeContainer(csmaSwitches[339], wifi_ap_nodes[311]));
	switch_devices[339].Add(aplink311.Get(0));
	ap_device_sets[311].Add(aplink311.Get(1));

	ns3::NetDeviceContainer aplink312;
	aplink312 = csma.Install(
			ns3::NodeContainer(csmaSwitches[339], wifi_ap_nodes[312]));
	switch_devices[339].Add(aplink312.Get(0));
	ap_device_sets[312].Add(aplink312.Get(1));

	ns3::NetDeviceContainer aplink314;
	aplink314 = csma.Install(
			ns3::NodeContainer(csmaSwitches[342], wifi_ap_nodes[314]));
	switch_devices[342].Add(aplink314.Get(0));
	ap_device_sets[314].Add(aplink314.Get(1));

//    aplink315 = csma.Install(ns3::NodeContainer(csmaSwitches[05],wifi_ap_nodes[315]));
//    switch_devices[05].Add(aplink315.Get(0));
//    ap_device_sets[315].Add(aplink315.Get(1));

//switch link
	ns3::NetDeviceContainer link11;
	link11 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[11]));
	switch_devices[9].Add(link11.Get(0));
	switch_devices[11].Add(link11.Get(1));

	ns3::NetDeviceContainer link14;
	link14 = csma.Install(
			ns3::NodeContainer(csmaSwitches[11], csmaSwitches[14]));
	switch_devices[11].Add(link14.Get(0));
	switch_devices[14].Add(link14.Get(1));

	ns3::NetDeviceContainer link15;
	link15 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[15]));
	switch_devices[9].Add(link15.Get(0));
	switch_devices[15].Add(link15.Get(1));

	ns3::NetDeviceContainer link17;
	link17 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[17]));
	switch_devices[9].Add(link17.Get(0));
	switch_devices[17].Add(link17.Get(1));

	ns3::NetDeviceContainer link18;
	link18 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[18]));
	switch_devices[9].Add(link18.Get(0));
	switch_devices[18].Add(link18.Get(1));

	ns3::NetDeviceContainer link19;
	link19 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[19]));
	switch_devices[9].Add(link19.Get(0));
	switch_devices[19].Add(link19.Get(1));

	ns3::NetDeviceContainer link20;
	link20 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[20]));
	switch_devices[9].Add(link20.Get(0));
	switch_devices[20].Add(link20.Get(1));

	ns3::NetDeviceContainer link21;
	link21 = csma.Install(
			ns3::NodeContainer(csmaSwitches[20], csmaSwitches[21]));
	switch_devices[20].Add(link21.Get(0));
	switch_devices[21].Add(link21.Get(1));

	ns3::NetDeviceContainer link25;
	link25 = csma.Install(
			ns3::NodeContainer(csmaSwitches[24], csmaSwitches[25]));
	switch_devices[24].Add(link25.Get(0));
	switch_devices[25].Add(link25.Get(1));

	ns3::NetDeviceContainer link29;
	link29 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[29]));
	switch_devices[9].Add(link29.Get(0));
	switch_devices[29].Add(link29.Get(1));

	ns3::NetDeviceContainer link30;
	link30 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[30]));
	switch_devices[9].Add(link30.Get(0));
	switch_devices[30].Add(link30.Get(1));

	ns3::NetDeviceContainer link33;
	link33 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[33]));
	switch_devices[9].Add(link33.Get(0));
	switch_devices[33].Add(link33.Get(1));

	ns3::NetDeviceContainer link34;
	link34 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[34]));
	switch_devices[9].Add(link34.Get(0));
	switch_devices[34].Add(link34.Get(1));

	ns3::NetDeviceContainer link35;
	link35 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[35]));
	switch_devices[9].Add(link35.Get(0));
	switch_devices[35].Add(link35.Get(1));

	ns3::NetDeviceContainer link37;
	link37 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[37]));
	switch_devices[9].Add(link37.Get(0));
	switch_devices[37].Add(link37.Get(1));

	ns3::NetDeviceContainer link38;
	link38 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[38]));
	switch_devices[9].Add(link38.Get(0));
	switch_devices[38].Add(link38.Get(1));

	ns3::NetDeviceContainer link39;
	link39 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[39]));
	switch_devices[9].Add(link39.Get(0));
	switch_devices[39].Add(link39.Get(1));

	ns3::NetDeviceContainer link50;
	link50 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[50]));
	switchDevices6506E.Add(link50.Get(0));
	switch_devices[50].Add(link50.Get(1));

	ns3::NetDeviceContainer link51;
	link51 = csma.Install(
			ns3::NodeContainer(csmaSwitches[50], csmaSwitches[51]));
	switch_devices[50].Add(link51.Get(0));
	switch_devices[51].Add(link51.Get(1));

	ns3::NetDeviceContainer link52;
	link52 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], csmaSwitches[52]));
	switch_devices[51].Add(link52.Get(0));
	switch_devices[52].Add(link52.Get(1));

	ns3::NetDeviceContainer link53;
	link53 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], csmaSwitches[53]));
	switch_devices[51].Add(link53.Get(0));
	switch_devices[53].Add(link53.Get(1));

	ns3::NetDeviceContainer link54;
	link54 = csma.Install(
			ns3::NodeContainer(csmaSwitches[53], csmaSwitches[54]));
	switch_devices[53].Add(link54.Get(0));
	switch_devices[54].Add(link54.Get(1));

	ns3::NetDeviceContainer link55;
	link55 = csma.Install(
			ns3::NodeContainer(csmaSwitches[51], csmaSwitches[55]));
	switch_devices[51].Add(link55.Get(0));
	switch_devices[55].Add(link55.Get(1));

	ns3::NetDeviceContainer link56;
	link56 = csma.Install(
			ns3::NodeContainer(csmaSwitches[55], csmaSwitches[56]));
	switch_devices[55].Add(link56.Get(0));
	switch_devices[56].Add(link56.Get(1));

	ns3::NetDeviceContainer link57;
	link57 = csma.Install(
			ns3::NodeContainer(csmaSwitches[50], csmaSwitches[57]));
	switch_devices[50].Add(link57.Get(0));
	switch_devices[57].Add(link57.Get(1));

	ns3::NetDeviceContainer link58;
	link58 = csma.Install(
			ns3::NodeContainer(csmaSwitches[50], csmaSwitches[58]));
	switch_devices[50].Add(link58.Get(0));
	switch_devices[58].Add(link58.Get(1));

	ns3::NetDeviceContainer link59;
	link59 = csma.Install(
			ns3::NodeContainer(csmaSwitches[50], csmaSwitches[59]));
	switch_devices[50].Add(link59.Get(0));
	switch_devices[59].Add(link59.Get(1));

	ns3::NetDeviceContainer link60;
	link60 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], csmaSwitches[60]));
	switch_devices[59].Add(link60.Get(0));
	switch_devices[60].Add(link60.Get(1));

	ns3::NetDeviceContainer link61;
	link61 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], csmaSwitches[61]));
	switch_devices[59].Add(link61.Get(0));
	switch_devices[61].Add(link61.Get(1));

	ns3::NetDeviceContainer link62;
	link62 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], csmaSwitches[62]));
	switch_devices[59].Add(link62.Get(0));
	switch_devices[62].Add(link62.Get(1));

	ns3::NetDeviceContainer link65;
	link65 = csma.Install(
			ns3::NodeContainer(csmaSwitches[64], csmaSwitches[65]));
	switch_devices[64].Add(link65.Get(0));
	switch_devices[65].Add(link65.Get(1));

	ns3::NetDeviceContainer link66;
	link66 = csma.Install(
			ns3::NodeContainer(csmaSwitches[64], csmaSwitches[66]));
	switch_devices[64].Add(link66.Get(0));
	switch_devices[66].Add(link66.Get(1));

	ns3::NetDeviceContainer link68;
	link68 = csma.Install(
			ns3::NodeContainer(csmaSwitches[64], csmaSwitches[68]));
	switch_devices[64].Add(link68.Get(0));
	switch_devices[68].Add(link68.Get(1));

	ns3::NetDeviceContainer link69;
	link69 = csma.Install(
			ns3::NodeContainer(csmaSwitches[64], csmaSwitches[69]));
	switch_devices[64].Add(link69.Get(0));
	switch_devices[69].Add(link69.Get(1));

	ns3::NetDeviceContainer link71;
	link71 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], csmaSwitches[71]));
	switch_devices[70].Add(link71.Get(0));
	switch_devices[71].Add(link71.Get(1));

	ns3::NetDeviceContainer link72;
	link72 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], csmaSwitches[72]));
	switch_devices[70].Add(link72.Get(0));
	switch_devices[72].Add(link72.Get(1));

	ns3::NetDeviceContainer link73;
	link73 = csma.Install(
			ns3::NodeContainer(csmaSwitches[72], csmaSwitches[73]));
	switch_devices[72].Add(link73.Get(0));
	switch_devices[73].Add(link73.Get(1));

	ns3::NetDeviceContainer link74;
	link74 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], csmaSwitches[74]));
	switch_devices[70].Add(link74.Get(0));
	switch_devices[74].Add(link74.Get(1));

	ns3::NetDeviceContainer link75;
	link75 = csma.Install(
			ns3::NodeContainer(csmaSwitches[74], csmaSwitches[75]));
	switch_devices[74].Add(link75.Get(0));
	switch_devices[75].Add(link75.Get(1));

	ns3::NetDeviceContainer link76;
	link76 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], csmaSwitches[76]));
	switch_devices[70].Add(link76.Get(0));
	switch_devices[76].Add(link76.Get(1));

	ns3::NetDeviceContainer link77;
	link77 = csma.Install(
			ns3::NodeContainer(csmaSwitches[76], csmaSwitches[77]));
	switch_devices[76].Add(link77.Get(0));
	switch_devices[77].Add(link77.Get(1));

	ns3::NetDeviceContainer link78;
	link78 = csma.Install(
			ns3::NodeContainer(csmaSwitches[70], csmaSwitches[78]));
	switch_devices[70].Add(link78.Get(0));
	switch_devices[78].Add(link78.Get(1));

	ns3::NetDeviceContainer link79;
	link79 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[79]));
	switchDevices6506E.Add(link79.Get(0));
	switch_devices[79].Add(link79.Get(1));

	ns3::NetDeviceContainer link81;
	link81 = csma.Install(
			ns3::NodeContainer(csmaSwitches[80], csmaSwitches[81]));
	switch_devices[80].Add(link81.Get(0));
	switch_devices[81].Add(link81.Get(1));

	ns3::NetDeviceContainer link82;
	link82 = csma.Install(
			ns3::NodeContainer(csmaSwitches[81], csmaSwitches[82]));
	switch_devices[81].Add(link82.Get(0));
	switch_devices[82].Add(link82.Get(1));

	ns3::NetDeviceContainer link84;
	link84 = csma.Install(
			ns3::NodeContainer(csmaSwitches[81], csmaSwitches[84]));
	switch_devices[81].Add(link84.Get(0));
	switch_devices[84].Add(link84.Get(1));

	ns3::NetDeviceContainer link85;
	link85 = csma.Install(
			ns3::NodeContainer(csmaSwitches[80], csmaSwitches[85]));
	switch_devices[80].Add(link85.Get(0));
	switch_devices[85].Add(link85.Get(1));

	ns3::NetDeviceContainer link99;
	link99 = csma.Install(
			ns3::NodeContainer(csmaSwitches[80], csmaSwitches[99]));
	switch_devices[80].Add(link99.Get(0));
	switch_devices[99].Add(link99.Get(1));

	ns3::NetDeviceContainer link114;
	link114 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[114]));
	switchDevices6506E.Add(link114.Get(0));
	switch_devices[114].Add(link114.Get(1));

	ns3::NetDeviceContainer link115;
	link115 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[115]));
	switchDevices6506E.Add(link115.Get(0));
	switch_devices[115].Add(link115.Get(1));

	ns3::NetDeviceContainer link116;
	link116 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[116]));
	switchDevices6506E.Add(link116.Get(0));
	switch_devices[116].Add(link116.Get(1));

	ns3::NetDeviceContainer link123;
	link123 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[123]));
	switchDevices6506E.Add(link123.Get(0));
	switch_devices[123].Add(link123.Get(1));

	ns3::NetDeviceContainer link127;
	link127 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[127]));
	switch_devices[126].Add(link127.Get(0));
	switch_devices[127].Add(link127.Get(1));

	ns3::NetDeviceContainer link128;
	link128 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[128]));
	switch_devices[126].Add(link128.Get(0));
	switch_devices[128].Add(link128.Get(1));

	ns3::NetDeviceContainer link129;
	link129 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[129]));
	switch_devices[126].Add(link129.Get(0));
	switch_devices[129].Add(link129.Get(1));

	ns3::NetDeviceContainer link130;
	link130 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[130]));
	switch_devices[126].Add(link130.Get(0));
	switch_devices[130].Add(link130.Get(1));

	ns3::NetDeviceContainer link131;
	link131 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[131]));
	switch_devices[126].Add(link131.Get(0));
	switch_devices[131].Add(link131.Get(1));

	ns3::NetDeviceContainer link132;
	link132 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[132]));
	switch_devices[126].Add(link132.Get(0));
	switch_devices[132].Add(link132.Get(1));

	ns3::NetDeviceContainer link133;
	link133 = csma.Install(
			ns3::NodeContainer(csmaSwitches[132], csmaSwitches[133]));
	switch_devices[132].Add(link133.Get(0));
	switch_devices[133].Add(link133.Get(1));

	ns3::NetDeviceContainer link134;
	link134 = csma.Install(
			ns3::NodeContainer(csmaSwitches[132], csmaSwitches[134]));
	switch_devices[132].Add(link134.Get(0));
	switch_devices[134].Add(link134.Get(1));

	ns3::NetDeviceContainer link135;
	link135 = csma.Install(
			ns3::NodeContainer(csmaSwitches[132], csmaSwitches[135]));
	switch_devices[132].Add(link135.Get(0));
	switch_devices[135].Add(link135.Get(1));

	ns3::NetDeviceContainer link136;
	link136 = csma.Install(
			ns3::NodeContainer(csmaSwitches[132], csmaSwitches[136]));
	switch_devices[132].Add(link136.Get(0));
	switch_devices[136].Add(link136.Get(1));

	ns3::NetDeviceContainer link137;
	link137 = csma.Install(
			ns3::NodeContainer(csmaSwitches[126], csmaSwitches[137]));
	switch_devices[126].Add(link137.Get(0));
	switch_devices[137].Add(link137.Get(1));

	ns3::NetDeviceContainer link142;
	link142 = csma.Install(
			ns3::NodeContainer(csmaSwitches[141], csmaSwitches[142]));
	switch_devices[141].Add(link142.Get(0));
	switch_devices[142].Add(link142.Get(1));

	ns3::NetDeviceContainer link143;
	link143 = csma.Install(
			ns3::NodeContainer(csmaSwitches[141], csmaSwitches[143]));
	switch_devices[141].Add(link143.Get(0));
	switch_devices[143].Add(link143.Get(1));

	ns3::NetDeviceContainer link144;
	link144 = csma.Install(
			ns3::NodeContainer(csmaSwitches[141], csmaSwitches[144]));
	switch_devices[141].Add(link144.Get(0));
	switch_devices[144].Add(link144.Get(1));

	ns3::NetDeviceContainer link145;
	link145 = csma.Install(
			ns3::NodeContainer(csmaSwitches[141], csmaSwitches[145]));
	switch_devices[141].Add(link145.Get(0));
	switch_devices[145].Add(link145.Get(1));

	ns3::NetDeviceContainer link146;
	link146 = csma.Install(
			ns3::NodeContainer(csmaSwitches[142], csmaSwitches[146]));
	switch_devices[142].Add(link146.Get(0));
	switch_devices[146].Add(link146.Get(1));

	ns3::NetDeviceContainer link149;
	link149 = csma.Install(
			ns3::NodeContainer(csmaSwitches[143], csmaSwitches[149]));
	switch_devices[143].Add(link149.Get(0));
	switch_devices[149].Add(link149.Get(1));

	ns3::NetDeviceContainer link150;
	link150 = csma.Install(
			ns3::NodeContainer(csmaSwitches[145], csmaSwitches[150]));
	switch_devices[145].Add(link150.Get(0));
	switch_devices[150].Add(link150.Get(1));

	ns3::NetDeviceContainer link151;
	link151 = csma.Install(
			ns3::NodeContainer(csmaSwitches[150], csmaSwitches[151]));
	switch_devices[150].Add(link151.Get(0));
	switch_devices[151].Add(link151.Get(1));

	ns3::NetDeviceContainer link154;
	link154 = csma.Install(
			ns3::NodeContainer(csmaSwitches[150], csmaSwitches[154]));
	switch_devices[150].Add(link154.Get(0));
	switch_devices[154].Add(link154.Get(1));

	ns3::NetDeviceContainer link158;
	link158 = csma.Install(
			ns3::NodeContainer(csmaSwitches[145], csmaSwitches[158]));
	switch_devices[145].Add(link158.Get(0));
	switch_devices[158].Add(link158.Get(1));

	ns3::NetDeviceContainer link165;
	link165 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[165]));
	switch_devices[161].Add(link165.Get(0));
	switch_devices[165].Add(link165.Get(1));

	ns3::NetDeviceContainer link167;
	link167 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[167]));
	switch_devices[161].Add(link167.Get(0));
	switch_devices[167].Add(link167.Get(1));

	ns3::NetDeviceContainer link172;
	link172 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[172]));
	switch_devices[167].Add(link172.Get(0));
	switch_devices[172].Add(link172.Get(1));

	ns3::NetDeviceContainer link178;
	link178 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[178]));
	switch_devices[161].Add(link178.Get(0));
	switch_devices[178].Add(link178.Get(1));

	ns3::NetDeviceContainer link180;
	link180 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[180]));
	switch_devices[161].Add(link180.Get(0));
	switch_devices[180].Add(link180.Get(1));

	ns3::NetDeviceContainer link181;
	link181 = csma.Install(
			ns3::NodeContainer(csmaSwitches[180], csmaSwitches[181]));
	switch_devices[180].Add(link181.Get(0));
	switch_devices[181].Add(link181.Get(1));

	ns3::NetDeviceContainer link183;
	link183 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[183]));
	switch_devices[161].Add(link183.Get(0));
	switch_devices[183].Add(link183.Get(1));

	ns3::NetDeviceContainer link193;
	link193 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[193]));
	switchDevices6506E.Add(link193.Get(0));
	switch_devices[193].Add(link193.Get(1));

	ns3::NetDeviceContainer link200;
	link200 = csma.Install(
			ns3::NodeContainer(csmaSwitch6506E, csmaSwitches[200]));
	switchDevices6506E.Add(link200.Get(0));
	switch_devices[200].Add(link200.Get(1));

	ns3::NetDeviceContainer link201;
	link201 = csma.Install(
			ns3::NodeContainer(csmaSwitches[200], csmaSwitches[201]));
	switch_devices[200].Add(link201.Get(0));
	switch_devices[201].Add(link201.Get(1));

	ns3::NetDeviceContainer link202;
	link202 = csma.Install(
			ns3::NodeContainer(csmaSwitches[201], csmaSwitches[202]));
	switch_devices[201].Add(link202.Get(0));
	switch_devices[202].Add(link202.Get(1));

	ns3::NetDeviceContainer link203;
	link203 = csma.Install(
			ns3::NodeContainer(csmaSwitches[201], csmaSwitches[203]));
	switch_devices[201].Add(link203.Get(0));
	switch_devices[203].Add(link203.Get(1));

	ns3::NetDeviceContainer link204;
	link204 = csma.Install(
			ns3::NodeContainer(csmaSwitches[201], csmaSwitches[204]));
	switch_devices[201].Add(link204.Get(0));
	switch_devices[204].Add(link204.Get(1));

	ns3::NetDeviceContainer link206;
	link206 = csma.Install(
			ns3::NodeContainer(csmaSwitches[200], csmaSwitches[206]));
	switch_devices[200].Add(link206.Get(0));
	switch_devices[206].Add(link206.Get(1));

	ns3::NetDeviceContainer link208;
	link208 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], csmaSwitches[208]));
	switch_devices[206].Add(link208.Get(0));
	switch_devices[208].Add(link208.Get(1));

	ns3::NetDeviceContainer link209;
	link209 = csma.Install(
			ns3::NodeContainer(csmaSwitches[208], csmaSwitches[209]));
	switch_devices[208].Add(link209.Get(0));
	switch_devices[209].Add(link209.Get(1));

	ns3::NetDeviceContainer link210;
	link210 = csma.Install(
			ns3::NodeContainer(csmaSwitches[208], csmaSwitches[210]));
	switch_devices[208].Add(link210.Get(0));
	switch_devices[210].Add(link210.Get(1));

	ns3::NetDeviceContainer link211;
	link211 = csma.Install(
			ns3::NodeContainer(csmaSwitches[208], csmaSwitches[211]));
	switch_devices[208].Add(link211.Get(0));
	switch_devices[211].Add(link211.Get(1));

	ns3::NetDeviceContainer link214;
	link214 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[214]));
	switchDevicessigenobu.Add(link214.Get(0));
	switch_devices[214].Add(link214.Get(1));

	ns3::NetDeviceContainer link215;
	link215 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[215]));
	switchDevicessigenobu.Add(link215.Get(0));
	switch_devices[215].Add(link215.Get(1));

	ns3::NetDeviceContainer link217;
	link217 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[217]));
	switchDevicessigenobu.Add(link217.Get(0));
	switch_devices[217].Add(link217.Get(1));

	ns3::NetDeviceContainer link220;
	link220 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[220]));
	switchDevicessigenobu.Add(link220.Get(0));
	switch_devices[220].Add(link220.Get(1));

	ns3::NetDeviceContainer link227;
	link227 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[227]));
	switch_devices[226].Add(link227.Get(0));
	switch_devices[227].Add(link227.Get(1));

	ns3::NetDeviceContainer link228;
	link228 = csma.Install(
			ns3::NodeContainer(csmaSwitches[227], csmaSwitches[228]));
	switch_devices[227].Add(link228.Get(0));
	switch_devices[228].Add(link228.Get(1));

	ns3::NetDeviceContainer link229;
	link229 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[229]));
	switch_devices[226].Add(link229.Get(0));
	switch_devices[229].Add(link229.Get(1));

	ns3::NetDeviceContainer link230;
	link230 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[230]));
	switch_devices[226].Add(link230.Get(0));
	switch_devices[230].Add(link230.Get(1));

	ns3::NetDeviceContainer link231;
	link231 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[231]));
	switch_devices[230].Add(link231.Get(0));
	switch_devices[231].Add(link231.Get(1));

	ns3::NetDeviceContainer link248;
	link248 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[248]));
	switch_devices[230].Add(link248.Get(0));
	switch_devices[248].Add(link248.Get(1));

	ns3::NetDeviceContainer link256;
	link256 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[256]));
	switch_devices[226].Add(link256.Get(0));
	switch_devices[256].Add(link256.Get(1));

	ns3::NetDeviceContainer link257;
	link257 = csma.Install(
			ns3::NodeContainer(csmaSwitches[256], csmaSwitches[257]));
	switch_devices[256].Add(link257.Get(0));
	switch_devices[257].Add(link257.Get(1));

	ns3::NetDeviceContainer link258;
	link258 = csma.Install(
			ns3::NodeContainer(csmaSwitches[256], csmaSwitches[258]));
	switch_devices[256].Add(link258.Get(0));
	switch_devices[258].Add(link258.Get(1));

	ns3::NetDeviceContainer link259;
	link259 = csma.Install(
			ns3::NodeContainer(csmaSwitches[256], csmaSwitches[259]));
	switch_devices[256].Add(link259.Get(0));
	switch_devices[259].Add(link259.Get(1));

	ns3::NetDeviceContainer link260;
	link260 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[260]));
	switch_devices[226].Add(link260.Get(0));
	switch_devices[260].Add(link260.Get(1));

	ns3::NetDeviceContainer link264;
	link264 = csma.Install(
			ns3::NodeContainer(csmaSwitchsigenobu, csmaSwitches[264]));
	switchDevicessigenobu.Add(link264.Get(0));
	switch_devices[264].Add(link264.Get(1));

	ns3::NetDeviceContainer link287;
	link287 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[287]));
	switchDevicestarumi.Add(link287.Get(0));
	switch_devices[287].Add(link287.Get(1));

	ns3::NetDeviceContainer link288;
	link288 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[288]));
	switchDevicestarumi.Add(link288.Get(0));
	switch_devices[288].Add(link288.Get(1));

	ns3::NetDeviceContainer link290;
	link290 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[290]));
	switchDevicestarumi.Add(link290.Get(0));
	switch_devices[290].Add(link290.Get(1));

	ns3::NetDeviceContainer link291;
	link291 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[291]));
	switchDevicestarumi.Add(link291.Get(0));
	switch_devices[291].Add(link291.Get(1));

	ns3::NetDeviceContainer link294;
	link294 = csma.Install(
			ns3::NodeContainer(csmaSwitches[291], csmaSwitches[294]));
	switch_devices[291].Add(link294.Get(0));
	switch_devices[294].Add(link294.Get(1));

	ns3::NetDeviceContainer link295;
	link295 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[295]));
	switchDevicestarumi.Add(link295.Get(0));
	switch_devices[295].Add(link295.Get(1));

	ns3::NetDeviceContainer link296;
	link296 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[296]));
	switch_devices[295].Add(link296.Get(0));
	switch_devices[296].Add(link296.Get(1));

	ns3::NetDeviceContainer link300;
	link300 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[300]));
	switch_devices[295].Add(link300.Get(0));
	switch_devices[300].Add(link300.Get(1));

	ns3::NetDeviceContainer link301;
	link301 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[301]));
	switch_devices[295].Add(link301.Get(0));
	switch_devices[301].Add(link301.Get(1));

	ns3::NetDeviceContainer link304;
	link304 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[304]));
	switchDevicestarumi.Add(link304.Get(0));
	switch_devices[304].Add(link304.Get(1));

	ns3::NetDeviceContainer link305;
	link305 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[305]));
	switch_devices[304].Add(link305.Get(0));
	switch_devices[305].Add(link305.Get(1));

	ns3::NetDeviceContainer link306;
	link306 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[306]));
	switch_devices[304].Add(link306.Get(0));
	switch_devices[306].Add(link306.Get(1));

	ns3::NetDeviceContainer link308;
	link308 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[308]));
	switch_devices[304].Add(link308.Get(0));
	switch_devices[308].Add(link308.Get(1));

	ns3::NetDeviceContainer link309;
	link309 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[309]));
	switch_devices[304].Add(link309.Get(0));
	switch_devices[309].Add(link309.Get(1));

	ns3::NetDeviceContainer link310;
	link310 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[310]));
	switch_devices[304].Add(link310.Get(0));
	switch_devices[310].Add(link310.Get(1));

	ns3::NetDeviceContainer link311;
	link311 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[311]));
	switchDevicestarumi.Add(link311.Get(0));
	switch_devices[311].Add(link311.Get(1));

	ns3::NetDeviceContainer link312;
	link312 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[312]));
	switchDevicestarumi.Add(link312.Get(0));
	switch_devices[312].Add(link312.Get(1));

	ns3::NetDeviceContainer link313;
	link313 = csma.Install(
			ns3::NodeContainer(csmaSwitches[312], csmaSwitches[313]));
	switch_devices[312].Add(link313.Get(0));
	switch_devices[313].Add(link313.Get(1));

	ns3::NetDeviceContainer link314;
	link314 = csma.Install(
			ns3::NodeContainer(csmaSwitches[312], csmaSwitches[314]));
	switch_devices[312].Add(link314.Get(0));
	switch_devices[314].Add(link314.Get(1));

	ns3::NetDeviceContainer link317;
	link317 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[317]));
	switch_devices[316].Add(link317.Get(0));
	switch_devices[317].Add(link317.Get(1));

	ns3::NetDeviceContainer link318;
	link318 = csma.Install(
			ns3::NodeContainer(csmaSwitches[317], csmaSwitches[318]));
	switch_devices[317].Add(link318.Get(0));
	switch_devices[318].Add(link318.Get(1));

	ns3::NetDeviceContainer link319;
	link319 = csma.Install(
			ns3::NodeContainer(csmaSwitches[317], csmaSwitches[319]));
	switch_devices[317].Add(link319.Get(0));
	switch_devices[319].Add(link319.Get(1));

	ns3::NetDeviceContainer link320;
	link320 = csma.Install(
			ns3::NodeContainer(csmaSwitches[317], csmaSwitches[320]));
	switch_devices[317].Add(link320.Get(0));
	switch_devices[320].Add(link320.Get(1));

	ns3::NetDeviceContainer link322;
	link322 = csma.Install(
			ns3::NodeContainer(csmaSwitches[321], csmaSwitches[322]));
	switch_devices[321].Add(link322.Get(0));
	switch_devices[322].Add(link322.Get(1));

	ns3::NetDeviceContainer link323;
	link323 = csma.Install(
			ns3::NodeContainer(csmaSwitches[321], csmaSwitches[323]));
	switch_devices[321].Add(link323.Get(0));
	switch_devices[323].Add(link323.Get(1));

	ns3::NetDeviceContainer link324;
	link324 = csma.Install(
			ns3::NodeContainer(csmaSwitches[321], csmaSwitches[324]));
	switch_devices[321].Add(link324.Get(0));
	switch_devices[324].Add(link324.Get(1));

	ns3::NetDeviceContainer link325;
	link325 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[325]));
	switch_devices[316].Add(link325.Get(0));
	switch_devices[325].Add(link325.Get(1));

	ns3::NetDeviceContainer link327;
	link327 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[327]));
	switch_devices[316].Add(link327.Get(0));
	switch_devices[327].Add(link327.Get(1));

	ns3::NetDeviceContainer link328;
	link328 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[328]));
	switch_devices[316].Add(link328.Get(0));
	switch_devices[328].Add(link328.Get(1));

	ns3::NetDeviceContainer link331;
	link331 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[331]));
	switch_devices[316].Add(link331.Get(0));
	switch_devices[331].Add(link331.Get(1));

	ns3::NetDeviceContainer link332;
	link332 = csma.Install(
			ns3::NodeContainer(csmaSwitches[331], csmaSwitches[332]));
	switch_devices[331].Add(link332.Get(0));
	switch_devices[332].Add(link332.Get(1));

	ns3::NetDeviceContainer link343;
	link343 = csma.Install(
			ns3::NodeContainer(csmaSwitches[197], csmaSwitches[343]));
	switch_devices[197].Add(link343.Get(0));
	switch_devices[343].Add(link343.Get(1));

	ns3::NetDeviceContainer link344;
	link344 = csma.Install(
			ns3::NodeContainer(csmaSwitches[45], csmaSwitches[344]));
	switch_devices[45].Add(link344.Get(0));
	switch_devices[344].Add(link344.Get(1));

	ns3::NetDeviceContainer link345;
	link345 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[345]));
	switch_devices[41].Add(link345.Get(0));
	switch_devices[345].Add(link345.Get(1));

	ns3::NetDeviceContainer link346;
	link346 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[346]));
	switch_devices[41].Add(link346.Get(0));
	switch_devices[346].Add(link346.Get(1));

	ns3::NetDeviceContainer link347;
	link347 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], csmaSwitches[347]));
	switch_devices[206].Add(link347.Get(0));
	switch_devices[347].Add(link347.Get(1));

	ns3::NetDeviceContainer link348;
	link348 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], csmaSwitches[348]));
	switch_devices[206].Add(link348.Get(0));
	switch_devices[348].Add(link348.Get(1));

//#channel define
	csma = ns3::CsmaHelper();
	csma.SetChannelAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate(1000000000)));
	csma.SetChannelAttribute("Delay", ns3::TimeValue(ns3::MilliSeconds(2)));

	ns3::NetDeviceContainer link10;
	link10 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[10]));
	switch_devices[9].Add(link10.Get(0));
	switch_devices[10].Add(link10.Get(1));

	ns3::NetDeviceContainer link12;
	link12 = csma.Install(
			ns3::NodeContainer(csmaSwitches[11], csmaSwitches[12]));
	switch_devices[11].Add(link12.Get(0));
	switch_devices[12].Add(link12.Get(1));

	ns3::NetDeviceContainer link13;
	link13 = csma.Install(
			ns3::NodeContainer(csmaSwitches[11], csmaSwitches[13]));
	switch_devices[11].Add(link13.Get(0));
	switch_devices[13].Add(link13.Get(1));

	ns3::NetDeviceContainer link16;
	link16 = csma.Install(
			ns3::NodeContainer(csmaSwitches[15], csmaSwitches[16]));
	switch_devices[15].Add(link16.Get(0));
	switch_devices[16].Add(link16.Get(1));

	ns3::NetDeviceContainer link22;
	link22 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[22]));
	switch_devices[9].Add(link22.Get(0));
	switch_devices[22].Add(link22.Get(1));

	ns3::NetDeviceContainer link23;
	link23 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[23]));
	switch_devices[9].Add(link23.Get(0));
	switch_devices[23].Add(link23.Get(1));

	ns3::NetDeviceContainer link24;
	link24 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[24]));
	switch_devices[9].Add(link24.Get(0));
	switch_devices[24].Add(link24.Get(1));

	ns3::NetDeviceContainer link26;
	link26 = csma.Install(
			ns3::NodeContainer(csmaSwitches[24], csmaSwitches[26]));
	switch_devices[24].Add(link26.Get(0));
	switch_devices[26].Add(link26.Get(1));

	ns3::NetDeviceContainer link27;
	link27 = csma.Install(
			ns3::NodeContainer(csmaSwitches[24], csmaSwitches[27]));
	switch_devices[24].Add(link27.Get(0));
	switch_devices[27].Add(link27.Get(1));

	ns3::NetDeviceContainer link28;
	link28 = csma.Install(
			ns3::NodeContainer(csmaSwitches[24], csmaSwitches[28]));
	switch_devices[24].Add(link28.Get(0));
	switch_devices[28].Add(link28.Get(1));

	ns3::NetDeviceContainer link31;
	link31 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[31]));
	switch_devices[9].Add(link31.Get(0));
	switch_devices[31].Add(link31.Get(1));

	ns3::NetDeviceContainer link32;
	link32 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[32]));
	switch_devices[9].Add(link32.Get(0));
	switch_devices[32].Add(link32.Get(1));

	ns3::NetDeviceContainer link36;
	link36 = csma.Install(
			ns3::NodeContainer(csmaSwitches[9], csmaSwitches[36]));
	switch_devices[9].Add(link36.Get(0));
	switch_devices[36].Add(link36.Get(1));

	ns3::NetDeviceContainer link41;
	link41 = csma.Install(
			ns3::NodeContainer(csmaSwitches[40], csmaSwitches[41]));
	switch_devices[40].Add(link41.Get(0));
	switch_devices[41].Add(link41.Get(1));

	ns3::NetDeviceContainer link42;
	link42 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[42]));
	switch_devices[41].Add(link42.Get(0));
	switch_devices[42].Add(link42.Get(1));

	ns3::NetDeviceContainer link43;
	link43 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[43]));
	switch_devices[41].Add(link43.Get(0));
	switch_devices[43].Add(link43.Get(1));

	ns3::NetDeviceContainer link44;
	link44 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[44]));
	switch_devices[41].Add(link44.Get(0));
	switch_devices[44].Add(link44.Get(1));

	ns3::NetDeviceContainer link45;
	link45 = csma.Install(
			ns3::NodeContainer(csmaSwitches[41], csmaSwitches[45]));
	switch_devices[41].Add(link45.Get(0));
	switch_devices[45].Add(link45.Get(1));

	ns3::NetDeviceContainer link46;
	link46 = csma.Install(
			ns3::NodeContainer(csmaSwitches[45], csmaSwitches[46]));
	switch_devices[45].Add(link46.Get(0));
	switch_devices[46].Add(link46.Get(1));

	ns3::NetDeviceContainer link47;
	link47 = csma.Install(
			ns3::NodeContainer(csmaSwitches[46], csmaSwitches[47]));
	switch_devices[46].Add(link47.Get(0));
	switch_devices[47].Add(link47.Get(1));

	ns3::NetDeviceContainer link48;
	link48 = csma.Install(
			ns3::NodeContainer(csmaSwitches[45], csmaSwitches[48]));
	switch_devices[45].Add(link48.Get(0));
	switch_devices[48].Add(link48.Get(1));

	ns3::NetDeviceContainer link49;
	link49 = csma.Install(
			ns3::NodeContainer(csmaSwitches[45], csmaSwitches[49]));
	switch_devices[45].Add(link49.Get(0));
	switch_devices[49].Add(link49.Get(1));

	ns3::NetDeviceContainer link63;
	link63 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], csmaSwitches[63]));
	switch_devices[59].Add(link63.Get(0));
	switch_devices[63].Add(link63.Get(1));

	ns3::NetDeviceContainer link64;
	link64 = csma.Install(
			ns3::NodeContainer(csmaSwitches[59], csmaSwitches[64]));
	switch_devices[59].Add(link64.Get(0));
	switch_devices[64].Add(link64.Get(1));

	ns3::NetDeviceContainer link67;
	link67 = csma.Install(
			ns3::NodeContainer(csmaSwitches[66], csmaSwitches[67]));
	switch_devices[66].Add(link67.Get(0));
	switch_devices[67].Add(link67.Get(1));

	ns3::NetDeviceContainer link83;
	link83 = csma.Install(
			ns3::NodeContainer(csmaSwitches[81], csmaSwitches[83]));
	switch_devices[81].Add(link83.Get(0));
	switch_devices[83].Add(link83.Get(1));

	ns3::NetDeviceContainer link86;
	link86 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], csmaSwitches[86]));
	switch_devices[85].Add(link86.Get(0));
	switch_devices[86].Add(link86.Get(1));

	ns3::NetDeviceContainer link87;
	link87 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], csmaSwitches[87]));
	switch_devices[85].Add(link87.Get(0));
	switch_devices[87].Add(link87.Get(1));

	ns3::NetDeviceContainer link88;
	link88 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], csmaSwitches[88]));
	switch_devices[85].Add(link88.Get(0));
	switch_devices[88].Add(link88.Get(1));

	ns3::NetDeviceContainer link89;
	link89 = csma.Install(
			ns3::NodeContainer(csmaSwitches[85], csmaSwitches[89]));
	switch_devices[85].Add(link89.Get(0));
	switch_devices[89].Add(link89.Get(1));

	ns3::NetDeviceContainer link90;
	link90 = csma.Install(
			ns3::NodeContainer(csmaSwitches[89], csmaSwitches[90]));
	switch_devices[89].Add(link90.Get(0));
	switch_devices[90].Add(link90.Get(1));

	ns3::NetDeviceContainer link91;
	link91 = csma.Install(
			ns3::NodeContainer(csmaSwitches[80], csmaSwitches[91]));
	switch_devices[80].Add(link91.Get(0));
	switch_devices[91].Add(link91.Get(1));

	ns3::NetDeviceContainer link92;
	link92 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[92]));
	switch_devices[91].Add(link92.Get(0));
	switch_devices[92].Add(link92.Get(1));

	ns3::NetDeviceContainer link93;
	link93 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[93]));
	switch_devices[91].Add(link93.Get(0));
	switch_devices[93].Add(link93.Get(1));

	ns3::NetDeviceContainer link94;
	link94 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[94]));
	switch_devices[91].Add(link94.Get(0));
	switch_devices[94].Add(link94.Get(1));

	ns3::NetDeviceContainer link95;
	link95 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[95]));
	switch_devices[91].Add(link95.Get(0));
	switch_devices[95].Add(link95.Get(1));

	ns3::NetDeviceContainer link96;
	link96 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[96]));
	switch_devices[91].Add(link96.Get(0));
	switch_devices[96].Add(link96.Get(1));

	ns3::NetDeviceContainer link97;
	link97 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[97]));
	switch_devices[91].Add(link97.Get(0));
	switch_devices[97].Add(link97.Get(1));

	ns3::NetDeviceContainer link98;
	link98 = csma.Install(
			ns3::NodeContainer(csmaSwitches[91], csmaSwitches[98]));
	switch_devices[91].Add(link98.Get(0));
	switch_devices[98].Add(link98.Get(1));

	ns3::NetDeviceContainer link100;
	link100 = csma.Install(
			ns3::NodeContainer(csmaSwitches[99], csmaSwitches[100]));
	switch_devices[99].Add(link100.Get(0));
	switch_devices[100].Add(link100.Get(1));

	ns3::NetDeviceContainer link101;
	link101 = csma.Install(
			ns3::NodeContainer(csmaSwitches[100], csmaSwitches[101]));
	switch_devices[100].Add(link101.Get(0));
	switch_devices[101].Add(link101.Get(1));

	ns3::NetDeviceContainer link102;
	link102 = csma.Install(
			ns3::NodeContainer(csmaSwitches[100], csmaSwitches[102]));
	switch_devices[100].Add(link102.Get(0));
	switch_devices[102].Add(link102.Get(1));

	ns3::NetDeviceContainer link103;
	link103 = csma.Install(
			ns3::NodeContainer(csmaSwitches[100], csmaSwitches[103]));
	switch_devices[100].Add(link103.Get(0));
	switch_devices[103].Add(link103.Get(1));

	ns3::NetDeviceContainer link104;
	link104 = csma.Install(
			ns3::NodeContainer(csmaSwitches[100], csmaSwitches[104]));
	switch_devices[100].Add(link104.Get(0));
	switch_devices[104].Add(link104.Get(1));

	ns3::NetDeviceContainer link105;
	link105 = csma.Install(
			ns3::NodeContainer(ns3::NodeContainer(csmaSwitches[100].Get(0)),
					ns3::NodeContainer(csmaSwitches[105].Get(0))));
	switch_devices[100].Add(link105.Get(0));
	switch_devices[105].Add(link105.Get(1));

	ns3::NetDeviceContainer link106;
	link106 = csma.Install(
			ns3::NodeContainer(ns3::NodeContainer(csmaSwitches[100].Get(0)),
					ns3::NodeContainer(csmaSwitches[106].Get(0))));
	switch_devices[100].Add(link106.Get(0));
	switch_devices[106].Add(link106.Get(1));

	ns3::NetDeviceContainer link107;
	link107 = csma.Install(
			ns3::NodeContainer(ns3::NodeContainer(csmaSwitches[99].Get(0)),
					ns3::NodeContainer(csmaSwitches[107].Get(0))));
	switch_devices[99].Add(link107.Get(0));
	switch_devices[107].Add(link107.Get(1));

	ns3::NetDeviceContainer link108;
	link108 = csma.Install(
			ns3::NodeContainer(ns3::NodeContainer(csmaSwitches[107].Get(0)),
					ns3::NodeContainer(csmaSwitches[108].Get(0))));
	switch_devices[107].Add(link108.Get(0));
	switch_devices[108].Add(link108.Get(1));

	ns3::NetDeviceContainer link109;
	link109 = csma.Install(
			ns3::NodeContainer(ns3::NodeContainer(csmaSwitches[107].Get(0)),
					ns3::NodeContainer(csmaSwitches[109].Get(0))));
	switch_devices[107].Add(link109.Get(0));
	switch_devices[109].Add(link109.Get(1));

	ns3::NetDeviceContainer link110;
	link110 = csma.Install(
			ns3::NodeContainer(csmaSwitches[107], csmaSwitches[110]));
	switch_devices[107].Add(link110.Get(0));
	switch_devices[110].Add(link110.Get(1));

	ns3::NetDeviceContainer link111;
	link111 = csma.Install(
			ns3::NodeContainer(csmaSwitches[107], csmaSwitches[111]));
	switch_devices[107].Add(link111.Get(0));
	switch_devices[111].Add(link111.Get(1));

	ns3::NetDeviceContainer link112;
	link112 = csma.Install(
			ns3::NodeContainer(csmaSwitches[99], csmaSwitches[112]));
	switch_devices[99].Add(link112.Get(0));
	switch_devices[112].Add(link112.Get(1));

	ns3::NetDeviceContainer link117;
	link117 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[117]));
	switch_devices[116].Add(link117.Get(0));
	switch_devices[117].Add(link117.Get(1));

	ns3::NetDeviceContainer link118;
	link118 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[118]));
	switch_devices[116].Add(link118.Get(0));
	switch_devices[118].Add(link118.Get(1));

	ns3::NetDeviceContainer link119;
	link119 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[119]));
	switch_devices[116].Add(link119.Get(0));
	switch_devices[119].Add(link119.Get(1));

	ns3::NetDeviceContainer link120;
	link120 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[120]));
	switch_devices[116].Add(link120.Get(0));
	switch_devices[120].Add(link120.Get(1));

	ns3::NetDeviceContainer link121;
	link121 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[121]));
	switch_devices[116].Add(link121.Get(0));
	switch_devices[121].Add(link121.Get(1));

	ns3::NetDeviceContainer link122;
	link122 = csma.Install(
			ns3::NodeContainer(csmaSwitches[116], csmaSwitches[122]));
	switch_devices[116].Add(link122.Get(0));
	switch_devices[122].Add(link122.Get(1));

	ns3::NetDeviceContainer link124;
	link124 = csma.Install(
			ns3::NodeContainer(csmaSwitches[123], csmaSwitches[124]));
	switch_devices[123].Add(link124.Get(0));
	switch_devices[124].Add(link124.Get(1));

	ns3::NetDeviceContainer link125;
	link125 = csma.Install(
			ns3::NodeContainer(csmaSwitches[123], csmaSwitches[125]));
	switch_devices[123].Add(link125.Get(0));
	switch_devices[125].Add(link125.Get(1));

	ns3::NetDeviceContainer link138;
	link138 = csma.Install(
			ns3::NodeContainer(csmaSwitches[137], csmaSwitches[138]));
	switch_devices[137].Add(link138.Get(0));
	switch_devices[138].Add(link138.Get(1));

	ns3::NetDeviceContainer link139;
	link139 = csma.Install(
			ns3::NodeContainer(csmaSwitches[137], csmaSwitches[139]));
	switch_devices[137].Add(link139.Get(0));
	switch_devices[139].Add(link139.Get(1));

	ns3::NetDeviceContainer link140;
	link140 = csma.Install(
			ns3::NodeContainer(csmaSwitches[137], csmaSwitches[140]));
	switch_devices[137].Add(link140.Get(0));
	switch_devices[140].Add(link140.Get(1));

	ns3::NetDeviceContainer link147;
	link147 = csma.Install(
			ns3::NodeContainer(csmaSwitches[146], csmaSwitches[147]));
	switch_devices[146].Add(link147.Get(0));
	switch_devices[147].Add(link147.Get(1));

	ns3::NetDeviceContainer link148;
	link148 = csma.Install(
			ns3::NodeContainer(csmaSwitches[146], csmaSwitches[148]));
	switch_devices[146].Add(link148.Get(0));
	switch_devices[148].Add(link148.Get(1));

	ns3::NetDeviceContainer link152;
	link152 = csma.Install(
			ns3::NodeContainer(csmaSwitches[151], csmaSwitches[152]));
	switch_devices[151].Add(link152.Get(0));
	switch_devices[152].Add(link152.Get(1));

	ns3::NetDeviceContainer link153;
	link153 = csma.Install(
			ns3::NodeContainer(csmaSwitches[151], csmaSwitches[153]));
	switch_devices[151].Add(link153.Get(0));
	switch_devices[153].Add(link153.Get(1));

	ns3::NetDeviceContainer link155;
	link155 = csma.Install(
			ns3::NodeContainer(csmaSwitches[154], csmaSwitches[155]));
	switch_devices[154].Add(link155.Get(0));
	switch_devices[155].Add(link155.Get(1));

	ns3::NetDeviceContainer link156;
	link156 = csma.Install(
			ns3::NodeContainer(csmaSwitches[154], csmaSwitches[156]));
	switch_devices[154].Add(link156.Get(0));
	switch_devices[156].Add(link156.Get(1));

	ns3::NetDeviceContainer link157;
	link157 = csma.Install(
			ns3::NodeContainer(csmaSwitches[154], csmaSwitches[157]));
	switch_devices[154].Add(link157.Get(0));
	switch_devices[157].Add(link157.Get(1));

	ns3::NetDeviceContainer link159;
	link159 = csma.Install(
			ns3::NodeContainer(csmaSwitches[158], csmaSwitches[159]));
	switch_devices[158].Add(link159.Get(0));
	switch_devices[159].Add(link159.Get(1));

	ns3::NetDeviceContainer link162;
	link162 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[162]));
	switch_devices[161].Add(link162.Get(0));
	switch_devices[162].Add(link162.Get(1));

	ns3::NetDeviceContainer link163;
	link163 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[163]));
	switch_devices[161].Add(link163.Get(0));
	switch_devices[163].Add(link163.Get(1));

	ns3::NetDeviceContainer link164;
	link164 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[164]));
	switch_devices[161].Add(link164.Get(0));
	switch_devices[164].Add(link164.Get(1));

	ns3::NetDeviceContainer link166;
	link166 = csma.Install(
			ns3::NodeContainer(csmaSwitches[161], csmaSwitches[166]));
	switch_devices[161].Add(link166.Get(0));
	switch_devices[166].Add(link166.Get(1));

	ns3::NetDeviceContainer link168;
	link168 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[168]));
	switch_devices[167].Add(link168.Get(0));
	switch_devices[168].Add(link168.Get(1));

	ns3::NetDeviceContainer link169;
	link169 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[169]));
	switch_devices[167].Add(link169.Get(0));
	switch_devices[169].Add(link169.Get(1));

	ns3::NetDeviceContainer link170;
	link170 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[170]));
	switch_devices[167].Add(link170.Get(0));
	switch_devices[170].Add(link170.Get(1));

	ns3::NetDeviceContainer link171;
	link171 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[171]));
	switch_devices[167].Add(link171.Get(0));
	switch_devices[171].Add(link171.Get(1));

	ns3::NetDeviceContainer link173;
	link173 = csma.Install(
			ns3::NodeContainer(csmaSwitches[172], csmaSwitches[173]));
	switch_devices[172].Add(link173.Get(0));
	switch_devices[173].Add(link173.Get(1));

	ns3::NetDeviceContainer link174;
	link174 = csma.Install(
			ns3::NodeContainer(csmaSwitches[172], csmaSwitches[174]));
	switch_devices[172].Add(link174.Get(0));
	switch_devices[174].Add(link174.Get(1));

	ns3::NetDeviceContainer link175;
	link175 = csma.Install(
			ns3::NodeContainer(csmaSwitches[174], csmaSwitches[175]));
	switch_devices[174].Add(link175.Get(0));
	switch_devices[175].Add(link175.Get(1));

	ns3::NetDeviceContainer link176;
	link176 = csma.Install(
			ns3::NodeContainer(csmaSwitches[167], csmaSwitches[176]));
	switch_devices[167].Add(link176.Get(0));
	switch_devices[176].Add(link176.Get(1));

	ns3::NetDeviceContainer link177;
	link177 = csma.Install(
			ns3::NodeContainer(csmaSwitches[176], csmaSwitches[177]));
	switch_devices[176].Add(link177.Get(0));
	switch_devices[177].Add(link177.Get(1));

	ns3::NetDeviceContainer link179;
	link179 = csma.Install(
			ns3::NodeContainer(csmaSwitches[178], csmaSwitches[179]));
	switch_devices[178].Add(link179.Get(0));
	switch_devices[179].Add(link179.Get(1));

	ns3::NetDeviceContainer link182;
	link182 = csma.Install(
			ns3::NodeContainer(csmaSwitches[181], csmaSwitches[182]));
	switch_devices[181].Add(link182.Get(0));
	switch_devices[182].Add(link182.Get(1));

	ns3::NetDeviceContainer link184;
	link184 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[184]));
	switch_devices[183].Add(link184.Get(0));
	switch_devices[184].Add(link184.Get(1));

	ns3::NetDeviceContainer link185;
	link185 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[185]));
	switch_devices[183].Add(link185.Get(0));
	switch_devices[185].Add(link185.Get(1));

	ns3::NetDeviceContainer link186;
	link186 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[186]));
	switch_devices[183].Add(link186.Get(0));
	switch_devices[186].Add(link186.Get(1));

	ns3::NetDeviceContainer link187;
	link187 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[187]));
	switch_devices[183].Add(link187.Get(0));
	switch_devices[187].Add(link187.Get(1));

	ns3::NetDeviceContainer link188;
	link188 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[188]));
	switch_devices[183].Add(link188.Get(0));
	switch_devices[188].Add(link188.Get(1));

	ns3::NetDeviceContainer link189;
	link189 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[189]));
	switch_devices[183].Add(link189.Get(0));
	switch_devices[189].Add(link189.Get(1));

	ns3::NetDeviceContainer link190;
	link190 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[190]));
	switch_devices[183].Add(link190.Get(0));
	switch_devices[190].Add(link190.Get(1));

	ns3::NetDeviceContainer link191;
	link191 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[191]));
	switch_devices[183].Add(link191.Get(0));
	switch_devices[191].Add(link191.Get(1));

	ns3::NetDeviceContainer link192;
	link192 = csma.Install(
			ns3::NodeContainer(csmaSwitches[183], csmaSwitches[192]));
	switch_devices[183].Add(link192.Get(0));
	switch_devices[192].Add(link192.Get(1));

	ns3::NetDeviceContainer link194;
	link194 = csma.Install(
			ns3::NodeContainer(csmaSwitches[193], csmaSwitches[194]));
	switch_devices[193].Add(link194.Get(0));
	switch_devices[194].Add(link194.Get(1));

	ns3::NetDeviceContainer link195;
	link195 = csma.Install(
			ns3::NodeContainer(csmaSwitches[193], csmaSwitches[195]));
	switch_devices[193].Add(link195.Get(0));
	switch_devices[195].Add(link195.Get(1));

	ns3::NetDeviceContainer link196;
	link196 = csma.Install(
			ns3::NodeContainer(csmaSwitches[193], csmaSwitches[196]));
	switch_devices[193].Add(link196.Get(0));
	switch_devices[196].Add(link196.Get(1));

	ns3::NetDeviceContainer link198;
	link198 = csma.Install(
			ns3::NodeContainer(csmaSwitches[197], csmaSwitches[198]));
	switch_devices[197].Add(link198.Get(0));
	switch_devices[198].Add(link198.Get(1));

	ns3::NetDeviceContainer link199;
	link199 = csma.Install(
			ns3::NodeContainer(csmaSwitches[197], csmaSwitches[199]));
	switch_devices[197].Add(link199.Get(0));
	switch_devices[199].Add(link199.Get(1));

	ns3::NetDeviceContainer link205;
	link205 = csma.Install(
			ns3::NodeContainer(csmaSwitches[200], csmaSwitches[205]));
	switch_devices[200].Add(link205.Get(0));
	switch_devices[205].Add(link205.Get(1));

	ns3::NetDeviceContainer link207;
	link207 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], csmaSwitches[207]));
	switch_devices[206].Add(link207.Get(0));
	switch_devices[207].Add(link207.Get(1));

	ns3::NetDeviceContainer link212;
	link212 = csma.Install(
			ns3::NodeContainer(csmaSwitches[206], csmaSwitches[212]));
	switch_devices[206].Add(link212.Get(0));
	switch_devices[212].Add(link212.Get(1));

	ns3::NetDeviceContainer link216;
	link216 = csma.Install(
			ns3::NodeContainer(csmaSwitches[215], csmaSwitches[216]));
	switch_devices[215].Add(link216.Get(0));
	switch_devices[216].Add(link216.Get(1));

	ns3::NetDeviceContainer link218;
	link218 = csma.Install(
			ns3::NodeContainer(csmaSwitches[217], csmaSwitches[218]));
	switch_devices[217].Add(link218.Get(0));
	switch_devices[218].Add(link218.Get(1));

	ns3::NetDeviceContainer link219;
	link219 = csma.Install(
			ns3::NodeContainer(csmaSwitches[217], csmaSwitches[219]));
	switch_devices[217].Add(link219.Get(0));
	switch_devices[219].Add(link219.Get(1));

	ns3::NetDeviceContainer link221;
	link221 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], csmaSwitches[221]));
	switch_devices[220].Add(link221.Get(0));
	switch_devices[221].Add(link221.Get(1));

	ns3::NetDeviceContainer link222;
	link222 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], csmaSwitches[222]));
	switch_devices[220].Add(link222.Get(0));
	switch_devices[222].Add(link222.Get(1));

	ns3::NetDeviceContainer link223;
	link223 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], csmaSwitches[223]));
	switch_devices[220].Add(link223.Get(0));
	switch_devices[223].Add(link223.Get(1));

	ns3::NetDeviceContainer link224;
	link224 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], csmaSwitches[224]));
	switch_devices[220].Add(link224.Get(0));
	switch_devices[224].Add(link224.Get(1));

	ns3::NetDeviceContainer link225;
	link225 = csma.Install(
			ns3::NodeContainer(csmaSwitches[220], csmaSwitches[225]));
	switch_devices[220].Add(link225.Get(0));
	switch_devices[225].Add(link225.Get(1));

	ns3::NetDeviceContainer link232;
	link232 = csma.Install(
			ns3::NodeContainer(csmaSwitches[231], csmaSwitches[232]));
	switch_devices[231].Add(link232.Get(0));
	switch_devices[232].Add(link232.Get(1));

	ns3::NetDeviceContainer link233;
	link233 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[233]));
	switch_devices[230].Add(link233.Get(0));
	switch_devices[233].Add(link233.Get(1));

	ns3::NetDeviceContainer link234;
	link234 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[234]));
	switch_devices[230].Add(link234.Get(0));
	switch_devices[234].Add(link234.Get(1));

	ns3::NetDeviceContainer link235;
	link235 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[235]));
	switch_devices[230].Add(link235.Get(0));
	switch_devices[235].Add(link235.Get(1));

	ns3::NetDeviceContainer link236;
	link236 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[236]));
	switch_devices[230].Add(link236.Get(0));
	switch_devices[236].Add(link236.Get(1));

	ns3::NetDeviceContainer link237;
	link237 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[237]));
	switch_devices[230].Add(link237.Get(0));
	switch_devices[237].Add(link237.Get(1));

	ns3::NetDeviceContainer link238;
	link238 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[238]));
	switch_devices[230].Add(link238.Get(0));
	switch_devices[238].Add(link238.Get(1));

	ns3::NetDeviceContainer link239;
	link239 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[239]));
	switch_devices[230].Add(link239.Get(0));
	switch_devices[239].Add(link239.Get(1));

	ns3::NetDeviceContainer link240;
	link240 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[240]));
	switch_devices[230].Add(link240.Get(0));
	switch_devices[240].Add(link240.Get(1));

	ns3::NetDeviceContainer link241;
	link241 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[241]));
	switch_devices[230].Add(link241.Get(0));
	switch_devices[241].Add(link241.Get(1));

	ns3::NetDeviceContainer link242;
	link242 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[242]));
	switch_devices[230].Add(link242.Get(0));
	switch_devices[242].Add(link242.Get(1));

	ns3::NetDeviceContainer link243;
	link243 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[243]));
	switch_devices[230].Add(link243.Get(0));
	switch_devices[243].Add(link243.Get(1));

	ns3::NetDeviceContainer link244;
	link244 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[244]));
	switch_devices[230].Add(link244.Get(0));
	switch_devices[244].Add(link244.Get(1));

	ns3::NetDeviceContainer link245;
	link245 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[245]));
	switch_devices[230].Add(link245.Get(0));
	switch_devices[245].Add(link245.Get(1));

	ns3::NetDeviceContainer link246;
	link246 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[246]));
	switch_devices[230].Add(link246.Get(0));
	switch_devices[246].Add(link246.Get(1));

	ns3::NetDeviceContainer link247;
	link247 = csma.Install(
			ns3::NodeContainer(csmaSwitches[230], csmaSwitches[247]));
	switch_devices[230].Add(link247.Get(0));
	switch_devices[247].Add(link247.Get(1));

	ns3::NetDeviceContainer link284;
	link284 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[284]));
	switch_devices[248].Add(link284.Get(0));
	switch_devices[284].Add(link284.Get(1));

	ns3::NetDeviceContainer link249;
	link249 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[249]));
	switch_devices[248].Add(link249.Get(0));
	switch_devices[249].Add(link249.Get(1));

	ns3::NetDeviceContainer link250;
	link250 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[250]));
	switch_devices[248].Add(link250.Get(0));
	switch_devices[250].Add(link250.Get(1));

	ns3::NetDeviceContainer link251;
	link251 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[251]));
	switch_devices[248].Add(link251.Get(0));
	switch_devices[251].Add(link251.Get(1));

	ns3::NetDeviceContainer link252;
	link252 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[252]));
	switch_devices[248].Add(link252.Get(0));
	switch_devices[252].Add(link252.Get(1));

	ns3::NetDeviceContainer link253;
	link253 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[253]));
	switch_devices[248].Add(link253.Get(0));
	switch_devices[253].Add(link253.Get(1));

	ns3::NetDeviceContainer link254;
	link254 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[254]));
	switch_devices[248].Add(link254.Get(0));
	switch_devices[254].Add(link254.Get(1));

	ns3::NetDeviceContainer link255;
	link255 = csma.Install(
			ns3::NodeContainer(csmaSwitches[248], csmaSwitches[255]));
	switch_devices[248].Add(link255.Get(0));
	switch_devices[255].Add(link255.Get(1));

	ns3::NetDeviceContainer link261;
	link261 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[261]));
	switch_devices[226].Add(link261.Get(0));
	switch_devices[261].Add(link261.Get(1));

	ns3::NetDeviceContainer link262;
	link262 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[262]));
	switch_devices[226].Add(link262.Get(0));
	switch_devices[262].Add(link262.Get(1));

	ns3::NetDeviceContainer link263;
	link263 = csma.Install(
			ns3::NodeContainer(csmaSwitches[226], csmaSwitches[263]));
	switch_devices[226].Add(link263.Get(0));
	switch_devices[263].Add(link263.Get(1));

	ns3::NetDeviceContainer link265;
	link265 = csma.Install(
			ns3::NodeContainer(csmaSwitches[264], csmaSwitches[265]));
	switch_devices[264].Add(link265.Get(0));
	switch_devices[265].Add(link265.Get(1));

	ns3::NetDeviceContainer link267;
	link267 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[267]));
	switch_devices[266].Add(link267.Get(0));
	switch_devices[267].Add(link267.Get(1));

	ns3::NetDeviceContainer link268;
	link268 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[268]));
	switch_devices[266].Add(link268.Get(0));
	switch_devices[268].Add(link268.Get(1));

	ns3::NetDeviceContainer link269;
	link269 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[269]));
	switch_devices[266].Add(link269.Get(0));
	switch_devices[269].Add(link269.Get(1));

	ns3::NetDeviceContainer link270;
	link270 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[270]));
	switch_devices[266].Add(link270.Get(0));
	switch_devices[270].Add(link270.Get(1));

	ns3::NetDeviceContainer link272;
	link272 = csma.Install(
			ns3::NodeContainer(csmaSwitches[270], csmaSwitches[272]));
	switch_devices[270].Add(link272.Get(0));
	switch_devices[272].Add(link272.Get(1));

	ns3::NetDeviceContainer link273;
	link273 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[273]));
	switch_devices[266].Add(link273.Get(0));
	switch_devices[273].Add(link273.Get(1));

	ns3::NetDeviceContainer link274;
	link274 = csma.Install(
			ns3::NodeContainer(csmaSwitches[266], csmaSwitches[274]));
	switch_devices[266].Add(link274.Get(0));
	switch_devices[274].Add(link274.Get(1));

	ns3::NetDeviceContainer link277;
	link277 = csma.Install(
			ns3::NodeContainer(csmaSwitches[276], csmaSwitches[277]));
	switch_devices[276].Add(link277.Get(0));
	switch_devices[277].Add(link277.Get(1));

	ns3::NetDeviceContainer link278;
	link278 = csma.Install(
			ns3::NodeContainer(csmaSwitches[276], csmaSwitches[278]));
	switch_devices[276].Add(link278.Get(0));
	switch_devices[278].Add(link278.Get(1));

	ns3::NetDeviceContainer link279;
	link279 = csma.Install(
			ns3::NodeContainer(csmaSwitches[278], csmaSwitches[279]));
	switch_devices[278].Add(link279.Get(0));
	switch_devices[279].Add(link279.Get(1));

	ns3::NetDeviceContainer link280;
	link280 = csma.Install(
			ns3::NodeContainer(csmaSwitches[276], csmaSwitches[280]));
	switch_devices[276].Add(link280.Get(0));
	switch_devices[280].Add(link280.Get(1));

	ns3::NetDeviceContainer link281;
	link281 = csma.Install(
			ns3::NodeContainer(csmaSwitches[280], csmaSwitches[281]));
	switch_devices[280].Add(link281.Get(0));
	switch_devices[281].Add(link281.Get(1));

	ns3::NetDeviceContainer link282;
	link282 = csma.Install(
			ns3::NodeContainer(csmaSwitches[276], csmaSwitches[282]));
	switch_devices[276].Add(link282.Get(0));
	switch_devices[282].Add(link282.Get(1));

	ns3::NetDeviceContainer link286;
	link286 = csma.Install(
			ns3::NodeContainer(csmaSwitchtarumi, csmaSwitches[286]));
	switchDevicestarumi.Add(link286.Get(0));
	switch_devices[286].Add(link286.Get(1));

	ns3::NetDeviceContainer link289;
	link289 = csma.Install(
			ns3::NodeContainer(csmaSwitches[288], csmaSwitches[289]));
	switch_devices[288].Add(link289.Get(0));
	switch_devices[289].Add(link289.Get(1));

	ns3::NetDeviceContainer link292;
	link292 = csma.Install(
			ns3::NodeContainer(csmaSwitches[291], csmaSwitches[292]));
	switch_devices[291].Add(link292.Get(0));
	switch_devices[292].Add(link292.Get(1));

	ns3::NetDeviceContainer link293;
	link293 = csma.Install(
			ns3::NodeContainer(csmaSwitches[291], csmaSwitches[293]));
	switch_devices[291].Add(link293.Get(0));
	switch_devices[293].Add(link293.Get(1));

	ns3::NetDeviceContainer link297;
	link297 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[297]));
	switch_devices[295].Add(link297.Get(0));
	switch_devices[297].Add(link297.Get(1));

	ns3::NetDeviceContainer link298;
	link298 = csma.Install(
			ns3::NodeContainer(csmaSwitches[297], csmaSwitches[298]));
	switch_devices[297].Add(link298.Get(0));
	switch_devices[298].Add(link298.Get(1));

	ns3::NetDeviceContainer link299;
	link299 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[299]));
	switch_devices[295].Add(link299.Get(0));
	switch_devices[299].Add(link299.Get(1));

	ns3::NetDeviceContainer link302;
	link302 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[302]));
	switch_devices[295].Add(link302.Get(0));
	switch_devices[302].Add(link302.Get(1));

	ns3::NetDeviceContainer link303;
	link303 = csma.Install(
			ns3::NodeContainer(csmaSwitches[295], csmaSwitches[303]));
	switch_devices[295].Add(link303.Get(0));
	switch_devices[303].Add(link303.Get(1));

	ns3::NetDeviceContainer link307;
	link307 = csma.Install(
			ns3::NodeContainer(csmaSwitches[304], csmaSwitches[307]));
	switch_devices[304].Add(link307.Get(0));
	switch_devices[307].Add(link307.Get(1));

	ns3::NetDeviceContainer link315;
	link315 = csma.Install(
			ns3::NodeContainer(csmaSwitches[312], csmaSwitches[315]));
	switch_devices[312].Add(link315.Get(0));
	switch_devices[315].Add(link315.Get(1));

	ns3::NetDeviceContainer link321;
	link321 = csma.Install(
			ns3::NodeContainer(csmaSwitches[317], csmaSwitches[321]));
	switch_devices[317].Add(link321.Get(0));
	switch_devices[321].Add(link321.Get(1));

	ns3::NetDeviceContainer link326;
	link326 = csma.Install(
			ns3::NodeContainer(csmaSwitches[316], csmaSwitches[326]));
	switch_devices[316].Add(link326.Get(0));
	switch_devices[326].Add(link326.Get(1));

	ns3::NetDeviceContainer link329;
	link329 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], csmaSwitches[329]));
	switch_devices[328].Add(link329.Get(0));
	switch_devices[329].Add(link329.Get(1));

	ns3::NetDeviceContainer link330;
	link330 = csma.Install(
			ns3::NodeContainer(csmaSwitches[328], csmaSwitches[330]));
	switch_devices[328].Add(link330.Get(0));
	switch_devices[330].Add(link330.Get(1));

	ns3::NetDeviceContainer link336;
	link336 = csma.Install(
			ns3::NodeContainer(csmaSwitches[335], csmaSwitches[336]));
	switch_devices[335].Add(link336.Get(0));
	switch_devices[336].Add(link336.Get(1));

	ns3::NetDeviceContainer link337;
	link337 = csma.Install(
			ns3::NodeContainer(csmaSwitches[336], csmaSwitches[337]));
	switch_devices[336].Add(link337.Get(0));
	switch_devices[337].Add(link337.Get(1));

	ns3::NetDeviceContainer link338;
	link338 = csma.Install(
			ns3::NodeContainer(csmaSwitches[336], csmaSwitches[338]));
	switch_devices[336].Add(link338.Get(0));
	switch_devices[338].Add(link338.Get(1));

	ns3::NetDeviceContainer link339;
	link339 = csma.Install(
			ns3::NodeContainer(csmaSwitches[336], csmaSwitches[339]));
	switch_devices[336].Add(link339.Get(0));
	switch_devices[339].Add(link339.Get(1));

	ns3::NetDeviceContainer link340;
	link340 = csma.Install(
			ns3::NodeContainer(csmaSwitches[336], csmaSwitches[340]));
	switch_devices[336].Add(link340.Get(0));
	switch_devices[340].Add(link340.Get(1));

	ns3::NetDeviceContainer link341;
	link341 = csma.Install(
			ns3::NodeContainer(csmaSwitches[340], csmaSwitches[341]));
	switch_devices[340].Add(link341.Get(0));
	switch_devices[341].Add(link341.Get(1));

	ns3::NetDeviceContainer link342;
	link342 = csma.Install(
			ns3::NodeContainer(csmaSwitches[336], csmaSwitches[342]));
	switch_devices[336].Add(link342.Get(0));
	switch_devices[342].Add(link342.Get(1));

// switch create

	ns3::Ptr<ns3::Node> switchNoderouter = csmaSwitchrouter.Get(0);
	ns3::Ptr<ns3::BridgeNetDevice> bridgeDevicerouter = ns3::CreateObject<
			ns3::BridgeNetDevice>();
	switchNoderouter->AddDevice(bridgeDevicerouter);

	for (unsigned int portIter; portIter < switchDevicesrouter.GetN();
			++portIter) {
		bridgeDevicerouter->AddBridgePort(switchDevicesrouter.Get(portIter));
	}

	ns3::Ptr<ns3::Node> switchNode6506E = csmaSwitch6506E.Get(0);
	ns3::Ptr<ns3::BridgeNetDevice> bridgeDevice6506E = ns3::CreateObject<
			ns3::BridgeNetDevice>();
	switchNode6506E->AddDevice(bridgeDevice6506E);

	for (unsigned int portIter; portIter < switchDevices6506E.GetN();
			++portIter) {
		bridgeDevice6506E->AddBridgePort(switchDevices6506E.Get(portIter));
	}

	for (int i = 5; i <= 348; ++i) {
		if (i == 271)
			continue;
		ns3::Ptr<ns3::Node> p_node = csmaSwitches[i].Get(0);
		ns3::Ptr<ns3::BridgeNetDevice> p_bridge_net_device = ns3::CreateObject<
				ns3::BridgeNetDevice>();
		p_node->AddDevice(p_bridge_net_device);

		for (unsigned int portIter; portIter < switch_devices[i].GetN();
				++portIter) {
			p_bridge_net_device->AddBridgePort(switch_devices[i].Get(portIter));
		}
	}
	ns3::Ptr<ns3::Node> switchNodesigenobu = csmaSwitchsigenobu.Get(0);
	ns3::Ptr<ns3::BridgeNetDevice> bridgeDevicesigenobu = ns3::CreateObject<
			ns3::BridgeNetDevice>();
	switchNodesigenobu->AddDevice(bridgeDevicesigenobu);

	for (unsigned int portIter; portIter < switchDevicessigenobu.GetN();
			++portIter) {
		bridgeDevicesigenobu->AddBridgePort(
				switchDevicessigenobu.Get(portIter));
	}
	ns3::Ptr<ns3::Node> switchNodetarumi = csmaSwitchtarumi.Get(0);
	ns3::Ptr<ns3::BridgeNetDevice> bridgeDevicetarumi = ns3::CreateObject<
			ns3::BridgeNetDevice>();
	switchNodetarumi->AddDevice(bridgeDevicetarumi);

	for (unsigned int portIter; portIter < switchDevicestarumi.GetN();
			++portIter) {
		bridgeDevicetarumi->AddBridgePort(switchDevicestarumi.Get(portIter));
	}

//apDevices switchDevices setuzoku
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		ns3::Ptr<ns3::Node> p_node = wifi_ap_nodes[i].Get(0);
		ns3::Ptr<ns3::BridgeNetDevice> p_bridge_net_device = ns3::CreateObject<
				ns3::BridgeNetDevice>();
		p_node->AddDevice(p_bridge_net_device);

		for (unsigned int portIter = 0; portIter < ap_device_sets[i].GetN();
				++portIter) {
			p_bridge_net_device->AddBridgePort(ap_device_sets[i].Get(portIter));
		}

		for (unsigned int portIter = 0; portIter < apDeviceSets[i].GetN();
				++portIter) {
			p_bridge_net_device->AddBridgePort(apDeviceSets[i].Get(portIter));
		}
	}	//for

// Add internet stack to the terminals
	ns3::InternetStackHelper internet;
	internet.Install(internetrouter.Get(0));

	internet.Install(csmaSwitchrouter.Get(0));
	internet.Install(csmaSwitch6506E.Get(0));
	for (int i = 5; i <= 348; ++i) {
		internet.Install(csmaSwitches[i].Get(0));
	}
	internet.Install(csmaSwitchsigenobu.Get(0));

	for (int i = 5; i <= 348; ++i) {
		internet.Install(terminal_sets[i]);
	}

	for (int i = 1; i <= 287; ++i) {
		internet.Install(wifi_ap_nodes[i]);
	}

	for (int i = 300; i <= 305; ++i) {
		internet.Install(wifi_ap_nodes[i]);
	}

	for (int i = 307; i <= 314; ++i) {
		internet.Install(wifi_ap_nodes[i]);
	}

	for (int i = 1; i <= 299; ++i) {
		internet.Install(wifi_sta_node_sets[i]);
	}

	for (int i = 300; i <= 305; ++i) {
		internet.Install(wifi_sta_node_sets[i]);
	}

	for (int i = 307; i <= 314; ++i) {
		internet.Install(wifi_sta_node_sets[i]);
	}

// We've got the "hardware" in place.  Now we need to add IP addresses.
//
//print "Assign IP Addresses."
	ns3::Ipv4AddressHelper ipv4;
	ipv4.SetBase(ns3::Ipv4Address("133.71.0.0"), ns3::Ipv4Mask("255.255.0.0"));
	std::vector<ns3::Ipv4InterfaceContainer> p2p_interface_sets(350);
	for (int i = 5; i <= 348; ++i) {
		if (i == 80 || i == 113 || i == 160 || i == 213 || i == 271 || i == 333)
			continue;
		p2p_interface_sets[i] = ipv4.Assign(terminal_device_sets[81]);
	}

	std::vector<ns3::Ipv4InterfaceContainer> apinterface_sets(320);
	for (int i = 1; i <= 315; ++i) {
		if (i == 298 || i == 299 || i == 306 || i == 315)
			continue;
		apinterface_sets[i] = ipv4.Assign(staDeviceSets[i]);
	}

	int port = 9;
	ns3::OnOffHelper onoff1("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.1"),
							port)));
	onoff1.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff1.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff1.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff1.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff1.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff1.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[5].GetAddress(0),
							port)));
	ns3::ApplicationContainer apps = onoff1.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	ns3::PacketSinkHelper sink("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	ns3::ApplicationContainer appsink = sink.Install(terminal_sets[5].Get(0));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));

//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff2("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.2"),
							port)));
	onoff2.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff2.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff2.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff2.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff2.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff2.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[5].GetAddress(1),
							port)));
	apps = onoff2.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[5].Get(1));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff3("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.3"),
							port)));
	onoff3.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff3.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff3.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff3.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff3.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff3.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[5].GetAddress(2),
							port)));
	apps = onoff3.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[5].Get(2));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff4("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.4"),
							port)));
	onoff4.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff4.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff4.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff4.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff4.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff4.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[5].GetAddress(3),
							port)));
	apps = onoff4.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[5].Get(3));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff5("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.5"),
							port)));
	onoff5.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff5.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff5.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff5.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff5.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff5.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[5].GetAddress(4),
							port)));
	apps = onoff5.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[5].Get(4));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
	//int port = 9;
	ns3::OnOffHelper onoff6("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.6"),
							port)));
	onoff6.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff6.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff6.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff6.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff6.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff6.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[6].GetAddress(0),
							port)));
	apps = onoff6.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[6].Get(0));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff7("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.7"),
							port)));
	onoff7.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff7.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff7.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff7.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff7.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff7.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[6].GetAddress(1),
							port)));
	apps = onoff7.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[6].Get(1));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff8("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.8"),
							port)));
	onoff8.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff8.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff8.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff8.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff8.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff8.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[6].GetAddress(2),
							port)));
	apps = onoff8.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[6].Get(2));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff9("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.9"),
							port)));
	onoff9.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff9.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff9.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff9.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff9.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff9.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[6].GetAddress(3),
							port)));
	apps = onoff9.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[6].Get(3));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));
//UDPecho
	//int port = 9;
	ns3::OnOffHelper onoff10("ns3::UdpSocketFactory",
			ns3::Address(
					ns3::InetSocketAddress(ns3::Ipv4Address("133.71.0.10"),
							port)));
	onoff10.SetAttribute("OnTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(5)));
	onoff10.SetAttribute("OffTime",
			ns3::RandomVariableValue(ns3::ConstantVariable(0)));
	onoff10.SetAttribute("DataRate",
			ns3::DataRateValue(ns3::DataRate("100kbps")));
	onoff10.SetAttribute("PacketSize", ns3::StringValue("1024"));
	onoff10.SetAttribute("MaxBytes", ns3::UintegerValue(100000000));
	onoff10.SetAttribute("Remote",
			ns3::AddressValue(
					ns3::InetSocketAddress(p2p_interface_sets[6].GetAddress(4),
							port)));
	apps = onoff10.Install(internetrouter.Get(0));
	apps.Start(ns3::Seconds(0.0));
	apps.Stop(ns3::Seconds(10.0));
	sink = ns3::PacketSinkHelper("ns3::UdpSocketFactory",
			ns3::InetSocketAddress(ns3::Ipv4Address::GetAny(), port));
	appsink = sink.Install(terminal_sets[6].Get(4));
	appsink.Start(ns3::Seconds(0.0));
	appsink.Stop(ns3::Seconds(10.0));

	ns3::Ipv4GlobalRoutingHelper().PopulateRoutingTables();

	ns3::Simulator::Stop(ns3::Seconds(10.00));
	ns3::Simulator::Run();
	ns3::Simulator::Destroy();

	return EXIT_SUCCESS;
} //main
