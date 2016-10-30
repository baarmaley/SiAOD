#include "group.h"

Group::Group(QString &name, QObject *parent) : QObject(parent)
{
    session = new QVector<QString>;
    nameGroup = new QString(name);
}

Group::~Group()
{
    delete session;
    delete nameGroup;
}

void Group::clear()
{
    session->clear();
}
void Group::addSesion(QString &session)
{
    this->session->push_back(session);
}
