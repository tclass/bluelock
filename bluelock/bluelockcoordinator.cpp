#include "bluelockcoordinator.h"

LockerCoordinator::LockerCoordinator(QObject *parent) : QObject(parent)
{
    locker = new BluelockLinux();
}
void LockerCoordinator::receive(int code){
    switch(code){

    case BluelockIF::LOCK:          locker->lock(); break;
    case BluelockIF::UNLOCK:        locker->unlock(); break;
    case BluelockIF::SHUTDOWN:      locker->shutdown(); break;
    case BluelockIF::SHUTDOWN_TIME: locker->shutdown(); break;
    }
}

LockerCoordinator::~LockerCoordinator(){

}
