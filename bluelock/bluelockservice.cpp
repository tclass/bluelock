#include "bluelockservice.h"

BluelockService::BluelockService(QObject *parent) : QObject(parent){
}

void BluelockService::startService(){

    server = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol,this);
    service = server->listen(uuid,serviceName);

    qDebug() << "UUID: "+service.serviceUuid().toString();
    qDebug() << "Local Device: "+localDevice.name();
    qDebug() << "Address: "+localDevice.address().toString();

    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

void BluelockService::acceptConnection(){
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readNextData()));
}

void BluelockService::readNextData(){
    QByteArray rawMessage = socket->readAll();
    QString message(rawMessage);
    qDebug() << "Message: "+message;
    emit notify(message.toInt());
}

BluelockService::~BluelockService()
{
    if(socket != NULL)
        delete socket;
}

