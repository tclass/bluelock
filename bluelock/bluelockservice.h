#ifndef BLUELOCKSERVICE_H
#define BLUELOCKSERVICE_H

#include <QObject>
#include <QBluetoothServer>
#include <qdebug.h>
#include <QBluetoothLocalDevice>
#include <bluelocklinux.h>
#include <memory>

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
    std::unique_ptr<QBluetoothSocket> socket = NULL;
    std::unique_ptr<QBluetoothServer> server;

    BluelockLinux ll;
    QBluetoothServiceInfo service;
    QBluetoothLocalDevice localDevice;

    const QBluetoothUuid uuid = QBluetoothUuid(QBluetoothUuid::HumanInterfaceDeviceService);
    const QString serviceName = QStringLiteral("BLUELOCK");

signals:
    void newConnection();
    void readyRead();



};

#endif // BLUELOCKSERVICE_H
