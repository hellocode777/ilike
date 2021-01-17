#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H


enum Event_Type
{
    ACCEPT_EVENT = 1,
    READ_EVENT = 2
};

class Event_handler
{
public:
    Event_handler() {}
    ~Event_handler() {}
    virtual void handle_event() = 0;
    virtual void get_handle() = 0;

    int itsFd = 0;
};


#endif