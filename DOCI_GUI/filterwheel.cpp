#include "filterwheel.h"

FilterWheel::FilterWheel(QMessageBox* eDiag)
{
    hsfw = new QAxObject("FA9E7329-1F0C-4176-996B-9E2EEABAFD85");
    filterCount = hsfw->dynamicCall("AttachedDeviceCount()").toInt();
    wheel = NULL;
    this->eDiag = eDiag;
    if(filterCount > 0){
        filterArray = hsfw->querySubObject("FilterWheelList()");
        wheel = filterArray->querySubObject("Item(int)",0);
        errorList   << "No Error has occured"
                    << "Power Cord Disconnected"
                    << "Device Stalled"
                    << "Communication Error"
                    << "Attempt to move wheel while in motion"
                    << "Attempt to change filter position while in motion"
                    << "Attempt to change filter position before homing"
                    << "Optec use only"
                    << "Unknown critical error";
    }
}
//Methods & HSFW Action
void FilterWheel::CurrentPosition(int i)
{
    if(!isNull()){
        wheel->dynamicCall("CurrentPosition",i);
        moveCheck();
    } else {
        noLib();
    }
}
void FilterWheel::Home()
{
    if(!isNull()){
        wheel->dynamicCall("HomeDevice()");
        moveCheck();
    } else {
        noLib();
    }
}
void FilterWheel::moveCheck()
{
    while(isMoving()){
    }
    errorCheck();
}
bool FilterWheel::isMoving()
{
    return wheel->dynamicCall("IsMoving()").toBool();
}

void FilterWheel::errorCheck()
{
    int error = wheel->dynamicCall("ErrorState()").toInt();
    if(error != 0){
        eDiag->setText(errorList[error]);
        eDiag->exec();
        wheel->dynamicCall("ClearErrorState()");
        error = 0;
        Home();
    }
}

//Return Properties
int FilterWheel::CurrentPosition()
{
    if(!isNull()){
        return wheel->dynamicCall("CurrentPosition()").toInt();
    } else {
        return -1;
    }
}
bool FilterWheel::isNull()
{
    return wheel == NULL;
}
void FilterWheel::noLib()
{
    eDiag->setText("Cannot find COM LIB or wheel not attached");
    eDiag->exec();
}
