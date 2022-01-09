#include "my_list.h"

MyList::MyList() {
    sq_list.elem = new int(LIST_INIT_SIZE * sizeof(ElemType));
    sq_list.length = 0;
    sq_list.listsize = LIST_INIT_SIZE;
}


Status MyList::ClearList() {
    if (!sq_list.elem)
        return FALSE;
    sq_list.length = 0;
    return OK;
}

Status MyList::ListEmpty() {
    if (!sq_list.elem)
        return FALSE;
    if (sq_list.length)
    {
        return FALSE;
    }
    return OK;
}

int MyList::ListLength() {
    return sq_list.length;
}

Status MyList::GetElem(int i, ElemType &e) {
    if (!sq_list.elem || (i < 0 || i > ListLength() - 1))
        return FALSE;
    e = sq_list.elem[i];
    return OK;
}

Status MyList::PriorElem(ElemType cur_e, ElemType &pre_e) {
    if (!sq_list.elem)
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
    if (!sq_list.elem)
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
    if (!sq_list.elem || (i < 0 || i > ListLength()))
        return FALSE;

    if (ListLength() == i)
    {
        sq_list.elem[i] = e;
        sq_list.length += 1;
        return OK;
    }
    int j = ListLength() - 1;
    while (true)
    {
        sq_list.elem[j + 1] = sq_list.elem[j];
        if (j == i)
        {
            sq_list.elem[j] = e;
            sq_list.length += 1;
            break;
        }
        j--;
    }
    return OK;
}

Status MyList::FindElem(int &i, ElemType e) {

    for (int j = 0; j < ListLength(); j++)
    {
        if (e == sq_list.elem[j])
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
        cout << sq_list.elem[i];
        if (i != ListLength() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}

MyList::~MyList() {
    cout << __FUNCTION__ << endl;
    //delete sq_list.elem;
    sq_list.elem = NULL;
    sq_list.length = 0;
    sq_list.listsize = 0;
}
void TestList::test_my_list() {
    cout << __FUNCTION__ << endl;
    MyList myList;
    myList.ListInsert(0, 2);
    myList.ListInsert(1, 26);
    myList.ListInsert(2, 36);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
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
    myList.Print();

    MyList myList1;
    myList1.ListInsert(0, 9);
    myList1.ListInsert(1, 19);
    myList1.ListInsert(2, 10);
    myList1.ListInsert(3, 29);
    myList1.ListInsert(4, 39);
    myList1.Print();

    UnionList(myList, myList1);
    myList.Print();

    cout << "----------end-------------" << endl << endl;
}
