#include "acquirecolor.h"

AcquireColor::AcquireColor(GameWorker* manger,GameState** state,VGControl* vgcontrol):
    GameState (manger,state),parent(vgcontrol)
{

}

void AcquireColor::nextRound()
{
    qDebug() << "hitcolor";
    if(worker->Col_Order.empty()){
        worker->players[worker->who].state = Player::failed;
        worker->players[worker->who?0:1].scores-=Ball::bai;
        //May require free Ball
    }else{
        int score = 0;
        for(int i=0;i<worker->falls.size();++i){
            if(worker->falls[i]->rank!=Ball::bai)
                score+=worker->falls[i]->rank;
            else {
                score = worker->falls[i]->rank;
                break;
            }
        }
        if(score>0)
        {
            //worker->players[worker->who].state = Player::hitred;
            *state = parent->getAR();
        }
        else
            //worker->players[worker->who].state = Player::failed;
            *state = parent->getFail();
    }
}
