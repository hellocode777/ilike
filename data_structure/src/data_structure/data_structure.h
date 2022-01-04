#ifndef DATA_STRUCTURE_H_
#define DATA_STRUCTURE_H_

#include "../../include/public.h"

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int ElemType;


class Triplet
{
public:
    Triplet(ElemType v1, ElemType v2, ElemType v3);
    Status get_elem(int i, ElemType& e);
    Status put_elem(int i, ElemType e);
    Status is_ascending();
    Status is_descending();
    Status max(ElemType& e);
    Status min(ElemType& e);

private:
    ElemType Data[3];
};    




class DataStructure
{
public:
    explicit DataStructure(ElemType v1, ElemType v2, ElemType v3);
    Triplet& get();
private:
    Triplet t_data;
};    

#endif
