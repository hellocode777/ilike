#ifndef RB_TREE_H
#define RB_TREE_H
#include "rb_tree_iterator.h"

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = alloc>
class rb_tree
{
protected:
    typedef void* void_pointer;
    typedef __rb_tree_node_base* base_ptr;
    typedef __rb_tree_node<Value> rb_tree_node;
    typedef simple_alloc<rb_tree_node, Alloc> rb_tree_node_allocator;
    typedef __rb_tree_color_type color_type;
    
public:
}




#endif