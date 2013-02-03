/*
 * EunetBase.h
 *
 *  Created on: Feb 3, 2013
 *      Author: sasaki
 */

#ifndef EUNETBASE_H_
#define EUNETBASE_H_

class EunetBase {
public:
	enum {
		INTERNET_ROUTER_INDEX = 0,
		CORE_SWITCH_INDEX = 1,
		JYOUHOKU_SWITCH_INDEX = 2,
		SHIGENOBU_SWITCH_INDEX = 3,
		TARUMI_SWITCH_INDEX = 4
	};

public:
	EunetBase() {
	}
	virtual ~EunetBase() {
	}
};

#endif /* EUNETBASE_H_ */
