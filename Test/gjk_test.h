#ifndef GJK_TEST_H
#define GJK_TEST_H

#include <QWidget>
#include "bound.h"
#include "ball.h"
#include <thread>
#include <QTimer>

class GJK_Test : public QWidget
{
    Q_OBJECT
public:
    explicit GJK_Test(QWidget *parent = nullptr);
    Bound *bound = nullptr;
    Ball *ball = nullptr;
    Vector2* p1 = nullptr,*p2 = nullptr,*p3 = nullptr;
    void test1();
    void wait();
    void paintEvent(QPaintEvent *event);
    QPainter mpainter;
    QPixmap mp;
    QTimer timer;
signals:

public slots:
    void move();
};

#endif // GJK_TEST_H
