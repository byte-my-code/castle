#ifndef EVENT_INCLUDED_H
#define EVENT_INCLUDED_H


enum EVENT_TYPE {
    KEY_PRESS      =  1,
    KEY_RELEASE    =  2,
    MOUSE_MOVE     =  4,
    MOUSE_BUTTON   =  8,
    WINDOW_EVENT   = 16,

};

/* Base Event Type.
 * Override this with concrete event types
 */
class Event {

    public:

        Event();
        virtual ~Event();

#ifdef DEBUG_BUILD
        virtual char *name();
#endif

        virtual EVENT_TYPE type();

        virtual void* data();
};

#endif // EVENT_INCLUDED_H 
