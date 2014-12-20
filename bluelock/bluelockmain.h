#ifndef BLUELOCKMAIN_H
#define BLUELOCKMAIN_H

#include <QMainWindow>
#include <QString>
#include <bluelockserver.h>
#include <lockercoordinator.h>
#include <qdebug.h>
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
    void updateDevices(QHash<QString,QString> devices);

private slots:
    void on_deviceBtn_clicked();

private:
    Ui::BluelockMain *ui;
    BluelockServer *bluelockServer = NULL;
    LockerCoordinator *lockerCoordinator = NULL;
    void setupServices();
};

#endif // BLUELOCKMAIN_H
