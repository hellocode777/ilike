#ifndef _LEAF_H_ 
#define _LEAF_H_
#include "Component.h"

namespace CompositePattern{
class Leaf:public Component { 
public: 
  Leaf();
  ~Leaf();
  void Operation();
protected:
private:
}; 
}
#endif //~_LEAF_H_
