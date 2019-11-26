#include <iostream>
#include <string>
#include "Public.h"
using namespace std;

class Student
{
public:
	void setName(std::string name);
	string getName();
  int getNum1();
  
	static int getNum();
	
	//static int m_iNum;
private:
	string m_strName;
	static int m_iNum;//static声明
                    //如果为静态成员变量，这需要在全局初始化这个static变量（int Student::m_iNum = 0;）
                    //若为private，访问的话需要接口int getNum1();或者static int getNum();注意两者的区别
};

void Student::setName(string name1)
{
	m_strName = name1;
	m_iNum++;//使用
}

string Student::getName()
{
	return m_strName;
}

int Student::getNum1()//成员函数调用
{
	return m_iNum;
}

int Student::getNum()//static函数调用
{
	return m_iNum;
}

int Student::m_iNum = 0;//定义

int StaticMain()
{
	Student stu;
	stu.setName("123");
	
	Student stu1;
	stu1.setName("456");
	
	Student stu2;
	stu2.setName("789");
	//cout << stu.getName() <<",num=" << Student::m_iNum <<endl;//当为public时，这是正确的
	cout<<",other=" << Student::getNum()<< endl;//当为private时
	cout<<",other=" << stu.getNum1()<< endl;//当为private时
		
	//cout << stu1.getName() <<",num=" << Student::m_iNum <<endl;
	cout<<",other=" << Student::getNum()<< endl;
	cout<<",other=" << stu.getNum1()<< endl;
		
	//cout << stu2.getName() <<",num=" << Student::m_iNum <<endl;
	cout<<",other=" << Student::getNum()<< endl;
	cout<<",other=" << stu.getNum1()<< endl;

	return 0;
}
