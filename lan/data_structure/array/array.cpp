/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array.cpp
 * Author: Administrator
 * 
 * Created on 2018年5月2日, 下午10:05
 */

#include <math.h>

#include "array.h"

CMyArray::CMyArray() 
{

}

CMyArray::CMyArray(int dim, ...) 
{
    if(dim < 1 || dim > MAX_ARRAY_DIM)
        exit(OVERFLOW1);
    m_tArray.dim = dim;
    m_tArray.bounds = new int[dim];
    if (!m_tArray.bounds) exit(OVERFLOW1);
    int nElemtotal = 1;
    int i;
    va_list ap;
    va_start(ap, dim);
    for(i = 0; i < dim; ++i)
    {
        m_tArray.bounds[i] = va_arg(ap, int);

        nElemtotal *= m_tArray.bounds[i];
    }
    va_end(ap);
    m_tArray.base = new int[nElemtotal];
    if (!m_tArray.base)
        exit(OVERFLOW1);
    
    m_tArray.constants = new int[dim];
    if (!m_tArray.constants)
        exit(OVERFLOW1);
    m_tArray.constants[dim - 1] = 1;
    for (i = dim - 2; i >= 0; --i )
    {
        m_tArray.constants[i] = m_tArray.bounds[i + 1] * m_tArray.constants[i + 1];
    }
}

Status CMyArray::DestroyArray()
{
    if (!m_tArray.base) return ERROR;
    delete m_tArray.base; m_tArray.base = NULL;
    if (!m_tArray.bounds) return ERROR;
    delete m_tArray.bounds; m_tArray.bounds = NULL;
    if (!m_tArray.constants) return ERROR;
    delete m_tArray.constants; m_tArray.constants = NULL;
}

Status CMyArray::Locate(va_list ap, int& off)
{
    off = 0;
    int i, ind;
    for (i = 0; i < m_tArray.dim; ++i)
    {
        ind = va_arg(ap, int);
        if (ind < 0 || ind >= m_tArray.bounds[i]) return OVERFLOW1;
        off += m_tArray.constants[i] * ind;
    }
    return OK;
}


Status CMyArray::Value(ElemType& e, ...)
{
    va_list ap;
    va_start(ap, e);
    int result, off;
    if (result = Locate(ap, off) <= 0) return result;
//    e *= (m_tArray.base + off);
    return OK;
}

Status CMyArray::Assign(ElemType e, ...)
{
    va_list ap;
    va_start(ap, e);
    int result, off;
    if (result = Locate(ap, off) <= 0) return result;
    e = *(m_tArray.base + off) ;
    return OK;
}
CMyArray::CMyArray(const CMyArray& orig) {
}

CMyArray::~CMyArray() {
}
