#include "hole.h"

Hole::Hole(int x,int y,int r,QColor color):Ball(x,y,r,color)
{
    rank = Ball::hole;
}

void Hole::draw(QPainter &mpainter)
{
    mpainter.setBrush(Qt::gray);
    mpainter.setPen(QColor(0,0,0,0));
    for(int i=0;i<indexs.size();++i){
        if(indexs[i]==0){
            mpainter.drawRect(x-r,y-r,r,r);
        }else if(indexs[i]==1){
            mpainter.drawRect(x,y-r,r,r);
        }else if(indexs[i]==2){
            mpainter.drawRect(x-r,y,r,r);
        }else mpainter.drawRect(x,y,r,r);
    }
    Ball::draw(mpainter);
}
