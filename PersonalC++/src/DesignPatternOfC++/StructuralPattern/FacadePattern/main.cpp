#include "Flyweight.h"
#include "FlyweightFactory.h"
#include <iostream>
using namespace std;
int FacadePatternMain() {
	FacadePattern::FlyweightFactory* fc = new FacadePattern::FlyweightFactory();
	FacadePattern::Flyweight* fw1 = fc->GetFlyweight("hello");
	FacadePattern::Flyweight* fw2 = fc->GetFlyweight("world!");
	FacadePattern::Flyweight* fw3 = fc->GetFlyweight("hello");
return 0; }
