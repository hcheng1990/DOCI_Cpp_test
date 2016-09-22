#ifndef ANDORCAM_H
#define ANDORCAM_H

#include "ATMCD32D.H"
#include <QDebug>

class AndorCam
{
public:
    AndorCam();
    void initialize();
    void shutdown();
    WORD* videoMode(int*,int*);
    void clearData();
private:
    int ui_error;
    bool started;
    WORD* lp_data;
};

#endif // ANDORCAM_H
