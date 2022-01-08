#ifndef MY_LIST_H_
#define MY_LIST_H_


#include "../../include/public.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    ElemType* elem;
    int length;
    int listsize;
}SqList;


class MyList {
public:
    MyList();
    Status ClearList();
    Status ListEmpty();
    int ListLength();
    Status GetElem(int i, ElemType& e);
    //Status LocateElem(ElemType e, compare());
    Status PriorElem(ElemType cur_e, ElemType& pre_e);
    Status NextElem(ElemType cur_e, ElemType& next_e);
    Status ListInsert(int i, ElemType e);
    Status ListDelete(int i, ElemType& e);
    //Status ListTraverse(visit());
    ~MyList(){};
private:
    SqList sq_list;
    
};    


#endif