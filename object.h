#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QPainter>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);
    Object(float x,float y,QColor color);
    virtual void draw(QPainter& painter) = 0;
    double x,y;
    bool showOn = false;
    void setBrush(const QBrush &brush);

    void setPen(const QPen &pen);

signals:

public slots:

protected:
    QPen m_pen;
    QColor m_color;
    QBrush m_brush;
};

#endif // OBJECT_H
