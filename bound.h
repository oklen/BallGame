#ifndef BOUND_H
#define BOUND_H

#include <object.h>
#include <QWidget>
#include "lineobject.h"
#include "boundline.h"
#include <vector>
#include "Resouces/bound_shape.h"

class Bound : public Object
{
    Q_OBJECT
public:
    explicit Bound(QObject *parent = nullptr);
    Bound(int xpos, int ypos, int xspan, int yspan,QColor color=QColor(0,0,0,0));
    void draw(QPainter& painter);
    void setColor(QColor color);
    int xspan,yspan;
    std::vector<BoundLine*> lines;
    QPixmap *image = nullptr;
    QRect mrect;
signals:

public slots:
private:
    QRect m_rect;
};


#endif // BOUND_H
