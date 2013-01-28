/*
 * TerminalDeviceSets.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef TERMINALDEVICESETS_H_
#define TERMINALDEVICESETS_H_

class TerminalDeviceSets {
	std::vector<ns3::NetDeviceContainer> terminalDeviceSets;

public:
	ns3::NetDeviceContainer& operator[](const int i) {
		return terminalDeviceSets[i];
	}

	TerminalDeviceSets(const int number_of_terminal_device_set) :
			terminalDeviceSets(number_of_terminal_device_set) {
	}

	virtual ~TerminalDeviceSets() {
	}
};

#endif /* TERMINALDEVICESETS_H_ */
