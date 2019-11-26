#include "context.h"
#include "state.h"
namespace StatePattern {
Context::Context() {
}
Context::Context(State* state) {
	this->_state = state;
}
Context::~Context() {
	delete _state;
}
void Context::OprationInterface() {
	_state->OperationInterface(this);
}
bool Context::ChangeState(State* state) {
	///_state->ChangeState(this,state);
	this->_state = state;
	return true;
}
void Context::OperationChangState() {
	_state->OperationChangeState(this, _state);
}
}
