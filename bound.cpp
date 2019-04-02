#include "bound.h"

Bound::Bound(QObject *parent) : Object(parent)
{

}

Bound::Bound(int xpos, int ypos, int xspan, int yspan,QColor color)
    : Object(xpos,ypos,color),xspan{xspan},yspan{yspan},
      m_rect{QRect(x,y,xspan,yspan)},
      image(new QPixmap("../BallGame/images/bound.png"))
{
    m_pen.setColor(Qt::black);
    x = m_rect.x();
    y = m_rect.y();
    xspan = m_rect.width();
    yspan = m_rect.height();

    lines.push_back(new BoundLine(x,y,x+xspan,y));
    lines.push_back(new BoundLine(x,y,x,y+yspan));
    lines.push_back(new BoundLine(x+xspan,y,x+xspan,y+yspan));
    lines.push_back(new BoundLine(x,y+yspan,x+xspan,y+yspan));

}

void Bound::draw(QPainter &painter)
{
    painter.setBrush(m_brush);
    painter.setPen(m_pen);
    painter.drawRect(m_rect);
//    qDebug()<<image->size();
//    painter.drawPixmap(m_rect,*image);
}

void Bound::setColor(QColor color)
{
    m_color = color;
    m_brush = QBrush(m_color);
}
