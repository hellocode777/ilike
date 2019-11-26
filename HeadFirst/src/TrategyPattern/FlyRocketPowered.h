/*
 * FlyRocketPowered.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef FLYROCKETPOWERED_H_
#define FLYROCKETPOWERED_H_

#include "FlyBehavior.h"

class FlyRocketPowered: public FlyBehavior {
public:
	FlyRocketPowered();
	virtual void fly()
	{
		std::cout << "I'm flying with a rocket!!!" << std::endl;
	}
	virtual ~FlyRocketPowered();
};

#endif /* FLYROCKETPOWERED_H_ */
