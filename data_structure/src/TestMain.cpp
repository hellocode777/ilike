#include <cstdlib>
#include "TestDay/test.h"
using namespace std;

int main(int argc, char** argv)
{
	test  test;
	test.test1();

	test.test2();

	test.test3();
	test.testSmartPtr();
	test.testDefault();
    return 0;
}
