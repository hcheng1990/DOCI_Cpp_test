#include "gui_methods.h"

void windowPreset(QMainWindow* main_gui)
{
    main_gui->setWindowTitle("DOCI");
    QRect deskSize = QApplication::desktop()->screenGeometry();
    int deskX = deskSize.width();
    int deskY = deskSize.height();
    int winX = 1200;
    int winY = 800;
    main_gui->setGeometry((deskX-winX)/2,(deskY-winY)/2,winX,winY);
    main_gui->setFixedSize(winX,winY);
}
void setFontSize(QWidget* widget, int fontSize)
{
    QFont font = widget->font();
    font.setPointSize(fontSize);
    widget->setFont(font);
}
