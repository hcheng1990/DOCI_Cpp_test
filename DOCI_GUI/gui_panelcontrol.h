#ifndef GUI_PANELCONTROL_H
#define GUI_PANELCONTROL_H

#include <QObject>
#include <QDebug>
#include "gui_var.h"
class gui_PanelControl : public QObject
{
    Q_OBJECT
public:
    gui_PanelControl(QObject*, gui_var*, QObject *parent = Q_NULLPTR);

private:
    gui_var* vars;
    void WP_display(bool);
    void CP_initial(bool);
    void CP_display(bool,int);
    void CP_display(bool,int,int);
    void displayWidget(bool,QWidget*);
private slots:
    //Main Button Functions
    void initialize();
    void cooling();
    void video(bool);
    void rgb();
    void ltVideo(bool);
    void lt1();
    void lt2();
    void shutdown();
};

#endif // GUI_PANELCONTROL_H
