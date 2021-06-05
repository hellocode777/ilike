#ifndef RB_TREE_ITERATOR_H
#define RB_TREE_ITERATOR_H

#include "rb_tree_node.h"

struct __rb_tree_base_iterator
{
    typedef __rb_tree_node_base::base_ptr base_ptr;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;

    base_ptr node;

    void increment()
    {
        if (node->right != 0)
        {
            node = node->right;
            while (node->left != 0)
            {
                node = node->left;
            }
        }
        else
        {
            base_ptr y = node->parent;
            while (node == y->right)
            {
                node = y;
                y = y->parent;
            }
            if (node->right != y)
            {
                node = y;
            }
        }
        
    }

    void decrement()
    {
        if (node->color == __rb_tree_red && node->parent->parent == node)
        {
            node = node->right;
        }
        else if (node->left != 0)
        {
            base_ptr y = node->left;
            while (y->right != 0)
            {
                y = y->right;
            }
            node = y;
            
        }
        else
        {
            base_ptr y = node->parent;
            while (node == y->left)
            {
                node = y;
                y = y->parent;
            }
            node = y;
        }
    }
};

template <class Value, class Ref, class Ptr>
struct __rb_tree_iterator : public __rb_tree_base_iterator
{
    typedef Value value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef __rb_tree_iterator<Value, Value&, Value*> iterator;
    typedef __rb_tree_iterator<Value, const Value&, const Value*> const_iterator;
    typedef __rb_tree_iterator<Value, Ref, Ptr> self;
    typedef __rb_tree_node<Value>* link_type;

    __rb_tree_iterator() {}
    __rb_tree_iterator(link_type x) { node = x;}
    __rb_tree_iterator(const iterator& it) { node = it.node;}

    reference operator*() const
    {
        return link_type(node)->value_field;
    }
    #ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator++(int) const
    {
        return &(operator*());
    }
    #endif

    self& operator++()
    {
        increment();
        return *this;
    }
    self operator++(int)
    {
        self tmp = *this;
        increment();
        return tmp;
    }

    self& operator--()
    {
        decrement();
        return *this;
    }
    self operator--(int)
    {
        self tmp = *this;
        decrement();
        return tmp;
    }


};




#endif