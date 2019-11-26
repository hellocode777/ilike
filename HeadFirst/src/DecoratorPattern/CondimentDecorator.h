/*
 * CondimentDecorator.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef CONDIMENTDECORATOR_H_
#define CONDIMENTDECORATOR_H_

#include "Beverage.h"

class CondimentDecorator: public Beverage {
public:
	CondimentDecorator();
	virtual std::string getDescription() = 0;
	virtual ~CondimentDecorator();
};

#endif /* CONDIMENTDECORATOR_H_ */
