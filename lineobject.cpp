#include "lineobject.h"

LineObject::LineObject()
{

}

void LineObject::CalABC(Vector2 begin, Vector2 dir)
{
    a = dir.y;
    b = -dir.x;
    c = -(a*begin.x+b*begin.y);
}

void LineObject::setABC(float ia, float ib, float ic)
{
    a=ia;
    b=ib;
    c=ic;
}
