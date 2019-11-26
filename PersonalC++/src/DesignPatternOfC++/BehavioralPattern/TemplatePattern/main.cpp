#include "Template.h"
#include <iostream>
using namespace std; 
int TemplatePatternMain()
{
	TemplatePattern::AbstractClass* p1 = new TemplatePattern::ConcreteClass1();
	TemplatePattern::AbstractClass* p2 = new TemplatePattern::ConcreteClass2(); 
	p1->TemplateMethod();
	p2->TemplateMethod();
	return 0;
}
