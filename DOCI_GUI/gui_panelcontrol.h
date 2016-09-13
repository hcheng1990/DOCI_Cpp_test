#ifndef GUI_PANELCONTROL_H
#define GUI_PANELCONTROL_H

#include <QGroupBox>
class gui_PanelControl : public QGroupBox
{
    Q_OBJECT
public:
    gui_PanelControl(const QString& title, QWidget* parent = Q_NULLPTR);
};

#endif // GUI_PANELCONTROL_H
