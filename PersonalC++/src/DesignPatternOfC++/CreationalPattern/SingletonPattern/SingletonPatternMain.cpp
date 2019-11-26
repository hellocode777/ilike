#include "Singleton.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;

int SingletonPatternMain()
{
	//Singleton* sgn = Singleton::Instance();
	Singleton::Instance();
	return 0;
}
