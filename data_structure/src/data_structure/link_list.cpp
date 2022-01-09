#include "link_list.h"
#include <algorithm>

LinkList::LinkList() {
    header = NULL;
    length = 0;
}

int LinkList::ListLength() {
    return length;
}

Status LinkList::ListInsert(int i, ElemType e) {
    if (i < 0 || i > ListLength())
        return FALSE;

    Node *np = new Node();
    np->next = NULL;
    np->value = e;

    if (header == NULL)
    {
        header = np;
        length++;
        return OK;
    }

    if (i == 0)
    {
        np->next = header;
        header = np;
        length++;
        return OK;
    }
    
    int j = 0;
    Node* tempNp = header;
    while (true)
    {
        if (j == i - 1)
        {
            break;
        }
        tempNp = tempNp->next;
        j++;
    }
    np->next = tempNp->next;
    tempNp->next = np;
    length++;

    return OK;  
}

void LinkList::Print() {
    Node* np = header;
    while (np) {
        cout << np->value;
        np = np->next;
        if (np)
            cout << "->";
    }
    cout << endl;
}

void TestLinkList::test() {
    cout << __FUNCTION__ << endl;
    
    LinkList linkList;
    ElemType e = 2;
    linkList.ListInsert(0, e);
    e = 3;
    linkList.ListInsert(1, e);
    e = 4;
    linkList.ListInsert(2, e);
    e = 21;
    linkList.ListInsert(1, e);
    e = 22;
    linkList.ListInsert(4, e);
    e = 24;
    linkList.ListInsert(4, e);

    linkList.Print();
    cout << "----------end-------------" << endl << endl;
}
