#ifndef BALL_H
#define BALL_H

#include "ballobject.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>
#include "vector2.h"

class Ball:public BallObject
{
public:

    float a = 2.5;
    constexpr static float stopBound = 1.5;

    static void swap(ball_color& first,ball_color& second){
        ball_color tmp = first;
        first = second;
        second = tmp;
    }

    void draw(QPainter& mpainter);
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
    ball_color rank;
    QPixmap image;
    float vx,vy;
private:
    double savex,savey;

};

#endif // BALL_H
