#include "gamemanger.h"
#include <QApplication>
#include "testboard.h"
#include "globalcontrol.h"
#include "Widgets/controlbutton.h"
#include "Widgets/pausemenu.h"
#include "Resouces/gjk_al.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//  GlobalControl globalContorl;
    GJK_Al al;
    al.tester.test1();
    qDebug()  << al.isCol(al.tester.bound,al.tester.ball);
    al.tester.timer.stop();
//      PauseMenu pause;
//      pause.show();
//    ControlButton cb;
//    cb.show();
//    gmr.mainWindow.showFullScreen();
//    w.show();

//    TestBoard testBoard;
//    testBoard.show();
    return a.exec();
}
