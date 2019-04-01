#include "acquirered.h"

AcquireRed::AcquireRed(GameWorker *manger, GameState **state,VGControl* vgcontrol):
    GameState (manger,state),parent(vgcontrol)
{

}

void AcquireRed::nextRound()
{
    qDebug()<<"hitred";
    int ban = 0;
    //qDebug()<<"rank:"<<Col_Order[0].first->rank << Col_Order[0].second->rank;
    if(worker->Col_Order.empty()) {
        worker->players[worker->who].state = Player::failed;
        ban+=Ball::bai;
    }
    else
    {
        if((worker->Col_Order[0].second->rank==Ball::hong||
            worker->Col_Order[0].first->rank==Ball::hong)){
            for(int i=0;i<worker->falls.size();++i){
                if(ban>=0&&worker->falls[i]->rank==Ball::hong) ban=1;
                else {ban=std::max(std::min(-4,-worker->falls[i]->rank),-7);}
            }
        }else {
            for(int i=0;i<worker->Col_Order.size();++i){
                ban=std::max(std::min(-4,
                                      -std::max(worker->Col_Order[i].first->rank,
                                               worker->Col_Order[i].second->rank))
                             ,-7);
            }
            for(int i=0;i<worker->falls.size();++i){
                if(worker->falls[i]->rank!=Ball::bai)
                ban=std::max(std::min(-4,-worker->falls[i]->rank),-7);
                else ban = std::min(ban,static_cast<int>(Ball::bai));
            }
        }
    }

    if(ban<0) {
        worker->players[worker->who?1:0].scores-=ban;
        *state = parent->getFail();
    }
    else
    {
        worker->players[worker->who].scores+=ban;
        if(ban)
        {
            *state = parent->getAC();
        }
        else
        {
            *state = parent->getFail();
        }
    }
}
