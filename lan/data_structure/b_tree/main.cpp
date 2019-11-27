/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2018年5月4日, 上午10:05
 */

#include <cstdlib>
#include "b_tree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    PT_B_TREE ptBtree;
    CMyBtree cMyBtree;
    cMyBtree.CreatTree(ptBtree);
    cMyBtree.GetTree(ptBtree);
    return 0;
}

