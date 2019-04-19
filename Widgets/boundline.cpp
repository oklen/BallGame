#include "boundline.h"

BoundLine::BoundLine(float x1, float y1, float x2, float y2)
{

    ma = y1-y2;
    mb = -(x1-x2);
    mc = -(ma*x1+mb*y1);

    mx1 = x1;
    my1 = y1;
    mx2 = x2;
    my2 = y2;
}

bool BoundLine::MeetAt(float a,float b,float c
                       ,Vector2& dir,float length,
                       Vector2& beginAt) //Used for vertical or horitonzal line
{
    if(std::abs(ma/mb-a/b)<0.01) return false;
    meetPoint.x  = (mc*b-mb*c)/(a*mb-ma*b);
    if(b!=0)
        meetPoint.y = (-c-a*meetPoint.x)/b;
    else return false;

    if((mx1!=mx2&&(meetPoint.x<mx1||meetPoint.x>mx2))
            ||(my1!=my2&&(meetPoint.y<my1||meetPoint.y>my2)))
        return false;

    if((meetPoint.x-beginAt.x)*dir.x<0) return false;

    if(ma==0){
        if(dir.y>0)
        meetPoint.y -=length;
        else meetPoint.y +=length;
            meetPoint.x -=dir.x*std::abs(length/dir.y);
    }else if(mb==0){
        if(dir.x>0)
            meetPoint.x -=length;
        else meetPoint.x +=length;
        meetPoint.y -=dir.y*std::abs(length/dir.x);
    }
    return true;
}

bool BoundLine::MeetAt2(Ball &ball, float dtime)//Used for Non-VH Lines
{
    float d_distance = ma*ball.vx + mb*ball.vy;     //diff of distance(upper)
    float o_distance = ma*ball.x + mb*ball.vy + mc; //distance(upper)
    float desire_Time = 0;
    if(o_distance*d_distance<0){
        desire_Time = o_distance/d_distance;
        desire_Time = std::min(desire_Time,dtime);
        o_distance += desire_Time*d_distance; //Get Min Distance
    }

    if(o_distance>ball.r) return false;
    float ball_x = ball.x + ball.vx * desire_Time,
            ball_y = ball.y + ball.vy * desire_Time;

    meetPoint.x = (mb*mb*ball_x-ma*mb*ball_y - ma*mc)/(ma*ma+mb*mb);
    meetPoint.y = (ma*ma*ball_y-ma*mb*ball_x - mb*mc)/(ma*ma+mb*mb);
    if(getDistance(ball_x,ball_y,mx1,my1)<ball.r*ball.r||
            getDistance(ball_x,ball_y,mx2,my2)<ball.r*ball.r||
            (ball_x>=std::min(mx2,mx1)&&ball_x<=std::max(mx1,mx2))||
            (ball_y>=std::min(my2,my1)&&ball_y<=std::max(my1,my2)))
        return true;
    return false;
}

void BoundLine::Col_Vcal(Ball &ball)
{
    Vector2 dir(mx1-mx2,my1-my2);
    dir.united();
    Vector2 vdir(-1/dir.x,1/dir.y);
    dir*=(ball.vx*dir.x+ball.vy*dir.y);
    vdir*=(ball.vx*vdir.x+ball.vy*vdir.y);
    vdir*=0.8;
    vdir.reserved();
    ball.vx = dir.x+vdir.x;
    ball.vy = dir.y+vdir.y;
}

float BoundLine::getDistance(float x1, float y1, float x2, float y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
