#include "bluelockservice.h"

BluelockService::BluelockService(QObject *parent) : QObject(parent)
{
    uuid = new QBluetoothUuid(uuid->HumanInterfaceDeviceService);


    server = new QBluetoothServer(service.RfcommProtocol,this);
    service = server->listen(*uuid,*serviceName);

    qDebug() << "UUID"+service.serviceUuid().toString();
    qDebug() << localDevice.name();
    qDebug() << localDevice.address().toString();
    qDebug() << server->serverAddress().toString();


    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}


void BluelockService::acceptConnection(){
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readNextData()));
}

void BluelockService::readNextData(){
    QByteArray byteArray = socket->readAll();
    QString as(byteArray);
    qDebug() << as << "  ";
}

BluelockService::~BluelockService()
{

}

