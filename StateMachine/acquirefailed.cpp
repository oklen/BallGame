#include "acquirefailed.h"

AcquireFailed::AcquireFailed(GameWorker *worker, GameState **state,VGControl* vgcontrol):
    GameState (worker,state),parent(vgcontrol)
{

}

void AcquireFailed::nextRound()
{        worker->who= (worker->who==1?0:1);

         *state = parent->getAR();
         bool haveRed = false;
              for(int i=0;i<worker->board->balls.size();++i){
                  if(worker->board->balls[i]->rank==Ball::hong){
                      haveRed = true;
                      break;
                  }
              }
                   if(haveRed){
                       for(int i=0;i<worker->falls.size();++i){
                           if(worker->falls[i]->rank!=worker->falls[i]->hong){
                               worker->falls[i]->restore();
                               if(worker->falls[i]->rank!=Ball::bai)
                               worker->board->balls.push_back(worker->falls[i]);
                               else {
                                   worker->board->balls.insert
                                           (worker->board->balls.begin(),worker->falls[i]);
                               }
                           }
                       }
                   }
         //worker->board->rd.showTurns = true;
}
