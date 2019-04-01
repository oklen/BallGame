#ifndef ACQUIRERED_H
#define ACQUIRERED_H

#include "gamestate.h"
#include "vgcontrol.h"

class AcquireRed : public GameState
{
public:
    AcquireRed(GameWorker* worker,GameState** state,
               VGControl* vgcontrol);
    VGControl* parent;
    void nextRound();
};

#endif // ACQUIRERED_H
