#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include "qtplugin_global.h"
#include "interface/qtplugininterface.h"
#include "cal.h"

class QTPLUGINSHARED_EXPORT QtPlugin : public QObject, public QtPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QtPluginInterfaceIID)
    Q_INTERFACES(QtPluginInterface)
public:
    QtPlugin();
    ~QtPlugin();
    virtual QObject *getObject() override;
private:
    Cal *m_cal = Q_NULLPTR;
};

#endif // QTPLUGIN_H
