/*
 * Squeak.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef SQUEAK_H_
#define SQUEAK_H_

#include "QuackBehavior.h"

class Squeak: public QuackBehavior {
public:
	Squeak();

	virtual void quack()
	{
		std::cout << "Squeak!!" << std::endl;
	}
	virtual ~Squeak();
};

#endif /* SQUEAK_H_ */
