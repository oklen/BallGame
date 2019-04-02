#include "musicmanger.h"
#include<assert.h>



void MusicManger::playBallHitBall()
{
    this->BHB->play();
}

void MusicManger::playPutBall()
{
    this->PB->play();
}

void MusicManger::playPolHitBall()
{
    this->PHB->play();
}

void MusicManger::doInitial()
{
    this->PB=new QMediaPlayer;
    this->PB->setVolume(this->Volume);
    this->PB->setMedia(QUrl::fromLocalFile("./music/pol_hit.wav"));

    this->BHB=new QMediaPlayer;
    this->BHB->setVolume(this->Volume);
    this->BHB->setMedia(QUrl::fromLocalFile("./music/ball_hit_ball.wav"));

    this->PHB=new QMediaPlayer;
    this->PHB->setVolume(Volume);
    this->PHB->setMedia(QUrl::fromLocalFile("./music/pol_hit_ball.wav"));

    //string url="https://doc.qt.io/qt-5/qmediaplayer.html#Error-enum";
    //if(this->PB->error()>0){
    //    cout<<"Error "<<this->PB->error()<<"Happend! "<<"See "<<url<<endl;
    //}
    assert(this->PB->error()==0 && this->BHB->error()==0 && this->PHB->error()==0);

    // Something Bad happened, see error code above to know where is wrong.
}
