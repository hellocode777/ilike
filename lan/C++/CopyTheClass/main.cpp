/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年9月9日, 下午8:28
 * 
 * 什么情况下会用到拷贝函数？
 *1、通过使用另一个同类型的对象来初始化新创建的对象。
 *2、复制对象把它作为参数传递给函数。
 *3、复制对象，并从函数返回这个对象。
 * 
 * 注意sizeof()和strlen()的区别
 * int num[10];sizeof(num) = 40;
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 
 */
class Student
{
public:
    Student(int age, char *name);
    ~Student();
    Student(const Student &stu);
    void SetAge(int age);
    void SetName(char *name);
    void Display() const;
private:
    int c_iAge;
//    char c_stName[10];
    char *c_stName;//注意：当类成员变量为指针时，在构造函数和拷贝构造函数内一定要为此成员变量手动分配空间new，然后在析构函数一定要手动释放此空间delete。
    /*若你的类里面有一个指针，当你在的构造函数为这个指针手动分配空间（new）的话，只需要在析构函数delete这个成员变量指针就可以了。
     * 若你是浅拷贝，没有在拷贝构造函数内对这个成员变量指针分配空间的话，编译不会报错，执行也会报错。
     * 成员变量为指针的话最好用深拷贝，在拷贝构造函数同样也要为这个指针手动申请空间（深拷贝）。
     */
};

Student::Student(int age, char* name)
{
    c_iAge = age;
    c_stName = new char[10];
    memset(c_stName, '\0', sizeof(this->c_stName));
    memcpy(c_stName, name, strlen(name));
}

void Student::SetAge(int age)
{
    this->c_iAge = age;
}

void Student::SetName(char* name)
{
    memset(this->c_stName, '\0', sizeof(this->c_stName));
    memcpy(this->c_stName, name, strlen(name));
}

Student::~Student()
{
    delete c_stName;
    printf("This is ~Studnet!\n");
}

Student::Student(const Student& stu)
{
    //这个很重要,为什么可以直接用c_iAge = stu.c_iAge，因为此函数有一个隐含的这个对象this指针,
    //也可以用this->c_iAge = stu.c_iAge
    this->c_iAge = stu.c_iAge;
    this->c_stName = new char[10];
    memset(this->c_stName, '\0', sizeof(this->c_stName));
    memcpy(this->c_stName, stu.c_stName, strlen(stu.c_stName));
    printf("这是拷贝构造函数!\n");
//    memcpy(this->c_stName, stu.c_stName, 8);
//    c_iAge = stu.c_iAge;
//    memcpy(c_stName, stu.c_stName, strlen(stu.c_stName));
    
}
void Student::Display() const
{
    printf("name:%s,age:%d\n", c_stName, c_iAge);
}

void NoClassDisplay(const Student stu) //这里不能用const，为什么？
                                        //const对象只能调用const成员函数，而const的成员函数不能改变对象的成员变量。
//void NoClassDisplay(Student &stu) //思考此处有没有&的区别，1、没有&的情况不会改变传入之前对象的成员变量的值，
                                    //并且会复制一个对象到stu；
                                    //2、有&，同时也会改变传入之前对象的成员变量的值，同时不会复制对象到stu，只是两个对象共用一个地址。
//void NoClassDisplay(Student stu)
{
    stu.Display();
//    stu.c_iAge = stu.c_iAge;//在这里不能使用这样的方法改变其成员变量，因为其成员变量为私有的
                              //若想在此改变需要用到公共接口。
//    stu.SetAge(50);//通过这种方式就可以对其成员变量进行改变。
    stu.Display();
}

//验证3、复制对象，并从函数返回这个对象。
Student ReturnClass(Student stu)
{
    stu.SetAge(100);
    return stu;
}

int
main(int argc, char** argv)
{
    char m_stName[] = "zhangsan";
    Student m_stu(25, m_stName);
    m_stu.Display();
    
    Student m_stu1 = m_stu;//1、通过使用另一个同类型的对象来初始化新创建的对象。
    m_stu1.Display();
    
    m_stu1.SetName((char*)"nihao");
    m_stu.Display();
    m_stu1.Display();
    
    /*
     *2、复制对象把它作为参数传递给函数。
     */
    NoClassDisplay(m_stu1);  //此函数传的参数为一个对象，当参数为一个对象是要用到拷贝函数。
    m_stu1.Display();
    
    Student m_stu2 = ReturnClass(m_stu1);
    m_stu2.Display();
    return 0;
}

