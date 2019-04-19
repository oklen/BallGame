#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>
#include <iostream>
#include <ostream>

class Vector2
{
public:
    Vector2();
    Vector2(double x,double y):x(x),y(y){}
    double x,y;
    Vector2 operator+(Vector2 in){
        Vector2 tmp = *this;
        tmp.x += in.x;
        tmp.y += in.y;
        return tmp;
    }
    Vector2 operator*(double in){
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

    Vector2& operator*=(double times){
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

    double lengthSquared() {
        return x*x+y*y;
    }

    double length(){
        return std::sqrt(x*x+y*y);
    }

    void united(){
        double sum = sqrt(x*x+y*y);
        x/=sum;
        y/=sum;
    }

    void reserved(){
        x*=-1;
        y*=-1;
    }

    double dot(Vector2 in){
        return x*in.x+y*in.y;
    }

    double dot(double dx,double dy){
        return x*dx+y*dy;
    }
    std::ostream& operator<<(std::ostream& out){
        out << x<< " "<< y;
        return out;
    }

    Vector2 ud(){
        return Vector2(x/length(),y/length());
    }
};

#endif // VECTOR2_H
