#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "bound.h"
#include "hole.h"

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

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    Bound *bounds[6];
    Hole *holes[6];
    ~MainWindow();

private:
    QPainter mpainter;
    Ui::Widget *ui;
};

#endif // WIDGET_H
