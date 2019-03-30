#include "rounder.h"

rounder::rounder(int x,int y,int size):Object (x,y,Qt::black),
    strs(QString("Now is 1 Turns!"))
{
    font.setPixelSize(size);
    mpen.setColor(m_color);
    showTurns = true;
}

void rounder::setRound(int who)
{
    strs[7] = '0'+who;
}

void rounder::draw(QPainter &mpainter)
{
    mpainter.setPen(mpen);
    mpainter.setFont(font);
    mpainter.drawText(x,y,strs);
}

void rounder::close()
{
    qDebug() << "Do close";
    showTurns = false;
}
