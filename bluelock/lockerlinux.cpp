#include "lockerlinux.h"

LockerLinux::LockerLinux(QObject *parent) :
    QObject(parent)
{
}

bool LockerLinux::unlock()
{
return false;
}

bool LockerLinux::lock()
{
return false;
}

int LockerLinux::getStatus()
{
    return 1;
}
