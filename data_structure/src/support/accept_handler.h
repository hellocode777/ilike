#ifndef ACCEPT_HANDLER_H
#define ACCEPT_HANDLER_H

#include "event_handler.h"


class Accept_handler : public Event_handler 
{
public:
    void handle_event() override;
    void get_handle() override;

};


#endif