/*
 * Espresso.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef ESPRESSO_H_
#define ESPRESSO_H_

#include "Beverage.h"

class Espresso: public Beverage {
public:
	Espresso();
	virtual double cost()
	{
		return 1.99;
	}
	virtual ~Espresso();
};

#endif /* ESPRESSO_H_ */
