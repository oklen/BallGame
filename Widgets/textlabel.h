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
    TextLabel(QString in);
    void paintEvent(QPaintEvent* event);

    void scaleTo(QSize size);
    QPixmap image;
    void setText(QString in);
    void setPic(QString in);
    void setTextPos(QPoint  in);
    QGraphicsDropShadowEffect* effect;

    QPen mpen;
    int TextSize;

    bool useTransparent =false;

    QString content;

signals:

public slots:

private:
    QPoint textPos;
    QPainter mpainter;
signals:

public slots:
};

#endif // TEXTLABEL_H
