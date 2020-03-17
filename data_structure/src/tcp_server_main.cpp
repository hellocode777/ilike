#include <iostream>
#include "tcp_server/TcpServer.h"
#include "tcp_server/ThreadPool.h"

using namespace std;

void *process(void *arg)
{

	int *i = (int *)arg;
	cout << "thread==============================================: " <<  (unsigned int)pthread_self() << "on task: "<< *i  << endl;
	sleep(1);
	cout <<  "task=====================================================: "<< *i   << "is end" << endl;

	return NULL;
}


int main(int argc, char** argv)
{
	//TcpServer  tcp_server;
	//std::cout << __LINE__<< std::endl;
	//tcp_server.do_receiveMsg();

	ThreadPool *thp1 = new ThreadPool;
	ThreadPool *thp = thp1->threadPool_create(3, 100, 100);
	cout <<  "pool inited!" << endl;

	int num[20], i;
	for (i = 0; i < 20; i++)
	{
		num[i] = i;
		cout <<  "add task!" << endl;
		thp1->threadpool_add(thp, process, (void*)&num[i]);
	}
	sleep(10);
	thp->threadpool_destroy(thp);
	return 0;



    return 0;
}
