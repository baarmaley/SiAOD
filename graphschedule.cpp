#include "graphschedule.h"

GraphSchedule::GraphSchedule()
{
    vertex = new QList<VertexGraph *>;
    edge = new  QMap<VertexGraph *, QList<VertexGraph *> *>;
}

GraphSchedule::~GraphSchedule()
{
    vertex->clear();
    delete vertex;

    delete edge;
}

void GraphSchedule::VertexAdd(QString &nameGroup, QString &nameSession)
{
    VertexGraph * vert = new VertexGraph(nameGroup, nameSession);
    this->vertex->append(vert);
}

void GraphSchedule::VertexClear()
{
    EdgeClear();
    while(!vertex->isEmpty())
    {
       delete vertex->takeAt(0);
    }
    vertex->clear();
}

QStringList GraphSchedule::GraphString()
{
    QStringList vertexStr;
    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        QString str = ("(" + (*it)->GetNameGroup() + ":" + (*it)->GetNameSession() + "):");

        QMap<VertexGraph *, QList<VertexGraph *> *>::Iterator mapIt = edge->find(*it);

        if(mapIt != edge->end())
        {
           QList<VertexGraph *> * list = mapIt.value();
           for(QList<VertexGraph *>::Iterator listIt = list->begin(); listIt != list->end(); listIt++)
           {
               str += "[" + (*listIt)->GetNameGroup() + ":" + (*listIt)->GetNameSession() + "]";
           }
        }

        vertexStr << str;

    }
    return vertexStr;
}

QStringList GraphSchedule::VertexString()
{
    QStringList vertexStr;
    for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
    {
        vertexStr << ("(" + (*it)->GetNameGroup() + ":" + (*it)->GetNameSession() + ")");
    }
    return vertexStr;
}

void GraphSchedule::EdgeBuild()
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

    }

}

void GraphSchedule::EdgeClear()
{
    while(!edge->isEmpty())
    {
        for(QList<VertexGraph *>::Iterator it = vertex->begin(); it != vertex->end(); it++)
        {
            QList<VertexGraph *> * vert = edge->take((*it));
            delete vert;
        }
    }
    edge->clear();
}
