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
    void save();
    void rollback();
    bool moving = false;
    float getVx() const;

    float getVy() const;

    void setVx(double value);

    void setVy(double value);
    float vx,vy;
private:
    double savex,savey;
};

#endif // BALL_H
