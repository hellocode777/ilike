/*
 * ThreadPoolTask.h
 *
 *  Created on: 2020-3-15
 *      Author: shuai
 */

#ifndef THREADPOOLTASK_H_
#define THREADPOOLTASK_H_

class ThreadPoolTask {
public:
	ThreadPoolTask();
	void *(*function)(void*);
	void *arg;
	virtual ~ThreadPoolTask();

};

#endif /* THREADPOOLTASK_H_ */
