#include <iostream>
#include "tcp_client/TcpClient.h"
using namespace std;

int main(int argc, char** argv)
{
	TcpClient  tcp_client;
	tcp_client.do_connet();
	tcp_client.do_send_msg();
    return 0;
}
