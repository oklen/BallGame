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

    QObject::connect(&gmr,&GameWorker::nextRound,[this](){
        this->nextRound();
    });
    *state = acquireRed;

    worker->mainWindow.showFullScreen();
    QObject::connect(worker->mainWindow.startGame,&ControlButton::mpress,[this](){
        this->restart();
        this->worker->mainWindow.pauseMenu->hide();
    });

    QObject::connect(worker->mainWindow.pauseMenu->restart,&ControlButton::mpress,[this](){
        this->restart();
        this->worker->mainWindow.pauseMenu->hide();
    });

    QObject::connect(&worker->mainWindow,&MainWindow::gamePause,[this](){
        this->pause();
    });

    QObject::connect(&worker->mainWindow,&MainWindow::gameContinue,[this](){
        this->gameContinue();
        this->worker->mainWindow.pauseMenu->hide();
    });
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
    worker->timer.start();
    worker->board->GameStarted = true;
}

void GlobalControl::pause()
{
    worker->timer.stop();
    worker->board->GameStarted = false;
}

void GlobalControl::gameContinue()
{
    worker->timer.start();
    worker->board->GameStarted = true;
}
