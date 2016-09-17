#ifndef GUI_PANELFOLDER_H
#define GUI_PANELFOLDER_H

#include <QObject>
#include "gui_var.h"
class gui_PanelFolder : public QObject
{
    Q_OBJECT
public:
    gui_PanelFolder(gui_var*, QObject *parent = Q_NULLPTR);
private:
    gui_var* vars;
private slots:
    void open_folder();
};

#endif // GUI_PANELFOLDER_H
