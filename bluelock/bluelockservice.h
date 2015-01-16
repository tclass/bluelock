#ifndef BLUELOCKSERVICE_H
#define BLUELOCKSERVICE_H

#include <QObject>
#include <QBluetoothServer>
#include <qdebug.h>
#include <QBluetoothLocalDevice>

class BluelockService : public QObject
{
    Q_OBJECT
public:
    explicit BluelockService(QObject *parent = 0);
    ~BluelockService();

private:
    QBluetoothSocket *socket = NULL;
    QBluetoothServer *server = NULL;
    QBluetoothUuid *uuid = NULL;
    QString *serviceName = new QString("BLUELOCK");
    QBluetoothServiceInfo  service;
    QBluetoothLocalDevice localDevice;

signals:
    void newConnection();
    void readyRead();

public slots:
    void acceptConnection();
    void readNextData();
};

#endif // BLUELOCKSERVICE_H
