#ifndef LOCKERIF_H
#define LOCKERIF_H

class LockerIF
{
public:
    virtual void lock()=0;
    virtual void unlock()=0;
    virtual void shutdown()=0;
    virtual int getStatus()=0;
};

#endif // LOCKERIF_H
