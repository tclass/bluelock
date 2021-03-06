#ifndef LOCKERIF_H
#define LOCKERIF_H

class BluelockIF
{

public:
    virtual void lock()=0;
    virtual void unlock()=0;
    virtual void shutdown()=0;
    virtual void shutdown_time(int time)=0;
    virtual int getStatus()=0;

    enum protocol {
        NONE = 0,
        ERROR = -1,
        LOCK = 1,
        UNLOCK = 2,
        SHUTDOWN = 3,
        SHUTDOWN_TIME = 4,
    };
};

#endif // LOCKERIF_H
