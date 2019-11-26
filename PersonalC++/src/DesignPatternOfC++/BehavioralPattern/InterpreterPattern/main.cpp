#include "context.h"
#include "interpret.h"
#include <iostream>
using namespace std;
int InterpreterPatternMain() {
	InterpreterPattern::Context* c = new InterpreterPattern::Context();
	InterpreterPattern::AbstractExpression* te = new InterpreterPattern::TerminalExpression("hello");
	InterpreterPattern::AbstractExpression* nte = new InterpreterPattern::NonterminalExpression(te,2);
	nte->Interpret(*c);
	return 0;
}
