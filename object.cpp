#include "object.h"

Object::Object(QObject *parent) : QObject(parent)
{

}

Object::Object(int x, int y, QColor color):x{x},y{y},
    m_color{color},m_brush{QBrush(color)}
{

}
