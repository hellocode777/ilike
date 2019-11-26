/*
 * Director.cpp
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#include "Director.h"
#include "Builder.h"

namespace BuilderPattern {

Director::Director(Builder* bld)
{
	_bld = bld;
}
Director::~Director()
{ }
void Director::Construct()
{
	_bld->BuildPartA("user-defined");
	_bld->BuildPartB("user-defined");
	_bld->BuildPartC("user-defined");
}

} /* namespace BuilderPattern */
