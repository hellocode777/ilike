/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   b_tree.cpp
 * Author: Administrator
 * 
 * Created on 2018年5月4日, 上午10:05
 */

#include <math.h>

#include "b_tree.h"
PT_B_TREE CreatTree1(PT_B_TREE tree);

CMyBtree::CMyBtree() 
{
    
}

CMyBtree::CMyBtree(PT_B_TREE &tree) 
{
    

}


PT_B_TREE CMyBtree::CreatTree(PT_B_TREE &tree)
{
    char chCh;
    std::cin >> chCh;

    tree = new T_B_TREE;
    if (tree == NULL) exit(OVERFLOW1);
        
    tree->date = chCh;
    tree->lchild = CreatTree1(tree->lchild);
    tree->rchild = CreatTree1(tree->rchild);


}

PT_B_TREE CreatTree1(PT_B_TREE tree)
{
    char chCh;
    std::cin >> chCh;
    if (chCh == '#')
        tree = NULL;
    else
    {
        tree = new T_B_TREE;
        if (tree == NULL) exit(OVERFLOW1);
        
        tree->date = chCh;
        tree->lchild = CreatTree1(tree->lchild);
        tree->rchild = CreatTree1(tree->rchild);
    }
    return tree;
}

void CMyBtree::GetTree(PT_B_TREE tree)
{
    if (tree != NULL)
    {
        printf("%c\n", tree->date);
        GetTree(tree->lchild);
        GetTree(tree->rchild);
    }
}

CMyBtree::CMyBtree(const CMyBtree& orig) {
}

CMyBtree::~CMyBtree() {
}

