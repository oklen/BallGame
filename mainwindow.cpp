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

    board->setParent(this);
    board->move(0,0);
    per[0]->move(0,board->height());
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
    stateShower =  nullptr;
}
