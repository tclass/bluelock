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
    connect(bluelockServer,SIGNAL(discoverdDevices(QHash<QString,QString>)), this, SLOT(updateDevices(QHash<QString,QString>)));
    bluelockServer->startDiscover();
    lockerCoordinator = new LockerCoordinator();
}

void BluelockMain::updateDevices(QHash<QString,QString> devices){
    //Device Strings setten und nicht adden maybe
    if(!devices.empty()){
        for(QString device : devices.values()){
            ui->deviceCmb->addItem(device);
        }
    }
    else{
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
