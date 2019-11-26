#include "reciever.h"
#include <iostream>

namespace CommandPattern {
Reciever::Reciever() {
}
Reciever::~Reciever() {
}
void Reciever::Action() {
	std::cout<<"Reciever action......."<<std::endl;
}
}
