#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>

class Vector2
{
public:
    Vector2();
    Vector2(float x,float y):x(x),y(y){}
    float x,y;
    Vector2 operator+(Vector2 in){
        Vector2 tmp = *this;
        tmp.x += in.x;
        tmp.y += in.y;
        return tmp;
    }
    Vector2 operator*(float in){
        Vector2 tmp = *this;
        tmp.x*=in;
        tmp.y*=in;
        return tmp;
    }
    Vector2 operator-(Vector2 in){
        Vector2 tmp = *this;
        tmp.x -= in.x;
        tmp.y -= in.y;
        return tmp;
    }
    Vector2 operator*(Vector2& in){
        Vector2 tmp = *this;
        tmp.x *= in.x;
        tmp.y *= in.y;
        return tmp;
    }

    Vector2& operator*=(float times){
        x*=times;
        y*=times;
        return *this;
    }

    Vector2& operator-=(Vector2& in){
        x-=in.x;
        y-=in.y;
        return *this;
    }
    Vector2& operator-=(Vector2 in){
        x-=in.x;
        y-=in.y;
        return *this;
    }

    Vector2& operator+=(Vector2& in){
        x+=in.x;
        y+=in.y;
        return *this;
    }

    void united(){
        float sum = sqrt(x*x+y*y);
        x/=sum;
        y/=sum;
    }

    void reserved(){
        x*=-1;
        y*=-1;
    }

    float dot(Vector2& in){
        return x*in.x+y*in.y;
    }
};

#endif // VECTOR2_H
