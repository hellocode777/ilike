#include "Builder.h"
#include "Product.h"
#include "Director.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;
int BuilderPatternMain()
{
	BuilderPattern::Director* d = new BuilderPattern::Director(new BuilderPattern::ConcreteBuilder());
	d->Construct();
	return 0;
}
