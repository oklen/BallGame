#ifndef MUSICMANGER_H
#define MUSICMANGER_H
#include <QMediaPlayer>
#include "object.h"

class MusicManger
{
public:

    MusicManger();
    void playBallHitBall();
    void playPutBall();
    void playPolHitBall();
    void doInitial();

    static MusicManger* ss;
private:

    static MusicManger* instance();
    QMediaPlayer  *BHB;
    QMediaPlayer  *PB;
    QMediaPlayer  *PHB;
    const int Volume=50;

} ;

#endif // MUSICMANGER_H
