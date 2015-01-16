#ifndef LOCKERIF_H
#define LOCKERIF_H

class LockerIF
{



public:
    virtual void lock()=0;
    virtual void unlock()=0;
    virtual void shutdown()=0;
    virtual int getStatus()=0;

    enum protocol {
       LOCK = 1,
       UNLOCK = 2,
       SHUTDOWN = 3,
       SHUTDOWN_TIME = 4,
       NONE = 0,
       ERROR = -1
       };
};

#endif // LOCKERIF_H
