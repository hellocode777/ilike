/*
 * Product.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_


class AbstractProductA
{
public:
	virtual ~AbstractProductA();
protected:
	AbstractProductA();
private:
};

class AbstractProductB
{
public:
	virtual ~AbstractProductB();
protected:
	AbstractProductB();
private:
};

class ProductA1:public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();
protected:
private:
};
class ProductA2:public AbstractProductA { public: ProductA2();
~ProductA2();
protected:
private:
};

class ProductB1:public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();
protected:
private:
};

class ProductB2:public AbstractProductB
{
public:ProductB2();
	~ProductB2();
protected:
private:
};

#endif /* PRODUCT_H_ */
