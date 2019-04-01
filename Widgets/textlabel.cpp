#include "textlabel.h"

TextLabel::TextLabel(QWidget *parent) : QWidget(parent),
    image("../BallGame/images/KK_back.png"),textPos({30,65}),
    TextSize(35)
{

}

TextLabel::TextLabel(QString in):content(in)
{
}

void TextLabel::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    if(!useTransparent)
    mpainter.drawPixmap(0,0,image);
    if(useTransparent) {
        mpainter.setBrush(QColor(0,0,0,0));
        mpainter.setPen(QColor(0,0,0,0));
    }
    mpainter.drawRect(rect());
    if(content.size()){
        mpainter.setPen(QColor(0,0,0));
        mpainter.setFont(QFont("Source Code Pro",TextSize, QFont::Bold));
       mpainter.drawText(textPos,content);
    }
    mpainter.end();
}

void TextLabel::scaleTo(QSize size)
{
    image = image.scaled(size);
    update();
}

void TextLabel::setText(QString in)
{
    content = in;
    update();
}

void TextLabel::setTextPos(QPoint in)
{
    textPos = in;
    update();
}
