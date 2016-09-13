#include "gui_methods.h"

void windowPreset(main_gui* myGUI)
{
    myGUI->setWindowTitle("DOCI");
    QRect deskSize = QApplication::desktop()->screenGeometry();
    int deskX = deskSize.width();
    int deskY = deskSize.height();
    int winX = 1200;
    int winY = 800;
    myGUI->setGeometry((deskX-winX)/2,(deskY-winY)/2,winX,winY);
    myGUI->setFixedSize(winX,winY);
}
