
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
    QString name;
    QString rank;
    QString Score;

    void setScore(int in);
    bool myTurn = false;

signals:

public slots:

private:
    TextLabel* mScores;
};

#endif // PERSEONSTATE_H
