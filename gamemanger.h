#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include "widget.h"
#include <QTimer>
#include <unordered_set>
#include "player.h"
#include "mainwindow.h"

constexpr static float time_span = 0.05;
constexpr static float Bound_loss = 0.97;

class GameWorker:public QObject
{
    Q_OBJECT
public:
    GameWorker(Board* child);
    void start();
//    void nextRound();

    void calFalls();
    void MoveBackBall();
    void clearBalls();
    MainWindow mainWindow;

    mutable std::vector<std::pair<Ball*,Ball*>> Col_Order;
    std::vector<Ball*> falls;

    Board* board;
    Player players[2];

    int score_playe1r=0,score_player2=0;

    int who = 1;
    bool someOneMove = false;

//private:
    bool pushTheBall = false;

signals:
    void nextRound();
public slots:
    void calMove();
    bool preciseDetectionCol(Ball& a,Ball& b) const;
};

#endif // GAMEMANGER_H
