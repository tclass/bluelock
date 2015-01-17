#include "bluelocklinux.h"


BluelockLinux::BluelockLinux(QObject *parent) : QObject(parent)
{
}

void BluelockLinux::afterCall(short code){
    system.closeWriteChannel();
    status = code;
}

void BluelockLinux::unlock()
{
    system.start("gnome-screensaver-command --deactivate");
    afterCall(protocol::UNLOCK);
}

void BluelockLinux::lock()
{

    system.start("gnome-screensaver-command --lock");
    afterCall(protocol::LOCK);
}

void BluelockLinux::shutdown()
{
    system.start("shutdown -h");
    afterCall(protocol::SHUTDOWN);
}

int BluelockLinux::getStatus()
{
    return status;
}
