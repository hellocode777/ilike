#include "Prototype.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;

int PrototyPatternMain() {
	PrototypePattern::Prototype* p = new PrototypePattern::ConcretePrototype();
	PrototypePattern::Prototype* p1 = p->Clone();
	return 0;
}
