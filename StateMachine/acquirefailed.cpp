#include "acquirefailed.h"

AcquireFailed::AcquireFailed(GameWorker *worker, GameState **state,VGControl* vgcontrol):
    GameState (worker,state),parent(vgcontrol)
{

}

void AcquireFailed::nextRound()
{        worker->who= (worker->who==1?0:1);

         //worker->board->rd.setRound(worker->who);

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
                               worker->board->balls.push_back(worker->falls[i]);
                           }
                       }
                   }
         //worker->board->rd.showTurns = true;

//         QTimer::singleShot(2000,&worker->board->rd,&rounder::close);
//         QTimer::singleShot(2050,worker->board,&Board::doUpdate);
}
