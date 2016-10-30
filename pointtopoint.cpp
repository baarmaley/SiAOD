#include "pointtopoint.h"

PointToPoint::PointToPoint(VertexGraph *first, VertexGraph *second)
{
    this->first = first;
    this->second = second;

    QString str1(first->GetNameGroup() + first->GetNameSession());
    QString str2(second->GetNameGroup() + second->GetNameSession());
    checksum = qChecksum(str1.toLocal8Bit().data(), str1.length()) +
            qChecksum(str2.toLocal8Bit().data(), str2.length());

}



PointToPoint::~PointToPoint()
{
    //delete compare;
}

bool PointToPoint::operator<(const PointToPoint &T) const
{
    return checksum < T.checksum;
}

QString PointToPoint::GetName()
{
    return QString("(" + first->GetNameGroup() + ":" + first->GetNameSession() + ")"
                   + "(" + second->GetNameGroup() + ":" + second->GetNameSession() + ")");
}


