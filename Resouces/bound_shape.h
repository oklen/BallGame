#ifndef BOUND_SHAPE_H
#define BOUND_SHAPE_H

#include <QPainter>
#include <QRect>

class Bound_Shape
{
public:
    Bound_Shape();
    QRect rect;
    QPixmap mp;
    void draw(QPainter& mpainter);
};

#endif // BOUND_SHAPE_H
