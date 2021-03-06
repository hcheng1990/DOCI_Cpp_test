#ifndef GUI_PANELIMAGE_H
#define GUI_PANELIMAGE_H

#include <QObject>
#include "gui_var.h"

//OpenCV Library
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/contrib/contrib.hpp>

class gui_PanelImage : public QObject
{
    Q_OBJECT
public:
    gui_PanelImage(gui_var*, QObject *parent = Q_NULLPTR);
    cv::Mat mat;
    //void setMat(int,int,WORD*);
private:
    gui_var* vars;
    void displayImage();
    void displayImage(double,double);
    int high;
    int low;
private slots:
    void changeScale(double,double);
};

#endif // GUI_PANELIMAGE_H
