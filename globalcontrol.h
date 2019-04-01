#ifndef GLOBALCONTROL_H
#define GLOBALCONTROL_H

#include "StateMachine/acquirecolor.h"
#include "StateMachine/acquirefailed.h"
#include "StateMachine/acquirered.h"
#include "StateMachine/acquireorder.h"

#include "vgcontrol.h"

class GlobalControl:public VGControl
{
public:
    GlobalControl();
    Board w;
    GameWorker gmr;


    AcquireRed* acquireRed;
    AcquireColor* acquireColor;
    AcquireFailed* acquireFailed;
    AcquireOrder* acquireOrder;

    GameState* getAR();
    GameState *getAC();
    GameState* getFail();
    GameState* getLast();

    void nextRound();

private:
    QTimer timer;
};

#endif // GLOBALCONTROL_H
