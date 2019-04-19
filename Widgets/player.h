#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    enum State{
        failed,hitred,hitcolor,hitHuang,hitlv,hitzong,hitlan,hitfen,hithei
    };
    Player(int who=0);
    int scores = 0;
    int who;
    State state;
};

#endif // PLAYER_H
