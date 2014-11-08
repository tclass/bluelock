#include "bluelockmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BluelockMain w;
    w.show();

    return a.exec();
}
