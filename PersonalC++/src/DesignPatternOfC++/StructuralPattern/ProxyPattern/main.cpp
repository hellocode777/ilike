#include "Proxy.h"
#include <iostream>
using namespace std;
int ProxyPatternMain() {
	ProxyPattern::Subject* sub = new ProxyPattern::ConcreteSubject();
	ProxyPattern::Proxy* p = new ProxyPattern::Proxy(sub);
	p->Request();
	return 0;
}
