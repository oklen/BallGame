#include "globalcontrol.h"

GlobalControl::GlobalControl():
    VGControl(),
    gmr(&w),
    acquireRed(new AcquireRed(&gmr,state,this)),
    acquireColor(new AcquireColor(&gmr,state,this)),
    acquireFailed(new AcquireFailed(&gmr,state,this)),
    acquireOrder(new AcquireOrder(&gmr,state,this))
{
    worker = &gmr;
    timer.setInterval(10);
    QObject::connect(&timer,&QTimer::timeout,&gmr,&GameWorker::calMove);
    QObject::connect(&gmr,&GameWorker::nextRound,[this](){
        this->nextRound();
    });
    *state = acquireRed;
    timer.start();
    restart();
    worker->mainWindow.showFullScreen();
}

GameState *GlobalControl::getAR()
{
    return acquireRed;
}

GameState *GlobalControl::getAC()
{
    return acquireColor;
}

GameState *GlobalControl::getFail()
{
    return acquireFailed;
}

GameState *GlobalControl::getLast()
{
    return acquireOrder;
}

void GlobalControl::nextRound()
{
    qDebug() << "Do NextRound! "<<worker->players[0].scores <<
                worker->players[1].scores;
    (*state)->nextRound();
    if(*state==acquireFailed) (*state)->nextRound();
    worker->clearBalls(); //Warning this do board update!
}

void GlobalControl::restart()
{
    worker->board->Reset();
    timer.start();
}

void GlobalControl::pause()
{
    timer.stop();
}

void GlobalControl::gameContinue()
{
    timer.start();
}
