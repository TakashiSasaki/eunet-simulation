/*
 * Eunet.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: sasaki
 */

#include "Eunet.h"
#include "EunetBase.h"
#include "EunetTarumi.h"
#include "EunetJyouhoku.h"
#include "EunetShigenobu.h"
#include "EunetMochida.h"

void Eunet::InstallCsmaLink() {
	connectSwitchNodes(EunetBase::INTERNET_ROUTER_INDEX,
			EunetBase::CORE_SWITCH_INDEX, 1000000000, 2);
	EunetTarumi eunet_tarumi(*this);
	eunet_tarumi.connectTier1();
	eunet_tarumi.connectTier2();
	eunet_tarumi.connectTier3();
	eunet_tarumi.connectTier4();
	eunet_tarumi.connectAp();

	EunetJyouhoku eunet_jyouhoku(*this);
	eunet_jyouhoku.connectTier1();
	eunet_jyouhoku.connectTier2();
	eunet_jyouhoku.connectTier3();
	eunet_jyouhoku.connectTier4();
	eunet_jyouhoku.connectTier5();
	eunet_jyouhoku.connectAp1();
	eunet_jyouhoku.connectAp2();

	EunetShigenobu eunet_shigenobu(*this);
	eunet_shigenobu.connectTier1();
	eunet_shigenobu.connectTier2();
	eunet_shigenobu.connectTier3();
	eunet_shigenobu.connectTier4();
	eunet_shigenobu.connectAp();

	EunetMochida eunet_mochida(*this);
	eunet_mochida.connectTier1();
	eunet_mochida.connectTier2();
} //InstallCsmaLink
