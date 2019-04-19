#ifndef STATESHOWER_H
#define STATESHOWER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QTimer>
#include "Widgets/textlabel.h"
#include <QDebug>

class StateShower : public QWidget
{
    Q_OBJECT
public:
    explicit StateShower(QWidget *parent = nullptr);
    TextLabel state;
    TextLabel time;
    void resetTime();

signals:
    void timeOut();
public slots:
    void reduceTime();
private:
    QTimer timer;
};

#endif // STATESHOWER_H
