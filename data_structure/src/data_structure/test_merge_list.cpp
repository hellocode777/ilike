#include "test_merge_list.h"

Status TestMergeList::MergeList(MyList la, MyList lb, MyList& targetList) {

    int i = 0;
    int j = 0;
    int k = 0;
    ElemType a, b;
    while (i < la.ListLength() && j < lb.ListLength()) {
        la.GetElem(i, a);
        lb.GetElem(j, b);
        if (a <= b)
        {
            targetList.ListInsert(k++, a);
            i++;
        }
        else
        {
            targetList.ListInsert(k++, b);
            j++;
        }
    }

    while (i < la.ListLength())
    {
        la.GetElem(i++, a);
        targetList.ListInsert(k++, a);
    }

    while (j < lb.ListLength())
    {
        lb.GetElem(j++, b);
        targetList.ListInsert(k++, b);
    }
    
    return OK;
}

void TestMergeList::test() {
    cout << __FUNCTION__ << endl;
    MyList list1;
    ElemType e = 0;
    list1.ListInsert(0, e);
    e = 1;
    list1.ListInsert(0, e);
    e = 2;
    list1.ListInsert(0, e);
    e = 3;
    list1.ListInsert(0, e);
    e = 4;
    list1.ListInsert(0, e);
    e = 5;
    list1.ListInsert(0, e);
    list1.Print();
    list1.Sort();
    list1.Print();

    MyList list2;
    e = 11;
    list2.ListInsert(0, e);
    e = 21;
    list2.ListInsert(0, e);
    e = 3;
    list2.ListInsert(0, e);
    e = 41;
    list2.ListInsert(0, e);
    e = 51;
    list2.ListInsert(0, e);
    e = 61;
    list2.ListInsert(0, e);
    list2.Print();
    list2.Sort();
    list2.Print();

    MyList targetList;
    MergeList(list1, list2, targetList);
    targetList.Print();
  
    cout << "----------end-------------" << endl << endl;
}
