/*
 * Factory.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef FACTORY_H_
#define FACTORY_H_

class Product;
class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
protected:
	Factory();
private:
};
class ConcreteFactory:public Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product* CreateProduct();
protected:
private:
};

#endif /* FACTORY_H_ */
