#include "bluelockmain.h"
#include <QTime>
#include <QFile>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <QtDebug>
#include <QApplication>

void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& message)
{
    (void)(context);
    QString txt;
    QTime time;
    std::cout << message.toStdString() << std::endl;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug - %1: %2").arg(time.currentTime().toString()).arg(message);
        break;
    case QtWarningMsg:
        txt = QString("Warning - %1: %2").arg(time.currentTime().toString()).arg(message);
        break;
    case QtCriticalMsg:
        txt = QString("Critical - %1: %2").arg(time.currentTime().toString()).arg(message);
        break;
    case QtFatalMsg:
        txt = QString("Fatal - %1: %2").arg(time.currentTime().toString()).arg(message);
        abort();
    }
    QFile outFile("bluelock_log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}


int main(int argc, char *argv[])
{
    qInstallMessageHandler(customMessageHandler);
    QApplication a(argc, argv);
    BluelockMain w;
    w.show();

    return a.exec();
}
