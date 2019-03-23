#ifndef BOUND_H
#define BOUND_H

#include <object.h>
#include <QWidget>

class Bound : public Object
{
    Q_OBJECT
public:
    explicit Bound(QObject *parent = nullptr);
    Bound(int xpos, int ypos, int xspan, int yspan,QColor color=QColor(Qt::red));
    void draw(QPainter& painter);
    void setColor(QColor color);
    int xspan,yspan;
signals:

public slots:
private:
    QRect m_rect;
};


#endif // BOUND_H