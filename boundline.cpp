#include "boundline.h"

BoundLine::BoundLine(float x1, float y1, float x2, float y2)
{
    ma = y1-y2;
    mb = -(x1-x2);
    mc = -(ma*x1+mb*y1);

}

bool BoundLine::MeetAt(float a,float b,float c,Vector2& dir,float length)
{
    qDebug()<<"abc:"<<a<<b<<c;
    if(std::abs(ma/mb-a/b)<0.0001) return false;
    meetPoint.x  = (mc*b-mb*c)/(a*mb-ma*b);
    if(b!=0)
        meetPoint.y = (-c-a*meetPoint.x)/b;
    else meetPoint.y = 0;

    if(a==0){
        if(dir.y>0)
        meetPoint.y -=length;
        else meetPoint.y +=length;
        meetPoint.x -=dir.x*std::abs(length/dir.y);
    }else if(b==0){
        if(dir.x>0)
        meetPoint.x -=length;
        else meetPoint.x +=length;
        meetPoint.y -=dir.y*std::abs(length/dir.x);
    }
    return true;
}
