#ifndef READ_HANDLER_H
#define READ_HANDLER_H

#include "../support/event_handler.h"
#include "../support/reactor.h"

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

class Server;
class Read_Handler : public Event_handler
{
public:
    Read_Handler(Reactor* reactor, Server* handler);
    void handle_event() override;
    void get_handle() override;
private:
    Reactor* itsReator;
    Server* itsServer;
};


#endif