#ifndef GUI_PANELIMAGE_H
#define GUI_PANELIMAGE_H

#include <QGroupBox>
class gui_PanelImage : public QGroupBox
{
    Q_OBJECT
public:
    gui_PanelImage(const QString& title, QWidget* parent = Q_NULLPTR);
};

#endif // GUI_PANELIMAGE_H
