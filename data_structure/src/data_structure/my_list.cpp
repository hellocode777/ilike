#include "my_list.h"
#include <algorithm>

MyList::MyList() {
}


Status MyList::ClearList() {
    sq_list.clear();
    return OK;
}

Status MyList::ListEmpty() {
    return sq_list.empty();
}

int MyList::ListLength() {
    return sq_list.size();
}

Status MyList::GetElem(int i, ElemType &e) {
    if (i < 0 || i > ListLength() - 1)
        return FALSE;
    e = sq_list[i];
    return OK;
}

Status MyList::PriorElem(ElemType cur_e, ElemType &pre_e) {
    if (ListEmpty())
        return FALSE;
  
    ElemType e;
    for (int i = 0; i < ListLength(); i++)
    {
        GetElem(i, e);
        if (cur_e == e)
        {
            if (i == 0)
            {
                return FALSE;
            }
            else
            {
                GetElem(i - 1, e);
                pre_e = e;
                return OK;
            }
        }
    }
    return FALSE;
}

Status MyList::NextElem(ElemType cur_e, ElemType &next_e) {
    if (ListEmpty())
        return FALSE;
  
    ElemType e;
    for (int i = 0; i < ListLength(); i++)
    {
        GetElem(i, e);
        if (cur_e == e)
        {
            if (i == ListLength() - 1)
            {
                return FALSE;
            }
            else
            {
                GetElem(i + 1, e);
                next_e = e;
                return OK;
            }
        }
    }
    return FALSE;
}

// 需要思考
Status MyList::ListInsert(int i, ElemType e) {
    if ((i < 0 || i > ListLength()))
        return FALSE;

    if (ListLength() == i)
    {
        sq_list.push_back(e);
        return OK;
    }
    int j = ListLength() - 1;
    sq_list.push_back(0);
    while (true)
    {
        sq_list[j + 1] = sq_list[j];
        if (j == i)
        {
            sq_list[j] = e;
            break;
        }
        j--;
    }
    return OK;
}

Status MyList::FindElem(int &i, ElemType e) {

    for (int j = 0; j < ListLength(); j++)
    {
        if (e == sq_list[j])
        {
            i = j;
            return OK;
        }

    }

    return FALSE;
}

void MyList::Print() {
  
    for (int i = 0; i < ListLength(); i++)
    {
        cout << sq_list[i];
        if (i != ListLength() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}

Status MyList::Sort() {
    sort(sq_list.begin(), sq_list.end());
    return OK;
}

SqList MyList::GetList() {
    return sq_list;
}

MyList::~MyList() {
}

void TestList::test_my_list() {
    cout << __FUNCTION__ << endl;
    MyList myList;
    myList.ListInsert(0, 2);
    myList.ListInsert(1, 26);
    myList.ListInsert(2, 6);
    myList.ListInsert(1, 5);
    myList.ListInsert(1, 4);
    myList.ListInsert(1, 3);
    myList.ListInsert(1, 2);
    myList.ListInsert(1, 1);
    myList.Sort();
    myList.Print();

    ElemType e = 0;
    myList.NextElem(56, e);
    cout << e << endl;
    cout << "----------end-------------" << endl << endl;
}

Status TestList::UnionList(MyList& la, MyList& lb) {
    ElemType e = 0;
    int j = 0;
    for (int i = 0; i < lb.ListLength(); i++)
    {
        lb.GetElem(i, e);
        if (!la.FindElem(j, e))
        {
            la.ListInsert(la.ListLength(), e);
        }
    }

    return OK;
}

void TestList::test_my_union_list() {
    cout << __FUNCTION__ << endl;
    MyList myList;
    myList.ListInsert(0, 1);
    myList.ListInsert(1, 2);
    myList.ListInsert(2, 3);
    myList.ListInsert(3, 5);
    myList.ListInsert(4, 5);
    myList.Sort();
    myList.Print();

    MyList myList1;
    myList1.ListInsert(0, 9);
    myList1.ListInsert(1, 19);
    myList1.ListInsert(2, 10);
    myList1.ListInsert(3, 29);
    myList1.ListInsert(4, 39);
    myList1.Sort();
    myList1.Print();

    UnionList(myList, myList1);
    myList.Sort();
    myList.Print();

    cout << "----------end-------------" << endl << endl;
}
