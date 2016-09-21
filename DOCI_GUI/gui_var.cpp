#include "gui_var.h"
#include <QDebug>
gui_var::gui_var()
{
    partsPanels(); //Create Panels
    partsControl(); //Control Panel Parts
    partsWheel(); //Wheel Panel Parts
    partsFolder(); //Folder Panel Parts
    partsImage(); //Image Panel Parts

    filterwheel = new FilterWheel();
}
void gui_var::partsPanels()
{
    //Panels
    layoutCentral = new QGridLayout();
    PanelControl = new QGroupBox("Control Panel");
    PanelFolder = new QGroupBox("Folder Panel");
    PanelImage = new QGroupBox("Image Panel");
    PanelWheel = new QGroupBox("Wheel Panel");
    layoutCentral->addWidget(PanelControl,1,0,16,1);
    layoutCentral->addWidget(PanelFolder,0,0,1,5);
    layoutCentral->addWidget(PanelImage,1,1,16,5);
    layoutCentral->addWidget(PanelWheel,0,5,1,1);
    setFontSize(PanelControl,12);
    setFontSize(PanelFolder,12);
    setFontSize(PanelImage,12);
    setFontSize(PanelWheel,12);
}
void gui_var::partsControl()
{
    CP_vbox = new QVBoxLayout;
    PanelControl->setLayout(CP_vbox);
    CP_button_names << "Initialize" << "Cooler" << "Video Mode" << "RGB Mode"
                    << "Lifetime Video" << "Lifetime Wheel 1" << "Lifetime Wheel 2"
                    << "RGB Registration" << "Shutdown" << "Close";

    for(int i = 0; i < CP_button_names.length(); i++){ //0-9
        CP_buttons.append(new custom_button(CP_button_names[i]));
        CP_vbox->addWidget(CP_buttons[i]);
    }
    debugLabel = new QLabel("App Started");
    CP_vbox->addWidget(debugLabel); //10
    CP_vbox->addStretch(1); //11
}
void gui_var::partsWheel()
{
    //Wheel Panel
    WP_grid = new QGridLayout;
    PanelWheel->setLayout(WP_grid);
    WP_select = new QComboBox();
    for(int i = 1; i <= 8; i++){
        WP_select->addItem(QString::number(i));
    }

    WP_home = new custom_button("Home");
    WP_grid->addWidget(WP_home);

    WP_label = new QLabel("1");

    WP_grid->addWidget(WP_home,0,0,1,1);
    WP_grid->addWidget(WP_select,0,1,0,1);
    WP_grid->addWidget(WP_label,0,2,0,1);
}
void gui_var::partsFolder()
{
    FP_grid = new QGridLayout();
    PanelFolder->setLayout(FP_grid);
    FP_label = new custom_label("D:/Dropbox/FLIM/Harrison/Raw Data/2015_04_20/2015_04_20 03.30PM");
    FP_grid->addWidget(FP_label);
}
void gui_var::partsImage()
{
    IP_grid = new QGridLayout();
    PanelImage->setLayout(IP_grid);
    IP_label = new QLabel();
    IP_grid->addWidget(IP_label);
    IP_slider = new custom_slider();
    //IP_grid->addWidget(IP_slider);
    IP_slider->addTo(PanelImage);

}
//Debug Use
void gui_var::stall()
{
    for (int i = 1; i < 20000; i++){
        for (int j = 1; j < 20000; j++){

        }
    }
}
