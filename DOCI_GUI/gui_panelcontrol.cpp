#include "gui_panelcontrol.h"

gui_PanelControl::gui_PanelControl(QObject* main_gui, gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    isTemp = false;
    num = 0;
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
    vars->debugLabel->setText("Initializing...");
    qApp->processEvents();
    vars->filterwheel->Home();
    //vars->stall(); //Initialize camera
    temp = 15; //Get Camera Temp
    CP_initial(true);
    vars->debugLabel->setText("Initialization Complete");
}
void gui_PanelControl::cooling()
{
    isTemp = true;
    vars->debugLabel->setText("Cooling...");
    CP_display(false,2,8);
    CP_enable(false,2,8);
    CP_enable(false,1);
    while(temp > -15){
        temp = temp-2;
        vars->debugLabel->setText(QString::number(temp));
        vars->CP_buttons[1]->setText("Cooling...");
        qApp->processEvents();
        vars->stall();
    }
    CP_display(true,2,8);
    CP_enable(true,2,8);
    vars->CP_buttons[1]->setText("Camera Cooled!");
}
void gui_PanelControl::video(bool checked)
{
    if(checked)
    {
        vars->CP_buttons[2]->setText("Stop Video");
        CP_enable(false,1);
        CP_enable(false,4,6);
        CP_enable(false,8);
    }
    while(checked)
    {
        num++;
        vars->debugLabel->setText(QString::number(num));
        qApp->processEvents();
        checked = vars->CP_buttons[2]->isChecked();
    }
    if(!checked)
    {
        vars->CP_buttons[2]->setText("Video Mode");
        if(!isTemp){
            CP_enable(true,1);
        }
        CP_enable(true,4,6);
        CP_enable(true,8);
    }
}
void gui_PanelControl::rgb()
{
    vars->CP_buttons[2]->setChecked(false);
    num = 0;
    vars->debugLabel->setText(QString::number(num));
    vars->CP_buttons[3]->setText("RGB Acquiring...");
    CP_enable(false,1,8);
    qApp->processEvents();
    vars->stall();
    vars->CP_buttons[3]->setText("RGB Mode");
    if(!isTemp){
        CP_enable(true,1);
    }
    CP_enable(true,2,8);
}
void gui_PanelControl::ltVideo(bool checked)
{
    if(checked)
    {
        vars->CP_buttons[4]->setText("Stop Video");
        CP_enable(false,1,3);
        CP_enable(false,7,8);
    }
    while(checked)
    {
        num++;
        vars->debugLabel->setText(QString::number(num));
        qApp->processEvents();
        checked = vars->CP_buttons[4]->isChecked();
    }
    if(!checked)
    {
        vars->CP_buttons[4]->setText("Video Mode");
        if(!isTemp){
            CP_enable(true,1);
        }
        CP_enable(true,2,3);
        CP_enable(true,7,8);
    }
}
void gui_PanelControl::lt1()
{
    lifetime(1);
}
void gui_PanelControl::lt2()
{
    lifetime(2);
}
void gui_PanelControl::shutdown()
{
    vars->CP_buttons[2]->setChecked(false);
    vars->CP_buttons[4]->setChecked(false);
    vars->debugLabel->setText("Shutting Down...");
    CP_enable(false,1,8);
    qApp->processEvents();
    vars->stall(); //Shutdown Camera

    while(temp < 0 || isTemp){
        temp = temp+2;
        vars->debugLabel->setText(QString::number(temp));
        vars->CP_buttons[1]->setText("Camera Warming...");
        qApp->processEvents();
        vars->stall();
        if(temp > 0){
            isTemp = false;
            CP_enable(true,1);
        }
    }
    temp = 15;
    CP_initial(false);
    vars->CP_buttons[1]->setText("Cooler");
    vars->debugLabel->setText("Shutdown Complete");
}
//-------------------Sub-Functions-------------------
void gui_PanelControl::CP_initial(bool initial)
{
    CP_display(!initial,0);
    CP_display(!initial,9);
    CP_display(initial,1,8);
    WP_display(initial);

    CP_enable(!initial,0);
    CP_enable(!initial,9);
    CP_enable(initial,1,8);
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
        enableWidget(display,vars->WP_grid->itemAt(i)->widget());
    }
}
void gui_PanelControl::displayWidget(bool display, QWidget* widget)
{
    if(display){
        widget->show();
    }else{
        widget->hide();
    }
}
void gui_PanelControl::CP_enable(bool enable, int start)
{
    enableWidget(enable,vars->CP_buttons[start]);
}
void gui_PanelControl::CP_enable(bool enable, int start, int end)
{
    for(int i = start; i <= end; i++){
        enableWidget(enable,vars->CP_buttons[i]);
    }
}
void gui_PanelControl::enableWidget(bool enable, QWidget* widget)
{
    widget->setEnabled(enable);
}
void gui_PanelControl::lifetime(int wheel)
{
    vars->CP_buttons[4]->setChecked(false);
    num = 0;
    vars->debugLabel->setText(QString::number(num));
    if(wheel == 1){
        vars->CP_buttons[5]->setText("Wheel 1 Acquiring...");
    }else{
        vars->CP_buttons[6]->setText("Wheel 2 Acquiring...");
    }
    CP_enable(false,1,8);
    qApp->processEvents();
    vars->stall();
    if(wheel == 1){
        vars->CP_buttons[5]->setText("Lifetime Wheel 1");
    }else{
        vars->CP_buttons[6]->setText("Lifetime Wheel 2");
    }
    if(!isTemp){
        CP_enable(true,1);
    }
    CP_enable(true,2,8);
}
