/*
 * FlyNoWay.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef FLYNOWAY_H_
#define FLYNOWAY_H_

#include "FlyBehavior.h"

class FlyNoWay: public FlyBehavior {
public:
	FlyNoWay();
	virtual void fly()
	{
		std::cout << "I can't fly!!!" << std::endl;
	}

	virtual ~FlyNoWay();
};

#endif /* FLYNOWAY_H_ */
