/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 * Created on 2018年4月30日, 上午7:39
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int ElemType;
const int MAXLEN = 100;
const int INCSIZE = 50;
struct SqList
{
    ElemType *elem;
    int length;
    int listsize;
    int incsize;
};
int IncSize(SqList &L);
void InitList_Sq(SqList &L, int maxlength = MAXLEN, int incsize = INCSIZE)
{
    L.elem = new ElemType[maxlength];
    L.length = 0;
    L.listsize = maxlength;
    L.incsize = incsize;
}
//提取操作
int GetElem_Sq(SqList L, int i, ElemType &e)
{
    if(i < 1 || i > L.length) 
        return 0;
    else
    {
        e = L.elem[i - 1];
        return 1;
    }
}
//修改操作
int SetElem_Sq(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length)
        return 0;
    L.elem[i - 1] = e;
    return 1;
}

//查找操作
int LocateElem_Sq(SqList L, ElemType e)
{
    int i = 0;
    while(i < L.length && L.elem[i - 1] == e)
    {
        i++;
        if (i < L.length)
            return i + 1;
        else
            return 0;
    }
}
//扩大存储空间操作
int IncSize(SqList &L)
{
    ElemType *a = new ElemType[L.listsize + L.incsize];
    for (int i = 0; i < L.length; i++)
    {
        a[i] = L.elem[i];
    }
    delete []L.elem;
    L.elem = a;
    L.length += L.incsize;
}
//插入操作
int InsertList_Sq(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return 0;
    if (L.listsize = L.length)
        IncSize(L);
    for (int k = L.length; k >= i - 1; k--)
    {
        L.elem[k + 1] = L.elem[k];
    }
    L.elem[i - 1] = e;
    L.length ++;
}

//删除操作
int DeleteList_Sq(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length + 1)
        return 0;
    e = L.elem[i - 1];
    for (int k = i - 1; k < L.length; k++)
    {
        L.elem[k] = L.elem[k + 1];
    }
    L.length --;
}
int main(int argc, char** argv) 
{
    SqList l;
    ElemType e;
    InitList_Sq(l, 0, 0);
    
    InsertList_Sq(l, 1, 1);
    InsertList_Sq(l, 2, 2);
    InsertList_Sq(l, 3, 3);
    InsertList_Sq(l, 2, 4);
//    SetElem_Sq(l, 4, 100);
    GetElem_Sq(l, 1, e);
    printf("e1 = %d\n", e);
    GetElem_Sq(l, 2, e);
    printf("e2 = %d\n", e);
    GetElem_Sq(l, 3, e);
    printf("e3 = %d\n", e);
    GetElem_Sq(l, 4, e);
    printf("e4 = %d\n", e);
    DeleteList_Sq(l, 2, e);
    GetElem_Sq(l, 1, e);
    printf("e1 = %d\n", e);
    GetElem_Sq(l, 2, e);
    printf("e2 = %d\n", e);
    GetElem_Sq(l, 3, e);
    printf("e3 = %d\n", e);
    GetElem_Sq(l, 4, e);
    printf("length = %d\n", l.length);
    return 0;
}

