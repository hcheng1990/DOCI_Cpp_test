#ifndef GUI_PANELFOLDER_H
#define GUI_PANELFOLDER_H

#include <QGroupBox>
class gui_PanelFolder : public QGroupBox
{
    Q_OBJECT
public:
    gui_PanelFolder(const QString& title, QWidget* parent = Q_NULLPTR);
};

#endif // GUI_PANELFOLDER_H
