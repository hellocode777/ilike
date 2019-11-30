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
#include "LinkList/LinkList.h"
using namespace std;
void visit(ElemType e)
{
    printf("%d\n",e);
}
int main(int argc, char** argv)
{
    ElemType e;
    CMyLinkList myList;
    myList.InitList();
    myList.ListInsert(0, 0);
    myList.GetElem(0, e);
    printf("e0 = %d\n", e);
    myList.ListInsert(1, 1);
    myList.ListInsert(2, 2);
    myList.ListInsert(3, 3);
    myList.ListInsert(4, 4);

    myList.GetElem(1, e);
    printf("e1 = %d\n", e);
    myList.GetElem(2, e);
    printf("e2 = %d\n", e);
    myList.GetElem(3, e);
    printf("e3 = %d\n", e);
    myList.GetElem(4, e);
    printf("e4 = %d\n", e);

    myList.ListDelete(4, e);
    printf("dete = %d\n", e);

//    LinkList l1 = (lmyList.l)->next;
//    int nI = 0;
//    while(l1)
//    {
//        printf("nI = %d, date = %d\n", nI, l1->date);
//        nI++;
//        l1 = l1->next;
//    }
//
//    ListTraverse(l,visit);
//    DestroyList(l);
    return 0;
}

