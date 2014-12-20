#include "lockerlinux.h"


LockerLinux::LockerLinux(QObject *parent) :
    QObject(parent)
{
    system = new QProcess();
}

void LockerLinux::unlock()
{
    system->start("gnome-screensaver-command --deactivate");
    system->closeWriteChannel();
    status = 0;
}

void LockerLinux::lock()
{

    system->start("gnome-screensaver-command --lock");
    system->closeWriteChannel();
    status = 1;
}

void LockerLinux::shutdown()
{
    system->start("shutdown -h");
    system->closeWriteChannel();
    status = 3;
}

int LockerLinux::getStatus()
{
    return status;
}
