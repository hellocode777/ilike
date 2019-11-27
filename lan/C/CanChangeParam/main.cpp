/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年9月8日, 下午8:21
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;
/*
 *可变参数最好是用C++的多态性来实现可变参数的实现。
 * 
 * /
/*
 * 
 */
//求传入参数的平均数
double Fun(int num,...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
       sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    printf("%f, %d\n",sum, num);
    return sum/num;
}
//打印出传入的可变参数
void Fun1(char *s, char *st,...)
{
    char *ppt = (char*)&s;
    printf("%p %p %p %p\n", ppt, &s, &st, ppt + 8);
    printf("%s\n", *(char**)(ppt+4));
    printf("%d\n", *(int*)(ppt + 4 + 4));
    return ;
}

int
main(int argc, char** argv)
{
    printf("m_dA = %f\n", Fun(3, 2, 4545, 3));//是求2,4545，和3这三个数的平均数；第一个参数为参数的个数3.
    printf("m_dB = %f\n", Fun(2, 3,1000));//是求3和1000这两个数的平均数；第一个参数2表示参数的个数2.
    
//    Fun1(3, 2, "hello", 3);//待验证
    return 0;
}




