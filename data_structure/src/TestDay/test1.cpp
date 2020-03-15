/*
 * test1.cpp
 *
 *  Created on: 2020-2-23
 *      Author: shuai
 */

#include "test1.h"
#include <cassert>



test1::test1() {
	// TODO Auto-generated constructor stub

}

test1::~test1() {
	// TODO Auto-generated destructor stub
}

void test1::test()
{

    assert(2+2==4);
    std::cout << "Execution continues past the first assert\n";
    assert(2+2==5);
    std::cout << "Execution continues past the second assert\n";
    std::cout<< "hello" << std::endl;

}

