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

#ifndef LINKLIST_H
#define LINKLIST_H
#include "../../include/public.h"
#include <stdarg.h>

typedef struct LNode
{
    ElemType date;
    struct LNode* next;
}LNode, *LinkList;

class CMyLinkList {
public:
	CMyLinkList();
	Status InitList();
	Status DestroyList();
	Status ClearList();
	Status ListEmpty();
	Status ListLength();
	Status GetElem(int i, ElemType &e);
	Status LocalElem(ElemType e);
	Status PriorElem(ElemType cur_e, ElemType &pre_e);
	Status NextElem(ElemType cur_e, ElemType &next_e);
	Status ListInsert(int i, ElemType e);
	Status ListDelete(int i, ElemType &e);
	Status ListTraverse(void(*visit)(ElemType));
	LinkList l;

};

#endif /* LINKLIST_H */
