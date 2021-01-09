/*
 * test1.h
 *
 *  Created on: 2020-2-23
 *      Author: shuai
 */

#ifndef TEST1_H_
#define TEST1_H_

//#define NDEBUG
//can not write in .cpp, don`t know why
#include <iostream>


class MyInline{
public:
	inline void myPrint();

private:
	std::string m_name;

};

inline void MyInline::myPrint()
{
	std::cout << "myPring" << std::endl;
}

class test {
public:
	test();
	virtual ~test();

	void test1();
	void test2();
	void test3();
	void testSmartPtr();

	void testDefault();

	void testMyInline();
};

#endif /* TEST1_H_ */
