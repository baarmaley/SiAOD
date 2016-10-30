#include "myelips.h"

MyElips::MyElips(QGraphicsItem *parent)
{
    Diametr = 35;
    pressed = false;
    allocated = false;
    //Brush = new QBrush(QColor::fromHsv(0, 255, 255));
    Color = new QColor(Qt::white);
    Pen = new QPen(Qt::black);

    //setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    //connect(this, SIGNAL(MouseRelease()), this, SLOT(UpdatePos()));
}

MyElips::~MyElips()
{
    //delete Brush;
    delete Color;
    delete Pen;
}

QRectF MyElips::boundingRect() const
{

    return QRectF(0,0,Diametr, Diametr);
}

void MyElips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(*Pen);

//    if(!pressed)
//    {
//        if(!allocated)
//        {
//            qDebug() << "paint: " << *Color;
//            painter->setBrush(QBrush(*Color));
//        }
//            else
//            painter->setBrush(QBrush(Qt::green));
//    }
//    else
//        painter->setBrush(QBrush(Qt::red));

    painter->setBrush(QBrush(*Color));

    QRectF rect = boundingRect();
    painter->drawEllipse(rect);

    if(!pressed)
    {
        if(!allocated)
        {
           painter->setPen(QPen(Qt::black, 0));
           painter->setBrush(QBrush(*Color));
        }
        else
        {
           //painter->setPen(QPen(*Color, 4));
            painter->setBrush(QBrush(Qt::DiagCrossPattern));
        }
    }
    else
        painter->setBrush(QBrush(Qt::DiagCrossPattern));


    painter->drawEllipse(rect);
    //  `painter->drawText(35,35, "Test");


}

void MyElips::setColor(QColor c)
{
    //qDebug() << "set after: " << c.convertTo(QColor::Rgb);
    *Color = c.convertTo(QColor::Rgb);
    //Brush->setColor(c);

    //qDebug() << "set before: " << *Color;
    update();
}

QColor MyElips::getColor() const
{
    return QColor(*Color);
}


void MyElips::setPen(const QPen &pen)
{
    delete Pen;
    Pen = new QPen(pen);
    update();
    //emit(klp());
}

void MyElips::setAllocated(bool a)
{
    allocated = a;
    update();
}



void MyElips::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsItem::mouseMoveEvent(event);
    emit MouseMove();

}




void MyElips::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press";
//    qDebug() << "Press x:" << event->scenePos().x() << " y: " <<event->scenePos().y();

    pressed = true;
    update();
    emit MousePress();
    QGraphicsItem::mousePressEvent(event);

}

void MyElips::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Release";
//    qDebug() << "Release x:" << event->scenePos().x() << " y: " <<event->scenePos().y();

    pressed = false;
    update();
    emit MouseRelease();
    QGraphicsItem::mouseReleaseEvent(event);
}




