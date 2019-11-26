#include "handle.h"
#include <iostream>
using namespace std;
int ChainOfResponsibilityPatternMain() {
	ChainOfResponsibilityPattern::Handle* h1 = new ChainOfResponsibilityPattern::ConcreteHandleA();
	ChainOfResponsibilityPattern::Handle* h2 = new ChainOfResponsibilityPattern::ConcreteHandleB();
	h1->SetSuccessor(h2);


	h1->HandleRequest();
	return 0;
}
