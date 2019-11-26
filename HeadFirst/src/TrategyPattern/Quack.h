/*
 * Quack.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef QUACK_H_
#define QUACK_H_

#include "QuackBehavior.h"

class Quack: public QuackBehavior {
public:
	Quack();
	virtual void quack()
	{
		std::cout << "Quack!!!" << std::endl;
	}
	virtual ~Quack();
};

#endif /* QUACK_H_ */
