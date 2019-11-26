/*
 * Abstraction.cpp
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#include "Abstraction.h"
#include "AbstractionImp.h"
#include <iostream>
using namespace std;

namespace BridgePattern {


Abstraction::Abstraction() {
}
Abstraction::~Abstraction() {
}
RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp) {
	_imp = imp;
}
RefinedAbstraction::~RefinedAbstraction()
{
}
void RefinedAbstraction::Operation() {
	_imp->Operation();
}

} /* namespace BridgePattern */
