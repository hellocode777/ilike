#ifndef MY_EPOLL_H
#define MY_EPOLL_H


#include "event_handler.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include <sys/epoll.h>

#include<iostream>

#define MAXFD 4096
class my_epoll
{
private:
    /* data */
public:
    my_epoll(/* args */);
    int getEpollFd() { return itsEpollFd; }
    int my_select(int epollFd, struct epoll_event* events,
		       int maxevents, int timeout);
    ~my_epoll();
private:
    int itsEpollFd;
};



#endif