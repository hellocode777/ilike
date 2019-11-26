#include "element.h"
#include "visitor.h" 
#include <iostream>
using namespace std; 

namespace VisitorPattern {
Element::Element()
{
}


Element::~Element()
{
} 
void Element::Accept(Visitor* vis)
{
} 
ConcreteElementA::ConcreteElementA()
{
} 
ConcreteElementA::~ConcreteElementA()
{
} 
void ConcreteElementA::Accept(Visitor* vis)
{
	vis->VisitConcreteElementA(this);
	cout<<"visiting ConcreteElementA..."<<endl;
} 
ConcreteElementB::ConcreteElementB()
{
}


ConcreteElementB::~ConcreteElementB()
{
} 	
void ConcreteElementB::Accept(Visitor* vis)
{
	cout<<"visiting ConcreteElementB..."<<endl;
	vis->VisitConcreteElementB(this);
}
}
