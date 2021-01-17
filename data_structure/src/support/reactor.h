#ifndef REACTOR_H
#define REACTOR_H
#include "event_handler.h"
#include "my_epoll.h"

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

#include <map>

#include<iostream>
class Reactor
{
public:

    void handle_events();
    void register_handler(Event_Type et, Event_handler* handler);
    void remove_handler(Event_handler* handler);
    void run();

private:
    my_epoll itsEpoll;
    std::map<int, Event_handler*> itsEvents; 
};


#endif