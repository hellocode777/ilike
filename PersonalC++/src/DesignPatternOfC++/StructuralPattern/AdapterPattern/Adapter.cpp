/*
 * Adapter.cpp
 *
 *  Created on: 2018-11-27
 *      Author: root
 */

#include "Adapter.h"
#include <iostream>

namespace AdapterPattern_class_ {


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
void Adaptee::SpecificRequest(){
	std::cout<<"Adaptee::SpecificRequest" <<std::endl;
}
Adapter::Adapter() {
}
Adapter::~Adapter() {
}
void Adapter::Request() {
	this->SpecificRequest();
}

} /* namespace AdapterPattern */
