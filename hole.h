#ifndef HOLE_H
#define HOLE_H

#include "ball.h"

class Hole:public Ball
{
public:
    Hole(int x,int y,int r,QColor color = Qt::blue);
};

#endif // HOLE_H
