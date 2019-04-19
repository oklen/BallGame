#include "mainwindow.h"


MainWindow::MainWindow(Board* board,QWidget *parent) : QWidget(parent),
    stateShower(new StateShower),board(board),pauseMenu(new PauseMenu),
    startGame(new ControlButton),GameTitile(new ControlButton)
{
    const int offset = 800;
    for(int i=0;i<2;++i)
    {
        per[i] = new PerseonState;
        per[i]->setParent(this);
        per[i]->setFixedWidth(500);
        per[i]->setFixedHeight(130);
    }


    stateShower->setParent(this);
    this->setStyleSheet("background-color: black");
    board->setParent(this);
    board->move(0,0);
    per[0]->move(offset/10,board->height());
    stateShower->setFixedWidth(320);
    stateShower->move(offset,board->height());
    per[1]->move(board->width()-offset/10-per[1]->width(),board->height());

    pauseMenu->setParent(this);
    pauseMenu->move((board->width()-pauseMenu->width())/2,height()-pauseMenu->height()/2);
    pauseMenu->hide();

    startGame->setParent(this);
    startGame->move((board->width()-startGame->width())/2,
                    height()+2*startGame->height());
    startGame->show();

    GameTitile->effect->setEnabled(false);
    GameTitile->setText("");

#ifdef __gnu_linux__
    GameTitile->setPic("../BallGame/images/GameName2.png");
#elif _WIN64
    GameTitile->setPic("..\\BallGame\\images\\GameName2.png");
#endif
    GameTitile->image = GameTitile->image.scaled(900,700);

    GameTitile->setFixedSize(800,600);
    GameTitile->setParent(this);


    GameTitile->move((board->width()-GameTitile->image.size().width())/2+20,
                    100);

    connect(startGame,&ControlButton::mpress,startGame,&ControlButton::hide);
    connect(startGame,&ControlButton::mpress,GameTitile,&ControlButton::hide);
    connect(pauseMenu->resume,&ControlButton::mpress,[this](){
        this->pauseMenu->hide();
        emit this->gameContinue();
    });
    connect(pauseMenu->restart,&ControlButton::mpress,[this](){
        this->pauseMenu->hide();
        emit this->gameContinue();
    });
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape){
        if(pauseMenu->isVisible()) {
            pauseMenu->hide();
            emit gameContinue();
        }
        else if(board->GameStarted){
            pauseMenu->show();
            emit gamePause();
        }
    }
}

MainWindow::~MainWindow(){
    board->setParent(nullptr);
    stateShower->setParent(nullptr);
    for(int i=0;i<2;++i)
    {
        per[i]->setParent(nullptr);
    }
    stateShower =  nullptr;
}


void MainWindow::paintEvent(QPaintEvent *){
//    QLinearGradient linearGradient(QPointF(0, 0),QPointF(0, 190));
//    linearGradient.setColorAt(0, Qt::yellow);
//    linearGradient.setColorAt(0.5, Qt::red);
//    linearGradient.setColorAt(1, Qt::green);
//    //指定渐变区域以外的区域的扩散方式
//    linearGradient.setSpread(QGradient::RepeatSpread);
    //使用渐变作为画刷
    QPainter painter;
    painter.begin(this);
//    painter.setBrush(linearGradient);
    painter.drawPixmap(0,board->height(),QPixmap("../BallGame/images/grey2.png").scaledToWidth(width()));
    painter.end();
}
