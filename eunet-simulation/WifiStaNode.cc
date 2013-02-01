#include <ns3/nqos-wifi-mac-helper.h>
#include "WifiStaNode.h"

bool WifiStaNode::initialized = false;

ns3::NqosWifiMacHelper WifiStaNode::nqosWifiMacHelper;
