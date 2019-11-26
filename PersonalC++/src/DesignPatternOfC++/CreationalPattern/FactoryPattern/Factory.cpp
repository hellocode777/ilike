/*
 * Factory.cpp
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#include "Factory.h"

#include "Product.h"
#include <iostream>
using namespace std;
Factory::Factory()
{
}
Factory::~Factory()
{
}
ConcreteFactory::ConcreteFactory()
{
	cout<<"ConcreteFactory....."<<endl;
}
ConcreteFactory::~ConcreteFactory()
{
}
Product* ConcreteFactory::CreateProduct()
{
	return new ConcreteProduct();
}
