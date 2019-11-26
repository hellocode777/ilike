#include "invoker.h"
#include "command.h"
#include <iostream>
namespace CommandPattern{
Invoker::Invoker(Command* cmd) {
	_cmd = cmd;
}
Invoker::~Invoker() {
	delete _cmd;
}
void Invoker::Invoke() {
	_cmd->Excute();
}
}
