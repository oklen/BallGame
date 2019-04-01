#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QBitmap>
#include <QDebug>

class ControlButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ControlButton(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    QPixmap image;
    QPainter mpainter;
    void setText(QString in);
signals:

public slots:
private:
    QString content;
};

#endif // CONTROLBUTTON_H
