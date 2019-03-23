#include "gamemanger.h"

GameManger::GameManger(MainWindow *child):board{child}
{
    board->show();
    timer.setInterval(10);
    connect(&timer,&QTimer::timeout,this,&GameManger::calMove);
    timer.start();
}

void GameManger::start()
{
    board->Reset();
}

void GameManger::calMove()
{
    bool needUpdate = false;
    for(int i=0;i<board->balls.size();++i){
        if(board->balls[i]->moving){
            board->balls[i]->Move(time_span);
            needUpdate = true;
        }
    }
    if(needUpdate) board->update();
}
