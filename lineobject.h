#ifndef LINEOBJECT_H
#define LINEOBJECT_H

#include "object.h"
#include "vector2.h"
#include <QDebug>

class LineObject:public Object
{
public:
    LineObject();
    void CalABC(Vector2 begin,Vector2 dir);
    void setABC(float a,float b,float c);
protected:
    float a,b,c;
};

#endif // LINEOBJECT_H
