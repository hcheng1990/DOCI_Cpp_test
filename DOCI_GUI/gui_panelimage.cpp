#include "gui_panelimage.h"

gui_PanelImage::gui_PanelImage(gui_var* vars, QObject *parent):QObject(parent)
{
    this->vars = vars;
    mat = cv::imread("E:/My Documents/GitHub/DOCI_GUI/DOCI_GUI/img/r.tif",-1);
    vars->IP_label->setScaledContents(true);
    QRect layoutSize = vars->IP_label->rect();
    int w = layoutSize.width();
    vars->IP_label->setFixedWidth(w);
    vars->IP_label->setFixedHeight(w);
    displayImage();
    connect(vars->IP_slider,SIGNAL(valueChanged(double,double)),this,SLOT(changeScale(double,double)));
}
void gui_PanelImage::displayImage(double high, double low)
{
    cv::Mat imageMap = mat.clone();
    cv::Size s = mat.size();
    int x = s.height;
    int y = s.width;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            int val = mat.at<ushort>(i,j);
            if (val<low){
                imageMap.at<ushort>(i,j) = low;
            }else if(val>high){
                imageMap.at<ushort>(i,j) = high;
            }
        }
    }
    float scale = 255 / (high-low);
    cv::Mat adjMap;
    imageMap.convertTo(adjMap,CV_8UC1, scale, -low*scale);
    cv::Mat resultMap;
    applyColorMap(adjMap, resultMap, cv::COLORMAP_JET);
    //cv::imshow("test",resultMap);
    cv::cvtColor(resultMap, resultMap, CV_BGR2RGB);

    QImage img(resultMap.data, resultMap.cols, resultMap.rows, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(img);
    vars->IP_label->setPixmap(pixmap);
}\
void gui_PanelImage::displayImage()
{
    displayImage(1000,600);
}

void gui_PanelImage::changeScale(double high, double low)
{
    displayImage(high,low);
}
