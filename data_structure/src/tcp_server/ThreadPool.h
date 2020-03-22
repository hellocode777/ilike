/*
 * ThreadPool.h
 *
 *  Created on: 2020-3-15
 *      Author: shuai
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <pthread.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <signal.h>
#include "ThreadPoolTask.h"
using namespace std;

#define DEFAULT_TIME 10
#define MIN_WAIT_TASK_NUM 10
#define DEFAULT_THREAD_VARY 10

class ThreadPool {
public:
	ThreadPool(int min_thr_num, int max_thr_num, int queue_max_size);
	//ThreadPool* threadPool_create(int min_thr_num, int max_thr_num, int queue_max_size);
	int threadpool_destroy(ThreadPool *pool);
	int threadpool_add(void*(*function)(void *arg), void *arg);
	int threadpool_free();
	int is_thread_alive(pthread_t tid);

	virtual ~ThreadPool();


	pthread_mutex_t lock;
	pthread_mutex_t thread_counter;
	pthread_cond_t queue_not_full;
	pthread_cond_t queue_not_empty;

	pthread_t adjust_tid;
	pthread_t* threads;
	ThreadPoolTask* task_queue;

	int min_thr_num;
	int max_thr_num;
	int live_thr_num;
	int busy_thr_num;
	int wait_exit_thr_num;

	int queue_front;
	int queue_rear;
	int queue_size;
	int queue_max_size;

	bool shutdown;



};

#endif /* THREADPOOL_H_ */
