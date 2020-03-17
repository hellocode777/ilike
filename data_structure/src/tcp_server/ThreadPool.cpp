/*
 * ThreadPool.cpp
 *
 *  Created on: 2020-3-15
 *      Author: shuai
 */

#include "ThreadPool.h"

void *threadpool_thread(void *threadpool);

void *adjust_thread(void *threadpool)
{
	int i;
	ThreadPool *pool = (ThreadPool *)threadpool;
	while (!pool->shutdown)
	{
		sleep(1);

		pthread_mutex_lock(&(pool->lock));
		int queue_size = pool->queue_size;
		int live_thr_num = pool->live_thr_num;
		pthread_mutex_unlock(&(pool->lock));

		pthread_mutex_lock(&(pool->thread_counter));
		int busy_thr_num = pool->busy_thr_num;
		pthread_mutex_unlock(&(pool->thread_counter));

		if (queue_size >= MIN_WAIT_TASK_NUM && live_thr_num < pool->max_thr_num)
		{
			pthread_mutex_lock(&(pool->lock));
			int add= 0;
			for (i = 0; i < pool->max_thr_num && add < DEFAULT_THREAD_VARY
				&& pool->live_thr_num < pool-> max_thr_num; i++)
			{
				if (pool->threads[i] == 0 || !pool->is_thread_alive(pool->threads[i]))
				{
					pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void *)pool);
					add++;
					pool->live_thr_num++;
				}
			}
			pthread_mutex_unlock(&(pool->lock));
		}
		if ((busy_thr_num * 2) < live_thr_num && live_thr_num > pool->min_thr_num)
		{
			pthread_mutex_lock(&(pool->lock));
			pool->wait_exit_thr_num = DEFAULT_THREAD_VARY;
			pthread_mutex_unlock(&(pool->lock));
			for(i = 0; i < DEFAULT_THREAD_VARY; i++)
			{
				pthread_cond_signal(&(pool->queue_not_empty));
			}
		}
	}
	return NULL;
}

void *threadpool_thread(void *threadpool)
{
	ThreadPool *pool = (ThreadPool *)threadpool;
	ThreadPoolTask task;
	while (true)
	{
		pthread_mutex_lock(&(pool->lock));

		while ((pool->queue_size == 0) && (!pool->shutdown))
		{
			cout << "thread: " <<  (unsigned int)pthread_self() << "is waiting" << endl;
			pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));
			if (pool->wait_exit_thr_num > 0)
			{
				pool->wait_exit_thr_num--;
				if (pool->live_thr_num > pool->min_thr_num)
				{
					cout << "thread: " <<  (unsigned int)pthread_self() << "is exiting" << endl;
					pool->live_thr_num--;
					pthread_mutex_unlock(&(pool->lock));
					pthread_exit(NULL);
				}
			}
		}

		if (pool->shutdown)
		{
			pthread_mutex_unlock(&(pool->lock));
			cout << "thread: " <<  (unsigned int)pthread_self() << "is exiting" << endl;
			pthread_exit(NULL);
		}

		task.function = pool->task_queue[pool->queue_front].function;
		task.arg = pool->task_queue[pool->queue_front].arg;

		pool->queue_front = (pool->queue_front + 1) % pool->queue_max_size;
		pool->queue_size--;

		pthread_cond_broadcast(&(pool->queue_not_full));

		pthread_mutex_unlock(&(pool->lock));

		cout << "thread: " <<  (unsigned int)pthread_self() << "start working! " << endl;
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num++;
		pthread_mutex_unlock(&(pool->thread_counter));
		(*(task.function))(task.arg);

		cout << "thread: " <<  (unsigned int)pthread_self() << "end working! " << endl;
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num--;
		pthread_mutex_unlock(&(pool->thread_counter));

	}

	pthread_exit(NULL);
}

int ThreadPool::threadpool_free(ThreadPool *pool)
{
	if (pool == NULL)
	{
		return -1;
	}
	if (pool->task_queue)
	{
		free(pool->task_queue);
	}
	if (pool->threads)
	{
		free(pool->threads);
		pthread_mutex_lock(&(pool->lock));
		pthread_mutex_destroy(&(pool->lock));
		pthread_mutex_lock(&(pool->thread_counter));
		pthread_mutex_destroy(&(pool->thread_counter));
		pthread_cond_destroy(&(pool->queue_not_empty));
		pthread_cond_destroy(&(pool->queue_not_full));
	}
	free(pool);
	pool = NULL;
	return 0;
}

int ThreadPool::is_thread_alive(pthread_t tid)
{
	int kill_rc = pthread_kill(tid, 0);
	if (kill_rc == ESRCH)
	{
		return 0;
	}
	return 1;
}

ThreadPool::ThreadPool() {
	// TODO Auto-generated constructor stub

}

ThreadPool* ThreadPool::threadPool_create(int min_thr_num, int max_thr_num, int queue_max_size)
{
	ThreadPool* pool = new ThreadPool;
	for (int i = 0; i < 1; i++)
	{
		pool->min_thr_num = min_thr_num;
		pool->max_thr_num = max_thr_num;
		pool->busy_thr_num = 0;
		pool->live_thr_num = min_thr_num;
		pool->queue_size = 0;
		pool->queue_max_size = queue_max_size;
		pool->queue_front = 0;
		pool->queue_rear = 0;
		pool->shutdown = false;


		if (pthread_mutex_init(&(pool->lock), NULL) != 0
				|| pthread_mutex_init(&(pool->thread_counter), NULL) != 0
				|| pthread_cond_init(&(pool->queue_not_empty), NULL) != 0
				|| pthread_cond_init(&(pool->queue_not_full), NULL) != 0)
		{
			cout <<  "init the lock or cond fail!" << endl;
			break;
		}

		pool->threads = (pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
		if (pool->threads == NULL)
		{
			cout <<  "malloc threads fail!" << endl;
			break;
		}
		memset(pool->threads, 0, sizeof(pthread_t)*max_thr_num);

		pool->task_queue = (ThreadPoolTask *)malloc(sizeof(ThreadPoolTask)*queue_max_size);
		if (pool->task_queue == NULL)
		{
			cout <<  "malloc ThreadPoolTask fail!" << endl;
			break;
		}
		memset(pool->task_queue, 0, sizeof(ThreadPoolTask)*queue_max_size);

		for (int i = 0; i < min_thr_num; i++)
		{
			pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void *)pool);
			sleep(4);
			//cout << "start thread: " <<  (unsigned int)pool->threads[i] << endl;
		}
		pthread_create(&(pool->adjust_tid), NULL, adjust_thread, (void *)pool);
		return pool;
	}

	threadpool_free(pool);

	return NULL;

}

int ThreadPool::threadpool_add(ThreadPool *pool, void*(*function)(void *arg), void *arg)
{
	pthread_mutex_lock(&(pool->lock));

	while((pool->queue_size == pool->queue_max_size) && (!pool->shutdown))
	{
		pthread_cond_wait(&(pool->queue_not_full), &(pool->lock));
	}
	if (pool->shutdown)
	{
		pthread_mutex_unlock(&(pool->lock));
	}

	if (pool->task_queue[pool->queue_rear].arg != NULL)
	{
		free(pool->task_queue[pool->queue_rear].arg);
		pool->task_queue[pool->queue_rear].arg = NULL;
	}

	pool->task_queue[pool->queue_rear].function = function;

	pool->task_queue[pool->queue_rear].arg = arg;
	pool->queue_rear = (pool->queue_rear + 1) % pool->queue_max_size;
	pool->queue_size++;

	pthread_cond_signal(&(pool->queue_not_empty));
	pthread_mutex_unlock(&(pool->lock));

	return 0;

}

int ThreadPool::threadpool_destroy(ThreadPool *pool)
{
	int i;
	if (pool == NULL)
	{
		return -1;
	}
	pool->shutdown = true;

	pthread_join(pool->adjust_tid, NULL);

	for (i = 0; pool->live_thr_num; i++)
	{
		pthread_cond_broadcast(&(pool->queue_not_empty));
	}
	for (i = 0; pool->live_thr_num; i++)
	{
		pthread_join(pool->threads[i], NULL);
	}

	threadpool_free(pool);

	return 0;
}

ThreadPool::~ThreadPool() {
	// TODO Auto-generated destructor stub
}

