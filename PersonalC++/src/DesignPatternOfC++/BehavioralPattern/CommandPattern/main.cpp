#include "command.h"
#include "invoker.h"
#include "reciever.h"
#include <iostream>
using namespace std;
int CommandPatternMain() {
	CommandPattern::Reciever* rev = new CommandPattern::Reciever();
	CommandPattern::Command* cmd = new CommandPattern::ConcreteCommand(rev);
	CommandPattern::Invoker* inv = new CommandPattern::Invoker(cmd);
	inv->Invoke();
	return 0;
}
