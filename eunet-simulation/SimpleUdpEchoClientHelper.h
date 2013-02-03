/*
 * SimpleUdpEchoClientHelper.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef SIMPLEUDPECHOCLIENTHELPER_H_
#define SIMPLEUDPECHOCLIENTHELPER_H_

class SimpleUdpEchoClientHelper: public ns3::UdpEchoClientHelper {
	static int const echoPort = 7;
	static int const discardPort = 9;
public:
	SimpleUdpEchoClientHelper(ns3::Ipv4Address const& remote_ipv4_address) :
			UdpEchoClientHelper(remote_ipv4_address, echoPort) {
	}
	virtual ~SimpleUdpEchoClientHelper();
};

#endif /* SIMPLEUDPECHOCLIENTHELPER_H_ */
