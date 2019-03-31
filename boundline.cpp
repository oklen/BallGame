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
                       Vector2& beginAt)
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
