#include "Adapter.h"
#include "../../../Public.h"
#include <iostream>
using namespace std;

int AdapterPattern_class_Main() {
	//Adapter* adt = new Adapter();
	AdapterPattern_class_::Target* adt = new AdapterPattern_class_::Adapter();
	adt->Request();
	return 0;
}
