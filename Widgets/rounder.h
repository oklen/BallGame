#ifndef ROUNDER_H
#define ROUNDER_H

#include "object.h"
#include <QString>
#include <QDebug>

class rounder:public Object
{
public:
    rounder(int x,int y,int size=10);
    void setRound(int who);
    void draw(QPainter& mpainter);
    bool showTurns = false;
public slots:
    void close();
private:
    QPen mpen;
    QString strs;
    QFont font;
};

#endif // ROUNDER_H
