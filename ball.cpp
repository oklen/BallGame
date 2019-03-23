#include "ball.h"

Ball::Ball(int x, int y, int r, QColor color):BallObject(x,y,r,color)
{

}

void Ball::accelacte(float in_x, float in_y)
{
    vx = in_x;
    vy = in_y;
    moving = true;
}

void Ball::Move(float time_span)
{
    x+= vx*time_span;
    y+= vy*time_span;
    int dir = 1;
    if(vx<0) dir = -1;
    float ratio = std::abs(vx)/(std::abs(vx)+std::abs(vy));
    if(ratio!=ratio){
        moving=false;return;
    }
    vx -= time_span*a*ratio*dir; //Very Non-accurate methods
    if(vx!=vx) {
        qDebug() <<time_span<<a<<ratio<<dir;
        abort();
    }
    if(vy<0) dir = -1;
    else dir = 1;
    vy -= time_span*a*(1-ratio)*dir;
    if(std::abs(vx)<stopBound||std::abs(vy)<stopBound) {
        vx=vy=0;
        moving=false;
    }
}

void Ball::save()
{
    savex = x;savey = y;
}

void Ball::rollback()
{
    x = savex;
    y = savey;
}

float Ball::getVx() const
{
    return vx;
}

float Ball::getVy() const
{
    return vy;
}

void Ball::setVx(float value)
{
    vx = value;
}

void Ball::setVy(float value)
{
    vy = value;
}
