/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年9月10日, 下午12:46
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 思考：什么情况下派生类可以访问基类的？
 * 1、派生类可以访问基类中所有的非私有成员
 * 因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。
 * 访问	       public	  protected	private
 * 同一个类	yes	  yes	        yes
 * 派生类	yes	  yes	        no
 * 外部的类	yes	  no	        no
 * 
 * 一个派生类继承了所有的基类方法，但下列情况除外：
 * 基类的构造函数、析构函数和拷贝构造函数。派生类的构造函数和拷贝构造函数一样写法。
 * 基类的重载运算符。
 * 基类的友元函数。
 * 
 */
//基类
class Shape
{
public:
    Shape(int length, int wide);
    Shape(const Shape &sh);
    ~Shape();
    void SetLength(int length);
    void SetWide(int wide);
    int GetLength();
    int GetWide();
private:
    int c_iLength;
    int c_iWide;
};

class ShapeColour
{
public:
    ShapeColour(char *colour);
    ShapeColour(const ShapeColour &sh);
    ~ShapeColour();
    void SetColour(char *colour);
    char *GetColour();
private:
    char c_strColour[10];
};

//派生类
class Rectangle:public Shape, public ShapeColour
{
public:
    //派生类的构造函数不能在类外进行定义，只能在类里面进行定义。
    //派生类的构造函数的执行顺序：
    //1、先执行基类的构造函数，
    //多个基类的话是按基类继承的顺序来继承的（class Rectangle:public Shape, public ShapeColour）,
    //先执行Shape的构造函数，再执行ShapeColour的构造函数。
    //------------下面是运行结果
    //这是基类Shape的构造函数！
    //这是基类ShapeColour的构造函数！
    //这是基类Rectangle的构造函数！
    //名字：zhangsan, 面积为:30, 颜色：red
    //
    //那么析构函数的执行顺序是怎样的？
    //正好的构造函数的执行顺序相反。
    //这是基类Rectangle的析构函数！
    //这是基类ShapeColour的析构函数！
    //这是基类Shape的析构函数！
    //
    //
    Rectangle(char *colour, int length, int wide, char *name):ShapeColour(colour),Shape(length, wide)
    {
        memset(c_strShapeName, 0, sizeof(c_strShapeName));
        memcpy(c_strShapeName, name, strlen(name));
        printf("这是基类Rectangle的构造函数！\n");
    }
    ~Rectangle();
    Rectangle(const Rectangle &rec):Shape(rec),ShapeColour(rec)
    {
        memset(c_strShapeName, 0, sizeof(c_strShapeName));
        memcpy(this->c_strShapeName, rec.c_strShapeName, strlen(rec.c_strShapeName));
        printf("这是基类Rectangle的拷贝构造函数！\n");
    }
    void DisplayArea();
    void SetShapeName(char *name);
    char *GetShapeName();
private:
    char c_strShapeName[10];
};

//=====================================================Shape基类的成员函数
Shape::Shape(int length, int wide)
{
    c_iLength = length;
    c_iWide = wide;
    printf("这是基类Shape的构造函数！\n");
}
//Shape的拷贝构造函数
Shape::Shape(const Shape& sh)
{
    this->c_iLength = sh.c_iLength;
    this->c_iWide = sh.c_iWide;
    printf("这是基类Shape的拷贝构造函数！\n");
}

void Shape::SetLength(int length)
{
    c_iLength = length;
}

void Shape::SetWide(int wide)
{
    c_iWide = wide;
}

int Shape::GetLength()
{
    return c_iLength;
}

int Shape::GetWide()
{
    return c_iWide;
}

//析构函数
Shape::~Shape()
{
    printf("这是基类Shape的析构函数！\n");
}

//========================================================基类ShapeColour的成员函数
ShapeColour::ShapeColour(char* colour)
{
    memset(c_strColour, 0, sizeof(c_strColour));
    memcpy(c_strColour, colour, strlen(colour));
    printf("这是基类ShapeColour的构造函数！\n");
}

//ShapeColour的拷贝构造函数
ShapeColour::ShapeColour(const ShapeColour& sh)
{
    memset(c_strColour, 0, sizeof(c_strColour));
    memcpy(this->c_strColour, sh.c_strColour, strlen(sh.c_strColour));
    printf("这是基类ShapeColour的拷贝构造函数！\n");
}

void ShapeColour::SetColour(char* colour)
{
    memset(c_strColour, 0, sizeof(c_strColour));
    memcpy(c_strColour, colour, strlen(colour));
}

char *ShapeColour::GetColour()
{
    return c_strColour;
}

ShapeColour::~ShapeColour()
{
    printf("这是基类ShapeColour的析构函数！\n");
}

//=====================================================派生类Rectangle的成员函数
void Rectangle::SetShapeName(char* name)
{
    memset(c_strShapeName, 0, sizeof(c_strShapeName));
    memcpy(c_strShapeName, name, strlen(name));
}

char *Rectangle::GetShapeName()
{
    return c_strShapeName;
}

void Rectangle::DisplayArea()
{
//    printf("面积为:%d\n", c_iLength * c_iWide);//在这里不能直接访问基类的私有成员；需要提供公共接口来访问。
    printf("名字：%s, 面积为:%d, 颜色：%s\n", GetShapeName(), GetLength() * GetWide(), GetColour());
}

Rectangle::~Rectangle()
{
    printf("这是基类Rectangle的析构函数！\n");
}

//===================================================主函数
int
main(int argc, char** argv)
{
//    Rectangle rec((char*)"red",5, 6, (char*)"zhangsan");
//    rec.SetLength(10);
//    rec.SetWide(10);
//    rec.SetColour((char*)"yellow");
//    rec.DisplayArea();
//    printf("===================\n");
//    
//    Rectangle rec1 = rec;
//    rec1.DisplayArea();
    
    
    //以下是new的用法
    //析构函数的定义:析构函数也是特殊的类成员函数，它没有返回类型，没有参数，不能随意调用，
    //也没有重载，只有在类对象的生命期结束的时候，由系统自动调用。
    //什么时候会调用析构函数？
    //1、动态申请空间存放对象，若是用new一个对象，当delete这个对象指针的时候会调用析构函数；
    //2、在程序结束时一一调用。
    //思考：大型程序一般不会结束，如果不是用new创建无数个对象的话，是不是很容易造成程序崩溃？
    Rectangle *rec = new Rectangle((char*)"red",5, 6, (char*)"zhangsan");
    rec->DisplayArea();
    delete rec;
    return 0;
}

