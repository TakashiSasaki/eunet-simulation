/*
 * DefaultMobilityHelper.h
 *
 *  Created on: Jan 28, 2013
 *      Author: sasaki
 */

#ifndef DEFAULTMOBILITYHELPER_H_
#define DEFAULTMOBILITYHELPER_H_

#include <ns3/mobility-helper.h>
#include <ns3/mobility-model.h>

class DefaultMobilityHelper: public ns3::MobilityHelper {
public:
	DefaultMobilityHelper() {
		SetPositionAllocator("ns3::GridPositionAllocator", "MinX",
				ns3::DoubleValue(-30), "MinY", ns3::DoubleValue(0), "DeltaX",
				ns3::DoubleValue(1.0), "DeltaY", ns3::DoubleValue(0.0),
				"GridWidth", ns3::UintegerValue(3), "LayoutType",
				ns3::StringValue("RowFirst"));
		SetMobilityModel("ns3::RandomWalk2dMobilityModel", "Bounds",
				ns3::RectangleValue(ns3::Rectangle(-30, 30, -30, 30)));
	}
	virtual ~DefaultMobilityHelper() {
	}
};

#endif /* DEFAULTMOBILITYHELPER_H_ */
