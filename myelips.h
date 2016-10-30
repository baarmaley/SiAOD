#ifndef MYELIPS_H
#define MYELIPS_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
class MyElips : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    MyElips(QGraphicsItem *parent = 0);
    ~MyElips();


//    void setBrush(const QBrush & brush);
    void setPen(const QPen & pen);

    void setAllocated(bool);

    bool isPressed() const
    {
        return pressed;
    }

    void setColor(QColor);
    QColor getColor() const;

signals:


    void MousePress();
    void MouseRelease();
    void MouseMove();

private:
    //QBrush * Brush;
    QColor * Color;

    QPen * Pen;
    qreal Diametr;
    bool pressed;
    bool allocated;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



private slots:



protected:

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);


};

#endif // MYELIPS_H
