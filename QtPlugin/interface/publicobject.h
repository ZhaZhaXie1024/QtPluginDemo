#ifndef PUBLICINTERFACE_H
#define PUBLICINTERFACE_H

#include <QObject>
#include <QString>
#include <QVariant>

class PublicObject : public QObject{
    Q_OBJECT
public:
    PublicObject(){}
    ~PublicObject() = default;

public slots:
    virtual void doSome(QString type, QVariant v) = 0;

signals:
    void result(QString type, QVariant v);
};

#endif // PUBLICINTERFACE_H
