/*
 * CoreSwitch.h
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#ifndef CORESWITCH_H_
#define CORESWITCH_H_

#include <ns3/node-container.h>
#include <ns3/node.h>

class CoreSwitch {
	ns3::NodeContainer nodeContainer;
	const std::string description;
public:
	CoreSwitch(const std::string& description);
	virtual ~CoreSwitch();
	ns3::Ptr<ns3::Node> get() const;
	operator const ns3::NodeContainer&() const;
};

#endif /* CORESWITCH_H_ */
