#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "bound.h"
#include "hole.h"
#include "ball.h"
#include "rounder.h"
#include <QMouseEvent>
#include <vector>
#include <math.h>
#include <QDebug>
#include <QTimer>

#include <deque>
#include "club.h"
#include "shootline.h"
#define _DEBUG_
namespace Ui {
class Widget;
}


class Board : public QWidget
{
    Q_OBJECT

    bool eventFilter(QObject* who,QEvent* event);

public:
    explicit Board(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    Bound *bounds[6];
    Hole *holes[6];
    Club *club;
    ShootLine *shootline;
    std::deque<Ball*> balls;
    bool NoOneMove = true;

    void Reset();

    const float bound_width = 100;
    const float hole_size = bound_width*1.9;
    const int real_width = 3569;
    const int real_height = 1778;
    const float rev_scale = real_width/1920.0;
    const QColor holeColor = Qt::blue;
    const float hole_shift = 40;
    const float ball_radius = 18;

    const float used_bound_width = bound_width/rev_scale;
    ~Board();
    friend class GameWorker;

signals:
    void PushBall();
public slots:
    void doUpdate();

private:
    int selectedIndex;
    int mousex,mousey;
    QPainter mpainter;
    Ui::Widget *ui;
    QPen vectpen;
    rounder rd;
};

#endif // WIDGET_H
