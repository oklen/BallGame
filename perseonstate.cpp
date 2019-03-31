#include "perseonstate.h"
#include <Qpalette>



PerseonState::PerseonState(QWidget *parent) : QWidget(parent),
    personImage{ *new QImage("/root/图片/Lambda.png")},
    name(""),Score(QString::number(0)),
    rank(QString(" 大师"))
{
    QFont personFont;
    personFont.setFamily("宋体");
    personFont.setPointSize(30);
    personFont.setBold(true);

    QLabel *rankL = new QLabel(QString("Rank:")+rank);
    rankL->setFont(personFont);
    QLabel* nameLabel = new QLabel(name);
    nameLabel->setFont(personFont);

    rankL->setStyleSheet("color:gold");

    QLabel* scoreStaticLabel=new QLabel("Score:");
    QLabel* scoreDymicalLabel=new QLabel(Score);
    scoreStaticLabel->setStyleSheet("color:rgb(135,206,235)");
    scoreDymicalLabel->setStyleSheet("color:red");
    scoreDymicalLabel->setFont(personFont);
    scoreStaticLabel->setFont(personFont);

    QVBoxLayout* vlayout1 = new QVBoxLayout;
    QLabel* image = new QLabel;
    image->setPixmap(QPixmap::fromImage(personImage).scaled(80,80));

    vlayout1->addWidget(image);
    vlayout1->addWidget(nameLabel);

    QVBoxLayout* vlayout2 = new QVBoxLayout;
    QHBoxLayout* hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(scoreStaticLabel);
    hlayout1->addWidget(scoreDymicalLabel);

    vlayout2->addWidget(rankL);
    vlayout2->addLayout(hlayout1);

    QHBoxLayout* hlayout2 = new QHBoxLayout;
    hlayout2->addLayout(vlayout1);
    hlayout2->addLayout(vlayout2);
    setLayout(hlayout2);
}

