#ifndef RB_TREE_H
#define RB_TREE_H
#include "rb_tree_iterator.h"
#include <memory>
#include <set>

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = std::alloc>
class rb_tree
{
protected:
    typedef void* void_pointer;
    typedef __rb_tree_node_base* base_ptr;
    typedef __rb_tree_node<Value> rb_tree_node;
    typedef std::simple_alloc<rb_tree_node, Alloc> rb_tree_node_allocator;
    typedef __rb_tree_color_type color_type;
    
public:
    typedef Key key_type;
    typedef Value value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef rb_tree_node* link_type;
    typedef size_t difference_type;

protected:
    link_type get_node()
    {
        return rb_tree_node_allocator::allocate();
    }
    void put_node(link_type p)
    {
        rb_tree_node_allocator::deallocate(p);
    }

    link_type create_node(const value_type& x)
    {
        link_type tmp = get_node();
        __STL_TRY
        {
            
        }
    }

}




#endif