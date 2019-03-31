#include "stateshower.h"

StateShower::StateShower(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    state.setText(QString(" 解球"));
    vlayout->addWidget(&state);
    resetTime();
    vlayout->addWidget(&time);
    vlayout->setAlignment(Qt::AlignHCenter);
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&StateShower::reduceTime);
    timer.start();
    setLayout(vlayout);
}

void StateShower::resetTime()
{
    time.setText(QString::number(99));
}

void StateShower::reduceTime()
{
    if(time.text().toInt()==0) {emit timeOut();resetTime();}
    else time.setText("  "+QString::number(time.text().toInt()-1));
}
