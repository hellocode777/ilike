/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2017年10月11日, 下午2:13
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
using namespace std;

/*
 * 
 */
int i = 0;
pthread_mutex_t g_lock;
void* prit_msg1(void *p)
{
    while(pthread_mutex_trylock(&g_lock) != 0)
    {
//        usleep(100);
        /*注意pthread_mutex_trylock和pthread_mutex_lock的区别：
         * 1、pthread_mutex_trylock是非阻塞锁，发现这个锁正在另外一个线程使用，则此线程还会继续执行，那要这个函数有何用？
         * 我们可用一个while循环，在循环中可以打印出这个锁的状态，是不是很机智。
         * 
         */
    }
//    pthread_mutex_lock(&g_lock);
    for(i; i < 50; i++)
    {
        printf("out1 i = %d\n", i);
        usleep(100000);
    }
    pthread_mutex_unlock(&g_lock);
}

void* prit_msg2(void *p)
{
//    pthread_mutex_lock(&g_lock);
    while(pthread_mutex_trylock(&g_lock) != 0)
    {
//        usleep(100);
    }
    for(i; i < 100; i++)
    {
        printf("out2 i = %d\n", i);
        usleep(100000);
    }
    pthread_mutex_unlock(&g_lock);
}

int
main(int argc, char** argv)
{
    pthread_t m_p1;
    pthread_t m_p2;
    pthread_mutex_init(&g_lock, NULL);
    
    pthread_attr_t m_pat1;
    pthread_attr_t m_pat2;
    pthread_attr_init(&m_pat1);
    pthread_attr_init(&m_pat2);
    pthread_attr_setdetachstate(&m_pat1, PTHREAD_CREATE_DETACHED);
    pthread_attr_setdetachstate(&m_pat2, PTHREAD_CREATE_DETACHED);
    /*
     * 设置线程为可分离状态，可分离状态和资源回收有关。
     * 1、僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，
     * 那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。
     * 资源回收：2种方法
     * 1、系统自动释放：设置线程的状态为分离状态。线程结束后由系统自动回收资源
     * 2、由另一个线程释放：pthread_join( t)等待线程t退出，并释放t线程所占用的资源。
     */
    
    pthread_create(&m_p1, &m_pat1, prit_msg1, NULL);
    pthread_create(&m_p2, &m_pat2, prit_msg2, NULL);
//    pthread_join(m_p1, NULL);//等待线程结束，若没有此语句，线程还没结束，主进程就先结束了。主线程会在调用pthread_join()处等待
//    pthread_join(m_p2, NULL);
    pthread_mutex_destroy(&g_lock);
    while(1){}
    return 0;
}

