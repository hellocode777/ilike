//============================================================================
// Name        : HeadFirst.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "DecoratorPattern/Espresso.h"
#include "DecoratorPattern/DarkRoast.h"
#include "DecoratorPattern/Mocha.h"
#include "DecoratorPattern/Whip.h"
#include "DecoratorPattern/HouseBlend.h"
#include "DecoratorPattern/Soy.h"


int main()
{

	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << ", $ " << beverage->cost() << std::endl;

	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	std::cout << beverage2->getDescription() << ", $ " << beverage2->cost() << std::endl;

	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	std::cout << beverage3->getDescription() << ", $ " << beverage3->cost() << std::endl;

	delete beverage;
	beverage = nullptr;

	delete beverage2;
	beverage2 = nullptr;

	delete beverage3;
	beverage3 = nullptr;


	return 0;
}
