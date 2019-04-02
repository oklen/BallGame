#include "musicmanger.h"
#include<assert.h>

MusicManger* MusicManger::ss = nullptr;

MusicManger *MusicManger::instance()
{
    if(ss==nullptr)
    {
        ss=new MusicManger();
    }
   return ss;
}


MusicManger::MusicManger()
{
    this->doInitial();
}

void MusicManger::playBallHitBall()
{
    instance()->BHB->play();
}

void MusicManger::playPutBall()
{
    instance()->PB->play();
}

void MusicManger::playPolHitBall()
{
    instance()->PHB->play();
}

void MusicManger::doInitial()
{
    this->PB=new QMediaPlayer;
    this->PB->setVolume(this->Volume);
    this->PB->setMedia(QUrl::fromLocalFile("../BallGame/music/put_ball.wav"));

    this->BHB=new QMediaPlayer;
    this->BHB->setVolume(this->Volume);
    this->BHB->setMedia(QUrl::fromLocalFile("../BallGame/music/ball_hit_ball.wav"));

    this->PHB=new QMediaPlayer;
    this->PHB->setVolume(Volume);
    this->PHB->setMedia(QUrl::fromLocalFile("../BallGame/music/pol_hit_ball.wav"));

    //string url="https://doc.qt.io/qt-5/qmediaplayer.html#Error-enum";
    //if(this->PB->error()>0){
    //    cout<<"Error "<<this->PB->error()<<"Happend! "<<"See "<<url<<endl;
    //}
    assert(this->PB->isAvailable() && this->BHB->isAvailable() && this->PHB->isAvailable());
    // Something Bad happened, see error code above to know where is wrong.
}


