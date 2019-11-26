/*
 * Soy.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef SOY_H_
#define SOY_H_

#include "CondimentDecorator.h"

class Soy: public CondimentDecorator {
public:

	Soy(Beverage* beverage);

	virtual std::string getDescription()
	{
		return beverage->getDescription() + ", Soy";
	}

	virtual double cost()
	{
		return 1.20 + beverage->cost();
	}
	virtual ~Soy();

	Beverage* beverage;
};

#endif /* SOY_H_ */
