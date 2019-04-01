#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

class TextLabel : public QWidget
{
    Q_OBJECT
public:
    explicit TextLabel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);

    void scaleTo(QSize size);
    QPixmap image;
    void setText(QString in);
    void setPic(QString in);
    void setTextPos(QPoint  in);
    QGraphicsDropShadowEffect* effect;

    QPen mpen;

    bool useTransparent =false;
signals:

public slots:

private:
    QString content;
    QPoint textPos;
    QPainter mpainter;
signals:

public slots:
};

#endif // TEXTLABEL_H
