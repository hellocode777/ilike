#include "data_structure/data_structure.h"
#include "data_structure/my_list.h"

int main(int argc, char** argv)
{
    DataStructure d(1, 5, 6);
    ElemType e1;

    d.get().get_elem(1, e1);
    cout << e1 << endl;

    e1 = 30;
    d.get().put_elem(0, e1);
    cout << d.get().is_ascending() << endl;

    d.get().max(e1);
    cout << e1 << endl;

    d.get().min(e1);
    cout << e1 << endl;



    cout << "test 1" << endl;
    MyList myList;
    myList.ListInsert(0, 2);
    myList.ListInsert(1, 26);
    myList.ListInsert(2, 36);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    myList.ListInsert(1, 56);
    ElemType e;
    for (int i = 0; i < myList.ListLength(); i++)
    {
        myList.GetElem(i, e);
        cout << e << endl;
    }

        myList.NextElem(56, e);
        cout << e << endl;
    return 0;
}


