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

void test::testSmartPtr()
{
    std::shared_ptr<int> intPtr = std::make_shared<int>(10);
    std::cout<< "inPtr=" << *intPtr << std::endl;
    int* intP = intPtr.get();
    //delete intP;
    std::cout<< "inPtr=" << *intPtr.get() << std::endl;
    std::cout<< "inPtr=" << *intPtr << std::endl;
}

//test = default
class Student1
{
public:
	Student1() = default;
	Student1(std::string name):m_name(name) {}
//private:
	std::string m_name;
};
void test::testDefault()
{
    std::cout<< "void test::testDefault()" << std::endl;

	Student1 stu("shuai");
	Student1 stu1(stu);
	// here will fail, we need add default below in class.


    std::cout<< "stu.m_name=" << stu1.m_name << std::endl;
}

constexpr int add(int i)
{
	return i * 9;

}

void test::testMyInline()
{
	MyInline myInline;
	myInline.myPrint();

	// test constexpr
	const int a = 10;
	constexpr int b = a;
	constexpr int c = b;
	int sum1 = add(a);
	constexpr int sum = add(a);
	int i = 10;
	// failed, because i is not constexpr
	//constexpr int sum1 = add(i);
}