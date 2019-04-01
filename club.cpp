#include "club.h"

Club::Club(float x, float y, QColor color):Object (x,y,color),
    tops(x,y,-10,color),clubImage(new QPixmap("../BallGame/images/pol.png"))
{
    mpen.setWidth(m_width);
    mpen.setColor(color);
    tops.a = -100;
    tops.r=0;
}

void Club::draw(QPainter &mpainter)
{
    if(!showOn) return;
    mpainter.setPen(mpen);
    dir = Vector2(mcenter.x - tops.x,mcenter.y-tops.y);
    dir.united();
    QTransform trans;
    trans.translate(tops.x,tops.y);
    mpainter.setTransform(trans);
    float result  = std::atan(dir.y/dir.x)*180/3.14;
    if(result == result)
    {
        if(dir.x>0) result = 180+result;
        mpainter.rotate(result);
    };
    mpainter.drawPixmap(0,-clubImage->height()/2,*clubImage);
    trans.reset();
    mpainter.setTransform(trans);

    tops.rank = Ball::club;
//    mpainter.drawLine(tops.x,tops.y,tops.x - dir.x*m_length,tops.y - dir.y*m_length);
}


void Club::setTops(float x, float y)
{
    tops.x = x-dir.x*ball_radius;
    tops.y = y-dir.y*ball_radius;
}

void Club::setCenter(const Vector2 &value)
{
    mcenter = value;
}

void Club::setCenter(float x, float y)
{
    mcenter.x = x;
    mcenter.y = y;
}

bool Club::isTooFar(float x,float y)
{
    if(std::sqrt((mcenter.x-x)*(mcenter.x-x)+(mcenter.y-y)*(mcenter.y-y))
            >maxSpeed)
    {
        dir = Vector2(mcenter.x - x,mcenter.y-y);
        dir.united();
        tops.x = -dir.x*maxSpeed+mcenter.x;
        tops.y = -dir.y*maxSpeed+mcenter.y;
        return true;
    }
    return false;
}

Vector2 Club::getDir() const
{
    return dir;
}
