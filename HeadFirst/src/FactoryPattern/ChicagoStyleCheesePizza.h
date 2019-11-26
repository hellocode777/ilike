/*
 * ChicagoStyleCheesePizza.h
 *
 *  Created on: 2019-4-6
 *      Author: root
 */

#ifndef CHICAGOSTYLECHEESEPIZZA_H_
#define CHICAGOSTYLECHEESEPIZZA_H_

#include "Pizza.h"

class ChicagoStyleCheesePizza: public Pizza {
public:
	ChicagoStyleCheesePizza();
	void Cut()
	{
		std::cout << "Cutting the pizza into square slices" << std::endl;
	}
	virtual ~ChicagoStyleCheesePizza();
};

#endif /* CHICAGOSTYLECHEESEPIZZA_H_ */
