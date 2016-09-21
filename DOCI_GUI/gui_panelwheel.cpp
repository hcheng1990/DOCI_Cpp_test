#include "gui_panelwheel.h"

gui_PanelWheel::gui_PanelWheel(QObject* main_gui, gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    vars->WP_select->setMinimumHeight(35);
    vars->WP_select->setEditable(true);
    vars->WP_select->lineEdit()->setAlignment(Qt::AlignHCenter);
    connect(vars->WP_select,SIGNAL(currentIndexChanged(int)),this,SLOT(wheelChange(int)));

    vars->WP_home->setMinimumHeight(35);
    connect(vars->WP_home,SIGNAL(clicked()),this,SLOT(home()));

    vars->WP_label->setAlignment(Qt::AlignCenter);
    vars->WP_label->setMinimumHeight(35);
    setFontSize(vars->WP_label,12);
    vars->WP_label->setStyleSheet("QLabel { background: white }");
}
void gui_PanelWheel::wheelChange(int position)
{
    //MoveWheel
    vars->WP_label->setText(QString::number(position+1));
}
void gui_PanelWheel::home()
{
    //HomeWheel
    vars->WP_select->setCurrentIndex(0);
    vars->WP_label->setText("1");
}
