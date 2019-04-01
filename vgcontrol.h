#ifndef VGCONTROL_H
#define VGCONTROL_H
#include "gamemanger.h"
#include "StateMachine/gamestate.h"

class VGControl
{
public:
    VGControl();
    GameState **state;
    GameWorker *worker;
    virtual GameState* getAR()=0;
    virtual GameState* getAC() = 0;
    virtual GameState* getFail() =0 ;
    virtual GameState* getLast() = 0;

    virtual ~VGControl();
};

#endif // VGCONTROL_H
