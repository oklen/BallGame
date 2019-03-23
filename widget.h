#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "bound.h"
#include "hole.h"
#include "ball.h"
#include <QMouseEvent>
#include <vector>
#include <math.h>
#include <QDebug>
#define _DEBUG_
namespace Ui {
class Widget;
}


class MainWindow : public QWidget
{
    Q_OBJECT
    const int bound_width = 100;
    const int hole_size = bound_width*1.9;
    const int real_width = 3569;
    const int real_height = 1778;
    const int rev_scale = 3;
    const QColor holeColor = Qt::blue;
    const int hole_shift = 15;
    const int ball_radius = 11;
    bool eventFilter(QObject* who,QEvent* event);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    Bound *bounds[6];
    Hole *holes[6];
    std::vector<Ball*> balls;

    void Reset();
    ~MainWindow();

private:
    int selectedIndex;
    int mousex,mousey;
    QPainter mpainter;
    Ui::Widget *ui;
    QPen vectpen;
};

#endif // WIDGET_H
