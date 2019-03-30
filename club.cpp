#include "club.h"

Club::Club(float x, float y, QColor color):Object (x,y,color),
    tops(x,y,-10,color)
{
    tops.a = -40;
    mpen.setWidth(m_width);
    mpen.setColor(color);
}

void Club::draw(QPainter &mpainter)
{
    if(!showOn) return;
    mpainter.setPen(mpen);
    dir = Vector2(mcenter.x - tops.x,mcenter.y-tops.y);
    dir.united();
    tops.rank = Ball::club;
    mpainter.drawLine(tops.x-dir.x*10,tops.y-dir.y*10,tops.x - dir.x*m_length,tops.y - dir.y*m_length);
}


void Club::setTops(float x, float y)
{
//    qDebug() << x;
    tops.x = x;
    tops.y = y;
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
