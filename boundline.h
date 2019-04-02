#ifndef BOUNDLINE_H
#define BOUNDLINE_H

#include "vector2.h"
#include "ball.h"
#include <QDebug>

class BoundLine
{
public:
    BoundLine(float x1,float y1,float x2,float y2);
    bool MeetAt(float a,float b,float c,Vector2& dir,float length,
                Vector2& beginAt);
    bool MeetAt2(Ball& ball,float time);

    void Col_Vcal(Ball& ball);
    float getDistance(float x1,float y1,float x2,float y2);
    Vector2 meetPoint;
    float ma,mb,mc;
    float mx1,my1,mx2,my2;
};

#endif // BOUNDLINE_H
