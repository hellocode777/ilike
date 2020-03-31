/*
 * TcpServer.cpp
 *
 *  Created on: 2020-3-11
 *      Author: shuai
 */

#include "TcpServer.h"
namespace my_tcp_server {
void accepter_cb(event_loop* loop, int fd, void *args)
{
	TcpServer* server = (TcpServer*)args;
    server->do_accept();
}

void tcp_rcb(event_loop* loop, int fd, void *args)
{
	TcpServer* server = (TcpServer*)args;
	server->handle_read(fd);
}


/*
void *accepter_cb(void *args)
{
	TcpServer* server = (TcpServer*)args;
    server->do_accept();
    return NULL;
}
*/

TcpServer::TcpServer(event_loop* loop)
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

	_loop = loop;

	listen(iServerFd,10);

    //add accepter event
	_loop->add_ioev(iServerFd, accepter_cb, EPOLLIN, this);

/*
    int err;

    err = pthread_create(&pthNtid, NULL, accepter_cb, this);
    if (err != 0)
        printf("can't create thread: %s\n", strerror(err));

    pthread_detach(pthNtid);
    //std::cout << __LINE__<< std::endl;
     * */

}

void TcpServer::do_accept()
{

	std::cout << "do_accept" << std::endl;

	int iClient = accept(iServerFd,(struct sockaddr*)NULL,NULL);

	_loop->add_ioev(iClient, tcp_rcb, EPOLLIN, this);


/*
	int connfd;
   	bool conn_full = false;
	while (true)
	{
		connfd = ::accept(iServerFd,(struct sockaddr*)NULL,NULL);
		if (connfd == -1)
		{
			if (errno == EINTR)
			{
				continue;
			}
			else if (errno == EMFILE)
			{
				conn_full = true;
				::close(_reservfd);
			}
			else if (errno == EAGAIN)
			{
				break;
			}
			else
			{
				//exit_log("accept()");
			}
		}
		else if (conn_full)
		{
			//::close(connfd);
			//_reservfd = ::open("/tmp/reactor_accepter", O_CREAT | O_RDONLY | O_CLOEXEC, 0666);
			//error_if(_reservfd == -1, "open()");
		}
		else
		{
			//connfd and max connections
			int curr_conns;
			//get_conn_num(curr_conns);
			if (curr_conns >= _max_conns)
			{
				error_log("connection exceeds the maximum connection count %d", _max_conns);
				::close(connfd);
			}
			else
			{
				assert(connfd < _conns_size);
				if (_keepalive)
				{
					int opend = 1;
					int ret = ::setsockopt(connfd, SOL_SOCKET, SO_KEEPALIVE, &opend, sizeof(opend));
					error_if(ret < 0, "setsockopt SO_KEEPALIVE");
				}

				//multi-thread reactor model: round-robin a event loop and give message to it
				if (_thd_pool)
				{
					thread_queue<queue_msg>* cq = _thd_pool->get_next_thread();
					queue_msg msg;
					msg.cmd_type = queue_msg::NEW_CONN;
					msg.connfd = connfd;
					cq->send_msg(msg);
				}
				else//register in self thread
				{
					tcp_conn* conn = conns[connfd];
					if (conn)
					{
						conn->init(connfd, _loop);
					}
					else
					{
						conn = new tcp_conn(connfd, _loop);
						exit_if(conn == NULL, "new tcp_conn");
						conns[connfd] = conn;
					}
				}
			}
		}
	}

*/


}

void TcpServer::handle_read(int fd)
{
	int nfds;
	char buff[MAXLINE];
	memset(buff, 0, MAXLINE);
	recv(fd, buff, MAXLINE, 0);
	std::cout << "recv msg from client:" << buff << std::endl;

}

TcpServer::~TcpServer() {
	// TODO Auto-generated destructor stub
}

}
