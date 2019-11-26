#include "Abstraction.h"
#include "AbstractionImp.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;
int BridgePatternMain() {
	BridgePattern::AbstractionImp* imp = new BridgePattern::ConcreteAbstractionImpA();
	BridgePattern::Abstraction* abs = new BridgePattern::RefinedAbstraction(imp);
	abs->Operation();
	return 0;
}
