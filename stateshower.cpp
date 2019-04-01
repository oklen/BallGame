#include "stateshower.h"
#include <QPainter>

StateShower::StateShower(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(30);
    font.setBold(true);
    state.setFont(font);
    state.setText(QString("解球"));
    state.setStyleSheet("color:green;background-color: black");
    vlayout->addWidget(&state);
    resetTime();
    vlayout->addWidget(&time);
    time.setFont(font);
    vlayout->setAlignment(Qt::AlignHCenter);
    time.setStyleSheet("color:red");
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&StateShower::reduceTime);
    timer.start();
    setLayout(vlayout);
}

void StateShower::resetTime() // Counting should reset when one shoot.
{
    time.setText(QString::number(99));
}

void StateShower::reduceTime()
{
    if(time.text().toInt()==0) {emit timeOut();resetTime();}
    else time.setText(" "+QString::number(time.text().toInt()-1));
}
