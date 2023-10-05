#ifndef QTPLUGINSTRUCT_H
#define QTPLUGINSTRUCT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <QSharedPointer>

namespace qt_o_plugin {

    struct MData
    {
        MData(): num(0) {}
        int num;
        QString name;
    };
}

Q_DECLARE_METATYPE(qt_o_plugin::MData)
Q_DECLARE_METATYPE(qt_o_plugin::MData*)
Q_DECLARE_METATYPE(QSharedPointer<qt_o_plugin::MData>)

#endif // QTPLUGINSTRUCT_H
