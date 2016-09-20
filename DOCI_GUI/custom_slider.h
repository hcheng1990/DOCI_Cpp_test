#ifndef CUSTOM_SLIDER_H
#define CUSTOM_SLIDER_H

#include <QQuickView>
#include <QQuickItem>
#include <QQmlProperty>
#include <QDebug>
#include <QObject>
#include <QWidget>

class custom_slider : public QWidget
{
    Q_OBJECT
public:
    explicit custom_slider(QWidget *parent = 0);
    void addTo(QWidget*);
    QObject *slider;
    QQuickView* view;
    QObject *qitem;
    QWidget* container;
    void setSize(int,int);
signals:
    void valueChanged(double,double);
public slots:
    void emitValue(double,double);
};

#endif // CUSTOM_SLIDER_H
