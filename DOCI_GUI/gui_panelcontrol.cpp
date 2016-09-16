#include "gui_panelcontrol.h"

gui_PanelControl::gui_PanelControl(QObject* main_gui, gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    /*
     * 0: Initialize
     * 1: Cooler
     * 2: Video
     * 3: RGB
     * 4: LT-Video
     * 5: LT-Wheel 1
     * 6: LT-Wheel 2
     * 7: RGB 2
     * 8: Shutdown
     * 9: Close
    */
    vars->CP_buttons[0]->show();
    vars->CP_buttons[2]->setCheckable(true);
    vars->CP_buttons[4]->setCheckable(true);
    vars->CP_buttons[9]->show();

    connect(vars->CP_buttons[0],SIGNAL(clicked()),this,SLOT(initialize()));
    connect(vars->CP_buttons[1],SIGNAL(clicked()),this,SLOT(cooling()));
    connect(vars->CP_buttons[2],SIGNAL(toggled(bool)),this,SLOT(video(bool)));
    connect(vars->CP_buttons[3],SIGNAL(clicked()),this,SLOT(rgb()));
    connect(vars->CP_buttons[4],SIGNAL(toggled(bool)),this,SLOT(ltVideo(bool)));
    connect(vars->CP_buttons[5],SIGNAL(clicked()),this,SLOT(lt1()));
    connect(vars->CP_buttons[6],SIGNAL(clicked()),this,SLOT(lt2()));
    connect(vars->CP_buttons[7],SIGNAL(clicked()),this,SLOT(rgb()));
    connect(vars->CP_buttons[8],SIGNAL(clicked()),this,SLOT(shutdown()));
    connect(vars->CP_buttons[9],SIGNAL(clicked()),main_gui,SLOT(close()));
}

//Initialize Button
void gui_PanelControl::initialize()
{
    vars->debugLabel->setText("Initializing...");
    qApp->processEvents();
    vars->stall();
    for (int i = 1; i < vars->CP_buttons.count()-1; i++){
        vars->CP_buttons[i]->show();
    }
    vars->CP_buttons[0]->hide();
    vars->CP_buttons[9]->hide();
    /*
    //Initialize Camera
    setButtonDisplay(vbox,false,0);
    setButtonDisplay(vbox,false,9);
    setButtonDisplay(vbox,true,1,8);
    HSFW_home->show();
    HSFW_select->show();
    HSFW_indicator->show();
    */
    vars->debugLabel->setText("Initialization Complete");
}
void gui_PanelControl::cooling()
{
    vars->debugLabel->setText("Cooling");
}
void gui_PanelControl::video(bool)
{
    vars->debugLabel->setText("Video");
}
void gui_PanelControl::rgb()
{
    vars->debugLabel->setText("RGB");
}
void gui_PanelControl::ltVideo(bool)
{
    vars->debugLabel->setText("ltVideo");
}
void gui_PanelControl::lt1()
{
    vars->debugLabel->setText("lt1");
}
void gui_PanelControl::lt2()
{
    vars->debugLabel->setText("lt2");
}
void gui_PanelControl::shutdown()
{
    vars->debugLabel->setText("Shutting Down...");
    qApp->processEvents();
    vars->stall();
    for (int i = 1; i < vars->CP_buttons.count()-1; i++){
        vars->CP_buttons[i]->hide();
    }
    vars->CP_buttons[0]->show();
    vars->CP_buttons[9]->show();
    vars->debugLabel->setText("Shutdown Successful");
}
