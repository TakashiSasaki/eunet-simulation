/*
 * Sandbox.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: sasaki
 */

#include "Sandbox.h"
#include <ns3/net-device.h>
#include <ns3/node.h>
#include <ns3/bridge-net-device.h>
#include <ns3/simple-net-device.h>
#include <ns3/core-module.h>

Sandbox::Sandbox() {
	// TODO Auto-generated constructor stub

}

void Sandbox::run() {
	ns3::Ptr<ns3::Node> p_node;
	p_node = ns3::CreateObject<ns3::Node>();
	ns3::Ptr<ns3::NetDevice> p_net_device;
	p_net_device = ns3::CreateObject<ns3::SimpleNetDevice>();
	p_node->AddDevice(p_net_device);
	ns3::Simulator::Run();
	ns3::Simulator::Stop(ns3::Seconds(1000));
}

Sandbox::~Sandbox() {
	// TODO Auto-generated destructor stub
}

