/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array.h
 * Author: Administrator
 *
 * Created on 2018年5月2日, 下午10:05
 */

#ifndef ARRAY_H
#define ARRAY_H
#include "../../include/public.h"
#include <stdarg.h>
#define MAX_ARRAY_DIM 8
typedef struct ARRAY
{
    ElemType *base;//数组元素基址
    int dim;//数组维数
    int *bounds;//数组维数基址
    int *constants;//数组映像函数常数基址
}T_ARRAY;


class CMyArray {
public:
    CMyArray();
    CMyArray(int dim, ...);
    CMyArray(const CMyArray& orig);
    virtual ~CMyArray();
//    Status InitArray(T_ARRAY &A, int dim, ...);
    Status DestroyArray();
    Status Locate(va_list ap, int &off);
    Status Value(ElemType &e, ...);
    Status Assign(ElemType e, ...);
//private:
    T_ARRAY m_tArray;
};

#endif /* ARRAY_H */

