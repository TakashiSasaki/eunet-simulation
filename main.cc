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

	return EXIT_SUCCESS;
} //main
