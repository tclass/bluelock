#ifndef BLUELOCKSERVICECONNECTOR_H
#define BLUELOCKSERVICECONNECTOR_H

#include <QLowEnergyController>
#include <QBluetoothDeviceInfo>
#include <QBluetoothAddress>
#include <QObject>

class BluelockServiceConnector : public QObject
{
    Q_OBJECT
public:
    explicit BluelockServiceConnector(QObject *parent = 0);
    void connectToDevice(QBluetoothAddress);
    ~BluelockServiceConnector();

signals:
    void discoveryFinished();
    void error(QLowEnergyController::Error);
    void connected();
    void disconnected();

private:
    QLowEnergyController *blueCtr = NULL;
private slots:
    //QLowEnergyController
    void serviceDiscovered(const QBluetoothUuid &);
    void serviceScanDone();
    void controllerError(QLowEnergyController::Error);
    void deviceConnected();
    void deviceDisconnected();
};

#endif // BLUELOCKSERVICECONNECTOR_H
