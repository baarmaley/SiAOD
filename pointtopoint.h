#ifndef POINTTOPOINT_H
#define POINTTOPOINT_H
#include "vertexgraph.h"

class PointToPoint
{
public:
    PointToPoint(VertexGraph * first, VertexGraph * second);
    //PointToPoint(const PointToPoint &);
    ~PointToPoint();

    bool operator<(const PointToPoint &) const;
    QString GetName();
private:
    VertexGraph * first;
    VertexGraph * second;
    //QString * compare;
    quint16 checksum;
};

#endif // POINTTOPOINT_H
