/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年5月2日, 下午10:04
 */

#include <cstdlib>
#include "array.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    int dim = 2, bound1 = 3, bound2 = 4;
    CMyArray cMyarray(dim, 3, 4);
    ElemType e;
    ElemType *p = cMyarray.m_tArray.bounds;
    int i, j;
    for (i = 0; i < dim; i++)
        printf("一维%d ", *(p + i));
    p = cMyarray.m_tArray.constants;
    for (i = 0; i < dim; i++)
        printf("二维%d ", *(p + i));
    
    for(i=0; i<bound1; i++)
    {
        for(j=0; j<bound2; j++)
        {
                cMyarray.Assign(i*100+j*10,i,j); /* 将i*100+j*10+k赋值给A[i][j][k] */
                cMyarray.Value(e, i,j); /* 将A[i][j][k]的值赋给e */
                printf("A[%d][%d]=%2d ",i, j, e); /* 输出A[i][j][k] */
        }
        printf("\n");
    }
    return 0;
}

