/*
 * MallardDuck.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef MALLARDDUCK_H_
#define MALLARDDUCK_H_

#include "Duck.h"

class MallardDuck: public Duck {
public:
	MallardDuck();
	virtual void display()
	{
		std::cout << "I'm a real Mallard duck" << std::endl;
	}
	virtual ~MallardDuck();
};

#endif /* MALLARDDUCK_H_ */
