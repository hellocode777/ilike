/*
 * Product.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_



class Product
{
public:
	virtual ~Product() =0;
protected:
	Product();//
private:
};

class ConcreteProduct:public Product
{
public:
	~ConcreteProduct();
	ConcreteProduct();
protected:
private:
};

#endif /* PRODUCT_H_ */
