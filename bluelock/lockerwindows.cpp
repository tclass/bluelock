#include "lockerwindows.h"

LockerWindows::LockerWindows(QObject *parent) :
    QObject(parent)
{
}

void LockerWindows::unlock()
{

}

void LockerWindows::lock()
{
}

void LockerWindows::shutdown()
{

}

int LockerWindows::getStatus()
{
    return 1;
}
