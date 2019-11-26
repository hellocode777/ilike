/*
 * Product.cpp
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#include "Product.h"
#include <iostream>
using namespace std;

namespace BuilderPattern
{
Product::Product()
{
	ProducePart();
	cout<<"return a product"<<endl;
}
Product::~Product()
{
}
void Product::ProducePart()
{
	cout<<"build part of product.."<<endl;
}
ProductPart::ProductPart()
{
	//cout<<"build productpart.."<<endl;

}
ProductPart::~ProductPart()
{
}
ProductPart* ProductPart::BuildPart()
{
	return new ProductPart;
}

}
