#ifndef FILTERWHEEL_H
#define FILTERWHEEL_H

#include <QAxBase>
#include <QAxObject>
#include <QDebug>
#include <QMessageBox>

class FilterWheel
{
public:
    FilterWheel(QMessageBox*);
    int CurrentPosition();
    void CurrentPosition(int);
    void Home();
private:
    QMessageBox* eDiag;
    QAxObject *hsfw;
    int filterCount;
    QAxObject *filterArray;
    QAxObject *wheel;
    QList<QString> errorList;
    void moveCheck();
    void errorCheck();
    bool isMoving();
    bool isNull();
    void noLib();
};

#endif // FILTERWHEEL_H
