/*
 * Mocha.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef MOCHA_H_
#define MOCHA_H_

#include "CondimentDecorator.h"

class Mocha: public CondimentDecorator {
public:
	Mocha(Beverage* beverage);

	virtual std::string getDescription()
	{
		return beverage->getDescription() + ", Mocha";
	}

	virtual double cost()
	{
		return 0.20 + beverage->cost();
	}
	virtual ~Mocha();

	Beverage* beverage;

};

#endif /* MOCHA_H_ */
