#include "bound.h"

Bound::Bound(QObject *parent) : Object(parent)
{

}

Bound::Bound(int xpos, int ypos, int xspan, int yspan,QColor color)
    : Object(xpos,ypos,color),xspan{xspan},yspan{yspan},
      m_rect{QRect(x,y,xspan,yspan)}
{
    m_pen.setColor(Qt::black);
}

void Bound::draw(QPainter &painter)
{
    painter.setBrush(m_brush);
    painter.setPen(m_pen);
    painter.drawRect(m_rect);
}

void Bound::setColor(QColor color)
{
    m_color = color;
    m_brush = QBrush(m_color);
}
