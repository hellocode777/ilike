/*
 * Beverage.h
 *
 *  Created on: 2019-3-4
 *      Author: root
 */

#ifndef BEVERAGE_H_
#define BEVERAGE_H_

#include "/home/shuai/my_code/ilike/HeadFirst/include/Public.h"

class Beverage {
public:
	Beverage();

	virtual std::string getDescription()
	{
		return description;
	}

	virtual double cost() = 0;

	virtual ~Beverage();
	std::string description = "Unknown Beverage";
};

#endif /* BEVERAGE_H_ */
