#include <iostream>
#include "tcp_server/TcpServer.h"
#include "tcp_server/ThreadPool.h"

using namespace std;

void *process(void *arg)
{
<<<<<<< HEAD
	int *i = (int *)arg;
	cout << "thread==============================================: " <<  (unsigned int)pthread_self() << "on task: "<< *i  << endl;
	sleep(1);
	cout <<  "task=====================================================: "<< *i   << "is end" << endl;
=======
	cout << "thread: " <<  (unsigned int)pthread_self() << "on task: "  << endl;
	sleep(1);
	cout <<  "task: "  << "is end" << endl;
>>>>>>> 3ef46fc021982cad38bdfa8963d5e1125a324f6d
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

<<<<<<< HEAD
	int num[100], i;
	for (i = 0; i < 100; i++)
	{
		num[i] = i;
		cout <<  "add task!num[i]" << num[i] << endl;
		thp1->threadpool_add(thp, process, (void*)&num[i]);
=======
	int num[20], i;
	for (i = 0; i < 20; i++)
	{
		num[i] = i;
		cout <<  "add task!" << endl;
		thp->threadpool_add(thp, process, (void*)&num[i]);
>>>>>>> 3ef46fc021982cad38bdfa8963d5e1125a324f6d
	}
	sleep(10);
	thp->threadpool_destroy(thp);
	return 0;



    return 0;
}
