#ifndef PERSEONSTATE_H
#define PERSEONSTATE_H

#include <QWidget>
#include <QBoxLayout>
#include <QPainter>
#include <QLabel>

class PerseonState : public QWidget
{
    Q_OBJECT
public:
    explicit PerseonState(QWidget *parent = nullptr);
    QImage personImage;
    QString name;
    QString rank;
    QString Score;
    bool myTurn = false;


signals:

public slots:

};

#endif // PERSEONSTATE_H
