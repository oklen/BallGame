#ifndef BALL_H
#define BALL_H

#include "ballobject.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>

class Ball:public BallObject
{
public:
    constexpr static float a = 0.35;
    constexpr static float stopBound = 0.2;

    Ball(int x,int y,int r,QColor color);
    void accelacte(float in_x,float in_y);
    void Move(float time_span);
    bool moving = false;
    float getVx() const;

    float getVy() const;

    void setVx(float value);

    void setVy(float value);
    float vx,vy;
private:
};

#endif // BALL_H
