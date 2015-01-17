#ifndef LOCKERLINUX_H
#define LOCKERLINUX_H

#include <QObject>
#include <bluelockif.h>
#include <QProcess>

class BluelockLinux : public QObject, public BluelockIF
{
    Q_OBJECT
public:
    explicit BluelockLinux(QObject *parent = 0);
    virtual void unlock();
    virtual void lock();
    virtual void shutdown();
    virtual int getStatus();

private:
    void afterCall(short code);
    int status=-1;
    QProcess system;

signals:

public slots:
};

#endif // LOCKERLINUX_H
