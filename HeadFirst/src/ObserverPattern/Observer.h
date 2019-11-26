/*
 * Observer.h
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_
//#include <iostream>
//#include "../../../../include/Public.h"
#include "/home/shuai/workspace/C-Knowledge/HeadFirst/include/Public.h"

//HeadFirst/src/ObserverPattern/src/Observer.h
//HeadFirst/include/Public.h"
class Observer {
public:
	Observer();
	virtual void update(float temp, float humidity, float pressure) = 0;

	virtual bool operator ==(const Observer& other)
	{
		return true;
	}

	virtual ~Observer();
};

#endif /* OBSERVER_H_ */
