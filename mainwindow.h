#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "perseonstate.h"
#include "stateshower.h"
#include "widget.h"
#include "Widgets/pausemenu.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(Board* board,QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);

    PerseonState * per[2];
    StateShower* stateShower;
    Board *board;
    PauseMenu *pauseMenu;
    ControlButton *startGame;
    void paintEvent(QPaintEvent *);
    ~MainWindow();
signals:
    void gamePause();
    void gameContinue();
public slots:
};

#endif // MAINWINDOW_H
