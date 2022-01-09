#ifndef TEST_MERGE_LIST_H_
#define TEST_MERGE_LIST_H_


#include "my_list.h"

class TestMergeList {
public:
    Status MergeList(MyList la, MyList lb, MyList& targetList);
    void test();
};
#endif
