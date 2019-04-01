#include "controlbutton.h"

ControlButton::ControlButton(QWidget *parent) : QPushButton(parent),
    image("../BallGame/images/ButtonBackGround.png"),
    effect(new QGraphicsDropShadowEffect)
{
    effect->setBlurRadius(10);
    effect->setXOffset(0);
    effect->setYOffset(5);
    setGraphicsEffect(effect);
//    qDebug() << image.size();
    image = image.scaled(250,100);
    setMask(image.mask());
    setFixedSize(250,100);
    content = "开始游戏";
}

void ControlButton::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    mpainter.drawPixmap(0,0,image);
    if(content.size()){
        mpainter.setPen(QColor());
        mpainter.setFont(QFont("Source Code Pro",35, QFont::Bold));
       mpainter.drawText(30,65,content);
    }
    mpainter.end();
}

void ControlButton::enterEvent(QEvent *event)
{
    effect->setColor(Qt::white);
}

void ControlButton::leaveEvent(QEvent *event)
{
    effect->setColor(Qt::black);
}

void ControlButton::mousePressEvent(QMouseEvent *event)
{
    move(x(),y()+2);
    emit mpress();
}

void ControlButton::mouseReleaseEvent(QMouseEvent *event)
{
    move(x(),y()-2);
}

void ControlButton::scaleTo(QSize size)
{
    image = image.scaled(size);
    setFixedSize(size);
}


void ControlButton::setText(QString in)
{
    content = in;
    update();
}

void ControlButton::setPic(QString in)
{
    image = QPixmap(in);
//    image = image.scaled(250,100);
//    setMask(image.mask());
//    setFixedSize(image.size());
    setMask(QBitmap(image));
    update();
}
