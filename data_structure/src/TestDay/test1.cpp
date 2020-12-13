/*
 * test1.cpp
 *
 *  Created on: 2020-2-23
 *      Author: shuai
 */

#include "test1.h"
#include <cassert>
#include <memory>



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
    assert(2+2 != 5);
    std::cout << "Execution continues past the second assert\n";
    std::cout<< "hello" << std::endl;

}

void test1::testSmartPtr()
{
    std::shared_ptr<int> intPtr = std::make_shared<int>(10);
    std::cout<< "inPtr=" << *intPtr << std::endl;
    int* intP = intPtr.get();
    delete intP;
    std::cout<< "inPtr=" << *intPtr.get() << std::endl;
    std::cout<< "inPtr=" << *intPtr << std::endl;


}