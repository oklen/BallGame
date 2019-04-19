#ifndef HOLE_H
#define HOLE_H

#include "ball.h"

class Hole:public Ball
{
public:
    Hole(int x,int y,int r,QColor color = Qt::black);
    void draw(QPainter& mpainter);
    std::vector<int> indexs;
};

#endif // HOLE_H
