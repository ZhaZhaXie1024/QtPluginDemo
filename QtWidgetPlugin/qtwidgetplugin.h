#ifndef QTWIDGETPLUGIN_H
#define QTWIDGETPLUGIN_H

#include "qtwidgetplugin_global.h"
#include "interface/qtwidgetplugininterface.h"
#include "form.h"

class QTWIDGETPLUGINSHARED_EXPORT QtWidgetPlugin : public QObject, public QtWidgetPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QtWidgetPluginInterfaceIID)
    Q_INTERFACES(QtWidgetPluginInterface)
public:
    QtWidgetPlugin();
    ~QtWidgetPlugin();

    QWidget* getWidget() override;

private:
    Form *m_form = Q_NULLPTR;
};

#endif // QTWIDGETPLUGIN_H
