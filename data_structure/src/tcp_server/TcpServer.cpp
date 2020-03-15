/*
 * TcpServer.cpp
 *
 *  Created on: 2020-3-11
 *      Author: shuai
 */

#include "TcpServer.h"

void *accepter_cb(void *args)
{
	TcpServer* server = (TcpServer*)args;
    server->do_accept();
    return NULL;
}


TcpServer::TcpServer()
{
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(6666);
	iServerFd = socket(AF_INET,SOCK_STREAM,0);

    int opend = 1;
	setsockopt( iServerFd, SOL_SOCKET, SO_REUSEADDR, ( const char* )&opend, sizeof( opend ) );
	bind(iServerFd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	listen(iServerFd,10);
	iEpollFd = ::epoll_create1(0);

    int err;

    err = pthread_create(&pthNtid, NULL, accepter_cb, this);
    if (err != 0)
        printf("can't create thread: %s\n", strerror(err));

    pthread_detach(pthNtid);
    //std::cout << __LINE__<< std::endl;
}

void TcpServer::do_accept()
{
	while (1)
	{
		std::cout << "do_accept" << std::endl;
		struct epoll_event event;
		event.data.fd = accept(iServerFd,(struct sockaddr*)NULL,NULL);
		event.events = EPOLLIN;
		::epoll_ctl(iEpollFd, EPOLL_CTL_ADD, event.data.fd, &event);
	}

}

void TcpServer::do_receiveMsg()
{
	int nfds;
	char buff[MAXLINE];
    //pthread_join(pthNtid,NULL);
    //std::cout << __LINE__<< std::endl;
	while (1)
	{
		nfds = ::epoll_wait(iEpollFd, epollEvents, MAXEVENTS, 10);
		for (int i = 0; i < nfds; i++)
		{
			if (epollEvents[i].events & EPOLLIN)
            {
				memset(buff, 0, MAXLINE);
				recv(epollEvents[i].data.fd, buff, MAXLINE, 0);
				std::cout << "recv msg from client:" << buff << std::endl;
            }
		}
	}
}

TcpServer::~TcpServer() {
	// TODO Auto-generated destructor stub
}

