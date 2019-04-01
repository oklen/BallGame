#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QWidget>
#include "controlbutton.h"
#include <QVBoxLayout>

class PauseMenu : public QWidget
{
    Q_OBJECT
public:
    explicit PauseMenu(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent* event);
    ControlButton *resume;
    ControlButton *restart;
    ControlButton *quit;

    QPainter mpainter;
signals:

public slots:
};

#endif // PAUSEMENU_H
