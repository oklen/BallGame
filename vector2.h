#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>
#include <iostream>
#include <ostream>

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

//    Vector2 operator-(Vector2 in){
//        return Vector2(x-in.x,y-in.y);
//    }

    static Vector2 perpendicular(Vector2 in){
        return Vector2(in.y,-in.x);
    }

    Vector2 negatle(){
        return Vector2(-x,-y);
    }

    float lengthSquared() {
        return x*x+y*y;
    }

    float length(){
        return std::sqrt(x*x+y*y);
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

    double dot(Vector2 in){
        return (double)x*in.x+y*in.y;
    }

    float dot(float dx,float dy){
        return x*dx+y*dy;
    }
    std::ostream& operator<<(std::ostream& out){
        out << x<< " "<< y;
        return out;
    }
};

#endif // VECTOR2_H
