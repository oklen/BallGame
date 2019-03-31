#include "perseonstate.h"

PerseonState::PerseonState(QWidget *parent) : QWidget(parent),
    personImage{ *new QImage("/root/图片/Lambda.png")},
    name("Robert"),Score(QString::number(0)),
    rank(QString("大师"))
{
    QVBoxLayout* vlayout1 = new QVBoxLayout;
    QLabel* image = new QLabel;
    image->setPixmap(QPixmap::fromImage(personImage).scaled(80,80));
    QLabel* nameLabel = new QLabel(name);
    vlayout1->addWidget(image);
    vlayout1->addWidget(nameLabel);

    QVBoxLayout* vlayout2 = new QVBoxLayout;
    QLabel *rankL = new QLabel(QString("Rank:")+rank);

    QHBoxLayout* hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(new QLabel("Score:"));
    hlayout1->addWidget(new QLabel(Score));

    vlayout2->addWidget(rankL);
    vlayout2->addLayout(hlayout1);

    QHBoxLayout* hlayout2 = new QHBoxLayout;
    hlayout2->addLayout(vlayout1);
    hlayout2->addLayout(vlayout2);
    setLayout(hlayout2);
}
