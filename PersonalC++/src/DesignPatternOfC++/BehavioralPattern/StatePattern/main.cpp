#include "context.h"
#include "state.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;
int StatePatternMain() {
	StatePattern::State* st = new StatePattern::ConcreteStateA();
	StatePattern::Context* con = new StatePattern::Context(st);
	con->OperationChangState();
	con->OperationChangState();
	con->OperationChangState();
	con->OperationChangState();
	con->OperationChangState();
	con->OperationChangState();
	if (con != NULL)
		delete con;
	if (st != NULL)
		st = NULL;
	return 0;
}
