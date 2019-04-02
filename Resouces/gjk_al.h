#ifndef GJK_AL_H
#define GJK_AL_H

#include <vector2.h>
#include <ball.h>
#include "bound.h"
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
//        qDebug() << "ball:"<<ball->x+dir.x*ball->r<< ball->y+dir.y*ball->r;
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
            }
//            if(maxProduct<dir.dot(bound->lines[i]->mx2,bound->lines[i]->my2))
//            {
//                result.x = bound->lines[i]->mx2;
//                result.y = bound->lines[i]->my2;
//            }
        }
//        qDebug() << result.x << result.y;
        return result;
    }

    Vector2 support(Bound* bound,Ball* ball,Vector2 d){
        return getFarestPoint(bound,d)-getFarestPoint(ball,d.negatle());
    }

    Vector2 getTripleVector(Vector2 a,Vector2 b,Vector2 c){
//        qDebug() << "tirple:"<<a.x << a.y << b.x << b.y << c.x << c.y;

        float ac = a.dot(c);
        float bc = b.dot(c);

        return Vector2(b.x*ac-a.x*bc,b.y*ac-a.y*bc);
    }

    bool isCol(Bound* bound,Ball* ball){

        Vector2 boundCenter = getCenterPoint(bound),
                ballCenter = getCenterPoint(ball);
        Vector2 d(1,0);

        if((d.x==0)&&(d.y==0)) d.y = 1.0f;
        d.united();

        p1 = support(bound,ball,d);

        if(p1.dot(d)<=0) return false;

        p2 = support(bound,ball,d*-1);

        d = getTripleVector(p2-p1,p1*-1,p2-p1);//Perform ABxAOxAB
        if(p2.dot(d)==0) d = Vector2::perpendicular(p1-p2);

        qDebug() << "d:"<<d.x << d.y;

        tester.p1 = &p1;
        tester.p2 = &p2;
        int cnt = 0;
        while(true){
            qDebug() << "really d:"<< d.x << d.y;
            d.united();
            qDebug() << "united d:" << d.x << d.y;
            p3 = support(bound,ball,d);

            tester.p3 = &p3;
            tester.wait();
//            if(++cnt>20) return false;

//            qDebug() << "p1x:"<<p1.x << "p1y:"<<p1.y << "p2x:"<<p2.x
//                     << "p2y:"<<p2.y << "p3x:"<<p3.x << "p3y:"<<p3.y;
            //tester.update();

            qDebug() <<d.dot(p3);
            if(p3.length()<10) return true;
            if(d.dot(p3)<=0) {
                qDebug() << "length:" <<p3.length();

                return false;
            }

            //Vector2 toSide = getTripleVector(p2-p3,p1-p3,p1-p3);
            Vector2 toSide = getTripleVector(p1-p3,p2-p3,p1-p3)*-1;
            if(toSide.dot(p3*-1)>=0){
                d  = toSide;
            }else{
                //toSide = getTripleVector(p2-p3,p1-p3,p2-p3)*-1;
                toSide = getTripleVector(p1-p3,p2-p3,p2-p3);
                if(toSide.dot(p3*-1)<0){
                    return true;
                }
                d = toSide;
                p1 = p2;
                //p2 = p1;
            }
            p2 = p3;
        }
    }
};

#endif // GJK_AL_H
