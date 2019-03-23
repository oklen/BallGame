#ifndef TESTBOARD_H
#define TESTBOARD_H

#include <QWidget>
#include "ball.h"
#include <QTimer>

class TestBoard : public QWidget
{
    Q_OBJECT
public:
    static const int ball_amount = 1;
    explicit TestBoard(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent* event);

    Ball* balls[ball_amount];
private:
    QTimer timer;
signals:

public slots:
    void calMove();
};

#endif // TESTBOARD_H
