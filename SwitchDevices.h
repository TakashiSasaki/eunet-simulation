/*
 * SwitchDevices.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef SWITCHDEVICES_H_
#define SWITCHDEVICES_H_

void createNetDeviceContainer(
		std::vector<ns3::Ptr<ns3::NetDeviceContainer> >::iterator& current_position) {
	current_position = ns3::CreateObject<ns3::NetDeviceContainer>();
}

class SwitchDevices {
	std::vector<ns3::Ptr<ns3::NetDeviceContainer>> netDeviceContainers;
public:

	const ns3::Ptr<ns3::NetDeviceContainer> & operator [](const int position) {
		return netDeviceContainers[position];
	}

	SwitchDevices(const int number_of_devices) :
			netDeviceContainers(number_of_devices) {
		this->netDeviceContainers = new std::vector<
				ns3::Ptr<ns3::NetDeviceContainer> >(number_of_devices);
		std::for_each(netDeviceContainers.begin(), netDeviceContainers.end(),
				createNetDeviceContainer);
	}

	virtual ~SwitchDevices() {
	}
};

#endif /* SWITCHDEVICES_H_ */
