#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRect>
#include <QStackedLayout>
#include "localMonitor/localmonitormenu.h"
#include "intercom/intercomui.h"
#include "login/loginui.h"
#include "onescreen.h"
#include "twoScreen.h"
#include "fourscreen.h"
#include "nineScreen.h"
#include "sixteenScreen.h"
#include "vedioSearch.h"
#include "electronicMap.h"
#include "videoMeeting/videomeetingui.h"
#include "videoReview/videoreviewui.h"
#include "localMonitor/localmonitorui.h"
#include "hisiInterface/hisiinterface.h"

class MainUi : public QWidget
{
    Q_OBJECT
public:
    explicit MainUi(QRect rect,QWidget *parent = 0);
    ~MainUi();

    enum class MainMenuUi{
        localMonitorUi,
        intercomUi,
        videoMeetingUi,
        mapUi,
        videoReviewUi,
        settingUi,
    };

    enum class LayoutMode{
        one,
        two,
        four,
        nine,
        sixteen,
    };

    void init();
    void paintEvent(QPaintEvent *);
    static void layoutSwitchMode(LayoutMode layoutMode);
signals:

public slots:
    void loginBtnClickedSlot();
    void localMonitorBtnClickedSlot();
    void intercomBtnClickedSlot();
    void videoMeetingBtnClickedSlot();
    void mapBtnClickedSlot();
    void videoConsultBtnClickedSlot();
    void btnClickedSlot(QAbstractButton* button);
    void timerUpdate();
private:
    QPushButton *loginBtn;
    QLabel *timeLabel;
    QLabel *mobileLabel;
    QLabel *signalLabel;
    QLabel *batteryLabel;
    QPushButton *localMonitorBtn;
    QPushButton *intercomBtn;
    QPushButton *videoMeetingBtn;
    QPushButton *mapBtn;
    QPushButton *videoReviewBtn;
    QPushButton *settingBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
    QPropertyAnimation *loginUIAnimation;

    QFrame *topFrame;
    QFrame *leftFrame;
    QFrame *centerFrame;
    oneScreen oneScreenUi;
    twoScreen twoScreenUi;
    fourScreen fourScreenUi;
    nineScreen nineScreenUi;
    sixteenScreen sixteenScreenUi;
    VideoMeetingUi *videoMeetingUi;
    electronicMap *MapUi;
    vedioSearch *videoSearchUi;
    VideoReviewUi *videoReviewUi;
    LocalMonitorMenu *localMonitorMenu=nullptr;
    IntercomUi *intercomUi;
    LoginUi *loginUiInstance=nullptr;
    static QStackedLayout *stackedLayout;
    LocalMonitorUi *localMonitorUi;

    HisiDeviceInfoType hisiDeviceInfo;
    MainMenuUi mainMenuUi = MainMenuUi::localMonitorUi;
    static LayoutMode currLayoutMode;
};

#endif // MAINUI_H
