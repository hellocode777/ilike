/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: Administrator
 *
 * Created on 2018年5月2日, 上午10:06
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "public.h"

typedef struct NODE
{
    ElemType date;
    struct NODE *next;
//    PT_Node next;
}T_NODE, *PT_Node;

typedef struct QUEUE
{
    PT_Node front;//队列前
    PT_Node rear;//队列后
}T_QUEUE;

class CMyQueue
{
public:
    CMyQueue();
    Status Pop(ElemType &e);
    Status Push(ElemType e);
    Status GetFrond(ElemType &e);
    T_QUEUE GetQueue();
private:
    T_QUEUE m_tQueue;
};

#endif /* QUEUE_H */

