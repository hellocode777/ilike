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

#include "LinkList.h"

CMyLinkList::CMyLinkList()
{

}

Status CMyLinkList::InitList()
{
    l = (LinkList)malloc(sizeof(LNode));
    if (!l)
        return OVERFLOW;
    l->next = NULL;
    return OK;
}

Status CMyLinkList::DestroyList()
{
    for(LinkList l1 = l; l1->next == NULL; l1 = l->next)
    {
        free(l1);

    }
//    printf("DestroyList\n");
    return OK;
}

Status CMyLinkList::ClearList()
{
    for(LinkList l1 = l->next; l1->next == NULL; l1 = l1->next)
    {
        free(l1);

    }
    l->next = NULL;
//    printf("ClearList\n");
    return OK;
}

Status CMyLinkList::ListEmpty()
{
    if (l->next == NULL)
        return OK;
    else
        return FALSE;
}

Status CMyLinkList::ListLength()
{
    int i = 0;
    LinkList l1 = l;
//    for(l; l == NULL; l = l->next)
//    {
//        i++;
////        printf("ListLength\n");
//    }
    while(l1)
    {
        l1 = l1->next;
        i++;
    }
//    printf("ListLength\n");
    return i;
}

Status CMyLinkList::GetElem(int i, ElemType &e)
{
    if (i < 0 || i > CMyLinkList::ListLength())
        return OVERFLOW;
    int nI;
    LinkList l1 = l;
    for(nI = 0; nI <= i; nI++)
    {
        l1 = l1->next;
        e = l1->date;

    }
//    printf("GetElem\n");
}

Status CMyLinkList::LocalElem(ElemType e)
{
    int i = 0;
    for(LinkList l1 = l->next; l1->next == NULL; l1 = l1->next)
    {
        i++;
        if (l1->date == e)
            return i;

    }
//    printf("ListLength\n");
    return FALSE;
}

Status CMyLinkList::PriorElem(ElemType cur_e, ElemType &pre_e)
{
    for(LinkList l1 = l->next; (l1->next == NULL)||(l->next->next == NULL); l1 = l1->next)
    {
        if (l1->next->date == cur_e)
        {
            pre_e = l1->date;
            return OK;
        }

    }
//    printf("PriorElem\n");
    return ERROR;
}

Status CMyLinkList::NextElem(ElemType cur_e, ElemType &next_e)
{
    for(LinkList l1 = l->next; l1->next == NULL; l1 = l1->next)
    {
        if (l1->date == cur_e)
        {
            next_e = l1->next->date;
            return OK;
        }

    }
//    printf("NextElem\n");
    return ERROR;
}

Status CMyLinkList::ListInsert(int i, ElemType e)
{
    if(i < 0 || i > (CMyLinkList::ListLength()))
        return OVERFLOW;
    LinkList linL = (LinkList)malloc(sizeof(LNode));
    linL->date = e;
    linL->next = NULL;

    int nI = 0;
    LinkList l1 = l;
//    for(LinkList l = L->next; l->next == NULL; l = l->next)
    while(l1)
    {

        if (nI == i)
        {
            linL->next = l1->next;
            l1->next = linL;
            return OK;
        }
        l1 = l1->next;
        nI++;
    }
//    printf("ListInsert\n");
    return ERROR;
}

Status CMyLinkList::ListDelete(int i, ElemType &e)
{
    if(i < 0 || i > (CMyLinkList::ListLength()))
    return OVERFLOW;

    int nI = 0;
    LinkList dele;
    LinkList l1 = l;
//    for(LinkList l = L->next; l->next == NULL; l = l->next)
    while(l1)
    {

        if (nI == i)
        {
            e = l1->next->date;
            dele = l1->next;
            l1->next = l1->next->next;
            free(dele);
            return OK;
        }
        l1 = l1->next;
        nI++;
    }
//    printf("ListInsert\n");
    return ERROR;
}

Status CMyLinkList::ListTraverse(void(*visit)(ElemType))
{
    LinkList l1 = l->next;
    while(l1)
    {
        (*visit)(l1->date);
        l1 = l1->next;
    }
}
