#ifndef SERVER_H
#define SERVER_H

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

#define MAXLINE 4096
#define MAXFD 4096


class Server
{
public:
    Server();
    ~Server();
    void run();
private:
    int itsListenFd;
    int itsEpollFd;

    struct epoll_event itsEpollEvents[MAXFD];
};
#endif