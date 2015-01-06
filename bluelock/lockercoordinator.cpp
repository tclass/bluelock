#include "lockercoordinator.h"

LockerCoordinator::LockerCoordinator(BluelockServer *server, QObject *parent) : QObject(parent)
{
    blueServer = server;
    locker = new LockerLinux();
    activateTimer();
}
void LockerCoordinator::activateTimer(){
   // timer = new QTimer(this);
   // connect(timer, SIGNAL(timeout()), this, SLOT(kickOffDiscovery()));
   // timer->start(20000); //time specified in ms
}

void LockerCoordinator::kickOffDiscovery(){
    blueServer->startDiscover();
}
