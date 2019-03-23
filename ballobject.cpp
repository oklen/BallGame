#include "ballobject.h"

BallObject::BallObject(int x, int y, int r, QColor color):Object (x,y,color),center{x,y},
    r{r}
{

}

void BallObject::draw(QPainter &painter)
{
    if(selected)painter.setPen(Qt::white);
    painter.setBrush(m_brush);
    painter.drawEllipse(center,r,r);
}
