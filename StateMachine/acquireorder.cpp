#include "acquireorder.h"

AcquireOrder::AcquireOrder(GameWorker* worker,GameState** state,
                           VGControl* vgcontrol):
    GameState (worker,state),parent(vgcontrol)
{

}

void AcquireOrder::nextRound()
{
    if(worker->Col_Order.empty()){
        worker->players[worker->who?1:0].scores+=-Ball::bai;
        *state = parent->getFail();
        return;
    }
    int target = 8;
    for(int i=0;i<worker->Col_Order.size();++i){
        if(worker->Col_Order[i].first->rank>0)
        target = std::min(target,(int)worker->Col_Order[i].first->rank);
        if(worker->Col_Order[i].second->rank>0)
            target = std::min(target,(int)worker->Col_Order[i].second->rank);
    }
    int ban = 0;

    if(worker->Col_Order[0].first->rank>0&&worker->Col_Order[0].first->rank!=target){
        ban = -worker->Col_Order[0].first->rank;
    }

    if(worker->Col_Order[0].second->rank>0&&worker->Col_Order[0].second->rank!=target){
        ban = -worker->Col_Order[0].second->rank;
    }

        for(int i=0;i<worker->falls.size();++i){
            if(worker->falls[i]->rank==target&&!ban){
                ban = target;
            }else if(worker->falls[i]->rank!=Ball::bai)
                ban = std::min(ban,-worker->falls[i]->rank);
            else ban = std::min(ban,static_cast<int>(worker->falls[i]->rank));
        }

        if(ban>0){
            worker->players[worker->who].scores+=ban;
            //Still Live in this state!
            //*state = parent->getLast();
        }else {
            worker->players[worker->who?0:1].scores-=ban;
            *state = parent->getFail();
        }
}
