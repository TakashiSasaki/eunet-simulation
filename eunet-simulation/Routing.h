#ifndef ROUTING_H_
#define ROUTING_H_

#include <iostream>
#include <iomanip>

std::ostream& operator<<(std::ostream& ostream,
		ns3::Ipv4StaticRouting const & ipv4_static_routing) {
	for (size_t i = 0; ipv4_static_routing.GetNRoutes(); ++i) {
		ns3::Ipv4RoutingTableEntry & ipv4_routing_table_entry =
				ipv4_static_routing.GetRoute(i);
		ostream << i << '\t' << ipv4_routing_table_entry.GetDestNetwork() << 't'
				<< ipv4_routing_table_entry.GetDestNetworkMask() << 't'
				<< ipv4_routing_table_entry.GetGateway() << 't'
				<< ipv4_routing_table_entry.GetInterface() << std::endl;
	} //for
	return ostream;
}

#endif
