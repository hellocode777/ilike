/*
 * ModelDuck.cpp
 *
 *  Created on: 2019-2-23
 *      Author: root
 */

#include "ModelDuck.h"
#include "FlyNoWay.h"
#include "Quack.h"

ModelDuck::ModelDuck() {
	// TODO Auto-generated constructor stub
	flyBehavior = new FlyNoWay();
	quackBehavior = new Quack();

}

ModelDuck::~ModelDuck() {
	// TODO Auto-generated destructor stub
}

