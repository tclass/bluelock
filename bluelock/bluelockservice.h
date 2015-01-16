#ifndef BLUELOCKSERVICE_H
#define BLUELOCKSERVICE_H

#include <QObject>
#include <QBluetoothServer>
#include <qdebug.h>
#include <QBluetoothLocalDevice>
#include <lockerlinux.h>

class BluelockService : public QObject
{
    Q_OBJECT
public:
    explicit BluelockService(QObject *parent = 0);
    ~BluelockService();
    void startService();
signals:
    void notify(int);

public slots:
    void acceptConnection();
    void readNextData();

private:
    QBluetoothSocket *socket = NULL;
    QBluetoothServer *server;

    LockerLinux ll;
    QBluetoothServiceInfo service;
    QBluetoothLocalDevice localDevice;

    const QBluetoothUuid uuid = QBluetoothUuid(QBluetoothUuid::HumanInterfaceDeviceService);
    const QString serviceName = QString("BLUELOCK");

signals:
    void newConnection();
    void readyRead();



};

#endif // BLUELOCKSERVICE_H
