#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include "widget.h"
#include <QTimer>
#include <unordered_set>
#include "player.h"
#include "mainwindow.h"

constexpr static float time_span = 0.05;
constexpr static float Bound_loss = 0.97;

class GameManger:public QObject
{
public:
    GameManger(Board* child);
    void start();
    void nextRound();
    void calScore();
    void calFalls();

private:
    QTimer timer;
    int score_playe1r=0,score_player2=0;
    Board* board;
    MainWindow mainWindow;

    int who = 1;
    Player players[2];
    bool someOneMove = false;
    bool pushTheBall = false;
    mutable std::vector<std::pair<Ball*,Ball*>> Col_Order;

    std::vector<Ball*> falls;
    Ball* firstCol = nullptr;

    void clearBalls();
public slots:
    void calMove();
    bool preciseDetectionCol(Ball& a,Ball& b) const;
};

#endif // GAMEMANGER_H
