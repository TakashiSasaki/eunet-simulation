/*
 * CsmaSwitch.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef CSMASWITCH_H_
#define CSMASWITCH_H_

#include <vector>

void createCsmaSwitch(std::vector<ns3::Ptr<ns3::NodeContainer> >::iterator i) {
	i = ns3::CreateObject<ns3::NodeContainer>();
	ns3::NodeContainer &x = &i;
	x.Create(1);
}

class CsmaSwitches {
	std::vector<ns3::Ptr<ns3::NodeContainer> > csmaSwitches;
public:
	const ns3::NodeContainer& operator[](const int index) const {
		const ns3::NodeContainer& x = this->csmaSwitches[index];
		return x;
	}

	CsmaSwitches(const int number_of_csma_switches) :
			csmaSwitches(number_of_csma_switches) {
		std::for_each(csmaSwitches.begin(), csmaSwitches.end(),
				createCsmaSwitch);
	}

	virtual ~CsmaSwitches() {
	}
};

#endif /* CSMASWITCH_H_ */
