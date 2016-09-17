#include "gui_panelwheel.h"

gui_PanelWheel::gui_PanelWheel(QObject* main_gui, gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    vars->WP_select->setMinimumHeight(35);
    for(int i = 0; i < 8; i++){
        vars->WP_select->addItem(QString::number(i));
    }
    vars->WP_select->setEditable(true);
    vars->WP_select->lineEdit()->setAlignment(Qt::AlignHCenter);

    vars->WP_home->setMinimumHeight(35);

    vars->WP_label->setAlignment(Qt::AlignCenter);
    vars->WP_label->setMinimumHeight(35);
    setFontSize(vars->WP_label,12);
    vars->WP_label->setStyleSheet("QLabel { background: white }");
}
