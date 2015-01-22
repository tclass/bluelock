#include "bluelockmain.h"
#include "ui_bluelockmain.h"

BluelockMain::BluelockMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BluelockMain)
{
    ui->setupUi(this);
    this->setupServices();
}

void BluelockMain::setupServices()
{
    qDebug() << "Setting up server";
    bluelockservice.startService();
    ui->lblInputAddress->setText(bluelockservice.getLocalAddress());
    ui->lblInputUuid->setText(bluelockservice.getUuid());

    connect(&bluelockservice,&BluelockService::notify,&lockerCoordinator,&LockerCoordinator::receive);
    connect(bluelockservice.server.get(),SIGNAL(newConnection()),this,SLOT(clientConnected()));
    connect ( ui->btnReconnect, SIGNAL( clicked() ), this, SLOT( reconnect() ) );
}

void BluelockMain::reconnect()
{
    bluelockservice.stopService();
    bluelockservice.startService();
    ui->lblInputAddress->setText(bluelockservice.getLocalAddress());
    ui->lblInputUuid->setText(bluelockservice.getUuid());
}

void BluelockMain::clientConnected()
{
    ui->lblInputPeer->setText(bluelockservice.getPeerName());
}

BluelockMain::~BluelockMain()
{
}
