#ifndef QTWIDGETPLUGINSTRUCT_H
#define QTWIDGETPLUGINSTRUCT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <QSharedPointer>
#include <QList>

namespace qt_w_plugin {

    struct MData
    {
        MData(): num(0) {}
        int num;
        QString name;
    };
}

Q_DECLARE_METATYPE(qt_w_plugin::MData)
Q_DECLARE_METATYPE(qt_w_plugin::MData*)
Q_DECLARE_METATYPE(QSharedPointer<qt_w_plugin::MData>)
Q_DECLARE_METATYPE(QList<qt_w_plugin::MData>)

#endif // QTWIDGETPLUGINSTRUCT_H
