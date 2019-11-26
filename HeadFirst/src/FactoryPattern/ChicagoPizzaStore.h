/*
 * ChicagoPizzaStore.h
 *
 *  Created on: 2019-4-9
 *      Author: root
 */

#ifndef CHICAGOPIZZASTORE_H_
#define CHICAGOPIZZASTORE_H_

#include "PizzaStore.h"
#include "ChicagoStyleCheesePizza.h"

class ChicagoPizzaStore: public PizzaStore {
public:
	ChicagoPizzaStore();
	Pizza* CreatePizza(std::string tpye)
	{
		if(tpye == "cheese")
		{
			return new ChicagoStyleCheesePizza();
		}
		else
		{
			return nullptr;
		}
	}
	virtual ~ChicagoPizzaStore();
};

#endif /* CHICAGOPIZZASTORE_H_ */
