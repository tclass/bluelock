#include "bluelockservice.h"

BluelockService::BluelockService(QObject *parent) : QObject(parent){
}

void BluelockService::startService(){

    server = std::unique_ptr<QBluetoothServer>(new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol,this));
    service = server->listen(uuid,serviceName);

    qDebug() << "UUID: "+service.serviceUuid().toString();
    qDebug() << "Local Device: "+localDevice.name();
    qDebug() << "Address: "+localDevice.address().toString();

    connect(server.get(),SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

void BluelockService::acceptConnection(){
    socket = std::unique_ptr<QBluetoothSocket>(server->nextPendingConnection());
    connect(socket.get(),SIGNAL(readyRead()),this,SLOT(readNextData()));
}

void BluelockService::readNextData(){
    QByteArray rawMessage = socket->readAll();
    QString message(rawMessage);
    qDebug() << "Message: "+message;
    emit notify(message.toInt());
}

BluelockService::~BluelockService()
{
}

