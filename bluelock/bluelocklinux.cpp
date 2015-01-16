#include "bluelocklinux.h"


BluelockLinux::BluelockLinux(QObject *parent) : QObject(parent)
{
}

void BluelockLinux::unlock()
{
    system.start("gnome-screensaver-command --deactivate");
    system.closeWriteChannel();
    status = BluelockIF::protocol::UNLOCK;
}

void BluelockLinux::lock()
{

    system.start("gnome-screensaver-command --lock");
    system.closeWriteChannel();
    status = BluelockIF::protocol::LOCK;
}

void BluelockLinux::shutdown()
{
    system.start("shutdown -h");
    system.closeWriteChannel();
    status = BluelockIF::protocol::SHUTDOWN;
}

int BluelockLinux::getStatus()
{
    return status;
}
