#include "reactor.h"

void Reactor::handle_events()
{

}

void Reactor::register_handler(Event_Type et, Event_handler* handler)
{
    std::cout << "nfds2" << std::endl;
    if (et == Event_Type::ACCEPT_EVENT)
    {
        epoll_event event;
        event.data.fd = handler->itsFd;
        event.events = EPOLLIN;
        epoll_ctl(itsEpoll.getEpollFd(), EPOLL_CTL_ADD, handler->itsFd, &event); 
        itsEvents.insert(std::make_pair(handler->itsFd, handler));
    }
    else if (et == Event_Type::READ_EVENT)
    {
        epoll_event event;
        event.data.fd = handler->itsFd;
        event.events = EPOLLIN;
        epoll_ctl(itsEpoll.getEpollFd(), EPOLL_CTL_ADD, handler->itsFd, &event); 
        itsEvents.insert(std::make_pair(handler->itsFd, handler));
    }
}

void Reactor::remove_handler(Event_handler* handler)
{
    epoll_event event;
    event.data.fd = handler->itsFd;
    event.events = EPOLLIN;
    epoll_ctl(itsEpoll.getEpollFd(), EPOLL_CTL_DEL, handler->itsFd, &event); 
    itsEvents.erase(handler->itsFd);
}

void Reactor::run()
{
    epoll_event events[MAXFD + 1];
    std::cout << "nfds" << std::endl;
    while(1)
    {
        int nfds = itsEpoll.my_select(itsEpoll.getEpollFd(), events, MAXFD + 1, 100);
        sleep(1);
        std::cout << nfds << std::endl;
        for (int i = 0; i < nfds; i++)
        {
            //sleep(1);
            auto iter = itsEvents.find(events[i].data.fd);
            if (events[i].events & EPOLLIN)
            {
                iter->second->handle_event();
            }
        }
    } 
}