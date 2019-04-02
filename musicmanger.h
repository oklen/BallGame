#ifndef MUSICMANGER_H
#define MUSICMANGER_H
#include <QSound>
#include <QMediaPlayer>
#include <QObject>

class MusicManger
{
    Q_OBJECT
public:
    MusicManger();
    void playBallHitBall();
    void playPutBall();
    void playPolHitBall();
    void doInitial();


private:
    QMediaPlayer  *BHB;
    QMediaPlayer  *PB;
    QMediaPlayer  *PHB;
    const int Volume=50;

};

#endif // MUSICMANGER_H
