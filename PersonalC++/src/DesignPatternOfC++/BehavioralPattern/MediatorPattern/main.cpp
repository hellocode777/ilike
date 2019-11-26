#include "mediator.h"
#include "colleage.h"
#include <iostream>
using namespace std;
int MediatorPatternMain() {
	MediatorPattern::ConcreteMediator* m = new MediatorPattern::ConcreteMediator();
	MediatorPattern::ConcreteColleageA* c1 = new MediatorPattern::ConcreteColleageA(m);
	MediatorPattern::ConcreteColleageB* c2 = new MediatorPattern::ConcreteColleageB(m);
	m->IntroColleage(c1,c2);
	c1->SetState("old"); c2->SetState("old");
	c1->Aciton();
	c2->Aciton();
	cout<<endl;
	c1->SetState("new");
	c1->Aciton();
	c2->Aciton();
	cout<<endl;
	c2->SetState("old");
	c2->Aciton();
	c1->Aciton();
	return 0;
}
