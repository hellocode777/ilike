#include "my_epoll.h"
my_epoll::my_epoll(/* args */)
{
    itsEpollFd = epoll_create(MAXFD + 1);
}

my_epoll::~my_epoll()
{
}

int my_epoll::my_select(int epollFd, struct epoll_event* events,
		       int maxevents, int timeout)
{
    return epoll_wait(epollFd, events, maxevents, timeout);
}