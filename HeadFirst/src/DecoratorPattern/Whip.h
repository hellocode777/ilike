/*
 * Whip.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef WHIP_H_
#define WHIP_H_

#include "CondimentDecorator.h"

class Whip: public CondimentDecorator {
public:
	Whip(Beverage* beverage);

	virtual std::string getDescription()
	{
		return beverage->getDescription() + ", Whip";
	}

	virtual double cost()
	{
		return 11.20 + beverage->cost();
	}
	virtual ~Whip();

	Beverage* beverage;
};

#endif /* WHIP_H_ */
