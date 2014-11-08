#ifndef LOCKERCOORDINATOR_H
#define LOCKERCOORDINATOR_H

#include <QObject>
#include <lockerif.h>

class LockerCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit LockerCoordinator(QObject *parent = 0);

private:
    LockerIF *locker;



signals:

public slots:

};

#endif // LOCKERCOORDINATOR_H
