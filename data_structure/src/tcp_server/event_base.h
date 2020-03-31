#ifndef __EVENT_BASE_H__
#define __EVENT_BASE_H__

#include <stdint.h>
#include <stdio.h>//NULL
namespace my_tcp_server {
class event_loop;

typedef void io_callback(event_loop* loop, int fd, void *args);//IO事件回调函数

struct io_event//注册的IO事件
{
    io_event(): read_cb(NULL), write_cb(NULL), rcb_args(NULL), wcb_args(NULL) { }
    int mask;               //EPOLLIN EPOLLOUT
    io_callback* read_cb;  //callback when EPOLLIN comming
    io_callback* write_cb; //callback when EPOLLOUT comming
    void* rcb_args;   //extra arguments for read_cb
    void* wcb_args;  //extra arguments for write_cb
};
}



#endif
