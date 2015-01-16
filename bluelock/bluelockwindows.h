#ifndef BLUELOCKWINDOWS_H
#define BLUELOCKWINDOWS_H

#include <QObject>
#include <QDebug>
#include <bluelockif.h>

class BluelockWindows : public QObject,BluelockIF
{
    Q_OBJECT
public:
    explicit BluelockWindows(QObject *parent = 0);
    virtual void unlock();
    virtual void lock();
    virtual void shutdown();
    virtual int getStatus();

signals:

public slots:

};

#endif // BLUELOCKWINDOWS_H
