#ifndef MUSICMANGER_H
#define MUSICMANGER_H
#include <QMediaPlayer>
#include "object.h"

class MusicManger
{
public:

    MusicManger();
    static void playBallHitBall();
    static void playPutBall();
    static void playPolHitBall();


    static MusicManger* ss;
private:
    void doInitial();
    static MusicManger* instance();
    QMediaPlayer  *BHB;
    QMediaPlayer  *PB;
    QMediaPlayer  *PHB;
    const int Volume=100;

} ;

#endif // MUSICMANGER_H
