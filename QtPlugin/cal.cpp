#include "cal.h"
#include "interface/qtpluginstruct.h"
#include <QSharedPointer>

Cal::Cal(QObject *parent) : PublicObject()
{
    this->setParent(parent);
}

void Cal::doSome(QString type, QVariant v)
{
    if(type.compare("1") == 0) {
        emit result(type, handle1(v));
    }
    else if(type.compare("2") == 0) {
        emit result(type, handle2(v));
    }
    else if(type.compare("3") == 0) {
        emit result(type, handle3(v));
    }
    else if(type.compare("4") == 0) {
        emit result(type, handle4(v));
    }
}

int Cal::handle1(QVariant v)
{
    int value = v.toInt();
    return value + 1;
}

QVariant Cal::handle2(QVariant v)
{
    qt_o_plugin::MData data;
    data.num = v.toInt();
    data.name = "(handle2)my name:" + QString::number(v.toInt());
    QVariant value;
    value.setValue(data);
    return value;
}

QVariant Cal::handle3(QVariant v)
{
    qt_o_plugin::MData *data = new qt_o_plugin::MData;
    data->num = v.toInt();
    data->name = "(handle3)my name:" + QString::number(v.toInt());
    QVariant value;
    value.setValue(data);
    return value;
}

QVariant Cal::handle4(QVariant v)
{
    QSharedPointer<qt_o_plugin::MData> data(new qt_o_plugin::MData);
    data->num = v.toInt();
    data->name = "(handle4)my name:" + QString::number(v.toInt());
    QVariant value;
    value.setValue(data);
    return value;
}
