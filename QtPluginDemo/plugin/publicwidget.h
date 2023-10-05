#ifndef PUBLICWIDGET_H
#define PUBLICWIDGET_H

#include <QWidget>
#include <QString>
#include <QVariant>

class PublicWidget : public QWidget {
    Q_OBJECT
public:
    PublicWidget(QWidget* parent = nullptr) : QWidget(parent){}
    ~PublicWidget() = default;

public slots:
    virtual void doSome(QString type, QVariant v) = 0;

signals:
    void result(QString type, QVariant v);
};

#endif // PUBLICWIDGET_H
