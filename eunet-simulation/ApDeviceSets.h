/*
 * ApDeviceSets.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef APDEVICESETS_H_
#define APDEVICESETS_H_

class ApDeviceSets {
	std::vector<ns3::NetDeviceContainer> apDeviceSets;
public:
	ns3::NetDeviceContainer & operator[](const int i) {
		return apDeviceSets[i];
	}
	ApDeviceSets(const int number_of_ap_device_set) :
			apDeviceSets(number_of_ap_device_set) {

	}
	virtual ~ApDeviceSets() {
	}
};

#endif /* APDEVICESETS_H_ */
