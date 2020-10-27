/*
 * test1.cpp
 *
 *  Created on: 2020-2-23
 *      Author: shuai
 */

#include "test.h"
#include <cassert>

#include <memory>
#include <iostream>
#include <utility>
#include <vector>



test::test() {
	// TODO Auto-generated constructor stub

}

test::~test() {
	// TODO Auto-generated destructor stub
}

void test::test1()
{

    assert(2+2==4);
    std::cout << "Execution continues past the first assert\n";
    assert(2+2==4);
    std::cout << "Execution continues past the second assert\n";
    std::cout<< "hello" << std::endl;

}

void test::test2()
{
	int a = 6;
	int *p = &a;

	std::cout << "*p=" << *p << std::endl;

	*p = 10;
	std::cout << "*p=" << *p << std::endl;
	int b = *p;
	std::cout << "b=" << b << std::endl;

	int i = 1;
	a = i++;
	std::cout << " a=" << a << "i=" << i << std::endl;//a=1,i=2

	i = 1;
	a = ++i;
	std::cout << " a=" << a << "i=" << i << std::endl;//a=2,i=2

	int sum[] = {1,2,3,4};

}

class Student
{
public:
	void set(std::unique_ptr<int> &a)
	{
		//oo = std::unique_ptr<int>(std::move(a));

		foo = std::move(a);
	}

	int& get()
	{
		return *foo;
	}

	std::unique_ptr<int>& getPtr()
	{
		return foo;
	}

	std::unique_ptr<int> foo;
};

void test::test3()
{
	  std::unique_ptr<int> foo;
	  std::unique_ptr<int> bar;

	  foo = std::unique_ptr<int>(new int (101));  // rvalue
	  std::cout << "foo: ";
	  if (foo) std::cout << *foo << '\n'; else std::cout << "empty\n";


	  Student stu;
	  stu.set(foo);

	  //int a = std::move(stu.get());
	  bar = std::move(stu.getPtr());
          //此时stu.foo为null，因为资源被移走
	  //std::cout << *stu.foo << " "; //<< a << '\n';


	  //bar = std::move(foo);                       // using std::move

	  std::cout << "foo: ";
	  if (foo) std::cout << *foo << '\n'; else std::cout << "empty\n";

	  std::cout << "bar: ";
	  if (bar) std::cout << *bar << '\n'; else std::cout << "empty\n";


}

