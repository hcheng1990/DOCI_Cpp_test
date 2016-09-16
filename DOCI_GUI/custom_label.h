#ifndef CUSTOM_LABEL_H
#define CUSTOM_LABEL_H

#include <QLabel>
#include <QMouseEvent>
class custom_label : public QLabel
{
    Q_OBJECT
public:
    custom_label(const QString& text, QWidget* parent=0);
    void mousePressEvent(QMouseEvent* event);
signals:
    void clicked();
};

#endif // CUSTOM_LABEL_H
