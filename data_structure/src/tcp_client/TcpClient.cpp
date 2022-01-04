/*
 * TcpClient.cpp
 *
 *  Created on: 2020-3-11
 *      Author: shuai
 */

#include "TcpClient.h"

TcpClient::TcpClient()
{
	// TODO Auto-generated constructor stub

    int sockfd,n;



    iClientFd = socket(AF_INET,SOCK_STREAM,0);


    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);

}

void TcpClient::do_connet()
{
    connect(iClientFd,(struct sockaddr*)&servaddr,sizeof(servaddr));
}

void TcpClient::do_send_msg()
{
    char sendline[MAXLINE];
    while (1)
    {
    	memset(sendline, 0, MAXLINE);
		std::cout << "send msg to server:" << std::endl;
		fgets(sendline, MAXLINE, stdin);
		send(iClientFd, sendline, strlen(sendline), 0);
        char recvline[MAXLINE];
        recv(iClientFd, recvline, MAXLINE, 0);
		std::cout << "recv msg from server:" << recvline << std::endl;
    }

}

TcpClient::~TcpClient() {
	// TODO Auto-generated destructor stub
	close(iClientFd);
}

