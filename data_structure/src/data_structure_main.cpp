#include "data_structure/data_structure.h"

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
    return 0;
}


