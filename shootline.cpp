#include "shootline.h"

ShootLine::ShootLine():targetBall(new BallObject(0,0,0,Qt::white))
{
    mpen.setColor(Qt::white);
    mpen.setDashOffset(10);
    mpen.setWidth(2);
    mpen.setStyle(Qt::DashLine);
    targetBall->setPen(mpen);
    targetBall->setBrush(QColor(0,0,0,0));
}

void ShootLine::draw(QPainter &mpainter)
{
    if(!showOn) return;
    mpen.setStyle(Qt::DashLine);
    mpainter.setPen(mpen);

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

        targetBall->r = ball_radius;
        targetBall->x = EndPos.x;
        targetBall->y = EndPos.y;
        targetBall->draw(mpainter);

    }else     mpainter.drawLine(beginAt.x,beginAt.y,beginAt.x+dir.x*2000,beginAt.y+dir.y*2000);
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

void ShootLine::colTest(Bound **bound)
{
    if(!showOn||(a==0&&b==0)) return;
//    qDebug() << "one True!";
    for(int i=0;i<6;++i){
        for(int j=0;j<bound[i]->lines.size();++j){
            if(bound[i]->lines[j]->MeetAt(a,b,c,dir,ball_radius,beginAt)){
                mpos.push_back(bound[i]->lines[j]->meetPoint);
//                qDebug()<<mpos.back().x <<mpos.back().y;
            }
        }
    }
}

void ShootLine::setBall_radius(float value)
{
    ball_radius = value;
}

bool ShootLine::isMposEmpty()
{
    return mpos.empty();
}
