#ifndef CAL_H
#define CAL_H

#include "interface/publicobject.h"

class Cal : public PublicObject
{
    Q_OBJECT
public:
    explicit Cal(QObject *parent = nullptr);

public slots:
    virtual void doSome(QString type, QVariant v) override;

private:
    int handle1(QVariant v);
    QVariant handle2(QVariant v);
    QVariant handle3(QVariant v);
    QVariant handle4(QVariant v);
};

#endif // CAL_H
