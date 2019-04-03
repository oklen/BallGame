#include "gjk_test.h"

GJK_Test::GJK_Test(QWidget *parent) : QWidget(parent)
{
    resize(800,800);
    show();
    timer.setInterval(100);
    connect(&timer,&QTimer::timeout,this,&GJK_Test::move);
    timer.start();
}

void GJK_Test::test1()
{
    if(bound) delete bound;
    if(ball) delete ball;
    bound = new Bound(0,0,550,50);
    bound->lines.push_back(new BoundLine(0,0,550,0));
    bound->lines.push_back(new BoundLine(550,0,550,50));
    bound->lines.push_back(new BoundLine(550,50,0,50));
    bound->lines.push_back(new BoundLine(0,50,0,0));

    ball = new Ball(561,11,12,QColor(0,0,0,0));
}

void GJK_Test::wait()
{
    mp = grab(rect());
}



void GJK_Test::paintEvent(QPaintEvent *event)
{

    mpainter.begin(this);

    mpainter.drawPixmap(rect(),mp);
    mpainter.translate(QPoint(100,400));
    mpainter.setBrush(QColor(0,0,0,0));
    if(bound)
        bound->draw(mpainter);
    if(ball)
        ball->draw(mpainter);

    QPen mpen;

    if(p1&&p2){
        mpen.setColor(Qt::red);
        mpainter.setPen(mpen);
        mpainter.drawLine(p1->x,p1->y,p2->x,p2->y);
        qDebug() << "p1:"<<p1->x << p2->y;
    }
    if(p1&&p3){
        mpen.setColor(Qt::green);
        mpainter.setPen(mpen);
        mpainter.drawLine(p1->x,p1->y,p3->x,p3->y);
    }
    if(p2&&p3){
        mpen.setColor(Qt::blue);
        mpainter.setPen(mpen);
        mpainter.drawLine(p2->x,p2->y,p3->x,p3->y);
        mpen.setColor(Qt::yellow);
        mpen.setWidth(6);
        mpainter.setPen(mpen);
        mpainter.drawPoint(p3->x,p3->y);
    }
    mpen.setColor(Qt::cyan);
    mpen.setWidth(6);
    mpainter.setPen(mpen);
    mpainter.drawPoint(0,0);
    mpen.setWidth(1);
    mpainter.setPen(mpen);
    mpainter.translate(QPoint(-500,-400));
    mpainter.end();
}

void GJK_Test::move()
{
    ball->y -=10;
}
