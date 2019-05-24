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
#include <QPointer>
#include <QMap>
#include "localMonitor/localmonitormenu.h"
#include "intercom/intercomui.h"
#include "login/loginui.h"
#include "videoMeeting/videomeetingui.h"
#include "videoReview/videoreviewui.h"
#include "localMonitor/localmonitorui.h"
#include "common/common.h"


class MainUi : public QWidget
{
    Q_OBJECT
public:
    MainUi(QRect rect = QRect(),QWidget *parent = 0);
    ~MainUi();

    enum class MainMenuUi{
        localMonitorUi,
        intercomUi,
        videoMeetingUi,
        mapUi,
        videoReviewUi,
        settingUi,
    };

    void init();
    void addCenterWidget(QWidget *widget, MainMenuUi menuUi);
    void setCenterWidget(MainMenuUi menuUi);
    QRect getCenterFrame();
signals:

public slots:
    void loginBtnClickedSlot();
    void localMonitorBtnClickedSlot();
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

    QFrame *topFrame;
    QFrame *leftFrame;
    QWidget *centerFrame;
    QPointer<LoginUi> loginUi;
    QPointer<LocalMonitorMenu> localMonitorMenu;
    QStackedLayout *stackedLayout;
    MainMenuUi mainMenuUi;
    QMap<MainMenuUi, QWidget*> currMenuUi;
};

#endif // MAINUI_H
