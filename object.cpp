#include "object.h"

Object::Object(QObject *parent) : QObject(parent)
{

}

Object::Object(float x,float y,QColor color):x{x},y{y},
    m_color{color},m_brush{QBrush(color)}
{

}

void Object::setBrush(const QBrush &brush)
{
    m_brush = brush;
}

void Object::setPen(const QPen &pen)
{
    m_pen = pen;
}
