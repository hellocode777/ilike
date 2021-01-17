#ifndef READ_HANDLER_H
#define READ_HANDLER_H
#include "event_handler.h"

class Read_handler : public Event_handler
{
public:
    void handle_event() override;
    void get_handle() override;
};


#endif