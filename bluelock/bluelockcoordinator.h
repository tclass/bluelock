#ifndef LOCKERCOORDINATOR_H
#define LOCKERCOORDINATOR_H

#include <QObject>
#include <bluelockif.h>
#include <bluelocklinux.h>

class LockerCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit LockerCoordinator(QObject *parent = 0);
    BluelockIF *locker;
    ~LockerCoordinator();

public slots:
    void receive(int code);
};

#endif // LOCKERCOORDINATOR_H
