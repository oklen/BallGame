#include "gamemanger.h"
#include <QApplication>
#include "testboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board w;
    GameManger gmr(&w);
//    w.show();

//    TestBoard testBoard;
//    testBoard.show();
    return a.exec();
}
