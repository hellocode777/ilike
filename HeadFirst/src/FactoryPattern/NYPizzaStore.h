/*
 * NYPizzaStore.h
 *
 *  Created on: 2019-4-6
 *      Author: root
 */

#ifndef NYPIZZASTORE_H_
#define NYPIZZASTORE_H_

#include "PizzaStore.h"
#include "NYStyleCheesePizza.h"

class NYPizzaStore: public PizzaStore {
public:
	NYPizzaStore();
	Pizza* CreatePizza(std::string tpye)
	{
		if(tpye == "cheese")
		{
			return new NYStyleCheesePizza();
		}
		else
		{
			return nullptr;
		}
	}
	virtual ~NYPizzaStore();
};

#endif /* NYPIZZASTORE_H_ */
