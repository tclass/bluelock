#include "bluelockserviceconnector.h"

BluelockServiceConnector::BluelockServiceConnector(QObject *parent) : QObject(parent)
{

}



// Connecting to specific device
void BluelockServiceConnector::connectToDevice(QBluetoothAddress address){
   blueCtr = new QLowEnergyController(address);
   blueCtr->connectToDevice();

   connect(blueCtr, SIGNAL(serviceDiscovered(QBluetoothUuid)),this, SLOT(serviceDiscovered(QBluetoothUuid)));

   connect(blueCtr, SIGNAL(discoveryFinished()),this, SLOT(serviceScanDone()));

   connect(blueCtr, SIGNAL(error(QLowEnergyController::Error)),this, SLOT(controllerError(QLowEnergyController::Error)));

   connect(blueCtr, SIGNAL(connected()),this, SLOT(deviceConnected()));

   connect(blueCtr, SIGNAL(disconnected()),this, SLOT(deviceDisconnected()));
}

void BluelockServiceConnector::serviceDiscovered(const QBluetoothUuid &gatt){
    qDebug() << gatt;
}

void BluelockServiceConnector::serviceScanDone(){

}

void BluelockServiceConnector::controllerError(QLowEnergyController::Error error){

}

void BluelockServiceConnector::deviceConnected(){
    qDebug() << "Device connected!";
}

void BluelockServiceConnector::deviceDisconnected(){
    qDebug() << "Device disssss!";
}

BluelockServiceConnector::~BluelockServiceConnector()
{

}

