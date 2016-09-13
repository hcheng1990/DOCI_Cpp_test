#include "gui_var.h"

gui_var::gui_var()
{
    layoutCentral = new QGridLayout();
    PanelControl = new gui_PanelControl("Control Panel");
    PanelFolder = new gui_PanelFolder("Folder Panel");
    PanelImage = new gui_PanelImage("Image Panel");
    PanelWheel = new gui_PanelWheel("Wheel Panel");

    addPanels();
}
void gui_var::addPanels()
{
    layoutCentral->addWidget(PanelControl,1,0,16,1);
    layoutCentral->addWidget(PanelFolder,0,0,1,5);
    layoutCentral->addWidget(PanelImage,1,1,16,5);
    layoutCentral->addWidget(PanelWheel,0,5,1,1);
}

