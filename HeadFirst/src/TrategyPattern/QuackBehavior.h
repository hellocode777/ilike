/*
 * QuackBehavior.h
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#ifndef QUACKBEHAVIOR_H_
#define QUACKBEHAVIOR_H_
#include "/home/shuai/workspace/C-Knowledge/HeadFirst/include/Public.h"
class QuackBehavior {
public:
	QuackBehavior();
	virtual void quack()= 0;
	virtual ~QuackBehavior();
};

#endif /* QUACKBEHAVIOR_H_ */
