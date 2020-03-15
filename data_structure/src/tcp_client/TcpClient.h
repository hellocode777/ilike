/*
 * TcpClient.h
 *
 *  Created on: 2020-3-11
 *      Author: shuai
 */

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<errno.h>
#include<iostream>
#include<unistd.h>



#define MAXLINE 4096

class TcpClient {
public:
	TcpClient();
	void do_connet();
	void do_send_msg();
	virtual ~TcpClient();

private:
    struct sockaddr_in servaddr;
	int iClientFd;
};

#endif /* TCPCLIENT_H_ */
