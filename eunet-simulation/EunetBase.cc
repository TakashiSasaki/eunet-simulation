#include "EunetBase.h"

void EunetBase::connectSwitchNodes(const int i_switch_1, const int i_switch_2,
		uint64_t bps, uint64_t ms) {
	eunet.connectSwitchNodes(i_switch_1, i_switch_2, bps, ms);
} //connectSwitchNodes

void EunetBase::connectSwitchAndWifiAp(const int i_switch_node,
		const int i_wifi_ap_node) {
	eunet.connectSwitchAndWifiAp(i_switch_node, i_wifi_ap_node);
}	//connectSwitchAndWifiAp
