#include "element.h"
#include "visitor.h" 
#include <iostream>
using namespace std; 
int VisitorPatternMain()
{
	VisitorPattern::Visitor* vis = new VisitorPattern::ConcreteVisitorA();
	VisitorPattern::Element* elm = new VisitorPattern::ConcreteElementA();
	elm->Accept(vis); 
	return 0;
}
