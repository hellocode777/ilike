/*
 * Pizza.h
 *
 *  Created on: 2019-4-6
 *      Author: root
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include "/home/shuai/workspace/C-Knowledge/HeadFirst/include/Public.h"

class Pizza {
public:
	Pizza();
	virtual void Prepare()
	{
		std::cout << "Preparing " << m_name << std::endl;
		std::cout << "Tossing dough..." << std::endl;
		std::cout << "Adding sauce..." << std::endl;
	}
	virtual void Bake()
	{
		std::cout << "Bake for 25 minutes at 350." << std::endl;
	}

	virtual void Cut()
	{
		std::cout << "Cutting the pizza into diagonal slices." << std::endl;
	}

	virtual void Box()
	{
		std::cout << "Place pizza in official PizzaStore box." << std::endl;
	}

	std::string GetName()
	{
		return m_name;
	}

	void SetName(std::string name)
	{
		m_name = name;
	}

	void SetDough(std::string dough)
	{
		m_dough = dough;
	}

	void SetSauce(std::string sauce)
	{
		m_name = sauce;
	}

	virtual ~Pizza() = 0;
private:
	std::string m_name;
	std::string m_dough;
	std::string m_sauce;
};

#endif /* PIZZA_H_ */
