#include "graphview.h"
#include "ui_graphview.h"
#include <qmath.h>
#include <QGraphicsItem>
#include <QMap>
#include <qmath.h>


GraphView::GraphView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphView)
{
    ui->setupUi(this);

    vertex = new QList<VertexGraph *>;
    edge = new QMap<VertexGraph *, QList<VertexGraph *> *>;

    scene = new QGraphicsScene;
    vertexCircle = new QMap<VertexGraph *, QGraphicsItem *>;
    edgeLine = new QMap<PointToPoint, QGraphicsItem *>;
    MapColor = new QMultiHash<int, VertexGraph *>;

    //scene->setSceneRect(-150, -150, 300, 300);
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setCursor(Qt::ArrowCursor);
//    ui->graphicsView->setInteractive(false);




    //scene->setSceneRect(0, 0, 600, 600);
    connect(this, SIGNAL(UpdateZoom()), this, SLOT(graph_zoom()));

    connect(ui->btn_colorize, SIGNAL(clicked()), this, SLOT(AlgorithmColorize()));

    Radius = 100;
    Zoom = 0;
    Diametr = 35;

}

GraphView::~GraphView()
{

    VertexClear();

    delete edge;
    delete scene;
    delete vertex;
    delete vertexCircle;
    delete edgeLine;
    delete ui;

}

void GraphView::VertexAdd(QString &nameGroup, QString &nameSession)
{
    VertexGraph * vert = new VertexGraph(nameGroup, nameSession);
    MyElips * circle = new MyElips;

    //connect(circle, SIGNAL(MouseRelease()), this, SLOT(DrawGraph()));
    //connect(circle, SIGNAL(MouseMove()), this, SLOT(EdgeUpdate()));
    connect(circle, SIGNAL(MouseRelease()), this, SLOT(EdgeUpdate()));
    connect(circle, SIGNAL(MousePress()), this, SLOT(EdgeUpdate()));

    //connect(vert, SIGNAL(ChangeColor(int)), circle, SLOT(setColor(int)));

    circle->setToolTip(QString("(" + nameGroup + ":" + nameSession + ")"));

    //scene->addText(*(new QString("(" + nameGroup + ":" + nameSession + ")")));

    //circle->setRect(0,0, Diametr, Diametr);
    //circle->setColor(QColor::fromHsv(30, 255, 255));
    this->vertex->append(vert);
    vertexCircle->insert(vert,(QGraphicsItem *) circle);
}

void GraphView::VertexClear()
{
    ClearScene();
    EdgeClear();

    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        QGraphicsItem * elips = vertexCircle->take(*it);
        delete elips;
    }

    vertexCircle->clear();


    while(!vertex->isEmpty())
    {
       delete vertex->takeAt(0);
    }
    vertex->clear();
}

void GraphView::EdgeBuild()
{
    EdgeClear();
    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        QList<VertexGraph *> * ListEdge = new QList<VertexGraph *>;
        edge->insert(*it, ListEdge);

        //Создаем ребра
        for(QList<VertexGraph *>::Iterator subIt = vertex->begin(); subIt != vertex->end(); subIt++)
        {

            if(subIt != it)
            {
                // Создаем ребро
                if((*it)->GetNameGroup() == (*subIt)->GetNameGroup() ||
                        (*it)->GetNameSession() == (*subIt)->GetNameSession())
                {
                    ListEdge->append((*subIt));
                }
            }

        }

        (*it)->SetRank(ListEdge->size());

    }

}

void GraphView::EdgeClear()
{
    edgeLine->clear();

    while(!edge->isEmpty())
    {
        for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
        {
            QList<VertexGraph *> * vert = edge->take((*it));
            delete vert;
            (*it)->ClearRank();
        }
    }
    edge->clear();
}




void GraphView::ClearScene()
{
   if(scene->items().size() > 0)
   {
       QList<VertexGraph *> vert = vertexCircle->keys();
       for(QList<VertexGraph *>::Iterator it = vert.begin(); it != vert.end(); it++)
       {
           QMap<VertexGraph *, QGraphicsItem *>::Iterator  itCircle = vertexCircle->find((*it));
           if(itCircle != vertexCircle->end())
           {
               scene->removeItem(*itCircle);
           }
       }
   }

   scene->clear();
}


void GraphView::DrawGraph()
{
    ClearScene();


    DrawVertex();


    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        DrawEdge((*it));
    }

}


void GraphView::DrawVertex()
{
    qreal x0 = 0, y0 = 0, angle = 0;
    qreal rotate = 6.28 / vertex->size();

    // Создаем вершины графа
    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
         QMap<VertexGraph *, QGraphicsItem *>::Iterator  itCircle = vertexCircle->find((*it));
         if(itCircle != vertexCircle->end())
         {
             MyElips * elips = (MyElips *) *itCircle;

             qreal x = elips->sceneBoundingRect().x(), y = elips->sceneBoundingRect().y();
             qreal lengthVector = qSqrt(x*x + y*y);

             if(lengthVector <= 0)
                 lengthVector = Radius;

             elips->setPos(QPointF(x0 + lengthVector*qSin(angle), y0 + lengthVector*qCos(angle)));

             scene->addItem(*itCircle);

             elips->setZValue(1);

             angle += rotate;
         }
    }

}

void GraphView::DrawEdge(VertexGraph * vertex, bool update)
{

    QPointF point_start = ((MyElips *)vertexCircle->value(vertex))->sceneBoundingRect().center();
    bool pressed = ((MyElips *)vertexCircle->value(vertex))->isPressed();

    QMap<VertexGraph *, QList<VertexGraph *> *>::Iterator itList = edge->find(vertex);

    if(itList != edge->end())
    {
        // Проходим по списку вершин
        for(QList<VertexGraph *>::Iterator itVertex = (*itList)->begin(); itVertex != (*itList)->end(); itVertex++)
        {


           PointToPoint ptp(vertex, *itVertex);
           QMap<PointToPoint, QGraphicsItem *>::Iterator itLine = edgeLine->find(ptp);
           MyElips * elips = ((MyElips *)vertexCircle->value(*itVertex));
           QPointF point_end = elips->sceneBoundingRect().center();


           if(itLine == edgeLine->end())
           {

               //qDebug() << ptp.GetName();

               QGraphicsItem * line = (QGraphicsItem *) scene->addLine(point_start.x(), point_start.y(),
                                                                       point_end.x(), point_end.y());
               edgeLine->insert(ptp, line);
           }
           else if(update)
           {
               QGraphicsLineItem * line = ((QGraphicsLineItem *)(*itLine));
               line->setLine(point_start.x(), point_start.y(), point_end.x(), point_end.y());
               if(pressed)
               {
                   QColor color = elips->getColor();
                   line->setPen(QPen((color == Qt::white) ? Qt::black : color , 2));
                   elips->setAllocated(true);
                   //elips->setBrush(QBrush(Qt::green));
               }
               else
               {
                   line->setPen(QPen(Qt::black, 0));
                   elips->setAllocated(false);
                   //elips->setBrush(QBrush(Qt::white));
               }
           }
        }
    }
}

void GraphView::EdgeUpdate()
{
    MyElips * elips = (MyElips *) sender();
    VertexGraph * vertex = vertexCircle->key(elips);

    DrawEdge(vertex, true);

}


void GraphView::on_btn_zoomPlus_clicked()
{
    Zoom -= 30;
    emit UpdateZoom();
}

void GraphView::on_btn_zoomMinus_clicked()
{

    Zoom += 30;
    emit UpdateZoom();
}

void GraphView::graph_zoom()
{
    QList<QGraphicsItem * > listItem = vertexCircle->values();

    for(QList<QGraphicsItem * >::Iterator it = listItem.begin(); it != listItem.end(); it++)
    {
        MyElips * elips = (MyElips *) *it;
        qreal x = elips->pos().x();
        qreal y = elips->pos().y();
        qreal arctg = qAtan(x/y);

        qreal lengthVector = qSqrt(x*x + y*y);

        if(lengthVector <= Radius + 10 && Radius - 10 < lengthVector
                && Zoom > 0)
            continue;

        if(y > 0)
        {
            x -= Zoom*qSin(arctg);
            y -= Zoom*qCos(arctg);
        }
        else
        {
            x += Zoom*qSin(arctg);
            y += Zoom*qCos(arctg);
        }

        elips->setPos(QPointF(x, y));

    }
    Zoom = 0;

    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        DrawEdge((*it), true);
    }

}



void GraphView::AlgorithmColorize()
{

    MapColor->clear();

    //qSort(vertex->begin(), vertex->end(), SortingVertexRank);

    for(auto it = vertex->begin(); it != vertex->end(); it++)
    {
        (*it)->ClearColor();
    }

    int color = 1;

    auto ItVertex = vertex->begin();

    QSet<VertexGraph *> VertexColor;

    while(1)
    {
        if(ItVertex == vertex->end())
            break;

        if((*ItVertex)->GetColor() > 0)
        {
            ItVertex++;
            continue;
        }

        (*ItVertex)->SetColor(color);
        VertexColor << *ItVertex;


        QSet<VertexGraph *> tempVertex = vertex->toSet(); // Список всех вершин
        tempVertex.subtract(VertexColor);                 // Удаляем выбраную вершину

        auto ListEdge = edge->find(*ItVertex); // Получаем список ребер

        if(ListEdge != edge->end())
        {
            tempVertex.subtract((*ListEdge)->toSet());
        }

        auto ItTempVertex = tempVertex.begin();

        while(1)
        {

            if(ItTempVertex == tempVertex.end())
                break;

            (*ItTempVertex)->SetColor(color);
            VertexColor << *ItTempVertex;



            //if(tempVertex.size() =< 1)
            //    break;


            QMap<VertexGraph *, QList<VertexGraph *> *>::Iterator SubItEdge = edge->find(*ItTempVertex);


            tempVertex -= (*ItTempVertex);


            // Если есть ребра удаляем
            if(SubItEdge != edge->end())
            {
                QList<VertexGraph *> * SubListEdge = (*SubItEdge);
                tempVertex.subtract(SubListEdge->toSet());
            }


            ItTempVertex = tempVertex.begin();



        }


        if(ItVertex != vertex->end())
        {
            ItVertex++;
            color++;
        }
        else
            break;
    }

    qreal H = 360. / (color - 1);

    //qDebug() << QColor::fromHsv(180, 255, 255);

    //qDebug() << H;
    for(QMap<VertexGraph *, QGraphicsItem *>::Iterator it = vertexCircle->begin(); it != vertexCircle->end(); it++)
    {

        int c = it.key()->GetColor();


        MyElips * elips = (MyElips *)*it;
        elips->setColor(QColor::fromHsv(int(H*c)%360, 255, 255));


    }

    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        MapColor->insert((*it)->GetColor(), *it);
    }

    qDebug() << MapColor->keys();

    ui->le_CountColor->setText(QString::number(color));

    qDebug() << "Fine!";
}










