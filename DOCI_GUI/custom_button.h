#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>

class custom_button : public QPushButton
{
    Q_OBJECT
public:
    custom_button(const QString &text, QWidget *parent = Q_NULLPTR);

private:
    void defaultFormat();
    QTimer *mytimer;

private slots:
    void mousePressEvent(QMouseEvent *e);
    void stopTimer();
signals:
    void clicked();
};

#endif // CUSTOM_BUTTON_H
