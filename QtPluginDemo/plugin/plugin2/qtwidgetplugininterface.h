#ifndef QTWIDGETPLUGININTERFACE_H
#define QTWIDGETPLUGININTERFACE_H

#include <QWidget>

//每一个插件都需要创建一个自己的抽象类
//定义一个不重复的 IID
#define QtWidgetPluginInterfaceIID "com.yuming.QtWidgetPluginInterface/1.0.0"

class QtWidgetPluginInterface {
public:
    virtual ~QtWidgetPluginInterface() = default;
    virtual QWidget* getWidget() = 0;
};

//将IID和接口绑定           接口类名                        IID
Q_DECLARE_INTERFACE(QtWidgetPluginInterface, QtWidgetPluginInterfaceIID);

#endif // QTWIDGETPLUGININTERFACE_H
