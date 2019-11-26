#include "iterator.h"
#include "aggregate.h"
#include <iostream>
using namespace std;
int IteratorPatternMain() {
	IteratorPattern::Aggregate* ag = new IteratorPattern::ConcreteAggregate();
	IteratorPattern::Iterator* it = new IteratorPattern::ConcreteIterator(ag);
	for (; !(it->IsDone()) ; it->Next())
	{
		cout<<it->CurrentItem()<<endl;
	}
	return 0;
}
