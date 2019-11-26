/*
 * Product.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

namespace BuilderPattern
{

class Product
{
public:
	Product();
	~Product();
	void ProducePart();
protected:
private:
};

class ProductPart
{
public:
	ProductPart();
	~ProductPart();
	ProductPart* BuildPart();
protected:
private:
};

} /* namespace BuilderPattern */
#endif /* PRODUCT_H_ */
