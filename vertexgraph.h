#ifndef VERTEXGRAPH_H
#define VERTEXGRAPH_H

#include <QObject>



class VertexGraph : public QObject
{
    Q_OBJECT
    QString * nameGroup;
    QString * nameSession;
    //QList<VertexGraph *> * ListToVertex;
    int rank;
    int color;

public:
    explicit VertexGraph(QString &nameGroup, QString &nameSession, QObject *parent = 0);
    ~VertexGraph();

    void SetColor(int);
    void ClearColor();
    int GetColor();

    void SetRank(int R)
    {
        rank = R;
    }

    void ClearRank()
    {
        SetRank(0);
    }

    int GetRank() const
    {
        return rank;
    }

    QString GetNameGroup()
    {
        return QString(*nameGroup);
    }

    QString GetNameSession()
    {
        return QString(*nameSession);
    }

signals:

    void ChangeColor(int);

public slots:
};

bool SortingVertexRank(const VertexGraph * V1, const VertexGraph * V2);

#endif // VERTEXGRAPH_H
