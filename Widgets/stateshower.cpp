#include "stateshower.h"
#include <QPainter>
#include"Resouces/musicmanger.h"

StateShower::StateShower(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
//    QFont font;
//    font.setFamily("宋体");
//    font.setPointSize(30);
//    font.setBold(true);
//    state.setFont(font);

    state.setText(QString("时间"));
    state.setFixedSize(110,60);
    state.setTextPos({0,50});
    state.useTransparent = true;
//    state.scaleTo(state.size());
//    state.setStyleSheet("color:green;background-color: black");
    vlayout->addWidget(&state);
    state.show();
    vlayout->addWidget(&time);

//    time.setFont(font);
    vlayout->setAlignment(Qt::AlignHCenter);
//    time.setStyleSheet("color:red");
    time.setTextPos({0,30});
    time.useTransparent = true;

    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&StateShower::reduceTime);
    timer.start();
    setLayout(vlayout);
    resetTime();
    setFixedHeight(160);
}

void StateShower::resetTime() // Counting should reset when one shoot.
{
    time.setText(QString(" ")+QString::number(99));
}

void StateShower::reduceTime()
{
    if(time.content.toInt()==0) {emit timeOut();resetTime();}
    else time.setText(" "+QString::number(time.content.toInt()-1));

}
