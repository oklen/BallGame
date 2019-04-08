
#ifndef PERSEONSTATE_H
#define PERSEONSTATE_H

#include <QWidget>
#include <QBoxLayout>
#include <QPainter>
#include <QLabel>
#include "Widgets/textlabel.h"

class PerseonState : public QWidget
{
    Q_OBJECT
public:
    explicit PerseonState(QWidget *parent = nullptr);
    QImage personImage;
    QString rank;
    QString Score;

    TextLabel* nameLabel;
    void setScore(int in);
    bool myTurn = false;

signals:

public slots:

private:
    TextLabel* mScores;
};

#endif // PERSEONSTATE_H
