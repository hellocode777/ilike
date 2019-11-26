/*
 * MuteQuack.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef MUTEQUACK_H_
#define MUTEQUACK_H_

#include "QuackBehavior.h"

class MuteQuack: public QuackBehavior {
public:
	MuteQuack();
	virtual void quack()
	{
		std::cout << "<< Silence >>" << std::endl;
	}
	virtual ~MuteQuack();
};

#endif /* MUTEQUACK_H_ */
