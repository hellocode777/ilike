/*
 * FlyBehavior.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef FLYBEHAVIOR_H_
#define FLYBEHAVIOR_H_

#include "/home/shuai/my_code/ilike/HeadFirst/include/Public.h"

class FlyBehavior {
public:
	FlyBehavior();
	virtual void fly()=0;
	virtual ~FlyBehavior();
};

#endif /* FLYBEHAVIOR_H_ */
