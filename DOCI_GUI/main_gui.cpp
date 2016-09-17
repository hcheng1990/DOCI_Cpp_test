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
    PanelControl = new gui_PanelControl(this,vars);
    PanelWheel = new gui_PanelWheel(this,vars);
    PanelFolder = new gui_PanelFolder(vars);
    PanelImage = new gui_PanelImage(vars);
}

main_gui::~main_gui()
{
    delete ui;
}
