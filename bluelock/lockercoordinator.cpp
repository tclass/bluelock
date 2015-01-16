#include "lockercoordinator.h"

LockerCoordinator::LockerCoordinator(QObject *parent) : QObject(parent)
{
    locker = new LockerLinux();
}
void LockerCoordinator::receive(int code){
    switch(code){

    case LockerIF::LOCK:          locker->lock(); break;
    case LockerIF::UNLOCK:        locker->unlock(); break;
    case LockerIF::SHUTDOWN:      locker->shutdown(); break;
    case LockerIF::SHUTDOWN_TIME: locker->shutdown(); break;
    }
}

LockerCoordinator::~LockerCoordinator(){

}
