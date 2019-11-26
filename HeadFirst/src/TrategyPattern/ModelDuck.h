/*
 * ModelDuck.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef MODELDUCK_H_
#define MODELDUCK_H_

#include "Duck.h"

class ModelDuck: public Duck {
public:
	ModelDuck();
	virtual void display()
	{
		std::cout << "I'm a model duck!!!" << std::endl;
	}
	virtual ~ModelDuck();
};

#endif /* MODELDUCK_H_ */
