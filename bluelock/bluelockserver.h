#ifndef BLUELOCKSERVER_H
#define BLUELOCKSERVER_H

#include <QObject>
#include <QString>
#include <QHash>
#include <qbluetoothservicediscoveryagent.h>

static const QString serviceUuid(QStringLiteral("Bluelock 1.0"));

class BluelockServer : public QObject
{
    Q_OBJECT
public:
    explicit BluelockServer(QObject *parent = 0);
    void startDiscover();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = NULL;
    QHash<QString,QString> devices;

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo&);
    void error(QBluetoothDeviceDiscoveryAgent::Error);
    void finished();
    void discoverdDevices(QHash<QString,QString>);

public slots:
    void addDevice(const QBluetoothDeviceInfo& device);
    void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void scanFinished();

};

#endif // BLUETOOTHSERVER_H