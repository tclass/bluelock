#include "bluelockmain.h"
#include "ui_bluelockmain.h"

BluelockMain::BluelockMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluelockMain)
{
    ui->setupUi(this);
    this->setupServices();
}

BluelockMain::~BluelockMain()
{
    delete ui;
}

void BluelockMain::setupServices()
{
    qDebug() << "Setting up server";
    bluelockServer = new BluelockServer();
    connect(bluelockServer,SIGNAL(discoverdDevices(QHash<QString,QBluetoothAddress>)), this, SLOT(updateDevices(QHash<QString,QBluetoothAddress>)));
    lockerCoordinator = new LockerCoordinator(bluelockServer);
}

void BluelockMain::updateDevices(QHash<QString,QBluetoothAddress> foundDevices){
    devices = foundDevices;
    //Device Strings setten und nicht adden maybe
    if(!devices.empty()){
   // lockerCoordinator->locker->unlock();
    while(ui->deviceCmb->count() > 0){
        ui->deviceCmb->removeItem(0);
    }
     for(QString device : devices.keys()){
            ui->deviceCmb->addItem(device);
        }
    }
    else{
     //   lockerCoordinator->locker->lock();
        while(ui->deviceCmb->count() > 0){
            ui->deviceCmb->removeItem(0);
        }
    }
    ui->deviceCmb->repaint();
}

void BluelockMain::on_deviceBtn_clicked()
{
    bluelockServer->startDiscover();
}

void BluelockMain::on_deviceConnectButton_clicked()
{
    QBluetoothAddress p;
    for(QString device : devices.keys()){
        if(device.compare(ui->deviceCmb->currentText()) == 0){
            p = devices.value(device);
        }
    }
    bluelockServiceConnector->connectToDevice(devices.values().at(0));
}
