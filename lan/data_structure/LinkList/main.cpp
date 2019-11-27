/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年5月1日, 上午7:33
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
using namespace std;

typedef struct LNode
{
    ElemType date;
    struct LNode* next;
}LNode, *LinkList;
/*
 * 
 */
Status InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return OVERFLOW;
    L->next = NULL;
    return OK;
}

Status DestroyList(LinkList &L)
{
    for(LinkList l = L; l->next == NULL; l = l->next)
    {
        free(l);
        
    }
//    printf("DestroyList\n");
    return OK;
}

Status ClearList(LinkList &L)
{
    for(LinkList l = L->next; l->next == NULL; l = l->next)
    {
        free(l);
        
    }
    L->next = NULL;
//    printf("ClearList\n");
    return OK;
}

Status ListEmpty(LinkList &L)
{
    if (L->next == NULL)
        return OK;
    else
        return FALSE;
}

Status ListLength(LinkList &L)
{
    int i = 0;
    LinkList l = L;
//    for(l; l == NULL; l = l->next)
//    {
//        i++;
////        printf("ListLength\n");
//    }
    while(l)
    {
        l = l->next;
        i++;
    }
//    printf("ListLength\n");
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    if (i < 0 || i > ListLength(L))
        return OVERFLOW;
    int nI;
    LinkList l = L;
    for(nI = 0; nI <= i; nI++)
    {
        l = l->next;
        e = l->date;
        
    }
//    printf("GetElem\n");
}

Status LocalElem(LinkList L, ElemType e)
{
    int i = 0;
    for(LinkList l = L->next; l->next == NULL; l = l->next)
    {
        i++;
        if (l->date == e)
            return i;
        
    }
//    printf("ListLength\n");
    return FALSE;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    for(LinkList l = L->next; (l->next == NULL)||(L->next->next == NULL); l = l->next)
    {
        if (l->next->date == cur_e)
        {
            pre_e = l->date;
            return OK;
        }
        
    }
//    printf("PriorElem\n");
    return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    for(LinkList l = L->next; l->next == NULL; l = l->next)
    {
        if (l->date == cur_e)
        {
            next_e = l->next->date;
            return OK;
        }
        
    }
//    printf("NextElem\n");
    return ERROR;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    if(i < 0 || i > (ListLength(L)))
        return OVERFLOW;
    LinkList linL = (LinkList)malloc(sizeof(LNode));
    linL->date = e;
    linL->next = NULL;
    
    int nI = 0;
    LinkList l = L;
//    for(LinkList l = L->next; l->next == NULL; l = l->next)
    while(l)
    {
        
        if (nI == i)
        {
            linL->next = l->next;
            l->next = linL;
            return OK;
        }
        l = l->next;
        nI++;
    }
//    printf("ListInsert\n");
    return ERROR;
}

Status ListDelete(LinkList L, int i, ElemType &e)
{
    if(i < 0 || i > (ListLength(L)))
    return OVERFLOW;

    int nI = 0;
    LinkList dele;
    LinkList l = L;
//    for(LinkList l = L->next; l->next == NULL; l = l->next)
    while(l)
    {
        
        if (nI == i)
        {
            e = l->next->date;
            dele = l->next;
            l->next = l->next->next;
            free(dele);
            return OK;
        }
        l = l->next;
        nI++;
    }
//    printf("ListInsert\n");
    return ERROR;
}

Status ListTraverse(LinkList L, void(*visit)(ElemType))
{
    LinkList l1 = L->next;
    while(l1)
    {
        (*visit)(l1->date);
        l1 = l1->next;
    }
}
void visit(ElemType e)
{
    printf("%d\n",e);
}
int main(int argc, char** argv) 
{
    LinkList l;
    ElemType e;
    InitList(l);
    ListInsert(l, 0, 0);
    GetElem(l, 0, e);
    printf("e0 = %d\n", e);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 4, 4);
    
    GetElem(l, 1, e);
    printf("e1 = %d\n", e);
    GetElem(l, 2, e);
    printf("e2 = %d\n", e);
    GetElem(l, 3, e);
    printf("e3 = %d\n", e);
    GetElem(l, 4, e);
    printf("e4 = %d\n", e);
    
    ListDelete(l, 4, e);
    printf("dete = %d\n", e);
    
    LinkList l1 = l->next;
    int nI = 0;
    while(l1)
    {
        printf("nI = %d, date = %d\n", nI, l1->date);
        nI++;
        l1 = l1->next;
    }
    
    ListTraverse(l,visit);
    DestroyList(l);
    return 0;
}

