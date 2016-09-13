#include "main_gui.h"
#include "ui_main_gui.h"

main_gui::main_gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_gui)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    windowPreset(this);
    gui_var* vars = new gui_var();
    centralWidget()->setLayout(vars->layoutCentral);
}

main_gui::~main_gui()
{
    delete ui;
}
