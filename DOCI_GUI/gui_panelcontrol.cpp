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
    CP_initial(false);

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

//----------------------Core Control Functions---------------------------
void gui_PanelControl::initialize()
{
    qDebug() << "init";
    vars->debugLabel->setText("Initializing...");
    qApp->processEvents();
    vars->stall(); //Initialize camera
    CP_initial(true);
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
    vars->stall(); //Shutdown Camera
    CP_initial(false);
    vars->debugLabel->setText("Shutdown Successful");
}
//-------------------Sub-Functions-------------------
void gui_PanelControl::CP_initial(bool initial)
{
    CP_display(!initial,0);
    CP_display(!initial,9);
    CP_display(initial,1,8);
    WP_display(initial);
}
void gui_PanelControl::CP_display(bool display, int start)
{
    displayWidget(display,vars->CP_buttons[start]);
}
void gui_PanelControl::CP_display(bool display, int start, int end)
{
    for (int i = start; i <= end; i++){
        displayWidget(display,vars->CP_buttons[i]);
    }
}
void gui_PanelControl::WP_display(bool display)
{
    for(int i = 0; i < vars->WP_grid->count(); i++){
        displayWidget(display,vars->WP_grid->itemAt(i)->widget());
    }
}
void gui_PanelControl::displayWidget(bool display, QWidget* widget)
{
    widget->setEnabled(display);
    if(display){
        widget->show();

    }else{
        widget->hide();
    }
}
