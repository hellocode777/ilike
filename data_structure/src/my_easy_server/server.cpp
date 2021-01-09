#include "server.h"

void myServer()
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[4096];
    int n;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
    { 
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    } 
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);             
    servaddr.sin_addr.s_addr = inet_addr("192.168.64.128");
    servaddr.sin_port = htons(6666);
    int opend = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, ( const char* )&opend, sizeof( opend ) );
    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    { 
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    }

    if( listen(listenfd, 10) == -1)
    { 
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0); 
    } 
    printf("======waiting for client's request======\n");
    while(1)
    {
        struct sockaddr_in clientAddr;
        unsigned int len = sizeof(clientAddr); 
        if ((connfd = accept(listenfd, (struct sockaddr*)&clientAddr, &len)) == -1)
        { 
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
            continue; 
        } 
        std::cout << "the address of client is " << inet_ntoa(clientAddr.sin_addr) << " port is " << clientAddr.sin_port << std::endl;
        n = recv(connfd, buff, MAXLINE, 0); 
        buff[n] = '\0'; 
        printf("recv msg from client: %s\n", buff); 
        close(connfd); 
    } 
    close(listenfd); 

}