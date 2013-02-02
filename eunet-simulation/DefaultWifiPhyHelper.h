/*
 * DefaultWifiPhy.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef DEFAULTWIFIPHY_H_
#define DEFAULTWIFIPHY_H_

#include <ns3/yans-wifi-channel.h>
#include <ns3/yans-wifi-helper.h>
#include <ns3/yans-wifi-phy.h>
#include <ns3/error-rate-model.h>
#include <ns3/propagation-delay-model.h>
#include <ns3/propagation-loss-model.h>
#include <ns3/propagation-environment.h>

class DefaultWifiChannelHelper: public ns3::YansWifiChannelHelper {
public:
	DefaultWifiChannelHelper() {
		this->SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel");
		this->AddPropagationLoss("ns3::LogDistancePropagationLossModel");
	}
	~DefaultWifiChannelHelper() {
	}
};

class DefaultWifiPhyHelper: public ns3::YansWifiPhyHelper {
	DefaultWifiChannelHelper defaultWifiChannelHelper;
	ns3::Ptr<ns3::YansWifiChannel> pYansWifiChannel;
public:
	DefaultWifiPhyHelper() :
			// Note that the order of initialization of members follows the order of declaration.
			pYansWifiChannel(defaultWifiChannelHelper.Create()) {
		this->SetErrorRateModel("ns3::NistErrorRateModel");
		this->SetChannel(pYansWifiChannel);
	}
	virtual ~DefaultWifiPhyHelper() {
	}
};

#endif /* DEFAULTWIFIPHY_H_ */
