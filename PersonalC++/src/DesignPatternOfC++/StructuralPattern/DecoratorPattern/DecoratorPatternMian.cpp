#include "Decorator.h"
#include "../../../Public.h"
#include <iostream> 
using namespace std;
int DecoratorPatternMian() { 
  DecoratorPattern::Component* com = new DecoratorPattern::ConcreteComponent();
  DecoratorPattern::Decorator* dec = new DecoratorPattern::ConcreteDecorator(com);
  dec->Operation();
  delete dec;
  return 0; 
}
