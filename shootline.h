#ifndef SHOOTLINE_H
#define SHOOTLINE_H

#include <QPen>
#include "ball.h"
#include "lineobject.h"
#include "bound.h"
#include <deque>

class ShootLine:public LineObject
{
public:
    ShootLine();
    Vector2 beginAt;
    Vector2 dir;
    void draw(QPainter& mpainter) override;
    void colTest(std::deque<Ball*>& balls);
    void colTest(Bound** bound);
    void setBall_radius(float value);

    bool isMposEmpty();
private:
    QPen mpen;
    std::deque<Vector2> mpos;
    BallObject *targetBall;
    float ball_radius = 5;
};

#endif // SHOOTLINE_H
