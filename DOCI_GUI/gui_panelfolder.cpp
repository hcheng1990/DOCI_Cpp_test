#include "gui_panelfolder.h"

gui_PanelFolder::gui_PanelFolder(gui_var* vars, QObject *parent) : QObject(parent)
{
    this->vars = vars;
    setFontSize(vars->FP_label,14);
    vars->FP_label->setMinimumHeight(35);
    vars->FP_label->setStyleSheet("QLabel { background: white; }");
    connect(vars->FP_label,SIGNAL(clicked()),this,SLOT(open_folder()));
}
void gui_PanelFolder::open_folder()
{
    QDesktopServices::openUrl(QUrl(QString("file:///").append(vars->FP_label->text())));
}
