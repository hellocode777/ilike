/*
 * eventloop.h
 *
 *  Created on: 2020-3-30
 *      Author: shuai
 */

#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include "event_base.h"
#include <sys/epoll.h>
#include <iostream>
#include <assert.h>
#include <map>


namespace my_tcp_server {

#define MAXEVENTS 10

class event_loop {
public:
    event_loop();
    void process_evs();

    //operator for IO event
    void add_ioev(int fd, io_callback* proc, int mask, void* args = NULL);

	virtual ~event_loop();
private:
	int _iEpollFd;
	struct epoll_event _fired_evs[MAXEVENTS];

    std::map<int, io_event> _io_evs;
    typedef std::map<int, io_event>::iterator ioev_it;
};

} /* namespace my_tcp_server */
#endif /* EVENTLOOP_H_ */
