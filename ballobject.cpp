#include "ballobject.h"

BallObject::BallObject(int x, int y, int r, QColor color):Object (x,y,color),center{x,y},
    r{r}
{
    bx = x;by = y;
}

void BallObject::draw(QPainter &painter)
{
    if(selected)painter.setPen(Qt::white);
    else painter.setPen(Qt::black);
    painter.setBrush(m_brush);
    painter.drawEllipse(QPoint(x,y),r,r);
}

void BallObject::restore()
{
    x = bx;y = by;
}
