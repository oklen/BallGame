#include "shootline.h"

ShootLine::ShootLine()
{
    mpen.setColor(Qt::white);
    mpen.setDashOffset(10);
    mpen.setWidth(2);
}

void ShootLine::draw(QPainter &mpainter)
{
    if(!showOn) return;
    mpen.setStyle(Qt::DashLine);
    mpainter.setPen(mpen);
//    if(a&&b)
//    mpainter.drawLine(beginAt.x,beginAt.y,150,-(c+150*a)/b);
    if(!mpos.empty()){
        Vector2 EndPos = {mpos[0].x,mpos[0].y};
        for(int i=1;i<mpos.size();++i){
            if(((beginAt.x-mpos[i].x)*(beginAt.x-mpos[i].x)
                    +(beginAt.y - mpos[i].y)*(beginAt.y - mpos[i].y))
                    <(beginAt.x-EndPos.x)*(beginAt.x-EndPos.x)+(beginAt.y-EndPos.y)*(beginAt.y-EndPos.y))
            {
                EndPos.x = mpos[i].x;
                EndPos.y = mpos[i].y;
            }
        }
        mpainter.drawLine(beginAt.x,beginAt.y,EndPos.x,EndPos.y);
        mpen.setStyle(Qt::SolidLine);
        mpainter.setPen(mpen);
        QBrush mbursh = QColor(0,0,0,0);
        mpainter.setBrush(mbursh);
        mpainter.drawEllipse(QPointF(EndPos.x,EndPos.y),ball_radius,ball_radius);
    }else     mpainter.drawLine(beginAt.x,beginAt.y,beginAt.x+dir.x*1000,beginAt.y+dir.y*1000);
    //qDebug() << dir.x << dir.y;
    mpos.clear();

}

void ShootLine::colTest(std::deque<Ball*>& balls)
{
    if(!showOn||(a==0&&b==0)) return;

    for(int i=0;i<balls.size();++i)
    {
        Ball* ball = balls[i];
        if(ball->rank==Ball::bai)continue;
        ball_radius = ball->r;
        double Length =  std::abs(a*ball->x+b*ball->y+c)/std::sqrt(a*a+b*b);
        if(Length>ball->r*2) continue;
//        qDebug() << Length;

        float ddx  = (b*b*ball->x-a*b*ball->y-a*c)/(a*a+b*b),
                ddy = (a*a*ball->y-a*b*ball->x-b*c)/(a*a+b*b);
//       qDebug() << ddx-ball->x << dir.x;
       if((ddx-beginAt.x)*dir.x<0) continue;

        Length = std::sqrt((ball->r*2)*(ball->r*2)-Length*Length);
        if(Length==Length)
        {
            ddx-=dir.x*Length;
            ddy-=dir.y*Length;
        }
        mpos.push_back({ddx,ddy});
    }
}

void ShootLine::setBall_radius(float value)
{
    ball_radius = value;
}
