#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Widget w;

    //w.setStyleSheet("border-image: url(:/icon/6.jpg)");


    w.setWindowTitle("FiR Pre-Beta 0180102.1");
    w.show();

    return a.exec();
}
