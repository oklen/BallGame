#ifndef ACQUIREORDER_H
#define ACQUIREORDER_H

#include "gamestate.h"
#include "vgcontrol.h"

class AcquireOrder: public GameState
{
public:
    AcquireOrder(GameWorker* worker,GameState** state,
                 VGControl* vgcontrol);
    VGControl* parent;

    void nextRound();
};

#endif // ACQUIREORDER_H
