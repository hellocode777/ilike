#include "Public.h"
#include <vector>

///////////////////////////////////////////////////////////////////////////
//[1]函数指针

//int (*Addp)(int, int);//声明一个函数指针
typedef int (*Addp)(int, int);//定义一个数据类型为函数指针的数据类型

int Add(int a, int b)
{
	return a + b;
}

int Subtraction(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}

void Fun1()
{
	Addp p = Add;
	std::cout << "Add a + b = " << p(2, 3) << std::endl;
	vector<Addp> m_VAdd;
	m_VAdd.push_back(Add);
	m_VAdd.push_back(Subtraction);
	m_VAdd.push_back(multiplication);
	m_VAdd.push_back(division);

	vector<Addp>::iterator iter = m_VAdd.begin();
	for (; iter != m_VAdd.end(); iter++)
	{
		cout << (*iter)(4, 5) << endl;
	}


	return;
}

///////////////////////////////////////////////////////////////////////////




int C__PrimerMain()
{
	Fun1();
	return 0;
}
