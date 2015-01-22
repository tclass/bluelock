#include "bluelockservice.h"

BluelockService::BluelockService(QObject *parent) : QObject(parent){
}

void BluelockService::startService(){

    localDevice = std::unique_ptr<QBluetoothLocalDevice>(new QBluetoothLocalDevice());
    server = std::unique_ptr<QBluetoothServer>(new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol,this));
    service = server->listen(uuid,serviceName);

    qDebug() << "UUID: "+service.serviceUuid().toString();
    uuidStr = service.serviceUuid().toString();

    qDebug() << "Local Device: "+localDevice->name();

    qDebug() << "Address: "+localDevice->address().toString();
    localAddress = localDevice->address().toString();

    connect(server.get(),SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    running = true;
}

void BluelockService::stopService(){
    running = false;
    if(socket.get() != NULL){
        socket.get()->close();
        socket.release();
    }
    localDevice.release();
    server->close();
    server.release();
}

QString BluelockService::getLocalAddress()
{
    return localAddress;
}

QString BluelockService::getPeerName()
{
    return peerName;
}

QString BluelockService::getUuid()
{
    return uuidStr;
}

void BluelockService::acceptConnection(){
    socket = std::unique_ptr<QBluetoothSocket>(server->nextPendingConnection());

    qDebug() << "Peer Name: "+socket->peerName();
    peerName = socket->peerName();

    connect(socket.get(),SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    connect(socket.get(),SIGNAL(readyRead()),this,SLOT(readNextData()));
}

void BluelockService::readNextData(){
    QByteArray rawMessage = socket->readAll();
    QString message(rawMessage);

    qDebug() << "Message: "+message;
    qDebug() << "Peer Name: "+socket->peerName();
    peerName = socket->peerName();


    emit notify(message.toInt(),0);
}

void BluelockService::socketDisconnected(){
    if(running){
        qDebug() << "Socket closed for "+socket->peerName();
        emit notify(BluelockIF::protocol::LOCK,0);
    }
}

BluelockService::~BluelockService()
{
}

