#ifndef STATESHOWER_H
#define STATESHOWER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QTimer>

class StateShower : public QWidget
{
    Q_OBJECT
public:
    explicit StateShower(QWidget *parent = nullptr);
    QLabel state;
    QLabel time;
    void resetTime();
signals:
    void timeOut();
public slots:
    void reduceTime();
private:
    QTimer timer;
};

#endif // STATESHOWER_H
