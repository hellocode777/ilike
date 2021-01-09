#include "server.h"

Server::Server()
{
    itsEpollFd = epoll_create(MAXFD + 1);
    if (itsEpollFd <= 0)
    {
        std::cout << "epoll_create() failed!" << std::endl;
    }

    struct sockaddr_in servaddr;
    if ((itsListenFd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
    { 
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    } 
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("192.168.64.128");
    servaddr.sin_port = htons(6666);
    int opend = 1;
	setsockopt(itsListenFd, SOL_SOCKET, SO_REUSEADDR, ( const char* )&opend, sizeof( opend ) );
    if( bind(itsListenFd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    { 
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    }

    if( listen(itsListenFd, 10) == -1)
    { 
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    } 

    epoll_event event;
    event.data.fd = itsListenFd;
    event.events = EPOLL_CTL_ADD;
    if (epoll_ctl(itsEpollFd, EPOLL_CTL_ADD, itsListenFd, &event) < 0)
    {
        std::cout << "event add failed!" << std::endl;
    }
}

void Server::run()
{
    printf("======waiting for client's request======\n");
    int connfd;
    epoll_event ev;
    epoll_event events[MAXFD + 1];
    while(1)
    {
        int nfds = epoll_wait(itsEpollFd, events, MAXFD + 1, 100);
        //sleep(1);
        for (int i = 0; i < nfds; i++)
        {
            //sleep(1);
            if (events[i].data.fd == itsListenFd)
            {
                struct sockaddr_in clientAddr;
                unsigned int len = sizeof(clientAddr); 
                if ((connfd = accept(itsListenFd, (struct sockaddr*)&clientAddr, &len)) == -1)
                { 
                    printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
                    continue; 
                } 
                std::cout << "the address of client is " << inet_ntoa(clientAddr.sin_addr) << " port is " << clientAddr.sin_port << std::endl;
                ev.data.fd = connfd;
                ev.events = EPOLLIN;
                epoll_ctl(itsEpollFd, EPOLL_CTL_ADD, connfd, &ev);
            }
            else if (events[i].events & EPOLLIN)
            {
                int n;
                int clientFd = events[i].data.fd;
                char buff[4096];
                n = recv(clientFd, buff, MAXLINE, 0); 
                if (n <= 0)
                {
                    close(clientFd);
                    epoll_ctl(itsEpollFd, EPOLL_CTL_DEL, clientFd, &events[i]);
                    continue;
                }
                buff[n] = '\0'; 
                printf("recv msg from client: %s\n", buff); 
            }
        }
    } 
}

Server::~Server()
{
    close(itsListenFd);
}