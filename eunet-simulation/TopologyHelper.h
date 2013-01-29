/*
 * TopologyHelper.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef TOPOLOGYHELPER_H_
#define TOPOLOGYHELPER_H_

#include <ns3/net-device-container.h>
#include <ns3/csma-helper.h>
#include <ns3/node-container.h>

class TopologyHelper {
public:
	TopologyHelper();
	virtual ~TopologyHelper();
	void InstallCsmaLink(const ns3::NodeContainer& nc1,
			ns3::NetDeviceContainer& ndc1, const ns3::NodeContainer& nc2,
			ns3::NetDeviceContainer& ndc2, const uint64_t bps,
			const uint64_t ms);
};

#endif /* TOPOLOGYHELPER_H_ */
