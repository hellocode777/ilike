/*
 * TcpServer.h
 *
 *  Created on: 2020-3-11
 *      Author: shuai
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<errno.h>
#include<iostream>
#include<unistd.h>
#include <sys/epoll.h>

#include <pthread.h>
#include "event_loop.h"


#define MAXLINE 4096
#define MAXEVENTS 10

class TcpServer {
public:
	TcpServer(event_loop* loop);
	void do_accept();
	//void *thr_fn(void *arg)
	void handle_read();
	virtual ~TcpServer();


private:
	int iServerFd;
	int iClientFd;

	event_loop* _loop;

	int iEpollFd;
    pthread_t pthNtid;
	struct epoll_event epollEvents[MAXEVENTS];
};

#endif /* TCPSERVER_H_ */
