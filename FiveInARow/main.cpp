#include "widget.h"
#include <QApplication>
#include <QStringList>
int main(int argc, char *argv[])
{



    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);

    QApplication a(argc, argv);
    a.addLibraryPath(a.applicationDirPath()+"/plugins");
    Widget w;



    //w.setStyleSheet("border-image: url(:/icon/6.jpg)");


    w.setWindowTitle("FiR Pre-Beta 0180104.6");
    w.show();



    return a.exec();
}
