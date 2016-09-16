#include "custom_button.h"

custom_button::custom_button(const QString &text, QWidget *parent): QPushButton(text,parent)
{
    defaultFormat();
    mytimer = new QTimer();
    connect(mytimer,SIGNAL(timeout()),this,SLOT(stopTimer()));
}
void custom_button::defaultFormat()
{
    hide();
    setMinimumHeight(50);
    QFont font = this->font();
    font.setPointSize(14);
    setFont(font);
}

void custom_button::mousePressEvent(QMouseEvent *e)
{
    if(this->isCheckable()){
        this->setDown(true);
    }else if(mytimer->remainingTime() == -1 && e->button()== Qt::LeftButton){
        mytimer->start(2000);
        emit clicked();
    }
}
void custom_button::stopTimer()
{
    mytimer->stop();
}
