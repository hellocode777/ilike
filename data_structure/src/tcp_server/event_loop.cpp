/*
 * eventloop.cpp
 *
 *  Created on: 2020-3-30
 *      Author: shuai
 */

#include "event_loop.h"

namespace my_tcp_server {

event_loop::event_loop() {
	// TODO Auto-generated constructor stub
	_iEpollFd = ::epoll_create1(0);

}

/*
 * if EPOLLIN in mask, EPOLLOUT must not in mask;
 * if EPOLLOUT in mask, EPOLLIN must not in mask;
 * if want to register EPOLLOUT | EPOLLIN event, just call add_ioev twice!
 */
void event_loop::add_ioev(int fd, io_callback* proc, int mask, void* args)
{
    int f_mask = 0;//finial mask
    int op;
    ioev_it it = _io_evs.find(fd);
    if (it == _io_evs.end())
    {
        f_mask = mask;
        op = EPOLL_CTL_ADD;
    }
    else
    {
        f_mask = it->second.mask | mask;
        op = EPOLL_CTL_MOD;
    }
    if (mask & EPOLLIN)
    {
        _io_evs[fd].read_cb = proc;
        _io_evs[fd].rcb_args = args;
    }
    else if (mask & EPOLLOUT)
    {
        _io_evs[fd].write_cb = proc;
        _io_evs[fd].wcb_args = args;
    }

    _io_evs[fd].mask = f_mask;
    struct epoll_event event;
    event.events = f_mask;
    event.data.fd = fd;
    int ret = ::epoll_ctl(_iEpollFd, op, fd, &event);

}

void event_loop::process_evs()
{
    while (true)
    {
        //handle file event
        ioev_it it;
        int nfds = ::epoll_wait(_iEpollFd, _fired_evs, MAXEVENTS, 10);
        for (int i = 0; i < nfds; ++i)
        {
            it = _io_evs.find(_fired_evs[i].data.fd);
            assert(it != _io_evs.end());
            io_event* ev = &(it->second);

            std::cout << __FILE__ << " ZZSS =" << _fired_evs[i].events << std::endl;
            if (_fired_evs[i].events & EPOLLIN)
            {
                void *args = ev->rcb_args;
                ev->read_cb(this, _fired_evs[i].data.fd, args);
            }
            else if (_fired_evs[i].events & EPOLLOUT)
            {
                void *args = ev->wcb_args;
                ev->write_cb(this, _fired_evs[i].data.fd, args);
            }
            else if (_fired_evs[i].events & (EPOLLHUP | EPOLLERR))
            {
                if (ev->read_cb)
                {
                    void *args = ev->rcb_args;
                    ev->read_cb(this, _fired_evs[i].data.fd, args);
                }
                else if (ev->write_cb)
                {
                    void *args = ev->wcb_args;
                    ev->write_cb(this, _fired_evs[i].data.fd, args);
                }
                else
                {
                   // error_log("fd %d get error, delete it from epoll", _fired_evs[i].data.fd);
                    //del_ioev(_fired_evs[i].data.fd);
                }
            }
        }
        //run_task();
    }
}



event_loop::~event_loop() {
	// TODO Auto-generated destructor stub
}

} /* namespace my_tcp_server */
