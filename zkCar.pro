#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T15:01:16
#
#-------------------------------------------------

QT += core gui  network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zkCar
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
    network/networkmanager.cpp \
    localMonitor/localmonitormenu.cpp \
    localMonitor/layoutswitchmenu.cpp \
    login/loginui.cpp \
    intercom/intercomui.cpp \
    mainUI/mainui.cpp \
    videoMeeting/itemeditor.cpp \
    videoMeeting/meetingModel.cpp \
    videoMeeting/videomeetinglistitem.cpp \
    videoMeeting/videomeetingui.cpp \
    videoReview/videoinfotableui.cpp \
    videoReview/videoplayui.cpp \
    videoReview/videoreviewui.cpp \
    intercom/qflowlayout.cpp \
    localMonitor/localmonitorui.cpp \
    hisiInterface/hisiinterface.cpp \
    manager/manager.cpp \
    manager/ui.cpp \
    videoMeeting/listwidgetitem.cpp \
    intercom/treewidgetitem.cpp \
    map/mapui.cpp \
    videoReview/videofullscreen.cpp \
    setting/settingui.cpp \
    test.cpp

HEADERS  += mainwidget.h \
    network/networkmanager.h \
    network/type.h \
    localMonitor/localmonitormenu.h \
    localMonitor/layoutswitchmenu.h \
    login/loginui.h \
    intercom/intercomui.h \
    mainUI/mainui.h \
    videoMeeting/itemeditor.h \
    videoMeeting/meetingModel.h \
    videoMeeting/videomeetinglistitem.h \
    videoMeeting/videomeetingui.h \
    videoReview/videoinfotableui.h \
    videoReview/videoplayui.h \
    videoReview/videoreviewui.h \
    intercom/qflowlayout.h \
    localMonitor/localmonitorui.h \
    hisiInterface/hisiinterface.h \
    common/common.h \
    manager/manager.h \
    manager/ui.h \
    videoMeeting/listwidgetitem.h \
    intercom/treewidgetitem.h \
    map/mapui.h \
    videoReview/videofullscreen.h \
    setting/settingui.h \
    common/keyborder.h \
    test.h


RESOURCES += \
    statuslog.qrc \
    datetimeimg.qrc \
    recordimg.qrc

INCLUDEPATH += $$PWD/network

equals(QMAKE_CXX, arm-hisiv300-linux-g++) {

    QT += webkit script webkitwidgets

    DEFINES += HISI_PLATFORM
    DESTDIR = /home/tys/software/nfsboot/
    system("cp /home/tys/software/zkCar/lib/keyborder /home/tys/software/nfsboot/ -r")

    INCLUDEPATH += $$PWD/lib/

    unix:!macx: LIBS += -L$$PWD/lib/ -lzkpush
    unix:!macx: LIBS += -L$$PWD/lib/ -lzkrtsp

    INCLUDEPATH += $$PWD/.
    DEPENDPATH += $$PWD/.

    unix:!macx: LIBS += -L$$PWD/../../doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/lib/ -lmpi -lhdmi -ljpeg -lupvqe -ldnvqe -lVoiceEngine

    INCLUDEPATH += $$PWD/../../doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/extdrv/tlv320aic31
    INCLUDEPATH += $$PWD/../../doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/include

    unix:!macx: LIBS += -L$$PWD/lib/faac/lib/ -lfaac

    INCLUDEPATH += $$PWD/lib/faac/include $$PWD/lib/mp4v2/include $$PWD/lib/faad/include $$PWD/lib/mp4v2/include $$PWD/lib/libcurl/include
    DEPENDPATH += $$PWD/lib/faac/include $$PWD/lib/faad/include $$PWD/lib/mp4v2/include $$PWD/lib/mp4v2/include $$PWD/lib/libcurl/include
    INCLUDEPATH += $$PWD/lib/zlib/include $$PWD/lib/openssl/include $$PWD/lib/openssl/include
    INCLUDEPATH += $$PWD/lib/faac/include

    unix:!macx: PRE_TARGETDEPS += $$PWD/lib/faac/lib/libfaac.a
    unix:!macx: LIBS += -L$$PWD/lib/faad/lib/ -lfaad
    unix:!macx: PRE_TARGETDEPS += $$PWD/lib/faad/lib/libfaad.a
    unix:!macx: LIBS += -L$$PWD/lib/mp4v2/lib/ -lmp4v2
    #unix:!macx: PRE_TARGETDEPS += $$PWD/lib/libcurl/lib/libcurl.a
    unix:!macx: LIBS += -L$$PWD/lib/libcurl/lib/ -lcurl
    LIBS += -L$$PWD/lib/ -lhisicar
    unix:!macx: LIBS += -L$$PWD/lib/zlib/lib/ -lz
    unix:!macx: LIBS += -L$$PWD/lib/openssl/lib/ -lssl
    unix:!macx: LIBS += -L$$PWD/lib/openssl/lib/ -lcrypto

    unix:!macx: LIBS += -L$$PWD/lib/faac/lib/ -lfaac

    unix:!macx: LIBS += -L$$PWD/lib/json_hisi/ -ljsoncpp

    INCLUDEPATH += $$PWD/lib/json_hisi/include
    DEPENDPATH += $$PWD/lib/json_hisi/include

    unix:!macx: LIBS += -L$$PWD/lib/keyborder/ -lKeyBorder
    INCLUDEPATH += $$PWD/lib/keyborder
    DEPENDPATH += $$PWD/lib/keyborder
 }


