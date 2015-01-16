#ifndef LOCKERCOORDINATOR_H
#define LOCKERCOORDINATOR_H

#include <QObject>
#include <lockerif.h>
#include <lockerlinux.h>

class LockerCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit LockerCoordinator(QObject *parent = 0);
    LockerIF *locker;
    ~LockerCoordinator();

public slots:
    void receive(int code);
};

#endif // LOCKERCOORDINATOR_H
