#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T10:29:33
#
#-------------------------------------------------

QT       += core gui quick axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DOCI_GUI
TEMPLATE = app


SOURCES += main.cpp\
        main_gui.cpp \
    gui_methods.cpp \
    gui_var.cpp \
    gui_panelfolder.cpp \
    gui_panelcontrol.cpp \
    gui_panelimage.cpp \
    gui_panelwheel.cpp \
    custom_button.cpp \
    custom_label.cpp \
    custom_slider.cpp \
    filterwheel.cpp

HEADERS  += main_gui.h \
    gui_methods.h \
    gui_var.h \
    gui_panelfolder.h \
    gui_panelcontrol.h \
    gui_panelimage.h \
    gui_panelwheel.h \
    custom_button.h \
    custom_label.h \
    custom_slider.h \
    filterwheel.h

FORMS    += main_gui.ui

#Opencv library declarations
INCLUDEPATH += C:/opencv-mingw/install/include
LIBS += -L"C:/opencv-mingw/install/x86/mingw/bin"
LIBS += -lopencv_calib3d2413
LIBS += -lopencv_contrib2413
LIBS += -lopencv_core2413
LIBS += -lopencv_features2d2413
LIBS += -lopencv_flann2413
LIBS += -lopencv_gpu2413
LIBS += -lopencv_highgui2413
LIBS += -lopencv_imgproc2413
LIBS += -lopencv_legacy2413
LIBS += -lopencv_ml2413
LIBS += -lopencv_nonfree2413
LIBS += -lopencv_objdetect2413
LIBS += -lopencv_ocl2413
LIBS += -lopencv_photo2413
LIBS += -lopencv_stitching2413
LIBS += -lopencv_superres2413
LIBS += -lopencv_video2413
LIBS += -lopencv_videostab2413

DISTFILES += \
    custom_slider.qml \
    custom_gradient.js

RESOURCES += \
    myrc.qrc
