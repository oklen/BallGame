#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsColorizeEffect>

class ControlButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ControlButton(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);


    QPixmap image;
    QPainter mpainter;
    void setText(QString in);
    void setPic(QString in);
    QGraphicsDropShadowEffect* effect;


signals:
    void mpress();
public slots:
private:
    QString content;
};

#endif // CONTROLBUTTON_H
