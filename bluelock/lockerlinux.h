#ifndef LOCKERLINUX_H
#define LOCKERLINUX_H

#include <QObject>
#include <lockerif.h>
#include <QProcess>

class LockerLinux : public QObject, public LockerIF
{
    Q_OBJECT
public:
    explicit LockerLinux(QObject *parent = 0);
    virtual void unlock();
    virtual void lock();
    virtual void shutdown();
    virtual int getStatus();

private:
    int status=-1;
    QProcess *system;

signals:

public slots:
};

#endif // LOCKERLINUX_H
