#include "context.h"
#include "strategy.h"
#include <iostream>
using namespace std;
namespace StrategyPattern {

Context::Context(Strategy* stg) {
	_stg = stg;
}
Context::~Context() {
	if (!_stg)
		delete _stg;
}
void Context::DoAction() {
	_stg->AlgrithmInterface();
}

}
