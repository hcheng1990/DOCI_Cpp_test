#include "custom_slider.h"

custom_slider::custom_slider(QWidget *parent) : QWidget(parent)
{
    view = new QQuickView();
    view->setSource(QUrl("qrc:/custom_slider.qml"));
    qitem = view->rootObject();
    slider = qitem->findChild<QObject*>("slider");
    connect(slider,SIGNAL(qmlSignal(double,double)),this,SLOT(emitValue(double,double)));
}
void custom_slider::addTo(QWidget* widget){
    container = QWidget::createWindowContainer(view, widget);
    container->move(820,30);
    setSize(100,640);

}
void custom_slider::setSize(int width,int height){
    container->setMaximumWidth(width);
    container->setMinimumWidth(width);
    container->setMinimumHeight(height);
    container->setMaximumHeight(height);
}
void custom_slider::emitValue(double top, double bot){
    emit valueChanged(top, bot);
}
