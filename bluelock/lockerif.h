#ifndef LOCKERIF_H
#define LOCKERIF_H

class LockerIF
{
public:
    virtual bool lock()=0;
    virtual bool unlock()=0;
    virtual int getStatus()=0;
};

#endif // LOCKERIF_H
