#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "perseonstate.h"
#include "stateshower.h"
#include "widget.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(Board* board,QWidget *parent = nullptr);
    PerseonState * per[2];
    StateShower* stateShower;
    Board *board;
signals:

public slots:
};

#endif // MAINWINDOW_H
