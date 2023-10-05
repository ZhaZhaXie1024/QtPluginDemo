#ifndef QTPLUGININTERFACE_H
#define QTPLUGININTERFACE_H

#include <QObject>

//每一个插件都需要创建一个自己的抽象类
//定义一个不重复的 IID
#define QtPluginInterfaceIID "com.yuming.QtPluginInterface/1.0.0"

class QtPluginInterface {
public:
    virtual ~QtPluginInterface() = default;
    virtual QObject* getObject() = 0;
};

//将IID和接口绑定           接口类名               IID
Q_DECLARE_INTERFACE(QtPluginInterface, QtPluginInterfaceIID);

#endif // QTPLUGININTERFACE_H
