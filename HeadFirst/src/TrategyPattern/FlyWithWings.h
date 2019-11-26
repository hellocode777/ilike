/*
 * FlyWithWings.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef FLYWITHWINGS_H_
#define FLYWITHWINGS_H_

#include "FlyBehavior.h"

class FlyWithWings: public FlyBehavior {
public:
	FlyWithWings();
	virtual void fly()
	{
		std::cout << "I'm flying!!" << std::endl;
	}
	virtual ~FlyWithWings();
};

#endif /* FLYWITHWINGS_H_ */
