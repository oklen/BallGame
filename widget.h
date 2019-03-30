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

#define _DEBUG_
namespace Ui {
class Widget;
}


class MainWindow : public QWidget
{
    Q_OBJECT

    bool eventFilter(QObject* who,QEvent* event);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    Bound *bounds[6];
    Hole *holes[6];
    std::vector<Ball*> balls;

    void Reset();

    const int bound_width = 100;
    const int hole_size = bound_width*1.9;
    const int real_width = 3569;
    const int real_height = 1778;
    const int rev_scale = 3;
    const QColor holeColor = Qt::blue;
    const int hole_shift = 15;
    const int ball_radius = 11;

    const int used_bound_width = bound_width/rev_scale;
    ~MainWindow();
    friend class GameManger;

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
