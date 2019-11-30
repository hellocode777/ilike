/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "queue.h"


CMyQueue::CMyQueue()
{
    PT_Node ptNode;
    ptNode = new T_NODE;
    ptNode->next = NULL;
    ptNode->date = 0;
    m_tQueue.front = m_tQueue.rear = ptNode;
}

Status CMyQueue::Pop(ElemType &e)
{
    return OK;
}

Status CMyQueue::Push(ElemType e)
{
    m_tQueue.rear->date = e;
    PT_Node pNode = new T_NODE;
    pNode->next = NULL;
    m_tQueue.rear->next = pNode;
    m_tQueue.rear = pNode;
    return OK;
}

Status CMyQueue::GetFrond(ElemType& e)
{
    if (m_tQueue.front == m_tQueue.rear)
    {
        printf("空队列\n");
        return ERROR;
    }
    e = m_tQueue.front->date;
    PT_Node ptNode = m_tQueue.front;
    m_tQueue.front = m_tQueue.front->next;
    free(ptNode);
    ptNode->next = NULL;
    return OK;
}

T_QUEUE CMyQueue::GetQueue()
{
    return m_tQueue;
}
