#include <iostream>
#include "tcp_server/TcpServer.h"
#include "tcp_server/event_loop.h"
#include "tcp_server/ThreadPool.h"

using namespace std;

void *process(void *arg)
{

	int *i = (int *)arg;
	cout << "thread==============================================: " <<  (unsigned int)pthread_self() << "on task: "<< *i  << endl;
	sleep(4);
	cout <<  "task=====================================================: "<< *i   << "is end" << endl;

	return NULL;
}


int main(int argc, char** argv)
{
	my_tcp_server::event_loop *loop = new my_tcp_server::event_loop;
	my_tcp_server::TcpServer  tcp_server(loop);
	loop->process_evs();
	std::cout << __LINE__<< std::endl;
	//tcp_server.do_receiveMsg();
	/*
	ThreadPool *thp = new ThreadPool(3, 100, 100);
	cout <<  "pool inited!" << endl;

	int num[5], i;
	for (i = 0; i < 5; i++)
	{
		num[i] = i;
		cout <<  "add task!" << endl;

		thp->threadpool_add(process, (void*)&num[i]);
		sleep(10);
	}
	sleep(10);
	for (i = 0; i < 5; i++)
	{
		num[i] = i;
		cout <<  "add task!" << endl;

		thp->threadpool_add(process, (void*)&num[i]);
		sleep(10);
	}
	//thp->threadpool_destroy(thp);

	delete thp;
	thp = NULL;
	*/
	return 0;

}
