#include "widget.h"
#include "ui_widget.h"

#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    enableBtn(false);
}

Widget::~Widget()
{
    delete ui;

    if(m_loder.isLoaded())
        m_loder.unload();

    if(m_widgetLoder.isLoaded())
        m_widgetLoder.unload();
}

void Widget::resultSlot(QString type, QVariant v)
{
    QString typeName = v.typeName();
    if(sender() == m_calObj) {
        if(QString("qt_o_plugin::MData").compare(typeName) == 0) {
            qt_o_plugin::MData data = v.value<qt_o_plugin::MData>();
            qDebug() << "num:" << data.num << " name:" << data.name;
        }
        else if(QString("qt_o_plugin::MData*").compare(typeName) == 0) {
            qt_o_plugin::MData *data = v.value<qt_o_plugin::MData*>();
            qDebug() << "num:" << data->num << " name:" << data->name;
            delete data;
        }
        else if(QString("QSharedPointer<qt_o_plugin::MData>").compare(typeName) == 0) {
            QSharedPointer<qt_o_plugin::MData> data = v.value<QSharedPointer<qt_o_plugin::MData> >();
            qDebug() << "num:" << data->num << " name:" << data->name;
        }
        else {
            qDebug() << "type:" << type << " v:" << v;
        }
    }
    else if(sender() == m_widget) {
        if(type.compare("add") == 0) {
            qt_w_plugin::MData data = v.value<qt_w_plugin::MData>();
            qDebug() << "num:" << data.num << " name:" << data.name;
            m_datas.append(data);

            initList();
        }
        else if(type.compare("delete") == 0) {
            qt_w_plugin::MData data = v.value<qt_w_plugin::MData>();
            qDebug() << "num:" << data.num << " name:" << data.name;
            for(int i = 0; i < m_datas.size(); i++) {
                if(data.num == m_datas.at(i).num && data.name.compare(m_datas.at(i).name) == 0) {
                    m_datas.removeAt(i);
                    break;
                }
            }

            initList();
        }
    }
}

void Widget::on_pushButton_clicked()
{
    if(!m_loder.isLoaded()) {
        QDir dir(QApplication::applicationDirPath());
        m_loder.setFileName(dir.filePath("QtPlugin.dll"));
        if(!m_loder.load()) {
            QMessageBox::critical(this, "", m_loder.errorString());
            return;
        }

        QtPluginInterface *interface = qobject_cast<QtPluginInterface *>(m_loder.instance());
        if(!interface) {
            m_loder.unload();
            QMessageBox::critical(this, "", "获取插件实例失败!");
            return;
        }

        m_calObj = static_cast<PublicObject *>(interface->getObject());
        if(!m_calObj) {
            m_loder.unload();
            QMessageBox::critical(this, "", "获取插件指定实例失败!");
            m_calObj = Q_NULLPTR;
            return;
        }

        connect(this, &Widget::sendTask, m_calObj, &PublicObject::doSome);
        connect(m_calObj, &PublicObject::result, this, &Widget::resultSlot);

        qDebug() << "加载插件成功！";

        ui->pushButton->setText("卸载插件");
        enableBtn(true);
    }
    else {
        disconnect(this, &Widget::sendTask, m_calObj, &PublicObject::doSome);
        disconnect(m_calObj, &PublicObject::result, this, &Widget::resultSlot);
        m_calObj = nullptr;
        m_loder.unload();
        ui->pushButton->setText("加载插件");
        enableBtn(false);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(!m_loder.isLoaded())
        return;

    emit sendTask("1", 1);
}

void Widget::on_pushButton_3_clicked()
{
    if(!m_loder.isLoaded())
        return;

    emit sendTask("2", 2);
}

void Widget::on_pushButton_4_clicked()
{
    if(!m_loder.isLoaded())
        return;

    emit sendTask("3", 3);
}

void Widget::on_pushButton_5_clicked()
{
    if(!m_loder.isLoaded())
        return;

    emit sendTask("4", 4);
}

void Widget::enableBtn(bool status)
{
    ui->pushButton_2->setEnabled(status);
    ui->pushButton_3->setEnabled(status);
    ui->pushButton_4->setEnabled(status);
    ui->pushButton_5->setEnabled(status);
}

void Widget::initList()
{
    QVariant value;
    value.setValue(m_datas);
    emit sendTask("initList", value);
}

void Widget::on_pushButton_6_clicked()
{
    if(!m_widgetLoder.isLoaded()) {
        QDir dir(QApplication::applicationDirPath());
        m_widgetLoder.setFileName(dir.filePath("QtWidgetPlugin.dll"));
        if(!m_widgetLoder.load()) {
            QMessageBox::critical(this, "", m_widgetLoder.errorString());
            return;
        }

        QtWidgetPluginInterface *interface = qobject_cast<QtWidgetPluginInterface *>(m_widgetLoder.instance());
        if(!interface) {
            m_widgetLoder.unload();
            QMessageBox::critical(this, "", "获取插件实例失败!");
            return;
        }

        m_widget = static_cast<PublicWidget *>(interface->getWidget());
        if(!m_widget) {
            m_widgetLoder.unload();
            QMessageBox::critical(this, "", "获取插件指定实例失败!");
            m_widget = Q_NULLPTR;
            return;
        }

        connect(this, &Widget::sendTask, m_widget, &PublicWidget::doSome);
        connect(m_widget, &PublicWidget::result, this, &Widget::resultSlot);

        qDebug() << "窗体加载插件成功！";

        ui->pushButton_6->setText("卸载窗体插件");

        if(ui->frame->layout() == Q_NULLPTR)
            m_widgetLayout = new QHBoxLayout(ui->frame);
        m_widgetLayout->addWidget(m_widget);

        //初始化插件中的列表
        int i = 0;
        while(i < 3) {
            qt_w_plugin::MData data;
            data.num = i+1;
            data.name = "name:" + QString::number(i+1);
            m_datas.append(data);
            i++;
        }

        initList();
    }
    else {
        m_widgetLayout->removeWidget(m_widget);
        disconnect(this, &Widget::sendTask, m_widget, &PublicWidget::doSome);
        disconnect(m_widget, &PublicWidget::result, this, &Widget::resultSlot);
        m_widget = nullptr;
        m_widgetLoder.unload();
        ui->pushButton_6->setText("加载窗体插件");
    }
}
