#include "Factory.h"
#include "Product.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;
int FactoryPatternMain()
{
	Factory* fac = new ConcreteFactory();
	Product* p = fac->CreateProduct();
	return 0;
}
