/*
 * SwitchDevices.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef SWITCHDEVICES_H_
#define SWITCHDEVICES_H_

class SwitchDevices {
	std::vector<ns3::NetDeviceContainer> netDeviceContainers;
public:

	ns3::NetDeviceContainer & operator [](const int position) {
		return netDeviceContainers[position];
	}

	SwitchDevices(const int number_of_devices) :
			netDeviceContainers(number_of_devices) {
	}

	virtual ~SwitchDevices() {
	}
};

#endif /* SWITCHDEVICES_H_ */
