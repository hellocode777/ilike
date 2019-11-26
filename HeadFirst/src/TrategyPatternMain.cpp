//============================================================================
// Name        : HeadFirst.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "TrategyPattern/MallardDuck.h"
#include "TrategyPattern/ModelDuck.h"
#include "TrategyPattern/FlyRocketPowered.h"


int main()
{
	// TrategyPattern

	Duck* mallard = new MallardDuck();
	mallard->performFly();
	mallard->performQuack();
	mallard->display();
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	mallard = new ModelDuck();
	mallard->performFly();
	mallard->setFlyBehavior(new FlyRocketPowered());
	mallard->performFly();
	mallard->performQuack();
	mallard->display();

	return 0;
}
