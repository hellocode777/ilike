/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年4月29日, 下午10:16
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int ElemType;
typedef ElemType *Triplet;
/*
 * 
 */
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
Status DestroyTriplet(Triplet &T);
Status Get(Triplet T, int i, ElemType &e);
Status Put(Triplet &T, int i, ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
    T = (ElemType *)malloc(3 * sizeof(ElemType));
    if (!T)
        exit(OVERFLOW);
    T[0] = v1;
    T[1] = v2;
    T[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet &T)
{
    free(T);
    T = NULL;
    return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
    if (i < 1 || i > 3)
        return ERROR;
    e = T[i - 1];
    return OK;
}

Status Put(Triplet &T, int i, ElemType e)
{
    if (i < 1 || i > 3)
        return ERROR;
    T[i - 1] = e;
    return OK;
}

Status IsAscending(Triplet T)
{
    return (T[0] <= T[1] && T[1] <= T[2]);
}

Status IsDescending(Triplet T)
{
    return (T[0] >= T[1] && T[1] >= T[2]);
}

Status Max(Triplet T, ElemType &e)
{
    e = (T[0] >= T[1])?((T[0] >= T[2]) ? T[0] : T[2]):((T[1] >= T[2]) ? T[1] : T[2]);
    return OK;
}

Status Min(Triplet T, ElemType &e)
{
    e = (T[0] <= T[1])?((T[0] <= T[2]) ? T[0] : T[2]):((T[1] <= T[2]) ? T[1] : T[2]);
    return OK;
}


int main(int argc, char** argv) 
{
    Triplet t;
    ElemType e;
    Status i;
    if (InitTriplet(t, 1, 2, 3) == OK)
    {
        i = Put(t, 3, 100);
        
    }
    i = Get(t, 3, e);
    i = Min(t, e);
    i = DestroyTriplet(t);
    printf("e = %d\n", e);
    
    return 0;
}

