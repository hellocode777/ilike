/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   b_tree.h
 * Author: Administrator
 *
 * Created on 2018年5月4日, 上午10:05
 */

#ifndef B_TREE_H
#define B_TREE_H

#include "public.h"


typedef struct NODE
{
    ElemType date;
    int *lchild;
    int *rchild;
}T_NODE, *PT_NODE;

typedef struct B_TREE
{
    char date;
    struct B_TREE *lchild;
    struct B_TREE *rchild;
}T_B_TREE, *PT_B_TREE;

class CMyBtree {
public:
    CMyBtree();
    CMyBtree(PT_B_TREE &tree);
    CMyBtree(const CMyBtree& orig);
    PT_B_TREE CreatTree(PT_B_TREE &tree);
    void GetTree(PT_B_TREE tree);
    virtual ~CMyBtree();
//private:
//    PT_B_TREE m_ptETree;
};

#endif /* B_TREE_H */

