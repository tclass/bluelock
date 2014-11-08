#ifndef BLUELOCKMAIN_H
#define BLUELOCKMAIN_H

#include <QMainWindow>

namespace Ui {
class BluelockMain;
}

class BluelockMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit BluelockMain(QWidget *parent = 0);
    ~BluelockMain();

private:
    Ui::BluelockMain *ui;
};

#endif // BLUELOCKMAIN_H
