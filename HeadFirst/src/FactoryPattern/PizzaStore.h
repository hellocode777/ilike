/*
 * PizzaStore.h
 *
 *  Created on: 2019-4-6
 *      Author: root
 */

#ifndef PIZZASTORE_H_
#define PIZZASTORE_H_
#include "/home/shuai/workspace/C-Knowledge/HeadFirst/include/Public.h"
#include "Pizza.h"
class PizzaStore {
public:
	PizzaStore();
	Pizza* OrderPizza(std::string type)
	{
		Pizza* pizza;
		pizza = CreatePizza(type);

		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();

		return pizza;

	}
	virtual Pizza* CreatePizza(std::string type) = 0;
	virtual ~PizzaStore();
};

#endif /* PIZZASTORE_H_ */
