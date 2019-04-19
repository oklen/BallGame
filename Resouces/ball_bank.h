#ifndef BALL_BANK_H
#define BALL_BANK_H

#include <QPixmap>
#include "Widgets/object.h"
#include <QDebug>

#define    NAME(name)    (#name)
class Ball_Bank
{
public:
    Ball_Bank();
    static QPixmap* getBallImage(int in);
private:
    static Ball_Bank* instance();
    QPixmap* red = new QPixmap("../BallGame/images/red.png");
    QPixmap* black= new QPixmap("../BallGame/images/black.png");
    QPixmap* brown= new QPixmap("../BallGame/images/brown.png");
    QPixmap* pink= new QPixmap("../BallGame/images/pink.png");
    QPixmap* green= new QPixmap("../BallGame/images/green.png");
    QPixmap* white= new QPixmap("../BallGame/images/white.png");
    QPixmap* yellow= new QPixmap("../BallGame/images/yellow.png");
    QPixmap* blue= new QPixmap("../BallGame/images/blue.png");
    static Ball_Bank *p;
};

#endif // BALL_BANK_H
