/*
 * AbstractionImp.cpp
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#include "AbstractionImp.h"
#include <iostream>
using namespace std;

namespace BridgePattern {


AbstractionImp::AbstractionImp() {
}
AbstractionImp::~AbstractionImp() {
}
void AbstractionImp::Operation() {
	cout<<"AbstractionImp....imp..."<<endl;
}
ConcreteAbstractionImpA::ConcreteAbstractionImpA() {
}
ConcreteAbstractionImpA::~ConcreteAbstractionImpA() {
}
void ConcreteAbstractionImpA::Operation() {
	cout<<"ConcreteAbstractionImpA...."<<endl;
}
ConcreteAbstractionImpB::ConcreteAbstractionImpB() {
}
ConcreteAbstractionImpB::~ConcreteAbstractionImpB() {
}
void ConcreteAbstractionImpB::Operation() {
	cout<<"ConcreteAbstractionImpB...."<<endl;
}

} /* namespace BridgePattern */
