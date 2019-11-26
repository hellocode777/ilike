/*
 * Adapter_dui.cpp
 *
 *  Created on: 2018-11-27
 *      Author: root
 */

#include "Adapter_dui.h"
#include <iostream>

namespace AdapterPattern_dui_ {


Target::Target() {
}
Target::~Target() {
}
void Target::Request() {
	std::cout<<"Target::Request"<<std::endl;
}
Adaptee::Adaptee() {
}
Adaptee::~Adaptee() {
}
void Adaptee::SpecificRequest() {
	std::cout<<"Adaptee::SpecificRequest"<<std::endl;
}
Adapter::Adapter(Adaptee* ade) {
	this->_ade = ade;
}
Adapter::~Adapter() {

}
void Adapter::Request() {
	_ade->SpecificRequest();
}

} /* namespace AdapterPattern_dui_ */
