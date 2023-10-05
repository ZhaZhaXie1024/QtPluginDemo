#include "qtplugin.h"
#include "interface/qtpluginstruct.h"
#include <QMetaType>
#include <QSharedPointer>

QtPlugin::QtPlugin()
{
    qRegisterMetaType<qt_o_plugin::MData>("qt_o_plugin::MData");
    qRegisterMetaType<qt_o_plugin::MData>("qt_o_plugin::MData&");
    qRegisterMetaType<qt_o_plugin::MData*>("qt_o_plugin::MData*");
    qRegisterMetaType< QSharedPointer<qt_o_plugin::MData> >("QSharedPointer<qt_o_plugin::MData>");
}

QtPlugin::~QtPlugin()
{
    if(m_cal) {
        m_cal->deleteLater();
    }
}

QObject *QtPlugin::getObject()
{
    if(!m_cal) {
        m_cal = new Cal;
    }
    return m_cal;
}
