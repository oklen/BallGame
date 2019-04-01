#ifndef ACQUIRECOLOR_H
#define ACQUIRECOLOR_H

#include "gamestate.h"
#include "vgcontrol.h"

class AcquireColor:public GameState
{
public:
    AcquireColor(GameWorker* worker,GameState** state,
                 VGControl* vgcontrol);
    VGControl* parent;
    void nextRound() override;
};

#endif // ACQUIRECOLOR_H
