#ifndef GJK_AL_H
#define GJK_AL_H

#include "Widgets/vector2.h"
#include "Widgets/ball.h"
#include "Widgets/bound.h"
#include <deque>
#include "Test/gjk_test.h"


class GJK_Al
{
public:
    GJK_Al();
    GJK_Test tester;
    Vector2 getCenterPoint(Ball * ball){
        return Vector2(ball->x,ball->y);
    }

    Vector2 p1,p2,p3;

    Vector2 getCenterPoint(Bound* bound){
        Vector2 center;
        for(int i=0;i<bound->lines.size();++i){
            center.x += (bound->lines[i]->mx1+bound->lines[i]->mx2)/2;
            center.y += (bound->lines[i]->my1+bound->lines[i]->my2)/2;
        }
        center.x/=bound->lines.size();
        center.y/=bound->lines.size();
        return center;
    }

    Vector2 getOriginDir(Vector2 a,Vector2 b,Vector2 c){
        float ac = a.dot(c),bc = b.dot(c);
        return Vector2(b.x*ac-a.x*bc,b.y*ac-a.y*bc);
    }

    Vector2 getFarestPoint(Ball*ball ,Vector2 dir){
        return Vector2(ball->x,ball->y)+dir*ball->r;
    }

    Vector2 getFarestPoint(Bound* bound,Vector2 dir){
        Vector2 result;
        float maxProduct = dir.dot(bound->lines[0]->mx1,bound->lines[0]->my1);
        for(int i=0;i<bound->lines.size();++i){
            if(maxProduct<dir.dot(bound->lines[i]->mx1,bound->lines[i]->my1))
            {
                result.x = bound->lines[i]->mx1;
                result.y = bound->lines[i]->my1;
                maxProduct = dir.dot(bound->lines[i]->mx1,bound->lines[i]->my1);
            }
        }
//        qDebug() << result.x << result.y;
        return result;
    }

    Vector2 support(Bound* bound,Ball* ball,Vector2 d){
        return getFarestPoint(bound,d)-getFarestPoint(ball,d.negatle());
    }

    Vector2 getTripleVector(Vector2 a,Vector2 b,Vector2 c){
//        qDebug() << "tirple:"<<a.x << a.y << b.x << b.y << c.x << c.y;
        a.united();
        b.united();
        c.united();
        double ac = a.dot(c);
        double bc = b.dot(c);

        return Vector2(b.x*ac-a.x*bc,b.y*ac-a.y*bc);
    }

    bool isCol(Bound* bound,Ball* ball){

        Vector2 boundCenter = getCenterPoint(bound),
                ballCenter = getCenterPoint(ball);
        Vector2 d(1,1);

        if((d.x==0)&&(d.y==0)) d.y = 1.0f;
        d.united();

        p1 = support(bound,ball,d);
        qDebug() << p1.x << p1.y;
        if(p1.dot(d)<=0) return false;

        d*=-1;
        p2 = support(bound,ball,d);

        if(p2.dot(d)<=0) return false;

        d = getTripleVector(p2-p1,p1*-1,p2-p1);//Perform ABxAOxAB

        if(p2.dot(d)==0) d = Vector2::perpendicular(p1-p2);

        qDebug() << "d:"<<d.x << d.y;

        tester.p1 = &p1;
        tester.p2 = &p2;
        int cnt = 0;

        while(true){
            d.united();
//            qDebug() << "united d:" << d.x << d.y;
            p3 = support(bound,ball,d);

            tester.p3 = &p3;
            tester.wait();

//            Vector2 tp1 = p1,tp2 = p2,tp3 = p3;
//            tp1.united();tp2.united();tp3.united();
//            qDebug() <<  "result:"<< (d-tp3).length() << (d-tp2).length() <<
//                         (d-tp1).length();

            if(d.dot(p3)<=0) {
                return false;
            }

            Vector2 toSide = getTripleVector(p1-p3,p2-p3,p1-p3)*-1;
            toSide.united();

            if(toSide.dot(p3*-1)>=0){
                d  = toSide;
            }
            else{
                toSide = getTripleVector(p1-p3,p2-p3,p2-p3);
                toSide.united();
//                qDebug() << "key process:" << toSide.dot(p3*-1)
//                         << p3.x << p3.y << toSide.x << toSide.y;
//                qDebug() << "cal:" << p3.x*toSide.x << p3.y*toSide.y;
                if(toSide.dot(p3*-1)<0)
                {
                    return true;
                }
                d = toSide;
                p1 = p2;
            }
            p2 = p3;
        }
    }
};

#endif // GJK_AL_H
