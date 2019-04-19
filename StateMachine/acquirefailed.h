#ifndef ACQUIREFAILED_H
#define ACQUIREFAILED_H

#include "gamestate.h"
#include "Widgets/vgcontrol.h"

class AcquireFailed:public GameState
{
public:
    AcquireFailed(GameWorker* worker,GameState** state,
                  VGControl* vgcontrol);
    VGControl* parent;
    void nextRound() override;
};

#endif // ACQUIREFAILED_H
