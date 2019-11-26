#include "subject.h"
#include "observer.h"
#include <iostream>
using namespace std;
int ObserverPatternMain() {
	ObserverPattern::ConcreteSubject* sub = new ObserverPattern::ConcreteSubject();
	ObserverPattern::Observer* o1 = new ObserverPattern::ConcreteObserverA(sub);
	ObserverPattern::Observer* o2 = new ObserverPattern::ConcreteObserverB(sub);
	sub->SetState("old");
	sub->Notify();
	sub->SetState("new"); //也可以由Observer调用
	sub->Notify();
	return 0;
}
