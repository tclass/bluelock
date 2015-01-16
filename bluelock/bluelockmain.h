#ifndef BLUELOCKMAIN_H
#define BLUELOCKMAIN_H

#include <QMainWindow>
#include <QString>
#include <bluelockserver.h>
#include <lockercoordinator.h>
#include <bluelockserviceconnector.h>
#include <qdebug.h>
#include <bluelockservice.h>

namespace Ui {

class BluelockMain;
}

class BluelockMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit BluelockMain(QWidget *parent = 0);
    ~BluelockMain();

public slots:
    void updateDevices(QHash<QString,QBluetoothAddress> foundDevices);

private slots:
    void on_deviceBtn_clicked();

    void on_deviceConnectButton_clicked();

private:
    QHash<QString,QBluetoothAddress> devices;
    Ui::BluelockMain *ui;
    BluelockServer *bluelockServer = NULL;
    BluelockService *bluelockservice = NULL;
    BluelockServiceConnector *bluelockServiceConnector = NULL;
    LockerCoordinator *lockerCoordinator = NULL;
    void setupServices();
};

#endif // BLUELOCKMAIN_H
