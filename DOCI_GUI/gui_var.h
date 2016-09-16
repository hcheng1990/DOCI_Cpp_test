#ifndef GUI_VAR_H
#define GUI_VAR_H

#include <QtWidgets>
#include "custom_button.h"
#include "custom_label.h"

class gui_var
{
public:
    gui_var();
    //GUI Central Layout
    QGridLayout* layoutCentral;

    //QGroupBox control panels
    QGroupBox* PanelControl;
    QGroupBox* PanelFolder;
    QGroupBox* PanelImage;
    QGroupBox* PanelWheel;

    //Control Panel
    QVBoxLayout* CP_vbox;
    QList<QString> CP_button_names;
    QList<custom_button*> CP_buttons;
    QLabel* debugLabel;

    //Wheel Panel
    QGridLayout* WP_grid;
    QComboBox* WP_select;
    custom_button* WP_home;
    QLabel* WP_label;

    //Folder Panel
    QGridLayout* FP_grid;
    custom_label* FP_label;

    //Image Panel
    QGridLayout* IP_grid;
    QLabel* IP_label;

    //Debug Use
    void stall();
private:
    void partsPanels();
    void partsControl();
    void partsFolder();
    void partsImage();
    void partsWheel();
};

#endif // GUI_VAR_H
