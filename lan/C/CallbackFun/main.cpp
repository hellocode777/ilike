/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年9月7日, 下午9:47
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

/*
 * 
 */
void SetBuffer(int *buff, int size, int (*fun)(void))
{
    if(NULL == fun)
        return;
    int i = 0;
    srand((int)time(0));
    for(i; i < size; i++)
    {
        buff[i] = fun();
    }
}

//获得随机数
int GetRand()
{

//    return 1+(int)(10.0*rand()/(RAND_MAX+1.0));//产生1到10的随机数
    return 1+rand()%10;//同样产生1到10的随机数
}
int
main(int argc, char** argv)
{
    int m_iBuff[10];
    memset(m_iBuff, 0, 10);
    SetBuffer(m_iBuff, 10, NULL);//1、若想调用那个函数，就可以把那个函数名传进去，2、若不想调用直接传入NULL、注意判断
    for(int i = 0; i < 10; i++)
    {
        printf("buff[%d] = %d\n", i, m_iBuff[i]);
    }
    return 0;
}