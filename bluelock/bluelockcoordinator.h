#ifndef LOCKERCOORDINATOR_H
#define LOCKERCOORDINATOR_H

#include <QObject>
#include <bluelockif.h>
#include <bluelocklinux.h>
#include <memory>

class LockerCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit LockerCoordinator(QObject *parent = 0);
    std::shared_ptr<BluelockIF> locker;
    ~LockerCoordinator();

public slots:
    void receive(int code, int extra);
};

#endif // LOCKERCOORDINATOR_H
