#include "controlbutton.h"

ControlButton::ControlButton(QWidget *parent) : QPushButton(parent),
    image("/media/root/Dstore/LENOVO/Qt_Project/BallGame/images/ButtonBackGround.png")
{
    qDebug() << image.size();
    image = image.scaled(250,100);
    setMask(image.mask());
    content = "开始游戏";
}

void ControlButton::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    mpainter.drawPixmap(0,0,image);
    if(content.size()){
        qDebug() << content;
        mpainter.setPen(QColor());
        mpainter.setFont(QFont("Source Code Pro",35, QFont::Bold));
       mpainter.drawText(30,65,content);
    }
    mpainter.end();
}
