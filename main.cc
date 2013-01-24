#include <ns3/core-module.h>
#include <ns3/network-module.h>
#include <ns3/csma-module.h>
#include <ns3/internet-module.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/applications-module.h>
#include <ns3/ipv4-global-routing-helper.h>
#include <ns3/wifi-helper.h>
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

	return EXIT_SUCCESS;
} //main
