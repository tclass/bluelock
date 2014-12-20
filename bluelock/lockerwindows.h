#ifndef LOCKERWINDOWS_H
#define LOCKERWINDOWS_H

#include <QObject>
#include <lockerif.h>

class LockerWindows : public QObject,LockerIF
{
    Q_OBJECT
public:
    explicit LockerWindows(QObject *parent = 0);
    virtual bool unlock();
    virtual bool lock();
    virtual void shutdown();
    virtual int getStatus();

signals:

public slots:

};

#endif // LOCKERWINDOWS_H
