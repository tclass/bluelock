#include "lockerwindows.h"

LockerWindows::LockerWindows(QObject *parent) :
    QObject(parent)
{
}

bool LockerWindows::unlock()
{
    return false;
}

bool LockerWindows::lock()
{
    return false;
}

void LockerWindows::shutdown()
{
    return;
}

int LockerWindows::getStatus()
{
    return 1;
}
