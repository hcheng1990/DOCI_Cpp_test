#ifndef GUI_PANELWHEEL_H
#define GUI_PANELWHEEL_H

#include <QGroupBox>
class gui_PanelWheel : public QGroupBox
{
    Q_OBJECT
public:
    gui_PanelWheel(const QString& title, QWidget* parent = Q_NULLPTR);
};

#endif // GUI_PANELWHEEL_H
