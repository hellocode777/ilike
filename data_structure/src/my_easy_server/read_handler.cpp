#include "read_handler.h"
#include "server.h"

Read_Handler::Read_Handler(Reactor* reactor, Server* handler)
{
    itsServer = handler;
    itsReator = reactor;
}

void Read_Handler::handle_event()
{
    int n;
    char buff[4096];
    n = recv(itsFd, buff, MAXLINE, 0); 
    if (n <= 0)
    {
        close(itsFd);
        itsReator->remove_handler(this);
        itsServer->moveClient(itsFd);
    }
    buff[n] = '\0'; 
    printf("recv msg from client: %s\n", buff);
}

void Read_Handler::get_handle()
{

}