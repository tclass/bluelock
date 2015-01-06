#include "bluelockserver.h"

BluelockServer::BluelockServer(QObject *parent) :
    QObject(parent)
{

    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    connect(discoveryAgent, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo&)),this, SLOT(addDevice(const QBluetoothDeviceInfo&)));
    connect(discoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),this, SLOT(deviceScanError(QBluetoothDeviceDiscoveryAgent::Error)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));

}

void BluelockServer::startDiscover(){
    discoveryAgent->start();
    qDebug() << "start discovery";
}

void BluelockServer::addDevice(const QBluetoothDeviceInfo& device){

    if (!devices.contains(device.address().toString()) /*&& device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration*/) {
        devices.insert(device.name(),device.address());
        qWarning() << "Discovered LE Device name: " << device.name() << " Address: " << device.address().toString();
    }

}

void BluelockServer::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error){
    qWarning() << error;
}

void BluelockServer::scanFinished(){

    qDebug() << "scan finished";
    qDebug() << devices.size();
    emit discoverdDevices(devices);
    devices.clear();
}



