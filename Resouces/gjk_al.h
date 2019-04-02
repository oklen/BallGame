#ifndef GJK_AL_H
#define GJK_AL_H

#include <vector2.h>
#include <ball.h>
#include "bound.h"

class GJK_Al
{
public:
    GJK_Al();

    Vector2 GetCenterPoint(Ball * ball){
        return Vector2(ball->x,ball->y);
    }

    Vector2 GetCenterPoint(Bound* bound){
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

    Vector2 GetFarestPoint(Ball*ball ,Vector2 dir){
        return Vector2(ball->x,ball->y)+dir*ball->r;
    }

    Vector2 GetFarestPoint(Bound* bound,Vector2 dir){
        Vector2 result;
        float maxProduct = dir.dot(bound->lines[0]->mx1,bound->lines[0]->mx2);
        for(int i=0;i<bound->lines.size();++i){
            if(maxProduct<dir.dot(bound->lines[i]->mx1,bound->lines[i]->my1))
            {
                result.x = bound->lines[i]->mx1;
                result.y = bound->lines[i]->my1;
            }
            if(maxProduct<dir.dot(bound->lines[i]->mx2,bound->lines[i]->my2))
            {
                result.x = bound->lines[i]->mx2;
                result.y = bound->lines[i]->my2;
            }
        }
        return result;
    }

    Vector2 support(Bound* bound,Ball* ball,Vector2 d){
        return GetFarestPoint(bound,d)-GetFarestPoint(ball,d);
    }

    bool isCol(Bound* bound,Ball* ball){

    }
};

#endif // GJK_AL_H
