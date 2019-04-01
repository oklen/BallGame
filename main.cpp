#include "gamemanger.h"
#include <QApplication>
#include "testboard.h"
#include "globalcontrol.h"
#include "Widgets/controlbutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    GlobalControl globalContorl;

    ControlButton cb;
    cb.show();
//    gmr.mainWindow.showFullScreen();
//    w.show();

//    TestBoard testBoard;
//    testBoard.show();
    return a.exec();
}
