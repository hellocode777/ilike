#include <cstdlib>
#include "memory_plan/CMemoryPlan.h"
using namespace std;

int main(int argc, char** argv)
{
	CMemoryPlan  myPlan(26, 96, 6);
	myPlan.MakePlan();
    return 0;
}


