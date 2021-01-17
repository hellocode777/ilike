#include "my_easy_server/server.h"
#include "support/reactor.h"
#include "support/accept_handler.h"

int main()
{
    Reactor* reactor = new Reactor();
    Server myServer(reactor);
    reactor->run();



    delete reactor;
    reactor = NULL;
    return 0;
}