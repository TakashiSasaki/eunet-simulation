/*
 * InternetRouter.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef INTERNETROUTER_H_
#define INTERNETROUTER_H_

//internet-edge
class InternetRouter {
	ns3::NodeContainer internetrouter;
public:
	InternetRouter();
	virtual ~InternetRouter();
	ns3::Ptr<ns3::NodeContainer> get();
};

#endif /* INTERNETROUTER_H_ */
