#include "vertexgraph.h"

bool SortingVertexRank(const VertexGraph *V1, const VertexGraph *V2)
{
    return V1->GetRank() < V2->GetRank();
}

VertexGraph::VertexGraph(QString &nameGroup, QString &nameSession, QObject *parent) : QObject(parent)
{
    this->nameGroup = new QString(nameGroup);
    this->nameSession = new QString(nameSession);
    color = 0;
    rank = 0;
    //ListToVertex = new QList<VertexGraph *>;
}

VertexGraph::~VertexGraph()
{
    delete nameGroup;
    delete nameSession;
    //delete ListToVertex;
}

void VertexGraph::SetColor(int c)
{
    color = c;
    emit ChangeColor(c);
}
void VertexGraph::ClearColor()
{
    color = 0;
    emit ChangeColor(0);
}
int VertexGraph::GetColor()
{
    return color;
}

//void VertexGraph::VertexClear()
//{
//    ListToVertex->clear();
//}

//void VertexGraph::VertexAdd(VertexGraph * vertex)
//{
//    ListToVertex->append(vertex);
//}

