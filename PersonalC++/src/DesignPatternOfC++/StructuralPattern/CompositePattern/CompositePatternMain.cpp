#include "Component.h" 
#include "Composite.h" 
#include "../../../Public.h"
#include "Leaf.h" 
#include <iostream> 
using namespace std;
int CompositePatternMain() { 
  CompositePattern::Leaf* l = new CompositePattern::Leaf(); 
  l->Operation();
  CompositePattern::Composite* com = new CompositePattern::Composite();
  com->Add(l);
  com->Operation();
  CompositePattern::Component* ll = com->GetChild(0);
  ll->Operation();
  return 0;
}
