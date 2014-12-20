#ifndef LOCKERCOORDINATOR_H
#define LOCKERCOORDINATOR_H

#include <QObject>
#include <lockerif.h>
#include <lockerlinux.h>
#include <bluelockserver.h>
#include <qtimer.h>

class LockerCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit LockerCoordinator(BluelockServer *server, QObject *parent = 0);
LockerIF *locker;
private:

    BluelockServer *blueServer;
    QTimer *timer;
    void activateTimer();
signals:
    void timeout();
public slots:
    void kickOffDiscovery();
};

#endif // LOCKERCOORDINATOR_H
