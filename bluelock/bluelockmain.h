#ifndef BLUELOCKMAIN_H
#define BLUELOCKMAIN_H

#include <QMainWindow>
#include <QString>
#include <bluelockcoordinator.h>
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

private:
    std::unique_ptr<Ui::BluelockMain> ui;
    BluelockService bluelockservice;
    LockerCoordinator lockerCoordinator;
    void setupServices();
};

#endif // BLUELOCKMAIN_H
