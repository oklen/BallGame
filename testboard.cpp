#include "testboard.h"

TestBoard::TestBoard(QWidget *parent) : QWidget(parent)
{
    for(int i=0;i<ball_amount;++i)
    {
        balls[i] = new Ball(100,100,15,Qt::green);
        balls[i]->accelacte(10,3);
    }
    timer.setInterval(10);
    connect(&timer,&QTimer::timeout,this,&TestBoard::calMove);
    timer.start();
}

void TestBoard::paintEvent(QPaintEvent *event)
{
    QPainter mpainter(this);
    for(int i=0;i<ball_amount;++i)
    {
        balls[i]->draw(mpainter);
    }
    mpainter.end();
}

void TestBoard::calMove()
{
    bool oneMove = false;
    for(int i=0;i<ball_amount;++i)
    {
        if(balls[i]->moving)
        {
            balls[i]->Move(0.1);
            oneMove = true;
        }
    }
        update();
}
