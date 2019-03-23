#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include "widget.h"
#include <QTimer>

class GameManger:public QObject
{
    constexpr static float time_span = 0.1;
public:
    GameManger(MainWindow* child);
    void start();
private:
    QTimer timer;
    int score_playe1r=0,score_player2=0;
    MainWindow* board;
public slots:
    void calMove();
};

#endif // GAMEMANGER_H
