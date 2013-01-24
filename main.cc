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

NS_LOG_COMPONENT_DEFINE("OnOffApplication");

int main(int argc, char** argv) {
	std::cout << "entered in main function." << std::endl;
	ns3::LogComponentEnable("CsmaBridgeOneHopExample", ns3::LOG_LEVEL_INFO);
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

	//networkkanrisitu-serversegment-ue
	ns3::NodeContainer csmaSwitch5;
	csmaSwitch5.Create(1);

//2F networkkanrisitu WASSY buredoserver-right
	ns3::NodeContainer csmaSwitch6;
	csmaSwitch6.Create(1);
//2F networkkanrisitu buredoserver-left
	ns3::NodeContainer csmaSwitch7;
	csmaSwitch7.Create(1);
//2F networkkanrisitu-serversegment-sita
	ns3::NodeContainer csmaSwitch8;
	csmaSwitch8.Create(1);

//sougoujouhoumediacenter 2F network-kanrisitu-sita
	ns3::NodeContainer csmaSwitch9;
	csmaSwitch9.Create(1);
//sougoujouhoumediacenter 2F network-kanrisitu-sub1
	ns3::NodeContainer csmaSwitch10;
	csmaSwitch10.Create(1);
//sougoujouhoumediacenter 2F network-kanrisitu-sub2
	ns3::NodeContainer csmaSwitch11;
	csmaSwitch11.Create(1);
//RTX1100-1
	ns3::NodeContainer csmaSwitch12;
	csmaSwitch12.Create(1);
//RTX1100-2
	ns3::NodeContainer csmaSwitch13;
	csmaSwitch13.Create(1);
//2F NWkanrisitu-ehimeCATVsama
	ns3::NodeContainer csmaSwitch14;
	csmaSwitch14.Create(1);
//sougoujouhoumediacenter 2F network-kanrisitu-sub3
	ns3::NodeContainer csmaSwitch15;
	csmaSwitch15.Create(1);
//RTX1100-3
	ns3::NodeContainer csmaSwitch16;
	csmaSwitch16.Create(1);
//sougoujouhoumediacenter 2F network-kanrisitu-sub4
	ns3::NodeContainer csmaSwitch17;
	csmaSwitch17.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch18;
	csmaSwitch18.Create(1);
//1F dai5ensyusitu
	ns3::NodeContainer csmaSwitch19;
	csmaSwitch19.Create(1);
//1F serverkisitu-left
	ns3::NodeContainer csmaSwitch20;
	csmaSwitch20.Create(1);
//1F serverkisitu-right
	ns3::NodeContainer csmaSwitch21;
	csmaSwitch21.Create(1);
//WLC-1
	ns3::NodeContainer csmaSwitch22;
	csmaSwitch22.Create(1);
//WLC-2
	ns3::NodeContainer csmaSwitch23;
	csmaSwitch23.Create(1);
//2F mediazikkensitu108-main
	ns3::NodeContainer csmaSwitch24;
	csmaSwitch24.Create(1);
//2F mediazikkensitu108-sub1
	ns3::NodeContainer csmaSwitch25;
	csmaSwitch25.Create(1);
//2F mediazikkensitu108-sub2
	ns3::NodeContainer csmaSwitch26;
	csmaSwitch26.Create(1);
//2F mediazikkensitu108-sub3
	ns3::NodeContainer csmaSwitch27;
	csmaSwitch27.Create(1);
//1F mediaholeEPS
	ns3::NodeContainer csmaSwitch28;
	csmaSwitch28.Create(1);
//2F dai1ensyusitu-left
	ns3::NodeContainer csmaSwitch29;
	csmaSwitch29.Create(1);
//2F dai1ensyusitu-right
	ns3::NodeContainer csmaSwitch30;
	csmaSwitch30.Create(1);
//3F dai2ensyusitu-left
	ns3::NodeContainer csmaSwitch31;
	csmaSwitch31.Create(1);
//3F dai2ensyusitu-right
	ns3::NodeContainer csmaSwitch32;
	csmaSwitch32.Create(1);
//3F dai3ensyusitu-left
	ns3::NodeContainer csmaSwitch33;
	csmaSwitch33.Create(1);
//3F dai3ensyusitu-right
	ns3::NodeContainer csmaSwitch34;
	csmaSwitch34.Create(1);
//4F dai4ensyusitu-left
	ns3::NodeContainer csmaSwitch35;
	csmaSwitch35.Create(1);
//4F dai4ensyusitu-right
	ns3::NodeContainer csmaSwitch36;
	csmaSwitch36.Create(1);
//4F dai6ensyusitu-left
	ns3::NodeContainer csmaSwitch37;
	csmaSwitch37.Create(1);
//4F dai6ensyusitu-right
	ns3::NodeContainer csmaSwitch38;
	csmaSwitch38.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch39;
	csmaSwitch39.Create(1);

//huzokujouhoutosyokan
//2F serversitu
	ns3::NodeContainer csmaSwitch40;
	csmaSwitch40.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch41;
	csmaSwitch41.Create(1);
//2F EPS-nisi
	ns3::NodeContainer csmaSwitch42;
	csmaSwitch42.Create(1);
//3F EPS-nisi
	ns3::NodeContainer csmaSwitch43;
	csmaSwitch43.Create(1);
//4F EPS-nisi
	ns3::NodeContainer csmaSwitch44;
	csmaSwitch44.Create(1);
//6F EPS-nisi
	ns3::NodeContainer csmaSwitch344;
	csmaSwitch344.Create(1);
//1F gakuseiservicecenter
	ns3::NodeContainer csmaSwitch45;
	csmaSwitch45.Create(1);
#2F EPS-higasi-1
	ns3::NodeContainer csmaSwitch46;
	csmaSwitch46.Create(1);
#2F EPS-higasi-2
	ns3::NodeContainer csmaSwitch47;
	csmaSwitch47.Create(1);
#3F EPS-higasi
	ns3::NodeContainer csmaSwitch48;
	csmaSwitch48.Create(1);
#4F EPS-higasi
	ns3::NodeContainer csmaSwitch49;
	csmaSwitch49.Create(1);
#6F EPS-higasi
	ns3::NodeContainer csmaSwitch345;
	csmaSwitch345.Create(1);

//nankakinenho-ru
	ns3::NodeContainer csmaSwitch346;
	csmaSwitch346.Create(1);

//kyouikugakubu3goukan
//2F syoruisitu
	ns3::NodeContainer csmaSwitch50;
	csmaSwitch50.Create(1);

//kyouikugakubuhonkan
//1F buppinko
	ns3::NodeContainer csmaSwitch51;
	csmaSwitch51.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch52;
	csmaSwitch52.Create(1);
//3F EPS-left
	ns3::NodeContainer csmaSwitch53;
	csmaSwitch53.Create(1);
#3F EPS-right
	ns3::NodeContainer csmaSwitch54;
	csmaSwitch54.Create(1);
//4F EPS-left
	ns3::NodeContainer csmaSwitch55;
	csmaSwitch55.Create(1);
#4F EPS-right
	ns3::NodeContainer csmaSwitch56;
	csmaSwitch56.Create(1);

//kyouikugakubu3goukan
//1F chouzouzissyusitu
	ns3::NodeContainer csmaSwitch57;
	csmaSwitch57.Create(1);
//3F gazousyorisitu
	ns3::NodeContainer csmaSwitch58;
	csmaSwitch58.Create(1);
//2F syoruisitu
	ns3::NodeContainer csmaSwitch59;
	csmaSwitch59.Create(1);
//4F syakaitosyositu
	ns3::NodeContainer csmaSwitch60;
	csmaSwitch60.Create(1);
//5F youzikyouikusiryousitu
	ns3::NodeContainer csmaSwitch61;
	csmaSwitch61.Create(1);
//6F 601 ongakuzissyusitu
	ns3::NodeContainer csmaSwitch62;
	csmaSwitch62.Create(1);

//kyouikugakubu4goukan
//1F serversitu N0.1
	ns3::NodeContainer csmaSwitch63;
	csmaSwitch63.Create(1);
//1F serversitu N0.2
	ns3::NodeContainer csmaSwitch64;
	csmaSwitch64.Create(1);
//1F serversitu N0.3
	ns3::NodeContainer csmaSwitch65;
	csmaSwitch65.Create(1);
//2F tikakunintizikkensitu
	ns3::NodeContainer csmaSwitch66;
	csmaSwitch66.Create(1);
//yougo1
	ns3::NodeContainer csmaSwitch67;
	csmaSwitch67.Create(1);
//3F chounouzissyusitu
	ns3::NodeContainer csmaSwitch68;
	csmaSwitch68.Create(1);
//4F gengokunrenzissyusitu
	ns3::NodeContainer csmaSwitch69;
	csmaSwitch69.Create(1);
//kyouikugakubu2goukan
//2F dai2jouhousyorizissyusitu
	ns3::NodeContainer csmaSwitch70;
	csmaSwitch70.Create(1);
//1F kyousyokuinsienroom
	ns3::NodeContainer csmaSwitch71;
	csmaSwitch71.Create(1);
//3F dai1jouhousyorizissyusitu-1
	ns3::NodeContainer csmaSwitch72;
	csmaSwitch72.Create(1);
#3F dai1jouhousyorizissyusitu-2
	ns3::NodeContainer csmaSwitch73;
	csmaSwitch73.Create(1);
//3F buturikenkyusitu-1
	ns3::NodeContainer csmaSwitch74;
	csmaSwitch74.Create(1);
#3F buturikenkyusitu-2
	ns3::NodeContainer csmaSwitch75;
	csmaSwitch75.Create(1);
//4F jouhoubunkazissyusitu-1
	ns3::NodeContainer csmaSwitch76;
	csmaSwitch76.Create(1);
#4F jouhoubunkazissyusitu-2
	ns3::NodeContainer csmaSwitch77;
	csmaSwitch77.Create(1);
//5F ongakuensyusitu
	ns3::NodeContainer csmaSwitch78;
	csmaSwitch78.Create(1);
//jouhokuzimucenter-1
//1F EPS
	ns3::NodeContainer csmaSwitch79;
	csmaSwitch79.Create(1);

//rigakubu
//rigakubu-80setuzoku-switch
	ns3::NodeContainer csmaSwitch80;
	csmaSwitch80.Create(1);
//rigakunu2goukan
//1F rigakubu2goukan-buturikagakukatosyokan
	ns3::NodeContainer csmaSwitch81;
	csmaSwitch81.Create(1);
//2F kyoudoukenkyusitu
	ns3::NodeContainer csmaSwitch82;
	csmaSwitch82.Create(1);
//3F keisankisitu
	ns3::NodeContainer csmaSwitch83;
	csmaSwitch83.Create(1);
//4F suurisugakukadai2ensyusitu
	ns3::NodeContainer csmaSwitch84;
	csmaSwitch84.Create(1);
//rigakubuhonkan-higasi
//1F EPS
	ns3::NodeContainer csmaSwitch85;
	csmaSwitch85.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch86;
	csmaSwitch86.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch87;
	csmaSwitch87.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch88;
	csmaSwitch88.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch89;
	csmaSwitch89.Create(1);
//5F jouhousyoriaitu
	ns3::NodeContainer csmaSwitch90;
	csmaSwitch90.Create(1);
//sougoukenkyutou-nisi--sougoukenkyurou-higasi
//sougoukenkyutou-nisi-1F EPS
	ns3::NodeContainer csmaSwitch91;
	csmaSwitch91.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch92;
	csmaSwitch92.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch93;
	csmaSwitch93.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch94;
	csmaSwitch94.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch95;
	csmaSwitch95.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch96;
	csmaSwitch96.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch97;
	csmaSwitch97.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch98;
	csmaSwitch98.Create(1);

//rigakubuhonkan1F CPUbunsitu
	ns3::NodeContainer csmaSwitch99;
	csmaSwitch99.Create(1);
//sougoukenkyutou-nisi-sita
//1F EPS
	ns3::NodeContainer csmaSwitch100;
	csmaSwitch100.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch101;
	csmaSwitch101.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch102;
	csmaSwitch102.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch103;
	csmaSwitch103.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch104;
	csmaSwitch104.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch105;
	csmaSwitch105.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch106;
	csmaSwitch106.Create(1);

//rigakubuhonkan-nisi-sita
//1F EPS
	ns3::NodeContainer csmaSwitch107;
	csmaSwitch107.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch108;
	csmaSwitch108.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch109;
	csmaSwitch109.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch110;
	csmaSwitch110.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch111;
	csmaSwitch111.Create(1);
//sougoukagakukenkyusiencenter-jouhoku-station
	ns3::NodeContainer csmaSwitch112;
	csmaSwitch112.Create(1);
//sougoujouhoumediacenter 2Fnetwork-kanrisituCATV
	ns3::NodeContainer csmaSwitch113;
	csmaSwitch113.Create(1);

//jouhokuhonbu--aidaimyu-zu
//daigakuhonbu
	ns3::NodeContainer csmaSwitch114;
	csmaSwitch114.Create(1);
//seibutukankyousiryoubank
	ns3::NodeContainer csmaSwitch115;
	csmaSwitch115.Create(1);
//benchabizinesu+musaibouseimeikagakukenkyucenter
//1F EPS
	ns3::NodeContainer csmaSwitch116;
	csmaSwitch116.Create(1);
//2F bencha-bizinesu EPS
	ns3::NodeContainer csmaSwitch117;
	csmaSwitch117.Create(1);
//3F bencha-bizinesu EPS
	ns3::NodeContainer csmaSwitch118;
	csmaSwitch118.Create(1);
//4F bencha-bizinesu EPS
	ns3::NodeContainer csmaSwitch119;
	csmaSwitch119.Create(1);
//1F musaibouseimeikagaku EPS
	ns3::NodeContainer csmaSwitch120;
	csmaSwitch120.Create(1);
//2F musaibouseimeikagaku EPS
	ns3::NodeContainer csmaSwitch121;
	csmaSwitch121.Create(1);
//3F musaibouseimeikagaku EPS
	ns3::NodeContainer csmaSwitch122;
	csmaSwitch122.Create(1);

//sangyoukagakugijutusiencenter
//1F  EPS
	ns3::NodeContainer csmaSwitch123;
	csmaSwitch123.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch124;
	csmaSwitch124.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch125;
	csmaSwitch125.Create(1);

//hougakubuhonkan
//1F 108gousitu main
	ns3::NodeContainer csmaSwitch126;
	csmaSwitch126.Create(1);
//1F syusyokusoudansitu-1
	ns3::NodeContainer csmaSwitch127;
	csmaSwitch127.Create(1);
//1F syusyokusoudansitu-2
	ns3::NodeContainer csmaSwitch128;
	csmaSwitch128.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch129;
	csmaSwitch129.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch130;
	csmaSwitch130.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch131;
	csmaSwitch131.Create(1);
//5F EPS-ue
	ns3::NodeContainer csmaSwitch132;
	csmaSwitch132.Create(1);
//5F EPS-sita
	ns3::NodeContainer csmaSwitch133;
	csmaSwitch133.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch134;
	csmaSwitch134.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch135;
	csmaSwitch135.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch136;
	csmaSwitch136.Create(1);

//houbungakubu2goukan
//1F junbisitu
	ns3::NodeContainer csmaSwitch137;
	csmaSwitch137.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch138;
	csmaSwitch138.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch139;
	csmaSwitch139.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch140;
	csmaSwitch140.Create(1);

//aidaimyuzu-higasi
//aidaimyuzu-higasi 1F EPS
	ns3::NodeContainer csmaSwitch141;
	csmaSwitch141.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch142;
	csmaSwitch142.Create(1);
//2F EPS-left
	ns3::NodeContainer csmaSwitch143;
	csmaSwitch143.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch144;
	csmaSwitch144.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch145;
	csmaSwitch145.Create(1);
//2F EPS-right
	ns3::NodeContainer csmaSwitch146;
	csmaSwitch146.Create(1);

//aidaimyuzu-minami
//1F  EPS
	ns3::NodeContainer csmaSwitch147;
	csmaSwitch147.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch148;
	csmaSwitch148.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch149;
	csmaSwitch149.Create(1);

//aidaimyuzu-nisi
//1F EPS
	ns3::NodeContainer csmaSwitch150;
	csmaSwitch150.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch151;
	csmaSwitch151.Create(1);
//2F M21kyousitu-1
	ns3::NodeContainer csmaSwitch152;
	csmaSwitch152.Create(1);
//2F M21kyousitu-2
	ns3::NodeContainer csmaSwitch153;
	csmaSwitch153.Create(1);
//3F EPS-left
	ns3::NodeContainer csmaSwitch154;
	csmaSwitch154.Create(1);
//3F M31kyousitu-1
	ns3::NodeContainer csmaSwitch155;
	csmaSwitch155.Create(1);
//3F M31kyousitu-2
	ns3::NodeContainer csmaSwitch156;
	csmaSwitch156.Create(1);
//3F EPS-right
	ns3::NodeContainer csmaSwitch157;
	csmaSwitch157.Create(1);

//kyotukyoikukougitou 1F zissyusitu--greenhole
//kyotukyoikukougitou 1F zissyusitu
	ns3::NodeContainer csmaSwitch158;
	csmaSwitch158.Create(1);
//greenhole
	ns3::NodeContainer csmaSwitch159;
	csmaSwitch159.Create(1);

//sougoujouhoumediacenter 2F network kanrisituCATV
	ns3::NodeContainer csmaSwitch160;
	csmaSwitch160.Create(1);

//kougakubu--sougoukenkyu2
//kougakubuhonkan 2F EPS
	ns3::NodeContainer csmaSwitch161;
	csmaSwitch161.Create(1);

//kougakubuhonkan-ue
//1F EPS
	ns3::NodeContainer csmaSwitch162;
	csmaSwitch162.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch163;
	csmaSwitch163.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch164;
	csmaSwitch164.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch165;
	csmaSwitch165.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch166;
	csmaSwitch166.Create(1);

//kougakubu2goukan
//1F rouka joudan,migi
	ns3::NodeContainer csmaSwitch167;
	csmaSwitch167.Create(1);
//1F rouka joudan,hidari
	ns3::NodeContainer csmaSwitch168;
	csmaSwitch168.Create(1);
//2F rouka joudan
	ns3::NodeContainer csmaSwitch169;
	csmaSwitch169.Create(1);
//3F rouka joudan
	ns3::NodeContainer csmaSwitch170;
	csmaSwitch170.Create(1);
//4F rouka joudan
	ns3::NodeContainer csmaSwitch171;
	csmaSwitch171.Create(1);
//5F rouka joudan,migi
	ns3::NodeContainer csmaSwitch172;
	csmaSwitch172.Create(1);
//okyakusamaSW-1
	ns3::NodeContainer csmaSwitch173;
	csmaSwitch173.Create(1);
//5F rouka joudan,hidari
	ns3::NodeContainer csmaSwitch174;
	csmaSwitch174.Create(1);
//3F okuakusamaSW-2
	ns3::NodeContainer csmaSwitch175;
	csmaSwitch175.Create(1);
//6F rouka,joudan
	ns3::NodeContainer csmaSwitch176;
	csmaSwitch176.Create(1);
//okyakusamaSW-3
	ns3::NodeContainer csmaSwitch177;
	csmaSwitch177.Create(1);

//kougakubu3goukan+kougakubu4goukan
//kougakubu3goukan
//3F dai7kenkyusitu-left
	ns3::NodeContainer csmaSwitch178;
	csmaSwitch178.Create(1);
//3F dai7kenkyusitu-right
	ns3::NodeContainer csmaSwitch179;
	csmaSwitch179.Create(1);

//kougakubu4goukan
//3F EPS
	ns3::NodeContainer csmaSwitch180;
	csmaSwitch180.Create(1);
//7F EPS-left
	ns3::NodeContainer csmaSwitch181;
	csmaSwitch181.Create(1);
//7F EPS-right
	ns3::NodeContainer csmaSwitch182;
	csmaSwitch182.Create(1);
//kougakubu5goukan
//1F rouka joudan,migi
	ns3::NodeContainer csmaSwitch183;
	csmaSwitch183.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch184;
	csmaSwitch184.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch185;
	csmaSwitch185.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch186;
	csmaSwitch186.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch187;
	csmaSwitch187.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch188;
	csmaSwitch188.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch189;
	csmaSwitch189.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch190;
	csmaSwitch190.Create(1);
//9F EPS
	ns3::NodeContainer csmaSwitch191;
	csmaSwitch191.Create(1);
//10F EPS
	ns3::NodeContainer csmaSwitch192;
	csmaSwitch192.Create(1);
//kougakubu1goukan
//1F EPS
	ns3::NodeContainer csmaSwitch193;
	csmaSwitch193.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch194;
	csmaSwitch194.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch195;
	csmaSwitch195.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch196;
	csmaSwitch196.Create(1);
//kougakubukougitou
//1F kisokagakuzikkensitu
	ns3::NodeContainer csmaSwitch197;
	csmaSwitch197.Create(1);
//24bankougisitu
	ns3::NodeContainer csmaSwitch343;
	csmaSwitch343.Create(1);
//4F Dseizusitu-1
	ns3::NodeContainer csmaSwitch198;
	csmaSwitch198.Create(1);
//4F Dseizusitu-2
	ns3::NodeContainer csmaSwitch199;
	csmaSwitch199.Create(1);

//sougoukenkyutou
//1F EPS-main
	ns3::NodeContainer csmaSwitch200;
	csmaSwitch200.Create(1);
//3F EPS-main
	ns3::NodeContainer csmaSwitch201;
	csmaSwitch201.Create(1);
//3F EPS-sub-1
	ns3::NodeContainer csmaSwitch202;
	csmaSwitch202.Create(1);
//3F EPS-sub-2
	ns3::NodeContainer csmaSwitch203;
	csmaSwitch203.Create(1);
//3F EPS-sub-3
	ns3::NodeContainer csmaSwitch204;
	csmaSwitch204.Create(1);
//2F EPS-ue
	ns3::NodeContainer csmaSwitch205;
	csmaSwitch205.Create(1);
//1F EPS-sub
	ns3::NodeContainer csmaSwitch206;
	csmaSwitch206.Create(1);
//2F EPS-sita
	ns3::NodeContainer csmaSwitch207;
	csmaSwitch207.Create(1);
//4F EPS-main
	ns3::NodeContainer csmaSwitch208;
	csmaSwitch208.Create(1);
//4F EPS-sub-1
	ns3::NodeContainer csmaSwitch209;
	csmaSwitch209.Create(1);
//4F EPS-sub-2
	ns3::NodeContainer csmaSwitch210;
	csmaSwitch210.Create(1);
//4F EPS-sub-3
	ns3::NodeContainer csmaSwitch211;
	csmaSwitch211.Create(1);

//syakairenkeisuisinnkikou
//1F
	ns3::NodeContainer csmaSwitch347;
	csmaSwitch347.Create(1);
//2F
	ns3::NodeContainer csmaSwitch348;
	csmaSwitch348.Create(1);

//kougakubukikaizissyukoujoutou
//1F zimusitu
	ns3::NodeContainer csmaSwitch212;
	csmaSwitch212.Create(1);
//sougoujouhoumediacenter 2F networkkanrisitu-CATVsama
	ns3::NodeContainer csmaSwitch213;
	csmaSwitch213.Create(1);

//2F serversitu-mediacenterbunsitu-main
	ns3::NodeContainer csmaSwitchsigenobu;
	csmaSwitchsigenobu.Create(1);

//igakubutou2F
//2F EPS
	ns3::NodeContainer csmaSwitch214;
	csmaSwitch214.Create(1);
//sougoukagakukenkyusiencenter-sigenobustation
//2F kagakuzikkensitu
	ns3::NodeContainer csmaSwitch215;
	csmaSwitch215.Create(1);
//1F siryouhokanko1-EPS
	ns3::NodeContainer csmaSwitch216;
	csmaSwitch216.Create(1);
//rinsyoukenkyutou
//1F seitaijouhoukaisekikenkyusitu
	ns3::NodeContainer csmaSwitch217;
	csmaSwitch217.Create(1);
//2F josyusitu
	ns3::NodeContainer csmaSwitch218;
	csmaSwitch218.Create(1);
//3F kyoukankenkyusitu2
	ns3::NodeContainer csmaSwitch219;
	csmaSwitch219.Create(1);
//kangogakkakousya
//3F EPS
	ns3::NodeContainer csmaSwitch220;
	csmaSwitch220.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch221;
	csmaSwitch221.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch222;
	csmaSwitch222.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch223;
	csmaSwitch223.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch224;
	csmaSwitch224.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch225;
	csmaSwitch225.Create(1);
//2F serversitu-mediacenterbunsitu-sub
	ns3::NodeContainer csmaSwitch226;
	csmaSwitch226.Create(1);
//4F ensyusitu
	ns3::NodeContainer csmaSwitch227;
	csmaSwitch227.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch228;
	csmaSwitch228.Create(1);
//gairaitou
//1F housyasenkachouonpakensasitu
	ns3::NodeContainer csmaSwitch229;
	csmaSwitch229.Create(1);
//huzokubyouin1goukan
//2F denwakoukankisitu
	ns3::NodeContainer csmaSwitch230;
	csmaSwitch230.Create(1);
//gairaitou
//1F haidensitu1
	ns3::NodeContainer csmaSwitch231;
	csmaSwitch231.Create(1);
//1F haidensitu2
	ns3::NodeContainer csmaSwitch232;
	csmaSwitch232.Create(1);
//3F eiyousidouditu
	ns3::NodeContainer csmaSwitch233;
	csmaSwitch233.Create(1);
//huzokubyouin1goukan
//1F EPS-nisi
	ns3::NodeContainer csmaSwitch234;
	csmaSwitch234.Create(1);
//1F EPS-higasi
	ns3::NodeContainer csmaSwitch235;
	csmaSwitch235.Create(1);
//2F denwakoukankisitu
	ns3::NodeContainer csmaSwitch236;
	csmaSwitch236.Create(1);
//2F chuoukensasitu
	ns3::NodeContainer csmaSwitch237;
	csmaSwitch237.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch238;
	csmaSwitch238.Create(1);
//3F EPS-nisi
	ns3::NodeContainer csmaSwitch239;
	csmaSwitch239.Create(1);
//3F EPS-higasi
	ns3::NodeContainer csmaSwitch240;
	csmaSwitch240.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch241;
	csmaSwitch241.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch242;
	csmaSwitch242.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch243;
	csmaSwitch243.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch244;
	csmaSwitch244.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch245;
	csmaSwitch245.Create(1);
//9F EPS
	ns3::NodeContainer csmaSwitch246;
	csmaSwitch246.Create(1);
//222F EPS
	ns3::NodeContainer csmaSwitch247;
	csmaSwitch247.Create(1);

//huzokubyouin2goukan
//1F EPS
	ns3::NodeContainer csmaSwitch248;
	csmaSwitch248.Create(1);
//B1F EPS
	ns3::NodeContainer csmaSwitch284;
	csmaSwitch284.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch249;
	csmaSwitch249.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch250;
	csmaSwitch250.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch251;
	csmaSwitch251.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch252;
	csmaSwitch252.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch253;
	csmaSwitch253.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch254;
	csmaSwitch254.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch255;
	csmaSwitch255.Create(1);

//sougoukyouikutou
//2F sosikizissyusitu-main
	ns3::NodeContainer csmaSwitch256;
	csmaSwitch256.Create(1);
//2F sosikizissyusitu-sub1
	ns3::NodeContainer csmaSwitch257;
	csmaSwitch257.Create(1);
//2F sosikizissyusitu-sub2
	ns3::NodeContainer csmaSwitch258;
	csmaSwitch258.Create(1);
//2F sosikizissyusitu-sub3
	ns3::NodeContainer csmaSwitch259;
	csmaSwitch259.Create(1);

//huzokutosyokan-igakububunya
//1F kaigisitu
	ns3::NodeContainer csmaSwitch260;
	csmaSwitch260.Create(1);

//kanritou
//2F kenkyukyouryokusitu
	ns3::NodeContainer csmaSwitch261;
	csmaSwitch261.Create(1);
//3F kaigisitu
	ns3::NodeContainer csmaSwitch262;
	csmaSwitch262.Create(1);
//hukurikaikan
//1F hendensitu
	ns3::NodeContainer csmaSwitch263;
	csmaSwitch263.Create(1);

//igakubutou2F
//2392800G-259TCL
	ns3::NodeContainer csmaSwitch264;
	csmaSwitch264.Create(1);
//2F networktanmatusitu
	ns3::NodeContainer csmaSwitch265;
	csmaSwitch265.Create(1);

//2Fserversitu-ue
	ns3::NodeContainer csmaSwitch266;
	csmaSwitch266.Create(1);
// 2392800G-72TCL
	ns3::NodeContainer csmaSwitch267;
	csmaSwitch267.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch268;
	csmaSwitch268.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch269;
	csmaSwitch269.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch270;
	csmaSwitch270.Create(1);
//okyakusamaSW-1
	ns3::NodeContainer csmaSwitch272;
	csmaSwitch272.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch273;
	csmaSwitch273.Create(1);
//Wasay buredo-server
	ns3::NodeContainer csmaSwitch274;
	csmaSwitch274.Create(1);
//2F serversitu-buredoserver
	ns3::NodeContainer csmaSwitch275;
	csmaSwitch275.Create(1);
//2Fserversitu-sita
	ns3::NodeContainer csmaSwitch276;
	csmaSwitch276.Create(1);
//6F EPS
	ns3::NodeContainer csmaSwitch277;
	csmaSwitch277.Create(1);
//7F EPS
	ns3::NodeContainer csmaSwitch278;
	csmaSwitch278.Create(1);
//okyakusamaSW-2
	ns3::NodeContainer csmaSwitch279;
	csmaSwitch279.Create(1);
//8F EPS
	ns3::NodeContainer csmaSwitch280;
	csmaSwitch280.Create(1);
//okyakusamaSW-3
	ns3::NodeContainer csmaSwitch281;
	csmaSwitch281.Create(1);
//9F EPS
	ns3::NodeContainer csmaSwitch282;
	csmaSwitch282.Create(1);

//igakubumediacenterbunsitu
	ns3::NodeContainer csmaSwitch283;
	csmaSwitch283.Create(1);

//3F serversitu-mediacenterbunsitu-left-main
	ns3::NodeContainer csmaSwitchtarumi;
//csmaSwitchtarumi = ns.network.NodeContainer()
	csmaSwitchtarumi.Create(1);
//nougakubu2goukan-2Fserversitu
//buredoserver
	ns3::NodeContainer csmaSwitch285;
	csmaSwitch285.Create(1);
//3F mediacenterbunsitu-1
	ns3::NodeContainer csmaSwitch286;
	csmaSwitch286.Create(1);
//3F mediacenterbunsitu-2
	ns3::NodeContainer csmaSwitch287;
	csmaSwitch287.Create(1);
//3F mediacenterbunsitu-3-left
	ns3::NodeContainer csmaSwitch288;
	csmaSwitch288.Create(1);
//3F mediacenterbunsitu-3-right
	ns3::NodeContainer csmaSwitch289;
	csmaSwitch289.Create(1);
//3F mediacenterbunsitu-4
	ns3::NodeContainer csmaSwitch290;
	csmaSwitch290.Create(1);

//nougakubu2goukan
//2F EPS-left
	ns3::NodeContainer csmaSwitch291;
	csmaSwitch291.Create(1);
//3F 317kougisitu
	ns3::NodeContainer csmaSwitch292;
	csmaSwitch292.Create(1);
//2F huzokutosyokan-multimediacorner
	ns3::NodeContainer csmaSwitch293;
	csmaSwitch293.Create(1);
//2F EPS-right
	ns3::NodeContainer csmaSwitch294;
	csmaSwitch294.Create(1);
//nougakubu3goukan
//4F seibutukankyoujouhousisutemugaku-conpyutasitu-left
	ns3::NodeContainer csmaSwitch295;
	csmaSwitch295.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch296;
	csmaSwitch296.Create(1);
//2F EPS-ue
	ns3::NodeContainer csmaSwitch297;
	csmaSwitch297.Create(1);
//nougakubuseigyokazikkensisetu
//okyakusamaSW
	ns3::NodeContainer csmaSwitch298;
	csmaSwitch298.Create(1);
//2F EPS-sita
	ns3::NodeContainer csmaSwitch299;
	csmaSwitch299.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch300;
	csmaSwitch300.Create(1);
//4F seibutukankyoujouhousisutemugaku-computersitu-right
	ns3::NodeContainer csmaSwitch301;
	csmaSwitch301.Create(1);
//5F EPS-ue
	ns3::NodeContainer csmaSwitch302;
	csmaSwitch302.Create(1);
//5F EPS-sita
	ns3::NodeContainer csmaSwitch303;
	csmaSwitch303.Create(1);

//nougakubuhonkan-minami
//3F EPS-left
	ns3::NodeContainer csmaSwitch304;
	csmaSwitch304.Create(1);
//1F EPS
	ns3::NodeContainer csmaSwitch305;
	csmaSwitch305.Create(1);
//2F EPS-ue
	ns3::NodeContainer csmaSwitch306;
	csmaSwitch306.Create(1);
//2F EPS-sita
	ns3::NodeContainer csmaSwitch307;
	csmaSwitch307.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch308;
	csmaSwitch308.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch309;
	csmaSwitch309.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch310;
	csmaSwitch310.Create(1);
//sougoukagakukenkyusiencenter
//2F EPS
	ns3::NodeContainer csmaSwitch311;
	csmaSwitch311.Create(1);

//rengounougakukenkyuka
//2F inseikenkyusitu
	ns3::NodeContainer csmaSwitch312;
	csmaSwitch312.Create(1);
//1F zimusitu
	ns3::NodeContainer csmaSwitch313;
	csmaSwitch313.Create(1);
//3F senninkyoukanzikkensitu
	ns3::NodeContainer csmaSwitch314;
	csmaSwitch314.Create(1);

//yukarikaikan
//1F zimusitu
	ns3::NodeContainer csmaSwitch315;
	csmaSwitch315.Create(1);

//3F serversitu-mediacenterbunsitu-right
	ns3::NodeContainer csmaSwitch316;
	csmaSwitch316.Create(1);

//nougakubuhonkan-kita
//1F EPS-left
	ns3::NodeContainer csmaSwitch317;
	csmaSwitch317.Create(1);
//1F EPS-right
	ns3::NodeContainer csmaSwitch318;
	csmaSwitch318.Create(1);
//2F EPS
	ns3::NodeContainer csmaSwitch319;
	csmaSwitch319.Create(1);
//3F EPS
	ns3::NodeContainer csmaSwitch320;
	csmaSwitch320.Create(1);
//6F EPS-left
	ns3::NodeContainer csmaSwitch321;
	csmaSwitch321.Create(1);
//4F EPS
	ns3::NodeContainer csmaSwitch322;
	csmaSwitch322.Create(1);
//5F EPS
	ns3::NodeContainer csmaSwitch323;
	csmaSwitch323.Create(1);
//6F EPS-right
	ns3::NodeContainer csmaSwitch324;
	csmaSwitch324.Create(1);

//mikazikkensitu
//2F EPS
	ns3::NodeContainer csmaSwitch325;
	csmaSwitch325.Create(1);

//huzokukoukousya-minami
//1F EPS
	ns3::NodeContainer csmaSwitch326;
	csmaSwitch326.Create(1);
//5F jouhousiryousakuseisitu
	ns3::NodeContainer csmaSwitch327;
	csmaSwitch327.Create(1);

//huzokukoukousya-kita--huzokukoukousya-naka
//3F jouhousiryousakuseisitu
	ns3::NodeContainer csmaSwitch328;
	csmaSwitch328.Create(1);
//2F kitarouka
	ns3::NodeContainer csmaSwitch329;
	csmaSwitch329.Create(1);
//2F minamirouka
	ns3::NodeContainer csmaSwitch330;
	csmaSwitch330.Create(1);

//kankyousangyoukenkyusisetu
//1F keisankisitu
	ns3::NodeContainer csmaSwitch331;
	csmaSwitch331.Create(1);

//syokubutukoujousama
//2F serverkisitu
	ns3::NodeContainer csmaSwitch332;
	csmaSwitch332.Create(1);

//sougoujouhoumediacenter 2Fnetwork-kanrisituCATV
	ns3::NodeContainer csmaSwitch333;
	csmaSwitch333.Create(1);

//huzokusyougakkoukousya
//1F zimusitu-left
	ns3::NodeContainer csmaSwitch334;
	csmaSwitch334.Create(1);
//1F zimusitu-right
	ns3::NodeContainer csmaSwitch335;
	csmaSwitch335.Create(1);

//huzokusyougakkou-centertou 1F bunkensiryousitu
	ns3::NodeContainer csmaSwitch336;
	csmaSwitch336.Create(1);

//huzokusyougakkoukousya
//2F sichoukakusitu
	ns3::NodeContainer csmaSwitch337;
	csmaSwitch337.Create(1);

//huzokuchugakkou-honkan
//2F kaigisitu
	ns3::NodeContainer csmaSwitch338;
	csmaSwitch338.Create(1);
//1F jouhoukyouikusitu
	ns3::NodeContainer csmaSwitch339;
	csmaSwitch339.Create(1);

//huzokuyougogakkoukousya
//1F keisankisitu
	ns3::NodeContainer csmaSwitch340;
	csmaSwitch340.Create(1);
//ehimedaigakuSW
	ns3::NodeContainer csmaSwitch341;
	csmaSwitch341.Create(1);

//huzokuyoutienhonkan
//1F kyoukansitu
	ns3::NodeContainer csmaSwitch342;
	csmaSwitch342.Create(1);

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

//AP Sta nodes define
	ns3::NodeContainer wifiStaNodes1;
	wifiStaNodes1.Create(15);
	ns3::NodeContainer wifiApNode1;
	wifiApNode1.Create(1);
	ns3::NodeContainer wifiStaNodes2;
	wifiStaNodes2.Create(15);
	ns3::NodeContainer wifiApNode2;
	wifiApNode2.Create(1);
	ns3::NodeContainer wifiStaNodes3;
	wifiStaNodes3.Create(15);
	ns3::NodeContainer wifiApNode3;
	wifiApNode3.Create(1);
	ns3::NodeContainer wifiStaNodes4;
	wifiStaNodes4.Create(15);
	ns3::NodeContainer wifiApNode4;
	wifiApNode4.Create(1);
	ns3::NodeContainer wifiStaNodes5;
	wifiStaNodes5.Create(15);
	ns3::NodeContainer wifiApNode5;
	wifiApNode5.Create(1);
	ns3::NodeContainer wifiStaNodes6;
	wifiStaNodes6.Create(15);
	ns3::NodeContainer wifiApNode6;
	wifiApNode6.Create(1);
	ns3::NodeContainer wifiStaNodes7;
	wifiStaNodes7.Create(15);
	ns3::NodeContainer wifiApNode7;
	wifiApNode7.Create(1);
	ns3::NodeContainer wifiStaNodes8;
	wifiStaNodes8.Create(15);
	ns3::NodeContainer wifiApNode8;
	wifiApNode8.Create(1);
	ns3::NodeContainer wifiStaNodes9;
	wifiStaNodes9.Create(15);
	ns3::NodeContainer wifiApNode9;
	wifiApNode9.Create(1);
	ns3::NodeContainer wifiStaNodes10;
	wifiStaNodes10.Create(15);
	ns3::NodeContainer wifiApNode10;
	wifiApNode10.Create(1);
	ns3::NodeContainer wifiStaNodes11;
	wifiStaNodes11.Create(15);
	ns3::NodeContainer wifiApNode11;
	wifiApNode11.Create(1);
	ns3::NodeContainer wifiStaNodes12;
	wifiStaNodes12.Create(15);
	ns3::NodeContainer wifiApNode12;
	wifiApNode12.Create(1);
	ns3::NodeContainer wifiStaNodes13;
	wifiStaNodes13.Create(15);
	ns3::NodeContainer wifiApNode13;
	wifiApNode13.Create(1);
	ns3::NodeContainer wifiStaNodes14;
	wifiStaNodes14.Create(15);
	ns3::NodeContainer wifiApNode14;
	wifiApNode14.Create(1);
	ns3::NodeContainer wifiStaNodes15;
	wifiStaNodes15.Create(15);
	ns3::NodeContainer wifiApNode15;
	wifiApNode15.Create(1);
	ns3::NodeContainer wifiStaNodes16;
	wifiStaNodes16.Create(15);
	ns3::NodeContainer wifiApNode16;
	wifiApNode16.Create(1);
	ns3::NodeContainer wifiStaNodes17;
	wifiStaNodes17.Create(15);
	ns3::NodeContainer wifiApNode17;
	wifiApNode17.Create(1);
	ns3::NodeContainer wifiStaNodes18;
	wifiStaNodes18.Create(15);
	ns3::NodeContainer wifiApNode18;
	wifiApNode18.Create(1);
	ns3::NodeContainer wifiStaNodes19;
	wifiStaNodes19.Create(15);
	ns3::NodeContainer wifiApNode19;
	wifiApNode19.Create(1);
	ns3::NodeContainer wifiStaNodes20;
	wifiStaNodes20.Create(15);
	ns3::NodeContainer wifiApNode20;
	wifiApNode20.Create(1);
	ns3::NodeContainer wifiStaNodes21;
	wifiStaNodes21.Create(15);
	ns3::NodeContainer wifiApNode21;
	wifiApNode21.Create(1);
	ns3::NodeContainer wifiStaNodes22;
	wifiStaNodes22.Create(15);
	ns3::NodeContainer wifiApNode22;
	wifiApNode22.Create(1);
	ns3::NodeContainer wifiStaNodes23;
	wifiStaNodes23.Create(15);
	ns3::NodeContainer wifiApNode23;
	wifiApNode23.Create(1);
	ns3::NodeContainer wifiStaNodes24;
	wifiStaNodes24.Create(15);
	ns3::NodeContainer wifiApNode24;
	wifiApNode24.Create(1);
	ns3::NodeContainer wifiStaNodes25;
	wifiStaNodes25.Create(15);
	ns3::NodeContainer wifiApNode25;
	wifiApNode25.Create(1);
	ns3::NodeContainer wifiStaNodes26;
	wifiStaNodes26.Create(15);
	ns3::NodeContainer wifiApNode26;
	wifiApNode26.Create(1);
	ns3::NodeContainer wifiStaNodes27;
	wifiStaNodes27.Create(15);
	ns3::NodeContainer wifiApNode27;
	wifiApNode27.Create(1);
	ns3::NodeContainer wifiStaNodes28;
	wifiStaNodes28.Create(15);
	ns3::NodeContainer wifiApNode28;
	wifiApNode28.Create(1);
	ns3::NodeContainer wifiStaNodes29;
	wifiStaNodes29.Create(15);
	ns3::NodeContainer wifiApNode29;
	wifiApNode29.Create(1);
	ns3::NodeContainer wifiStaNodes30;
	wifiStaNodes30.Create(15);
	ns3::NodeContainer wifiApNode30;
	wifiApNode30.Create(1);
	ns3::NodeContainer wifiStaNodes31;
	wifiStaNodes31.Create(15);
	ns3::NodeContainer wifiApNode31;
	wifiApNode31.Create(1);
	ns3::NodeContainer wifiStaNodes32;
	wifiStaNodes32.Create(15);
	ns3::NodeContainer wifiApNode32;
	wifiApNode32.Create(1);
	ns3::NodeContainer wifiStaNodes33;
	wifiStaNodes33.Create(15);
	ns3::NodeContainer wifiApNode33;
	wifiApNode33.Create(1);
	ns3::NodeContainer wifiStaNodes34;
	wifiStaNodes34.Create(15);
	ns3::NodeContainer wifiApNode34;
	wifiApNode34.Create(1);
	ns3::NodeContainer wifiStaNodes35;
	wifiStaNodes35.Create(15);
	ns3::NodeContainer wifiApNode35;
	wifiApNode35.Create(1);
	ns3::NodeContainer wifiStaNodes36;
	wifiStaNodes36.Create(15);
	ns3::NodeContainer wifiApNode36;
	wifiApNode36.Create(1);
	ns3::NodeContainer wifiStaNodes37;
	wifiStaNodes37.Create(15);
	ns3::NodeContainer wifiApNode37;
	wifiApNode37.Create(1);
	ns3::NodeContainer wifiStaNodes38;
	wifiStaNodes38.Create(15);
	ns3::NodeContainer wifiApNode38;
	wifiApNode38.Create(1);
	ns3::NodeContainer wifiStaNodes39;
	wifiStaNodes39.Create(15);
	ns3::NodeContainer wifiApNode39;
	wifiApNode39.Create(1);
	ns3::NodeContainer wifiStaNodes40;
	wifiStaNodes40.Create(15);
	ns3::NodeContainer wifiApNode40;
	wifiApNode40.Create(1);
	ns3::NodeContainer wifiStaNodes41;
	wifiStaNodes41.Create(15);
	ns3::NodeContainer wifiApNode41;
	wifiApNode41.Create(1);
	ns3::NodeContainer wifiStaNodes42;
	wifiStaNodes42.Create(15);
	ns3::NodeContainer wifiApNode42;
	wifiApNode42.Create(1);
	ns3::NodeContainer wifiStaNodes43;
	wifiStaNodes43.Create(15);
	ns3::NodeContainer wifiApNode43;
	wifiApNode43.Create(1);
	ns3::NodeContainer wifiStaNodes44;
	wifiStaNodes44.Create(15);
	ns3::NodeContainer wifiApNode44;
	wifiApNode44.Create(1);
	ns3::NodeContainer wifiStaNodes45;
	wifiStaNodes45.Create(15);
	ns3::NodeContainer wifiApNode45;
	wifiApNode45.Create(1);
	ns3::NodeContainer wifiStaNodes46;
	wifiStaNodes46.Create(15);
	ns3::NodeContainer wifiApNode46;
	wifiApNode46.Create(1);
	ns3::NodeContainer wifiStaNodes47;
	wifiStaNodes47.Create(15);
	ns3::NodeContainer wifiApNode47;
	wifiApNode47.Create(1);
	ns3::NodeContainer wifiStaNodes48;
	wifiStaNodes48.Create(15);
	ns3::NodeContainer wifiApNode48;
	wifiApNode48.Create(1);
	ns3::NodeContainer wifiStaNodes49;
	wifiStaNodes49.Create(15);
	ns3::NodeContainer wifiApNode49;
	wifiApNode49.Create(1);
	ns3::NodeContainer wifiStaNodes50;
	wifiStaNodes50.Create(15);
	ns3::NodeContainer wifiApNode50;
	wifiApNode50.Create(1);
	ns3::NodeContainer wifiStaNodes51;
	wifiStaNodes51.Create(15);
	ns3::NodeContainer wifiApNode51;
	wifiApNode51.Create(1);
	ns3::NodeContainer wifiStaNodes52;
	wifiStaNodes52.Create(15);
	ns3::NodeContainer wifiApNode52;
	wifiApNode52.Create(1);
	ns3::NodeContainer wifiStaNodes53;
	wifiStaNodes53.Create(15);
	ns3::NodeContainer wifiApNode53;
	wifiApNode53.Create(1);
	ns3::NodeContainer wifiStaNodes54;
	wifiStaNodes54.Create(15);
	ns3::NodeContainer wifiApNode54;
	wifiApNode54.Create(1);
	ns3::NodeContainer wifiStaNodes55;
	wifiStaNodes55.Create(15);
	ns3::NodeContainer wifiApNode55;
	wifiApNode55.Create(1);
	ns3::NodeContainer wifiStaNodes56;
	wifiStaNodes56.Create(15);
	ns3::NodeContainer wifiApNode56;
	wifiApNode56.Create(1);
	ns3::NodeContainer wifiStaNodes57;
	wifiStaNodes57.Create(15);
	ns3::NodeContainer wifiApNode57;
	wifiApNode57.Create(1);
	ns3::NodeContainer wifiStaNodes58;
	wifiStaNodes58.Create(15);
	ns3::NodeContainer wifiApNode58;
	wifiApNode58.Create(1);
	ns3::NodeContainer wifiStaNodes59;
	wifiStaNodes59.Create(15);
	ns3::NodeContainer wifiApNode59;
	wifiApNode59.Create(1);
	ns3::NodeContainer wifiStaNodes60;
	wifiStaNodes60.Create(15);
	ns3::NodeContainer wifiApNode60;
	wifiApNode60.Create(1);
	ns3::NodeContainer wifiStaNodes61;
	wifiStaNodes61.Create(15);
	ns3::NodeContainer wifiApNode61;
	wifiApNode61.Create(1);
	ns3::NodeContainer wifiStaNodes62;
	wifiStaNodes62.Create(15);
	ns3::NodeContainer wifiApNode62;
	wifiApNode62.Create(1);
	ns3::NodeContainer wifiStaNodes63;
	wifiStaNodes63.Create(15);
	ns3::NodeContainer wifiApNode63;
	wifiApNode63.Create(1);
	ns3::NodeContainer wifiStaNodes64;
	wifiStaNodes64.Create(15);
	ns3::NodeContainer wifiApNode64;
	wifiApNode64.Create(1);
	ns3::NodeContainer wifiStaNodes65;
	wifiStaNodes65.Create(15);
	ns3::NodeContainer wifiApNode65;
	wifiApNode65.Create(1);
	ns3::NodeContainer wifiStaNodes66;
	wifiStaNodes66.Create(15);
	ns3::NodeContainer wifiApNode66;
	wifiApNode66.Create(1);
	ns3::NodeContainer wifiStaNodes67;
	wifiStaNodes67.Create(15);
	ns3::NodeContainer wifiApNode67;
	wifiApNode67.Create(1);
	ns3::NodeContainer wifiStaNodes68;
	wifiStaNodes68.Create(15);
	ns3::NodeContainer wifiApNode68;
	wifiApNode68.Create(1);
	ns3::NodeContainer wifiStaNodes69;
	wifiStaNodes69.Create(15);
	ns3::NodeContainer wifiApNode69;
	wifiApNode69.Create(1);
	ns3::NodeContainer wifiStaNodes70;
	wifiStaNodes70.Create(15);
	ns3::NodeContainer wifiApNode70;
	wifiApNode70.Create(1);
	ns3::NodeContainer wifiStaNodes71;
	wifiStaNodes71.Create(15);
	ns3::NodeContainer wifiApNode71;
	wifiApNode71.Create(1);
	ns3::NodeContainer wifiStaNodes72;
	wifiStaNodes72.Create(15);
	ns3::NodeContainer wifiApNode72;
	wifiApNode72.Create(1);
	ns3::NodeContainer wifiStaNodes73;
	wifiStaNodes73.Create(15);
	ns3::NodeContainer wifiApNode73;
	wifiApNode73.Create(1);
	ns3::NodeContainer wifiStaNodes74;
	wifiStaNodes74.Create(15);
	ns3::NodeContainer wifiApNode74;
	wifiApNode74.Create(1);
	ns3::NodeContainer wifiStaNodes75;
	wifiStaNodes75.Create(15);
	ns3::NodeContainer wifiApNode75;
	wifiApNode75.Create(1);
	ns3::NodeContainer wifiStaNodes76;
	wifiStaNodes76.Create(15);
	ns3::NodeContainer wifiApNode76;
	wifiApNode76.Create(1);
	ns3::NodeContainer wifiStaNodes77;
	wifiStaNodes77.Create(15);
	ns3::NodeContainer wifiApNode77;
	wifiApNode77.Create(1);
	ns3::NodeContainer wifiStaNodes78;
	wifiStaNodes78.Create(15);
	ns3::NodeContainer wifiApNode78;
	wifiApNode78.Create(1);
	ns3::NodeContainer wifiStaNodes79;
	wifiStaNodes79.Create(15);
	ns3::NodeContainer wifiApNode79;
	wifiApNode79.Create(1);
	ns3::NodeContainer wifiStaNodes80;
	wifiStaNodes80.Create(15);
	ns3::NodeContainer wifiApNode80;
	wifiApNode80.Create(1);
	ns3::NodeContainer wifiStaNodes81;
	wifiStaNodes81.Create(15);
	ns3::NodeContainer wifiApNode81;
	wifiApNode81.Create(1);
	ns3::NodeContainer wifiStaNodes82;
	wifiStaNodes82.Create(15);
	ns3::NodeContainer wifiApNode82;
	wifiApNode82.Create(1);
	ns3::NodeContainer wifiStaNodes83;
	wifiStaNodes83.Create(15);
	ns3::NodeContainer wifiApNode83;
	wifiApNode83.Create(1);
	ns3::NodeContainer wifiStaNodes84;
	wifiStaNodes84.Create(15);
	ns3::NodeContainer wifiApNode84;
	wifiApNode84.Create(1);
	ns3::NodeContainer wifiStaNodes85;
	wifiStaNodes85.Create(15);
	ns3::NodeContainer wifiApNode85;
	wifiApNode85.Create(1);
	ns3::NodeContainer wifiStaNodes86;
	wifiStaNodes86.Create(15);
	ns3::NodeContainer wifiApNode86;
	wifiApNode86.Create(1);
	ns3::NodeContainer wifiStaNodes87;
	wifiStaNodes87.Create(15);
	ns3::NodeContainer wifiApNode87;
	wifiApNode87.Create(1);
	ns3::NodeContainer wifiStaNodes88;
	wifiStaNodes88.Create(15);
	ns3::NodeContainer wifiApNode88;
	wifiApNode88.Create(1);
	ns3::NodeContainer wifiStaNodes89;
	wifiStaNodes89.Create(15);
	ns3::NodeContainer wifiApNode89;
	wifiApNode89.Create(1);
	ns3::NodeContainer wifiStaNodes90;
	wifiStaNodes90.Create(15);
	ns3::NodeContainer wifiApNode90;
	wifiApNode90.Create(1);
	ns3::NodeContainer wifiStaNodes91;
	wifiStaNodes91.Create(15);
	ns3::NodeContainer wifiApNode91;
	wifiApNode91.Create(1);
	ns3::NodeContainer wifiStaNodes92;
	wifiStaNodes92.Create(15);
	ns3::NodeContainer wifiApNode92;
	wifiApNode92.Create(1);
	ns3::NodeContainer wifiStaNodes93;
	wifiStaNodes93.Create(15);
	ns3::NodeContainer wifiApNode93;
	wifiApNode93.Create(1);
	ns3::NodeContainer wifiStaNodes94;
	wifiStaNodes94.Create(15);
	ns3::NodeContainer wifiApNode94;
	wifiApNode94.Create(1);
	ns3::NodeContainer wifiStaNodes95;
	wifiStaNodes95.Create(15);
	ns3::NodeContainer wifiApNode95;
	wifiApNode95.Create(1);
	ns3::NodeContainer wifiStaNodes96;
	wifiStaNodes96.Create(15);
	ns3::NodeContainer wifiApNode96;
	wifiApNode96.Create(1);
	ns3::NodeContainer wifiStaNodes97;
	wifiStaNodes97.Create(15);
	ns3::NodeContainer wifiApNode97;
	wifiApNode97.Create(1);
	ns3::NodeContainer wifiStaNodes98;
	wifiStaNodes98.Create(15);
	ns3::NodeContainer wifiApNode98;
	wifiApNode98.Create(1);
	ns3::NodeContainer wifiStaNodes99;
	wifiStaNodes99.Create(15);
	ns3::NodeContainer wifiApNode99;
	wifiApNode99.Create(1);
	ns3::NodeContainer wifiStaNodes100;
	wifiStaNodes100.Create(15);
	ns3::NodeContainer wifiApNode100;
	wifiApNode100.Create(1);
	ns3::NodeContainer wifiStaNodes101;
	wifiStaNodes101.Create(15);
	ns3::NodeContainer wifiApNode101;
	wifiApNode101.Create(1);
	ns3::NodeContainer wifiStaNodes102;
	wifiStaNodes102.Create(15);
	ns3::NodeContainer wifiApNode102;
	wifiApNode102.Create(1);
	ns3::NodeContainer wifiStaNodes103;
	wifiStaNodes103.Create(15);
	ns3::NodeContainer wifiApNode103;
	wifiApNode103.Create(1);
	ns3::NodeContainer wifiStaNodes104;
	wifiStaNodes104.Create(15);
	ns3::NodeContainer wifiApNode104;
	wifiApNode104.Create(1);
	ns3::NodeContainer wifiStaNodes105;
	wifiStaNodes105.Create(15);
	ns3::NodeContainer wifiApNode105;
	wifiApNode105.Create(1);
	ns3::NodeContainer wifiStaNodes106;
	wifiStaNodes106.Create(15);
	ns3::NodeContainer wifiApNode106;
	wifiApNode106.Create(1);
	ns3::NodeContainer wifiStaNodes107;
	wifiStaNodes107.Create(15);
	ns3::NodeContainer wifiApNode107;
	wifiApNode107.Create(1);
	ns3::NodeContainer wifiStaNodes108;
	wifiStaNodes108.Create(15);
	ns3::NodeContainer wifiApNode108;
	wifiApNode108.Create(1);
	ns3::NodeContainer wifiStaNodes109;
	wifiStaNodes109.Create(15);
	ns3::NodeContainer wifiApNode109;
	wifiApNode109.Create(1);
	ns3::NodeContainer wifiStaNodes110;
	wifiStaNodes110.Create(15);
	ns3::NodeContainer wifiApNode110;
	wifiApNode110.Create(1);
	ns3::NodeContainer wifiStaNodes111;
	wifiStaNodes111.Create(15);
	ns3::NodeContainer wifiApNode111;
	wifiApNode111.Create(1);
	ns3::NodeContainer wifiStaNodes112;
	wifiStaNodes112.Create(15);
	ns3::NodeContainer wifiApNode112;
	wifiApNode112.Create(1);
	ns3::NodeContainer wifiStaNodes113;
	wifiStaNodes113.Create(15);
	ns3::NodeContainer wifiApNode113;
	wifiApNode113.Create(1);
	ns3::NodeContainer wifiStaNodes114;
	wifiStaNodes114.Create(15);
	ns3::NodeContainer wifiApNode114;
	wifiApNode114.Create(1);
	ns3::NodeContainer wifiStaNodes115;
	wifiStaNodes115.Create(15);
	ns3::NodeContainer wifiApNode115;
	wifiApNode115.Create(1);
	ns3::NodeContainer wifiStaNodes116;
	wifiStaNodes116.Create(15);
	ns3::NodeContainer wifiApNode116;
	wifiApNode116.Create(1);
	ns3::NodeContainer wifiStaNodes117;
	wifiStaNodes117.Create(15);
	ns3::NodeContainer wifiApNode117;
	wifiApNode117.Create(1);
	ns3::NodeContainer wifiStaNodes118;
	wifiStaNodes118.Create(15);
	ns3::NodeContainer wifiApNode118;
	wifiApNode118.Create(1);
	ns3::NodeContainer wifiStaNodes119;
	wifiStaNodes119.Create(15);
	ns3::NodeContainer wifiApNode119;
	wifiApNode119.Create(1);
	ns3::NodeContainer wifiStaNodes120;
	wifiStaNodes120.Create(15);
	ns3::NodeContainer wifiApNode120;
	wifiApNode120.Create(1);
	ns3::NodeContainer wifiStaNodes121;
	wifiStaNodes121.Create(15);
	ns3::NodeContainer wifiApNode121;
	wifiApNode121.Create(1);
	ns3::NodeContainer wifiStaNodes122;
	wifiStaNodes122.Create(15);
	ns3::NodeContainer wifiApNode122;
	wifiApNode122.Create(1);
	ns3::NodeContainer wifiStaNodes123;
	wifiStaNodes123.Create(15);
	ns3::NodeContainer wifiApNode123;
	wifiApNode123.Create(1);
	ns3::NodeContainer wifiStaNodes124;
	wifiStaNodes124.Create(15);
	ns3::NodeContainer wifiApNode124;
	wifiApNode124.Create(1);
	ns3::NodeContainer wifiStaNodes125;
	wifiStaNodes125.Create(15);
	ns3::NodeContainer wifiApNode125;
	wifiApNode125.Create(1);
	ns3::NodeContainer wifiStaNodes126;
	wifiStaNodes126.Create(15);
	ns3::NodeContainer wifiApNode126;
	wifiApNode126.Create(1);
	ns3::NodeContainer wifiStaNodes127;
	wifiStaNodes127.Create(15);
	ns3::NodeContainer wifiApNode127;
	wifiApNode127.Create(1);
	ns3::NodeContainer wifiStaNodes128;
	wifiStaNodes128.Create(15);
	ns3::NodeContainer wifiApNode128;
	wifiApNode128.Create(1);
	ns3::NodeContainer wifiStaNodes129;
	wifiStaNodes129.Create(15);
	ns3::NodeContainer wifiApNode129;
	wifiApNode129.Create(1);
	ns3::NodeContainer wifiStaNodes130;
	wifiStaNodes130.Create(15);
	ns3::NodeContainer wifiApNode130;
	wifiApNode130.Create(1);
	ns3::NodeContainer wifiStaNodes131;
	wifiStaNodes131.Create(15);
	ns3::NodeContainer wifiApNode131;
	wifiApNode131.Create(1);
	ns3::NodeContainer wifiStaNodes132;
	wifiStaNodes132.Create(15);
	ns3::NodeContainer wifiApNode132;
	wifiApNode132.Create(1);
	ns3::NodeContainer wifiStaNodes133;
	wifiStaNodes133.Create(15);
	ns3::NodeContainer wifiApNode133;
	wifiApNode133.Create(1);
	ns3::NodeContainer wifiStaNodes134;
	wifiStaNodes134.Create(15);
	ns3::NodeContainer wifiApNode134;
	wifiApNode134.Create(1);
	ns3::NodeContainer wifiStaNodes135;
	wifiStaNodes135.Create(15);
	ns3::NodeContainer wifiApNode135;
	wifiApNode135.Create(1);
	ns3::NodeContainer wifiStaNodes136;
	wifiStaNodes136.Create(15);
	ns3::NodeContainer wifiApNode136;
	wifiApNode136.Create(1);
	ns3::NodeContainer wifiStaNodes137;
	wifiStaNodes137.Create(15);
	ns3::NodeContainer wifiApNode137;
	wifiApNode137.Create(1);
	ns3::NodeContainer wifiStaNodes138;
	wifiStaNodes138.Create(15);
	ns3::NodeContainer wifiApNode138;
	wifiApNode138.Create(1);
	ns3::NodeContainer wifiStaNodes139;
	wifiStaNodes139.Create(15);
	ns3::NodeContainer wifiApNode139;
	wifiApNode139.Create(1);
	ns3::NodeContainer wifiStaNodes140;
	wifiStaNodes140.Create(15);
	ns3::NodeContainer wifiApNode140;
	wifiApNode140.Create(1);
	ns3::NodeContainer wifiStaNodes141;
	wifiStaNodes141.Create(15);
	ns3::NodeContainer wifiApNode141;
	wifiApNode141.Create(1);
	ns3::NodeContainer wifiStaNodes142;
	wifiStaNodes142.Create(15);
	ns3::NodeContainer wifiApNode142;
	wifiApNode142.Create(1);
	ns3::NodeContainer wifiStaNodes143;
	wifiStaNodes143.Create(15);
	ns3::NodeContainer wifiApNode143;
	wifiApNode143.Create(1);
	ns3::NodeContainer wifiStaNodes144;
	wifiStaNodes144.Create(15);
	ns3::NodeContainer wifiApNode144;
	wifiApNode144.Create(1);
	ns3::NodeContainer wifiStaNodes145;
	wifiStaNodes145.Create(15);
	ns3::NodeContainer wifiApNode145;
	wifiApNode145.Create(1);
	ns3::NodeContainer wifiStaNodes146;
	wifiStaNodes146.Create(15);
	ns3::NodeContainer wifiApNode146;
	wifiApNode146.Create(1);
	ns3::NodeContainer wifiStaNodes147;
	wifiStaNodes147.Create(15);
	ns3::NodeContainer wifiApNode147;
	wifiApNode147.Create(1);
	ns3::NodeContainer wifiStaNodes148;
	wifiStaNodes148.Create(15);
	ns3::NodeContainer wifiApNode148;
	wifiApNode148.Create(1);
	ns3::NodeContainer wifiStaNodes149;
	wifiStaNodes149.Create(15);
	ns3::NodeContainer wifiApNode149;
	wifiApNode149.Create(1);
	ns3::NodeContainer wifiStaNodes150;
	wifiStaNodes150.Create(15);
	ns3::NodeContainer wifiApNode150;
	wifiApNode150.Create(1);
	ns3::NodeContainer wifiStaNodes151;
	wifiStaNodes151.Create(15);
	ns3::NodeContainer wifiApNode151;
	wifiApNode151.Create(1);
	ns3::NodeContainer wifiStaNodes152;
	wifiStaNodes152.Create(15);
	ns3::NodeContainer wifiApNode152;
	wifiApNode152.Create(1);
	ns3::NodeContainer wifiStaNodes153;
	wifiStaNodes153.Create(15);
	ns3::NodeContainer wifiApNode153;
	wifiApNode153.Create(1);
	ns3::NodeContainer wifiStaNodes154;
	wifiStaNodes154.Create(15);
	ns3::NodeContainer wifiApNode154;
	wifiApNode154.Create(1);
	ns3::NodeContainer wifiStaNodes155;
	wifiStaNodes155.Create(15);
	ns3::NodeContainer wifiApNode155;
	wifiApNode155.Create(1);
	ns3::NodeContainer wifiStaNodes156;
	wifiStaNodes156.Create(15);
	ns3::NodeContainer wifiApNode156;
	wifiApNode156.Create(1);
	ns3::NodeContainer wifiStaNodes157;
	wifiStaNodes157.Create(15);
	ns3::NodeContainer wifiApNode157;
	wifiApNode157.Create(1);
	ns3::NodeContainer wifiStaNodes158;
	wifiStaNodes158.Create(15);
	ns3::NodeContainer wifiApNode158;
	wifiApNode158.Create(1);
	ns3::NodeContainer wifiStaNodes159;
	wifiStaNodes159.Create(15);
	ns3::NodeContainer wifiApNode159;
	wifiApNode159.Create(1);
	ns3::NodeContainer wifiStaNodes160;
	wifiStaNodes160.Create(15);
	ns3::NodeContainer wifiApNode160;
	wifiApNode160.Create(1);
	ns3::NodeContainer wifiStaNodes161;
	wifiStaNodes161.Create(15);
	ns3::NodeContainer wifiApNode161;
	wifiApNode161.Create(1);
	ns3::NodeContainer wifiStaNodes162;
	wifiStaNodes162.Create(15);
	ns3::NodeContainer wifiApNode162;
	wifiApNode162.Create(1);
	ns3::NodeContainer wifiStaNodes163;
	wifiStaNodes163.Create(15);
	ns3::NodeContainer wifiApNode163;
	wifiApNode163.Create(1);
	ns3::NodeContainer wifiStaNodes164;
	wifiStaNodes164.Create(15);
	ns3::NodeContainer wifiApNode164;
	wifiApNode164.Create(1);
	ns3::NodeContainer wifiStaNodes165;
	wifiStaNodes165.Create(15);
	ns3::NodeContainer wifiApNode165;
	wifiApNode165.Create(1);
	ns3::NodeContainer wifiStaNodes166;
	wifiStaNodes166.Create(15);
	ns3::NodeContainer wifiApNode166;
	wifiApNode166.Create(1);
	ns3::NodeContainer wifiStaNodes167;
	wifiStaNodes167.Create(15);
	ns3::NodeContainer wifiApNode167;
	wifiApNode167.Create(1);
	ns3::NodeContainer wifiStaNodes168;
	wifiStaNodes168.Create(15);
	ns3::NodeContainer wifiApNode168;
	wifiApNode168.Create(1);
	ns3::NodeContainer wifiStaNodes169;
	wifiStaNodes169.Create(15);
	ns3::NodeContainer wifiApNode169;
	wifiApNode169.Create(1);
	ns3::NodeContainer wifiStaNodes170;
	wifiStaNodes170.Create(15);
	ns3::NodeContainer wifiApNode170;
	wifiApNode170.Create(1);
	ns3::NodeContainer wifiStaNodes171;
	wifiStaNodes171.Create(15);
	ns3::NodeContainer wifiApNode171;
	wifiApNode171.Create(1);
	ns3::NodeContainer wifiStaNodes172;
	wifiStaNodes172.Create(15);
	ns3::NodeContainer wifiApNode172;
	wifiApNode172.Create(1);
	ns3::NodeContainer wifiStaNodes173;
	wifiStaNodes173.Create(15);
	ns3::NodeContainer wifiApNode173;
	wifiApNode173.Create(1);
	ns3::NodeContainer wifiStaNodes174;
	wifiStaNodes174.Create(15);
	ns3::NodeContainer wifiApNode174;
	wifiApNode174.Create(1);
	ns3::NodeContainer wifiStaNodes175;
	wifiStaNodes175.Create(15);
	ns3::NodeContainer wifiApNode175;
	wifiApNode175.Create(1);
	ns3::NodeContainer wifiStaNodes176;
	wifiStaNodes176.Create(15);
	ns3::NodeContainer wifiApNode176;
	wifiApNode176.Create(1);
	ns3::NodeContainer wifiStaNodes177;
	wifiStaNodes177.Create(15);
	ns3::NodeContainer wifiApNode177;
	wifiApNode177.Create(1);
	ns3::NodeContainer wifiStaNodes178;
	wifiStaNodes178.Create(15);
	ns3::NodeContainer wifiApNode178;
	wifiApNode178.Create(1);
	ns3::NodeContainer wifiStaNodes179;
	wifiStaNodes179.Create(15);
	ns3::NodeContainer wifiApNode179;
	wifiApNode179.Create(1);
	ns3::NodeContainer wifiStaNodes180;
	wifiStaNodes180.Create(15);
	ns3::NodeContainer wifiApNode180;
	wifiApNode180.Create(1);
	ns3::NodeContainer wifiStaNodes181;
	wifiStaNodes181.Create(15);
	ns3::NodeContainer wifiApNode181;
	wifiApNode181.Create(1);
	ns3::NodeContainer wifiStaNodes182;
	wifiStaNodes182.Create(15);
	ns3::NodeContainer wifiApNode182;
	wifiApNode182.Create(1);
	ns3::NodeContainer wifiStaNodes183;
	wifiStaNodes183.Create(15);
	ns3::NodeContainer wifiApNode183;
	wifiApNode183.Create(1);
	ns3::NodeContainer wifiStaNodes184;
	wifiStaNodes184.Create(15);
	ns3::NodeContainer wifiApNode184;
	wifiApNode184.Create(1);
	ns3::NodeContainer wifiStaNodes185;
	wifiStaNodes185.Create(15);
	ns3::NodeContainer wifiApNode185;
	wifiApNode185.Create(1);
	ns3::NodeContainer wifiStaNodes186;
	wifiStaNodes186.Create(15);
	ns3::NodeContainer wifiApNode186;
	wifiApNode186.Create(1);
	ns3::NodeContainer wifiStaNodes187;
	wifiStaNodes187.Create(15);
	ns3::NodeContainer wifiApNode187;
	wifiApNode187.Create(1);
	ns3::NodeContainer wifiStaNodes188;
	wifiStaNodes188.Create(15);
	ns3::NodeContainer wifiApNode188;
	wifiApNode188.Create(1);
	ns3::NodeContainer wifiStaNodes189;
	wifiStaNodes189.Create(15);
	ns3::NodeContainer wifiApNode189;
	wifiApNode189.Create(1);
	ns3::NodeContainer wifiStaNodes190;
	wifiStaNodes190.Create(15);
	ns3::NodeContainer wifiApNode190;
	wifiApNode190.Create(1);
	ns3::NodeContainer wifiStaNodes191;
	wifiStaNodes191.Create(15);
	ns3::NodeContainer wifiApNode191;
	wifiApNode191.Create(1);
	ns3::NodeContainer wifiStaNodes192;
	wifiStaNodes192.Create(15);
	ns3::NodeContainer wifiApNode192;
	wifiApNode192.Create(1);
	ns3::NodeContainer wifiStaNodes193;
	wifiStaNodes193.Create(15);
	ns3::NodeContainer wifiApNode193;
	wifiApNode193.Create(1);
	ns3::NodeContainer wifiStaNodes194;
	wifiStaNodes194.Create(15);
	ns3::NodeContainer wifiApNode194;
	wifiApNode194.Create(1);
	ns3::NodeContainer wifiStaNodes195;
	wifiStaNodes195.Create(15);
	ns3::NodeContainer wifiApNode195;
	wifiApNode195.Create(1);
	ns3::NodeContainer wifiStaNodes196;
	wifiStaNodes196.Create(15);
	ns3::NodeContainer wifiApNode196;
	wifiApNode196.Create(1);
	ns3::NodeContainer wifiStaNodes197;
	wifiStaNodes197.Create(15);
	ns3::NodeContainer wifiApNode197;
	wifiApNode197.Create(1);
	ns3::NodeContainer wifiStaNodes198;
	wifiStaNodes198.Create(15);
	ns3::NodeContainer wifiApNode198;
	wifiApNode198.Create(1);
	ns3::NodeContainer wifiStaNodes199;
	wifiStaNodes199.Create(15);
	ns3::NodeContainer wifiApNode199;
	wifiApNode199.Create(1);
	ns3::NodeContainer wifiStaNodes200;
	wifiStaNodes200.Create(15);
	ns3::NodeContainer wifiApNode200;
	wifiApNode200.Create(1);
	ns3::NodeContainer wifiStaNodes201;
	wifiStaNodes201.Create(15);
	ns3::NodeContainer wifiApNode201;
	wifiApNode201.Create(1);
	ns3::NodeContainer wifiStaNodes202;
	wifiStaNodes202.Create(15);
	ns3::NodeContainer wifiApNode202;
	wifiApNode202.Create(1);
	ns3::NodeContainer wifiStaNodes203;
	wifiStaNodes203.Create(15);
	ns3::NodeContainer wifiApNode203;
	wifiApNode203.Create(1);
	ns3::NodeContainer wifiStaNodes204;
	wifiStaNodes204.Create(15);
	ns3::NodeContainer wifiApNode204;
	wifiApNode204.Create(1);
	ns3::NodeContainer wifiStaNodes205;
	wifiStaNodes205.Create(15);
	ns3::NodeContainer wifiApNode205;
	wifiApNode205.Create(1);
	ns3::NodeContainer wifiStaNodes206;
	wifiStaNodes206.Create(15);
	ns3::NodeContainer wifiApNode206;
	wifiApNode206.Create(1);
	ns3::NodeContainer wifiStaNodes207;
	wifiStaNodes207.Create(15);
	ns3::NodeContainer wifiApNode207;
	wifiApNode207.Create(1);
	ns3::NodeContainer wifiStaNodes208;
	wifiStaNodes208.Create(15);
	ns3::NodeContainer wifiApNode208;
	wifiApNode208.Create(1);
	ns3::NodeContainer wifiStaNodes209;
	wifiStaNodes209.Create(15);
	ns3::NodeContainer wifiApNode209;
	wifiApNode209.Create(1);
	ns3::NodeContainer wifiStaNodes210;
	wifiStaNodes210.Create(15);
	ns3::NodeContainer wifiApNode210;
	wifiApNode210.Create(1);
	ns3::NodeContainer wifiStaNodes211;
	wifiStaNodes211.Create(15);
	ns3::NodeContainer wifiApNode211;
	wifiApNode211.Create(1);
	ns3::NodeContainer wifiStaNodes212;
	wifiStaNodes212.Create(15);
	ns3::NodeContainer wifiApNode212;
	wifiApNode212.Create(1);
	ns3::NodeContainer wifiStaNodes213;
	wifiStaNodes213.Create(15);
	ns3::NodeContainer wifiApNode213;
	wifiApNode213.Create(1);
	ns3::NodeContainer wifiStaNodes214;
	wifiStaNodes214.Create(15);
	ns3::NodeContainer wifiApNode214;
	wifiApNode214.Create(1);
	ns3::NodeContainer wifiStaNodes215;
	wifiStaNodes215.Create(15);
	ns3::NodeContainer wifiApNode215;
	wifiApNode215.Create(1);
	ns3::NodeContainer wifiStaNodes216;
	wifiStaNodes216.Create(15);
	ns3::NodeContainer wifiApNode216;
	wifiApNode216.Create(1);
	ns3::NodeContainer wifiStaNodes217;
	wifiStaNodes217.Create(15);
	ns3::NodeContainer wifiApNode217;
	wifiApNode217.Create(1);
	ns3::NodeContainer wifiStaNodes218;
	wifiStaNodes218.Create(15);
	ns3::NodeContainer wifiApNode218;
	wifiApNode218.Create(1);
	ns3::NodeContainer wifiStaNodes219;
	wifiStaNodes219.Create(15);
	ns3::NodeContainer wifiApNode219;
	wifiApNode219.Create(1);
	ns3::NodeContainer wifiStaNodes220;
	wifiStaNodes220.Create(15);
	ns3::NodeContainer wifiApNode220;
	wifiApNode220.Create(1);
	ns3::NodeContainer wifiStaNodes221;
	wifiStaNodes221.Create(15);
	ns3::NodeContainer wifiApNode221;
	wifiApNode221.Create(1);
	ns3::NodeContainer wifiStaNodes222;
	wifiStaNodes222.Create(15);
	ns3::NodeContainer wifiApNode222;
	wifiApNode222.Create(1);
	ns3::NodeContainer wifiStaNodes223;
	wifiStaNodes223.Create(15);
	ns3::NodeContainer wifiApNode223;
	wifiApNode223.Create(1);
	ns3::NodeContainer wifiStaNodes224;
	wifiStaNodes224.Create(15);
	ns3::NodeContainer wifiApNode224;
	wifiApNode224.Create(1);
	ns3::NodeContainer wifiStaNodes225;
	wifiStaNodes225.Create(15);
	ns3::NodeContainer wifiApNode225;
	wifiApNode225.Create(1);
	ns3::NodeContainer wifiStaNodes226;
	wifiStaNodes226.Create(15);
	ns3::NodeContainer wifiApNode226;
	wifiApNode226.Create(1);
	ns3::NodeContainer wifiStaNodes227;
	wifiStaNodes227.Create(15);
	ns3::NodeContainer wifiApNode227;
	wifiApNode227.Create(1);
	ns3::NodeContainer wifiStaNodes228;
	wifiStaNodes228.Create(15);
	ns3::NodeContainer wifiApNode228;
	wifiApNode228.Create(1);
	ns3::NodeContainer wifiStaNodes229;
	wifiStaNodes229.Create(15);
	ns3::NodeContainer wifiApNode229;
	wifiApNode229.Create(1);
	ns3::NodeContainer wifiStaNodes230;
	wifiStaNodes230.Create(15);
	ns3::NodeContainer wifiApNode230;
	wifiApNode230.Create(1);
	ns3::NodeContainer wifiStaNodes231;
	wifiStaNodes231.Create(15);
	ns3::NodeContainer wifiApNode231;
	wifiApNode231.Create(1);
	ns3::NodeContainer wifiStaNodes232;
	wifiStaNodes232.Create(15);
	ns3::NodeContainer wifiApNode232;
	wifiApNode232.Create(1);
	ns3::NodeContainer wifiStaNodes233;
	wifiStaNodes233.Create(15);
	ns3::NodeContainer wifiApNode233;
	wifiApNode233.Create(1);
	ns3::NodeContainer wifiStaNodes234;
	wifiStaNodes234.Create(15);
	ns3::NodeContainer wifiApNode234;
	wifiApNode234.Create(1);
	ns3::NodeContainer wifiStaNodes235;
	wifiStaNodes235.Create(15);
	ns3::NodeContainer wifiApNode235;
	wifiApNode235.Create(1);
	ns3::NodeContainer wifiStaNodes236;
	wifiStaNodes236.Create(15);
	ns3::NodeContainer wifiApNode236;
	wifiApNode236.Create(1);
	ns3::NodeContainer wifiStaNodes237;
	wifiStaNodes237.Create(15);
	ns3::NodeContainer wifiApNode237;
	wifiApNode237.Create(1);
	ns3::NodeContainer wifiStaNodes238;
	wifiStaNodes238.Create(15);
	ns3::NodeContainer wifiApNode238;
	wifiApNode238.Create(1);
	ns3::NodeContainer wifiStaNodes239;
	wifiStaNodes239.Create(15);
	ns3::NodeContainer wifiApNode239;
	wifiApNode239.Create(1);
	ns3::NodeContainer wifiStaNodes240;
	wifiStaNodes240.Create(15);
	ns3::NodeContainer wifiApNode240;
	wifiApNode240.Create(1);
	ns3::NodeContainer wifiStaNodes241;
	wifiStaNodes241.Create(15);
	ns3::NodeContainer wifiApNode241;
	wifiApNode241.Create(1);
	ns3::NodeContainer wifiStaNodes242;
	wifiStaNodes242.Create(15);
	ns3::NodeContainer wifiApNode242;
	wifiApNode242.Create(1);
	ns3::NodeContainer wifiStaNodes243;
	wifiStaNodes243.Create(15);
	ns3::NodeContainer wifiApNode243;
	wifiApNode243.Create(1);
	ns3::NodeContainer wifiStaNodes244;
	wifiStaNodes244.Create(15);
	ns3::NodeContainer wifiApNode244;
	wifiApNode244.Create(1);
	ns3::NodeContainer wifiStaNodes245;
	wifiStaNodes245.Create(15);
	ns3::NodeContainer wifiApNode245;
	wifiApNode245.Create(1);
	ns3::NodeContainer wifiStaNodes246;
	wifiStaNodes246.Create(15);
	ns3::NodeContainer wifiApNode246;
	wifiApNode246.Create(1);
	ns3::NodeContainer wifiStaNodes247;
	wifiStaNodes247.Create(15);
	ns3::NodeContainer wifiApNode247;
	wifiApNode247.Create(1);
	ns3::NodeContainer wifiStaNodes248;
	wifiStaNodes248.Create(15);
	ns3::NodeContainer wifiApNode248;
	wifiApNode248.Create(1);
	ns3::NodeContainer wifiStaNodes249;
	wifiStaNodes249.Create(15);
	ns3::NodeContainer wifiApNode249;
	wifiApNode249.Create(1);
	ns3::NodeContainer wifiStaNodes250;
	wifiStaNodes250.Create(15);
	ns3::NodeContainer wifiApNode250;
	wifiApNode250.Create(1);
	ns3::NodeContainer wifiStaNodes251;
	wifiStaNodes251.Create(15);
	ns3::NodeContainer wifiApNode251;
	wifiApNode251.Create(1);
	ns3::NodeContainer wifiStaNodes252;
	wifiStaNodes252.Create(15);
	ns3::NodeContainer wifiApNode252;
	wifiApNode252.Create(1);
	ns3::NodeContainer wifiStaNodes253;
	wifiStaNodes253.Create(15);
	ns3::NodeContainer wifiApNode253;
	wifiApNode253.Create(1);
	ns3::NodeContainer wifiStaNodes254;
	wifiStaNodes254.Create(15);
	ns3::NodeContainer wifiApNode254;
	wifiApNode254.Create(1);
	ns3::NodeContainer wifiStaNodes255;
	wifiStaNodes255.Create(15);
	ns3::NodeContainer wifiApNode255;
	wifiApNode255.Create(1);
	ns3::NodeContainer wifiStaNodes256;
	wifiStaNodes256.Create(15);
	ns3::NodeContainer wifiApNode256;
	wifiApNode256.Create(1);
	ns3::NodeContainer wifiStaNodes257;
	wifiStaNodes257.Create(15);
	ns3::NodeContainer wifiApNode257;
	wifiApNode257.Create(1);
	ns3::NodeContainer wifiStaNodes258;
	wifiStaNodes258.Create(15);
	ns3::NodeContainer wifiApNode258;
	wifiApNode258.Create(1);
	ns3::NodeContainer wifiStaNodes259;
	wifiStaNodes259.Create(15);
	ns3::NodeContainer wifiApNode259;
	wifiApNode259.Create(1);
	ns3::NodeContainer wifiStaNodes260;
	wifiStaNodes260.Create(15);
	ns3::NodeContainer wifiApNode260;
	wifiApNode260.Create(1);
	ns3::NodeContainer wifiStaNodes261;
	wifiStaNodes261.Create(15);
	ns3::NodeContainer wifiApNode261;
	wifiApNode261.Create(1);
	ns3::NodeContainer wifiStaNodes262;
	wifiStaNodes262.Create(15);
	ns3::NodeContainer wifiApNode262;
	wifiApNode262.Create(1);
	ns3::NodeContainer wifiStaNodes263;
	wifiStaNodes263.Create(15);
	ns3::NodeContainer wifiApNode263;
	wifiApNode263.Create(1);
	ns3::NodeContainer wifiStaNodes264;
	wifiStaNodes264.Create(15);
	ns3::NodeContainer wifiApNode264;
	wifiApNode264.Create(1);
	ns3::NodeContainer wifiStaNodes265;
	wifiStaNodes265.Create(15);
	ns3::NodeContainer wifiApNode265;
	wifiApNode265.Create(1);
	ns3::NodeContainer wifiStaNodes266;
	wifiStaNodes266.Create(15);
	ns3::NodeContainer wifiApNode266;
	wifiApNode266.Create(1);
	ns3::NodeContainer wifiStaNodes267;
	wifiStaNodes267.Create(15);
	ns3::NodeContainer wifiApNode267;
	wifiApNode267.Create(1);
	ns3::NodeContainer wifiStaNodes268;
	wifiStaNodes268.Create(15);
	ns3::NodeContainer wifiApNode268;
	wifiApNode268.Create(1);
	ns3::NodeContainer wifiStaNodes269;
	wifiStaNodes269.Create(15);
	ns3::NodeContainer wifiApNode269;
	wifiApNode269.Create(1);
	ns3::NodeContainer wifiStaNodes270;
	wifiStaNodes270.Create(15);
	ns3::NodeContainer wifiApNode270;
	wifiApNode270.Create(1);
	ns3::NodeContainer wifiStaNodes271;
	wifiStaNodes271.Create(15);
	ns3::NodeContainer wifiApNode271;
	wifiApNode271.Create(1);
	ns3::NodeContainer wifiStaNodes272;
	wifiStaNodes272.Create(15);
	ns3::NodeContainer wifiApNode272;
	wifiApNode272.Create(1);
	ns3::NodeContainer wifiStaNodes273;
	wifiStaNodes273.Create(15);
	ns3::NodeContainer wifiApNode273;
	wifiApNode273.Create(1);
	ns3::NodeContainer wifiStaNodes274;
	wifiStaNodes274.Create(15);
	ns3::NodeContainer wifiApNode274;
	wifiApNode274.Create(1);
	ns3::NodeContainer wifiStaNodes275;
	wifiStaNodes275.Create(15);
	ns3::NodeContainer wifiApNode275;
	wifiApNode275.Create(1);
	ns3::NodeContainer wifiStaNodes276;
	wifiStaNodes276.Create(15);
	ns3::NodeContainer wifiApNode276;
	wifiApNode276.Create(1);
	ns3::NodeContainer wifiStaNodes277;
	wifiStaNodes277.Create(15);
	ns3::NodeContainer wifiApNode277;
	wifiApNode277.Create(1);
	ns3::NodeContainer wifiStaNodes278;
	wifiStaNodes278.Create(15);
	ns3::NodeContainer wifiApNode278;
	wifiApNode278.Create(1);
	ns3::NodeContainer wifiStaNodes279;
	wifiStaNodes279.Create(15);
	ns3::NodeContainer wifiApNode279;
	wifiApNode279.Create(1);
	ns3::NodeContainer wifiStaNodes280;
	wifiStaNodes280.Create(15);
	ns3::NodeContainer wifiApNode280;
	wifiApNode280.Create(1);
	ns3::NodeContainer wifiStaNodes281;
	wifiStaNodes281.Create(15);
	ns3::NodeContainer wifiApNode281;
	wifiApNode281.Create(1);
	ns3::NodeContainer wifiStaNodes282;
	wifiStaNodes282.Create(15);
	ns3::NodeContainer wifiApNode282;
	wifiApNode282.Create(1);
	ns3::NodeContainer wifiStaNodes283;
	wifiStaNodes283.Create(15);
	ns3::NodeContainer wifiApNode283;
	wifiApNode283.Create(1);
	ns3::NodeContainer wifiStaNodes284;
	wifiStaNodes284.Create(15);
	ns3::NodeContainer wifiApNode284;
	wifiApNode284.Create(1);
	ns3::NodeContainer wifiStaNodes285;
	wifiStaNodes285.Create(15);
	ns3::NodeContainer wifiApNode285;
	wifiApNode285.Create(1);
	ns3::NodeContainer wifiStaNodes286;
	wifiStaNodes286.Create(15);
	ns3::NodeContainer wifiApNode286;
	wifiApNode286.Create(1);
	ns3::NodeContainer wifiStaNodes287;
	wifiStaNodes287.Create(15);
	ns3::NodeContainer wifiApNode287;
	wifiApNode287.Create(1);
	ns3::NodeContainer wifiStaNodes288;
	wifiStaNodes288.Create(15);
	ns3::NodeContainer wifiApNode288;
	wifiApNode288.Create(1);
	ns3::NodeContainer wifiStaNodes289;
	wifiStaNodes289.Create(15);
	ns3::NodeContainer wifiApNode289;
	wifiApNode289.Create(1);
	ns3::NodeContainer wifiStaNodes290;
	wifiStaNodes290.Create(15);
	ns3::NodeContainer wifiApNode290;
	wifiApNode290.Create(1);
	ns3::NodeContainer wifiStaNodes291;
	wifiStaNodes291.Create(15);
	ns3::NodeContainer wifiApNode291;
	wifiApNode291.Create(1);
	ns3::NodeContainer wifiStaNodes292;
	wifiStaNodes292.Create(15);
	ns3::NodeContainer wifiApNode292;
	wifiApNode292.Create(1);
	ns3::NodeContainer wifiStaNodes293;
	wifiStaNodes293.Create(15);
	ns3::NodeContainer wifiApNode293;
	wifiApNode293.Create(1);
	ns3::NodeContainer wifiStaNodes294;
	wifiStaNodes294.Create(15);
	ns3::NodeContainer wifiApNode294;
	wifiApNode294.Create(1);
	ns3::NodeContainer wifiStaNodes295;
	wifiStaNodes295.Create(15);
	ns3::NodeContainer wifiApNode295;
	wifiApNode295.Create(1);
	ns3::NodeContainer wifiStaNodes296;
	wifiStaNodes296.Create(15);
	ns3::NodeContainer wifiApNode296;
	wifiApNode296.Create(1);
	ns3::NodeContainer wifiStaNodes297;
	wifiStaNodes297.Create(15);
	ns3::NodeContainer wifiApNode297;
	wifiApNode297.Create(1);
	ns3::NodeContainer wifiStaNodes298;
	wifiStaNodes298.Create(15);
	ns3::NodeContainer wifiApNode298;
	wifiApNode298.Create(1);
	ns3::NodeContainer wifiStaNodes299;
	wifiStaNodes299.Create(15);
	ns3::NodeContainer wifiApNode299;
	wifiApNode299.Create(1);
	ns3::NodeContainer wifiStaNodes300;
	wifiStaNodes300.Create(15);
	ns3::NodeContainer wifiApNode300;
	wifiApNode300.Create(1);
	ns3::NodeContainer wifiStaNodes301;
	wifiStaNodes301.Create(15);
	ns3::NodeContainer wifiApNode301;
	wifiApNode301.Create(1);
	ns3::NodeContainer wifiStaNodes302;
	wifiStaNodes302.Create(15);
	ns3::NodeContainer wifiApNode302;
	wifiApNode302.Create(1);
	ns3::NodeContainer wifiStaNodes303;
	wifiStaNodes303.Create(15);
	ns3::NodeContainer wifiApNode303;
	wifiApNode303.Create(1);
	ns3::NodeContainer wifiStaNodes304;
	wifiStaNodes304.Create(15);
	ns3::NodeContainer wifiApNode304;
	wifiApNode304.Create(1);
	ns3::NodeContainer wifiStaNodes305;
	wifiStaNodes305.Create(15);
	ns3::NodeContainer wifiApNode305;
	wifiApNode305.Create(1);
//    wifiStaNodes306 = ns.network.NodeContainer()
//    wifiStaNodes306.Create(15)
//
//    wifiApNode306= ns.network.NodeContainer()
//    wifiApNode306.Create(1)
//
	ns3::NodeContainer wifiStaNodes307;
	wifiStaNodes307.Create(15);
	ns3::NodeContainer wifiApNode307;
	wifiApNode307.Create(1);
	ns3::NodeContainer wifiStaNodes308;
	wifiStaNodes308.Create(15);
	ns3::NodeContainer wifiApNode308;
	wifiApNode308.Create(1);
	ns3::NodeContainer wifiStaNodes309;
	wifiStaNodes309.Create(15);
	ns3::NodeContainer wifiApNode309;
	wifiApNode309.Create(1);
	ns3::NodeContainer wifiStaNodes310;
	wifiStaNodes310.Create(15);
	ns3::NodeContainer wifiApNode310;
	wifiApNode310.Create(1);
	ns3::NodeContainer wifiStaNodes311;
	wifiStaNodes311.Create(15);
	ns3::NodeContainer wifiApNode311;
	wifiApNode311.Create(1);
	ns3::NodeContainer wifiStaNodes312;
	wifiStaNodes312.Create(15);
	ns3::NodeContainer wifiApNode312;
	wifiApNode312.Create(1);
	ns3::NodeContainer wifiStaNodes313;
	wifiStaNodes313.Create(15);
	ns3::NodeContainer wifiApNode313;
	wifiApNode313.Create(1);
	ns3::NodeContainer wifiStaNodes314;
	wifiStaNodes314.Create(15);
	ns3::NodeContainer wifiApNode314;
	wifiApNode314.Create(1);
	ns3::NodeContainer wifiStaNodes315;
	wifiStaNodes315.Create(15);
	ns3::NodeContainer wifiApNode315;
	wifiApNode315.Create(1);
	ns3::NodeContainer wifiStaNodes316;
	wifiStaNodes316.Create(15);
	ns3::NodeContainer wifiApNode316;
	wifiApNode316.Create(1);
	ns3::NodeContainer wifiStaNodes317;
	wifiStaNodes317.Create(15);
	ns3::NodeContainer wifiApNode317;
	wifiApNode317.Create(1);
	ns3::NodeContainer wifiStaNodes318;
	wifiStaNodes318.Create(15);
	ns3::NodeContainer wifiApNode318;
	wifiApNode318.Create(1);
	ns3::NodeContainer wifiStaNodes319;
	wifiStaNodes319.Create(15);
	ns3::NodeContainer wifiApNode319;
	wifiApNode319.Create(1);
	ns3::NodeContainer wifiStaNodes320;
	wifiStaNodes320.Create(15);
	ns3::NodeContainer wifiApNode320;
	wifiApNode320.Create(1);
	ns3::NodeContainer wifiStaNodes321;
	wifiStaNodes321.Create(15);
	ns3::NodeContainer wifiApNode321;
	wifiApNode321.Create(1);
	ns3::NodeContainer wifiStaNodes322;
	wifiStaNodes322.Create(15);
	ns3::NodeContainer wifiApNode322;
	wifiApNode322.Create(1);
	ns3::NodeContainer wifiStaNodes323;
	wifiStaNodes323.Create(15);
	ns3::NodeContainer wifiApNode323;
	wifiApNode323.Create(1);
	ns3::NodeContainer wifiStaNodes324;
	wifiStaNodes324.Create(15);
	ns3::NodeContainer wifiApNode324;
	wifiApNode324.Create(1);
	ns3::NodeContainer wifiStaNodes325;
	wifiStaNodes325.Create(15);
	ns3::NodeContainer wifiApNode325;
	wifiApNode325.Create(1);
	ns3::NodeContainer wifiStaNodes326;
	wifiStaNodes326.Create(15);
	ns3::NodeContainer wifiApNode326;
	wifiApNode326.Create(1);
	ns3::NodeContainer wifiStaNodes327;
	wifiStaNodes327.Create(15);
	ns3::NodeContainer wifiApNode327;
	wifiApNode327.Create(1);
	ns3::NodeContainer wifiStaNodes328;
	wifiStaNodes328.Create(15);
	ns3::NodeContainer wifiApNode328;
	wifiApNode328.Create(1);
	ns3::NodeContainer wifiStaNodes329;
	wifiStaNodes329.Create(15);
	ns3::NodeContainer wifiApNode329;
	wifiApNode329.Create(1);
	ns3::NodeContainer wifiStaNodes330;
	wifiStaNodes330.Create(15);
	ns3::NodeContainer wifiApNode330;
	wifiApNode330.Create(1);
	ns3::NodeContainer wifiStaNodes331;
	wifiStaNodes331.Create(15);
	ns3::NodeContainer wifiApNode331;
	wifiApNode331.Create(1);
	ns3::NodeContainer wifiStaNodes322;
	wifiStaNodes322.Create(15);
	ns3::NodeContainer wifiApNode322;
	wifiApNode322.Create(1);
	ns3::NodeContainer wifiStaNodes323;
	wifiStaNodes323.Create(15);
	ns3::NodeContainer wifiApNode323;
	wifiApNode323.Create(1);
	ns3::NodeContainer wifiStaNodes324;
	wifiStaNodes324.Create(15);
	ns3::NodeContainer wifiApNode324;
	wifiApNode324.Create(1);
	ns3::NodeContainer wifiStaNodes325;
	wifiStaNodes325.Create(15);
	ns3::NodeContainer wifiApNode325;
	wifiApNode325.Create(1);
	ns3::NodeContainer wifiStaNodes326;
	wifiStaNodes326.Create(15);
	ns3::NodeContainer wifiApNode326;
	wifiApNode326.Create(1);
	ns3::NodeContainer wifiStaNodes327;
	wifiStaNodes327.Create(15);
	ns3::NodeContainer wifiApNode327;
	wifiApNode327.Create(1);
	ns3::NodeContainer wifiStaNodes328;
	wifiStaNodes328.Create(15);
	ns3::NodeContainer wifiApNode328;
	wifiApNode328.Create(1);
	ns3::NodeContainer wifiStaNodes329;
	wifiStaNodes329.Create(15);
	ns3::NodeContainer wifiApNode329;
	wifiApNode329.Create(1);
	ns3::NodeContainer wifiStaNodes330;
	wifiStaNodes330.Create(15);
	ns3::NodeContainer wifiApNode330;
	wifiApNode330.Create(1);
	ns3::NodeContainer wifiStaNodes331;
	wifiStaNodes331.Create(15);
	ns3::NodeContainer wifiApNode331;
	wifiApNode331.Create(1);
	ns3::NodeContainer wifiStaNodes332;
	wifiStaNodes332.Create(15);
	ns3::NodeContainer wifiApNode332;
	wifiApNode332.Create(1);
	ns3::NodeContainer wifiStaNodes333;
	wifiStaNodes333.Create(15);
	ns3::NodeContainer wifiApNode333;
	wifiApNode333.Create(1);
	ns3::NodeContainer wifiStaNodes334;
	wifiStaNodes334.Create(15);
	ns3::NodeContainer wifiApNode334;
	wifiApNode334.Create(1);
	ns3::NodeContainer wifiStaNodes335;
	wifiStaNodes335.Create(15);
	ns3::NodeContainer wifiApNode335;
	wifiApNode335.Create(1);
	ns3::NodeContainer wifiStaNodes336;
	wifiStaNodes336.Create(15);
	ns3::NodeContainer wifiApNode336;
	wifiApNode336.Create(1);
	ns3::NodeContainer wifiStaNodes337;
	wifiStaNodes337.Create(15);
	ns3::NodeContainer wifiApNode337;
	wifiApNode337.Create(1);
	ns3::NodeContainer wifiStaNodes338;
	wifiStaNodes338.Create(15);
	ns3::NodeContainer wifiApNode338;
	wifiApNode338.Create(1);
	ns3::NodeContainer wifiStaNodes339;
	wifiStaNodes339.Create(15);
	ns3::NodeContainer wifiApNode339;
	wifiApNode339.Create(1);
	ns3::NodeContainer wifiStaNodes340;
	wifiStaNodes340.Create(15);
	ns3::NodeContainer wifiApNode340;
	wifiApNode340.Create(1);
	ns3::NodeContainer wifiStaNodes341;
	wifiStaNodes341.Create(15);
	ns3::NodeContainer wifiApNode341;
	wifiApNode341.Create(1);

// Create the csma links, from each terminal to the switch

	ns3::NetDeviceContainer internetrouterdevices;
	ns3::NetDeviceContainer switchDevicesrouter;
	ns3::NetDeviceContainer switchDevices6506E;
	ns3::NetDeviceContainer switchDevices5;
	ns3::NetDeviceContainer switchDevices6;
	ns3::NetDeviceContainer switchDevices7;
	ns3::NetDeviceContainer switchDevices8;
	ns3::NetDeviceContainer switchDevices9;
	ns3::NetDeviceContainer switchDevices10;
	ns3::NetDeviceContainer switchDevices11;
	ns3::NetDeviceContainer switchDevices12;
	ns3::NetDeviceContainer switchDevices13;
	ns3::NetDeviceContainer switchDevices14;
	ns3::NetDeviceContainer switchDevices15;
	ns3::NetDeviceContainer switchDevices16;
	ns3::NetDeviceContainer switchDevices17;
	ns3::NetDeviceContainer switchDevices18;
	ns3::NetDeviceContainer switchDevices19;
	ns3::NetDeviceContainer switchDevices20;
	ns3::NetDeviceContainer switchDevices21;
	ns3::NetDeviceContainer switchDevices22;
	ns3::NetDeviceContainer switchDevices23;
	ns3::NetDeviceContainer switchDevices24;
	ns3::NetDeviceContainer switchDevices25;
	ns3::NetDeviceContainer switchDevices26;
	ns3::NetDeviceContainer switchDevices27;
	ns3::NetDeviceContainer switchDevices28;
	ns3::NetDeviceContainer switchDevices29;
	ns3::NetDeviceContainer switchDevices30;
	ns3::NetDeviceContainer switchDevices31;
	ns3::NetDeviceContainer switchDevices32;
	ns3::NetDeviceContainer switchDevices33;
	ns3::NetDeviceContainer switchDevices34;
	ns3::NetDeviceContainer switchDevices35;
	ns3::NetDeviceContainer switchDevices36;
	ns3::NetDeviceContainer switchDevices37;
	ns3::NetDeviceContainer switchDevices38;
	ns3::NetDeviceContainer switchDevices39;
	ns3::NetDeviceContainer switchDevices40;
	ns3::NetDeviceContainer switchDevices41;
	ns3::NetDeviceContainer switchDevices42;
	ns3::NetDeviceContainer switchDevices43;
	ns3::NetDeviceContainer switchDevices44;
	ns3::NetDeviceContainer switchDevices45;
	ns3::NetDeviceContainer switchDevices46;
	ns3::NetDeviceContainer switchDevices47;
	ns3::NetDeviceContainer switchDevices48;
	ns3::NetDeviceContainer switchDevices49;
	ns3::NetDeviceContainer switchDevices50;
	ns3::NetDeviceContainer switchDevices51;
	ns3::NetDeviceContainer switchDevices52;
	ns3::NetDeviceContainer switchDevices53;
	ns3::NetDeviceContainer switchDevices54;
	ns3::NetDeviceContainer switchDevices55;
	ns3::NetDeviceContainer switchDevices56;
	ns3::NetDeviceContainer switchDevices57;
	ns3::NetDeviceContainer switchDevices58;
	ns3::NetDeviceContainer switchDevices59;
	ns3::NetDeviceContainer switchDevices60;
	ns3::NetDeviceContainer switchDevices61;
	ns3::NetDeviceContainer switchDevices62;
	ns3::NetDeviceContainer switchDevices63;
	ns3::NetDeviceContainer switchDevices64;
	ns3::NetDeviceContainer switchDevices65;
	ns3::NetDeviceContainer switchDevices66;
	ns3::NetDeviceContainer switchDevices67;
	ns3::NetDeviceContainer switchDevices68;
	ns3::NetDeviceContainer switchDevices69;
	ns3::NetDeviceContainer switchDevices70;
	ns3::NetDeviceContainer switchDevices71;
	ns3::NetDeviceContainer switchDevices72;
	ns3::NetDeviceContainer switchDevices73;
	ns3::NetDeviceContainer switchDevices74;
	ns3::NetDeviceContainer switchDevices75;
	ns3::NetDeviceContainer switchDevices76;
	ns3::NetDeviceContainer switchDevices77;
	ns3::NetDeviceContainer switchDevices78;
	ns3::NetDeviceContainer switchDevices79;
	ns3::NetDeviceContainer switchDevices80;
	ns3::NetDeviceContainer switchDevices81;
	ns3::NetDeviceContainer switchDevices82;
	ns3::NetDeviceContainer switchDevices83;
	ns3::NetDeviceContainer switchDevices84;
	ns3::NetDeviceContainer switchDevices85;
	ns3::NetDeviceContainer switchDevices86;
	ns3::NetDeviceContainer switchDevices87;
	ns3::NetDeviceContainer switchDevices88;
	ns3::NetDeviceContainer switchDevices89;
	ns3::NetDeviceContainer switchDevices90;
	ns3::NetDeviceContainer switchDevices91;
	ns3::NetDeviceContainer switchDevices92;
	ns3::NetDeviceContainer switchDevices93;
	ns3::NetDeviceContainer switchDevices94;
	ns3::NetDeviceContainer switchDevices95;
	ns3::NetDeviceContainer switchDevices96;
	ns3::NetDeviceContainer switchDevices97;
	ns3::NetDeviceContainer switchDevices98;
	ns3::NetDeviceContainer switchDevices99;
	ns3::NetDeviceContainer switchDevices100;
	ns3::NetDeviceContainer switchDevices101;
	ns3::NetDeviceContainer switchDevices102;
	ns3::NetDeviceContainer switchDevices103;
	ns3::NetDeviceContainer switchDevices104;
	ns3::NetDeviceContainer switchDevices105;
	ns3::NetDeviceContainer switchDevices106;
	ns3::NetDeviceContainer switchDevices107;
	ns3::NetDeviceContainer switchDevices108;
	ns3::NetDeviceContainer switchDevices109;
	ns3::NetDeviceContainer switchDevices110;
	ns3::NetDeviceContainer switchDevices111;
	ns3::NetDeviceContainer switchDevices112;
	ns3::NetDeviceContainer switchDevices113;
	ns3::NetDeviceContainer switchDevices114;
	ns3::NetDeviceContainer switchDevices115;
	ns3::NetDeviceContainer switchDevices116;
	ns3::NetDeviceContainer switchDevices117;
	ns3::NetDeviceContainer switchDevices118;
	ns3::NetDeviceContainer switchDevices119;
	ns3::NetDeviceContainer switchDevices120;
	ns3::NetDeviceContainer switchDevices121;
	ns3::NetDeviceContainer switchDevices122;
	ns3::NetDeviceContainer switchDevices123;
	ns3::NetDeviceContainer switchDevices124;
	ns3::NetDeviceContainer switchDevices125;
	ns3::NetDeviceContainer switchDevices126;
	ns3::NetDeviceContainer switchDevices127;
	ns3::NetDeviceContainer switchDevices128;
	ns3::NetDeviceContainer switchDevices129;
	ns3::NetDeviceContainer switchDevices130;
	ns3::NetDeviceContainer switchDevices131;
	ns3::NetDeviceContainer switchDevices132;
	ns3::NetDeviceContainer switchDevices133;
	ns3::NetDeviceContainer switchDevices134;
	ns3::NetDeviceContainer switchDevices135;
	ns3::NetDeviceContainer switchDevices136;
	ns3::NetDeviceContainer switchDevices137;
	ns3::NetDeviceContainer switchDevices138;
	ns3::NetDeviceContainer switchDevices139;
	ns3::NetDeviceContainer switchDevices140;
	ns3::NetDeviceContainer switchDevices141;
	ns3::NetDeviceContainer switchDevices142;
	ns3::NetDeviceContainer switchDevices143;
	ns3::NetDeviceContainer switchDevices144;
	ns3::NetDeviceContainer switchDevices145;
	ns3::NetDeviceContainer switchDevices146;
	ns3::NetDeviceContainer switchDevices147;
	ns3::NetDeviceContainer switchDevices148;
	ns3::NetDeviceContainer switchDevices149;
	ns3::NetDeviceContainer switchDevices150;
	ns3::NetDeviceContainer switchDevices151;
	ns3::NetDeviceContainer switchDevices152;
	ns3::NetDeviceContainer switchDevices153;
	ns3::NetDeviceContainer switchDevices154;
	ns3::NetDeviceContainer switchDevices155;
	ns3::NetDeviceContainer switchDevices156;
	ns3::NetDeviceContainer switchDevices157;
	ns3::NetDeviceContainer switchDevices158;
	ns3::NetDeviceContainer switchDevices159;
	ns3::NetDeviceContainer switchDevices160;
	ns3::NetDeviceContainer switchDevices161;
	ns3::NetDeviceContainer switchDevices162;
	ns3::NetDeviceContainer switchDevices163;
	ns3::NetDeviceContainer switchDevices164;
	ns3::NetDeviceContainer switchDevices165;
	ns3::NetDeviceContainer switchDevices166;
	ns3::NetDeviceContainer switchDevices167;
	ns3::NetDeviceContainer switchDevices168;
	ns3::NetDeviceContainer switchDevices169;
	ns3::NetDeviceContainer switchDevices170;
	ns3::NetDeviceContainer switchDevices171;
	ns3::NetDeviceContainer switchDevices172;
	ns3::NetDeviceContainer switchDevices173;
	ns3::NetDeviceContainer switchDevices174;
	ns3::NetDeviceContainer switchDevices175;
	ns3::NetDeviceContainer switchDevices176;
	ns3::NetDeviceContainer switchDevices177;
	ns3::NetDeviceContainer switchDevices178;
	ns3::NetDeviceContainer switchDevices179;
	ns3::NetDeviceContainer switchDevices180;
	ns3::NetDeviceContainer switchDevices181;
	ns3::NetDeviceContainer switchDevices182;
	ns3::NetDeviceContainer switchDevices183;
	ns3::NetDeviceContainer switchDevices184;
	ns3::NetDeviceContainer switchDevices185;
	ns3::NetDeviceContainer switchDevices186;
	ns3::NetDeviceContainer switchDevices187;
	ns3::NetDeviceContainer switchDevices188;
	ns3::NetDeviceContainer switchDevices189;
	ns3::NetDeviceContainer switchDevices190;
	ns3::NetDeviceContainer switchDevices191;
	ns3::NetDeviceContainer switchDevices192;
	ns3::NetDeviceContainer switchDevices193;
	ns3::NetDeviceContainer switchDevices194;
	ns3::NetDeviceContainer switchDevices195;
	ns3::NetDeviceContainer switchDevices196;
	ns3::NetDeviceContainer switchDevices197;
	ns3::NetDeviceContainer switchDevices198;
	ns3::NetDeviceContainer switchDevices199;
	ns3::NetDeviceContainer switchDevices200;
	ns3::NetDeviceContainer switchDevices201;
	ns3::NetDeviceContainer switchDevices202;
	ns3::NetDeviceContainer switchDevices203;
	ns3::NetDeviceContainer switchDevices204;
	ns3::NetDeviceContainer switchDevices205;
	ns3::NetDeviceContainer switchDevices206;
	ns3::NetDeviceContainer switchDevices207;
	ns3::NetDeviceContainer switchDevices208;
	ns3::NetDeviceContainer switchDevices209;
	ns3::NetDeviceContainer switchDevices210;
	ns3::NetDeviceContainer switchDevices211;
	ns3::NetDeviceContainer switchDevices212;
	ns3::NetDeviceContainer switchDevices213;
	ns3::NetDeviceContainer switchDevicessigenobu;
	ns3::NetDeviceContainer switchDevices214;
	ns3::NetDeviceContainer switchDevices215;
	ns3::NetDeviceContainer switchDevices216;
	ns3::NetDeviceContainer switchDevices217;
	ns3::NetDeviceContainer switchDevices218;
	ns3::NetDeviceContainer switchDevices219;
	ns3::NetDeviceContainer switchDevices220;
	ns3::NetDeviceContainer switchDevices221;
	ns3::NetDeviceContainer switchDevices222;
	ns3::NetDeviceContainer switchDevices223;
	ns3::NetDeviceContainer switchDevices224;
	ns3::NetDeviceContainer switchDevices225;
	ns3::NetDeviceContainer switchDevices226;
	ns3::NetDeviceContainer switchDevices227;
	ns3::NetDeviceContainer switchDevices228;
	ns3::NetDeviceContainer switchDevices229;
	ns3::NetDeviceContainer switchDevices230;
	ns3::NetDeviceContainer switchDevices231;
	ns3::NetDeviceContainer switchDevices232;
	ns3::NetDeviceContainer switchDevices233;
	ns3::NetDeviceContainer switchDevices234;
	ns3::NetDeviceContainer switchDevices235;
	ns3::NetDeviceContainer switchDevices236;
	ns3::NetDeviceContainer switchDevices237;
	ns3::NetDeviceContainer switchDevices238;
	ns3::NetDeviceContainer switchDevices239;
	ns3::NetDeviceContainer switchDevices240;
	ns3::NetDeviceContainer switchDevices241;
	ns3::NetDeviceContainer switchDevices242;
	ns3::NetDeviceContainer switchDevices243;
	ns3::NetDeviceContainer switchDevices244;
	ns3::NetDeviceContainer switchDevices245;
	ns3::NetDeviceContainer switchDevices246;
	ns3::NetDeviceContainer switchDevices247;
	ns3::NetDeviceContainer switchDevices248;
	ns3::NetDeviceContainer switchDevices284;
	ns3::NetDeviceContainer switchDevices249;
	ns3::NetDeviceContainer switchDevices250;
	ns3::NetDeviceContainer switchDevices251;
	ns3::NetDeviceContainer switchDevices252;
	ns3::NetDeviceContainer switchDevices253;
	ns3::NetDeviceContainer switchDevices254;
	ns3::NetDeviceContainer switchDevices255;
	ns3::NetDeviceContainer switchDevices256;
	ns3::NetDeviceContainer switchDevices257;
	ns3::NetDeviceContainer switchDevices258;
	ns3::NetDeviceContainer switchDevices259;
	ns3::NetDeviceContainer switchDevices260;
	ns3::NetDeviceContainer switchDevices261;
	ns3::NetDeviceContainer switchDevices262;
	ns3::NetDeviceContainer switchDevices263;
	ns3::NetDeviceContainer switchDevices264;
	ns3::NetDeviceContainer switchDevices265;
	ns3::NetDeviceContainer switchDevices266;
	ns3::NetDeviceContainer switchDevices267;
	ns3::NetDeviceContainer switchDevices268;
	ns3::NetDeviceContainer switchDevices269;
	ns3::NetDeviceContainer switchDevices270;
	ns3::NetDeviceContainer switchDevices272;
	ns3::NetDeviceContainer switchDevices273;
	ns3::NetDeviceContainer switchDevices274;
	ns3::NetDeviceContainer switchDevices275;
	ns3::NetDeviceContainer switchDevices276;
	ns3::NetDeviceContainer switchDevices277;
	ns3::NetDeviceContainer switchDevices278;
	ns3::NetDeviceContainer switchDevices279;
	ns3::NetDeviceContainer switchDevices280;
	ns3::NetDeviceContainer switchDevices281;
	ns3::NetDeviceContainer switchDevices282;
	ns3::NetDeviceContainer switchDevices283;
	ns3::NetDeviceContainer switchDevicestarumi;
	ns3::NetDeviceContainer switchDevices285;
	ns3::NetDeviceContainer switchDevices286;
	ns3::NetDeviceContainer switchDevices287;
	ns3::NetDeviceContainer switchDevices288;
	ns3::NetDeviceContainer switchDevices289;
	ns3::NetDeviceContainer switchDevices290;
	ns3::NetDeviceContainer switchDevices291;
	ns3::NetDeviceContainer switchDevices292;
	ns3::NetDeviceContainer switchDevices293;
	ns3::NetDeviceContainer switchDevices294;
	ns3::NetDeviceContainer switchDevices295;
	ns3::NetDeviceContainer switchDevices296;
	ns3::NetDeviceContainer switchDevices297;
	ns3::NetDeviceContainer switchDevices298;
	ns3::NetDeviceContainer switchDevices299;
	ns3::NetDeviceContainer switchDevices300;
	ns3::NetDeviceContainer switchDevices301;
	ns3::NetDeviceContainer switchDevices302;
	ns3::NetDeviceContainer switchDevices303;
	ns3::NetDeviceContainer switchDevices304;
	ns3::NetDeviceContainer switchDevices305;
	ns3::NetDeviceContainer switchDevices306;
	ns3::NetDeviceContainer switchDevices307;
	ns3::NetDeviceContainer switchDevices308;
	ns3::NetDeviceContainer switchDevices309;
	ns3::NetDeviceContainer switchDevices310;
	ns3::NetDeviceContainer switchDevices311;
	ns3::NetDeviceContainer switchDevices312;
	ns3::NetDeviceContainer switchDevices313;
	ns3::NetDeviceContainer switchDevices314;
	ns3::NetDeviceContainer switchDevices315;
	ns3::NetDeviceContainer switchDevices316;
	ns3::NetDeviceContainer switchDevices317;
	ns3::NetDeviceContainer switchDevices318;
	ns3::NetDeviceContainer switchDevices319;
	ns3::NetDeviceContainer switchDevices320;
	ns3::NetDeviceContainer switchDevices321;
	ns3::NetDeviceContainer switchDevices322;
	ns3::NetDeviceContainer switchDevices323;
	ns3::NetDeviceContainer switchDevices324;
	ns3::NetDeviceContainer switchDevices325;
	ns3::NetDeviceContainer switchDevices326;
	ns3::NetDeviceContainer switchDevices327;
	ns3::NetDeviceContainer switchDevices328;
	ns3::NetDeviceContainer switchDevices329;
	ns3::NetDeviceContainer switchDevices330;
	ns3::NetDeviceContainer switchDevices331;
	ns3::NetDeviceContainer switchDevices332;
	ns3::NetDeviceContainer switchDevices333;
	ns3::NetDeviceContainer switchDevices334;
	ns3::NetDeviceContainer switchDevices335;
	ns3::NetDeviceContainer switchDevices336;
	ns3::NetDeviceContainer switchDevices337;
	ns3::NetDeviceContainer switchDevices338;
	ns3::NetDeviceContainer switchDevices339;
	ns3::NetDeviceContainer switchDevices340;
	ns3::NetDeviceContainer switchDevices341;
	ns3::NetDeviceContainer switchDevices342;
	ns3::NetDeviceContainer switchDevices343;
	ns3::NetDeviceContainer switchDevices344;
	ns3::NetDeviceContainer switchDevices345;
	ns3::NetDeviceContainer switchDevices346;
	ns3::NetDeviceContainer switchDevices347;
	ns3::NetDeviceContainer switchDevices348;

	ns3::NetDeviceContainer terminaldevices5;
	ns3::NetDeviceContainer terminaldevices6;
	ns3::NetDeviceContainer terminaldevices7;
	ns3::NetDeviceContainer terminaldevices8;
	ns3::NetDeviceContainer terminaldevices9;
	ns3::NetDeviceContainer terminaldevices10;
	ns3::NetDeviceContainer terminaldevices11;
	ns3::NetDeviceContainer terminaldevices12;
	ns3::NetDeviceContainer terminaldevices13;
	ns3::NetDeviceContainer terminaldevices14;
	ns3::NetDeviceContainer terminaldevices15;
	ns3::NetDeviceContainer terminaldevices16;
	ns3::NetDeviceContainer terminaldevices17;
	ns3::NetDeviceContainer terminaldevices18;
	ns3::NetDeviceContainer terminaldevices19;
	ns3::NetDeviceContainer terminaldevices20;
	ns3::NetDeviceContainer terminaldevices21;
	ns3::NetDeviceContainer terminaldevices22;
	ns3::NetDeviceContainer terminaldevices23;
	ns3::NetDeviceContainer terminaldevices24;
	ns3::NetDeviceContainer terminaldevices25;
	ns3::NetDeviceContainer terminaldevices26;
	ns3::NetDeviceContainer terminaldevices27;
	ns3::NetDeviceContainer terminaldevices28;
	ns3::NetDeviceContainer terminaldevices29;
	ns3::NetDeviceContainer terminaldevices30;
	ns3::NetDeviceContainer terminaldevices31;
	ns3::NetDeviceContainer terminaldevices32;
	ns3::NetDeviceContainer terminaldevices33;
	ns3::NetDeviceContainer terminaldevices34;
	ns3::NetDeviceContainer terminaldevices35;
	ns3::NetDeviceContainer terminaldevices36;
	ns3::NetDeviceContainer terminaldevices37;
	ns3::NetDeviceContainer terminaldevices38;
	ns3::NetDeviceContainer terminaldevices39;
	ns3::NetDeviceContainer terminaldevices40;
	ns3::NetDeviceContainer terminaldevices41;
	ns3::NetDeviceContainer terminaldevices42;
	ns3::NetDeviceContainer terminaldevices43;
	ns3::NetDeviceContainer terminaldevices44;
	ns3::NetDeviceContainer terminaldevices45;
	ns3::NetDeviceContainer terminaldevices46;
	ns3::NetDeviceContainer terminaldevices47;
	ns3::NetDeviceContainer terminaldevices48;
	ns3::NetDeviceContainer terminaldevices49;
	ns3::NetDeviceContainer terminaldevices50;
	ns3::NetDeviceContainer terminaldevices51;
	ns3::NetDeviceContainer terminaldevices52;
	ns3::NetDeviceContainer terminaldevices53;
	ns3::NetDeviceContainer terminaldevices54;
	ns3::NetDeviceContainer terminaldevices55;
	ns3::NetDeviceContainer terminaldevices56;
	ns3::NetDeviceContainer terminaldevices57;
	ns3::NetDeviceContainer terminaldevices58;
	ns3::NetDeviceContainer terminaldevices59;
	ns3::NetDeviceContainer terminaldevices60;
	ns3::NetDeviceContainer terminaldevices61;
	ns3::NetDeviceContainer terminaldevices62;
	ns3::NetDeviceContainer terminaldevices63;
	ns3::NetDeviceContainer terminaldevices64;
	ns3::NetDeviceContainer terminaldevices65;
	ns3::NetDeviceContainer terminaldevices66;
	ns3::NetDeviceContainer terminaldevices67;
	ns3::NetDeviceContainer terminaldevices68;
	ns3::NetDeviceContainer terminaldevices69;
	ns3::NetDeviceContainer terminaldevices70;
	ns3::NetDeviceContainer terminaldevices71;
	ns3::NetDeviceContainer terminaldevices72;
	ns3::NetDeviceContainer terminaldevices73;
	ns3::NetDeviceContainer terminaldevices74;
	ns3::NetDeviceContainer terminaldevices75;
	ns3::NetDeviceContainer terminaldevices76;
	ns3::NetDeviceContainer terminaldevices77;
	ns3::NetDeviceContainer terminaldevices78;
	ns3::NetDeviceContainer terminaldevices79;
	ns3::NetDeviceContainer terminaldevices81;
	ns3::NetDeviceContainer terminaldevices82;
	ns3::NetDeviceContainer terminaldevices83;
	ns3::NetDeviceContainer terminaldevices84;
	ns3::NetDeviceContainer terminaldevices85;
	ns3::NetDeviceContainer terminaldevices86;
	ns3::NetDeviceContainer terminaldevices87;
	ns3::NetDeviceContainer terminaldevices88;
	ns3::NetDeviceContainer terminaldevices89;
	ns3::NetDeviceContainer terminaldevices90;
	ns3::NetDeviceContainer terminaldevices91;
	ns3::NetDeviceContainer terminaldevices92;
	ns3::NetDeviceContainer terminaldevices93;
	ns3::NetDeviceContainer terminaldevices94;
	ns3::NetDeviceContainer terminaldevices95;
	ns3::NetDeviceContainer terminaldevices96;
	ns3::NetDeviceContainer terminaldevices97;
	ns3::NetDeviceContainer terminaldevices98;
	ns3::NetDeviceContainer terminaldevices99;
	ns3::NetDeviceContainer terminaldevices100;
	ns3::NetDeviceContainer terminaldevices101;
	ns3::NetDeviceContainer terminaldevices102;
	ns3::NetDeviceContainer terminaldevices103;
	ns3::NetDeviceContainer terminaldevices104;
	ns3::NetDeviceContainer terminaldevices105;
	ns3::NetDeviceContainer terminaldevices106;
	ns3::NetDeviceContainer terminaldevices107;
	ns3::NetDeviceContainer terminaldevices108;
	ns3::NetDeviceContainer terminaldevices109;
	ns3::NetDeviceContainer terminaldevices110;
	ns3::NetDeviceContainer terminaldevices111;
	ns3::NetDeviceContainer terminaldevices112;
	ns3::NetDeviceContainer terminaldevices114;
	ns3::NetDeviceContainer terminaldevices115;
	ns3::NetDeviceContainer terminaldevices116;
	ns3::NetDeviceContainer terminaldevices117;
	ns3::NetDeviceContainer terminaldevices118;
	ns3::NetDeviceContainer terminaldevices119;
	ns3::NetDeviceContainer terminaldevices120;
	ns3::NetDeviceContainer terminaldevices121;
	ns3::NetDeviceContainer terminaldevices122;
	ns3::NetDeviceContainer terminaldevices123;
	ns3::NetDeviceContainer terminaldevices124;
	ns3::NetDeviceContainer terminaldevices125;
	ns3::NetDeviceContainer terminaldevices126;
	ns3::NetDeviceContainer terminaldevices127;
	ns3::NetDeviceContainer terminaldevices128;
	ns3::NetDeviceContainer terminaldevices129;
	ns3::NetDeviceContainer terminaldevices130;
	ns3::NetDeviceContainer terminaldevices131;
	ns3::NetDeviceContainer terminaldevices132;
	ns3::NetDeviceContainer terminaldevices133;
	ns3::NetDeviceContainer terminaldevices134;
	ns3::NetDeviceContainer terminaldevices135;
	ns3::NetDeviceContainer terminaldevices136;
	ns3::NetDeviceContainer terminaldevices137;
	ns3::NetDeviceContainer terminaldevices138;
	ns3::NetDeviceContainer terminaldevices139;
	ns3::NetDeviceContainer terminaldevices140;
	ns3::NetDeviceContainer terminaldevices141;
	ns3::NetDeviceContainer terminaldevices142;
	ns3::NetDeviceContainer terminaldevices143;
	ns3::NetDeviceContainer terminaldevices144;
	ns3::NetDeviceContainer terminaldevices145;
	ns3::NetDeviceContainer terminaldevices146;
	ns3::NetDeviceContainer terminaldevices147;
	ns3::NetDeviceContainer terminaldevices148;
	ns3::NetDeviceContainer terminaldevices149;
	ns3::NetDeviceContainer terminaldevices150;
	ns3::NetDeviceContainer terminaldevices151;
	ns3::NetDeviceContainer terminaldevices152;
	ns3::NetDeviceContainer terminaldevices153;
	ns3::NetDeviceContainer terminaldevices154;
	ns3::NetDeviceContainer terminaldevices155;
	ns3::NetDeviceContainer terminaldevices156;
	ns3::NetDeviceContainer terminaldevices157;
	ns3::NetDeviceContainer terminaldevices158;
	ns3::NetDeviceContainer terminaldevices159;
	ns3::NetDeviceContainer terminaldevices161;
	ns3::NetDeviceContainer terminaldevices162;
	ns3::NetDeviceContainer terminaldevices163;
	ns3::NetDeviceContainer terminaldevices164;
	ns3::NetDeviceContainer terminaldevices165;
	ns3::NetDeviceContainer terminaldevices166;
	ns3::NetDeviceContainer terminaldevices167;
	ns3::NetDeviceContainer terminaldevices168;
	ns3::NetDeviceContainer terminaldevices169;
	ns3::NetDeviceContainer terminaldevices170;
	ns3::NetDeviceContainer terminaldevices171;
	ns3::NetDeviceContainer terminaldevices172;
	ns3::NetDeviceContainer terminaldevices173;
	ns3::NetDeviceContainer terminaldevices174;
	ns3::NetDeviceContainer terminaldevices175;
	ns3::NetDeviceContainer terminaldevices176;
	ns3::NetDeviceContainer terminaldevices177;
	ns3::NetDeviceContainer terminaldevices178;
	ns3::NetDeviceContainer terminaldevices179;
	ns3::NetDeviceContainer terminaldevices180;
	ns3::NetDeviceContainer terminaldevices181;
	ns3::NetDeviceContainer terminaldevices182;
	ns3::NetDeviceContainer terminaldevices183;
	ns3::NetDeviceContainer terminaldevices184;
	ns3::NetDeviceContainer terminaldevices185;
	ns3::NetDeviceContainer terminaldevices186;
	ns3::NetDeviceContainer terminaldevices187;
	ns3::NetDeviceContainer terminaldevices188;
	ns3::NetDeviceContainer terminaldevices189;
	ns3::NetDeviceContainer terminaldevices190;
	ns3::NetDeviceContainer terminaldevices191;
	ns3::NetDeviceContainer terminaldevices192;
	ns3::NetDeviceContainer terminaldevices193;
	ns3::NetDeviceContainer terminaldevices194;
	ns3::NetDeviceContainer terminaldevices195;
	ns3::NetDeviceContainer terminaldevices196;
	ns3::NetDeviceContainer terminaldevices197;
	ns3::NetDeviceContainer terminaldevices198;
	ns3::NetDeviceContainer terminaldevices199;
	ns3::NetDeviceContainer terminaldevices200;
	ns3::NetDeviceContainer terminaldevices201;
	ns3::NetDeviceContainer terminaldevices202;
	ns3::NetDeviceContainer terminaldevices203;
	ns3::NetDeviceContainer terminaldevices204;
	ns3::NetDeviceContainer terminaldevices205;
	ns3::NetDeviceContainer terminaldevices206;
	ns3::NetDeviceContainer terminaldevices207;
	ns3::NetDeviceContainer terminaldevices208;
	ns3::NetDeviceContainer terminaldevices209;
	ns3::NetDeviceContainer terminaldevices210;
	ns3::NetDeviceContainer terminaldevices211;
	ns3::NetDeviceContainer terminaldevices212;
	ns3::NetDeviceContainer terminaldevices214;
	ns3::NetDeviceContainer terminaldevices215;
	ns3::NetDeviceContainer terminaldevices216;
	ns3::NetDeviceContainer terminaldevices217;
	ns3::NetDeviceContainer terminaldevices218;
	ns3::NetDeviceContainer terminaldevices219;
	ns3::NetDeviceContainer terminaldevices220;
	ns3::NetDeviceContainer terminaldevices221;
	ns3::NetDeviceContainer terminaldevices222;
	ns3::NetDeviceContainer terminaldevices223;
	ns3::NetDeviceContainer terminaldevices224;
	ns3::NetDeviceContainer terminaldevices225;
	ns3::NetDeviceContainer terminaldevices226;
	ns3::NetDeviceContainer terminaldevices227;
	ns3::NetDeviceContainer terminaldevices228;
	ns3::NetDeviceContainer terminaldevices229;
	ns3::NetDeviceContainer terminaldevices230;
	ns3::NetDeviceContainer terminaldevices231;
	ns3::NetDeviceContainer terminaldevices232;
	ns3::NetDeviceContainer terminaldevices233;
	ns3::NetDeviceContainer terminaldevices234;
	ns3::NetDeviceContainer terminaldevices235;
	ns3::NetDeviceContainer terminaldevices236;
	ns3::NetDeviceContainer terminaldevices237;
	ns3::NetDeviceContainer terminaldevices238;
	ns3::NetDeviceContainer terminaldevices239;
	ns3::NetDeviceContainer terminaldevices240;
	ns3::NetDeviceContainer terminaldevices241;
	ns3::NetDeviceContainer terminaldevices242;
	ns3::NetDeviceContainer terminaldevices243;
	ns3::NetDeviceContainer terminaldevices244;
	ns3::NetDeviceContainer terminaldevices245;
	ns3::NetDeviceContainer terminaldevices246;
	ns3::NetDeviceContainer terminaldevices247;
	ns3::NetDeviceContainer terminaldevices248;
	ns3::NetDeviceContainer terminaldevices284;
	ns3::NetDeviceContainer terminaldevices249;
	ns3::NetDeviceContainer terminaldevices250;
	ns3::NetDeviceContainer terminaldevices251;
	ns3::NetDeviceContainer terminaldevices252;
	ns3::NetDeviceContainer terminaldevices253;
	ns3::NetDeviceContainer terminaldevices254;
	ns3::NetDeviceContainer terminaldevices255;
	ns3::NetDeviceContainer terminaldevices256;
	ns3::NetDeviceContainer terminaldevices257;
	ns3::NetDeviceContainer terminaldevices258;
	ns3::NetDeviceContainer terminaldevices259;
	ns3::NetDeviceContainer terminaldevices260;
	ns3::NetDeviceContainer terminaldevices261;
	ns3::NetDeviceContainer terminaldevices262;
	ns3::NetDeviceContainer terminaldevices263;
	ns3::NetDeviceContainer terminaldevices264;
	ns3::NetDeviceContainer terminaldevices265;
	ns3::NetDeviceContainer terminaldevices266;
	ns3::NetDeviceContainer terminaldevices267;
	ns3::NetDeviceContainer terminaldevices268;
	ns3::NetDeviceContainer terminaldevices269;
	ns3::NetDeviceContainer terminaldevices270;
	ns3::NetDeviceContainer terminaldevices272;
	ns3::NetDeviceContainer terminaldevices273;
	ns3::NetDeviceContainer terminaldevices274;
	ns3::NetDeviceContainer terminaldevices275;
	ns3::NetDeviceContainer terminaldevices276;
	ns3::NetDeviceContainer terminaldevices277;
	ns3::NetDeviceContainer terminaldevices278;
	ns3::NetDeviceContainer terminaldevices279;
	ns3::NetDeviceContainer terminaldevices280;
	ns3::NetDeviceContainer terminaldevices281;
	ns3::NetDeviceContainer terminaldevices282;
	ns3::NetDeviceContainer terminaldevices283;
	ns3::NetDeviceContainer terminaldevices285;
	ns3::NetDeviceContainer terminaldevices286;
	ns3::NetDeviceContainer terminaldevices287;
	ns3::NetDeviceContainer terminaldevices288;
	ns3::NetDeviceContainer terminaldevices289;
	ns3::NetDeviceContainer terminaldevices290;
	ns3::NetDeviceContainer terminaldevices291;
	ns3::NetDeviceContainer terminaldevices292;
	ns3::NetDeviceContainer terminaldevices293;
	ns3::NetDeviceContainer terminaldevices294;
	ns3::NetDeviceContainer terminaldevices295;
	ns3::NetDeviceContainer terminaldevices296;
	ns3::NetDeviceContainer terminaldevices297;
	ns3::NetDeviceContainer terminaldevices298;
	ns3::NetDeviceContainer terminaldevices299;
	ns3::NetDeviceContainer terminaldevices300;
	ns3::NetDeviceContainer terminaldevices301;
	ns3::NetDeviceContainer terminaldevices302;
	ns3::NetDeviceContainer terminaldevices303;
	ns3::NetDeviceContainer terminaldevices304;
	ns3::NetDeviceContainer terminaldevices305;
	ns3::NetDeviceContainer terminaldevices306;
	ns3::NetDeviceContainer terminaldevices307;
	ns3::NetDeviceContainer terminaldevices308;
	ns3::NetDeviceContainer terminaldevices309;
	ns3::NetDeviceContainer terminaldevices310;
	ns3::NetDeviceContainer terminaldevices311;
	ns3::NetDeviceContainer terminaldevices312;
	ns3::NetDeviceContainer terminaldevices313;
	ns3::NetDeviceContainer terminaldevices314;
	ns3::NetDeviceContainer terminaldevices315;
	ns3::NetDeviceContainer terminaldevices316;
	ns3::NetDeviceContainer terminaldevices317;
	ns3::NetDeviceContainer terminaldevices318;
	ns3::NetDeviceContainer terminaldevices319;
	ns3::NetDeviceContainer terminaldevices320;
	ns3::NetDeviceContainer terminaldevices321;
	ns3::NetDeviceContainer terminaldevices322;
	ns3::NetDeviceContainer terminaldevices323;
	ns3::NetDeviceContainer terminaldevices324;
	ns3::NetDeviceContainer terminaldevices325;
	ns3::NetDeviceContainer terminaldevices326;
	ns3::NetDeviceContainer terminaldevices327;
	ns3::NetDeviceContainer terminaldevices328;
	ns3::NetDeviceContainer terminaldevices329;
	ns3::NetDeviceContainer terminaldevices330;
	ns3::NetDeviceContainer terminaldevices331;
	ns3::NetDeviceContainer terminaldevices332;
	ns3::NetDeviceContainer terminaldevices334;
	ns3::NetDeviceContainer terminaldevices335;
	ns3::NetDeviceContainer terminaldevices336;
	ns3::NetDeviceContainer terminaldevices337;
	ns3::NetDeviceContainer terminaldevices338;
	ns3::NetDeviceContainer terminaldevices339;
	ns3::NetDeviceContainer terminaldevices340;
	ns3::NetDeviceContainer terminaldevices341;
	ns3::NetDeviceContainer terminaldevices342;
	ns3::NetDeviceContainer terminaldevices343;
	ns3::NetDeviceContainer terminaldevices344;
	ns3::NetDeviceContainer terminaldevices345;
	ns3::NetDeviceContainer terminaldevices346;
	ns3::NetDeviceContainer terminaldevices347;
	ns3::NetDeviceContainer terminaldevices348;
	ns3::NetDeviceContainer apdevices1;
	ns3::NetDeviceContainer apdevices2;
	ns3::NetDeviceContainer apdevices3;
	ns3::NetDeviceContainer apdevices4;
	ns3::NetDeviceContainer apdevices5;
	ns3::NetDeviceContainer apdevices6;
	ns3::NetDeviceContainer apdevices7;
	ns3::NetDeviceContainer apdevices8;
	ns3::NetDeviceContainer apdevices9;
	ns3::NetDeviceContainer apdevices10;
	ns3::NetDeviceContainer apdevices11;
	ns3::NetDeviceContainer apdevices12;
	ns3::NetDeviceContainer apdevices13;
	ns3::NetDeviceContainer apdevices14;
	ns3::NetDeviceContainer apdevices15;
	ns3::NetDeviceContainer apdevices16;
	ns3::NetDeviceContainer apdevices17;
	ns3::NetDeviceContainer apdevices18;
	ns3::NetDeviceContainer apdevices19;
	ns3::NetDeviceContainer apdevices20;
	ns3::NetDeviceContainer apdevices21;
	ns3::NetDeviceContainer apdevices22;
	ns3::NetDeviceContainer apdevices23;
	ns3::NetDeviceContainer apdevices24;
	ns3::NetDeviceContainer apdevices25;
	ns3::NetDeviceContainer apdevices26;
	ns3::NetDeviceContainer apdevices27;
	ns3::NetDeviceContainer apdevices28;
	ns3::NetDeviceContainer apdevices29;
	ns3::NetDeviceContainer apdevices30;
	ns3::NetDeviceContainer apdevices31;
	ns3::NetDeviceContainer apdevices32;
	ns3::NetDeviceContainer apdevices33;
	ns3::NetDeviceContainer apdevices34;
	ns3::NetDeviceContainer apdevices35;
	ns3::NetDeviceContainer apdevices36;
	ns3::NetDeviceContainer apdevices37;
	ns3::NetDeviceContainer apdevices38;
	ns3::NetDeviceContainer apdevices313;
	ns3::NetDeviceContainer apdevices39;
	ns3::NetDeviceContainer apdevices40;
	ns3::NetDeviceContainer apdevices41;
	ns3::NetDeviceContainer apdevices42;
	ns3::NetDeviceContainer apdevices43;
	ns3::NetDeviceContainer apdevices44;
	ns3::NetDeviceContainer apdevices45;
	ns3::NetDeviceContainer apdevices46;
	ns3::NetDeviceContainer apdevices47;
	ns3::NetDeviceContainer apdevices48;
	ns3::NetDeviceContainer apdevices49;
	ns3::NetDeviceContainer apdevices50;
	ns3::NetDeviceContainer apdevices51;
	ns3::NetDeviceContainer apdevices52;
	ns3::NetDeviceContainer apdevices53;
	ns3::NetDeviceContainer apdevices54;
	ns3::NetDeviceContainer apdevices55;
	ns3::NetDeviceContainer apdevices56;
	ns3::NetDeviceContainer apdevices57;
	ns3::NetDeviceContainer apdevices58;
	ns3::NetDeviceContainer apdevices59;
	ns3::NetDeviceContainer apdevices60;
	ns3::NetDeviceContainer apdevices61;
	ns3::NetDeviceContainer apdevices62;
	ns3::NetDeviceContainer apdevices63;
	ns3::NetDeviceContainer apdevices64;
	ns3::NetDeviceContainer apdevices65;
	ns3::NetDeviceContainer apdevices66;
	ns3::NetDeviceContainer apdevices67;
	ns3::NetDeviceContainer apdevices68;
	ns3::NetDeviceContainer apdevices69;
	ns3::NetDeviceContainer apdevices70;
	ns3::NetDeviceContainer apdevices71;
	ns3::NetDeviceContainer apdevices72;
	ns3::NetDeviceContainer apdevices73;
	ns3::NetDeviceContainer apdevices74;
	ns3::NetDeviceContainer apdevices75;
	ns3::NetDeviceContainer apdevices76;
	ns3::NetDeviceContainer apdevices77;
	ns3::NetDeviceContainer apdevices78;
	ns3::NetDeviceContainer apdevices79;
	ns3::NetDeviceContainer apdevices80;
	ns3::NetDeviceContainer apdevices81;
	ns3::NetDeviceContainer apdevices82;
	ns3::NetDeviceContainer apdevices83;
	ns3::NetDeviceContainer apdevices84;
	ns3::NetDeviceContainer apdevices85;
	ns3::NetDeviceContainer apdevices86;
	ns3::NetDeviceContainer apdevices87;
	ns3::NetDeviceContainer apdevices88;
	ns3::NetDeviceContainer apdevices89;
	ns3::NetDeviceContainer apdevices90;
	ns3::NetDeviceContainer apdevices91;
	ns3::NetDeviceContainer apdevices92;
	ns3::NetDeviceContainer apdevices93;
	ns3::NetDeviceContainer apdevices94;
	ns3::NetDeviceContainer apdevices95;
	ns3::NetDeviceContainer apdevices96;
	ns3::NetDeviceContainer apdevices97;
	ns3::NetDeviceContainer apdevices98;
	ns3::NetDeviceContainer apdevices99;
	ns3::NetDeviceContainer apdevices100;
	ns3::NetDeviceContainer apdevices101;
	ns3::NetDeviceContainer apdevices102;
	ns3::NetDeviceContainer apdevices103;
	ns3::NetDeviceContainer apdevices104;
	ns3::NetDeviceContainer apdevices105;
	ns3::NetDeviceContainer apdevices106;
	ns3::NetDeviceContainer apdevices107;
	ns3::NetDeviceContainer apdevices108;
	ns3::NetDeviceContainer apdevices109;
	ns3::NetDeviceContainer apdevices110;
	ns3::NetDeviceContainer apdevices111;
	ns3::NetDeviceContainer apdevices112;
	ns3::NetDeviceContainer apdevices113;
	ns3::NetDeviceContainer apdevices114;
	ns3::NetDeviceContainer apdevices115;
	ns3::NetDeviceContainer apdevices116;
	ns3::NetDeviceContainer apdevices117;
	ns3::NetDeviceContainer apdevices118;
	ns3::NetDeviceContainer apdevices119;
	ns3::NetDeviceContainer apdevices120;
	ns3::NetDeviceContainer apdevices121;
	ns3::NetDeviceContainer apdevices122;
	ns3::NetDeviceContainer apdevices123;
	ns3::NetDeviceContainer apdevices124;
	ns3::NetDeviceContainer apdevices125;
	ns3::NetDeviceContainer apdevices126;
	ns3::NetDeviceContainer apdevices127;
	ns3::NetDeviceContainer apdevices128;
	ns3::NetDeviceContainer apdevices129;
	ns3::NetDeviceContainer apdevices130;
	ns3::NetDeviceContainer apdevices131;
	ns3::NetDeviceContainer apdevices132;
	ns3::NetDeviceContainer apdevices133;
	ns3::NetDeviceContainer apdevices134;
	ns3::NetDeviceContainer apdevices135;
	ns3::NetDeviceContainer apdevices136;
	ns3::NetDeviceContainer apdevices137;
	ns3::NetDeviceContainer apdevices138;
	ns3::NetDeviceContainer apdevices139;
	ns3::NetDeviceContainer apdevices140;
	ns3::NetDeviceContainer apdevices141;
	ns3::NetDeviceContainer apdevices142;
	ns3::NetDeviceContainer apdevices143;
	ns3::NetDeviceContainer apdevices144;
	ns3::NetDeviceContainer apdevices145;
	ns3::NetDeviceContainer apdevices146;
	ns3::NetDeviceContainer apdevices147;
	ns3::NetDeviceContainer apdevices148;
	ns3::NetDeviceContainer apdevices149;
	ns3::NetDeviceContainer apdevices150;
	ns3::NetDeviceContainer apdevices151;
	ns3::NetDeviceContainer apdevices152;
	ns3::NetDeviceContainer apdevices153;
	ns3::NetDeviceContainer apdevices154;
	ns3::NetDeviceContainer apdevices155;
	ns3::NetDeviceContainer apdevices156;
	ns3::NetDeviceContainer apdevices157;
	ns3::NetDeviceContainer apdevices158;
	ns3::NetDeviceContainer apdevices159;
	ns3::NetDeviceContainer apdevices160;
	ns3::NetDeviceContainer apdevices161;
	ns3::NetDeviceContainer apdevices162;
	ns3::NetDeviceContainer apdevices163;
	ns3::NetDeviceContainer apdevices164;
	ns3::NetDeviceContainer apdevices165;
	ns3::NetDeviceContainer apdevices166;
	ns3::NetDeviceContainer apdevices167;
	ns3::NetDeviceContainer apdevices168;
	ns3::NetDeviceContainer apdevices169;
	ns3::NetDeviceContainer apdevices170;
	ns3::NetDeviceContainer apdevices171;
	ns3::NetDeviceContainer apdevices172;
	ns3::NetDeviceContainer apdevices173;
	ns3::NetDeviceContainer apdevices174;
	ns3::NetDeviceContainer apdevices175;
	ns3::NetDeviceContainer apdevices176;
	ns3::NetDeviceContainer apdevices177;
	ns3::NetDeviceContainer apdevices178;
	ns3::NetDeviceContainer apdevices179;
	ns3::NetDeviceContainer apdevices180;
	ns3::NetDeviceContainer apdevices181;
	ns3::NetDeviceContainer apdevices182;
	ns3::NetDeviceContainer apdevices183;
	ns3::NetDeviceContainer apdevices184;
	ns3::NetDeviceContainer apdevices185;
	ns3::NetDeviceContainer apdevices186;
	ns3::NetDeviceContainer apdevices187;
	ns3::NetDeviceContainer apdevices188;
	ns3::NetDeviceContainer apdevices189;
	ns3::NetDeviceContainer apdevices190;
	ns3::NetDeviceContainer apdevices191;
	ns3::NetDeviceContainer apdevices192;
	ns3::NetDeviceContainer apdevices193;
	ns3::NetDeviceContainer apdevices194;
	ns3::NetDeviceContainer apdevices195;
	ns3::NetDeviceContainer apdevices196;
	ns3::NetDeviceContainer apdevices197;
	ns3::NetDeviceContainer apdevices198;
	ns3::NetDeviceContainer apdevices199;
	ns3::NetDeviceContainer apdevices200;
	ns3::NetDeviceContainer apdevices201;
	ns3::NetDeviceContainer apdevices202;
	ns3::NetDeviceContainer apdevices203;
	ns3::NetDeviceContainer apdevices204;
	ns3::NetDeviceContainer apdevices205;
	ns3::NetDeviceContainer apdevices206;
	ns3::NetDeviceContainer apdevices207;
	ns3::NetDeviceContainer apdevices208;
	ns3::NetDeviceContainer apdevices209;
	ns3::NetDeviceContainer apdevices210;
	ns3::NetDeviceContainer apdevices211;
	ns3::NetDeviceContainer apdevices212;
	ns3::NetDeviceContainer apdevices213;
	ns3::NetDeviceContainer apdevices214;
	ns3::NetDeviceContainer apdevices215;
	ns3::NetDeviceContainer apdevices216;
	ns3::NetDeviceContainer apdevices217;
	ns3::NetDeviceContainer apdevices218;
	ns3::NetDeviceContainer apdevices219;
	ns3::NetDeviceContainer apdevices220;
	ns3::NetDeviceContainer apdevices221;
	ns3::NetDeviceContainer apdevices222;
	ns3::NetDeviceContainer apdevices223;
	ns3::NetDeviceContainer apdevices224;
	ns3::NetDeviceContainer apdevices225;
	ns3::NetDeviceContainer apdevices226;
	ns3::NetDeviceContainer apdevices227;
	ns3::NetDeviceContainer apdevices228;
	ns3::NetDeviceContainer apdevices229;
	ns3::NetDeviceContainer apdevices230;
	ns3::NetDeviceContainer apdevices231;
	ns3::NetDeviceContainer apdevices232;
	ns3::NetDeviceContainer apdevices233;
	ns3::NetDeviceContainer apdevices234;
	ns3::NetDeviceContainer apdevices235;
	ns3::NetDeviceContainer apdevices236;
	ns3::NetDeviceContainer apdevices237;
	ns3::NetDeviceContainer apdevices238;
	ns3::NetDeviceContainer apdevices239;
	ns3::NetDeviceContainer apdevices240;
	ns3::NetDeviceContainer apdevices241;
	ns3::NetDeviceContainer apdevices242;
	ns3::NetDeviceContainer apdevices243;
	ns3::NetDeviceContainer apdevices244;
	ns3::NetDeviceContainer apdevices245;
	ns3::NetDeviceContainer apdevices246;
	ns3::NetDeviceContainer apdevices247;
	ns3::NetDeviceContainer apdevices248;
	ns3::NetDeviceContainer apdevices284;
	ns3::NetDeviceContainer apdevices249;
	ns3::NetDeviceContainer apdevices250;
	ns3::NetDeviceContainer apdevices251;
	ns3::NetDeviceContainer apdevices252;
	ns3::NetDeviceContainer apdevices253;
	ns3::NetDeviceContainer apdevices254;
	ns3::NetDeviceContainer apdevices255;
	ns3::NetDeviceContainer apdevices256;
	ns3::NetDeviceContainer apdevices257;
	ns3::NetDeviceContainer apdevices258;
	ns3::NetDeviceContainer apdevices259;
	ns3::NetDeviceContainer apdevices260;
	ns3::NetDeviceContainer apdevices261;
	ns3::NetDeviceContainer apdevices262;
	ns3::NetDeviceContainer apdevices263;
	ns3::NetDeviceContainer apdevices264;
	ns3::NetDeviceContainer apdevices265;
	ns3::NetDeviceContainer apdevices266;
	ns3::NetDeviceContainer apdevices267;
	ns3::NetDeviceContainer apdevices268;
	ns3::NetDeviceContainer apdevices269;
	ns3::NetDeviceContainer apdevices270;
	ns3::NetDeviceContainer apdevices271;
	ns3::NetDeviceContainer apdevices272;
	ns3::NetDeviceContainer apdevices273;
	ns3::NetDeviceContainer apdevices274;
	ns3::NetDeviceContainer apdevices275;
	ns3::NetDeviceContainer apdevices276;
	ns3::NetDeviceContainer apdevices277;
	ns3::NetDeviceContainer apdevices278;
	ns3::NetDeviceContainer apdevices279;
	ns3::NetDeviceContainer apdevices280;
	ns3::NetDeviceContainer apdevices281;
	ns3::NetDeviceContainer apdevices282;
	ns3::NetDeviceContainer apdevices283;
	ns3::NetDeviceContainer apdevices285;
	ns3::NetDeviceContainer apdevices286;
	ns3::NetDeviceContainer apdevices287;
	ns3::NetDeviceContainer apdevices288;
	ns3::NetDeviceContainer apdevices289;
	ns3::NetDeviceContainer apdevices290;
	ns3::NetDeviceContainer apdevices291;
	ns3::NetDeviceContainer apdevices292;
	ns3::NetDeviceContainer apdevices293;
	ns3::NetDeviceContainer apdevices294;
	ns3::NetDeviceContainer apdevices295;
	ns3::NetDeviceContainer apdevices296;
	ns3::NetDeviceContainer apdevices297;
//    apdevices298 = ns.network.NetDeviceContainer()
//    apdevices299 = ns.network.NetDeviceContainer()
	ns3::NetDeviceContainer apdevices300;
	ns3::NetDeviceContainer apdevices301;
	ns3::NetDeviceContainer apdevices302;
	ns3::NetDeviceContainer apdevices303;
	ns3::NetDeviceContainer apdevices304;
	ns3::NetDeviceContainer apdevices305;
//    apdevices306 = ns.network.NetDeviceContainer()
	ns3::NetDeviceContainer apdevices307;
	ns3::NetDeviceContainer apdevices308;
	ns3::NetDeviceContainer apdevices309;
	ns3::NetDeviceContainer apdevices310;
	ns3::NetDeviceContainer apdevices311;
	ns3::NetDeviceContainer apdevices312;
	ns3::NetDeviceContainer apdevices314;
//    apdevices315 = ns.network.NetDeviceContainer()

//wifi
	ns3::WifiHelper Wifi;
	Wifi = ns3::WifiHelper::Default();
	Wifi.SetRemoteStationManager("ns3::ArfWifiManager");

//wifi channel
	ns3::YansWifiChannelHelper wifiChannel;
	wifiChannel = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy;
	wifiPhy = ns3::YansWifiPhyHelper::Default();
	wifiPhy.SetChannel(wifiChannel.Create());

	//wifiChannel = ns.wifi.YansWifiChannelHelper.Default()
	//wifiPhy = ns.wifi.YansWifiPhyHelper.Default()
	//wifiPhy.SetChannel(wifiChannel.Create())

	ns3::YansWifiChannelHelper wifiChannel2;
	wifiChannel2 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy2;
	wifiPhy2 = ns3::YansWifiPhyHelper::Default();
	wifiPhy2.SetChannel(wifiChannel2.Create());

	ns3::YansWifiChannelHelper wifiChannel3;
	wifiChannel3 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy3;
	wifiPhy3 = ns3::YansWifiPhyHelper::Default();
	wifiPhy3.SetChannel(wifiChannel3.Create());

	ns3::YansWifiChannelHelper wifiChannel4;
	wifiChannel4 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy4;
	wifiPhy4 = ns3::YansWifiPhyHelper::Default();
	wifiPhy4.SetChannel(wifiChannel4.Create());

	ns3::YansWifiChannelHelper wifiChannel5;
	wifiChannel5 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy5;
	wifiPhy5 = ns3::YansWifiPhyHelper::Default();
	wifiPhy5.SetChannel(wifiChannel5.Create());

	ns3::YansWifiChannelHelper wifiChannel6;
	wifiChannel6 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy6;
	wifiPhy6 = ns3::YansWifiPhyHelper::Default();
	wifiPhy6.SetChannel(wifiChannel6.Create());

	ns3::YansWifiChannelHelper wifiChannel7;
	wifiChannel7 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy7;
	wifiPhy7 = ns3::YansWifiPhyHelper::Default();
	wifiPhy7.SetChannel(wifiChannel7.Create());

	ns3::YansWifiChannelHelper wifiChannel8;
	wifiChannel8 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy8;
	wifiPhy8 = ns3::YansWifiPhyHelper::Default();
	wifiPhy8.SetChannel(wifiChannel8.Create());

	ns3::YansWifiChannelHelper wifiChannel9;
	wifiChannel9 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy9;
	wifiPhy9 = ns3::YansWifiPhyHelper::Default();
	wifiPhy9.SetChannel(wifiChannel9.Create());

	ns3::YansWifiChannelHelper wifiChannel10;
	wifiChannel10 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy10;
	wifiPhy10 = ns3::YansWifiPhyHelper::Default();
	wifiPhy10.SetChannel(wifiChannel10.Create());

	ns3::YansWifiChannelHelper wifiChannel11;
	wifiChannel11 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy11;
	wifiPhy11 = ns3::YansWifiPhyHelper::Default();
	wifiPhy11.SetChannel(wifiChannel11.Create());

	ns3::YansWifiChannelHelper wifiChannel12;
	wifiChannel12 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy12;
	wifiPhy12 = ns3::YansWifiPhyHelper::Default();
	wifiPhy12.SetChannel(wifiChannel12.Create());

	ns3::YansWifiChannelHelper wifiChannel13;
	wifiChannel13 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy13;
	wifiPhy13 = ns3::YansWifiPhyHelper::Default();
	wifiPhy13.SetChannel(wifiChannel13.Create());

	ns3::YansWifiChannelHelper wifiChannel14;
	wifiChannel14 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy14;
	wifiPhy14 = ns3::YansWifiPhyHelper::Default();
	wifiPhy14.SetChannel(wifiChannel14.Create());

	ns3::YansWifiChannelHelper wifiChannel15;
	wifiChannel15 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy15;
	wifiPhy15 = ns3::YansWifiPhyHelper::Default();
	wifiPhy15.SetChannel(wifiChannel15.Create());

	ns3::YansWifiChannelHelper wifiChannel16;
	wifiChannel16 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy16;
	wifiPhy16 = ns3::YansWifiPhyHelper::Default();
	wifiPhy16.SetChannel(wifiChannel16.Create());

	ns3::YansWifiChannelHelper wifiChannel17;
	wifiChannel17 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy17;
	wifiPhy17 = ns3::YansWifiPhyHelper::Default();
	wifiPhy17.SetChannel(wifiChannel17.Create());

	ns3::YansWifiChannelHelper wifiChannel18;
	wifiChannel18 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy18;
	wifiPhy18 = ns3::YansWifiPhyHelper::Default();
	wifiPhy18.SetChannel(wifiChannel18.Create());

	ns3::YansWifiChannelHelper wifiChannel19;
	wifiChannel19 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy19;
	wifiPhy19 = ns3::YansWifiPhyHelper::Default();
	wifiPhy19.SetChannel(wifiChannel19.Create());

	ns3::YansWifiChannelHelper wifiChannel20;
	wifiChannel20 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy20;
	wifiPhy20 = ns3::YansWifiPhyHelper::Default();
	wifiPhy20.SetChannel(wifiChannel20.Create());

	ns3::YansWifiChannelHelper wifiChannel21;
	wifiChannel21 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy21;
	wifiPhy21 = ns3::YansWifiPhyHelper::Default();
	wifiPhy21.SetChannel(wifiChannel21.Create());

	ns3::YansWifiChannelHelper wifiChannel22;
	wifiChannel22 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy22;
	wifiPhy22 = ns3::YansWifiPhyHelper::Default();
	wifiPhy22.SetChannel(wifiChannel22.Create());

	ns3::YansWifiChannelHelper wifiChannel23;
	wifiChannel23 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy23;
	wifiPhy23 = ns3::YansWifiPhyHelper::Default();
	wifiPhy23.SetChannel(wifiChannel23.Create());

	ns3::YansWifiChannelHelper wifiChannel24;
	wifiChannel24 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy24;
	wifiPhy24 = ns3::YansWifiPhyHelper::Default();
	wifiPhy24.SetChannel(wifiChannel24.Create());

	ns3::YansWifiChannelHelper wifiChannel25;
	wifiChannel25 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy25;
	wifiPhy25 = ns3::YansWifiPhyHelper::Default();
	wifiPhy25.SetChannel(wifiChannel25.Create());

	ns3::YansWifiChannelHelper wifiChannel26;
	wifiChannel26 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy26;
	wifiPhy26 = ns3::YansWifiPhyHelper::Default();
	wifiPhy26.SetChannel(wifiChannel26.Create());

	ns3::YansWifiChannelHelper wifiChannel27;
	wifiChannel27 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy27;
	wifiPhy27 = ns3::YansWifiPhyHelper::Default();
	wifiPhy27.SetChannel(wifiChannel27.Create());

	ns3::YansWifiChannelHelper wifiChannel28;
	wifiChannel28 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy28;
	wifiPhy28 = ns3::YansWifiPhyHelper::Default();
	wifiPhy28.SetChannel(wifiChannel28.Create());

	ns3::YansWifiChannelHelper wifiChannel29;
	wifiChannel29 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy29;
	wifiPhy29 = ns3::YansWifiPhyHelper::Default();
	wifiPhy29.SetChannel(wifiChannel29.Create());

	ns3::YansWifiChannelHelper wifiChannel30;
	wifiChannel30 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy30;
	wifiPhy30 = ns3::YansWifiPhyHelper::Default();
	wifiPhy30.SetChannel(wifiChannel30.Create());

	ns3::YansWifiChannelHelper wifiChannel31;
	wifiChannel31 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy31;
	wifiPhy31 = ns3::YansWifiPhyHelper::Default();
	wifiPhy31.SetChannel(wifiChannel31.Create());

	ns3::YansWifiChannelHelper wifiChannel32;
	wifiChannel32 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy32;
	wifiPhy32 = ns3::YansWifiPhyHelper::Default();
	wifiPhy32.SetChannel(wifiChannel32.Create());

	ns3::YansWifiChannelHelper wifiChannel33;
	wifiChannel33 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy33;
	wifiPhy33 = ns3::YansWifiPhyHelper::Default();
	wifiPhy33.SetChannel(wifiChannel33.Create());

	ns3::YansWifiChannelHelper wifiChannel34;
	wifiChannel34 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy34;
	wifiPhy34 = ns3::YansWifiPhyHelper::Default();
	wifiPhy34.SetChannel(wifiChannel34.Create());

	ns3::YansWifiChannelHelper wifiChannel35;
	wifiChannel35 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy35;
	wifiPhy35 = ns3::YansWifiPhyHelper::Default();
	wifiPhy35.SetChannel(wifiChannel35.Create());

	ns3::YansWifiChannelHelper wifiChannel36;
	wifiChannel36 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy36;
	wifiPhy36 = ns3::YansWifiPhyHelper::Default();
	wifiPhy36.SetChannel(wifiChannel36.Create());

	ns3::YansWifiChannelHelper wifiChannel37;
	wifiChannel37 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy37;
	wifiPhy37 = ns3::YansWifiPhyHelper::Default();
	wifiPhy37.SetChannel(wifiChannel37.Create());

	ns3::YansWifiChannelHelper wifiChannel38;
	wifiChannel38 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy38;
	wifiPhy38 = ns3::YansWifiPhyHelper::Default();
	wifiPhy38.SetChannel(wifiChannel38.Create());

	ns3::YansWifiChannelHelper wifiChannel39;
	wifiChannel39 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy39;
	wifiPhy39 = ns3::YansWifiPhyHelper::Default();
	wifiPhy39.SetChannel(wifiChannel39.Create());

	ns3::YansWifiChannelHelper wifiChannel40;
	wifiChannel40 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy40;
	wifiPhy40 = ns3::YansWifiPhyHelper::Default();
	wifiPhy40.SetChannel(wifiChannel40.Create());

	ns3::YansWifiChannelHelper wifiChannel41;
	wifiChannel41 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy41;
	wifiPhy41 = ns3::YansWifiPhyHelper::Default();
	wifiPhy41.SetChannel(wifiChannel41.Create());

	ns3::YansWifiChannelHelper wifiChannel42;
	wifiChannel42 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy42;
	wifiPhy42 = ns3::YansWifiPhyHelper::Default();
	wifiPhy42.SetChannel(wifiChannel42.Create());

	ns3::YansWifiChannelHelper wifiChannel43;
	wifiChannel43 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy43;
	wifiPhy43 = ns3::YansWifiPhyHelper::Default();
	wifiPhy43.SetChannel(wifiChannel43.Create());

	ns3::YansWifiChannelHelper wifiChannel44;
	wifiChannel44 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy44;
	wifiPhy44 = ns3::YansWifiPhyHelper::Default();
	wifiPhy44.SetChannel(wifiChannel44.Create());

	ns3::YansWifiChannelHelper wifiChannel45;
	wifiChannel45 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy45;
	wifiPhy45 = ns3::YansWifiPhyHelper::Default();
	wifiPhy45.SetChannel(wifiChannel45.Create());

	ns3::YansWifiChannelHelper wifiChannel46;
	wifiChannel46 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy46;
	wifiPhy46 = ns3::YansWifiPhyHelper::Default();
	wifiPhy46.SetChannel(wifiChannel46.Create());

	ns3::YansWifiChannelHelper wifiChannel47;
	wifiChannel47 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy47;
	wifiPhy47 = ns3::YansWifiPhyHelper::Default();
	wifiPhy47.SetChannel(wifiChannel47.Create());

	ns3::YansWifiChannelHelper wifiChannel48;
	wifiChannel48 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy48;
	wifiPhy48 = ns3::YansWifiPhyHelper::Default();
	wifiPhy48.SetChannel(wifiChannel48.Create());

	ns3::YansWifiChannelHelper wifiChannel49;
	wifiChannel49 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy49;
	wifiPhy49 = ns3::YansWifiPhyHelper::Default();
	wifiPhy49.SetChannel(wifiChannel49.Create());

	ns3::YansWifiChannelHelper wifiChannel50;
	wifiChannel50 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy50;
	wifiPhy50 = ns3::YansWifiPhyHelper::Default();
	wifiPhy50.SetChannel(wifiChannel50.Create());

	ns3::YansWifiChannelHelper wifiChannel51;
	wifiChannel51 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy51;
	wifiPhy51 = ns3::YansWifiPhyHelper::Default();
	wifiPhy51.SetChannel(wifiChannel51.Create());

	ns3::YansWifiChannelHelper wifiChannel52;
	wifiChannel52 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy52;
	wifiPhy52 = ns3::YansWifiPhyHelper::Default();
	wifiPhy52.SetChannel(wifiChannel52.Create());

	ns3::YansWifiChannelHelper wifiChannel53;
	wifiChannel53 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy53;
	wifiPhy53 = ns3::YansWifiPhyHelper::Default();
	wifiPhy53.SetChannel(wifiChannel53.Create());

	ns3::YansWifiChannelHelper wifiChannel54;
	wifiChannel54 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy54;
	wifiPhy54 = ns3::YansWifiPhyHelper::Default();
	wifiPhy54.SetChannel(wifiChannel54.Create());

	ns3::YansWifiChannelHelper wifiChannel55;
	wifiChannel55 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy55;
	wifiPhy55 = ns3::YansWifiPhyHelper::Default();
	wifiPhy55.SetChannel(wifiChannel55.Create());

	ns3::YansWifiChannelHelper wifiChannel56;
	wifiChannel56 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy56;
	wifiPhy56 = ns3::YansWifiPhyHelper::Default();
	wifiPhy56.SetChannel(wifiChannel56.Create());

	ns3::YansWifiChannelHelper wifiChannel57;
	wifiChannel57 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy57;
	wifiPhy57 = ns3::YansWifiPhyHelper::Default();
	wifiPhy57.SetChannel(wifiChannel57.Create());

	ns3::YansWifiChannelHelper wifiChannel58;
	wifiChannel58 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy58;
	wifiPhy58 = ns3::YansWifiPhyHelper::Default();
	wifiPhy58.SetChannel(wifiChannel58.Create());

	ns3::YansWifiChannelHelper wifiChannel59;
	wifiChannel59 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy59;
	wifiPhy59 = ns3::YansWifiPhyHelper::Default();
	wifiPhy59.SetChannel(wifiChannel59.Create());

	ns3::YansWifiChannelHelper wifiChannel60;
	wifiChannel60 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy60;
	wifiPhy60 = ns3::YansWifiPhyHelper::Default();
	wifiPhy60.SetChannel(wifiChannel60.Create());

	ns3::YansWifiChannelHelper wifiChannel61;
	wifiChannel61 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy61;
	wifiPhy61 = ns3::YansWifiPhyHelper::Default();
	wifiPhy61.SetChannel(wifiChannel61.Create());

	ns3::YansWifiChannelHelper wifiChannel62;
	wifiChannel62 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy62;
	wifiPhy62 = ns3::YansWifiPhyHelper::Default();
	wifiPhy62.SetChannel(wifiChannel62.Create());

	ns3::YansWifiChannelHelper wifiChannel63;
	wifiChannel63 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy63;
	wifiPhy63 = ns3::YansWifiPhyHelper::Default();
	wifiPhy63.SetChannel(wifiChannel63.Create());

	ns3::YansWifiChannelHelper wifiChannel64;
	wifiChannel64 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy64;
	wifiPhy64 = ns3::YansWifiPhyHelper::Default();
	wifiPhy64.SetChannel(wifiChannel64.Create());

	ns3::YansWifiChannelHelper wifiChannel65;
	wifiChannel65 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy65;
	wifiPhy65 = ns3::YansWifiPhyHelper::Default();
	wifiPhy65.SetChannel(wifiChannel65.Create());

	ns3::YansWifiChannelHelper wifiChannel66;
	wifiChannel66 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy66;
	wifiPhy66 = ns3::YansWifiPhyHelper::Default();
	wifiPhy66.SetChannel(wifiChannel66.Create());

	ns3::YansWifiChannelHelper wifiChannel67;
	wifiChannel67 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy67;
	wifiPhy67 = ns3::YansWifiPhyHelper::Default();
	wifiPhy67.SetChannel(wifiChannel67.Create());

	ns3::YansWifiChannelHelper wifiChannel68;
	wifiChannel68 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy68;
	wifiPhy68 = ns3::YansWifiPhyHelper::Default();
	wifiPhy68.SetChannel(wifiChannel68.Create());

	ns3::YansWifiChannelHelper wifiChannel69;
	wifiChannel69 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy69;
	wifiPhy69 = ns3::YansWifiPhyHelper::Default();
	wifiPhy69.SetChannel(wifiChannel69.Create());

	ns3::YansWifiChannelHelper wifiChannel70;
	wifiChannel70 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy70;
	wifiPhy70 = ns3::YansWifiPhyHelper::Default();
	wifiPhy70.SetChannel(wifiChannel70.Create());

	ns3::YansWifiChannelHelper wifiChannel71;
	wifiChannel71 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy71;
	wifiPhy71 = ns3::YansWifiPhyHelper::Default();
	wifiPhy71.SetChannel(wifiChannel71.Create());

	ns3::YansWifiChannelHelper wifiChannel72;
	wifiChannel72 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy72;
	wifiPhy72 = ns3::YansWifiPhyHelper::Default();
	wifiPhy72.SetChannel(wifiChannel72.Create());

	ns3::YansWifiChannelHelper wifiChannel73;
	wifiChannel73 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy73;
	wifiPhy73 = ns3::YansWifiPhyHelper::Default();
	wifiPhy73.SetChannel(wifiChannel73.Create());

	ns3::YansWifiChannelHelper wifiChannel74;
	wifiChannel74 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy74;
	wifiPhy74 = ns3::YansWifiPhyHelper::Default();
	wifiPhy74.SetChannel(wifiChannel74.Create());

	ns3::YansWifiChannelHelper wifiChannel75;
	wifiChannel75 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy75;
	wifiPhy75 = ns3::YansWifiPhyHelper::Default();
	wifiPhy75.SetChannel(wifiChannel75.Create());

	ns3::YansWifiChannelHelper wifiChannel76;
	wifiChannel76 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy76;
	wifiPhy76 = ns3::YansWifiPhyHelper::Default();
	wifiPhy76.SetChannel(wifiChannel76.Create());

	ns3::YansWifiChannelHelper wifiChannel77;
	wifiChannel77 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy77;
	wifiPhy77 = ns3::YansWifiPhyHelper::Default();
	wifiPhy77.SetChannel(wifiChannel77.Create());

	ns3::YansWifiChannelHelper wifiChannel78;
	wifiChannel78 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy78;
	wifiPhy78 = ns3::YansWifiPhyHelper::Default();
	wifiPhy78.SetChannel(wifiChannel78.Create());

	ns3::YansWifiChannelHelper wifiChannel79;
	wifiChannel79 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy79;
	wifiPhy79 = ns3::YansWifiPhyHelper::Default();
	wifiPhy79.SetChannel(wifiChannel79.Create());

	ns3::YansWifiChannelHelper wifiChannel80;
	wifiChannel80 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy80;
	wifiPhy80 = ns3::YansWifiPhyHelper::Default();
	wifiPhy80.SetChannel(wifiChannel80.Create());

	ns3::YansWifiChannelHelper wifiChannel81;
	wifiChannel81 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy81;
	wifiPhy81 = ns3::YansWifiPhyHelper::Default();
	wifiPhy81.SetChannel(wifiChannel81.Create());

	ns3::YansWifiChannelHelper wifiChannel82;
	wifiChannel82 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy82;
	wifiPhy82 = ns3::YansWifiPhyHelper::Default();
	wifiPhy82.SetChannel(wifiChannel82.Create());

	ns3::YansWifiChannelHelper wifiChannel83;
	wifiChannel83 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy83;
	wifiPhy83 = ns3::YansWifiPhyHelper::Default();
	wifiPhy83.SetChannel(wifiChannel83.Create());

	ns3::YansWifiChannelHelper wifiChannel84;
	wifiChannel84 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy84;
	wifiPhy84 = ns3::YansWifiPhyHelper::Default();
	wifiPhy84.SetChannel(wifiChannel84.Create());

	ns3::YansWifiChannelHelper wifiChannel85;
	wifiChannel85 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy85;
	wifiPhy85 = ns3::YansWifiPhyHelper::Default();
	wifiPhy85.SetChannel(wifiChannel85.Create());

	ns3::YansWifiChannelHelper wifiChannel86;
	wifiChannel86 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy86;
	wifiPhy86 = ns3::YansWifiPhyHelper::Default();
	wifiPhy86.SetChannel(wifiChannel86.Create());

	ns3::YansWifiChannelHelper wifiChannel87;
	wifiChannel87 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy87;
	wifiPhy87 = ns3::YansWifiPhyHelper::Default();
	wifiPhy87.SetChannel(wifiChannel87.Create());

	ns3::YansWifiChannelHelper wifiChannel88;
	wifiChannel88 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy88;
	wifiPhy88 = ns3::YansWifiPhyHelper::Default();
	wifiPhy88.SetChannel(wifiChannel88.Create());

	ns3::YansWifiChannelHelper wifiChannel89;
	wifiChannel89 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy89;
	wifiPhy89 = ns3::YansWifiPhyHelper::Default();
	wifiPhy89.SetChannel(wifiChannel89.Create());

	ns3::YansWifiChannelHelper wifiChannel90;
	wifiChannel90 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy90;
	wifiPhy90 = ns3::YansWifiPhyHelper::Default();
	wifiPhy90.SetChannel(wifiChannel90.Create());

	ns3::YansWifiChannelHelper wifiChannel91;
	wifiChannel91 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy91;
	wifiPhy91 = ns3::YansWifiPhyHelper::Default();
	wifiPhy91.SetChannel(wifiChannel91.Create());

	ns3::YansWifiChannelHelper wifiChannel92;
	wifiChannel92 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy92;
	wifiPhy92 = ns3::YansWifiPhyHelper::Default();
	wifiPhy92.SetChannel(wifiChannel92.Create());

	ns3::YansWifiChannelHelper wifiChannel93;
	wifiChannel93 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy93;
	wifiPhy93 = ns3::YansWifiPhyHelper::Default();
	wifiPhy93.SetChannel(wifiChannel93.Create());

	ns3::YansWifiChannelHelper wifiChannel94;
	wifiChannel94 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy94;
	wifiPhy94 = ns3::YansWifiPhyHelper::Default();
	wifiPhy94.SetChannel(wifiChannel94.Create());

	ns3::YansWifiChannelHelper wifiChannel95;
	wifiChannel95 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy95;
	wifiPhy95 = ns3::YansWifiPhyHelper::Default();
	wifiPhy95.SetChannel(wifiChannel95.Create());

	ns3::YansWifiChannelHelper wifiChannel96;
	wifiChannel96 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy96;
	wifiPhy96 = ns3::YansWifiPhyHelper::Default();
	wifiPhy96.SetChannel(wifiChannel96.Create());

	ns3::YansWifiChannelHelper wifiChannel97;
	wifiChannel97 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy97;
	wifiPhy97 = ns3::YansWifiPhyHelper::Default();
	wifiPhy97.SetChannel(wifiChannel97.Create());

	ns3::YansWifiChannelHelper wifiChannel98;
	wifiChannel98 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy98;
	wifiPhy98 = ns3::YansWifiPhyHelper::Default();
	wifiPhy98.SetChannel(wifiChannel98.Create());

	ns3::YansWifiChannelHelper wifiChannel99;
	wifiChannel99 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy99;
	wifiPhy99 = ns3::YansWifiPhyHelper::Default();
	wifiPhy99.SetChannel(wifiChannel99.Create());

	ns3::YansWifiChannelHelper wifiChannel100;
	wifiChannel100 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy100;
	wifiPhy100 = ns3::YansWifiPhyHelper::Default();
	wifiPhy100.SetChannel(wifiChannel100.Create());

	ns3::YansWifiChannelHelper wifiChannel101;
	wifiChannel101 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy101;
	wifiPhy101 = ns3::YansWifiPhyHelper::Default();
	wifiPhy101.SetChannel(wifiChannel101.Create());

	ns3::YansWifiChannelHelper wifiChannel102;
	wifiChannel102 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy102;
	wifiPhy102 = ns3::YansWifiPhyHelper::Default();
	wifiPhy102.SetChannel(wifiChannel102.Create());

	ns3::YansWifiChannelHelper wifiChannel103;
	wifiChannel103 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy103;
	wifiPhy103 = ns3::YansWifiPhyHelper::Default();
	wifiPhy103.SetChannel(wifiChannel103.Create());

	ns3::YansWifiChannelHelper wifiChannel104;
	wifiChannel104 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy104;
	wifiPhy104 = ns3::YansWifiPhyHelper::Default();
	wifiPhy104.SetChannel(wifiChannel104.Create());

	ns3::YansWifiChannelHelper wifiChannel105;
	wifiChannel105 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy105;
	wifiPhy105 = ns3::YansWifiPhyHelper::Default();
	wifiPhy105.SetChannel(wifiChannel105.Create());

	ns3::YansWifiChannelHelper wifiChannel106;
	wifiChannel106 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy106;
	wifiPhy106 = ns3::YansWifiPhyHelper::Default();
	wifiPhy106.SetChannel(wifiChannel106.Create());

	ns3::YansWifiChannelHelper wifiChannel107;
	wifiChannel107 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy107;
	wifiPhy107 = ns3::YansWifiPhyHelper::Default();
	wifiPhy107.SetChannel(wifiChannel107.Create());

	ns3::YansWifiChannelHelper wifiChannel108;
	wifiChannel108 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy108;
	wifiPhy108 = ns3::YansWifiPhyHelper::Default();
	wifiPhy108.SetChannel(wifiChannel108.Create());

	ns3::YansWifiChannelHelper wifiChannel109;
	wifiChannel109 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy109;
	wifiPhy109 = ns3::YansWifiPhyHelper::Default();
	wifiPhy109.SetChannel(wifiChannel109.Create());

	ns3::YansWifiChannelHelper wifiChannel110;
	wifiChannel110 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy110;
	wifiPhy110 = ns3::YansWifiPhyHelper::Default();
	wifiPhy110.SetChannel(wifiChannel110.Create());

	ns3::YansWifiChannelHelper wifiChannel111;
	wifiChannel111 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy111;
	wifiPhy111 = ns3::YansWifiPhyHelper::Default();
	wifiPhy111.SetChannel(wifiChannel111.Create());

	ns3::YansWifiChannelHelper wifiChannel112;
	wifiChannel112 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy112;
	wifiPhy112 = ns3::YansWifiPhyHelper::Default();
	wifiPhy112.SetChannel(wifiChannel112.Create());

	ns3::YansWifiChannelHelper wifiChannel113;
	wifiChannel113 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy113;
	wifiPhy113 = ns3::YansWifiPhyHelper::Default();
	wifiPhy113.SetChannel(wifiChannel113.Create());

	ns3::YansWifiChannelHelper wifiChannel114;
	wifiChannel114 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy114;
	wifiPhy114 = ns3::YansWifiPhyHelper::Default();
	wifiPhy114.SetChannel(wifiChannel114.Create());

	ns3::YansWifiChannelHelper wifiChannel115;
	wifiChannel115 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy115;
	wifiPhy115 = ns3::YansWifiPhyHelper::Default();
	wifiPhy115.SetChannel(wifiChannel115.Create());

	ns3::YansWifiChannelHelper wifiChannel116;
	wifiChannel116 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy116;
	wifiPhy116 = ns3::YansWifiPhyHelper::Default();
	wifiPhy116.SetChannel(wifiChannel116.Create());

	ns3::YansWifiChannelHelper wifiChannel117;
	wifiChannel117 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy117;
	wifiPhy117 = ns3::YansWifiPhyHelper::Default();
	wifiPhy117.SetChannel(wifiChannel117.Create());

	ns3::YansWifiChannelHelper wifiChannel118;
	wifiChannel118 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy118;
	wifiPhy118 = ns3::YansWifiPhyHelper::Default();
	wifiPhy118.SetChannel(wifiChannel118.Create());

	ns3::YansWifiChannelHelper wifiChannel119;
	wifiChannel119 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy119;
	wifiPhy119 = ns3::YansWifiPhyHelper::Default();
	wifiPhy119.SetChannel(wifiChannel119.Create());

	ns3::YansWifiChannelHelper wifiChannel120;
	wifiChannel120 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy120;
	wifiPhy120 = ns3::YansWifiPhyHelper::Default();
	wifiPhy120.SetChannel(wifiChannel120.Create());

	ns3::YansWifiChannelHelper wifiChannel121;
	wifiChannel121 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy121;
	wifiPhy121 = ns3::YansWifiPhyHelper::Default();
	wifiPhy121.SetChannel(wifiChannel121.Create());

	ns3::YansWifiChannelHelper wifiChannel122;
	wifiChannel122 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy122;
	wifiPhy122 = ns3::YansWifiPhyHelper::Default();
	wifiPhy122.SetChannel(wifiChannel122.Create());

	ns3::YansWifiChannelHelper wifiChannel123;
	wifiChannel123 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy123;
	wifiPhy123 = ns3::YansWifiPhyHelper::Default();
	wifiPhy123.SetChannel(wifiChannel123.Create());

	ns3::YansWifiChannelHelper wifiChannel124;
	wifiChannel124 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy124;
	wifiPhy124 = ns3::YansWifiPhyHelper::Default();
	wifiPhy124.SetChannel(wifiChannel124.Create());

	ns3::YansWifiChannelHelper wifiChannel125;
	wifiChannel125 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy125;
	wifiPhy125 = ns3::YansWifiPhyHelper::Default();
	wifiPhy125.SetChannel(wifiChannel125.Create());

	ns3::YansWifiChannelHelper wifiChannel126;
	wifiChannel126 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy126;
	wifiPhy126 = ns3::YansWifiPhyHelper::Default();
	wifiPhy126.SetChannel(wifiChannel126.Create());

	ns3::YansWifiChannelHelper wifiChannel127;
	wifiChannel127 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy127;
	wifiPhy127 = ns3::YansWifiPhyHelper::Default();
	wifiPhy127.SetChannel(wifiChannel127.Create());

	ns3::YansWifiChannelHelper wifiChannel128;
	wifiChannel128 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy128;
	wifiPhy128 = ns3::YansWifiPhyHelper::Default();
	wifiPhy128.SetChannel(wifiChannel128.Create());

	ns3::YansWifiChannelHelper wifiChannel129;
	wifiChannel129 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy129;
	wifiPhy129 = ns3::YansWifiPhyHelper::Default();
	wifiPhy129.SetChannel(wifiChannel129.Create());

	ns3::YansWifiChannelHelper wifiChannel130;
	wifiChannel130 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy130;
	wifiPhy130 = ns3::YansWifiPhyHelper::Default();
	wifiPhy130.SetChannel(wifiChannel130.Create());

	ns3::YansWifiChannelHelper wifiChannel131;
	wifiChannel131 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy131;
	wifiPhy131 = ns3::YansWifiPhyHelper::Default();
	wifiPhy131.SetChannel(wifiChannel131.Create());

	ns3::YansWifiChannelHelper wifiChannel132;
	wifiChannel132 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy132;
	wifiPhy132 = ns3::YansWifiPhyHelper::Default();
	wifiPhy132.SetChannel(wifiChannel132.Create());

	ns3::YansWifiChannelHelper wifiChannel133;
	wifiChannel133 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy133;
	wifiPhy133 = ns3::YansWifiPhyHelper::Default();
	wifiPhy133.SetChannel(wifiChannel133.Create());

	ns3::YansWifiChannelHelper wifiChannel134;
	wifiChannel134 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy134;
	wifiPhy134 = ns3::YansWifiPhyHelper::Default();
	wifiPhy134.SetChannel(wifiChannel134.Create());

	ns3::YansWifiChannelHelper wifiChannel135;
	wifiChannel135 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy135;
	wifiPhy135 = ns3::YansWifiPhyHelper::Default();
	wifiPhy135.SetChannel(wifiChannel135.Create());

	ns3::YansWifiChannelHelper wifiChannel136;
	wifiChannel136 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy136;
	wifiPhy136 = ns3::YansWifiPhyHelper::Default();
	wifiPhy136.SetChannel(wifiChannel136.Create());

	ns3::YansWifiChannelHelper wifiChannel137;
	wifiChannel137 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy137;
	wifiPhy137 = ns3::YansWifiPhyHelper::Default();
	wifiPhy137.SetChannel(wifiChannel137.Create());

	ns3::YansWifiChannelHelper wifiChannel138;
	wifiChannel138 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy138;
	wifiPhy138 = ns3::YansWifiPhyHelper::Default();
	wifiPhy138.SetChannel(wifiChannel138.Create());

	ns3::YansWifiChannelHelper wifiChannel139;
	wifiChannel139 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy139;
	wifiPhy139 = ns3::YansWifiPhyHelper::Default();
	wifiPhy139.SetChannel(wifiChannel139.Create());

	ns3::YansWifiChannelHelper wifiChannel140;
	wifiChannel140 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy140;
	wifiPhy140 = ns3::YansWifiPhyHelper::Default();
	wifiPhy140.SetChannel(wifiChannel140.Create());

	ns3::YansWifiChannelHelper wifiChannel141;
	wifiChannel141 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy141;
	wifiPhy141 = ns3::YansWifiPhyHelper::Default();
	wifiPhy141.SetChannel(wifiChannel141.Create());

	ns3::YansWifiChannelHelper wifiChannel142;
	wifiChannel142 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy142;
	wifiPhy142 = ns3::YansWifiPhyHelper::Default();
	wifiPhy142.SetChannel(wifiChannel142.Create());

	ns3::YansWifiChannelHelper wifiChannel143;
	wifiChannel143 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy143;
	wifiPhy143 = ns3::YansWifiPhyHelper::Default();
	wifiPhy143.SetChannel(wifiChannel143.Create());

	ns3::YansWifiChannelHelper wifiChannel144;
	wifiChannel144 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy144;
	wifiPhy144 = ns3::YansWifiPhyHelper::Default();
	wifiPhy144.SetChannel(wifiChannel144.Create());

	ns3::YansWifiChannelHelper wifiChannel145;
	wifiChannel145 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy145;
	wifiPhy145 = ns3::YansWifiPhyHelper::Default();
	wifiPhy145.SetChannel(wifiChannel145.Create());

	ns3::YansWifiChannelHelper wifiChannel146;
	wifiChannel146 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy146;
	wifiPhy146 = ns3::YansWifiPhyHelper::Default();
	wifiPhy146.SetChannel(wifiChannel146.Create());

	ns3::YansWifiChannelHelper wifiChannel147;
	wifiChannel147 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy147;
	wifiPhy147 = ns3::YansWifiPhyHelper::Default();
	wifiPhy147.SetChannel(wifiChannel147.Create());

	ns3::YansWifiChannelHelper wifiChannel148;
	wifiChannel148 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy148;
	wifiPhy148 = ns3::YansWifiPhyHelper::Default();
	wifiPhy148.SetChannel(wifiChannel148.Create());

	ns3::YansWifiChannelHelper wifiChannel149;
	wifiChannel149 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy149;
	wifiPhy149 = ns3::YansWifiPhyHelper::Default();
	wifiPhy149.SetChannel(wifiChannel149.Create());

	ns3::YansWifiChannelHelper wifiChannel150;
	wifiChannel150 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy150;
	wifiPhy150 = ns3::YansWifiPhyHelper::Default();
	wifiPhy150.SetChannel(wifiChannel150.Create());

	ns3::YansWifiChannelHelper wifiChannel151;
	wifiChannel151 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy151;
	wifiPhy151 = ns3::YansWifiPhyHelper::Default();
	wifiPhy151.SetChannel(wifiChannel151.Create());

	ns3::YansWifiChannelHelper wifiChannel152;
	wifiChannel152 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy152;
	wifiPhy152 = ns3::YansWifiPhyHelper::Default();
	wifiPhy152.SetChannel(wifiChannel152.Create());

	ns3::YansWifiChannelHelper wifiChannel153;
	wifiChannel153 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy153;
	wifiPhy153 = ns3::YansWifiPhyHelper::Default();
	wifiPhy153.SetChannel(wifiChannel153.Create());

	ns3::YansWifiChannelHelper wifiChannel154;
	wifiChannel154 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy154;
	wifiPhy154 = ns3::YansWifiPhyHelper::Default();
	wifiPhy154.SetChannel(wifiChannel154.Create());

	ns3::YansWifiChannelHelper wifiChannel155;
	wifiChannel155 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy155;
	wifiPhy155 = ns3::YansWifiPhyHelper::Default();
	wifiPhy155.SetChannel(wifiChannel155.Create());

	ns3::YansWifiChannelHelper wifiChannel156;
	wifiChannel156 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy156;
	wifiPhy156 = ns3::YansWifiPhyHelper::Default();
	wifiPhy156.SetChannel(wifiChannel156.Create());

	ns3::YansWifiChannelHelper wifiChannel157;
	wifiChannel157 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy157;
	wifiPhy157 = ns3::YansWifiPhyHelper::Default();
	wifiPhy157.SetChannel(wifiChannel157.Create());

	ns3::YansWifiChannelHelper wifiChannel158;
	wifiChannel158 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy158;
	wifiPhy158 = ns3::YansWifiPhyHelper::Default();
	wifiPhy158.SetChannel(wifiChannel158.Create());

	ns3::YansWifiChannelHelper wifiChannel159;
	wifiChannel159 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy159;
	wifiPhy159 = ns3::YansWifiPhyHelper::Default();
	wifiPhy159.SetChannel(wifiChannel159.Create());

	ns3::YansWifiChannelHelper wifiChannel160;
	wifiChannel160 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy160;
	wifiPhy160 = ns3::YansWifiPhyHelper::Default();
	wifiPhy160.SetChannel(wifiChannel160.Create());

	ns3::YansWifiChannelHelper wifiChannel161;
	wifiChannel161 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy161;
	wifiPhy161 = ns3::YansWifiPhyHelper::Default();
	wifiPhy161.SetChannel(wifiChannel161.Create());

	ns3::YansWifiChannelHelper wifiChannel162;
	wifiChannel162 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy162;
	wifiPhy162 = ns3::YansWifiPhyHelper::Default();
	wifiPhy162.SetChannel(wifiChannel162.Create());

	ns3::YansWifiChannelHelper wifiChannel163;
	wifiChannel163 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy163;
	wifiPhy163 = ns3::YansWifiPhyHelper::Default();
	wifiPhy163.SetChannel(wifiChannel163.Create());

	ns3::YansWifiChannelHelper wifiChannel164;
	wifiChannel164 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy164;
	wifiPhy164 = ns3::YansWifiPhyHelper::Default();
	wifiPhy164.SetChannel(wifiChannel164.Create());

	ns3::YansWifiChannelHelper wifiChannel165;
	wifiChannel165 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy165;
	wifiPhy165 = ns3::YansWifiPhyHelper::Default();
	wifiPhy165.SetChannel(wifiChannel165.Create());

	ns3::YansWifiChannelHelper wifiChannel166;
	wifiChannel166 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy166;
	wifiPhy166 = ns3::YansWifiPhyHelper::Default();
	wifiPhy166.SetChannel(wifiChannel166.Create());

	ns3::YansWifiChannelHelper wifiChannel167;
	wifiChannel167 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy167;
	wifiPhy167 = ns3::YansWifiPhyHelper::Default();
	wifiPhy167.SetChannel(wifiChannel167.Create());

	ns3::YansWifiChannelHelper wifiChannel168;
	wifiChannel168 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy168;
	wifiPhy168 = ns3::YansWifiPhyHelper::Default();
	wifiPhy168.SetChannel(wifiChannel168.Create());

	ns3::YansWifiChannelHelper wifiChannel169;
	wifiChannel169 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy169;
	wifiPhy169 = ns3::YansWifiPhyHelper::Default();
	wifiPhy169.SetChannel(wifiChannel169.Create());

	ns3::YansWifiChannelHelper wifiChannel170;
	wifiChannel170 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy170;
	wifiPhy170 = ns3::YansWifiPhyHelper::Default();
	wifiPhy170.SetChannel(wifiChannel170.Create());

	ns3::YansWifiChannelHelper wifiChannel171;
	wifiChannel171 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy171;
	wifiPhy171 = ns3::YansWifiPhyHelper::Default();
	wifiPhy171.SetChannel(wifiChannel171.Create());

	ns3::YansWifiChannelHelper wifiChannel172;
	wifiChannel172 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy172;
	wifiPhy172 = ns3::YansWifiPhyHelper::Default();
	wifiPhy172.SetChannel(wifiChannel172.Create());

	ns3::YansWifiChannelHelper wifiChannel173;
	wifiChannel173 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy173;
	wifiPhy173 = ns3::YansWifiPhyHelper::Default();
	wifiPhy173.SetChannel(wifiChannel173.Create());

	ns3::YansWifiChannelHelper wifiChannel174;
	wifiChannel174 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy174;
	wifiPhy174 = ns3::YansWifiPhyHelper::Default();
	wifiPhy174.SetChannel(wifiChannel174.Create());

	ns3::YansWifiChannelHelper wifiChannel175;
	wifiChannel175 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy175;
	wifiPhy175 = ns3::YansWifiPhyHelper::Default();
	wifiPhy175.SetChannel(wifiChannel175.Create());

	ns3::YansWifiChannelHelper wifiChannel176;
	wifiChannel176 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy176;
	wifiPhy176 = ns3::YansWifiPhyHelper::Default();
	wifiPhy176.SetChannel(wifiChannel176.Create());

	ns3::YansWifiChannelHelper wifiChannel177;
	wifiChannel177 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy177;
	wifiPhy177 = ns3::YansWifiPhyHelper::Default();
	wifiPhy177.SetChannel(wifiChannel177.Create());

	ns3::YansWifiChannelHelper wifiChannel178;
	wifiChannel178 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy178;
	wifiPhy178 = ns3::YansWifiPhyHelper::Default();
	wifiPhy178.SetChannel(wifiChannel178.Create());

	ns3::YansWifiChannelHelper wifiChannel179;
	wifiChannel179 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy179;
	wifiPhy179 = ns3::YansWifiPhyHelper::Default();
	wifiPhy179.SetChannel(wifiChannel179.Create());

	ns3::YansWifiChannelHelper wifiChannel180;
	wifiChannel180 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy180;
	wifiPhy180 = ns3::YansWifiPhyHelper::Default();
	wifiPhy180.SetChannel(wifiChannel180.Create());

	ns3::YansWifiChannelHelper wifiChannel181;
	wifiChannel181 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy181;
	wifiPhy181 = ns3::YansWifiPhyHelper::Default();
	wifiPhy181.SetChannel(wifiChannel181.Create());

	ns3::YansWifiChannelHelper wifiChannel182;
	wifiChannel182 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy182;
	wifiPhy182 = ns3::YansWifiPhyHelper::Default();
	wifiPhy182.SetChannel(wifiChannel182.Create());

	ns3::YansWifiChannelHelper wifiChannel183;
	wifiChannel183 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy183;
	wifiPhy183 = ns3::YansWifiPhyHelper::Default();
	wifiPhy183.SetChannel(wifiChannel183.Create());

	ns3::YansWifiChannelHelper wifiChannel184;
	wifiChannel184 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy184;
	wifiPhy184 = ns3::YansWifiPhyHelper::Default();
	wifiPhy184.SetChannel(wifiChannel184.Create());

	ns3::YansWifiChannelHelper wifiChannel185;
	wifiChannel185 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy185;
	wifiPhy185 = ns3::YansWifiPhyHelper::Default();
	wifiPhy185.SetChannel(wifiChannel185.Create());

	ns3::YansWifiChannelHelper wifiChannel186;
	wifiChannel186 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy186;
	wifiPhy186 = ns3::YansWifiPhyHelper::Default();
	wifiPhy186.SetChannel(wifiChannel186.Create());

	ns3::YansWifiChannelHelper wifiChannel187;
	wifiChannel187 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy187;
	wifiPhy187 = ns3::YansWifiPhyHelper::Default();
	wifiPhy187.SetChannel(wifiChannel187.Create());

	ns3::YansWifiChannelHelper wifiChannel188;
	wifiChannel188 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy188;
	wifiPhy188 = ns3::YansWifiPhyHelper::Default();
	wifiPhy188.SetChannel(wifiChannel188.Create());

	ns3::YansWifiChannelHelper wifiChannel189;
	wifiChannel189 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy189;
	wifiPhy189 = ns3::YansWifiPhyHelper::Default();
	wifiPhy189.SetChannel(wifiChannel189.Create());

	ns3::YansWifiChannelHelper wifiChannel190;
	wifiChannel190 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy190;
	wifiPhy190 = ns3::YansWifiPhyHelper::Default();
	wifiPhy190.SetChannel(wifiChannel190.Create());

	ns3::YansWifiChannelHelper wifiChannel191;
	wifiChannel191 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy191;
	wifiPhy191 = ns3::YansWifiPhyHelper::Default();
	wifiPhy191.SetChannel(wifiChannel191.Create());

	ns3::YansWifiChannelHelper wifiChannel192;
	wifiChannel192 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy192;
	wifiPhy192 = ns3::YansWifiPhyHelper::Default();
	wifiPhy192.SetChannel(wifiChannel192.Create());

	ns3::YansWifiChannelHelper wifiChannel193;
	wifiChannel193 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy193;
	wifiPhy193 = ns3::YansWifiPhyHelper::Default();
	wifiPhy193.SetChannel(wifiChannel193.Create());

	ns3::YansWifiChannelHelper wifiChannel194;
	wifiChannel194 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy194;
	wifiPhy194 = ns3::YansWifiPhyHelper::Default();
	wifiPhy194.SetChannel(wifiChannel194.Create());

	ns3::YansWifiChannelHelper wifiChannel195;
	wifiChannel195 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy195;
	wifiPhy195 = ns3::YansWifiPhyHelper::Default();
	wifiPhy195.SetChannel(wifiChannel195.Create());

	ns3::YansWifiChannelHelper wifiChannel196;
	wifiChannel196 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy196;
	wifiPhy196 = ns3::YansWifiPhyHelper::Default();
	wifiPhy196.SetChannel(wifiChannel196.Create());

	ns3::YansWifiChannelHelper wifiChannel197;
	wifiChannel197 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy197;
	wifiPhy197 = ns3::YansWifiPhyHelper::Default();
	wifiPhy197.SetChannel(wifiChannel197.Create());

	ns3::YansWifiChannelHelper wifiChannel198;
	wifiChannel198 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy198;
	wifiPhy198 = ns3::YansWifiPhyHelper::Default();
	wifiPhy198.SetChannel(wifiChannel198.Create());

	ns3::YansWifiChannelHelper wifiChannel199;
	wifiChannel199 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy199;
	wifiPhy199 = ns3::YansWifiPhyHelper::Default();
	wifiPhy199.SetChannel(wifiChannel199.Create());

	ns3::YansWifiChannelHelper wifiChannel200;
	wifiChannel200 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy200;
	wifiPhy200 = ns3::YansWifiPhyHelper::Default();
	wifiPhy200.SetChannel(wifiChannel200.Create());

	ns3::YansWifiChannelHelper wifiChannel201;
	wifiChannel201 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy201;
	wifiPhy201 = ns3::YansWifiPhyHelper::Default();
	wifiPhy201.SetChannel(wifiChannel201.Create());

	ns3::YansWifiChannelHelper wifiChannel202;
	wifiChannel202 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy202;
	wifiPhy202 = ns3::YansWifiPhyHelper::Default();
	wifiPhy202.SetChannel(wifiChannel202.Create());

	ns3::YansWifiChannelHelper wifiChannel203;
	wifiChannel203 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy203;
	wifiPhy203 = ns3::YansWifiPhyHelper::Default();
	wifiPhy203.SetChannel(wifiChannel203.Create());

	ns3::YansWifiChannelHelper wifiChannel204;
	wifiChannel204 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy204;
	wifiPhy204 = ns3::YansWifiPhyHelper::Default();
	wifiPhy204.SetChannel(wifiChannel204.Create());

	ns3::YansWifiChannelHelper wifiChannel205;
	wifiChannel205 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy205;
	wifiPhy205 = ns3::YansWifiPhyHelper::Default();
	wifiPhy205.SetChannel(wifiChannel205.Create());

	ns3::YansWifiChannelHelper wifiChannel206;
	wifiChannel206 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy206;
	wifiPhy206 = ns3::YansWifiPhyHelper::Default();
	wifiPhy206.SetChannel(wifiChannel206.Create());

	ns3::YansWifiChannelHelper wifiChannel207;
	wifiChannel207 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy207;
	wifiPhy207 = ns3::YansWifiPhyHelper::Default();
	wifiPhy207.SetChannel(wifiChannel207.Create());

	ns3::YansWifiChannelHelper wifiChannel208;
	wifiChannel208 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy208;
	wifiPhy208 = ns3::YansWifiPhyHelper::Default();
	wifiPhy208.SetChannel(wifiChannel208.Create());

	ns3::YansWifiChannelHelper wifiChannel209;
	wifiChannel209 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy209;
	wifiPhy209 = ns3::YansWifiPhyHelper::Default();
	wifiPhy209.SetChannel(wifiChannel209.Create());

	ns3::YansWifiChannelHelper wifiChannel210;
	wifiChannel210 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy210;
	wifiPhy210 = ns3::YansWifiPhyHelper::Default();
	wifiPhy210.SetChannel(wifiChannel210.Create());

	ns3::YansWifiChannelHelper wifiChannel211;
	wifiChannel211 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy211;
	wifiPhy211 = ns3::YansWifiPhyHelper::Default();
	wifiPhy211.SetChannel(wifiChannel211.Create());

	ns3::YansWifiChannelHelper wifiChannel212;
	wifiChannel212 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy212;
	wifiPhy212 = ns3::YansWifiPhyHelper::Default();
	wifiPhy212.SetChannel(wifiChannel212.Create());

	ns3::YansWifiChannelHelper wifiChannel213;
	wifiChannel213 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy213;
	wifiPhy213 = ns3::YansWifiPhyHelper::Default();
	wifiPhy213.SetChannel(wifiChannel213.Create());

	ns3::YansWifiChannelHelper wifiChannel214;
	wifiChannel214 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy214;
	wifiPhy214 = ns3::YansWifiPhyHelper::Default();
	wifiPhy214.SetChannel(wifiChannel214.Create());

	ns3::YansWifiChannelHelper wifiChannel215;
	wifiChannel215 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy215;
	wifiPhy215 = ns3::YansWifiPhyHelper::Default();
	wifiPhy215.SetChannel(wifiChannel215.Create());

	ns3::YansWifiChannelHelper wifiChannel216;
	wifiChannel216 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy216;
	wifiPhy216 = ns3::YansWifiPhyHelper::Default();
	wifiPhy216.SetChannel(wifiChannel216.Create());

	ns3::YansWifiChannelHelper wifiChannel217;
	wifiChannel217 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy217;
	wifiPhy217 = ns3::YansWifiPhyHelper::Default();
	wifiPhy217.SetChannel(wifiChannel217.Create());

	ns3::YansWifiChannelHelper wifiChannel218;
	wifiChannel218 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy218;
	wifiPhy218 = ns3::YansWifiPhyHelper::Default();
	wifiPhy218.SetChannel(wifiChannel218.Create());

	ns3::YansWifiChannelHelper wifiChannel219;
	wifiChannel219 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy219;
	wifiPhy219 = ns3::YansWifiPhyHelper::Default();
	wifiPhy219.SetChannel(wifiChannel219.Create());

	ns3::YansWifiChannelHelper wifiChannel220;
	wifiChannel220 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy220;
	wifiPhy220 = ns3::YansWifiPhyHelper::Default();
	wifiPhy220.SetChannel(wifiChannel220.Create());

	ns3::YansWifiChannelHelper wifiChannel221;
	wifiChannel221 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy221;
	wifiPhy221 = ns3::YansWifiPhyHelper::Default();
	wifiPhy221.SetChannel(wifiChannel221.Create());

	ns3::YansWifiChannelHelper wifiChannel222;
	wifiChannel222 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy222;
	wifiPhy222 = ns3::YansWifiPhyHelper::Default();
	wifiPhy222.SetChannel(wifiChannel222.Create());

	ns3::YansWifiChannelHelper wifiChannel223;
	wifiChannel223 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy223;
	wifiPhy223 = ns3::YansWifiPhyHelper::Default();
	wifiPhy223.SetChannel(wifiChannel223.Create());

	ns3::YansWifiChannelHelper wifiChannel224;
	wifiChannel224 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy224;
	wifiPhy224 = ns3::YansWifiPhyHelper::Default();
	wifiPhy224.SetChannel(wifiChannel224.Create());

	ns3::YansWifiChannelHelper wifiChannel225;
	wifiChannel225 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy225;
	wifiPhy225 = ns3::YansWifiPhyHelper::Default();
	wifiPhy225.SetChannel(wifiChannel225.Create());

	ns3::YansWifiChannelHelper wifiChannel226;
	wifiChannel226 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy226;
	wifiPhy226 = ns3::YansWifiPhyHelper::Default();
	wifiPhy226.SetChannel(wifiChannel226.Create());

	ns3::YansWifiChannelHelper wifiChannel227;
	wifiChannel227 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy227;
	wifiPhy227 = ns3::YansWifiPhyHelper::Default();
	wifiPhy227.SetChannel(wifiChannel227.Create());

	ns3::YansWifiChannelHelper wifiChannel228;
	wifiChannel228 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy228;
	wifiPhy228 = ns3::YansWifiPhyHelper::Default();
	wifiPhy228.SetChannel(wifiChannel228.Create());

	ns3::YansWifiChannelHelper wifiChannel229;
	wifiChannel229 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy229;
	wifiPhy229 = ns3::YansWifiPhyHelper::Default();
	wifiPhy229.SetChannel(wifiChannel229.Create());

	ns3::YansWifiChannelHelper wifiChannel230;
	wifiChannel230 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy230;
	wifiPhy230 = ns3::YansWifiPhyHelper::Default();
	wifiPhy230.SetChannel(wifiChannel230.Create());

	ns3::YansWifiChannelHelper wifiChannel231;
	wifiChannel231 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy231;
	wifiPhy231 = ns3::YansWifiPhyHelper::Default();
	wifiPhy231.SetChannel(wifiChannel231.Create());

	ns3::YansWifiChannelHelper wifiChannel232;
	wifiChannel232 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy232;
	wifiPhy232 = ns3::YansWifiPhyHelper::Default();
	wifiPhy232.SetChannel(wifiChannel232.Create());

	ns3::YansWifiChannelHelper wifiChannel233;
	wifiChannel233 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy233;
	wifiPhy233 = ns3::YansWifiPhyHelper::Default();
	wifiPhy233.SetChannel(wifiChannel233.Create());

	ns3::YansWifiChannelHelper wifiChannel234;
	wifiChannel234 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy234;
	wifiPhy234 = ns3::YansWifiPhyHelper::Default();
	wifiPhy234.SetChannel(wifiChannel234.Create());

	ns3::YansWifiChannelHelper wifiChannel235;
	wifiChannel235 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy235;
	wifiPhy235 = ns3::YansWifiPhyHelper::Default();
	wifiPhy235.SetChannel(wifiChannel235.Create());

	ns3::YansWifiChannelHelper wifiChannel236;
	wifiChannel236 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy236;
	wifiPhy236 = ns3::YansWifiPhyHelper::Default();
	wifiPhy236.SetChannel(wifiChannel236.Create());

	ns3::YansWifiChannelHelper wifiChannel237;
	wifiChannel237 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy237;
	wifiPhy237 = ns3::YansWifiPhyHelper::Default();
	wifiPhy237.SetChannel(wifiChannel237.Create());

	ns3::YansWifiChannelHelper wifiChannel238;
	wifiChannel238 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy238;
	wifiPhy238 = ns3::YansWifiPhyHelper::Default();
	wifiPhy238.SetChannel(wifiChannel238.Create());

	ns3::YansWifiChannelHelper wifiChannel239;
	wifiChannel239 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy239;
	wifiPhy239 = ns3::YansWifiPhyHelper::Default();
	wifiPhy239.SetChannel(wifiChannel239.Create());

	ns3::YansWifiChannelHelper wifiChannel240;
	wifiChannel240 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy240;
	wifiPhy240 = ns3::YansWifiPhyHelper::Default();
	wifiPhy240.SetChannel(wifiChannel240.Create());

	ns3::YansWifiChannelHelper wifiChannel241;
	wifiChannel241 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy241;
	wifiPhy241 = ns3::YansWifiPhyHelper::Default();
	wifiPhy241.SetChannel(wifiChannel241.Create());

	ns3::YansWifiChannelHelper wifiChannel242;
	wifiChannel242 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy242;
	wifiPhy242 = ns3::YansWifiPhyHelper::Default();
	wifiPhy242.SetChannel(wifiChannel242.Create());

	ns3::YansWifiChannelHelper wifiChannel243;
	wifiChannel243 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy243;
	wifiPhy243 = ns3::YansWifiPhyHelper::Default();
	wifiPhy243.SetChannel(wifiChannel243.Create());

	ns3::YansWifiChannelHelper wifiChannel244;
	wifiChannel244 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy244;
	wifiPhy244 = ns3::YansWifiPhyHelper::Default();
	wifiPhy244.SetChannel(wifiChannel244.Create());

	ns3::YansWifiChannelHelper wifiChannel245;
	wifiChannel245 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy245;
	wifiPhy245 = ns3::YansWifiPhyHelper::Default();
	wifiPhy245.SetChannel(wifiChannel245.Create());

	ns3::YansWifiChannelHelper wifiChannel246;
	wifiChannel246 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy246;
	wifiPhy246 = ns3::YansWifiPhyHelper::Default();
	wifiPhy246.SetChannel(wifiChannel246.Create());

	ns3::YansWifiChannelHelper wifiChannel247;
	wifiChannel247 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy247;
	wifiPhy247 = ns3::YansWifiPhyHelper::Default();
	wifiPhy247.SetChannel(wifiChannel247.Create());

	ns3::YansWifiChannelHelper wifiChannel248;
	wifiChannel248 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy248;
	wifiPhy248 = ns3::YansWifiPhyHelper::Default();
	wifiPhy248.SetChannel(wifiChannel248.Create());

	ns3::YansWifiChannelHelper wifiChannel249;
	wifiChannel249 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy249;
	wifiPhy249 = ns3::YansWifiPhyHelper::Default();
	wifiPhy249.SetChannel(wifiChannel249.Create());

	ns3::YansWifiChannelHelper wifiChannel250;
	wifiChannel250 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy250;
	wifiPhy250 = ns3::YansWifiPhyHelper::Default();
	wifiPhy250.SetChannel(wifiChannel250.Create());

	ns3::YansWifiChannelHelper wifiChannel251;
	wifiChannel251 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy251;
	wifiPhy251 = ns3::YansWifiPhyHelper::Default();
	wifiPhy251.SetChannel(wifiChannel251.Create());

	ns3::YansWifiChannelHelper wifiChannel252;
	wifiChannel252 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy252;
	wifiPhy252 = ns3::YansWifiPhyHelper::Default();
	wifiPhy252.SetChannel(wifiChannel252.Create());

	ns3::YansWifiChannelHelper wifiChannel253;
	wifiChannel253 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy253;
	wifiPhy253 = ns3::YansWifiPhyHelper::Default();
	wifiPhy253.SetChannel(wifiChannel253.Create());

	ns3::YansWifiChannelHelper wifiChannel254;
	wifiChannel254 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy254;
	wifiPhy254 = ns3::YansWifiPhyHelper::Default();
	wifiPhy254.SetChannel(wifiChannel254.Create());

	ns3::YansWifiChannelHelper wifiChannel255;
	wifiChannel255 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy255;
	wifiPhy255 = ns3::YansWifiPhyHelper::Default();
	wifiPhy255.SetChannel(wifiChannel255.Create());

	ns3::YansWifiChannelHelper wifiChannel256;
	wifiChannel256 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy256;
	wifiPhy256 = ns3::YansWifiPhyHelper::Default();
	wifiPhy256.SetChannel(wifiChannel256.Create());

	ns3::YansWifiChannelHelper wifiChannel257;
	wifiChannel257 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy257;
	wifiPhy257 = ns3::YansWifiPhyHelper::Default();
	wifiPhy257.SetChannel(wifiChannel257.Create());

	ns3::YansWifiChannelHelper wifiChannel258;
	wifiChannel258 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy258;
	wifiPhy258 = ns3::YansWifiPhyHelper::Default();
	wifiPhy258.SetChannel(wifiChannel258.Create());

	ns3::YansWifiChannelHelper wifiChannel259;
	wifiChannel259 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy259;
	wifiPhy259 = ns3::YansWifiPhyHelper::Default();
	wifiPhy259.SetChannel(wifiChannel259.Create());

	ns3::YansWifiChannelHelper wifiChannel260;
	wifiChannel260 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy260;
	wifiPhy260 = ns3::YansWifiPhyHelper::Default();
	wifiPhy260.SetChannel(wifiChannel260.Create());

	ns3::YansWifiChannelHelper wifiChannel261;
	wifiChannel261 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy261;
	wifiPhy261 = ns3::YansWifiPhyHelper::Default();
	wifiPhy261.SetChannel(wifiChannel261.Create());

	ns3::YansWifiChannelHelper wifiChannel262;
	wifiChannel262 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy262;
	wifiPhy262 = ns3::YansWifiPhyHelper::Default();
	wifiPhy262.SetChannel(wifiChannel262.Create());

	ns3::YansWifiChannelHelper wifiChannel263;
	wifiChannel263 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy263;
	wifiPhy263 = ns3::YansWifiPhyHelper::Default();
	wifiPhy263.SetChannel(wifiChannel263.Create());

	ns3::YansWifiChannelHelper wifiChannel264;
	wifiChannel264 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy264;
	wifiPhy264 = ns3::YansWifiPhyHelper::Default();
	wifiPhy264.SetChannel(wifiChannel264.Create());

	ns3::YansWifiChannelHelper wifiChannel265;
	wifiChannel265 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy265;
	wifiPhy265 = ns3::YansWifiPhyHelper::Default();
	wifiPhy265.SetChannel(wifiChannel265.Create());

	ns3::YansWifiChannelHelper wifiChannel266;
	wifiChannel266 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy266;
	wifiPhy266 = ns3::YansWifiPhyHelper::Default();
	wifiPhy266.SetChannel(wifiChannel266.Create());

	ns3::YansWifiChannelHelper wifiChannel267;
	wifiChannel267 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy267;
	wifiPhy267 = ns3::YansWifiPhyHelper::Default();
	wifiPhy267.SetChannel(wifiChannel267.Create());

	ns3::YansWifiChannelHelper wifiChannel268;
	wifiChannel268 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy268;
	wifiPhy268 = ns3::YansWifiPhyHelper::Default();
	wifiPhy268.SetChannel(wifiChannel268.Create());

	ns3::YansWifiChannelHelper wifiChannel269;
	wifiChannel269 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy269;
	wifiPhy269 = ns3::YansWifiPhyHelper::Default();
	wifiPhy269.SetChannel(wifiChannel269.Create());

	ns3::YansWifiChannelHelper wifiChannel270;
	wifiChannel270 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy270;
	wifiPhy270 = ns3::YansWifiPhyHelper::Default();
	wifiPhy270.SetChannel(wifiChannel270.Create());

	ns3::YansWifiChannelHelper wifiChannel271;
	wifiChannel271 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy271;
	wifiPhy271 = ns3::YansWifiPhyHelper::Default();
	wifiPhy271.SetChannel(wifiChannel271.Create());

	ns3::YansWifiChannelHelper wifiChannel272;
	wifiChannel272 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy272;
	wifiPhy272 = ns3::YansWifiPhyHelper::Default();
	wifiPhy272.SetChannel(wifiChannel272.Create());

	ns3::YansWifiChannelHelper wifiChannel273;
	wifiChannel273 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy273;
	wifiPhy273 = ns3::YansWifiPhyHelper::Default();
	wifiPhy273.SetChannel(wifiChannel273.Create());

	ns3::YansWifiChannelHelper wifiChannel274;
	wifiChannel274 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy274;
	wifiPhy274 = ns3::YansWifiPhyHelper::Default();
	wifiPhy274.SetChannel(wifiChannel274.Create());

	ns3::YansWifiChannelHelper wifiChannel275;
	wifiChannel275 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy275;
	wifiPhy275 = ns3::YansWifiPhyHelper::Default();
	wifiPhy275.SetChannel(wifiChannel275.Create());

	ns3::YansWifiChannelHelper wifiChannel276;
	wifiChannel276 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy276;
	wifiPhy276 = ns3::YansWifiPhyHelper::Default();
	wifiPhy276.SetChannel(wifiChannel276.Create());

	ns3::YansWifiChannelHelper wifiChannel277;
	wifiChannel277 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy277;
	wifiPhy277 = ns3::YansWifiPhyHelper::Default();
	wifiPhy277.SetChannel(wifiChannel277.Create());

	ns3::YansWifiChannelHelper wifiChannel278;
	wifiChannel278 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy278;
	wifiPhy278 = ns3::YansWifiPhyHelper::Default();
	wifiPhy278.SetChannel(wifiChannel278.Create());

	ns3::YansWifiChannelHelper wifiChannel279;
	wifiChannel279 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy279;
	wifiPhy279 = ns3::YansWifiPhyHelper::Default();
	wifiPhy279.SetChannel(wifiChannel279.Create());

	ns3::YansWifiChannelHelper wifiChannel280;
	wifiChannel280 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy280;
	wifiPhy280 = ns3::YansWifiPhyHelper::Default();
	wifiPhy280.SetChannel(wifiChannel280.Create());

	ns3::YansWifiChannelHelper wifiChannel281;
	wifiChannel281 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy281;
	wifiPhy281 = ns3::YansWifiPhyHelper::Default();
	wifiPhy281.SetChannel(wifiChannel281.Create());

	ns3::YansWifiChannelHelper wifiChannel282;
	wifiChannel282 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy282;
	wifiPhy282 = ns3::YansWifiPhyHelper::Default();
	wifiPhy282.SetChannel(wifiChannel282.Create());

	ns3::YansWifiChannelHelper wifiChannel283;
	wifiChannel283 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy283;
	wifiPhy283 = ns3::YansWifiPhyHelper::Default();
	wifiPhy283.SetChannel(wifiChannel283.Create());

	ns3::YansWifiChannelHelper wifiChannel284;
	wifiChannel284 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy284;
	wifiPhy284 = ns3::YansWifiPhyHelper::Default();
	wifiPhy284.SetChannel(wifiChannel284.Create());

	ns3::YansWifiChannelHelper wifiChannel285;
	wifiChannel285 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy285;
	wifiPhy285 = ns3::YansWifiPhyHelper::Default();
	wifiPhy285.SetChannel(wifiChannel285.Create());

	ns3::YansWifiChannelHelper wifiChannel286;
	wifiChannel286 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy286;
	wifiPhy286 = ns3::YansWifiPhyHelper::Default();
	wifiPhy286.SetChannel(wifiChannel286.Create());

	ns3::YansWifiChannelHelper wifiChannel287;
	wifiChannel287 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy287;
	wifiPhy287 = ns3::YansWifiPhyHelper::Default();
	wifiPhy287.SetChannel(wifiChannel287.Create());

	ns3::YansWifiChannelHelper wifiChannel288;
	wifiChannel288 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy288;
	wifiPhy288 = ns3::YansWifiPhyHelper::Default();
	wifiPhy288.SetChannel(wifiChannel288.Create());

	ns3::YansWifiChannelHelper wifiChannel289;
	wifiChannel289 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy289;
	wifiPhy289 = ns3::YansWifiPhyHelper::Default();
	wifiPhy289.SetChannel(wifiChannel289.Create());

	ns3::YansWifiChannelHelper wifiChannel290;
	wifiChannel290 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy290;
	wifiPhy290 = ns3::YansWifiPhyHelper::Default();
	wifiPhy290.SetChannel(wifiChannel290.Create());

	ns3::YansWifiChannelHelper wifiChannel291;
	wifiChannel291 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy291;
	wifiPhy291 = ns3::YansWifiPhyHelper::Default();
	wifiPhy291.SetChannel(wifiChannel291.Create());

	ns3::YansWifiChannelHelper wifiChannel292;
	wifiChannel292 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy292;
	wifiPhy292 = ns3::YansWifiPhyHelper::Default();
	wifiPhy292.SetChannel(wifiChannel292.Create());

	ns3::YansWifiChannelHelper wifiChannel293;
	wifiChannel293 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy293;
	wifiPhy293 = ns3::YansWifiPhyHelper::Default();
	wifiPhy293.SetChannel(wifiChannel293.Create());

	ns3::YansWifiChannelHelper wifiChannel294;
	wifiChannel294 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy294;
	wifiPhy294 = ns3::YansWifiPhyHelper::Default();
	wifiPhy294.SetChannel(wifiChannel294.Create());

	ns3::YansWifiChannelHelper wifiChannel295;
	wifiChannel295 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy295;
	wifiPhy295 = ns3::YansWifiPhyHelper::Default();
	wifiPhy295.SetChannel(wifiChannel295.Create());

	ns3::YansWifiChannelHelper wifiChannel296;
	wifiChannel296 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy296;
	wifiPhy296 = ns3::YansWifiPhyHelper::Default();
	wifiPhy296.SetChannel(wifiChannel296.Create());

	ns3::YansWifiChannelHelper wifiChannel297;
	wifiChannel297 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy297;
	wifiPhy297 = ns3::YansWifiPhyHelper::Default();
	wifiPhy297.SetChannel(wifiChannel297.Create());

//    wifiChannel298 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy298 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy298.SetChannel(wifiChannel298.Create())
//
//    wifiChannel299 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy299 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy299.SetChannel(wifiChannel299.Create())
//
	ns3::YansWifiChannelHelper wifiChannel300;
	wifiChannel300 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy300;
	wifiPhy300 = ns3::YansWifiPhyHelper::Default();
	wifiPhy300.SetChannel(wifiChannel300.Create());

	ns3::YansWifiChannelHelper wifiChannel301;
	wifiChannel301 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy301;
	wifiPhy301 = ns3::YansWifiPhyHelper::Default();
	wifiPhy301.SetChannel(wifiChannel301.Create());

	ns3::YansWifiChannelHelper wifiChannel302;
	wifiChannel302 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy302;
	wifiPhy302 = ns3::YansWifiPhyHelper::Default();
	wifiPhy302.SetChannel(wifiChannel302.Create());

	ns3::YansWifiChannelHelper wifiChannel303;
	wifiChannel303 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy303;
	wifiPhy303 = ns3::YansWifiPhyHelper::Default();
	wifiPhy303.SetChannel(wifiChannel303.Create());

	ns3::YansWifiChannelHelper wifiChannel304;
	wifiChannel304 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy304;
	wifiPhy304 = ns3::YansWifiPhyHelper::Default();
	wifiPhy304.SetChannel(wifiChannel304.Create());

	ns3::YansWifiChannelHelper wifiChannel305;
	wifiChannel305 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy305;
	wifiPhy305 = ns3::YansWifiPhyHelper::Default();
	wifiPhy305.SetChannel(wifiChannel305.Create());

//    wifiChannel306 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy306 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy306.SetChannel(wifiChannel306.Create())
//
	ns3::YansWifiChannelHelper wifiChannel307;
	wifiChannel307 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy307;
	wifiPhy307 = ns3::YansWifiPhyHelper::Default();
	wifiPhy307.SetChannel(wifiChannel307.Create());

	ns3::YansWifiChannelHelper wifiChannel308;
	wifiChannel308 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy308;
	wifiPhy308 = ns3::YansWifiPhyHelper::Default();
	wifiPhy308.SetChannel(wifiChannel308.Create());

	ns3::YansWifiChannelHelper wifiChannel309;
	wifiChannel309 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy309;
	wifiPhy309 = ns3::YansWifiPhyHelper::Default();
	wifiPhy309.SetChannel(wifiChannel309.Create());

	ns3::YansWifiChannelHelper wifiChannel310;
	wifiChannel310 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy310;
	wifiPhy310 = ns3::YansWifiPhyHelper::Default();
	wifiPhy310.SetChannel(wifiChannel310.Create());

	ns3::YansWifiChannelHelper wifiChannel311;
	wifiChannel311 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy311;
	wifiPhy311 = ns3::YansWifiPhyHelper::Default();
	wifiPhy311.SetChannel(wifiChannel311.Create());

	ns3::YansWifiChannelHelper wifiChannel312;
	wifiChannel312 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy312;
	wifiPhy312 = ns3::YansWifiPhyHelper::Default();
	wifiPhy312.SetChannel(wifiChannel312.Create());

	ns3::YansWifiChannelHelper wifiChannel313;
	wifiChannel313 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy313;
	wifiPhy313 = ns3::YansWifiPhyHelper::Default();
	wifiPhy313.SetChannel(wifiChannel313.Create());

	ns3::YansWifiChannelHelper wifiChannel314;
	wifiChannel314 = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhyHelper wifiPhy314;
	wifiPhy314 = ns3::YansWifiPhyHelper::Default();
	wifiPhy314.SetChannel(wifiChannel314.Create());

//    wifiChannel315 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy315 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy315.SetChannel(wifiChannel315.Create())
//

//stanodes mac
	ns3::NqosWifiMacHelper mac;
	mac = ns3::NqosWifiMacHelper::Default();
	//mac = ns.wifi.NqosWifiMacHelper.Default()
	ns3::Ssid ssid;
	ssid = ns3::Ssid("wifi-default");
	//ssid = ns.wifi.Ssid("wifi-default")
	mac.SetType("ns3::StaWifiMac", "Ssid", ns3::SsidValue(ssid),
			"ActiveProbing", ns3::BooleanValue(false));

	ns3::NetDeviceContainer staDevices1;
	staDevices1 = Wifi.Install(wifiPhy, mac, wifiStaNodes1);
	ns3::NetDeviceContainer staDevices2;
	staDevices2 = Wifi.Install(wifiPhy2, mac, wifiStaNodes2);
	ns3::NetDeviceContainer staDevices3;
	staDevices3 = Wifi.Install(wifiPhy3, mac, wifiStaNodes3);
	ns3::NetDeviceContainer staDevices4;
	staDevices4 = Wifi.Install(wifiPhy4, mac, wifiStaNodes4);
	ns3::NetDeviceContainer staDevices5;
	staDevices5 = Wifi.Install(wifiPhy5, mac, wifiStaNodes5);
	ns3::NetDeviceContainer staDevices6;
	staDevices6 = Wifi.Install(wifiPhy6, mac, wifiStaNodes6);
	ns3::NetDeviceContainer staDevices7;
	staDevices7 = Wifi.Install(wifiPhy7, mac, wifiStaNodes7);
	ns3::NetDeviceContainer staDevices8;
	staDevices8 = Wifi.Install(wifiPhy8, mac, wifiStaNodes8);
	ns3::NetDeviceContainer staDevices9;
	staDevices9 = Wifi.Install(wifiPhy9, mac, wifiStaNodes9);
	ns3::NetDeviceContainer staDevices10;
	staDevices10 = Wifi.Install(wifiPhy10, mac, wifiStaNodes10);
	ns3::NetDeviceContainer staDevices11;
	staDevices11 = Wifi.Install(wifiPhy11, mac, wifiStaNodes11);
	ns3::NetDeviceContainer staDevices12;
	staDevices12 = Wifi.Install(wifiPhy12, mac, wifiStaNodes12);
	ns3::NetDeviceContainer staDevices13;
	staDevices13 = Wifi.Install(wifiPhy13, mac, wifiStaNodes13);
	ns3::NetDeviceContainer staDevices14;
	staDevices14 = Wifi.Install(wifiPhy14, mac, wifiStaNodes14);
	ns3::NetDeviceContainer staDevices15;
	staDevices15 = Wifi.Install(wifiPhy15, mac, wifiStaNodes15);
	ns3::NetDeviceContainer staDevices16;
	staDevices16 = Wifi.Install(wifiPhy16, mac, wifiStaNodes16);
	ns3::NetDeviceContainer staDevices17;
	staDevices17 = Wifi.Install(wifiPhy17, mac, wifiStaNodes17);
	ns3::NetDeviceContainer staDevices18;
	staDevices18 = Wifi.Install(wifiPhy18, mac, wifiStaNodes18);
	ns3::NetDeviceContainer staDevices19;
	staDevices19 = Wifi.Install(wifiPhy19, mac, wifiStaNodes19);
	ns3::NetDeviceContainer staDevices20;
	staDevices20 = Wifi.Install(wifiPhy20, mac, wifiStaNodes20);
	ns3::NetDeviceContainer staDevices21;
	staDevices21 = Wifi.Install(wifiPhy21, mac, wifiStaNodes21);
	ns3::NetDeviceContainer staDevices22;
	staDevices22 = Wifi.Install(wifiPhy22, mac, wifiStaNodes22);
	ns3::NetDeviceContainer staDevices23;
	staDevices23 = Wifi.Install(wifiPhy23, mac, wifiStaNodes23);
	ns3::NetDeviceContainer staDevices24;
	staDevices24 = Wifi.Install(wifiPhy24, mac, wifiStaNodes24);
	ns3::NetDeviceContainer staDevices25;
	staDevices25 = Wifi.Install(wifiPhy25, mac, wifiStaNodes25);
	ns3::NetDeviceContainer staDevices26;
	staDevices26 = Wifi.Install(wifiPhy26, mac, wifiStaNodes26);
	ns3::NetDeviceContainer staDevices27;
	staDevices27 = Wifi.Install(wifiPhy27, mac, wifiStaNodes27);
	ns3::NetDeviceContainer staDevices28;
	staDevices28 = Wifi.Install(wifiPhy28, mac, wifiStaNodes28);
	ns3::NetDeviceContainer staDevices29;
	staDevices29 = Wifi.Install(wifiPhy29, mac, wifiStaNodes29);
	ns3::NetDeviceContainer staDevices30;
	staDevices30 = Wifi.Install(wifiPhy30, mac, wifiStaNodes30);
	ns3::NetDeviceContainer staDevices31;
	staDevices31 = Wifi.Install(wifiPhy31, mac, wifiStaNodes31);
	ns3::NetDeviceContainer staDevices32;
	staDevices32 = Wifi.Install(wifiPhy32, mac, wifiStaNodes32);
	ns3::NetDeviceContainer staDevices33;
	staDevices33 = Wifi.Install(wifiPhy33, mac, wifiStaNodes33);
	ns3::NetDeviceContainer staDevices34;
	staDevices34 = Wifi.Install(wifiPhy34, mac, wifiStaNodes34);
	ns3::NetDeviceContainer staDevices35;
	staDevices35 = Wifi.Install(wifiPhy35, mac, wifiStaNodes35);
	ns3::NetDeviceContainer staDevices36;
	staDevices36 = Wifi.Install(wifiPhy36, mac, wifiStaNodes36);
	ns3::NetDeviceContainer staDevices37;
	staDevices37 = Wifi.Install(wifiPhy37, mac, wifiStaNodes37);
	ns3::NetDeviceContainer staDevices38;
	staDevices38 = Wifi.Install(wifiPhy38, mac, wifiStaNodes38);
	ns3::NetDeviceContainer staDevices39;
	staDevices39 = Wifi.Install(wifiPhy39, mac, wifiStaNodes39);
	ns3::NetDeviceContainer staDevices40;
	staDevices40 = Wifi.Install(wifiPhy40, mac, wifiStaNodes40);
	ns3::NetDeviceContainer staDevices41;
	staDevices41 = Wifi.Install(wifiPhy41, mac, wifiStaNodes41);
	ns3::NetDeviceContainer staDevices42;
	staDevices42 = Wifi.Install(wifiPhy42, mac, wifiStaNodes42);
	ns3::NetDeviceContainer staDevices43;
	staDevices43 = Wifi.Install(wifiPhy43, mac, wifiStaNodes43);
	ns3::NetDeviceContainer staDevices44;
	staDevices44 = Wifi.Install(wifiPhy44, mac, wifiStaNodes44);
	ns3::NetDeviceContainer staDevices45;
	staDevices45 = Wifi.Install(wifiPhy45, mac, wifiStaNodes45);
	ns3::NetDeviceContainer staDevices46;
	staDevices46 = Wifi.Install(wifiPhy46, mac, wifiStaNodes46);
	ns3::NetDeviceContainer staDevices47;
	staDevices47 = Wifi.Install(wifiPhy47, mac, wifiStaNodes47);
	ns3::NetDeviceContainer staDevices48;
	staDevices48 = Wifi.Install(wifiPhy48, mac, wifiStaNodes48);
	ns3::NetDeviceContainer staDevices49;
	staDevices49 = Wifi.Install(wifiPhy49, mac, wifiStaNodes49);
	ns3::NetDeviceContainer staDevices50;
	staDevices50 = Wifi.Install(wifiPhy50, mac, wifiStaNodes50);
	ns3::NetDeviceContainer staDevices51;
	staDevices51 = Wifi.Install(wifiPhy51, mac, wifiStaNodes51);
	ns3::NetDeviceContainer staDevices52;
	staDevices52 = Wifi.Install(wifiPhy52, mac, wifiStaNodes52);
	ns3::NetDeviceContainer staDevices53;
	staDevices53 = Wifi.Install(wifiPhy53, mac, wifiStaNodes53);
	ns3::NetDeviceContainer staDevices54;
	staDevices54 = Wifi.Install(wifiPhy54, mac, wifiStaNodes54);
	ns3::NetDeviceContainer staDevices55;
	staDevices55 = Wifi.Install(wifiPhy55, mac, wifiStaNodes55);
	ns3::NetDeviceContainer staDevices56;
	staDevices56 = Wifi.Install(wifiPhy56, mac, wifiStaNodes56);
	ns3::NetDeviceContainer staDevices57;
	staDevices57 = Wifi.Install(wifiPhy57, mac, wifiStaNodes57);
	ns3::NetDeviceContainer staDevices58;
	staDevices58 = Wifi.Install(wifiPhy58, mac, wifiStaNodes58);
	ns3::NetDeviceContainer staDevices59;
	staDevices59 = Wifi.Install(wifiPhy59, mac, wifiStaNodes59);
	ns3::NetDeviceContainer staDevices60;
	staDevices60 = Wifi.Install(wifiPhy60, mac, wifiStaNodes60);
	ns3::NetDeviceContainer staDevices61;
	staDevices61 = Wifi.Install(wifiPhy61, mac, wifiStaNodes61);
	ns3::NetDeviceContainer staDevices62;
	staDevices62 = Wifi.Install(wifiPhy62, mac, wifiStaNodes62);
	ns3::NetDeviceContainer staDevices63;
	staDevices63 = Wifi.Install(wifiPhy63, mac, wifiStaNodes63);
	ns3::NetDeviceContainer staDevices64;
	staDevices64 = Wifi.Install(wifiPhy64, mac, wifiStaNodes64);
	ns3::NetDeviceContainer staDevices65;
	staDevices65 = Wifi.Install(wifiPhy65, mac, wifiStaNodes65);
	ns3::NetDeviceContainer staDevices66;
	staDevices66 = Wifi.Install(wifiPhy66, mac, wifiStaNodes66);
	ns3::NetDeviceContainer staDevices67;
	staDevices67 = Wifi.Install(wifiPhy67, mac, wifiStaNodes67);
	ns3::NetDeviceContainer staDevices68;
	staDevices68 = Wifi.Install(wifiPhy68, mac, wifiStaNodes68);
	ns3::NetDeviceContainer staDevices69;
	staDevices69 = Wifi.Install(wifiPhy69, mac, wifiStaNodes69);
	ns3::NetDeviceContainer staDevices70;
	staDevices70 = Wifi.Install(wifiPhy70, mac, wifiStaNodes70);
	ns3::NetDeviceContainer staDevices71;
	staDevices71 = Wifi.Install(wifiPhy71, mac, wifiStaNodes71);
	ns3::NetDeviceContainer staDevices72;
	staDevices72 = Wifi.Install(wifiPhy72, mac, wifiStaNodes72);
	ns3::NetDeviceContainer staDevices73;
	staDevices73 = Wifi.Install(wifiPhy73, mac, wifiStaNodes73);
	ns3::NetDeviceContainer staDevices74;
	staDevices74 = Wifi.Install(wifiPhy74, mac, wifiStaNodes74);
	ns3::NetDeviceContainer staDevices75;
	staDevices75 = Wifi.Install(wifiPhy75, mac, wifiStaNodes75);
	ns3::NetDeviceContainer staDevices76;
	staDevices76 = Wifi.Install(wifiPhy76, mac, wifiStaNodes76);
	ns3::NetDeviceContainer staDevices77;
	staDevices77 = Wifi.Install(wifiPhy77, mac, wifiStaNodes77);
	ns3::NetDeviceContainer staDevices78;
	staDevices78 = Wifi.Install(wifiPhy78, mac, wifiStaNodes78);
	ns3::NetDeviceContainer staDevices79;
	staDevices79 = Wifi.Install(wifiPhy79, mac, wifiStaNodes79);
	ns3::NetDeviceContainer staDevices80;
	staDevices80 = Wifi.Install(wifiPhy80, mac, wifiStaNodes80);
	ns3::NetDeviceContainer staDevices81;
	staDevices81 = Wifi.Install(wifiPhy81, mac, wifiStaNodes81);
	ns3::NetDeviceContainer staDevices82;
	staDevices82 = Wifi.Install(wifiPhy82, mac, wifiStaNodes82);
	ns3::NetDeviceContainer staDevices83;
	staDevices83 = Wifi.Install(wifiPhy83, mac, wifiStaNodes83);
	ns3::NetDeviceContainer staDevices84;
	staDevices84 = Wifi.Install(wifiPhy84, mac, wifiStaNodes84);
	ns3::NetDeviceContainer staDevices85;
	staDevices85 = Wifi.Install(wifiPhy85, mac, wifiStaNodes85);
	ns3::NetDeviceContainer staDevices86;
	staDevices86 = Wifi.Install(wifiPhy86, mac, wifiStaNodes86);
	ns3::NetDeviceContainer staDevices87;
	staDevices87 = Wifi.Install(wifiPhy87, mac, wifiStaNodes87);
	ns3::NetDeviceContainer staDevices88;
	staDevices88 = Wifi.Install(wifiPhy88, mac, wifiStaNodes88);
	ns3::NetDeviceContainer staDevices89;
	staDevices89 = Wifi.Install(wifiPhy89, mac, wifiStaNodes89);
	ns3::NetDeviceContainer staDevices90;
	staDevices90 = Wifi.Install(wifiPhy90, mac, wifiStaNodes90);
	ns3::NetDeviceContainer staDevices91;
	staDevices91 = Wifi.Install(wifiPhy91, mac, wifiStaNodes91);
	ns3::NetDeviceContainer staDevices92;
	staDevices92 = Wifi.Install(wifiPhy92, mac, wifiStaNodes92);
	ns3::NetDeviceContainer staDevices93;
	staDevices93 = Wifi.Install(wifiPhy93, mac, wifiStaNodes93);
	ns3::NetDeviceContainer staDevices94;
	staDevices94 = Wifi.Install(wifiPhy94, mac, wifiStaNodes94);
	ns3::NetDeviceContainer staDevices95;
	staDevices95 = Wifi.Install(wifiPhy95, mac, wifiStaNodes95);
	ns3::NetDeviceContainer staDevices96;
	staDevices96 = Wifi.Install(wifiPhy96, mac, wifiStaNodes96);
	ns3::NetDeviceContainer staDevices97;
	staDevices97 = Wifi.Install(wifiPhy97, mac, wifiStaNodes97);
	ns3::NetDeviceContainer staDevices98;
	staDevices98 = Wifi.Install(wifiPhy98, mac, wifiStaNodes98);
	ns3::NetDeviceContainer staDevices99;
	staDevices99 = Wifi.Install(wifiPhy99, mac, wifiStaNodes99);
	ns3::NetDeviceContainer staDevices100;
	staDevices100 = Wifi.Install(wifiPhy100, mac, wifiStaNodes100);
	ns3::NetDeviceContainer staDevices101;
	staDevices101 = Wifi.Install(wifiPhy101, mac, wifiStaNodes101);
	ns3::NetDeviceContainer staDevices102;
	staDevices102 = Wifi.Install(wifiPhy102, mac, wifiStaNodes102);
	ns3::NetDeviceContainer staDevices103;
	staDevices103 = Wifi.Install(wifiPhy103, mac, wifiStaNodes103);
	ns3::NetDeviceContainer staDevices104;
	staDevices104 = Wifi.Install(wifiPhy104, mac, wifiStaNodes104);
	ns3::NetDeviceContainer staDevices105;
	staDevices105 = Wifi.Install(wifiPhy105, mac, wifiStaNodes105);
	ns3::NetDeviceContainer staDevices106;
	staDevices106 = Wifi.Install(wifiPhy106, mac, wifiStaNodes106);
	ns3::NetDeviceContainer staDevices107;
	staDevices107 = Wifi.Install(wifiPhy107, mac, wifiStaNodes107);
	ns3::NetDeviceContainer staDevices108;
	staDevices108 = Wifi.Install(wifiPhy108, mac, wifiStaNodes108);
	ns3::NetDeviceContainer staDevices109;
	staDevices109 = Wifi.Install(wifiPhy109, mac, wifiStaNodes109);
	ns3::NetDeviceContainer staDevices110;
	staDevices110 = Wifi.Install(wifiPhy110, mac, wifiStaNodes110);
	ns3::NetDeviceContainer staDevices111;
	staDevices111 = Wifi.Install(wifiPhy111, mac, wifiStaNodes111);
	ns3::NetDeviceContainer staDevices112;
	staDevices112 = Wifi.Install(wifiPhy112, mac, wifiStaNodes112);
	ns3::NetDeviceContainer staDevices113;
	staDevices113 = Wifi.Install(wifiPhy113, mac, wifiStaNodes113);
	ns3::NetDeviceContainer staDevices114;
	staDevices114 = Wifi.Install(wifiPhy114, mac, wifiStaNodes114);
	ns3::NetDeviceContainer staDevices115;
	staDevices115 = Wifi.Install(wifiPhy115, mac, wifiStaNodes115);
	ns3::NetDeviceContainer staDevices116;
	staDevices116 = Wifi.Install(wifiPhy116, mac, wifiStaNodes116);
	ns3::NetDeviceContainer staDevices117;
	staDevices117 = Wifi.Install(wifiPhy117, mac, wifiStaNodes117);
	ns3::NetDeviceContainer staDevices118;
	staDevices118 = Wifi.Install(wifiPhy118, mac, wifiStaNodes118);
	ns3::NetDeviceContainer staDevices119;
	staDevices119 = Wifi.Install(wifiPhy119, mac, wifiStaNodes119);
	ns3::NetDeviceContainer staDevices120;
	staDevices120 = Wifi.Install(wifiPhy120, mac, wifiStaNodes120);
	ns3::NetDeviceContainer staDevices121;
	staDevices121 = Wifi.Install(wifiPhy121, mac, wifiStaNodes121);
	ns3::NetDeviceContainer staDevices122;
	staDevices122 = Wifi.Install(wifiPhy122, mac, wifiStaNodes122);
	ns3::NetDeviceContainer staDevices123;
	staDevices123 = Wifi.Install(wifiPhy123, mac, wifiStaNodes123);
	ns3::NetDeviceContainer staDevices124;
	staDevices124 = Wifi.Install(wifiPhy124, mac, wifiStaNodes124);
	ns3::NetDeviceContainer staDevices125;
	staDevices125 = Wifi.Install(wifiPhy125, mac, wifiStaNodes125);
	ns3::NetDeviceContainer staDevices126;
	staDevices126 = Wifi.Install(wifiPhy126, mac, wifiStaNodes126);
	ns3::NetDeviceContainer staDevices127;
	staDevices127 = Wifi.Install(wifiPhy127, mac, wifiStaNodes127);
	ns3::NetDeviceContainer staDevices128;
	staDevices128 = Wifi.Install(wifiPhy128, mac, wifiStaNodes128);
	ns3::NetDeviceContainer staDevices129;
	staDevices129 = Wifi.Install(wifiPhy129, mac, wifiStaNodes129);
	ns3::NetDeviceContainer staDevices130;
	staDevices130 = Wifi.Install(wifiPhy130, mac, wifiStaNodes130);
	ns3::NetDeviceContainer staDevices131;
	staDevices131 = Wifi.Install(wifiPhy131, mac, wifiStaNodes131);
	ns3::NetDeviceContainer staDevices132;
	staDevices132 = Wifi.Install(wifiPhy132, mac, wifiStaNodes132);
	ns3::NetDeviceContainer staDevices133;
	staDevices133 = Wifi.Install(wifiPhy133, mac, wifiStaNodes133);
	ns3::NetDeviceContainer staDevices134;
	staDevices134 = Wifi.Install(wifiPhy134, mac, wifiStaNodes134);
	ns3::NetDeviceContainer staDevices135;
	staDevices135 = Wifi.Install(wifiPhy135, mac, wifiStaNodes135);
	ns3::NetDeviceContainer staDevices136;
	staDevices136 = Wifi.Install(wifiPhy136, mac, wifiStaNodes136);
	ns3::NetDeviceContainer staDevices137;
	staDevices137 = Wifi.Install(wifiPhy137, mac, wifiStaNodes137);
	ns3::NetDeviceContainer staDevices138;
	staDevices138 = Wifi.Install(wifiPhy138, mac, wifiStaNodes138);
	ns3::NetDeviceContainer staDevices139;
	staDevices139 = Wifi.Install(wifiPhy139, mac, wifiStaNodes139);
	ns3::NetDeviceContainer staDevices140;
	staDevices140 = Wifi.Install(wifiPhy140, mac, wifiStaNodes140);
	ns3::NetDeviceContainer staDevices141;
	staDevices141 = Wifi.Install(wifiPhy141, mac, wifiStaNodes141);
	ns3::NetDeviceContainer staDevices142;
	staDevices142 = Wifi.Install(wifiPhy142, mac, wifiStaNodes142);
	ns3::NetDeviceContainer staDevices143;
	staDevices143 = Wifi.Install(wifiPhy143, mac, wifiStaNodes143);
	ns3::NetDeviceContainer staDevices144;
	staDevices144 = Wifi.Install(wifiPhy144, mac, wifiStaNodes144);
	ns3::NetDeviceContainer staDevices145;
	staDevices145 = Wifi.Install(wifiPhy145, mac, wifiStaNodes145);
	ns3::NetDeviceContainer staDevices146;
	staDevices146 = Wifi.Install(wifiPhy146, mac, wifiStaNodes146);
	ns3::NetDeviceContainer staDevices147;
	staDevices147 = Wifi.Install(wifiPhy147, mac, wifiStaNodes147);
	ns3::NetDeviceContainer staDevices148;
	staDevices148 = Wifi.Install(wifiPhy148, mac, wifiStaNodes148);
	ns3::NetDeviceContainer staDevices149;
	staDevices149 = Wifi.Install(wifiPhy149, mac, wifiStaNodes149);
	ns3::NetDeviceContainer staDevices150;
	staDevices150 = Wifi.Install(wifiPhy150, mac, wifiStaNodes150);
	ns3::NetDeviceContainer staDevices151;
	staDevices151 = Wifi.Install(wifiPhy151, mac, wifiStaNodes151);
	ns3::NetDeviceContainer staDevices152;
	staDevices152 = Wifi.Install(wifiPhy152, mac, wifiStaNodes152);
	ns3::NetDeviceContainer staDevices153;
	staDevices153 = Wifi.Install(wifiPhy153, mac, wifiStaNodes153);
	ns3::NetDeviceContainer staDevices154;
	staDevices154 = Wifi.Install(wifiPhy154, mac, wifiStaNodes154);
	ns3::NetDeviceContainer staDevices155;
	staDevices155 = Wifi.Install(wifiPhy155, mac, wifiStaNodes155);
	ns3::NetDeviceContainer staDevices156;
	staDevices156 = Wifi.Install(wifiPhy156, mac, wifiStaNodes156);
	ns3::NetDeviceContainer staDevices157;
	staDevices157 = Wifi.Install(wifiPhy157, mac, wifiStaNodes157);
	ns3::NetDeviceContainer staDevices158;
	staDevices158 = Wifi.Install(wifiPhy158, mac, wifiStaNodes158);
	ns3::NetDeviceContainer staDevices159;
	staDevices159 = Wifi.Install(wifiPhy159, mac, wifiStaNodes159);
	ns3::NetDeviceContainer staDevices160;
	staDevices160 = Wifi.Install(wifiPhy160, mac, wifiStaNodes160);
	ns3::NetDeviceContainer staDevices161;
	staDevices161 = Wifi.Install(wifiPhy161, mac, wifiStaNodes161);
	ns3::NetDeviceContainer staDevices162;
	staDevices162 = Wifi.Install(wifiPhy162, mac, wifiStaNodes162);
	ns3::NetDeviceContainer staDevices163;
	staDevices163 = Wifi.Install(wifiPhy163, mac, wifiStaNodes163);
	ns3::NetDeviceContainer staDevices164;
	staDevices164 = Wifi.Install(wifiPhy164, mac, wifiStaNodes164);
	ns3::NetDeviceContainer staDevices165;
	staDevices165 = Wifi.Install(wifiPhy165, mac, wifiStaNodes165);
	ns3::NetDeviceContainer staDevices166;
	staDevices166 = Wifi.Install(wifiPhy166, mac, wifiStaNodes166);
	ns3::NetDeviceContainer staDevices167;
	staDevices167 = Wifi.Install(wifiPhy167, mac, wifiStaNodes167);
	ns3::NetDeviceContainer staDevices168;
	staDevices168 = Wifi.Install(wifiPhy168, mac, wifiStaNodes168);
	ns3::NetDeviceContainer staDevices169;
	staDevices169 = Wifi.Install(wifiPhy169, mac, wifiStaNodes169);
	ns3::NetDeviceContainer staDevices170;
	staDevices170 = Wifi.Install(wifiPhy170, mac, wifiStaNodes170);
	ns3::NetDeviceContainer staDevices171;
	staDevices171 = Wifi.Install(wifiPhy171, mac, wifiStaNodes171);
	ns3::NetDeviceContainer staDevices172;
	staDevices172 = Wifi.Install(wifiPhy172, mac, wifiStaNodes172);
	ns3::NetDeviceContainer staDevices173;
	staDevices173 = Wifi.Install(wifiPhy173, mac, wifiStaNodes173);
	ns3::NetDeviceContainer staDevices174;
	staDevices174 = Wifi.Install(wifiPhy174, mac, wifiStaNodes174);
	ns3::NetDeviceContainer staDevices175;
	staDevices175 = Wifi.Install(wifiPhy175, mac, wifiStaNodes175);
	ns3::NetDeviceContainer staDevices176;
	staDevices176 = Wifi.Install(wifiPhy176, mac, wifiStaNodes176);
	ns3::NetDeviceContainer staDevices177;
	staDevices177 = Wifi.Install(wifiPhy177, mac, wifiStaNodes177);
	ns3::NetDeviceContainer staDevices178;
	staDevices178 = Wifi.Install(wifiPhy178, mac, wifiStaNodes178);
	ns3::NetDeviceContainer staDevices179;
	staDevices179 = Wifi.Install(wifiPhy179, mac, wifiStaNodes179);
	ns3::NetDeviceContainer staDevices180;
	staDevices180 = Wifi.Install(wifiPhy180, mac, wifiStaNodes180);
	ns3::NetDeviceContainer staDevices181;
	staDevices181 = Wifi.Install(wifiPhy181, mac, wifiStaNodes181);
	ns3::NetDeviceContainer staDevices182;
	staDevices182 = Wifi.Install(wifiPhy182, mac, wifiStaNodes182);
	ns3::NetDeviceContainer staDevices183;
	staDevices183 = Wifi.Install(wifiPhy183, mac, wifiStaNodes183);
	ns3::NetDeviceContainer staDevices184;
	staDevices184 = Wifi.Install(wifiPhy184, mac, wifiStaNodes184);
	ns3::NetDeviceContainer staDevices185;
	staDevices185 = Wifi.Install(wifiPhy185, mac, wifiStaNodes185);
	ns3::NetDeviceContainer staDevices186;
	staDevices186 = Wifi.Install(wifiPhy186, mac, wifiStaNodes186);
	ns3::NetDeviceContainer staDevices187;
	staDevices187 = Wifi.Install(wifiPhy187, mac, wifiStaNodes187);
	ns3::NetDeviceContainer staDevices188;
	staDevices188 = Wifi.Install(wifiPhy188, mac, wifiStaNodes188);
	ns3::NetDeviceContainer staDevices189;
	staDevices189 = Wifi.Install(wifiPhy189, mac, wifiStaNodes189);
	ns3::NetDeviceContainer staDevices190;
	staDevices190 = Wifi.Install(wifiPhy190, mac, wifiStaNodes190);
	ns3::NetDeviceContainer staDevices191;
	staDevices191 = Wifi.Install(wifiPhy191, mac, wifiStaNodes191);
	ns3::NetDeviceContainer staDevices192;
	staDevices192 = Wifi.Install(wifiPhy192, mac, wifiStaNodes192);
	ns3::NetDeviceContainer staDevices193;
	staDevices193 = Wifi.Install(wifiPhy193, mac, wifiStaNodes193);
	ns3::NetDeviceContainer staDevices194;
	staDevices194 = Wifi.Install(wifiPhy194, mac, wifiStaNodes194);
	ns3::NetDeviceContainer staDevices195;
	staDevices195 = Wifi.Install(wifiPhy195, mac, wifiStaNodes195);
	ns3::NetDeviceContainer staDevices196;
	staDevices196 = Wifi.Install(wifiPhy196, mac, wifiStaNodes196);
	ns3::NetDeviceContainer staDevices197;
	staDevices197 = Wifi.Install(wifiPhy197, mac, wifiStaNodes197);
	ns3::NetDeviceContainer staDevices198;
	staDevices198 = Wifi.Install(wifiPhy198, mac, wifiStaNodes198);
	ns3::NetDeviceContainer staDevices199;
	staDevices199 = Wifi.Install(wifiPhy199, mac, wifiStaNodes199);
	ns3::NetDeviceContainer staDevices200;
	staDevices200 = Wifi.Install(wifiPhy200, mac, wifiStaNodes200);
	ns3::NetDeviceContainer staDevices201;
	staDevices201 = Wifi.Install(wifiPhy201, mac, wifiStaNodes201);
	ns3::NetDeviceContainer staDevices202;
	staDevices202 = Wifi.Install(wifiPhy202, mac, wifiStaNodes202);
	ns3::NetDeviceContainer staDevices203;
	staDevices203 = Wifi.Install(wifiPhy203, mac, wifiStaNodes203);
	ns3::NetDeviceContainer staDevices204;
	staDevices204 = Wifi.Install(wifiPhy204, mac, wifiStaNodes204);
	ns3::NetDeviceContainer staDevices205;
	staDevices205 = Wifi.Install(wifiPhy205, mac, wifiStaNodes205);
	ns3::NetDeviceContainer staDevices206;
	staDevices206 = Wifi.Install(wifiPhy206, mac, wifiStaNodes206);
	ns3::NetDeviceContainer staDevices207;
	staDevices207 = Wifi.Install(wifiPhy207, mac, wifiStaNodes207);
	ns3::NetDeviceContainer staDevices208;
	staDevices208 = Wifi.Install(wifiPhy208, mac, wifiStaNodes208);
	ns3::NetDeviceContainer staDevices209;
	staDevices209 = Wifi.Install(wifiPhy209, mac, wifiStaNodes209);
	ns3::NetDeviceContainer staDevices210;
	staDevices210 = Wifi.Install(wifiPhy210, mac, wifiStaNodes210);
	ns3::NetDeviceContainer staDevices211;
	staDevices211 = Wifi.Install(wifiPhy211, mac, wifiStaNodes211);
	ns3::NetDeviceContainer staDevices212;
	staDevices212 = Wifi.Install(wifiPhy212, mac, wifiStaNodes212);
	ns3::NetDeviceContainer staDevices213;
	staDevices213 = Wifi.Install(wifiPhy213, mac, wifiStaNodes213);
	ns3::NetDeviceContainer staDevices214;
	staDevices214 = Wifi.Install(wifiPhy214, mac, wifiStaNodes214);
	ns3::NetDeviceContainer staDevices215;
	staDevices215 = Wifi.Install(wifiPhy215, mac, wifiStaNodes215);
	ns3::NetDeviceContainer staDevices216;
	staDevices216 = Wifi.Install(wifiPhy216, mac, wifiStaNodes216);
	ns3::NetDeviceContainer staDevices217;
	staDevices217 = Wifi.Install(wifiPhy217, mac, wifiStaNodes217);
	ns3::NetDeviceContainer staDevices218;
	staDevices218 = Wifi.Install(wifiPhy218, mac, wifiStaNodes218);
	ns3::NetDeviceContainer staDevices219;
	staDevices219 = Wifi.Install(wifiPhy219, mac, wifiStaNodes219);
	ns3::NetDeviceContainer staDevices220;
	staDevices220 = Wifi.Install(wifiPhy220, mac, wifiStaNodes220);
	ns3::NetDeviceContainer staDevices221;
	staDevices221 = Wifi.Install(wifiPhy221, mac, wifiStaNodes221);
	ns3::NetDeviceContainer staDevices222;
	staDevices222 = Wifi.Install(wifiPhy222, mac, wifiStaNodes222);
	ns3::NetDeviceContainer staDevices223;
	staDevices223 = Wifi.Install(wifiPhy223, mac, wifiStaNodes223);
	ns3::NetDeviceContainer staDevices224;
	staDevices224 = Wifi.Install(wifiPhy224, mac, wifiStaNodes224);
	ns3::NetDeviceContainer staDevices225;
	staDevices225 = Wifi.Install(wifiPhy225, mac, wifiStaNodes225);
	ns3::NetDeviceContainer staDevices226;
	staDevices226 = Wifi.Install(wifiPhy226, mac, wifiStaNodes226);
	ns3::NetDeviceContainer staDevices227;
	staDevices227 = Wifi.Install(wifiPhy227, mac, wifiStaNodes227);
	ns3::NetDeviceContainer staDevices228;
	staDevices228 = Wifi.Install(wifiPhy228, mac, wifiStaNodes228);
	ns3::NetDeviceContainer staDevices229;
	staDevices229 = Wifi.Install(wifiPhy229, mac, wifiStaNodes229);
	ns3::NetDeviceContainer staDevices230;
	staDevices230 = Wifi.Install(wifiPhy230, mac, wifiStaNodes230);
	ns3::NetDeviceContainer staDevices231;
	staDevices231 = Wifi.Install(wifiPhy231, mac, wifiStaNodes231);
	ns3::NetDeviceContainer staDevices232;
	staDevices232 = Wifi.Install(wifiPhy232, mac, wifiStaNodes232);
	ns3::NetDeviceContainer staDevices233;
	staDevices233 = Wifi.Install(wifiPhy233, mac, wifiStaNodes233);
	ns3::NetDeviceContainer staDevices234;
	staDevices234 = Wifi.Install(wifiPhy234, mac, wifiStaNodes234);
	ns3::NetDeviceContainer staDevices235;
	staDevices235 = Wifi.Install(wifiPhy235, mac, wifiStaNodes235);
	ns3::NetDeviceContainer staDevices236;
	staDevices236 = Wifi.Install(wifiPhy236, mac, wifiStaNodes236);
	ns3::NetDeviceContainer staDevices237;
	staDevices237 = Wifi.Install(wifiPhy237, mac, wifiStaNodes237);
	ns3::NetDeviceContainer staDevices238;
	staDevices238 = Wifi.Install(wifiPhy238, mac, wifiStaNodes238);
	ns3::NetDeviceContainer staDevices239;
	staDevices239 = Wifi.Install(wifiPhy239, mac, wifiStaNodes239);
	ns3::NetDeviceContainer staDevices240;
	staDevices240 = Wifi.Install(wifiPhy240, mac, wifiStaNodes240);
	ns3::NetDeviceContainer staDevices241;
	staDevices241 = Wifi.Install(wifiPhy241, mac, wifiStaNodes241);
	ns3::NetDeviceContainer staDevices242;
	staDevices242 = Wifi.Install(wifiPhy242, mac, wifiStaNodes242);
	ns3::NetDeviceContainer staDevices243;
	staDevices243 = Wifi.Install(wifiPhy243, mac, wifiStaNodes243);
	ns3::NetDeviceContainer staDevices244;
	staDevices244 = Wifi.Install(wifiPhy244, mac, wifiStaNodes244);
	ns3::NetDeviceContainer staDevices245;
	staDevices245 = Wifi.Install(wifiPhy245, mac, wifiStaNodes245);
	ns3::NetDeviceContainer staDevices246;
	staDevices246 = Wifi.Install(wifiPhy246, mac, wifiStaNodes246);
	ns3::NetDeviceContainer staDevices247;
	staDevices247 = Wifi.Install(wifiPhy247, mac, wifiStaNodes247);
	ns3::NetDeviceContainer staDevices248;
	staDevices248 = Wifi.Install(wifiPhy248, mac, wifiStaNodes248);
	ns3::NetDeviceContainer staDevices249;
	staDevices249 = Wifi.Install(wifiPhy249, mac, wifiStaNodes249);
	ns3::NetDeviceContainer staDevices250;
	staDevices250 = Wifi.Install(wifiPhy250, mac, wifiStaNodes250);
	ns3::NetDeviceContainer staDevices251;
	staDevices251 = Wifi.Install(wifiPhy251, mac, wifiStaNodes251);
	ns3::NetDeviceContainer staDevices252;
	staDevices252 = Wifi.Install(wifiPhy252, mac, wifiStaNodes252);
	ns3::NetDeviceContainer staDevices253;
	staDevices253 = Wifi.Install(wifiPhy253, mac, wifiStaNodes253);
	ns3::NetDeviceContainer staDevices254;
	staDevices254 = Wifi.Install(wifiPhy254, mac, wifiStaNodes254);
	ns3::NetDeviceContainer staDevices255;
	staDevices255 = Wifi.Install(wifiPhy255, mac, wifiStaNodes255);
	ns3::NetDeviceContainer staDevices256;
	staDevices256 = Wifi.Install(wifiPhy256, mac, wifiStaNodes256);
	ns3::NetDeviceContainer staDevices257;
	staDevices257 = Wifi.Install(wifiPhy257, mac, wifiStaNodes257);
	ns3::NetDeviceContainer staDevices258;
	staDevices258 = Wifi.Install(wifiPhy258, mac, wifiStaNodes258);
	ns3::NetDeviceContainer staDevices259;
	staDevices259 = Wifi.Install(wifiPhy259, mac, wifiStaNodes259);
	ns3::NetDeviceContainer staDevices260;
	staDevices260 = Wifi.Install(wifiPhy260, mac, wifiStaNodes260);
	ns3::NetDeviceContainer staDevices261;
	staDevices261 = Wifi.Install(wifiPhy261, mac, wifiStaNodes261);
	ns3::NetDeviceContainer staDevices262;
	staDevices262 = Wifi.Install(wifiPhy262, mac, wifiStaNodes262);
	ns3::NetDeviceContainer staDevices263;
	staDevices263 = Wifi.Install(wifiPhy263, mac, wifiStaNodes263);
	ns3::NetDeviceContainer staDevices264;
	staDevices264 = Wifi.Install(wifiPhy264, mac, wifiStaNodes264);
	ns3::NetDeviceContainer staDevices265;
	staDevices265 = Wifi.Install(wifiPhy265, mac, wifiStaNodes265);
	ns3::NetDeviceContainer staDevices266;
	staDevices266 = Wifi.Install(wifiPhy266, mac, wifiStaNodes266);
	ns3::NetDeviceContainer staDevices267;
	staDevices267 = Wifi.Install(wifiPhy267, mac, wifiStaNodes267);
	ns3::NetDeviceContainer staDevices268;
	staDevices268 = Wifi.Install(wifiPhy268, mac, wifiStaNodes268);
	ns3::NetDeviceContainer staDevices269;
	staDevices269 = Wifi.Install(wifiPhy269, mac, wifiStaNodes269);
	ns3::NetDeviceContainer staDevices270;
	staDevices270 = Wifi.Install(wifiPhy270, mac, wifiStaNodes270);
	ns3::NetDeviceContainer staDevices271;
	staDevices271 = Wifi.Install(wifiPhy271, mac, wifiStaNodes271);
	ns3::NetDeviceContainer staDevices272;
	staDevices272 = Wifi.Install(wifiPhy272, mac, wifiStaNodes272);
	ns3::NetDeviceContainer staDevices273;
	staDevices273 = Wifi.Install(wifiPhy273, mac, wifiStaNodes273);
	ns3::NetDeviceContainer staDevices274;
	staDevices274 = Wifi.Install(wifiPhy274, mac, wifiStaNodes274);
	ns3::NetDeviceContainer staDevices275;
	staDevices275 = Wifi.Install(wifiPhy275, mac, wifiStaNodes275);
	ns3::NetDeviceContainer staDevices276;
	staDevices276 = Wifi.Install(wifiPhy276, mac, wifiStaNodes276);
	ns3::NetDeviceContainer staDevices277;
	staDevices277 = Wifi.Install(wifiPhy277, mac, wifiStaNodes277);
	ns3::NetDeviceContainer staDevices278;
	staDevices278 = Wifi.Install(wifiPhy278, mac, wifiStaNodes278);
	ns3::NetDeviceContainer staDevices279;
	staDevices279 = Wifi.Install(wifiPhy279, mac, wifiStaNodes279);
	ns3::NetDeviceContainer staDevices280;
	staDevices280 = Wifi.Install(wifiPhy280, mac, wifiStaNodes280);
	ns3::NetDeviceContainer staDevices281;
	staDevices281 = Wifi.Install(wifiPhy281, mac, wifiStaNodes281);
	ns3::NetDeviceContainer staDevices282;
	staDevices282 = Wifi.Install(wifiPhy282, mac, wifiStaNodes282);
	ns3::NetDeviceContainer staDevices283;
	staDevices283 = Wifi.Install(wifiPhy283, mac, wifiStaNodes283);
	ns3::NetDeviceContainer staDevices284;
	staDevices284 = Wifi.Install(wifiPhy284, mac, wifiStaNodes284);
	ns3::NetDeviceContainer staDevices285;
	staDevices285 = Wifi.Install(wifiPhy285, mac, wifiStaNodes285);
	ns3::NetDeviceContainer staDevices286;
	staDevices286 = Wifi.Install(wifiPhy286, mac, wifiStaNodes286);
	ns3::NetDeviceContainer staDevices287;
	staDevices287 = Wifi.Install(wifiPhy287, mac, wifiStaNodes287);
	ns3::NetDeviceContainer staDevices288;
	staDevices288 = Wifi.Install(wifiPhy288, mac, wifiStaNodes288);
	ns3::NetDeviceContainer staDevices289;
	staDevices289 = Wifi.Install(wifiPhy289, mac, wifiStaNodes289);
	ns3::NetDeviceContainer staDevices290;
	staDevices290 = Wifi.Install(wifiPhy290, mac, wifiStaNodes290);
	ns3::NetDeviceContainer staDevices291;
	staDevices291 = Wifi.Install(wifiPhy291, mac, wifiStaNodes291);
	ns3::NetDeviceContainer staDevices292;
	staDevices292 = Wifi.Install(wifiPhy292, mac, wifiStaNodes292);
	ns3::NetDeviceContainer staDevices293;
	staDevices293 = Wifi.Install(wifiPhy293, mac, wifiStaNodes293);
	ns3::NetDeviceContainer staDevices294;
	staDevices294 = Wifi.Install(wifiPhy294, mac, wifiStaNodes294);
	ns3::NetDeviceContainer staDevices295;
	staDevices295 = Wifi.Install(wifiPhy295, mac, wifiStaNodes295);
	ns3::NetDeviceContainer staDevices296;
	staDevices296 = Wifi.Install(wifiPhy296, mac, wifiStaNodes296);
	ns3::NetDeviceContainer staDevices297;
	staDevices297 = Wifi.Install(wifiPhy297, mac, wifiStaNodes297);
//    staDevices298 = Wifi.Install (wifiPhy298, mac, wifiStaNodes298)
//    staDevices299 = Wifi.Install (wifiPhy299, mac, wifiStaNodes299)
	ns3::NetDeviceContainer staDevices300;
	staDevices300 = Wifi.Install(wifiPhy300, mac, wifiStaNodes300);
	ns3::NetDeviceContainer staDevices301;
	staDevices301 = Wifi.Install(wifiPhy301, mac, wifiStaNodes301);
	ns3::NetDeviceContainer staDevices302;
	staDevices302 = Wifi.Install(wifiPhy302, mac, wifiStaNodes302);
	ns3::NetDeviceContainer staDevices303;
	staDevices303 = Wifi.Install(wifiPhy303, mac, wifiStaNodes303);
	ns3::NetDeviceContainer staDevices304;
	staDevices304 = Wifi.Install(wifiPhy304, mac, wifiStaNodes304);
	ns3::NetDeviceContainer staDevices305;
	staDevices305 = Wifi.Install(wifiPhy305, mac, wifiStaNodes305);
//    staDevices306 = Wifi.Install (wifiPhy306, mac, wifiStaNodes306)
	ns3::NetDeviceContainer staDevices307;
	staDevices307 = Wifi.Install(wifiPhy307, mac, wifiStaNodes307);
	ns3::NetDeviceContainer staDevices308;
	staDevices308 = Wifi.Install(wifiPhy308, mac, wifiStaNodes308);
	ns3::NetDeviceContainer staDevices309;
	staDevices309 = Wifi.Install(wifiPhy309, mac, wifiStaNodes309);
	ns3::NetDeviceContainer staDevices310;
	staDevices310 = Wifi.Install(wifiPhy310, mac, wifiStaNodes310);
	ns3::NetDeviceContainer staDevices311;
	staDevices311 = Wifi.Install(wifiPhy311, mac, wifiStaNodes311);
	ns3::NetDeviceContainer staDevices312;
	staDevices312 = Wifi.Install(wifiPhy312, mac, wifiStaNodes312);
	ns3::NetDeviceContainer staDevices313;
	staDevices313 = Wifi.Install(wifiPhy313, mac, wifiStaNodes313);
	ns3::NetDeviceContainer staDevices314;
	staDevices314 = Wifi.Install(wifiPhy314, mac, wifiStaNodes314);
//    staDevices315 = Wifi.Install (wifiPhy315, mac, wifiStaNodes315)

// apnodes mac
	mac.SetType("ns3::ApWifiMac", "Ssid", ns3::SsidValue(ssid),
			"BeaconGeneration", ns3::BooleanValue(true), "BeaconInterval",
			ns3::TimeValue(ns3::Seconds(2.5)));
	ns3::NetDeviceContainer apDevices1;
	apDevices1 = Wifi.Install(wifiPhy, mac, wifiApNode1);
	ns3::NetDeviceContainer apDevices2;
	apDevices2 = Wifi.Install(wifiPhy2, mac, wifiApNode2);
	ns3::NetDeviceContainer apDevices3;
	apDevices3 = Wifi.Install(wifiPhy3, mac, wifiApNode3);
	ns3::NetDeviceContainer apDevices4;
	apDevices4 = Wifi.Install(wifiPhy4, mac, wifiApNode4);
	ns3::NetDeviceContainer apDevices5;
	apDevices5 = Wifi.Install(wifiPhy5, mac, wifiApNode5);
	ns3::NetDeviceContainer apDevices6;
	apDevices6 = Wifi.Install(wifiPhy6, mac, wifiApNode6);
	ns3::NetDeviceContainer apDevices7;
	apDevices7 = Wifi.Install(wifiPhy7, mac, wifiApNode7);
	ns3::NetDeviceContainer apDevices8;
	apDevices8 = Wifi.Install(wifiPhy8, mac, wifiApNode8);
	ns3::NetDeviceContainer apDevices9;
	apDevices9 = Wifi.Install(wifiPhy9, mac, wifiApNode9);
	ns3::NetDeviceContainer apDevices10;
	apDevices10 = Wifi.Install(wifiPhy10, mac, wifiApNode10);
	ns3::NetDeviceContainer apDevices11;
	apDevices11 = Wifi.Install(wifiPhy11, mac, wifiApNode11);
	ns3::NetDeviceContainer apDevices12;
	apDevices12 = Wifi.Install(wifiPhy12, mac, wifiApNode12);
	ns3::NetDeviceContainer apDevices13;
	apDevices13 = Wifi.Install(wifiPhy13, mac, wifiApNode13);
	ns3::NetDeviceContainer apDevices14;
	apDevices14 = Wifi.Install(wifiPhy14, mac, wifiApNode14);
	ns3::NetDeviceContainer apDevices15;
	apDevices15 = Wifi.Install(wifiPhy15, mac, wifiApNode15);
	ns3::NetDeviceContainer apDevices16;
	apDevices16 = Wifi.Install(wifiPhy16, mac, wifiApNode16);
	ns3::NetDeviceContainer apDevices17;
	apDevices17 = Wifi.Install(wifiPhy17, mac, wifiApNode17);
	ns3::NetDeviceContainer apDevices18;
	apDevices18 = Wifi.Install(wifiPhy18, mac, wifiApNode18);
	ns3::NetDeviceContainer apDevices19;
	apDevices19 = Wifi.Install(wifiPhy19, mac, wifiApNode19);
	ns3::NetDeviceContainer apDevices20;
	apDevices20 = Wifi.Install(wifiPhy20, mac, wifiApNode20);
	ns3::NetDeviceContainer apDevices21;
	apDevices21 = Wifi.Install(wifiPhy21, mac, wifiApNode21);
	ns3::NetDeviceContainer apDevices22;
	apDevices22 = Wifi.Install(wifiPhy22, mac, wifiApNode22);
	ns3::NetDeviceContainer apDevices23;
	apDevices23 = Wifi.Install(wifiPhy23, mac, wifiApNode23);
	ns3::NetDeviceContainer apDevices24;
	apDevices24 = Wifi.Install(wifiPhy24, mac, wifiApNode24);
	ns3::NetDeviceContainer apDevices25;
	apDevices25 = Wifi.Install(wifiPhy25, mac, wifiApNode25);
	ns3::NetDeviceContainer apDevices26;
	apDevices26 = Wifi.Install(wifiPhy26, mac, wifiApNode26);
	ns3::NetDeviceContainer apDevices27;
	apDevices27 = Wifi.Install(wifiPhy27, mac, wifiApNode27);
	ns3::NetDeviceContainer apDevices28;
	apDevices28 = Wifi.Install(wifiPhy28, mac, wifiApNode28);
	ns3::NetDeviceContainer apDevices29;
	apDevices29 = Wifi.Install(wifiPhy29, mac, wifiApNode29);
	ns3::NetDeviceContainer apDevices30;
	apDevices30 = Wifi.Install(wifiPhy30, mac, wifiApNode30);
	ns3::NetDeviceContainer apDevices31;
	apDevices31 = Wifi.Install(wifiPhy31, mac, wifiApNode31);
	ns3::NetDeviceContainer apDevices32;
	apDevices32 = Wifi.Install(wifiPhy32, mac, wifiApNode32);
	ns3::NetDeviceContainer apDevices33;
	apDevices33 = Wifi.Install(wifiPhy33, mac, wifiApNode33);
	ns3::NetDeviceContainer apDevices34;
	apDevices34 = Wifi.Install(wifiPhy34, mac, wifiApNode34);
	ns3::NetDeviceContainer apDevices35;
	apDevices35 = Wifi.Install(wifiPhy35, mac, wifiApNode35);
	ns3::NetDeviceContainer apDevices36;
	apDevices36 = Wifi.Install(wifiPhy36, mac, wifiApNode36);
	ns3::NetDeviceContainer apDevices37;
	apDevices37 = Wifi.Install(wifiPhy37, mac, wifiApNode37);
	ns3::NetDeviceContainer apDevices38;
	apDevices38 = Wifi.Install(wifiPhy38, mac, wifiApNode38);
	ns3::NetDeviceContainer apDevices39;
	apDevices39 = Wifi.Install(wifiPhy39, mac, wifiApNode39);
	ns3::NetDeviceContainer apDevices40;
	apDevices40 = Wifi.Install(wifiPhy40, mac, wifiApNode40);
	ns3::NetDeviceContainer apDevices41;
	apDevices41 = Wifi.Install(wifiPhy41, mac, wifiApNode41);
	ns3::NetDeviceContainer apDevices42;
	apDevices42 = Wifi.Install(wifiPhy42, mac, wifiApNode42);
	ns3::NetDeviceContainer apDevices43;
	apDevices43 = Wifi.Install(wifiPhy43, mac, wifiApNode43);
	ns3::NetDeviceContainer apDevices44;
	apDevices44 = Wifi.Install(wifiPhy44, mac, wifiApNode44);
	ns3::NetDeviceContainer apDevices45;
	apDevices45 = Wifi.Install(wifiPhy45, mac, wifiApNode45);
	ns3::NetDeviceContainer apDevices46;
	apDevices46 = Wifi.Install(wifiPhy46, mac, wifiApNode46);
	ns3::NetDeviceContainer apDevices47;
	apDevices47 = Wifi.Install(wifiPhy47, mac, wifiApNode47);
	ns3::NetDeviceContainer apDevices48;
	apDevices48 = Wifi.Install(wifiPhy48, mac, wifiApNode48);
	ns3::NetDeviceContainer apDevices49;
	apDevices49 = Wifi.Install(wifiPhy49, mac, wifiApNode49);
	ns3::NetDeviceContainer apDevices50;
	apDevices50 = Wifi.Install(wifiPhy50, mac, wifiApNode50);
	ns3::NetDeviceContainer apDevices51;
	apDevices51 = Wifi.Install(wifiPhy51, mac, wifiApNode51);
	ns3::NetDeviceContainer apDevices52;
	apDevices52 = Wifi.Install(wifiPhy52, mac, wifiApNode52);
	ns3::NetDeviceContainer apDevices53;
	apDevices53 = Wifi.Install(wifiPhy53, mac, wifiApNode53);
	ns3::NetDeviceContainer apDevices54;
	apDevices54 = Wifi.Install(wifiPhy54, mac, wifiApNode54);
	ns3::NetDeviceContainer apDevices55;
	apDevices55 = Wifi.Install(wifiPhy55, mac, wifiApNode55);
	ns3::NetDeviceContainer apDevices56;
	apDevices56 = Wifi.Install(wifiPhy56, mac, wifiApNode56);
	ns3::NetDeviceContainer apDevices57;
	apDevices57 = Wifi.Install(wifiPhy57, mac, wifiApNode57);
	ns3::NetDeviceContainer apDevices58;
	apDevices58 = Wifi.Install(wifiPhy58, mac, wifiApNode58);
	ns3::NetDeviceContainer apDevices59;
	apDevices59 = Wifi.Install(wifiPhy59, mac, wifiApNode59);
	ns3::NetDeviceContainer apDevices60;
	apDevices60 = Wifi.Install(wifiPhy60, mac, wifiApNode60);
	ns3::NetDeviceContainer apDevices61;
	apDevices61 = Wifi.Install(wifiPhy61, mac, wifiApNode61);
	ns3::NetDeviceContainer apDevices62;
	apDevices62 = Wifi.Install(wifiPhy62, mac, wifiApNode62);
	ns3::NetDeviceContainer apDevices63;
	apDevices63 = Wifi.Install(wifiPhy63, mac, wifiApNode63);
	ns3::NetDeviceContainer apDevices64;
	apDevices64 = Wifi.Install(wifiPhy64, mac, wifiApNode64);
	ns3::NetDeviceContainer apDevices65;
	apDevices65 = Wifi.Install(wifiPhy65, mac, wifiApNode65);
	ns3::NetDeviceContainer apDevices66;
	apDevices66 = Wifi.Install(wifiPhy66, mac, wifiApNode66);
	ns3::NetDeviceContainer apDevices67;
	apDevices67 = Wifi.Install(wifiPhy67, mac, wifiApNode67);
	ns3::NetDeviceContainer apDevices68;
	apDevices68 = Wifi.Install(wifiPhy68, mac, wifiApNode68);
	ns3::NetDeviceContainer apDevices69;
	apDevices69 = Wifi.Install(wifiPhy69, mac, wifiApNode69);
	ns3::NetDeviceContainer apDevices70;
	apDevices70 = Wifi.Install(wifiPhy70, mac, wifiApNode70);
	ns3::NetDeviceContainer apDevices71;
	apDevices71 = Wifi.Install(wifiPhy71, mac, wifiApNode71);
	ns3::NetDeviceContainer apDevices72;
	apDevices72 = Wifi.Install(wifiPhy72, mac, wifiApNode72);
	ns3::NetDeviceContainer apDevices73;
	apDevices73 = Wifi.Install(wifiPhy73, mac, wifiApNode73);
	ns3::NetDeviceContainer apDevices74;
	apDevices74 = Wifi.Install(wifiPhy74, mac, wifiApNode74);
	ns3::NetDeviceContainer apDevices75;
	apDevices75 = Wifi.Install(wifiPhy75, mac, wifiApNode75);
	ns3::NetDeviceContainer apDevices76;
	apDevices76 = Wifi.Install(wifiPhy76, mac, wifiApNode76);
	ns3::NetDeviceContainer apDevices77;
	apDevices77 = Wifi.Install(wifiPhy77, mac, wifiApNode77);
	ns3::NetDeviceContainer apDevices78;
	apDevices78 = Wifi.Install(wifiPhy78, mac, wifiApNode78);
	ns3::NetDeviceContainer apDevices79;
	apDevices79 = Wifi.Install(wifiPhy79, mac, wifiApNode79);
	ns3::NetDeviceContainer apDevices80;
	apDevices80 = Wifi.Install(wifiPhy80, mac, wifiApNode80);
	ns3::NetDeviceContainer apDevices81;
	apDevices81 = Wifi.Install(wifiPhy81, mac, wifiApNode81);
	ns3::NetDeviceContainer apDevices82;
	apDevices82 = Wifi.Install(wifiPhy82, mac, wifiApNode82);
	ns3::NetDeviceContainer apDevices83;
	apDevices83 = Wifi.Install(wifiPhy83, mac, wifiApNode83);
	ns3::NetDeviceContainer apDevices84;
	apDevices84 = Wifi.Install(wifiPhy84, mac, wifiApNode84);
	ns3::NetDeviceContainer apDevices85;
	apDevices85 = Wifi.Install(wifiPhy85, mac, wifiApNode85);
	ns3::NetDeviceContainer apDevices86;
	apDevices86 = Wifi.Install(wifiPhy86, mac, wifiApNode86);
	ns3::NetDeviceContainer apDevices87;
	apDevices87 = Wifi.Install(wifiPhy87, mac, wifiApNode87);
	ns3::NetDeviceContainer apDevices88;
	apDevices88 = Wifi.Install(wifiPhy88, mac, wifiApNode88);
	ns3::NetDeviceContainer apDevices89;
	apDevices89 = Wifi.Install(wifiPhy89, mac, wifiApNode89);
	ns3::NetDeviceContainer apDevices90;
	apDevices90 = Wifi.Install(wifiPhy90, mac, wifiApNode90);
	ns3::NetDeviceContainer apDevices91;
	apDevices91 = Wifi.Install(wifiPhy91, mac, wifiApNode91);
	ns3::NetDeviceContainer apDevices92;
	apDevices92 = Wifi.Install(wifiPhy92, mac, wifiApNode92);
	ns3::NetDeviceContainer apDevices93;
	apDevices93 = Wifi.Install(wifiPhy93, mac, wifiApNode93);
	ns3::NetDeviceContainer apDevices94;
	apDevices94 = Wifi.Install(wifiPhy94, mac, wifiApNode94);
	ns3::NetDeviceContainer apDevices95;
	apDevices95 = Wifi.Install(wifiPhy95, mac, wifiApNode95);
	ns3::NetDeviceContainer apDevices96;
	apDevices96 = Wifi.Install(wifiPhy96, mac, wifiApNode96);
	ns3::NetDeviceContainer apDevices97;
	apDevices97 = Wifi.Install(wifiPhy97, mac, wifiApNode97);
	ns3::NetDeviceContainer apDevices98;
	apDevices98 = Wifi.Install(wifiPhy98, mac, wifiApNode98);
	ns3::NetDeviceContainer apDevices99;
	apDevices99 = Wifi.Install(wifiPhy99, mac, wifiApNode99);
	ns3::NetDeviceContainer apDevices100;
	apDevices100 = Wifi.Install(wifiPhy100, mac, wifiApNode100);
	ns3::NetDeviceContainer apDevices101;
	apDevices101 = Wifi.Install(wifiPhy101, mac, wifiApNode101);
	ns3::NetDeviceContainer apDevices102;
	apDevices102 = Wifi.Install(wifiPhy102, mac, wifiApNode102);
	ns3::NetDeviceContainer apDevices103;
	apDevices103 = Wifi.Install(wifiPhy103, mac, wifiApNode103);
	ns3::NetDeviceContainer apDevices104;
	apDevices104 = Wifi.Install(wifiPhy104, mac, wifiApNode104);
	ns3::NetDeviceContainer apDevices105;
	apDevices105 = Wifi.Install(wifiPhy105, mac, wifiApNode105);
	ns3::NetDeviceContainer apDevices106;
	apDevices106 = Wifi.Install(wifiPhy106, mac, wifiApNode106);
	ns3::NetDeviceContainer apDevices107;
	apDevices107 = Wifi.Install(wifiPhy107, mac, wifiApNode107);
	ns3::NetDeviceContainer apDevices108;
	apDevices108 = Wifi.Install(wifiPhy108, mac, wifiApNode108);
	ns3::NetDeviceContainer apDevices109;
	apDevices109 = Wifi.Install(wifiPhy109, mac, wifiApNode109);
	ns3::NetDeviceContainer apDevices110;
	apDevices110 = Wifi.Install(wifiPhy110, mac, wifiApNode110);
	ns3::NetDeviceContainer apDevices111;
	apDevices111 = Wifi.Install(wifiPhy111, mac, wifiApNode111);
	ns3::NetDeviceContainer apDevices112;
	apDevices112 = Wifi.Install(wifiPhy112, mac, wifiApNode112);
	ns3::NetDeviceContainer apDevices113;
	apDevices113 = Wifi.Install(wifiPhy113, mac, wifiApNode113);
	ns3::NetDeviceContainer apDevices114;
	apDevices114 = Wifi.Install(wifiPhy114, mac, wifiApNode114);
	ns3::NetDeviceContainer apDevices115;
	apDevices115 = Wifi.Install(wifiPhy115, mac, wifiApNode115);
	ns3::NetDeviceContainer apDevices116;
	apDevices116 = Wifi.Install(wifiPhy116, mac, wifiApNode116);
	ns3::NetDeviceContainer apDevices117;
	apDevices117 = Wifi.Install(wifiPhy117, mac, wifiApNode117);
	ns3::NetDeviceContainer apDevices118;
	apDevices118 = Wifi.Install(wifiPhy118, mac, wifiApNode118);
	ns3::NetDeviceContainer apDevices119;
	apDevices119 = Wifi.Install(wifiPhy119, mac, wifiApNode119);
	ns3::NetDeviceContainer apDevices120;
	apDevices120 = Wifi.Install(wifiPhy120, mac, wifiApNode120);
	ns3::NetDeviceContainer apDevices121;
	apDevices121 = Wifi.Install(wifiPhy121, mac, wifiApNode121);
	ns3::NetDeviceContainer apDevices122;
	apDevices122 = Wifi.Install(wifiPhy122, mac, wifiApNode122);
	ns3::NetDeviceContainer apDevices123;
	apDevices123 = Wifi.Install(wifiPhy123, mac, wifiApNode123);
	ns3::NetDeviceContainer apDevices124;
	apDevices124 = Wifi.Install(wifiPhy124, mac, wifiApNode124);
	ns3::NetDeviceContainer apDevices125;
	apDevices125 = Wifi.Install(wifiPhy125, mac, wifiApNode125);
	ns3::NetDeviceContainer apDevices126;
	apDevices126 = Wifi.Install(wifiPhy126, mac, wifiApNode126);
	ns3::NetDeviceContainer apDevices127;
	apDevices127 = Wifi.Install(wifiPhy127, mac, wifiApNode127);
	ns3::NetDeviceContainer apDevices128;
	apDevices128 = Wifi.Install(wifiPhy128, mac, wifiApNode128);
	ns3::NetDeviceContainer apDevices129;
	apDevices129 = Wifi.Install(wifiPhy129, mac, wifiApNode129);
	ns3::NetDeviceContainer apDevices130;
	apDevices130 = Wifi.Install(wifiPhy130, mac, wifiApNode130);
	ns3::NetDeviceContainer apDevices131;
	apDevices131 = Wifi.Install(wifiPhy131, mac, wifiApNode131);
	ns3::NetDeviceContainer apDevices132;
	apDevices132 = Wifi.Install(wifiPhy132, mac, wifiApNode132);
	ns3::NetDeviceContainer apDevices133;
	apDevices133 = Wifi.Install(wifiPhy133, mac, wifiApNode133);
	ns3::NetDeviceContainer apDevices134;
	apDevices134 = Wifi.Install(wifiPhy134, mac, wifiApNode134);
	ns3::NetDeviceContainer apDevices135;
	apDevices135 = Wifi.Install(wifiPhy135, mac, wifiApNode135);
	ns3::NetDeviceContainer apDevices136;
	apDevices136 = Wifi.Install(wifiPhy136, mac, wifiApNode136);
	ns3::NetDeviceContainer apDevices137;
	apDevices137 = Wifi.Install(wifiPhy137, mac, wifiApNode137);
	ns3::NetDeviceContainer apDevices138;
	apDevices138 = Wifi.Install(wifiPhy138, mac, wifiApNode138);
	ns3::NetDeviceContainer apDevices139;
	apDevices139 = Wifi.Install(wifiPhy139, mac, wifiApNode139);
	ns3::NetDeviceContainer apDevices140;
	apDevices140 = Wifi.Install(wifiPhy140, mac, wifiApNode140);
	ns3::NetDeviceContainer apDevices141;
	apDevices141 = Wifi.Install(wifiPhy141, mac, wifiApNode141);
	ns3::NetDeviceContainer apDevices142;
	apDevices142 = Wifi.Install(wifiPhy142, mac, wifiApNode142);
	ns3::NetDeviceContainer apDevices143;
	apDevices143 = Wifi.Install(wifiPhy143, mac, wifiApNode143);
	ns3::NetDeviceContainer apDevices144;
	apDevices144 = Wifi.Install(wifiPhy144, mac, wifiApNode144);
	ns3::NetDeviceContainer apDevices145;
	apDevices145 = Wifi.Install(wifiPhy145, mac, wifiApNode145);
	ns3::NetDeviceContainer apDevices146;
	apDevices146 = Wifi.Install(wifiPhy146, mac, wifiApNode146);
	ns3::NetDeviceContainer apDevices147;
	apDevices147 = Wifi.Install(wifiPhy147, mac, wifiApNode147);
	ns3::NetDeviceContainer apDevices148;
	apDevices148 = Wifi.Install(wifiPhy148, mac, wifiApNode148);
	ns3::NetDeviceContainer apDevices149;
	apDevices149 = Wifi.Install(wifiPhy149, mac, wifiApNode149);
	ns3::NetDeviceContainer apDevices150;
	apDevices150 = Wifi.Install(wifiPhy150, mac, wifiApNode150);
	ns3::NetDeviceContainer apDevices151;
	apDevices151 = Wifi.Install(wifiPhy151, mac, wifiApNode151);
	ns3::NetDeviceContainer apDevices152;
	apDevices152 = Wifi.Install(wifiPhy152, mac, wifiApNode152);
	ns3::NetDeviceContainer apDevices153;
	apDevices153 = Wifi.Install(wifiPhy153, mac, wifiApNode153);
	ns3::NetDeviceContainer apDevices154;
	apDevices154 = Wifi.Install(wifiPhy154, mac, wifiApNode154);
	ns3::NetDeviceContainer apDevices155;
	apDevices155 = Wifi.Install(wifiPhy155, mac, wifiApNode155);
	ns3::NetDeviceContainer apDevices156;
	apDevices156 = Wifi.Install(wifiPhy156, mac, wifiApNode156);
	ns3::NetDeviceContainer apDevices157;
	apDevices157 = Wifi.Install(wifiPhy157, mac, wifiApNode157);
	ns3::NetDeviceContainer apDevices158;
	apDevices158 = Wifi.Install(wifiPhy158, mac, wifiApNode158);
	ns3::NetDeviceContainer apDevices159;
	apDevices159 = Wifi.Install(wifiPhy159, mac, wifiApNode159);
	ns3::NetDeviceContainer apDevices160;
	apDevices160 = Wifi.Install(wifiPhy160, mac, wifiApNode160);
	ns3::NetDeviceContainer apDevices161;
	apDevices161 = Wifi.Install(wifiPhy161, mac, wifiApNode161);
	ns3::NetDeviceContainer apDevices162;
	apDevices162 = Wifi.Install(wifiPhy162, mac, wifiApNode162);
	ns3::NetDeviceContainer apDevices163;
	apDevices163 = Wifi.Install(wifiPhy163, mac, wifiApNode163);
	ns3::NetDeviceContainer apDevices164;
	apDevices164 = Wifi.Install(wifiPhy164, mac, wifiApNode164);
	ns3::NetDeviceContainer apDevices165;
	apDevices165 = Wifi.Install(wifiPhy165, mac, wifiApNode165);
	ns3::NetDeviceContainer apDevices166;
	apDevices166 = Wifi.Install(wifiPhy166, mac, wifiApNode166);
	ns3::NetDeviceContainer apDevices167;
	apDevices167 = Wifi.Install(wifiPhy167, mac, wifiApNode167);
	ns3::NetDeviceContainer apDevices168;
	apDevices168 = Wifi.Install(wifiPhy168, mac, wifiApNode168);
	ns3::NetDeviceContainer apDevices169;
	apDevices169 = Wifi.Install(wifiPhy169, mac, wifiApNode169);
	ns3::NetDeviceContainer apDevices170;
	apDevices170 = Wifi.Install(wifiPhy170, mac, wifiApNode170);
	ns3::NetDeviceContainer apDevices171;
	apDevices171 = Wifi.Install(wifiPhy171, mac, wifiApNode171);
	ns3::NetDeviceContainer apDevices172;
	apDevices172 = Wifi.Install(wifiPhy172, mac, wifiApNode172);
	ns3::NetDeviceContainer apDevices173;
	apDevices173 = Wifi.Install(wifiPhy173, mac, wifiApNode173);
	ns3::NetDeviceContainer apDevices174;
	apDevices174 = Wifi.Install(wifiPhy174, mac, wifiApNode174);
	ns3::NetDeviceContainer apDevices175;
	apDevices175 = Wifi.Install(wifiPhy175, mac, wifiApNode175);
	ns3::NetDeviceContainer apDevices176;
	apDevices176 = Wifi.Install(wifiPhy176, mac, wifiApNode176);
	ns3::NetDeviceContainer apDevices177;
	apDevices177 = Wifi.Install(wifiPhy177, mac, wifiApNode177);
	ns3::NetDeviceContainer apDevices178;
	apDevices178 = Wifi.Install(wifiPhy178, mac, wifiApNode178);
	ns3::NetDeviceContainer apDevices179;
	apDevices179 = Wifi.Install(wifiPhy179, mac, wifiApNode179);
	ns3::NetDeviceContainer apDevices180;
	apDevices180 = Wifi.Install(wifiPhy180, mac, wifiApNode180);
	ns3::NetDeviceContainer apDevices181;
	apDevices181 = Wifi.Install(wifiPhy181, mac, wifiApNode181);
	ns3::NetDeviceContainer apDevices182;
	apDevices182 = Wifi.Install(wifiPhy182, mac, wifiApNode182);
	ns3::NetDeviceContainer apDevices183;
	apDevices183 = Wifi.Install(wifiPhy183, mac, wifiApNode183);
	ns3::NetDeviceContainer apDevices184;
	apDevices184 = Wifi.Install(wifiPhy184, mac, wifiApNode184);
	ns3::NetDeviceContainer apDevices185;
	apDevices185 = Wifi.Install(wifiPhy185, mac, wifiApNode185);
	ns3::NetDeviceContainer apDevices186;
	apDevices186 = Wifi.Install(wifiPhy186, mac, wifiApNode186);
	ns3::NetDeviceContainer apDevices187;
	apDevices187 = Wifi.Install(wifiPhy187, mac, wifiApNode187);
	ns3::NetDeviceContainer apDevices188;
	apDevices188 = Wifi.Install(wifiPhy188, mac, wifiApNode188);
	ns3::NetDeviceContainer apDevices189;
	apDevices189 = Wifi.Install(wifiPhy189, mac, wifiApNode189);
	ns3::NetDeviceContainer apDevices190;
	apDevices190 = Wifi.Install(wifiPhy190, mac, wifiApNode190);
	ns3::NetDeviceContainer apDevices191;
	apDevices191 = Wifi.Install(wifiPhy191, mac, wifiApNode191);
	ns3::NetDeviceContainer apDevices192;
	apDevices192 = Wifi.Install(wifiPhy192, mac, wifiApNode192);
	ns3::NetDeviceContainer apDevices193;
	apDevices193 = Wifi.Install(wifiPhy193, mac, wifiApNode193);
	ns3::NetDeviceContainer apDevices194;
	apDevices194 = Wifi.Install(wifiPhy194, mac, wifiApNode194);
	ns3::NetDeviceContainer apDevices195;
	apDevices195 = Wifi.Install(wifiPhy195, mac, wifiApNode195);
	ns3::NetDeviceContainer apDevices196;
	apDevices196 = Wifi.Install(wifiPhy196, mac, wifiApNode196);
	ns3::NetDeviceContainer apDevices197;
	apDevices197 = Wifi.Install(wifiPhy197, mac, wifiApNode197);
	ns3::NetDeviceContainer apDevices198;
	apDevices198 = Wifi.Install(wifiPhy198, mac, wifiApNode198);
	ns3::NetDeviceContainer apDevices199;
	apDevices199 = Wifi.Install(wifiPhy199, mac, wifiApNode199);
	ns3::NetDeviceContainer apDevices200;
	apDevices200 = Wifi.Install(wifiPhy200, mac, wifiApNode200);
	ns3::NetDeviceContainer apDevices201;
	apDevices201 = Wifi.Install(wifiPhy201, mac, wifiApNode201);
	ns3::NetDeviceContainer apDevices202;
	apDevices202 = Wifi.Install(wifiPhy202, mac, wifiApNode202);
	ns3::NetDeviceContainer apDevices203;
	apDevices203 = Wifi.Install(wifiPhy203, mac, wifiApNode203);
	ns3::NetDeviceContainer apDevices204;
	apDevices204 = Wifi.Install(wifiPhy204, mac, wifiApNode204);
	ns3::NetDeviceContainer apDevices205;
	apDevices205 = Wifi.Install(wifiPhy205, mac, wifiApNode205);
	ns3::NetDeviceContainer apDevices206;
	apDevices206 = Wifi.Install(wifiPhy206, mac, wifiApNode206);
	ns3::NetDeviceContainer apDevices207;
	apDevices207 = Wifi.Install(wifiPhy207, mac, wifiApNode207);
	ns3::NetDeviceContainer apDevices208;
	apDevices208 = Wifi.Install(wifiPhy208, mac, wifiApNode208);
	ns3::NetDeviceContainer apDevices209;
	apDevices209 = Wifi.Install(wifiPhy209, mac, wifiApNode209);
	ns3::NetDeviceContainer apDevices210;
	apDevices210 = Wifi.Install(wifiPhy210, mac, wifiApNode210);
	ns3::NetDeviceContainer apDevices211;
	apDevices211 = Wifi.Install(wifiPhy211, mac, wifiApNode211);
	ns3::NetDeviceContainer apDevices212;
	apDevices212 = Wifi.Install(wifiPhy212, mac, wifiApNode212);
	ns3::NetDeviceContainer apDevices213;
	apDevices213 = Wifi.Install(wifiPhy213, mac, wifiApNode213);
	ns3::NetDeviceContainer apDevices214;
	apDevices214 = Wifi.Install(wifiPhy214, mac, wifiApNode214);
	ns3::NetDeviceContainer apDevices215;
	apDevices215 = Wifi.Install(wifiPhy215, mac, wifiApNode215);
	ns3::NetDeviceContainer apDevices216;
	apDevices216 = Wifi.Install(wifiPhy216, mac, wifiApNode216);
	ns3::NetDeviceContainer apDevices217;
	apDevices217 = Wifi.Install(wifiPhy217, mac, wifiApNode217);
	ns3::NetDeviceContainer apDevices218;
	apDevices218 = Wifi.Install(wifiPhy218, mac, wifiApNode218);
	ns3::NetDeviceContainer apDevices219;
	apDevices219 = Wifi.Install(wifiPhy219, mac, wifiApNode219);
	ns3::NetDeviceContainer apDevices220;
	apDevices220 = Wifi.Install(wifiPhy220, mac, wifiApNode220);
	ns3::NetDeviceContainer apDevices221;
	apDevices221 = Wifi.Install(wifiPhy221, mac, wifiApNode221);
	ns3::NetDeviceContainer apDevices222;
	apDevices222 = Wifi.Install(wifiPhy222, mac, wifiApNode222);
	ns3::NetDeviceContainer apDevices223;
	apDevices223 = Wifi.Install(wifiPhy223, mac, wifiApNode223);
	ns3::NetDeviceContainer apDevices224;
	apDevices224 = Wifi.Install(wifiPhy224, mac, wifiApNode224);
	ns3::NetDeviceContainer apDevices225;
	apDevices225 = Wifi.Install(wifiPhy225, mac, wifiApNode225);
	ns3::NetDeviceContainer apDevices226;
	apDevices226 = Wifi.Install(wifiPhy226, mac, wifiApNode226);
	ns3::NetDeviceContainer apDevices227;
	apDevices227 = Wifi.Install(wifiPhy227, mac, wifiApNode227);
	ns3::NetDeviceContainer apDevices228;
	apDevices228 = Wifi.Install(wifiPhy228, mac, wifiApNode228);
	ns3::NetDeviceContainer apDevices229;
	apDevices229 = Wifi.Install(wifiPhy229, mac, wifiApNode229);
	ns3::NetDeviceContainer apDevices230;
	apDevices230 = Wifi.Install(wifiPhy230, mac, wifiApNode230);
	ns3::NetDeviceContainer apDevices231;
	apDevices231 = Wifi.Install(wifiPhy231, mac, wifiApNode231);
	ns3::NetDeviceContainer apDevices232;
	apDevices232 = Wifi.Install(wifiPhy232, mac, wifiApNode232);
	ns3::NetDeviceContainer apDevices233;
	apDevices233 = Wifi.Install(wifiPhy233, mac, wifiApNode233);
	ns3::NetDeviceContainer apDevices234;
	apDevices234 = Wifi.Install(wifiPhy234, mac, wifiApNode234);
	ns3::NetDeviceContainer apDevices235;
	apDevices235 = Wifi.Install(wifiPhy235, mac, wifiApNode235);
	ns3::NetDeviceContainer apDevices236;
	apDevices236 = Wifi.Install(wifiPhy236, mac, wifiApNode236);
	ns3::NetDeviceContainer apDevices237;
	apDevices237 = Wifi.Install(wifiPhy237, mac, wifiApNode237);
	ns3::NetDeviceContainer apDevices238;
	apDevices238 = Wifi.Install(wifiPhy238, mac, wifiApNode238);
	ns3::NetDeviceContainer apDevices239;
	apDevices239 = Wifi.Install(wifiPhy239, mac, wifiApNode239);
	ns3::NetDeviceContainer apDevices240;
	apDevices240 = Wifi.Install(wifiPhy240, mac, wifiApNode240);
	ns3::NetDeviceContainer apDevices241;
	apDevices241 = Wifi.Install(wifiPhy241, mac, wifiApNode241);
	ns3::NetDeviceContainer apDevices242;
	apDevices242 = Wifi.Install(wifiPhy242, mac, wifiApNode242);
	ns3::NetDeviceContainer apDevices243;
	apDevices243 = Wifi.Install(wifiPhy243, mac, wifiApNode243);
	ns3::NetDeviceContainer apDevices244;
	apDevices244 = Wifi.Install(wifiPhy244, mac, wifiApNode244);
	ns3::NetDeviceContainer apDevices245;
	apDevices245 = Wifi.Install(wifiPhy245, mac, wifiApNode245);
	ns3::NetDeviceContainer apDevices246;
	apDevices246 = Wifi.Install(wifiPhy246, mac, wifiApNode246);
	ns3::NetDeviceContainer apDevices247;
	apDevices247 = Wifi.Install(wifiPhy247, mac, wifiApNode247);
	ns3::NetDeviceContainer apDevices248;
	apDevices248 = Wifi.Install(wifiPhy248, mac, wifiApNode248);
	ns3::NetDeviceContainer apDevices249;
	apDevices249 = Wifi.Install(wifiPhy249, mac, wifiApNode249);
	ns3::NetDeviceContainer apDevices250;
	apDevices250 = Wifi.Install(wifiPhy250, mac, wifiApNode250);
	ns3::NetDeviceContainer apDevices251;
	apDevices251 = Wifi.Install(wifiPhy251, mac, wifiApNode251);
	ns3::NetDeviceContainer apDevices252;
	apDevices252 = Wifi.Install(wifiPhy252, mac, wifiApNode252);
	ns3::NetDeviceContainer apDevices253;
	apDevices253 = Wifi.Install(wifiPhy253, mac, wifiApNode253);
	ns3::NetDeviceContainer apDevices254;
	apDevices254 = Wifi.Install(wifiPhy254, mac, wifiApNode254);
	ns3::NetDeviceContainer apDevices255;
	apDevices255 = Wifi.Install(wifiPhy255, mac, wifiApNode255);
	ns3::NetDeviceContainer apDevices256;
	apDevices256 = Wifi.Install(wifiPhy256, mac, wifiApNode256);
	ns3::NetDeviceContainer apDevices257;
	apDevices257 = Wifi.Install(wifiPhy257, mac, wifiApNode257);
	ns3::NetDeviceContainer apDevices258;
	apDevices258 = Wifi.Install(wifiPhy258, mac, wifiApNode258);
	ns3::NetDeviceContainer apDevices259;
	apDevices259 = Wifi.Install(wifiPhy259, mac, wifiApNode259);
	ns3::NetDeviceContainer apDevices260;
	apDevices260 = Wifi.Install(wifiPhy260, mac, wifiApNode260);
	ns3::NetDeviceContainer apDevices261;
	apDevices261 = Wifi.Install(wifiPhy261, mac, wifiApNode261);
	ns3::NetDeviceContainer apDevices262;
	apDevices262 = Wifi.Install(wifiPhy262, mac, wifiApNode262);
	ns3::NetDeviceContainer apDevices263;
	apDevices263 = Wifi.Install(wifiPhy263, mac, wifiApNode263);
	ns3::NetDeviceContainer apDevices264;
	apDevices264 = Wifi.Install(wifiPhy264, mac, wifiApNode264);
	ns3::NetDeviceContainer apDevices265;
	apDevices265 = Wifi.Install(wifiPhy265, mac, wifiApNode265);
	ns3::NetDeviceContainer apDevices266;
	apDevices266 = Wifi.Install(wifiPhy266, mac, wifiApNode266);
	ns3::NetDeviceContainer apDevices267;
	apDevices267 = Wifi.Install(wifiPhy267, mac, wifiApNode267);
	ns3::NetDeviceContainer apDevices268;
	apDevices268 = Wifi.Install(wifiPhy268, mac, wifiApNode268);
	ns3::NetDeviceContainer apDevices269;
	apDevices269 = Wifi.Install(wifiPhy269, mac, wifiApNode269);
	ns3::NetDeviceContainer apDevices270;
	apDevices270 = Wifi.Install(wifiPhy270, mac, wifiApNode270);
	ns3::NetDeviceContainer apDevices271;
	apDevices271 = Wifi.Install(wifiPhy271, mac, wifiApNode271);
	ns3::NetDeviceContainer apDevices272;
	apDevices272 = Wifi.Install(wifiPhy272, mac, wifiApNode272);
	ns3::NetDeviceContainer apDevices273;
	apDevices273 = Wifi.Install(wifiPhy273, mac, wifiApNode273);
	ns3::NetDeviceContainer apDevices274;
	apDevices274 = Wifi.Install(wifiPhy274, mac, wifiApNode274);
	ns3::NetDeviceContainer apDevices275;
	apDevices275 = Wifi.Install(wifiPhy275, mac, wifiApNode275);
	ns3::NetDeviceContainer apDevices276;
	apDevices276 = Wifi.Install(wifiPhy276, mac, wifiApNode276);
	ns3::NetDeviceContainer apDevices277;
	apDevices277 = Wifi.Install(wifiPhy277, mac, wifiApNode277);
	ns3::NetDeviceContainer apDevices278;
	apDevices278 = Wifi.Install(wifiPhy278, mac, wifiApNode278);
	ns3::NetDeviceContainer apDevices279;
	apDevices279 = Wifi.Install(wifiPhy279, mac, wifiApNode279);
	ns3::NetDeviceContainer apDevices280;
	apDevices280 = Wifi.Install(wifiPhy280, mac, wifiApNode280);
	ns3::NetDeviceContainer apDevices281;
	apDevices281 = Wifi.Install(wifiPhy281, mac, wifiApNode281);
	ns3::NetDeviceContainer apDevices282;
	apDevices282 = Wifi.Install(wifiPhy282, mac, wifiApNode282);
	ns3::NetDeviceContainer apDevices283;
	apDevices283 = Wifi.Install(wifiPhy283, mac, wifiApNode283);
	ns3::NetDeviceContainer apDevices284;
	apDevices284 = Wifi.Install(wifiPhy284, mac, wifiApNode284);
	ns3::NetDeviceContainer apDevices285;
	apDevices285 = Wifi.Install(wifiPhy285, mac, wifiApNode285);
	ns3::NetDeviceContainer apDevices286;
	apDevices286 = Wifi.Install(wifiPhy286, mac, wifiApNode286);
	ns3::NetDeviceContainer apDevices287;
	apDevices287 = Wifi.Install(wifiPhy287, mac, wifiApNode287);
	ns3::NetDeviceContainer apDevices288;
	apDevices288 = Wifi.Install(wifiPhy288, mac, wifiApNode288);
	ns3::NetDeviceContainer apDevices289;
	apDevices289 = Wifi.Install(wifiPhy289, mac, wifiApNode289);
	ns3::NetDeviceContainer apDevices290;
	apDevices290 = Wifi.Install(wifiPhy290, mac, wifiApNode290);
	ns3::NetDeviceContainer apDevices291;
	apDevices291 = Wifi.Install(wifiPhy291, mac, wifiApNode291);
	ns3::NetDeviceContainer apDevices292;
	apDevices292 = Wifi.Install(wifiPhy292, mac, wifiApNode292);
	ns3::NetDeviceContainer apDevices293;
	apDevices293 = Wifi.Install(wifiPhy293, mac, wifiApNode293);
	ns3::NetDeviceContainer apDevices294;
	apDevices294 = Wifi.Install(wifiPhy294, mac, wifiApNode294);
	ns3::NetDeviceContainer apDevices295;
	apDevices295 = Wifi.Install(wifiPhy295, mac, wifiApNode295);
	ns3::NetDeviceContainer apDevices296;
	apDevices296 = Wifi.Install(wifiPhy296, mac, wifiApNode296);
	ns3::NetDeviceContainer apDevices297;
	apDevices297 = Wifi.Install(wifiPhy297, mac, wifiApNode297);
//    apDevices298 = Wifi.Install (wifiPhy298, mac, wifiApNode298)
//    apDevices299 = Wifi.Install (wifiPhy299, mac, wifiApNode299)
	ns3::NetDeviceContainer apDevices300;
	apDevices300 = Wifi.Install(wifiPhy300, mac, wifiApNode300);
	ns3::NetDeviceContainer apDevices301;
	apDevices301 = Wifi.Install(wifiPhy301, mac, wifiApNode301);
	ns3::NetDeviceContainer apDevices302;
	apDevices302 = Wifi.Install(wifiPhy302, mac, wifiApNode302);
	ns3::NetDeviceContainer apDevices303;
	apDevices303 = Wifi.Install(wifiPhy303, mac, wifiApNode303);
	ns3::NetDeviceContainer apDevices304;
	apDevices304 = Wifi.Install(wifiPhy304, mac, wifiApNode304);
	ns3::NetDeviceContainer apDevices305;
	apDevices305 = Wifi.Install(wifiPhy305, mac, wifiApNode305);
//    apDevices306 = Wifi.Install (wifiPhy306, mac, wifiApNode306)
	ns3::NetDeviceContainer apDevices307;
	apDevices307 = Wifi.Install(wifiPhy307, mac, wifiApNode307);
	ns3::NetDeviceContainer apDevices308;
	apDevices308 = Wifi.Install(wifiPhy308, mac, wifiApNode308);
	ns3::NetDeviceContainer apDevices309;
	apDevices309 = Wifi.Install(wifiPhy309, mac, wifiApNode309);
	ns3::NetDeviceContainer apDevices310;
	apDevices310 = Wifi.Install(wifiPhy310, mac, wifiApNode310);
	ns3::NetDeviceContainer apDevices311;
	apDevices311 = Wifi.Install(wifiPhy311, mac, wifiApNode311);
	ns3::NetDeviceContainer apDevices312;
	apDevices312 = Wifi.Install(wifiPhy312, mac, wifiApNode312);
	ns3::NetDeviceContainer apDevices313;
	apDevices313 = Wifi.Install(wifiPhy313, mac, wifiApNode313);
	ns3::NetDeviceContainer apDevices314;
	apDevices314 = Wifi.Install(wifiPhy314, mac, wifiApNode314);
//    apDevices315 = Wifi.Install (wifiPhy315, mac, wifiApNode315)

	return EXIT_SUCCESS;
} //main
