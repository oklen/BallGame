#ifndef CLUB_H
#define CLUB_H
#include "object.h"
#include "vector2.h"
#include <QDebug>
#include "ball.h"

class Club:public Object
{
public:
    Club(float x,float y,QColor color);
    void draw(QPainter& painter) override;

    void setTops(const Vector2 &value);
    void setTops(float x,float y);

    void setCenter(const Vector2 &value);
    void setCenter(float x,float y);

    bool isTooFar(float x,float y);
    Ball tops;

    Vector2 getDir() const;

    int ball_radius= 20;
private:
    Vector2 dir;
    Vector2 mcenter;
    float m_length = 500;
    float m_width = 6;
    constexpr static float maxSpeed = 180;
    QPen mpen;
};

#endif // CLUB_H
