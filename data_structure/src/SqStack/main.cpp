/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年5月1日, 下午2:36
 */


#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, ElemType &e);
Status Push(SqStack &S, ElemType e);
Status Pop(SqStack &S, ElemType &e);
Status StackTraverse(SqStack S, Status(*visit)(ElemType e));
Status visit(ElemType e);
/*
 * 
 */
Status InitStack(SqStack &S)
{
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S)
{
    
}

Status GetTop(SqStack S, ElemType &e)
{
    if (S.base == S.top)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, ElemType e)
{
    if (S.top - S.base >= S.stacksize )
    {
        S.base = (ElemType *)malloc((S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
        
    }
//    *S.top++ = e;
    *S.top = e;
    S.top += 1;
    return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
    if(S.base == S.top)
        return ERROR;
    e = *(S.top - 1);
    S.top -= 1;
    return OK;
}

Status visit(ElemType e)
{
    printf("%d\n", e);
}

Status StackTraverse(SqStack S, Status(*visit)(ElemType e))
{
    if (S.base == S.top)
        return ERROR;
    for (; S.base < S.top; S.base ++)
    {
        (*visit)(*(S.base));
    }
}

int main(int argc, char** argv) 
{

    SqStack s;
    
    ElemType e;
    e.
    InitStack(s);
    Push(s, 0);
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    GetTop(s, e);
    printf("栈顶e = %d\n", e);
    Pop(s, e);
    printf("被删除的栈顶e = %d\n", e);
    GetTop(s, e);
    printf("删除后的栈顶e = %d\n", e);
    StackTraverse(s,visit);
    return 0;
}

