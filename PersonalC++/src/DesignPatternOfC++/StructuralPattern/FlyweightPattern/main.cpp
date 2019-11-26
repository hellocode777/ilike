#include "Facade.h"
#include <iostream>
using namespace std;
int FlyweightPatternMain()
{
	FlyweightPattern::Facade* f = new FlyweightPattern::Facade();
	f->OperationWrapper();
	return 0;
}
