#ifndef LOCKERLINUX_H
#define LOCKERLINUX_H

#include <QObject>
#include <lockerif.h>

class LockerLinux : public QObject,LockerIF
{
    Q_OBJECT
public:
    explicit LockerLinux(QObject *parent = 0);
    virtual bool unlock();
    virtual bool lock();
    virtual int getStatus();

signals:

public slots:

};

#endif // LOCKERLINUX_H
