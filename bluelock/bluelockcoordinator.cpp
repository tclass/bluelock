#include "bluelockcoordinator.h"

LockerCoordinator::LockerCoordinator(QObject *parent) : QObject(parent)
{
    // We have to decide if we are on windows or linux
    // for now the linux locker just implements the gnome commands
    locker = std::shared_ptr<BluelockIF>(new BluelockLinux());
}
void LockerCoordinator::receive(int code){
    switch(code){

    case BluelockIF::LOCK:          locker->lock(); break;
    case BluelockIF::UNLOCK:        locker->unlock(); break;
    case BluelockIF::SHUTDOWN:      locker->shutdown(); break;
    case BluelockIF::SHUTDOWN_TIME: locker->shutdown(); break; //TODO: implement timed shutdown
    }
}

LockerCoordinator::~LockerCoordinator(){

}
