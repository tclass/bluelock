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
    bluelockservice.startService();
    connect(&bluelockservice,&BluelockService::notify,&lockerCoordinator,&LockerCoordinator::receive);
}
