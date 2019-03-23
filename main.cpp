#include "widget.h"
#include <QApplication>
#include "testboard.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    TestBoard testBoard;
    testBoard.show();
    return a.exec();
}
