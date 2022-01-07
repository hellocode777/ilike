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
    e = *(sq_list.elem + i);
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
        *(sq_list.elem + i) = e;
        sq_list.length += 1;
        return OK;
    }
    int j = ListLength() - 1;
    while (true)
    {
        *(sq_list.elem + j + 1) = *(sq_list.elem + j); 
        if (j == i)
        {
            *(sq_list.elem + j) = e;
            sq_list.length += 1;
            break;
        }
        j--;
    }
    return OK;
}
