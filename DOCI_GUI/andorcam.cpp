#include "andorcam.h"

AndorCam::AndorCam()
{
    started = false;
    lp_data = NULL;
}
void AndorCam::initialize()
{
    if(!started){
        ui_error = Initialize("");
        qDebug() << QString::number(ui_error)+ " Initialize";
        if(ui_error == 20002){
            started = true;
            int info;
            ui_error = GetCameraSerialNumber(&info);
            qDebug() << QString::number(ui_error)+ " GetSerial";
            qDebug() << "CameraInfo: " + QString::number(info);
            ui_error = SetReadMode(4);
            qDebug() << QString::number(ui_error)+ " SetReadMode";
            ui_error = SetFullImage(1,1);
            qDebug() << QString::number(ui_error)+ " SetFullimage";
            ui_error = SetAcquisitionMode(1);
            qDebug() << QString::number(ui_error)+ " SetAcqMode";
            ui_error = SetExposureTime(0.01f);
            qDebug() << QString::number(ui_error)+ " SetExposureTime";
            AndorCapabilities* caps = new AndorCapabilities();
            ui_error = GetCapabilities(caps);
            qDebug() << QString::number(ui_error)+ " GetCapabilities";

            if(caps->ulFeatures & AC_FEATURES_SHUTTER) {

                //If a shutter is present set is to always open
                ui_error = SetShutter(1,1,10,10);
                qDebug() << QString::number(ui_error)+ " Set Shutter";
            }
            unsigned long long gatetime = 10*pow(10,-3)*pow(10,12);
            unsigned long long gatedelay = 0;
            qDebug() << gatetime;
            qDebug() << gatedelay;
            ui_error = SetDDGGateTime(gatedelay,gatetime);
            qDebug() << QString::number(ui_error)+ " SetDDGGateTime";
        }
    }
}
void AndorCam::shutdown()
{
    if(started){
        started = false;
        qDebug() << "stop";
        ui_error = ShutDown();
        qDebug() << ui_error;
    }
}
WORD* AndorCam::videoMode(int* i_x, int* i_y)
{
    if(started){
        unsigned long ul_size;

        ui_error = GetDetector(i_x,i_y);

        qDebug() << QString::number(ui_error)+ " GetDetector";
        ul_size = (*i_x)*(*i_y);
        lp_data = new WORD[ul_size];

        ui_error = StartAcquisition();
        qDebug() << QString::number(ui_error)+ " StartAcquisition";

        ui_error = WaitForAcquisition();
        qDebug() << QString::number(ui_error)+ " Wait";

        ui_error = GetMostRecentImage16(lp_data,ul_size);
        qDebug() << QString::number(ui_error)+ " GetAcquiredData";
        return lp_data;
    }
    return NULL;
}
void AndorCam::clearData()
{
    if(lp_data){
        delete[] lp_data;
    }
}
