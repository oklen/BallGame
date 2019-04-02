#include "bound_shape.h"

Bound_Shape::Bound_Shape()
{

}

void Bound_Shape::draw(QPainter &mpainter)
{
    mpainter.drawPixmap(rect,mp);
}
