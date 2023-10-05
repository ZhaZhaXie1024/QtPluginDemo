#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPluginLoader>
#include <QHBoxLayout>

#include "plugin/publicobject.h"
#include "plugin/plugin1/qtplugininterface.h"
#include "plugin/plugin1/qtpluginstruct.h"

#include "plugin/publicwidget.h"
#include "plugin/plugin2/qtwidgetplugininterface.h"
#include "plugin/plugin2/qtwidgetpluginstruct.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void sendTask(QString type, QVariant v);

public slots:
    //接收插件返回的结果槽函数
    void resultSlot(QString type, QVariant v);

private slots:
    //加载插件
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    //加载窗体插件
    void on_pushButton_6_clicked();

private:
    void enableBtn(bool status);

    //初始化窗体插件QListWidget的列表
    void initList();

private:
    Ui::Widget *ui;

    QPluginLoader m_loder;
    PublicObject *m_calObj = Q_NULLPTR;

    QPluginLoader m_widgetLoder;
    PublicWidget *m_widget = Q_NULLPTR;
    QHBoxLayout *m_widgetLayout = Q_NULLPTR;
    QList<qt_w_plugin::MData> m_datas;
};

#endif // WIDGET_H
