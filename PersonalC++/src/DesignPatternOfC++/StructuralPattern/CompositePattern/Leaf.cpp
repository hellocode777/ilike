#include "Leaf.h" 
#include <iostream> 
using namespace std;
namespace CompositePattern{
Leaf::Leaf() {
}
Leaf::~Leaf() { }
void Leaf::Operation() { 
  cout<<"Leaf operation....."<<endl;
}
}
