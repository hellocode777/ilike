#include "Public.h"
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年9月10日, 下午7:13
 * 虚函数:是在基类中使用关键字 virtual 声明的函数。
 * 在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
 * 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
 *
 *
 *
 *
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 *
 */
class Shape
{
public:
	 Shape(int length, int wide);
    void SetLength(int length);
    void SetWide(int wide);
    int GetLength();
    int GetWide();
    virtual void Display();//此函数为虚函数，那什么时候要用到纯虚函数？您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
//    void Display();
    //纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。
    //在基类中实现纯虚函数的方法是在函数原型后加“=0”
    //引入纯虚函数的原因：
    //1、为了方便使用多态特性，我们常常需要在基类中定义虚拟函数。
    //2、在很多情况下，基类本身生成对象是不合情理的。例如，动物作为一个基类可以派生出老虎、孔雀等子类，但动物本身生成对象明显不合常理。
    //
    // 抽象类只能作为基类来使用，其纯虚函数的实现由派生类给出。如果派生类中没有重新定义纯虚函数，而只是继承基类的纯虚函数，
    //则这个派生类仍然还是一个抽象类。如果派生类中给出了基类纯虚函数的实现，则该派生类就不再是抽象类了，它是一个可以建立对象的具体的类。
    //抽象类是不能定义对象的。
    //
    //在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。

    virtual ~Shape();
//    ~Shape();
private:
    int c_iLength;
    int c_iWide;
};

class Rectangle:public Shape
{
public:
    Rectangle(int length, int wide, char *name):Shape(length, wide)
    {
        memset(c_strName, 0, sizeof(c_strName));
        memcpy(this->c_strName, name, strlen(name));
        printf("这是Rectangled的构造函数！\n");
    }
    void SetName(char *name);
    char *GetName();
    void Display();
    ~Rectangle();
private:
    char c_strName[10];
};

class Triangle:public Shape
{
public:
    Triangle(int length, int wide, char *name):Shape(length, wide)
    {
        memset(c_strName, 0, sizeof(c_strName));
        memcpy(this->c_strName, name, strlen(name));
        printf("这是Triangle的构造函数！\n");
    }
    void SetName(char *name);
    char *GetName();
    void Display();
    ~Triangle();
private:
    char c_strName[10];
};

void Triangle::SetName(char* name)
{
    memset(c_strName, 0, sizeof(c_strName));
    memcpy(this->c_strName, name, strlen(name));
}

char* Triangle::GetName()
{
    return this->c_strName;
}

void Triangle::Display()
{
    printf("名字：%s, 面积：%d\n", c_strName, GetLength() * GetWide()/2);
}

Triangle::~Triangle()
{
    printf("这是Triangle的析构函数！\n");
}

void Rectangle::SetName(char* name)
{
    memset(c_strName, 0, sizeof(c_strName));
    memcpy(this->c_strName, name, strlen(name));
}

char* Rectangle::GetName()
{
    return this->c_strName;
}

void Rectangle::Display()
{
    printf("名字：%s, 面积：%d\n", c_strName, GetLength() * GetWide());
}

Rectangle::~Rectangle()
{
    printf("这是Rectangle的析构函数！\n");
}

Shape::Shape(int length, int wide)
{
    c_iLength = length;
    c_iWide = wide;
    printf("这是Shape的构造函数！\n");

}

void Shape::SetLength(int length)
{
    this->c_iLength = length;
}

void Shape::SetWide(int wide)
{
    this->c_iWide = wide;
}

int Shape::GetLength()
{
    return this->c_iLength;
}

int Shape::GetWide()
{
    return this->c_iWide;
}

void Shape::Display()
{
    printf("这是基类的Display函数！\n");
}


Shape::~Shape()
{
    printf("这是Shape的析构函数！\n");
}

int
Polymorphism_main()
{
//    Shape *sha;
//    Rectangle rec(5, 5, (char*)"正方形");
//    Triangle tri(3, 4, (char*)"三角形");
//
//    sha = &rec;
//    sha->Display();//这里执行的不是派生类的display函数，想要让它执行派生类的Display函数应该怎么做？
//                   //只需要在基类的Disney函数前加上virtual关键字即可。为什么会这样？
//    //1、在没有加virtual之前：调用函数 display() 被编译器设置为基类中的版本，这就是所谓的静态多态，或静态链接 - 函数调用在程序执行前就准备好了。
//    //有时候这也被称为早绑定，因为 display() 函数在程序编译期间就已经设置好了。
//    //2、在加入virtual之后：编译器看的是指针的内容，而不是它的类型。
//    //因此，由于 tri 和 rec 类的对象的地址存储在 *shape 中，所以会调用各自的 display() 函数。
//    sha = &tri;
//    sha->Display();
    printf("----------------------------------\n");
    Shape *sha1 = new Triangle(6, 8, (char*)"三角形大哥");
    sha1->Display();
    delete sha1;
    //若基类的析构函数没有加virtual的话，派生类的析构函数不会被执行，为什么？
    //若在基类的析构函数前加上virtual的话，先执行派生类的析构函数，再执行基类的析构函数。

    return 0;
}
