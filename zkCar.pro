#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T15:01:16
#
#-------------------------------------------------

QT       += core gui webkit script webkitwidgets network
QT += network
UI_DIR=./UI  #解决ui.h不及时更新的问题
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zkCar
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

DESTDIR = /home/tys/software/nfsboot/
target.path=/test
INSTALLS += target

SOURCES += main.cpp\
        mainwidget.cpp \
    onescreen.cpp \
    fourscreen.cpp \
    pushButtonMenu.cpp \
    twoScreen.cpp \
    nineScreen.cpp \
    sixteenScreen.cpp \
    electronicMap.cpp \
    vedioMeeting.cpp \
    vedioSearch.cpp \
    dateTimeButton.cpp \
    date.cpp \
    mediaplayer.cpp \
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
    intercom/qflowlayout.cpp

HEADERS  += mainwidget.h \
    onescreen.h \
    fourscreen.h \
    window_common.h \
    #button_localvedio_listwidget.h \
    nofocusrectstyle.h \
    #localVedioMenu.h \
    #screenModeMenu.h \
    pushButtonMenu.h \
    windowdefine.h \
    zkCarDevEnginge.h \
    zkdevdefine.h \
    twoScreen.h \
    nineScreen.h \
    sixteenScreen.h \
    electronicMap.h \
    vedioMeeting.h \
    vedioSearch.h \
    dateTimeButton.h \
    date.h \
    mediaplayer.h \
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
    intercom/qflowlayout.h

FORMS    += mainwidget.ui \
    onescreen.ui \
    fourscreen.ui \
    twoscreen.ui \
    ninescreen.ui \
    sixteenscreen.ui \
    electronicmap.ui \
    vediomeeting.ui \
    vediosearch.ui \
    mediaplayer.ui

RESOURCES += \
    statuslog.qrc \
    datetimeimg.qrc \
    recordimg.qrc

INCLUDEPATH += $$PWD/network
#INCLUDEPATH += /home/tys/doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/extdrv/tlv320aic31 /home/tys/doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/include
#LIBS += -L/home/tys/doc/wen_doc/Hi3531A_SDK_V1.0.4.0/mpp/lib -lmpi -lhdmi -ljpeg -lupvqe -ldnvqe -lVoiceEngine

#INCLUDEPATH += /home/tys/software/hisi3531aLib/mp4v2/include /home/tys/software/hisi3531aLib/faac/include /home/tys/software/hisi3531aLib/faad/include /home/tys/software/hisi3531aLib/libcurl/include ./common
#LIBS += -L/home/tys/software/hisi3531aLib/mp4v2/lib/ -L/home/tys/software/hisi3531aLib/faac/lib -L/home/tys/software/hisi3531aLib/faad/lib -L/home/tys/software/hisi3531aLib/libcurl/lib -lmp4v2 -lfaac -lfaad -lcurl
#LIBS += -L/home/tys/software/hisi3531aLib -lzkpush -lhisicar -lzkrtsp

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
