#include "bluelockwindows.h"

BluelockWindows::BluelockWindows(QObject *parent) :QObject(parent)
{
}

void BluelockWindows::unlock()
{
    qDebug() << "not implemented yet";
}

void BluelockWindows::lock()
{
    qDebug() << "not implemented yet";
}

void BluelockWindows::shutdown()
{
    qDebug() << "not implemented yet";
}

int BluelockWindows::getStatus()
{
    return BluelockIF::NONE;
}
