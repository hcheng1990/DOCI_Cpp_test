#ifndef GUI_VAR_H
#define GUI_VAR_H

#include <QtWidgets>
#include "gui_panelcontrol.h"
#include "gui_panelfolder.h"
#include "gui_panelimage.h"
#include "gui_panelwheel.h"

class gui_var
{
public:
    gui_var();
    //Layouts
    QGridLayout* layoutCentral;

    //QGroupBox control panels
    gui_PanelControl* PanelControl;
    gui_PanelFolder* PanelFolder;
    gui_PanelImage* PanelImage;
    gui_PanelWheel* PanelWheel;
private:
    void addPanels();
};

#endif // GUI_VAR_H
