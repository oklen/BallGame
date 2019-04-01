#include "gamemanger.h"
#include <QApplication>
#include "testboard.h"
#include "globalcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GlobalControl globalContorl;
//    gmr.mainWindow.showFullScreen();
//    w.show();

//    TestBoard testBoard;
//    testBoard.show();
    return a.exec();
}
