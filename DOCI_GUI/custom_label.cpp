#include "custom_label.h"

custom_label::custom_label(const QString& text, QWidget* parent): QLabel(text,parent)
{
}
void custom_label::mousePressEvent(QMouseEvent* event)
{
    if(Qt::LeftButton == event->button()){
        emit clicked();
    }
}

