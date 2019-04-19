#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include "object.h"
#include "Resouces/ball_bank.h"

class BallObject:public Object
{
public:

    static float scaleSize;
    BallObject(int x,int y,int r,QColor color);
    void draw(QPainter& painter) override;
    QPoint center;
    bool selected =false;
    int r;
    void restore();
private:
    double bx,by;
};

#endif // BALLOBJECT_H
