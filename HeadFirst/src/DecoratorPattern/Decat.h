/*
 * Decat.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef DECAT_H_
#define DECAT_H_

#include "Beverage.h"

class Decat: public Beverage {
public:
	Decat();
	virtual double cost()
	{
		return 0.99;
	}
	virtual ~Decat();
};

#endif /* DECAT_H_ */
