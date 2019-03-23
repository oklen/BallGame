#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QPainter>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);
    Object(int x,int y,QColor color);
    virtual void draw(QPainter& painter) = 0;
    int x,y;
    bool selected =false;
signals:

public slots:

protected:
    QColor m_color;
    QBrush m_brush;
};

#endif // OBJECT_H
