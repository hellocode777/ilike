/*
 * Duck.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef DUCK_H_
#define DUCK_H_
#include "/home/shuai/my_code/ilike/HeadFirst/include/Public.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck {

public:
	Duck();

	virtual void display()=0;

	void performFly()
	{
		flyBehavior->fly();
	}

	void performQuack()
	{
		quackBehavior->quack();
	}

	void swim()
	{
		std::cout << "All ducks float, event decoys!" << std::endl;
	}

	void setFlyBehavior(FlyBehavior* fd)
	{
		flyBehavior = fd;
	}

	void setQuackBehavior(QuackBehavior* fd)
	{
		quackBehavior = fd;
	}

	virtual ~Duck();



	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

#endif /* DUCK_H_ */
