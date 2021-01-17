#include "server.h"

Server::Server(Reactor* reactor)
{

    std::cout << "nfds1" << std::endl;
    itsReator = reactor;

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

    itsFd = itsListenFd;
    std::cout << "nfdsr" << std::endl;
    itsReator->register_handler(Event_Type::ACCEPT_EVENT, this);
    std::cout << "nfdse" << std::endl;
}

void Server::handle_event()
{
    struct sockaddr_in clientAddr;
    unsigned int len = sizeof(clientAddr); 
    int connfd;
    if ((connfd = accept(itsListenFd, (struct sockaddr*)&clientAddr, &len)) == -1)
    { 
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
    } 
    std::cout << "the address of client is " << inet_ntoa(clientAddr.sin_addr) << " port is " << clientAddr.sin_port << std::endl;
    Event_handler* client = new Read_Handler(itsReator, this);
    client->itsFd = connfd;
    itsReator->register_handler(Event_Type::READ_EVENT, client);
    itsClientMap.insert(std::make_pair(connfd, client));
}

void Server::moveClient(int fd)
{
    auto iter = itsClientMap.find(fd);
    if (iter != itsClientMap.end())
    {
        delete iter->second;
        iter->second = NULL;
        itsClientMap.erase(fd);
    }
}

void Server::get_handle()
{

}