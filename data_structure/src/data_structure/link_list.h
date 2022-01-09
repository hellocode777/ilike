#ifndef LINK_LIST_H_
#define LINK_LIST_H_


#include "../../include/public.h"

typedef struct Node{
    struct Node* next;
    ElemType value;
}Node;

class LinkList {
public:
    LinkList();
    Status ClearList();
    Status ListEmpty();
    int ListLength();
    Status GetElem(int i, ElemType& e);
    //Status LocateElem(ElemType e, compare());
    Status Sort();
    Status FindElem(int& i, ElemType e);
    Status PriorElem(ElemType cur_e, ElemType& pre_e);
    Status NextElem(ElemType cur_e, ElemType& next_e);
    Status ListInsert(int i, ElemType e);
    Status ListDelete(int i, ElemType& e);
    void Print();
    //SqList GetList();
    //Status ListTraverse(visit());
    ~LinkList(){}
private:
    Node* header;
    int length;
};


class TestLinkList {
public:
    void test();
};

#endif
