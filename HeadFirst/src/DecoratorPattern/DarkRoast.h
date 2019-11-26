/*
 * DarkRoast.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef DARKROAST_H_
#define DARKROAST_H_

#include "Beverage.h"

class DarkRoast: public Beverage {
public:
	DarkRoast();
	virtual double cost()
	{
		return 2.99;
	}
	virtual ~DarkRoast();
};

#endif /* DARKROAST_H_ */
