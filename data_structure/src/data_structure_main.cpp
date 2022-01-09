#include "data_structure_main.h"

int main(int argc, char** argv)
{
    cout << "TestList" << endl;
    TestList test_list;
    test_list.test_my_list();
    test_list.test_my_union_list();

    test_data_structure();

    cout << "TestMergeList" << endl;
    TestMergeList test_merge;
    test_merge.test();

    cout << "TestLinkList" << endl;
    TestLinkList testLinkList;
    testLinkList.test();
    return 0;
}


