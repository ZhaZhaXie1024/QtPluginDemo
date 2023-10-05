#include "qtwidgetplugin.h"
#include "interface/qtwidgetpluginstruct.h"

QtWidgetPlugin::QtWidgetPlugin()
{
    qRegisterMetaType<qt_w_plugin::MData>("qt_w_plugin::MData");
    qRegisterMetaType<qt_w_plugin::MData>("qt_w_plugin::MData&");
    qRegisterMetaType<qt_w_plugin::MData*>("qt_w_plugin::MData*");
    qRegisterMetaType< QSharedPointer<qt_w_plugin::MData> >("QSharedPointer<qt_w_plugin::MData>");
    qRegisterMetaType< QList<qt_w_plugin::MData> >("QList<qt_w_plugin::MData>");
}

QtWidgetPlugin::~QtWidgetPlugin()
{
    if(m_form) {
        m_form->hide();
        if(m_form->parent())
            m_form->setParent(nullptr);
        m_form->deleteLater();
    }
}

QWidget *QtWidgetPlugin::getWidget()
{
    if(!m_form) {
        m_form = new Form;
    }
    return m_form;
}
