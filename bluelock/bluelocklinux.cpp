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
    QStringList arguments;
    arguments << "-h" << "now";
    system.execute("shutdown", arguments);
    afterCall(protocol::SHUTDOWN);
}

void BluelockLinux::shutdown_time(int time){
    QStringList arguments;
    arguments << "-h" << "-t" << QString(time);
    system.execute("shutdown", arguments);
    afterCall(protocol::SHUTDOWN_TIME);
}

int BluelockLinux::getStatus()
{
    return status;
}
