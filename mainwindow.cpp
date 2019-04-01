#include "mainwindow.h"

MainWindow::MainWindow(Board* board,QWidget *parent) : QWidget(parent),
    stateShower(new StateShower),board(board)
{

    for(int i=0;i<2;++i)
    {
        per[i] = new PerseonState;
        per[i]->setParent(this);
        per[i]->setFixedWidth(800);
    }
    stateShower->setParent(this);
    this->setStyleSheet("background-color: black");
    board->setParent(this);
    board->move(0,0);
    per[0]->move(-per[0]->width()/3  ,board->height());
    stateShower->setFixedWidth(320);
    stateShower->move(per[0]->width(),board->height());
    per[1]->move(per[0]->width()+stateShower->width(),board->height());

//    QHBoxLayout* hlayout = new QHBoxLayout;
//    hlayout->addWidget(per[0]);
//    hlayout->addWidget(stateShower);
//    hlayout->addWidget(per[1]);
//    QVBoxLayout *vlayout = new QVBoxLayout;
//    setLayout(vlayout);
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
    QLinearGradient linearGradient(QPointF(0, 0),QPointF(0, 190));
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    //指定渐变区域以外的区域的扩散方式
    linearGradient.setSpread(QGradient::RepeatSpread);
    //使用渐变作为画刷
    QPainter painter;
    painter.begin(this);
    painter.setBrush(linearGradient);
    painter.drawRect(0, 0, 1920, 1024);
}
