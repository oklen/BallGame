#ifndef HOLE_H
#define HOLE_H

#include "ballobject.h"

class Hole:public BallObject
{
public:
    Hole(int x,int y,int r,QColor color = Qt::blue);
};

#endif // HOLE_H
