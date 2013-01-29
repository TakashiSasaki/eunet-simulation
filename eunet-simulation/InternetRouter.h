/*
 * InternetRouter.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef INTERNETROUTER_H_
#define INTERNETROUTER_H_

#include <ns3/node-container.h>
#include <ns3/node.h>

//internet-edge
class InternetRouter {
	ns3::NodeContainer internetrouter;
public:
	InternetRouter();
	virtual ~InternetRouter();
	ns3::Ptr<ns3::Node> get() const;
};

#endif /* INTERNETROUTER_H_ */
