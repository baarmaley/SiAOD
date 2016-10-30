#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include <QVector>

class Group : public QObject
{
    Q_OBJECT

    QVector<QString> * session;
    QString * nameGroup;

public:
    explicit Group(QString &, QObject *parent = 0);
    ~Group();


    void addSesion(QString &);
    void clear();

    QString getName();


signals:

public slots:
};

#endif // GROUP_H
