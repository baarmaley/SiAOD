#ifndef GRAPHSCHEDULE_H
#define GRAPHSCHEDULE_H

#include <QObject>
#include "vertexgraph.h"
#include <QStringList>
#include <QMap>
class GraphSchedule
{
    QList<VertexGraph *> * vertex;
    QMap<VertexGraph *, QList<VertexGraph *> *> * edge;

public:
    GraphSchedule();
    ~GraphSchedule();

    void VertexAdd(QString &nameGroup, QString &nameSession);
    void VertexClear();

    void EdgeBuild();
    void EdgeClear();

    QStringList GraphString();
    QStringList VertexString();




};

#endif // GRAPHSCHEDULE_H
