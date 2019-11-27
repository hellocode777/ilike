/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年5月2日, 上午9:49
 */

#include <cstdlib>
using namespace std;
#include "queue.h"

int main(int argc, char** argv) 
{
    CMyQueue qu;
    ElemType e;

    qu.Push(9);
    qu.Push(1);
    qu.Push(2);
    qu.Push(3);
    qu.GetFrond(e);
    printf("%d\n",e);
    qu.GetFrond(e);
    printf("%d\n",e);
    qu.GetFrond(e);
    printf("%d\n",e);
    qu.GetFrond(e);
    printf("%d\n",e);
    qu.GetFrond(e);
    printf("%d\n",e);
    return 0;
}

