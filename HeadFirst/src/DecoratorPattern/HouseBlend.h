/*
 * HouseBlend.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef HOUSEBLEND_H_
#define HOUSEBLEND_H_

#include "Beverage.h"

class HouseBlend: public Beverage {
public:
	HouseBlend();
	virtual double cost()
	{
		return 0.89;
	}
	virtual ~HouseBlend();
};

#endif /* HOUSEBLEND_H_ */
