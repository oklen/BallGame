#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Widgets/gamemanger.h"

class GameState
{
public:
    explicit GameState(GameWorker *worker,GameState** state);
    virtual void nextRound() = 0;
    GameWorker *worker;
    GameState **state;
    virtual ~GameState();
};

#endif // GAMESTATE_H
