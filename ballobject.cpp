#include "ballobject.h"

float BallObject::scaleSize;

BallObject::BallObject(int x, int y, int r, QColor color):Object (x,y,color),center{x,y},
    r{r}
{
    bx = x;by = y;
    r*=scaleSize;
}

void BallObject::draw(QPainter &painter)
{
    painter.setPen(m_pen);
    painter.setBrush(m_brush);
    painter.drawEllipse(QPoint(x,y),r,r);
}

void BallObject::restore()
{
    x = bx;y = by;
}
