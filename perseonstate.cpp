#include "perseonstate.h"
#include <QPalette>



PerseonState::PerseonState(QWidget *parent) : QWidget(parent),
    personImage{ *new QImage("../BallGame/images/Face.jpg")},
    name("Players"),Score(QString::number(0)),
    rank(QString(" 大师"))
{
    QFont personFont;
    personFont.setFamily("宋体");
    personFont.setPointSize(20);
    personFont.setBold(true);

    TextLabel *rankL = new TextLabel(QString("Rank:")+rank);
    rankL->setTextPos({0,30});
    rankL->TextSize = 20;
    rankL->useTransparent = true;

    TextLabel* nameLabel = new TextLabel(name);
    nameLabel->setFont(personFont);
//    rankL->setStyleSheet("color:gold;background-color: rgb(243,178,26)");

    TextLabel* scoreStaticLabel=new TextLabel("Score:");
    TextLabel* scoreDymicalLabel= new TextLabel(Score);

    scoreStaticLabel->setTextPos({0,30});
    scoreStaticLabel->TextSize = 20;

    scoreDymicalLabel->setTextPos({0,30});
    scoreDymicalLabel->TextSize = 20;

    nameLabel->setTextPos({0,30});
    nameLabel->TextSize = 20;

    scoreStaticLabel->useTransparent = true;
    scoreDymicalLabel->useTransparent = true;
    nameLabel->useTransparent = true;
//    scoreStaticLabel->setStyleSheet("color:rgb(135,206,235)");
//    scoreDymicalLabel->setStyleSheet("color:red");
//    scoreDymicalLabel->setFont(personFont);
    mScores = scoreDymicalLabel;
    scoreStaticLabel->setFont(personFont);

    QVBoxLayout* vlayout1 = new QVBoxLayout;
    QLabel* image = new QLabel;
    image->setFixedSize(QSize(130,100));
    image->setPixmap(QPixmap::fromImage(personImage).scaled(image->size()));

    vlayout1->addWidget(image);
    //vlayout1->addWidget(nameLabel);

    QVBoxLayout* vlayout2 = new QVBoxLayout;
    QHBoxLayout* hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(scoreStaticLabel);
    hlayout1->addWidget(scoreDymicalLabel);

    vlayout2->addWidget(rankL);
    vlayout2->addLayout(hlayout1);
    vlayout2->addWidget(nameLabel);

    QHBoxLayout* hlayout2 = new QHBoxLayout;
    hlayout2->addLayout(vlayout1);
    hlayout2->addLayout(vlayout2);
    setLayout(hlayout2);
}

void PerseonState::setScore(int in)
{
    mScores->setText(QString::number(in));
}


