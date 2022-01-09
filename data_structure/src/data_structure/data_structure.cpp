#include "data_structure.h"

DataStructure::DataStructure(ElemType v1, ElemType v2, ElemType v3):t_data(v1, v2, v3) {
}

Triplet &DataStructure::get() {
    return t_data;
}



Triplet::Triplet(ElemType v1, ElemType v2, ElemType v3) {
    Data[0] = v1;
    Data[1] = v2;
    Data[2] = v3;
}

Status Triplet::get_elem(int i, ElemType &e) {
    if (i < 0 || i > 2)
        return ERROR;
    e = Data[i];
    return OK;
}

Status Triplet::put_elem(int i, ElemType e) {
    if (i < 0 || i > 2)
        return ERROR;
    Data[i] = e;
    return OK;
}

Status Triplet::is_ascending() {
    return Data[0] <= Data[1] && Data[1] <= Data[2];
}

Status Triplet::is_descending() {
    return Data[0] >= Data[1] && Data[1] >= Data[2];
}

Status Triplet::max(ElemType &e) {
    e = Data[0] >= Data[1] ? (Data[0] >= Data[2] ? Data[0] : Data[2]) : (Data[1] >= Data[2] ? Data[1] : Data[2]);
    return OK;
}

Status Triplet::min(ElemType &e) {
    e = Data[0] <= Data[1] ? (Data[0] <= Data[2] ? Data[0] : Data[2]) : (Data[1] <= Data[2] ? Data[1] : Data[2]);
    return OK;
}



void test_data_structure() {
    cout << __FUNCTION__ << endl;
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
    cout << "----------end-------------" << endl << endl;
}
