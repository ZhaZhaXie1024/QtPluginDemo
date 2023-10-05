#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "interface/publicwidget.h"

namespace Ui {
class Form;
}

class Form : public PublicWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    virtual void doSome(QString type, QVariant v) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
