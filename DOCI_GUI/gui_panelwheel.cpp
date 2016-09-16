#include "gui_panelwheel.h"

gui_PanelWheel::gui_PanelWheel(QObject* main_gui, gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    vars->WP_home->show();
}
