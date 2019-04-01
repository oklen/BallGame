#include "gamestate.h"

GameState::GameState(GameWorker *manger, GameState **state):worker(manger),
    state(state)
{

}

GameState::~GameState(){
    delete worker;
}
