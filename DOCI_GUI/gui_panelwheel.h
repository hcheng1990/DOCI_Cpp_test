#ifndef GUI_PANELWHEEL_H
#define GUI_PANELWHEEL_H

#include <QObject>
#include "gui_var.h"

class gui_PanelWheel : public QObject
{
    Q_OBJECT
public:
    gui_PanelWheel(QObject*, gui_var*, QObject *parent = Q_NULLPTR);
private:
    gui_var* vars;
private slots:
    void home();
    void wheelChange(int);
};

#endif // GUI_PANELWHEEL_H
