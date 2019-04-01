#include "pausemenu.h"

PauseMenu::PauseMenu(QWidget *parent) : QWidget(parent),
    resume(new ControlButton),restart(new ControlButton),
    quit(new ControlButton)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    resume->setText("继续游戏");
    restart->setText("重新开始");
    quit->setText("退出游戏");
    vlayout->addWidget(resume);
    vlayout->addWidget(restart);
    vlayout->addWidget(quit);
    setFixedSize(300,600);
    setLayout(vlayout);
}

void PauseMenu::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    mpainter.setPen(QPen(QColor(0,0,0,0)));
    mpainter.setBrush(QColor(0,0,0,0));
    mpainter.drawRect(rect());
    mpainter.end();
}
