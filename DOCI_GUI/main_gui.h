#ifndef MAIN_GUI_H
#define MAIN_GUI_H

#include <QMainWindow>
#include "gui_methods.h" //General Method
#include "gui_var.h" //Widget Pointers

#include "gui_panelcontrol.h"
#include "gui_panelfolder.h"
#include "gui_panelimage.h"
#include "gui_panelwheel.h"

namespace Ui {
class main_gui;
}

class main_gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_gui(QWidget *parent = 0);
    ~main_gui();

private:
    Ui::main_gui *ui;
    gui_PanelControl *PanelControl;
};

#endif // MAIN_GUI_H
