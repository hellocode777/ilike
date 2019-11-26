#include "context.h" 
#include "strategy.h"
#include <iostream> 
using namespace std;
int StrategyPatternMain() { 
	StrategyPattern::Strategy* ps = new StrategyPattern::ConcreteStrategyA();
	StrategyPattern::Context* pc = new StrategyPattern::Context(ps);
	pc->DoAction();
	if (NULL != pc) 
	delete pc;
	return 0; 
}
