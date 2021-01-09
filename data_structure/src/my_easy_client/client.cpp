#include "client.h"

void myClient()
{
    int sockfd;
    char sendline[4096];
    struct sockaddr_in servaddr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        exit(0);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    { 
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }
    while (true)
    {
        printf("send msg to server: \n"); fgets(sendline, 4096, stdin);
        if (send(sockfd, sendline, strlen(sendline), 0) < 0)
        {
            printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
            exit(0);
        }
        memset(sendline, 0, 4096);
    } 
    close(sockfd);
    exit(0);
}