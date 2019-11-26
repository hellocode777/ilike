/*
 * MallardDuck.cpp
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#include "MallardDuck.h"
#include "FlyWithWings.h"
#include "Quack.h"

MallardDuck::MallardDuck() {
	// TODO Auto-generated constructor stub
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();

}

MallardDuck::~MallardDuck() {
	// TODO Auto-generated destructor stub
}

