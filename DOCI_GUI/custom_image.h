#ifndef CUSTOM_IMAGE_H
#define CUSTOM_IMAGE_H

#include <QObject>

#include <opencv2/core/core.hpp>

class custom_image : public QObject
{
    Q_OBJECT
public:
    custom_image(QObject *parent = Q_NULLPTR);
    cv::Mat mat;
};

#endif // CUSTOM_IMAGE_H
