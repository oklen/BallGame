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
    enum ball_color{
        bai=-4,hong=1,huang=2,lv=3,zong=4,lan=5,fen=6,hei=7,club = -1
    };

    float a = 1.5;
    constexpr static float stopBound = 1.6;

    static void swap(ball_color& first,ball_color& second){
        ball_color tmp = first;
        first = second;
        second = tmp;
    }

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
    float vx,vy;
private:
    double savex,savey;

};

#endif // BALL_H
