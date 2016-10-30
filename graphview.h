#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QMap>
#include <QtAlgorithms>

#include <vertexgraph.h>
#include <myelips.h>
#include "pointtopoint.h"

namespace Ui {
class GraphView;
}

//struct PointToPoint{
//    VertexGraph * first;
//    VertexGraph * second;
//    bool operator<(const PointToPoint &T) const
//    {
//        return (first < T.first | second < T.second);
//    }
//};

class GraphView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = 0);
    ~GraphView();



    void VertexAdd(QString &nameGroup, QString &nameSession);
    void VertexClear();

    void EdgeBuild();
    void EdgeClear();


signals:
    void UpdateZoom();

public slots:
    void ClearScene();
    void DrawGraph();

private slots:
    void on_btn_zoomPlus_clicked();

    void on_btn_zoomMinus_clicked();

    void graph_zoom();

    void DrawVertex();

    void DrawEdge(VertexGraph *, bool update = false);

    void EdgeUpdate();

    void AlgorithmColorize();

private:
    Ui::GraphView *ui;

    QGraphicsScene * scene;

    qreal Radius;
    qreal Diametr;
    qreal Zoom;

    QList<VertexGraph *> * vertex;
    //QList<PointToPoint> * edge;
    QMap<VertexGraph *, QList<VertexGraph *> *> * edge;
    QMap<VertexGraph *, QGraphicsItem *> * vertexCircle;
    QMap<PointToPoint, QGraphicsItem *> * edgeLine;

    QMultiHash<int, VertexGraph *> * MapColor;



};

#endif // GRAPHVIEW_H
