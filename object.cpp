#include "object.h"

Object::Object(QObject *parent) : QObject(parent)
{

}

Object::Object(float x,float y,QColor color):x{x},y{y},
    m_color{color},m_brush{QBrush(color)}
{

}
