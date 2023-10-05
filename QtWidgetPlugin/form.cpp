#include "form.h"
#include "ui_form.h"
#include "interface/qtwidgetpluginstruct.h"

#include <QListWidgetItem>

Form::Form(QWidget *parent) :
    PublicWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::doSome(QString type, QVariant v)
{
    if(type.compare("initList") == 0) {
        if(QString("QList<qt_w_plugin::MData>").compare(v.typeName()) == 0) {
            QList<qt_w_plugin::MData> datas = v.value< QList<qt_w_plugin::MData> >();
            ui->listWidget->clear();
            for(int i = 0; i < datas.size(); i++) {
                qt_w_plugin::MData data = datas.at(i);
                QListWidgetItem *item = new QListWidgetItem(data.name, ui->listWidget);
                item->setData(Qt::UserRole+1, data.num);
                ui->listWidget->addItem(item);
            }
        }
    }
}

void Form::on_pushButton_clicked()
{
    //add
    int num = ui->listWidget->count();
    QString name = ui->lineEdit_2->text().trimmed();

    if(!name.isEmpty()) {
        qt_w_plugin::MData data;
        data.num = num;
        data.name = name;
        QVariant value;
        value.setValue(data);
        emit result("add", value);
    }
}

void Form::on_pushButton_2_clicked()
{
    //delete
    if(ui->listWidget->currentIndex().isValid()) {
        QListWidgetItem *item = ui->listWidget->currentItem();
        int num = item->data(Qt::UserRole+1).toInt();
        QString name = item->text();
        qt_w_plugin::MData data;
        data.num = num;
        data.name = name;
        QVariant value;
        value.setValue(data);
        emit result("delete", value);
    }
}
