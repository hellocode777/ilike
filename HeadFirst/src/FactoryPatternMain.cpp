//============================================================================
// Name        : HeadFirst.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "FactoryPattern/NYStyleCheesePizza.h"
#include "FactoryPattern/ChicagoStyleCheesePizza.h"
#include "FactoryPattern/NYPizzaStore.h"
#include "FactoryPattern/ChicagoPizzaStore.h"


int main()
{

	PizzaStore* nyStore = new NYPizzaStore();
	Pizza* pizza = nyStore->OrderPizza("cheese");
	std::cout << "Ethan ordered a " << pizza->GetName() << std::endl;

	delete nyStore;
	delete pizza;

	nyStore = new ChicagoPizzaStore();
	pizza = nyStore->OrderPizza("cheese");
	std::cout << "Ethan ordered a " << pizza->GetName() << std::endl;
	delete nyStore;
	nyStore = nullptr;

	delete pizza;
	pizza = nullptr;


	return 0;
}
