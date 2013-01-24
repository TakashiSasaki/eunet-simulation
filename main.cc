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

ns3::NetDeviceContainer internetrouterdevices ;
ns3::NetDeviceContainer switchDevicesrouter ;
ns3::NetDeviceContainer switchDevices6506E ;
ns3::NetDeviceContainer switchDevices5 ;
ns3::NetDeviceContainer switchDevices6 ;
ns3::NetDeviceContainer switchDevices7 ;
ns3::NetDeviceContainer switchDevices8 ;
ns3::NetDeviceContainer switchDevices9 ;
ns3::NetDeviceContainer switchDevices10 ;
ns3::NetDeviceContainer switchDevices11 ;
ns3::NetDeviceContainer switchDevices12 ;
ns3::NetDeviceContainer switchDevices13 ;
ns3::NetDeviceContainer switchDevices14 ;
ns3::NetDeviceContainer switchDevices15 ;
ns3::NetDeviceContainer switchDevices16 ;
ns3::NetDeviceContainer switchDevices17 ;
ns3::NetDeviceContainer switchDevices18 ;
ns3::NetDeviceContainer switchDevices19 ;
ns3::NetDeviceContainer switchDevices20 ;
ns3::NetDeviceContainer switchDevices21 ;
ns3::NetDeviceContainer switchDevices22 ;
ns3::NetDeviceContainer switchDevices23 ;
ns3::NetDeviceContainer switchDevices24 ;
ns3::NetDeviceContainer switchDevices25 ;
ns3::NetDeviceContainer switchDevices26 ;
ns3::NetDeviceContainer switchDevices27 ;
ns3::NetDeviceContainer switchDevices28 ;
ns3::NetDeviceContainer switchDevices29 ;
ns3::NetDeviceContainer switchDevices30 ;
ns3::NetDeviceContainer switchDevices31 ;
ns3::NetDeviceContainer switchDevices32 ;
ns3::NetDeviceContainer switchDevices33 ;
ns3::NetDeviceContainer switchDevices34 ;
ns3::NetDeviceContainer switchDevices35 ;
ns3::NetDeviceContainer switchDevices36 ;
ns3::NetDeviceContainer switchDevices37 ;
ns3::NetDeviceContainer switchDevices38 ;
ns3::NetDeviceContainer switchDevices39 ;
ns3::NetDeviceContainer switchDevices40 ;
ns3::NetDeviceContainer switchDevices41 ;
ns3::NetDeviceContainer switchDevices42 ;
ns3::NetDeviceContainer switchDevices43 ;
ns3::NetDeviceContainer switchDevices44 ;
ns3::NetDeviceContainer switchDevices45 ;
ns3::NetDeviceContainer switchDevices46 ;
ns3::NetDeviceContainer switchDevices47 ;
ns3::NetDeviceContainer switchDevices48 ;
ns3::NetDeviceContainer switchDevices49 ;
ns3::NetDeviceContainer switchDevices50 ;
ns3::NetDeviceContainer switchDevices51 ;
ns3::NetDeviceContainer switchDevices52 ;
ns3::NetDeviceContainer switchDevices53 ;
ns3::NetDeviceContainer switchDevices54 ;
ns3::NetDeviceContainer switchDevices55 ;
ns3::NetDeviceContainer switchDevices56 ;
ns3::NetDeviceContainer switchDevices57 ;
ns3::NetDeviceContainer switchDevices58 ;
ns3::NetDeviceContainer switchDevices59 ;
ns3::NetDeviceContainer switchDevices60 ;
ns3::NetDeviceContainer switchDevices61 ;
ns3::NetDeviceContainer switchDevices62 ;
ns3::NetDeviceContainer switchDevices63 ;
ns3::NetDeviceContainer switchDevices64 ;
ns3::NetDeviceContainer switchDevices65 ;
ns3::NetDeviceContainer switchDevices66 ;
ns3::NetDeviceContainer switchDevices67 ;
ns3::NetDeviceContainer switchDevices68 ;
ns3::NetDeviceContainer switchDevices69 ;
ns3::NetDeviceContainer switchDevices70 ;
ns3::NetDeviceContainer switchDevices71 ;
ns3::NetDeviceContainer switchDevices72 ;
ns3::NetDeviceContainer switchDevices73 ;
ns3::NetDeviceContainer switchDevices74 ;
ns3::NetDeviceContainer switchDevices75 ;
ns3::NetDeviceContainer switchDevices76 ;
ns3::NetDeviceContainer switchDevices77 ;
ns3::NetDeviceContainer switchDevices78 ;
ns3::NetDeviceContainer switchDevices79 ;
ns3::NetDeviceContainer switchDevices80 ;
ns3::NetDeviceContainer switchDevices81 ;
ns3::NetDeviceContainer switchDevices82 ;
ns3::NetDeviceContainer switchDevices83 ;
ns3::NetDeviceContainer switchDevices84 ;
ns3::NetDeviceContainer switchDevices85 ;
ns3::NetDeviceContainer switchDevices86 ;
ns3::NetDeviceContainer switchDevices87 ;
ns3::NetDeviceContainer switchDevices88 ;
ns3::NetDeviceContainer switchDevices89 ;
ns3::NetDeviceContainer switchDevices90 ;
ns3::NetDeviceContainer switchDevices91 ;
ns3::NetDeviceContainer switchDevices92 ;
ns3::NetDeviceContainer switchDevices93 ;
ns3::NetDeviceContainer switchDevices94 ;
ns3::NetDeviceContainer switchDevices95 ;
ns3::NetDeviceContainer switchDevices96 ;
ns3::NetDeviceContainer switchDevices97 ;
ns3::NetDeviceContainer switchDevices98 ;
ns3::NetDeviceContainer switchDevices99 ;
ns3::NetDeviceContainer switchDevices100 ;
ns3::NetDeviceContainer switchDevices101 ;
ns3::NetDeviceContainer switchDevices102 ;
ns3::NetDeviceContainer switchDevices103 ;
ns3::NetDeviceContainer switchDevices104 ;
ns3::NetDeviceContainer switchDevices105 ;
ns3::NetDeviceContainer switchDevices106 ;
ns3::NetDeviceContainer switchDevices107 ;
ns3::NetDeviceContainer switchDevices108 ;
ns3::NetDeviceContainer switchDevices109 ;
ns3::NetDeviceContainer switchDevices110 ;
ns3::NetDeviceContainer switchDevices111 ;
ns3::NetDeviceContainer switchDevices112 ;
ns3::NetDeviceContainer switchDevices113 ;
ns3::NetDeviceContainer switchDevices114 ;
ns3::NetDeviceContainer switchDevices115 ;
ns3::NetDeviceContainer switchDevices116 ;
ns3::NetDeviceContainer switchDevices117 ;
ns3::NetDeviceContainer switchDevices118 ;
ns3::NetDeviceContainer switchDevices119 ;
ns3::NetDeviceContainer switchDevices120 ;
ns3::NetDeviceContainer switchDevices121 ;
ns3::NetDeviceContainer switchDevices122 ;
ns3::NetDeviceContainer switchDevices123 ;
ns3::NetDeviceContainer switchDevices124 ;
ns3::NetDeviceContainer switchDevices125 ;
ns3::NetDeviceContainer switchDevices126 ;
ns3::NetDeviceContainer switchDevices127 ;
ns3::NetDeviceContainer switchDevices128 ;
ns3::NetDeviceContainer switchDevices129 ;
ns3::NetDeviceContainer switchDevices130 ;
ns3::NetDeviceContainer switchDevices131 ;
ns3::NetDeviceContainer switchDevices132 ;
ns3::NetDeviceContainer switchDevices133 ;
ns3::NetDeviceContainer switchDevices134 ;
ns3::NetDeviceContainer switchDevices135 ;
ns3::NetDeviceContainer switchDevices136 ;
ns3::NetDeviceContainer switchDevices137 ;
ns3::NetDeviceContainer switchDevices138 ;
ns3::NetDeviceContainer switchDevices139 ;
ns3::NetDeviceContainer switchDevices140 ;
ns3::NetDeviceContainer switchDevices141 ;
ns3::NetDeviceContainer switchDevices142 ;
ns3::NetDeviceContainer switchDevices143 ;
ns3::NetDeviceContainer switchDevices144 ;
ns3::NetDeviceContainer switchDevices145 ;
ns3::NetDeviceContainer switchDevices146 ;
ns3::NetDeviceContainer switchDevices147 ;
ns3::NetDeviceContainer switchDevices148 ;
ns3::NetDeviceContainer switchDevices149 ;
ns3::NetDeviceContainer switchDevices150 ;
ns3::NetDeviceContainer switchDevices151 ;
ns3::NetDeviceContainer switchDevices152 ;
ns3::NetDeviceContainer switchDevices153 ;
ns3::NetDeviceContainer switchDevices154 ;
ns3::NetDeviceContainer switchDevices155 ;
ns3::NetDeviceContainer switchDevices156 ;
ns3::NetDeviceContainer switchDevices157 ;
ns3::NetDeviceContainer switchDevices158 ;
ns3::NetDeviceContainer switchDevices159 ;
ns3::NetDeviceContainer switchDevices160 ;
ns3::NetDeviceContainer switchDevices161 ;
ns3::NetDeviceContainer switchDevices162 ;
ns3::NetDeviceContainer switchDevices163 ;
ns3::NetDeviceContainer switchDevices164 ;
ns3::NetDeviceContainer switchDevices165 ;
ns3::NetDeviceContainer switchDevices166 ;
ns3::NetDeviceContainer switchDevices167 ;
ns3::NetDeviceContainer switchDevices168 ;
ns3::NetDeviceContainer switchDevices169 ;
ns3::NetDeviceContainer switchDevices170 ;
ns3::NetDeviceContainer switchDevices171 ;
ns3::NetDeviceContainer switchDevices172 ;
ns3::NetDeviceContainer switchDevices173 ;
ns3::NetDeviceContainer switchDevices174 ;
ns3::NetDeviceContainer switchDevices175 ;
ns3::NetDeviceContainer switchDevices176 ;
ns3::NetDeviceContainer switchDevices177 ;
ns3::NetDeviceContainer switchDevices178 ;
ns3::NetDeviceContainer switchDevices179 ;
ns3::NetDeviceContainer switchDevices180 ;
ns3::NetDeviceContainer switchDevices181 ;
ns3::NetDeviceContainer switchDevices182 ;
ns3::NetDeviceContainer switchDevices183 ;
ns3::NetDeviceContainer switchDevices184 ;
ns3::NetDeviceContainer switchDevices185 ;
ns3::NetDeviceContainer switchDevices186 ;
ns3::NetDeviceContainer switchDevices187 ;
ns3::NetDeviceContainer switchDevices188 ;
ns3::NetDeviceContainer switchDevices189 ;
ns3::NetDeviceContainer switchDevices190 ;
ns3::NetDeviceContainer switchDevices191 ;
ns3::NetDeviceContainer switchDevices192 ;
ns3::NetDeviceContainer switchDevices193 ;
ns3::NetDeviceContainer switchDevices194 ;
ns3::NetDeviceContainer switchDevices195 ;
ns3::NetDeviceContainer switchDevices196 ;
ns3::NetDeviceContainer switchDevices197 ;
ns3::NetDeviceContainer switchDevices198 ;
ns3::NetDeviceContainer switchDevices199 ;
ns3::NetDeviceContainer switchDevices200 ;
ns3::NetDeviceContainer switchDevices201 ;
ns3::NetDeviceContainer switchDevices202 ;
ns3::NetDeviceContainer switchDevices203 ;
ns3::NetDeviceContainer switchDevices204 ;
ns3::NetDeviceContainer switchDevices205 ;
ns3::NetDeviceContainer switchDevices206 ;
ns3::NetDeviceContainer switchDevices207 ;
ns3::NetDeviceContainer switchDevices208 ;
ns3::NetDeviceContainer switchDevices209 ;
ns3::NetDeviceContainer switchDevices210 ;
ns3::NetDeviceContainer switchDevices211 ;
ns3::NetDeviceContainer switchDevices212 ;
ns3::NetDeviceContainer switchDevices213 ;
ns3::NetDeviceContainer switchDevicessigenobu ;
ns3::NetDeviceContainer switchDevices214 ;
ns3::NetDeviceContainer switchDevices215 ;
ns3::NetDeviceContainer switchDevices216 ;
ns3::NetDeviceContainer switchDevices217 ;
ns3::NetDeviceContainer switchDevices218 ;
ns3::NetDeviceContainer switchDevices219 ;
ns3::NetDeviceContainer switchDevices220 ;
ns3::NetDeviceContainer switchDevices221 ;
ns3::NetDeviceContainer switchDevices222 ;
ns3::NetDeviceContainer switchDevices223 ;
ns3::NetDeviceContainer switchDevices224 ;
ns3::NetDeviceContainer switchDevices225 ;
ns3::NetDeviceContainer switchDevices226 ;
ns3::NetDeviceContainer switchDevices227 ;
ns3::NetDeviceContainer switchDevices228 ;
ns3::NetDeviceContainer switchDevices229 ;
ns3::NetDeviceContainer switchDevices230 ;
ns3::NetDeviceContainer switchDevices231 ;
ns3::NetDeviceContainer switchDevices232 ;
ns3::NetDeviceContainer switchDevices233 ;
ns3::NetDeviceContainer switchDevices234 ;
ns3::NetDeviceContainer switchDevices235 ;
ns3::NetDeviceContainer switchDevices236 ;
ns3::NetDeviceContainer switchDevices237 ;
ns3::NetDeviceContainer switchDevices238 ;
ns3::NetDeviceContainer switchDevices239 ;
ns3::NetDeviceContainer switchDevices240 ;
ns3::NetDeviceContainer switchDevices241 ;
ns3::NetDeviceContainer switchDevices242 ;
ns3::NetDeviceContainer switchDevices243 ;
ns3::NetDeviceContainer switchDevices244 ;
ns3::NetDeviceContainer switchDevices245 ;
ns3::NetDeviceContainer switchDevices246 ;
ns3::NetDeviceContainer switchDevices247 ;
ns3::NetDeviceContainer switchDevices248 ;
ns3::NetDeviceContainer switchDevices284 ;
ns3::NetDeviceContainer switchDevices249 ;
ns3::NetDeviceContainer switchDevices250 ;
ns3::NetDeviceContainer switchDevices251 ;
ns3::NetDeviceContainer switchDevices252 ;
ns3::NetDeviceContainer switchDevices253 ;
ns3::NetDeviceContainer switchDevices254 ;
ns3::NetDeviceContainer switchDevices255 ;
ns3::NetDeviceContainer switchDevices256 ;
ns3::NetDeviceContainer switchDevices257 ;
ns3::NetDeviceContainer switchDevices258 ;
ns3::NetDeviceContainer switchDevices259 ;
ns3::NetDeviceContainer switchDevices260 ;
ns3::NetDeviceContainer switchDevices261 ;
ns3::NetDeviceContainer switchDevices262 ;
ns3::NetDeviceContainer switchDevices263 ;
ns3::NetDeviceContainer switchDevices264 ;
ns3::NetDeviceContainer switchDevices265 ;
ns3::NetDeviceContainer switchDevices266 ;
ns3::NetDeviceContainer switchDevices267 ;
ns3::NetDeviceContainer switchDevices268 ;
ns3::NetDeviceContainer switchDevices269 ;
ns3::NetDeviceContainer switchDevices270 ;
ns3::NetDeviceContainer switchDevices272 ;
ns3::NetDeviceContainer switchDevices273 ;
ns3::NetDeviceContainer switchDevices274 ;
ns3::NetDeviceContainer switchDevices275 ;
ns3::NetDeviceContainer switchDevices276 ;
ns3::NetDeviceContainer switchDevices277 ;
ns3::NetDeviceContainer switchDevices278 ;
ns3::NetDeviceContainer switchDevices279 ;
ns3::NetDeviceContainer switchDevices280 ;
ns3::NetDeviceContainer switchDevices281 ;
ns3::NetDeviceContainer switchDevices282 ;
ns3::NetDeviceContainer switchDevices283 ;
ns3::NetDeviceContainer switchDevicestarumi ;
ns3::NetDeviceContainer switchDevices285 ;
ns3::NetDeviceContainer switchDevices286 ;
ns3::NetDeviceContainer switchDevices287 ;
ns3::NetDeviceContainer switchDevices288 ;
ns3::NetDeviceContainer switchDevices289 ;
ns3::NetDeviceContainer switchDevices290 ;
ns3::NetDeviceContainer switchDevices291 ;
ns3::NetDeviceContainer switchDevices292 ;
ns3::NetDeviceContainer switchDevices293 ;
ns3::NetDeviceContainer switchDevices294 ;
ns3::NetDeviceContainer switchDevices295 ;
ns3::NetDeviceContainer switchDevices296 ;
ns3::NetDeviceContainer switchDevices297 ;
ns3::NetDeviceContainer switchDevices298 ;
ns3::NetDeviceContainer switchDevices299 ;
ns3::NetDeviceContainer switchDevices300 ;
ns3::NetDeviceContainer switchDevices301 ;
ns3::NetDeviceContainer switchDevices302 ;
ns3::NetDeviceContainer switchDevices303 ;
ns3::NetDeviceContainer switchDevices304 ;
ns3::NetDeviceContainer switchDevices305 ;
ns3::NetDeviceContainer switchDevices306 ;
ns3::NetDeviceContainer switchDevices307 ;
ns3::NetDeviceContainer switchDevices308 ;
ns3::NetDeviceContainer switchDevices309 ;
ns3::NetDeviceContainer switchDevices310 ;
ns3::NetDeviceContainer switchDevices311 ;
ns3::NetDeviceContainer switchDevices312 ;
ns3::NetDeviceContainer switchDevices313 ;
ns3::NetDeviceContainer switchDevices314 ;
ns3::NetDeviceContainer switchDevices315 ;
ns3::NetDeviceContainer switchDevices316 ;
ns3::NetDeviceContainer switchDevices317 ;
ns3::NetDeviceContainer switchDevices318 ;
ns3::NetDeviceContainer switchDevices319 ;
ns3::NetDeviceContainer switchDevices320 ;
ns3::NetDeviceContainer switchDevices321 ;
ns3::NetDeviceContainer switchDevices322 ;
ns3::NetDeviceContainer switchDevices323 ;
ns3::NetDeviceContainer switchDevices324 ;
ns3::NetDeviceContainer switchDevices325 ;
ns3::NetDeviceContainer switchDevices326 ;
ns3::NetDeviceContainer switchDevices327 ;
ns3::NetDeviceContainer switchDevices328 ;
ns3::NetDeviceContainer switchDevices329 ;
ns3::NetDeviceContainer switchDevices330 ;
ns3::NetDeviceContainer switchDevices331 ;
ns3::NetDeviceContainer switchDevices332 ;
ns3::NetDeviceContainer switchDevices333 ;
ns3::NetDeviceContainer switchDevices334 ;
ns3::NetDeviceContainer switchDevices335 ;
ns3::NetDeviceContainer switchDevices336 ;
ns3::NetDeviceContainer switchDevices337 ;
ns3::NetDeviceContainer switchDevices338 ;
ns3::NetDeviceContainer switchDevices339 ;
ns3::NetDeviceContainer switchDevices340 ;
ns3::NetDeviceContainer switchDevices341 ;
ns3::NetDeviceContainer switchDevices342 ;
ns3::NetDeviceContainer switchDevices343 ;
ns3::NetDeviceContainer switchDevices344 ;
ns3::NetDeviceContainer switchDevices345 ;
ns3::NetDeviceContainer switchDevices346 ;
ns3::NetDeviceContainer switchDevices347 ;
ns3::NetDeviceContainer switchDevices348 ;









ns3::NetDeviceContainer terminaldevices5 ;
ns3::NetDeviceContainer terminaldevices6 ;
ns3::NetDeviceContainer terminaldevices7 ;
ns3::NetDeviceContainer terminaldevices8 ;
ns3::NetDeviceContainer terminaldevices9 ;
ns3::NetDeviceContainer terminaldevices10 ;
ns3::NetDeviceContainer terminaldevices11 ;
ns3::NetDeviceContainer terminaldevices12 ;
ns3::NetDeviceContainer terminaldevices13 ;
ns3::NetDeviceContainer terminaldevices14 ;
ns3::NetDeviceContainer terminaldevices15 ;
ns3::NetDeviceContainer terminaldevices16 ;
ns3::NetDeviceContainer terminaldevices17 ;
ns3::NetDeviceContainer terminaldevices18 ;
ns3::NetDeviceContainer terminaldevices19 ;
ns3::NetDeviceContainer terminaldevices20 ;
ns3::NetDeviceContainer terminaldevices21 ;
ns3::NetDeviceContainer terminaldevices22 ;
ns3::NetDeviceContainer terminaldevices23 ;
ns3::NetDeviceContainer terminaldevices24 ;
ns3::NetDeviceContainer terminaldevices25 ;
ns3::NetDeviceContainer terminaldevices26 ;
ns3::NetDeviceContainer terminaldevices27 ;
ns3::NetDeviceContainer terminaldevices28 ;
ns3::NetDeviceContainer terminaldevices29 ;
ns3::NetDeviceContainer terminaldevices30 ;
ns3::NetDeviceContainer terminaldevices31 ;
ns3::NetDeviceContainer terminaldevices32 ;
ns3::NetDeviceContainer terminaldevices33 ;
ns3::NetDeviceContainer terminaldevices34 ;
ns3::NetDeviceContainer terminaldevices35 ;
ns3::NetDeviceContainer terminaldevices36 ;
ns3::NetDeviceContainer terminaldevices37 ;
ns3::NetDeviceContainer terminaldevices38 ;
ns3::NetDeviceContainer terminaldevices39 ;
ns3::NetDeviceContainer terminaldevices40 ;
ns3::NetDeviceContainer terminaldevices41 ;
ns3::NetDeviceContainer terminaldevices42 ;
ns3::NetDeviceContainer terminaldevices43 ;
ns3::NetDeviceContainer terminaldevices44 ;
ns3::NetDeviceContainer terminaldevices45 ;
ns3::NetDeviceContainer terminaldevices46 ;
ns3::NetDeviceContainer terminaldevices47 ;
ns3::NetDeviceContainer terminaldevices48 ;
ns3::NetDeviceContainer terminaldevices49 ;
ns3::NetDeviceContainer terminaldevices50 ;
ns3::NetDeviceContainer terminaldevices51 ;
ns3::NetDeviceContainer terminaldevices52 ;
ns3::NetDeviceContainer terminaldevices53 ;
ns3::NetDeviceContainer terminaldevices54 ;
ns3::NetDeviceContainer terminaldevices55 ;
ns3::NetDeviceContainer terminaldevices56 ;
ns3::NetDeviceContainer terminaldevices57 ;
ns3::NetDeviceContainer terminaldevices58 ;
ns3::NetDeviceContainer terminaldevices59 ;
ns3::NetDeviceContainer terminaldevices60 ;
ns3::NetDeviceContainer terminaldevices61 ;
ns3::NetDeviceContainer terminaldevices62 ;
ns3::NetDeviceContainer terminaldevices63 ;
ns3::NetDeviceContainer terminaldevices64 ;
ns3::NetDeviceContainer terminaldevices65 ;
ns3::NetDeviceContainer terminaldevices66 ;
ns3::NetDeviceContainer terminaldevices67 ;
ns3::NetDeviceContainer terminaldevices68 ;
ns3::NetDeviceContainer terminaldevices69 ;
ns3::NetDeviceContainer terminaldevices70 ;
ns3::NetDeviceContainer terminaldevices71 ;
ns3::NetDeviceContainer terminaldevices72 ;
ns3::NetDeviceContainer terminaldevices73 ;
ns3::NetDeviceContainer terminaldevices74 ;
ns3::NetDeviceContainer terminaldevices75 ;
ns3::NetDeviceContainer terminaldevices76 ;
ns3::NetDeviceContainer terminaldevices77 ;
ns3::NetDeviceContainer terminaldevices78 ;
ns3::NetDeviceContainer terminaldevices79 ;
ns3::NetDeviceContainer terminaldevices81 ;
ns3::NetDeviceContainer terminaldevices82 ;
ns3::NetDeviceContainer terminaldevices83 ;
ns3::NetDeviceContainer terminaldevices84 ;
ns3::NetDeviceContainer terminaldevices85 ;
ns3::NetDeviceContainer terminaldevices86 ;
ns3::NetDeviceContainer terminaldevices87 ;
ns3::NetDeviceContainer terminaldevices88 ;
ns3::NetDeviceContainer terminaldevices89 ;
ns3::NetDeviceContainer terminaldevices90 ;
ns3::NetDeviceContainer terminaldevices91 ;
ns3::NetDeviceContainer terminaldevices92 ;
ns3::NetDeviceContainer terminaldevices93 ;
ns3::NetDeviceContainer terminaldevices94 ;
ns3::NetDeviceContainer terminaldevices95 ;
ns3::NetDeviceContainer terminaldevices96 ;
ns3::NetDeviceContainer terminaldevices97 ;
ns3::NetDeviceContainer terminaldevices98 ;
ns3::NetDeviceContainer terminaldevices99 ;
ns3::NetDeviceContainer terminaldevices100 ;
ns3::NetDeviceContainer terminaldevices101 ;
ns3::NetDeviceContainer terminaldevices102 ;
ns3::NetDeviceContainer terminaldevices103 ;
ns3::NetDeviceContainer terminaldevices104 ;
ns3::NetDeviceContainer terminaldevices105 ;
ns3::NetDeviceContainer terminaldevices106 ;
ns3::NetDeviceContainer terminaldevices107 ;
ns3::NetDeviceContainer terminaldevices108 ;
ns3::NetDeviceContainer terminaldevices109 ;
ns3::NetDeviceContainer terminaldevices110 ;
ns3::NetDeviceContainer terminaldevices111 ;
ns3::NetDeviceContainer terminaldevices112 ;
ns3::NetDeviceContainer terminaldevices114 ;
ns3::NetDeviceContainer terminaldevices115 ;
ns3::NetDeviceContainer terminaldevices116 ;
ns3::NetDeviceContainer terminaldevices117 ;
ns3::NetDeviceContainer terminaldevices118 ;
ns3::NetDeviceContainer terminaldevices119 ;
ns3::NetDeviceContainer terminaldevices120 ;
ns3::NetDeviceContainer terminaldevices121 ;
ns3::NetDeviceContainer terminaldevices122 ;
ns3::NetDeviceContainer terminaldevices123 ;
ns3::NetDeviceContainer terminaldevices124 ;
ns3::NetDeviceContainer terminaldevices125 ;
ns3::NetDeviceContainer terminaldevices126 ;
ns3::NetDeviceContainer terminaldevices127 ;
ns3::NetDeviceContainer terminaldevices128 ;
ns3::NetDeviceContainer terminaldevices129 ;
ns3::NetDeviceContainer terminaldevices130 ;
ns3::NetDeviceContainer terminaldevices131 ;
ns3::NetDeviceContainer terminaldevices132 ;
ns3::NetDeviceContainer terminaldevices133 ;
ns3::NetDeviceContainer terminaldevices134 ;
ns3::NetDeviceContainer terminaldevices135 ;
ns3::NetDeviceContainer terminaldevices136 ;
ns3::NetDeviceContainer terminaldevices137 ;
ns3::NetDeviceContainer terminaldevices138 ;
ns3::NetDeviceContainer terminaldevices139 ;
ns3::NetDeviceContainer terminaldevices140 ;
ns3::NetDeviceContainer terminaldevices141 ;
ns3::NetDeviceContainer terminaldevices142 ;
ns3::NetDeviceContainer terminaldevices143 ;
ns3::NetDeviceContainer terminaldevices144 ;
ns3::NetDeviceContainer terminaldevices145 ;
ns3::NetDeviceContainer terminaldevices146 ;
ns3::NetDeviceContainer terminaldevices147 ;
ns3::NetDeviceContainer terminaldevices148 ;
ns3::NetDeviceContainer terminaldevices149 ;
ns3::NetDeviceContainer terminaldevices150 ;
ns3::NetDeviceContainer terminaldevices151 ;
ns3::NetDeviceContainer terminaldevices152 ;
ns3::NetDeviceContainer terminaldevices153 ;
ns3::NetDeviceContainer terminaldevices154 ;
ns3::NetDeviceContainer terminaldevices155 ;
ns3::NetDeviceContainer terminaldevices156 ;
ns3::NetDeviceContainer terminaldevices157 ;
ns3::NetDeviceContainer terminaldevices158 ;
ns3::NetDeviceContainer terminaldevices159 ;
ns3::NetDeviceContainer terminaldevices161 ;
ns3::NetDeviceContainer terminaldevices162 ;
ns3::NetDeviceContainer terminaldevices163 ;
ns3::NetDeviceContainer terminaldevices164 ;
ns3::NetDeviceContainer terminaldevices165 ;
ns3::NetDeviceContainer terminaldevices166 ;
ns3::NetDeviceContainer terminaldevices167 ;
ns3::NetDeviceContainer terminaldevices168 ;
ns3::NetDeviceContainer terminaldevices169 ;
ns3::NetDeviceContainer terminaldevices170 ;
ns3::NetDeviceContainer terminaldevices171 ;
ns3::NetDeviceContainer terminaldevices172 ;
ns3::NetDeviceContainer terminaldevices173 ;
ns3::NetDeviceContainer terminaldevices174 ;
ns3::NetDeviceContainer terminaldevices175 ;
ns3::NetDeviceContainer terminaldevices176 ;
ns3::NetDeviceContainer terminaldevices177 ;
ns3::NetDeviceContainer terminaldevices178 ;
ns3::NetDeviceContainer terminaldevices179 ;
ns3::NetDeviceContainer terminaldevices180 ;
ns3::NetDeviceContainer terminaldevices181 ;
ns3::NetDeviceContainer terminaldevices182 ;
ns3::NetDeviceContainer terminaldevices183 ;
ns3::NetDeviceContainer terminaldevices184 ;
ns3::NetDeviceContainer terminaldevices185 ;
ns3::NetDeviceContainer terminaldevices186 ;
ns3::NetDeviceContainer terminaldevices187 ;
ns3::NetDeviceContainer terminaldevices188 ;
ns3::NetDeviceContainer terminaldevices189 ;
ns3::NetDeviceContainer terminaldevices190 ;
ns3::NetDeviceContainer terminaldevices191 ;
ns3::NetDeviceContainer terminaldevices192 ;
ns3::NetDeviceContainer terminaldevices193 ;
ns3::NetDeviceContainer terminaldevices194 ;
ns3::NetDeviceContainer terminaldevices195 ;
ns3::NetDeviceContainer terminaldevices196 ;
ns3::NetDeviceContainer terminaldevices197 ;
ns3::NetDeviceContainer terminaldevices198 ;
ns3::NetDeviceContainer terminaldevices199 ;
ns3::NetDeviceContainer terminaldevices200 ;
ns3::NetDeviceContainer terminaldevices201 ;
ns3::NetDeviceContainer terminaldevices202 ;
ns3::NetDeviceContainer terminaldevices203 ;
ns3::NetDeviceContainer terminaldevices204 ;
ns3::NetDeviceContainer terminaldevices205 ;
ns3::NetDeviceContainer terminaldevices206 ;
ns3::NetDeviceContainer terminaldevices207 ;
ns3::NetDeviceContainer terminaldevices208 ;
ns3::NetDeviceContainer terminaldevices209 ;
ns3::NetDeviceContainer terminaldevices210 ;
ns3::NetDeviceContainer terminaldevices211 ;
ns3::NetDeviceContainer terminaldevices212 ;
ns3::NetDeviceContainer terminaldevices214 ;
ns3::NetDeviceContainer terminaldevices215 ;
ns3::NetDeviceContainer terminaldevices216 ;
ns3::NetDeviceContainer terminaldevices217 ;
ns3::NetDeviceContainer terminaldevices218 ;
ns3::NetDeviceContainer terminaldevices219 ;
ns3::NetDeviceContainer terminaldevices220 ;
ns3::NetDeviceContainer terminaldevices221 ;
ns3::NetDeviceContainer terminaldevices222 ;
ns3::NetDeviceContainer terminaldevices223 ;
ns3::NetDeviceContainer terminaldevices224 ;
ns3::NetDeviceContainer terminaldevices225 ;
ns3::NetDeviceContainer terminaldevices226 ;
ns3::NetDeviceContainer terminaldevices227 ;
ns3::NetDeviceContainer terminaldevices228 ;
ns3::NetDeviceContainer terminaldevices229 ;
ns3::NetDeviceContainer terminaldevices230 ;
ns3::NetDeviceContainer terminaldevices231 ;
ns3::NetDeviceContainer terminaldevices232 ;
ns3::NetDeviceContainer terminaldevices233 ;
ns3::NetDeviceContainer terminaldevices234 ;
ns3::NetDeviceContainer terminaldevices235 ;
ns3::NetDeviceContainer terminaldevices236 ;
ns3::NetDeviceContainer terminaldevices237 ;
ns3::NetDeviceContainer terminaldevices238 ;
ns3::NetDeviceContainer terminaldevices239 ;
ns3::NetDeviceContainer terminaldevices240 ;
ns3::NetDeviceContainer terminaldevices241 ;
ns3::NetDeviceContainer terminaldevices242 ;
ns3::NetDeviceContainer terminaldevices243 ;
ns3::NetDeviceContainer terminaldevices244 ;
ns3::NetDeviceContainer terminaldevices245 ;
ns3::NetDeviceContainer terminaldevices246 ;
ns3::NetDeviceContainer terminaldevices247 ;
ns3::NetDeviceContainer terminaldevices248 ;
ns3::NetDeviceContainer terminaldevices284 ;
ns3::NetDeviceContainer terminaldevices249 ;
ns3::NetDeviceContainer terminaldevices250 ;
ns3::NetDeviceContainer terminaldevices251 ;
ns3::NetDeviceContainer terminaldevices252 ;
ns3::NetDeviceContainer terminaldevices253 ;
ns3::NetDeviceContainer terminaldevices254 ;
ns3::NetDeviceContainer terminaldevices255 ;
ns3::NetDeviceContainer terminaldevices256 ;
ns3::NetDeviceContainer terminaldevices257 ;
ns3::NetDeviceContainer terminaldevices258 ;
ns3::NetDeviceContainer terminaldevices259 ;
ns3::NetDeviceContainer terminaldevices260 ;
ns3::NetDeviceContainer terminaldevices261 ;
ns3::NetDeviceContainer terminaldevices262 ;
ns3::NetDeviceContainer terminaldevices263 ;
ns3::NetDeviceContainer terminaldevices264 ;
ns3::NetDeviceContainer terminaldevices265 ;
ns3::NetDeviceContainer terminaldevices266 ;
ns3::NetDeviceContainer terminaldevices267 ;
ns3::NetDeviceContainer terminaldevices268 ;
ns3::NetDeviceContainer terminaldevices269 ;
ns3::NetDeviceContainer terminaldevices270 ;
ns3::NetDeviceContainer terminaldevices272 ;
ns3::NetDeviceContainer terminaldevices273 ;
ns3::NetDeviceContainer terminaldevices274 ;
ns3::NetDeviceContainer terminaldevices275 ;
ns3::NetDeviceContainer terminaldevices276 ;
ns3::NetDeviceContainer terminaldevices277 ;
ns3::NetDeviceContainer terminaldevices278 ;
ns3::NetDeviceContainer terminaldevices279 ;
ns3::NetDeviceContainer terminaldevices280 ;
ns3::NetDeviceContainer terminaldevices281 ;
ns3::NetDeviceContainer terminaldevices282 ;
ns3::NetDeviceContainer terminaldevices283 ;
ns3::NetDeviceContainer terminaldevices285 ;
ns3::NetDeviceContainer terminaldevices286 ;
ns3::NetDeviceContainer terminaldevices287 ;
ns3::NetDeviceContainer terminaldevices288 ;
ns3::NetDeviceContainer terminaldevices289 ;
ns3::NetDeviceContainer terminaldevices290 ;
ns3::NetDeviceContainer terminaldevices291 ;
ns3::NetDeviceContainer terminaldevices292 ;
ns3::NetDeviceContainer terminaldevices293 ;
ns3::NetDeviceContainer terminaldevices294 ;
ns3::NetDeviceContainer terminaldevices295 ;
ns3::NetDeviceContainer terminaldevices296 ;
ns3::NetDeviceContainer terminaldevices297 ;
ns3::NetDeviceContainer terminaldevices298 ;
ns3::NetDeviceContainer terminaldevices299 ;
ns3::NetDeviceContainer terminaldevices300 ;
ns3::NetDeviceContainer terminaldevices301 ;
ns3::NetDeviceContainer terminaldevices302 ;
ns3::NetDeviceContainer terminaldevices303 ;
ns3::NetDeviceContainer terminaldevices304 ;
ns3::NetDeviceContainer terminaldevices305 ;
ns3::NetDeviceContainer terminaldevices306 ;
ns3::NetDeviceContainer terminaldevices307 ;
ns3::NetDeviceContainer terminaldevices308 ;
ns3::NetDeviceContainer terminaldevices309 ;
ns3::NetDeviceContainer terminaldevices310 ;
ns3::NetDeviceContainer terminaldevices311 ;
ns3::NetDeviceContainer terminaldevices312 ;
ns3::NetDeviceContainer terminaldevices313 ;
ns3::NetDeviceContainer terminaldevices314 ;
ns3::NetDeviceContainer terminaldevices315 ;
ns3::NetDeviceContainer terminaldevices316 ;
ns3::NetDeviceContainer terminaldevices317 ;
ns3::NetDeviceContainer terminaldevices318 ;
ns3::NetDeviceContainer terminaldevices319 ;
ns3::NetDeviceContainer terminaldevices320 ;
ns3::NetDeviceContainer terminaldevices321 ;
ns3::NetDeviceContainer terminaldevices322 ;
ns3::NetDeviceContainer terminaldevices323 ;
ns3::NetDeviceContainer terminaldevices324 ;
ns3::NetDeviceContainer terminaldevices325 ;
ns3::NetDeviceContainer terminaldevices326 ;
ns3::NetDeviceContainer terminaldevices327 ;
ns3::NetDeviceContainer terminaldevices328 ;
ns3::NetDeviceContainer terminaldevices329 ;
ns3::NetDeviceContainer terminaldevices330 ;
ns3::NetDeviceContainer terminaldevices331 ;
ns3::NetDeviceContainer terminaldevices332 ;
ns3::NetDeviceContainer terminaldevices334 ;
ns3::NetDeviceContainer terminaldevices335 ;
ns3::NetDeviceContainer terminaldevices336 ;
ns3::NetDeviceContainer terminaldevices337 ;
ns3::NetDeviceContainer terminaldevices338 ;
ns3::NetDeviceContainer terminaldevices339 ;
ns3::NetDeviceContainer terminaldevices340 ;
ns3::NetDeviceContainer terminaldevices341 ;
ns3::NetDeviceContainer terminaldevices342 ;
ns3::NetDeviceContainer terminaldevices343 ;
ns3::NetDeviceContainer terminaldevices344 ;
ns3::NetDeviceContainer terminaldevices345 ;
ns3::NetDeviceContainer terminaldevices346 ;
ns3::NetDeviceContainer terminaldevices347 ;
ns3::NetDeviceContainer terminaldevices348 ;
ns3::NetDeviceContainer apdevices1 ;
ns3::NetDeviceContainer apdevices2 ;
ns3::NetDeviceContainer apdevices3 ;
ns3::NetDeviceContainer apdevices4 ;
ns3::NetDeviceContainer apdevices5 ;
ns3::NetDeviceContainer apdevices6 ;
ns3::NetDeviceContainer apdevices7 ;
ns3::NetDeviceContainer apdevices8 ;
ns3::NetDeviceContainer apdevices9 ;
ns3::NetDeviceContainer apdevices10 ;
ns3::NetDeviceContainer apdevices11 ;
ns3::NetDeviceContainer apdevices12 ;
ns3::NetDeviceContainer apdevices13 ;
ns3::NetDeviceContainer apdevices14 ;
ns3::NetDeviceContainer apdevices15 ;
ns3::NetDeviceContainer apdevices16 ;
ns3::NetDeviceContainer apdevices17 ;
ns3::NetDeviceContainer apdevices18 ;
ns3::NetDeviceContainer apdevices19 ;
ns3::NetDeviceContainer apdevices20 ;
ns3::NetDeviceContainer apdevices21 ;
ns3::NetDeviceContainer apdevices22 ;
ns3::NetDeviceContainer apdevices23 ;
ns3::NetDeviceContainer apdevices24 ;
ns3::NetDeviceContainer apdevices25 ;
ns3::NetDeviceContainer apdevices26 ;
ns3::NetDeviceContainer apdevices27 ;
ns3::NetDeviceContainer apdevices28 ;
ns3::NetDeviceContainer apdevices29 ;
ns3::NetDeviceContainer apdevices30 ;
ns3::NetDeviceContainer apdevices31 ;
ns3::NetDeviceContainer apdevices32 ;
ns3::NetDeviceContainer apdevices33 ;
ns3::NetDeviceContainer apdevices34 ;
ns3::NetDeviceContainer apdevices35 ;
ns3::NetDeviceContainer apdevices36 ;
ns3::NetDeviceContainer apdevices37 ;
ns3::NetDeviceContainer apdevices38 ;
ns3::NetDeviceContainer apdevices313 ;
ns3::NetDeviceContainer apdevices39 ;
ns3::NetDeviceContainer apdevices40 ;
ns3::NetDeviceContainer apdevices41 ;
ns3::NetDeviceContainer apdevices42 ;
ns3::NetDeviceContainer apdevices43 ;
ns3::NetDeviceContainer apdevices44 ;
ns3::NetDeviceContainer apdevices45 ;
ns3::NetDeviceContainer apdevices46 ;
ns3::NetDeviceContainer apdevices47 ;
ns3::NetDeviceContainer apdevices48 ;
ns3::NetDeviceContainer apdevices49 ;
ns3::NetDeviceContainer apdevices50 ;
ns3::NetDeviceContainer apdevices51 ;
ns3::NetDeviceContainer apdevices52 ;
ns3::NetDeviceContainer apdevices53 ;
ns3::NetDeviceContainer apdevices54 ;
ns3::NetDeviceContainer apdevices55 ;
ns3::NetDeviceContainer apdevices56 ;
ns3::NetDeviceContainer apdevices57 ;
ns3::NetDeviceContainer apdevices58 ;
ns3::NetDeviceContainer apdevices59 ;
ns3::NetDeviceContainer apdevices60 ;
ns3::NetDeviceContainer apdevices61 ;
ns3::NetDeviceContainer apdevices62 ;
ns3::NetDeviceContainer apdevices63 ;
ns3::NetDeviceContainer apdevices64 ;
ns3::NetDeviceContainer apdevices65 ;
ns3::NetDeviceContainer apdevices66 ;
ns3::NetDeviceContainer apdevices67 ;
ns3::NetDeviceContainer apdevices68 ;
ns3::NetDeviceContainer apdevices69 ;
ns3::NetDeviceContainer apdevices70 ;
ns3::NetDeviceContainer apdevices71 ;
ns3::NetDeviceContainer apdevices72 ;
ns3::NetDeviceContainer apdevices73 ;
ns3::NetDeviceContainer apdevices74 ;
ns3::NetDeviceContainer apdevices75 ;
ns3::NetDeviceContainer apdevices76 ;
ns3::NetDeviceContainer apdevices77 ;
ns3::NetDeviceContainer apdevices78 ;
ns3::NetDeviceContainer apdevices79 ;
ns3::NetDeviceContainer apdevices80 ;
ns3::NetDeviceContainer apdevices81 ;
ns3::NetDeviceContainer apdevices82 ;
ns3::NetDeviceContainer apdevices83 ;
ns3::NetDeviceContainer apdevices84 ;
ns3::NetDeviceContainer apdevices85 ;
ns3::NetDeviceContainer apdevices86 ;
ns3::NetDeviceContainer apdevices87 ;
ns3::NetDeviceContainer apdevices88 ;
ns3::NetDeviceContainer apdevices89 ;
ns3::NetDeviceContainer apdevices90 ;
ns3::NetDeviceContainer apdevices91 ;
ns3::NetDeviceContainer apdevices92 ;
ns3::NetDeviceContainer apdevices93 ;
ns3::NetDeviceContainer apdevices94 ;
ns3::NetDeviceContainer apdevices95 ;
ns3::NetDeviceContainer apdevices96 ;
ns3::NetDeviceContainer apdevices97 ;
ns3::NetDeviceContainer apdevices98 ;
ns3::NetDeviceContainer apdevices99 ;
ns3::NetDeviceContainer apdevices100 ;
ns3::NetDeviceContainer apdevices101 ;
ns3::NetDeviceContainer apdevices102 ;
ns3::NetDeviceContainer apdevices103 ;
ns3::NetDeviceContainer apdevices104 ;
ns3::NetDeviceContainer apdevices105 ;
ns3::NetDeviceContainer apdevices106 ;
ns3::NetDeviceContainer apdevices107 ;
ns3::NetDeviceContainer apdevices108 ;
ns3::NetDeviceContainer apdevices109 ;
ns3::NetDeviceContainer apdevices110 ;
ns3::NetDeviceContainer apdevices111 ;
ns3::NetDeviceContainer apdevices112 ;
ns3::NetDeviceContainer apdevices113 ;
ns3::NetDeviceContainer apdevices114 ;
ns3::NetDeviceContainer apdevices115 ;
ns3::NetDeviceContainer apdevices116 ;
ns3::NetDeviceContainer apdevices117 ;
ns3::NetDeviceContainer apdevices118 ;
ns3::NetDeviceContainer apdevices119 ;
ns3::NetDeviceContainer apdevices120 ;
ns3::NetDeviceContainer apdevices121 ;
ns3::NetDeviceContainer apdevices122 ;
ns3::NetDeviceContainer apdevices123 ;
ns3::NetDeviceContainer apdevices124 ;
ns3::NetDeviceContainer apdevices125 ;
ns3::NetDeviceContainer apdevices126 ;
ns3::NetDeviceContainer apdevices127 ;
ns3::NetDeviceContainer apdevices128 ;
ns3::NetDeviceContainer apdevices129 ;
ns3::NetDeviceContainer apdevices130 ;
ns3::NetDeviceContainer apdevices131 ;
ns3::NetDeviceContainer apdevices132 ;
ns3::NetDeviceContainer apdevices133 ;
ns3::NetDeviceContainer apdevices134 ;
ns3::NetDeviceContainer apdevices135 ;
ns3::NetDeviceContainer apdevices136 ;
ns3::NetDeviceContainer apdevices137 ;
ns3::NetDeviceContainer apdevices138 ;
ns3::NetDeviceContainer apdevices139 ;
ns3::NetDeviceContainer apdevices140 ;
ns3::NetDeviceContainer apdevices141 ;
ns3::NetDeviceContainer apdevices142 ;
ns3::NetDeviceContainer apdevices143 ;
ns3::NetDeviceContainer apdevices144 ;
ns3::NetDeviceContainer apdevices145 ;
ns3::NetDeviceContainer apdevices146 ;
ns3::NetDeviceContainer apdevices147 ;
ns3::NetDeviceContainer apdevices148 ;
ns3::NetDeviceContainer apdevices149 ;
ns3::NetDeviceContainer apdevices150 ;
ns3::NetDeviceContainer apdevices151 ;
ns3::NetDeviceContainer apdevices152 ;
ns3::NetDeviceContainer apdevices153 ;
ns3::NetDeviceContainer apdevices154 ;
ns3::NetDeviceContainer apdevices155 ;
ns3::NetDeviceContainer apdevices156 ;
ns3::NetDeviceContainer apdevices157 ;
ns3::NetDeviceContainer apdevices158 ;
ns3::NetDeviceContainer apdevices159 ;
ns3::NetDeviceContainer apdevices160 ;
ns3::NetDeviceContainer apdevices161 ;
ns3::NetDeviceContainer apdevices162 ;
ns3::NetDeviceContainer apdevices163 ;
ns3::NetDeviceContainer apdevices164 ;
ns3::NetDeviceContainer apdevices165 ;
ns3::NetDeviceContainer apdevices166 ;
ns3::NetDeviceContainer apdevices167 ;
ns3::NetDeviceContainer apdevices168 ;
ns3::NetDeviceContainer apdevices169 ;
ns3::NetDeviceContainer apdevices170 ;
ns3::NetDeviceContainer apdevices171 ;
ns3::NetDeviceContainer apdevices172 ;
ns3::NetDeviceContainer apdevices173 ;
ns3::NetDeviceContainer apdevices174 ;
ns3::NetDeviceContainer apdevices175 ;
ns3::NetDeviceContainer apdevices176 ;
ns3::NetDeviceContainer apdevices177 ;
ns3::NetDeviceContainer apdevices178 ;
ns3::NetDeviceContainer apdevices179 ;
ns3::NetDeviceContainer apdevices180 ;
ns3::NetDeviceContainer apdevices181 ;
ns3::NetDeviceContainer apdevices182 ;
ns3::NetDeviceContainer apdevices183 ;
ns3::NetDeviceContainer apdevices184 ;
ns3::NetDeviceContainer apdevices185 ;
ns3::NetDeviceContainer apdevices186 ;
ns3::NetDeviceContainer apdevices187 ;
ns3::NetDeviceContainer apdevices188 ;
ns3::NetDeviceContainer apdevices189 ;
ns3::NetDeviceContainer apdevices190 ;
ns3::NetDeviceContainer apdevices191 ;
ns3::NetDeviceContainer apdevices192 ;
ns3::NetDeviceContainer apdevices193 ;
ns3::NetDeviceContainer apdevices194 ;
ns3::NetDeviceContainer apdevices195 ;
ns3::NetDeviceContainer apdevices196 ;
ns3::NetDeviceContainer apdevices197 ;
ns3::NetDeviceContainer apdevices198 ;
ns3::NetDeviceContainer apdevices199 ;
ns3::NetDeviceContainer apdevices200 ;
ns3::NetDeviceContainer apdevices201 ;
ns3::NetDeviceContainer apdevices202 ;
ns3::NetDeviceContainer apdevices203 ;
ns3::NetDeviceContainer apdevices204 ;
ns3::NetDeviceContainer apdevices205 ;
ns3::NetDeviceContainer apdevices206 ;
ns3::NetDeviceContainer apdevices207 ;
ns3::NetDeviceContainer apdevices208 ;
ns3::NetDeviceContainer apdevices209 ;
ns3::NetDeviceContainer apdevices210 ;
ns3::NetDeviceContainer apdevices211 ;
ns3::NetDeviceContainer apdevices212 ;
ns3::NetDeviceContainer apdevices213 ;
ns3::NetDeviceContainer apdevices214 ;
ns3::NetDeviceContainer apdevices215 ;
ns3::NetDeviceContainer apdevices216 ;
ns3::NetDeviceContainer apdevices217 ;
ns3::NetDeviceContainer apdevices218 ;
ns3::NetDeviceContainer apdevices219 ;
ns3::NetDeviceContainer apdevices220 ;
ns3::NetDeviceContainer apdevices221 ;
ns3::NetDeviceContainer apdevices222 ;
ns3::NetDeviceContainer apdevices223 ;
ns3::NetDeviceContainer apdevices224 ;
ns3::NetDeviceContainer apdevices225 ;
ns3::NetDeviceContainer apdevices226 ;
ns3::NetDeviceContainer apdevices227 ;
ns3::NetDeviceContainer apdevices228 ;
ns3::NetDeviceContainer apdevices229 ;
ns3::NetDeviceContainer apdevices230 ;
ns3::NetDeviceContainer apdevices231 ;
ns3::NetDeviceContainer apdevices232 ;
ns3::NetDeviceContainer apdevices233 ;
ns3::NetDeviceContainer apdevices234 ;
ns3::NetDeviceContainer apdevices235 ;
ns3::NetDeviceContainer apdevices236 ;
ns3::NetDeviceContainer apdevices237 ;
ns3::NetDeviceContainer apdevices238 ;
ns3::NetDeviceContainer apdevices239 ;
ns3::NetDeviceContainer apdevices240 ;
ns3::NetDeviceContainer apdevices241 ;
ns3::NetDeviceContainer apdevices242 ;
ns3::NetDeviceContainer apdevices243 ;
ns3::NetDeviceContainer apdevices244 ;
ns3::NetDeviceContainer apdevices245 ;
ns3::NetDeviceContainer apdevices246 ;
ns3::NetDeviceContainer apdevices247 ;
ns3::NetDeviceContainer apdevices248 ;
ns3::NetDeviceContainer apdevices284 ;
ns3::NetDeviceContainer apdevices249 ;
ns3::NetDeviceContainer apdevices250 ;
ns3::NetDeviceContainer apdevices251 ;
ns3::NetDeviceContainer apdevices252 ;
ns3::NetDeviceContainer apdevices253 ;
ns3::NetDeviceContainer apdevices254 ;
ns3::NetDeviceContainer apdevices255 ;
ns3::NetDeviceContainer apdevices256 ;
ns3::NetDeviceContainer apdevices257 ;
ns3::NetDeviceContainer apdevices258 ;
ns3::NetDeviceContainer apdevices259 ;
ns3::NetDeviceContainer apdevices260 ;
ns3::NetDeviceContainer apdevices261 ;
ns3::NetDeviceContainer apdevices262 ;
ns3::NetDeviceContainer apdevices263 ;
ns3::NetDeviceContainer apdevices264 ;
ns3::NetDeviceContainer apdevices265 ;
ns3::NetDeviceContainer apdevices266 ;
ns3::NetDeviceContainer apdevices267 ;
ns3::NetDeviceContainer apdevices268 ;
ns3::NetDeviceContainer apdevices269 ;
ns3::NetDeviceContainer apdevices270 ;
ns3::NetDeviceContainer apdevices271 ;
ns3::NetDeviceContainer apdevices272 ;
ns3::NetDeviceContainer apdevices273 ;
ns3::NetDeviceContainer apdevices274 ;
ns3::NetDeviceContainer apdevices275 ;
ns3::NetDeviceContainer apdevices276 ;
ns3::NetDeviceContainer apdevices277 ;
ns3::NetDeviceContainer apdevices278 ;
ns3::NetDeviceContainer apdevices279 ;
ns3::NetDeviceContainer apdevices280 ;
ns3::NetDeviceContainer apdevices281 ;
ns3::NetDeviceContainer apdevices282 ;
ns3::NetDeviceContainer apdevices283 ;
ns3::NetDeviceContainer apdevices285 ;
ns3::NetDeviceContainer apdevices286 ;
ns3::NetDeviceContainer apdevices287 ;
ns3::NetDeviceContainer apdevices288 ;
ns3::NetDeviceContainer apdevices289 ;
ns3::NetDeviceContainer apdevices290 ;
ns3::NetDeviceContainer apdevices291 ;
ns3::NetDeviceContainer apdevices292 ;
ns3::NetDeviceContainer apdevices293 ;
ns3::NetDeviceContainer apdevices294 ;
ns3::NetDeviceContainer apdevices295 ;
ns3::NetDeviceContainer apdevices296 ;
ns3::NetDeviceContainer apdevices297 ;
//    apdevices298 = ns.network.NetDeviceContainer()
//    apdevices299 = ns.network.NetDeviceContainer()
ns3::NetDeviceContainer apdevices300 ;
ns3::NetDeviceContainer apdevices301 ;
ns3::NetDeviceContainer apdevices302 ;
ns3::NetDeviceContainer apdevices303 ;
ns3::NetDeviceContainer apdevices304 ;
ns3::NetDeviceContainer apdevices305 ;
//    apdevices306 = ns.network.NetDeviceContainer()
ns3::NetDeviceContainer apdevices307 ;
ns3::NetDeviceContainer apdevices308 ;
ns3::NetDeviceContainer apdevices309 ;
ns3::NetDeviceContainer apdevices310 ;
ns3::NetDeviceContainer apdevices311 ;
ns3::NetDeviceContainer apdevices312 ;
ns3::NetDeviceContainer apdevices314 ;
//    apdevices315 = ns.network.NetDeviceContainer()

//wifi
	ns3::WifiHelper Wifi;
	Wifi = ns3::WifiHelper::Default();
	Wifi.SetRemoteStationManager("ns3::ArfWifiManager");

//wifi channel
	ns3::YansWifiChannelHelper wifiChannel;
	wifiChannel = ns3::YansWifiChannelHelper::Default();
	ns3::YansWifiPhy wifiPhy;
	wifiPhy = ns3::YansWifiPhyHelper::Default();
	wifiPhy.SetChannel(wifiChannel.Create());

   //wifiChannel = ns.wifi.YansWifiChannelHelper.Default()
   //wifiPhy = ns.wifi.YansWifiPhyHelper.Default()
   //wifiPhy.SetChannel(wifiChannel.Create())

   wifiChannel2 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy2 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy2.SetChannel(wifiChannel2.Create())

   wifiChannel3 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy3 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy3.SetChannel(wifiChannel3.Create())

   wifiChannel4 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy4 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy4.SetChannel(wifiChannel4.Create())

   wifiChannel5 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy5 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy5.SetChannel(wifiChannel5.Create())

   wifiChannel6 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy6 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy6.SetChannel(wifiChannel6.Create())

   wifiChannel7 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy7 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy7.SetChannel(wifiChannel7.Create())

   wifiChannel8 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy8 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy8.SetChannel(wifiChannel8.Create())

   wifiChannel9 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy9 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy9.SetChannel(wifiChannel9.Create())

   wifiChannel10 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy10 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy10.SetChannel(wifiChannel10.Create())

   wifiChannel11 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy11 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy11.SetChannel(wifiChannel11.Create())

   wifiChannel12 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy12 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy12.SetChannel(wifiChannel12.Create())

   wifiChannel13 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy13 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy13.SetChannel(wifiChannel13.Create())

   wifiChannel14 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy14 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy14.SetChannel(wifiChannel14.Create())

   wifiChannel15 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy15 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy15.SetChannel(wifiChannel15.Create())

   wifiChannel16 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy16 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy16.SetChannel(wifiChannel16.Create())

   wifiChannel17 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy17 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy17.SetChannel(wifiChannel17.Create())

   wifiChannel18 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy18 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy18.SetChannel(wifiChannel18.Create())

   wifiChannel19 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy19 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy19.SetChannel(wifiChannel19.Create())

   wifiChannel20 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy20 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy20.SetChannel(wifiChannel20.Create())

   wifiChannel21 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy21 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy21.SetChannel(wifiChannel21.Create())

   wifiChannel22 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy22 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy22.SetChannel(wifiChannel22.Create())

   wifiChannel23 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy23 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy23.SetChannel(wifiChannel23.Create())

   wifiChannel24 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy24 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy24.SetChannel(wifiChannel24.Create())

   wifiChannel25 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy25 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy25.SetChannel(wifiChannel25.Create())

   wifiChannel26 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy26 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy26.SetChannel(wifiChannel26.Create())

   wifiChannel27 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy27 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy27.SetChannel(wifiChannel27.Create())

   wifiChannel28 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy28 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy28.SetChannel(wifiChannel28.Create())

   wifiChannel29 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy29 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy29.SetChannel(wifiChannel29.Create())

   wifiChannel30 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy30 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy30.SetChannel(wifiChannel30.Create())

   wifiChannel31 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy31 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy31.SetChannel(wifiChannel31.Create())

   wifiChannel32 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy32 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy32.SetChannel(wifiChannel32.Create())

   wifiChannel33 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy33 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy33.SetChannel(wifiChannel33.Create())

   wifiChannel34 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy34 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy34.SetChannel(wifiChannel34.Create())

   wifiChannel35 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy35 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy35.SetChannel(wifiChannel35.Create())

   wifiChannel36 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy36 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy36.SetChannel(wifiChannel36.Create())

   wifiChannel37 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy37 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy37.SetChannel(wifiChannel37.Create())

   wifiChannel38 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy38 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy38.SetChannel(wifiChannel38.Create())

   wifiChannel39 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy39 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy39.SetChannel(wifiChannel39.Create())

   wifiChannel40 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy40 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy40.SetChannel(wifiChannel40.Create())

   wifiChannel41 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy41 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy41.SetChannel(wifiChannel41.Create())

   wifiChannel42 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy42 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy42.SetChannel(wifiChannel42.Create())

   wifiChannel43 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy43 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy43.SetChannel(wifiChannel43.Create())

   wifiChannel44 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy44 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy44.SetChannel(wifiChannel44.Create())

   wifiChannel45 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy45 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy45.SetChannel(wifiChannel45.Create())

   wifiChannel46 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy46 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy46.SetChannel(wifiChannel46.Create())

   wifiChannel47 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy47 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy47.SetChannel(wifiChannel47.Create())

   wifiChannel48 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy48 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy48.SetChannel(wifiChannel48.Create())

   wifiChannel49 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy49 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy49.SetChannel(wifiChannel49.Create())

   wifiChannel50 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy50 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy50.SetChannel(wifiChannel50.Create())

   wifiChannel51 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy51 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy51.SetChannel(wifiChannel51.Create())

   wifiChannel52 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy52 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy52.SetChannel(wifiChannel52.Create())

   wifiChannel53 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy53 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy53.SetChannel(wifiChannel53.Create())

   wifiChannel54 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy54 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy54.SetChannel(wifiChannel54.Create())

   wifiChannel55 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy55 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy55.SetChannel(wifiChannel55.Create())

   wifiChannel56 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy56 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy56.SetChannel(wifiChannel56.Create())

   wifiChannel57 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy57 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy57.SetChannel(wifiChannel57.Create())

   wifiChannel58 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy58 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy58.SetChannel(wifiChannel58.Create())

   wifiChannel59 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy59 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy59.SetChannel(wifiChannel59.Create())

   wifiChannel60 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy60 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy60.SetChannel(wifiChannel60.Create())

   wifiChannel61 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy61 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy61.SetChannel(wifiChannel61.Create())

   wifiChannel62 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy62 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy62.SetChannel(wifiChannel62.Create())

   wifiChannel63 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy63 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy63.SetChannel(wifiChannel63.Create())

   wifiChannel64 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy64 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy64.SetChannel(wifiChannel64.Create())

   wifiChannel65 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy65 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy65.SetChannel(wifiChannel65.Create())

   wifiChannel66 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy66 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy66.SetChannel(wifiChannel66.Create())

   wifiChannel67 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy67 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy67.SetChannel(wifiChannel67.Create())

   wifiChannel68 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy68 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy68.SetChannel(wifiChannel68.Create())

   wifiChannel69 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy69 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy69.SetChannel(wifiChannel69.Create())

   wifiChannel70 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy70 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy70.SetChannel(wifiChannel70.Create())

   wifiChannel71 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy71 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy71.SetChannel(wifiChannel71.Create())

   wifiChannel72 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy72 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy72.SetChannel(wifiChannel72.Create())

   wifiChannel73 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy73 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy73.SetChannel(wifiChannel73.Create())

   wifiChannel74 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy74 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy74.SetChannel(wifiChannel74.Create())

   wifiChannel75 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy75 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy75.SetChannel(wifiChannel75.Create())

   wifiChannel76 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy76 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy76.SetChannel(wifiChannel76.Create())

   wifiChannel77 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy77 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy77.SetChannel(wifiChannel77.Create())

   wifiChannel78 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy78 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy78.SetChannel(wifiChannel78.Create())

   wifiChannel79 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy79 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy79.SetChannel(wifiChannel79.Create())

   wifiChannel80 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy80 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy80.SetChannel(wifiChannel80.Create())

   wifiChannel81 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy81 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy81.SetChannel(wifiChannel81.Create())

   wifiChannel82 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy82 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy82.SetChannel(wifiChannel82.Create())

   wifiChannel83 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy83 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy83.SetChannel(wifiChannel83.Create())

   wifiChannel84 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy84 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy84.SetChannel(wifiChannel84.Create())

   wifiChannel85 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy85 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy85.SetChannel(wifiChannel85.Create())

   wifiChannel86 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy86 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy86.SetChannel(wifiChannel86.Create())

   wifiChannel87 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy87 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy87.SetChannel(wifiChannel87.Create())

   wifiChannel88 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy88 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy88.SetChannel(wifiChannel88.Create())

   wifiChannel89 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy89 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy89.SetChannel(wifiChannel89.Create())

   wifiChannel90 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy90 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy90.SetChannel(wifiChannel90.Create())

   wifiChannel91 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy91 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy91.SetChannel(wifiChannel91.Create())

   wifiChannel92 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy92 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy92.SetChannel(wifiChannel92.Create())

   wifiChannel93 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy93 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy93.SetChannel(wifiChannel93.Create())

   wifiChannel94 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy94 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy94.SetChannel(wifiChannel94.Create())

   wifiChannel95 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy95 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy95.SetChannel(wifiChannel95.Create())

   wifiChannel96 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy96 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy96.SetChannel(wifiChannel96.Create())

   wifiChannel97 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy97 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy97.SetChannel(wifiChannel97.Create())

   wifiChannel98 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy98 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy98.SetChannel(wifiChannel98.Create())

   wifiChannel99 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy99 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy99.SetChannel(wifiChannel99.Create())

   wifiChannel100 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy100 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy100.SetChannel(wifiChannel100.Create())

   wifiChannel101 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy101 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy101.SetChannel(wifiChannel101.Create())

   wifiChannel102 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy102 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy102.SetChannel(wifiChannel102.Create())

   wifiChannel103 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy103 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy103.SetChannel(wifiChannel103.Create())

   wifiChannel104 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy104 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy104.SetChannel(wifiChannel104.Create())

   wifiChannel105 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy105 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy105.SetChannel(wifiChannel105.Create())

   wifiChannel106 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy106 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy106.SetChannel(wifiChannel106.Create())

   wifiChannel107 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy107 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy107.SetChannel(wifiChannel107.Create())

   wifiChannel108 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy108 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy108.SetChannel(wifiChannel108.Create())

   wifiChannel109 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy109 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy109.SetChannel(wifiChannel109.Create())

   wifiChannel110 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy110 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy110.SetChannel(wifiChannel110.Create())

   wifiChannel111 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy111 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy111.SetChannel(wifiChannel111.Create())

   wifiChannel112 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy112 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy112.SetChannel(wifiChannel112.Create())

   wifiChannel113 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy113 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy113.SetChannel(wifiChannel113.Create())

   wifiChannel114 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy114 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy114.SetChannel(wifiChannel114.Create())

   wifiChannel115 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy115 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy115.SetChannel(wifiChannel115.Create())

   wifiChannel116 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy116 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy116.SetChannel(wifiChannel116.Create())

   wifiChannel117 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy117 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy117.SetChannel(wifiChannel117.Create())

   wifiChannel118 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy118 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy118.SetChannel(wifiChannel118.Create())

   wifiChannel119 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy119 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy119.SetChannel(wifiChannel119.Create())

   wifiChannel120 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy120 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy120.SetChannel(wifiChannel120.Create())

   wifiChannel121 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy121 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy121.SetChannel(wifiChannel121.Create())

   wifiChannel122 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy122 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy122.SetChannel(wifiChannel122.Create())

   wifiChannel123 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy123 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy123.SetChannel(wifiChannel123.Create())

   wifiChannel124 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy124 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy124.SetChannel(wifiChannel124.Create())

   wifiChannel125 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy125 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy125.SetChannel(wifiChannel125.Create())

   wifiChannel126 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy126 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy126.SetChannel(wifiChannel126.Create())

   wifiChannel127 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy127 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy127.SetChannel(wifiChannel127.Create())

   wifiChannel128 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy128 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy128.SetChannel(wifiChannel128.Create())

   wifiChannel129 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy129 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy129.SetChannel(wifiChannel129.Create())

   wifiChannel130 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy130 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy130.SetChannel(wifiChannel130.Create())

   wifiChannel131 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy131 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy131.SetChannel(wifiChannel131.Create())

   wifiChannel132 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy132 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy132.SetChannel(wifiChannel132.Create())

   wifiChannel133 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy133 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy133.SetChannel(wifiChannel133.Create())

   wifiChannel134 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy134 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy134.SetChannel(wifiChannel134.Create())

   wifiChannel135 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy135 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy135.SetChannel(wifiChannel135.Create())

   wifiChannel136 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy136 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy136.SetChannel(wifiChannel136.Create())

   wifiChannel137 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy137 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy137.SetChannel(wifiChannel137.Create())

   wifiChannel138 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy138 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy138.SetChannel(wifiChannel138.Create())

   wifiChannel139 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy139 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy139.SetChannel(wifiChannel139.Create())

   wifiChannel140 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy140 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy140.SetChannel(wifiChannel140.Create())

   wifiChannel141 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy141 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy141.SetChannel(wifiChannel141.Create())

   wifiChannel142 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy142 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy142.SetChannel(wifiChannel142.Create())

   wifiChannel143 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy143 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy143.SetChannel(wifiChannel143.Create())

   wifiChannel144 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy144 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy144.SetChannel(wifiChannel144.Create())

   wifiChannel145 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy145 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy145.SetChannel(wifiChannel145.Create())

   wifiChannel146 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy146 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy146.SetChannel(wifiChannel146.Create())

   wifiChannel147 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy147 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy147.SetChannel(wifiChannel147.Create())

   wifiChannel148 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy148 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy148.SetChannel(wifiChannel148.Create())

   wifiChannel149 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy149 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy149.SetChannel(wifiChannel149.Create())

   wifiChannel150 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy150 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy150.SetChannel(wifiChannel150.Create())

   wifiChannel151 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy151 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy151.SetChannel(wifiChannel151.Create())

   wifiChannel152 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy152 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy152.SetChannel(wifiChannel152.Create())

   wifiChannel153 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy153 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy153.SetChannel(wifiChannel153.Create())

   wifiChannel154 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy154 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy154.SetChannel(wifiChannel154.Create())

   wifiChannel155 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy155 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy155.SetChannel(wifiChannel155.Create())

   wifiChannel156 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy156 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy156.SetChannel(wifiChannel156.Create())

   wifiChannel157 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy157 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy157.SetChannel(wifiChannel157.Create())

   wifiChannel158 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy158 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy158.SetChannel(wifiChannel158.Create())

   wifiChannel159 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy159 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy159.SetChannel(wifiChannel159.Create())

   wifiChannel160 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy160 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy160.SetChannel(wifiChannel160.Create())

   wifiChannel161 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy161 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy161.SetChannel(wifiChannel161.Create())

   wifiChannel162 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy162 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy162.SetChannel(wifiChannel162.Create())

   wifiChannel163 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy163 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy163.SetChannel(wifiChannel163.Create())

   wifiChannel164 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy164 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy164.SetChannel(wifiChannel164.Create())

   wifiChannel165 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy165 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy165.SetChannel(wifiChannel165.Create())

   wifiChannel166 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy166 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy166.SetChannel(wifiChannel166.Create())

   wifiChannel167 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy167 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy167.SetChannel(wifiChannel167.Create())

   wifiChannel168 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy168 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy168.SetChannel(wifiChannel168.Create())

   wifiChannel169 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy169 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy169.SetChannel(wifiChannel169.Create())

   wifiChannel170 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy170 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy170.SetChannel(wifiChannel170.Create())

   wifiChannel171 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy171 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy171.SetChannel(wifiChannel171.Create())

   wifiChannel172 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy172 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy172.SetChannel(wifiChannel172.Create())

   wifiChannel173 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy173 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy173.SetChannel(wifiChannel173.Create())

   wifiChannel174 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy174 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy174.SetChannel(wifiChannel174.Create())

   wifiChannel175 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy175 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy175.SetChannel(wifiChannel175.Create())

   wifiChannel176 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy176 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy176.SetChannel(wifiChannel176.Create())

   wifiChannel177 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy177 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy177.SetChannel(wifiChannel177.Create())

   wifiChannel178 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy178 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy178.SetChannel(wifiChannel178.Create())

   wifiChannel179 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy179 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy179.SetChannel(wifiChannel179.Create())

   wifiChannel180 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy180 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy180.SetChannel(wifiChannel180.Create())

   wifiChannel181 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy181 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy181.SetChannel(wifiChannel181.Create())

   wifiChannel182 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy182 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy182.SetChannel(wifiChannel182.Create())

   wifiChannel183 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy183 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy183.SetChannel(wifiChannel183.Create())

   wifiChannel184 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy184 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy184.SetChannel(wifiChannel184.Create())

   wifiChannel185 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy185 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy185.SetChannel(wifiChannel185.Create())

   wifiChannel186 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy186 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy186.SetChannel(wifiChannel186.Create())

   wifiChannel187 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy187 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy187.SetChannel(wifiChannel187.Create())

   wifiChannel188 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy188 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy188.SetChannel(wifiChannel188.Create())

   wifiChannel189 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy189 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy189.SetChannel(wifiChannel189.Create())

   wifiChannel190 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy190 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy190.SetChannel(wifiChannel190.Create())

   wifiChannel191 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy191 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy191.SetChannel(wifiChannel191.Create())

   wifiChannel192 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy192 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy192.SetChannel(wifiChannel192.Create())

   wifiChannel193 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy193 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy193.SetChannel(wifiChannel193.Create())

   wifiChannel194 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy194 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy194.SetChannel(wifiChannel194.Create())

   wifiChannel195 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy195 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy195.SetChannel(wifiChannel195.Create())

   wifiChannel196 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy196 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy196.SetChannel(wifiChannel196.Create())

   wifiChannel197 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy197 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy197.SetChannel(wifiChannel197.Create())

   wifiChannel198 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy198 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy198.SetChannel(wifiChannel198.Create())

   wifiChannel199 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy199 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy199.SetChannel(wifiChannel199.Create())

   wifiChannel200 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy200 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy200.SetChannel(wifiChannel200.Create())

   wifiChannel201 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy201 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy201.SetChannel(wifiChannel201.Create())

   wifiChannel202 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy202 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy202.SetChannel(wifiChannel202.Create())

   wifiChannel203 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy203 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy203.SetChannel(wifiChannel203.Create())

   wifiChannel204 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy204 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy204.SetChannel(wifiChannel204.Create())

   wifiChannel205 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy205 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy205.SetChannel(wifiChannel205.Create())

   wifiChannel206 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy206 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy206.SetChannel(wifiChannel206.Create())

   wifiChannel207 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy207 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy207.SetChannel(wifiChannel207.Create())

   wifiChannel208 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy208 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy208.SetChannel(wifiChannel208.Create())

   wifiChannel209 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy209 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy209.SetChannel(wifiChannel209.Create())

   wifiChannel210 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy210 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy210.SetChannel(wifiChannel210.Create())

   wifiChannel211 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy211 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy211.SetChannel(wifiChannel211.Create())

   wifiChannel212 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy212 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy212.SetChannel(wifiChannel212.Create())

   wifiChannel213 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy213 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy213.SetChannel(wifiChannel213.Create())

   wifiChannel214 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy214 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy214.SetChannel(wifiChannel214.Create())

   wifiChannel215 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy215 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy215.SetChannel(wifiChannel215.Create())

   wifiChannel216 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy216 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy216.SetChannel(wifiChannel216.Create())

   wifiChannel217 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy217 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy217.SetChannel(wifiChannel217.Create())

   wifiChannel218 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy218 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy218.SetChannel(wifiChannel218.Create())

   wifiChannel219 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy219 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy219.SetChannel(wifiChannel219.Create())

   wifiChannel220 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy220 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy220.SetChannel(wifiChannel220.Create())

   wifiChannel221 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy221 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy221.SetChannel(wifiChannel221.Create())

   wifiChannel222 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy222 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy222.SetChannel(wifiChannel222.Create())

   wifiChannel223 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy223 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy223.SetChannel(wifiChannel223.Create())

   wifiChannel224 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy224 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy224.SetChannel(wifiChannel224.Create())

   wifiChannel225 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy225 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy225.SetChannel(wifiChannel225.Create())

   wifiChannel226 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy226 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy226.SetChannel(wifiChannel226.Create())

   wifiChannel227 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy227 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy227.SetChannel(wifiChannel227.Create())

   wifiChannel228 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy228 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy228.SetChannel(wifiChannel228.Create())

   wifiChannel229 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy229 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy229.SetChannel(wifiChannel229.Create())

   wifiChannel230 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy230 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy230.SetChannel(wifiChannel230.Create())

   wifiChannel231 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy231 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy231.SetChannel(wifiChannel231.Create())

   wifiChannel232 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy232 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy232.SetChannel(wifiChannel232.Create())

   wifiChannel233 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy233 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy233.SetChannel(wifiChannel233.Create())

   wifiChannel234 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy234 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy234.SetChannel(wifiChannel234.Create())

   wifiChannel235 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy235 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy235.SetChannel(wifiChannel235.Create())

   wifiChannel236 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy236 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy236.SetChannel(wifiChannel236.Create())

   wifiChannel237 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy237 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy237.SetChannel(wifiChannel237.Create())

   wifiChannel238 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy238 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy238.SetChannel(wifiChannel238.Create())

   wifiChannel239 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy239 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy239.SetChannel(wifiChannel239.Create())

   wifiChannel240 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy240 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy240.SetChannel(wifiChannel240.Create())

   wifiChannel241 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy241 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy241.SetChannel(wifiChannel241.Create())

   wifiChannel242 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy242 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy242.SetChannel(wifiChannel242.Create())

   wifiChannel243 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy243 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy243.SetChannel(wifiChannel243.Create())

   wifiChannel244 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy244 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy244.SetChannel(wifiChannel244.Create())

   wifiChannel245 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy245 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy245.SetChannel(wifiChannel245.Create())

   wifiChannel246 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy246 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy246.SetChannel(wifiChannel246.Create())

   wifiChannel247 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy247 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy247.SetChannel(wifiChannel247.Create())

   wifiChannel248 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy248 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy248.SetChannel(wifiChannel248.Create())

   wifiChannel249 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy249 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy249.SetChannel(wifiChannel249.Create())

   wifiChannel250 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy250 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy250.SetChannel(wifiChannel250.Create())

   wifiChannel251 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy251 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy251.SetChannel(wifiChannel251.Create())

   wifiChannel252 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy252 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy252.SetChannel(wifiChannel252.Create())

   wifiChannel253 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy253 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy253.SetChannel(wifiChannel253.Create())

   wifiChannel254 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy254 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy254.SetChannel(wifiChannel254.Create())

   wifiChannel255 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy255 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy255.SetChannel(wifiChannel255.Create())

   wifiChannel256 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy256 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy256.SetChannel(wifiChannel256.Create())

   wifiChannel257 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy257 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy257.SetChannel(wifiChannel257.Create())

   wifiChannel258 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy258 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy258.SetChannel(wifiChannel258.Create())

   wifiChannel259 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy259 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy259.SetChannel(wifiChannel259.Create())

   wifiChannel260 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy260 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy260.SetChannel(wifiChannel260.Create())

   wifiChannel261 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy261 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy261.SetChannel(wifiChannel261.Create())

   wifiChannel262 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy262 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy262.SetChannel(wifiChannel262.Create())

   wifiChannel263 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy263 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy263.SetChannel(wifiChannel263.Create())

   wifiChannel264 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy264 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy264.SetChannel(wifiChannel264.Create())

   wifiChannel265 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy265 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy265.SetChannel(wifiChannel265.Create())

   wifiChannel266 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy266 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy266.SetChannel(wifiChannel266.Create())

   wifiChannel267 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy267 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy267.SetChannel(wifiChannel267.Create())

   wifiChannel268 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy268 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy268.SetChannel(wifiChannel268.Create())

   wifiChannel269 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy269 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy269.SetChannel(wifiChannel269.Create())

   wifiChannel270 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy270 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy270.SetChannel(wifiChannel270.Create())

   wifiChannel271 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy271 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy271.SetChannel(wifiChannel271.Create())

   wifiChannel272 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy272 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy272.SetChannel(wifiChannel272.Create())

   wifiChannel273 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy273 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy273.SetChannel(wifiChannel273.Create())

   wifiChannel274 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy274 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy274.SetChannel(wifiChannel274.Create())

   wifiChannel275 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy275 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy275.SetChannel(wifiChannel275.Create())

   wifiChannel276 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy276 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy276.SetChannel(wifiChannel276.Create())

   wifiChannel277 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy277 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy277.SetChannel(wifiChannel277.Create())

   wifiChannel278 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy278 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy278.SetChannel(wifiChannel278.Create())

   wifiChannel279 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy279 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy279.SetChannel(wifiChannel279.Create())

   wifiChannel280 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy280 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy280.SetChannel(wifiChannel280.Create())

   wifiChannel281 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy281 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy281.SetChannel(wifiChannel281.Create())

   wifiChannel282 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy282 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy282.SetChannel(wifiChannel282.Create())

   wifiChannel283 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy283 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy283.SetChannel(wifiChannel283.Create())

   wifiChannel284 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy284 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy284.SetChannel(wifiChannel284.Create())

   wifiChannel285 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy285 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy285.SetChannel(wifiChannel285.Create())

   wifiChannel286 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy286 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy286.SetChannel(wifiChannel286.Create())

   wifiChannel287 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy287 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy287.SetChannel(wifiChannel287.Create())

   wifiChannel288 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy288 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy288.SetChannel(wifiChannel288.Create())

   wifiChannel289 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy289 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy289.SetChannel(wifiChannel289.Create())

   wifiChannel290 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy290 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy290.SetChannel(wifiChannel290.Create())

   wifiChannel291 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy291 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy291.SetChannel(wifiChannel291.Create())

   wifiChannel292 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy292 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy292.SetChannel(wifiChannel292.Create())

   wifiChannel293 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy293 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy293.SetChannel(wifiChannel293.Create())

   wifiChannel294 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy294 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy294.SetChannel(wifiChannel294.Create())

   wifiChannel295 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy295 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy295.SetChannel(wifiChannel295.Create())

   wifiChannel296 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy296 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy296.SetChannel(wifiChannel296.Create())

   wifiChannel297 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy297 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy297.SetChannel(wifiChannel297.Create())

//    wifiChannel298 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy298 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy298.SetChannel(wifiChannel298.Create())
//
//    wifiChannel299 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy299 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy299.SetChannel(wifiChannel299.Create())
//
   wifiChannel300 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy300 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy300.SetChannel(wifiChannel300.Create())

   wifiChannel301 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy301 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy301.SetChannel(wifiChannel301.Create())

   wifiChannel302 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy302 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy302.SetChannel(wifiChannel302.Create())

   wifiChannel303 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy303 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy303.SetChannel(wifiChannel303.Create())

   wifiChannel304 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy304 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy304.SetChannel(wifiChannel304.Create())

   wifiChannel305 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy305 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy305.SetChannel(wifiChannel305.Create())

//    wifiChannel306 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy306 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy306.SetChannel(wifiChannel306.Create())
//
   wifiChannel307 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy307 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy307.SetChannel(wifiChannel307.Create())

   wifiChannel308 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy308 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy308.SetChannel(wifiChannel308.Create())

   wifiChannel309 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy309 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy309.SetChannel(wifiChannel309.Create())

   wifiChannel310 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy310 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy310.SetChannel(wifiChannel310.Create())

   wifiChannel311 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy311 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy311.SetChannel(wifiChannel311.Create())

   wifiChannel312 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy312 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy312.SetChannel(wifiChannel312.Create())

   wifiChannel313 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy313 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy313.SetChannel(wifiChannel313.Create())

   wifiChannel314 = ns.wifi.YansWifiChannelHelper.Default()
   wifiPhy314 = ns.wifi.YansWifiPhyHelper.Default()
   wifiPhy314.SetChannel(wifiChannel314.Create())

//    wifiChannel315 = ns.wifi.YansWifiChannelHelper.Default()
//    wifiPhy315 = ns.wifi.YansWifiPhyHelper.Default()
//    wifiPhy315.SetChannel(wifiChannel315.Create())
//
	return EXIT_SUCCESS;
} //main
