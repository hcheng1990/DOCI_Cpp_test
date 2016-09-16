#ifndef GUI_PANELCONTROL_H
#define GUI_PANELCONTROL_H

#include <QObject>
#include "gui_var.h"
class gui_PanelControl : public QObject
{
    Q_OBJECT
public:
    gui_PanelControl(QObject*, gui_var*,QObject *parent = Q_NULLPTR);
private:
    gui_var* vars;
private slots:
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
