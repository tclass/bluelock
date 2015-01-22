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
    void stopService();

    std::unique_ptr<QBluetoothServer> server = NULL;

    QString getLocalAddress();
    QString getPeerName();
    QString getUuid();

signals:
    void notify(int,int);
    void disconnect();

public slots:
    void acceptConnection();
    void readNextData();
    void socketDisconnected();

private:
    std::unique_ptr<QBluetoothSocket> socket = NULL;
    std::unique_ptr<QBluetoothLocalDevice> localDevice = NULL;

    BluelockLinux ll;
    QBluetoothServiceInfo service;

    QString localAddress;
    QString peerName;
    QString uuidStr;

    bool running = false;

    const QBluetoothUuid uuid = QBluetoothUuid(QBluetoothUuid::HumanInterfaceDeviceService);
    const QString serviceName = QStringLiteral("BLUELOCK");

signals:
    void newConnection();
    void readyRead();



};

#endif // BLUELOCKSERVICE_H
