#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QButtonGroup>
#include "window_common.h"
#include "./UI/ui_mainwidget.h"
#include "onescreen.h"
#include "twoScreen.h"
#include "fourscreen.h"
#include "nineScreen.h"
#include "sixteenScreen.h"
#include "localVedioMenu.h"
#include "vedioMeeting.h"
#include "electronicMap.h"
#include "vedioSearch.h"
#include "login/loginui.h"
#include <QPropertyAnimation>
#include "localMonitor/localmonitormenu.h"
#include "intercom/intercomui.h"

class MainWidget : public QWidget, private Ui::MainWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void init();
    static int m_curScreen;//当前分屏
    static long long m_winFd;//窗口句柄
    static QStackedWidget* m_stackedWidget_central_show;
    static bool setScreenModel(int num);
    static bool setWindowSize(int winNum,int square);

private:
    bool show_all_device();
    long long apply_one_winFd();//申请一个可用的窗口句柄
    bool window_user_regist(long long winFd,INPUT_DEV_TYPE_E user_devType,int user_devId);//窗口使用者注册
    bool window_user_cancel(long long winFd);//窗口使用者注销
    bool update_central_show_rect();

public slots:
    void timerUpdate(void);
    void localMonitorBtnClickedSlot();
    void intercomBtnClickedSlot();
    void videoMeetingBtnClickedSlot();
    void mapBtnClickedSlot();
    void videoConsultBtnClickedSlot();
    void btnClickedSlot(QAbstractButton* button);
    void login_btn_clicked_slot();
    void userLoginStatusHandler(bool status);
    void loginUiCloseSlot();
private:
    Ui::MainWidget *ui;
    QStackedWidget *m_pStackedWidget;
    oneScreen m_onescreen;
    twoScreen m_twoscreen;
    fourScreen m_fourscreen;
    nineScreen m_ninescreen;
    sixteenScreen m_sixteenscreen;

    vedioMeeting* m_vedioMeetting;
    electronicMap* m_electronicMap;
    vedioSearch* m_vedioSearch;
    LoginUi *loginUiInstance=nullptr;

    QGridLayout* m_gridLayout_stack_central;
    QGraphicsOpacityEffect *m_opacityEffect;
    int m_curFuncIdex;//光标当前所在的功能页面（本地视频，视频会议，电子地图等大功能）对应的下标
    list<DEVICEINFO_S> m_dev_list;
    //pthread_mutex_t m_pthreadMutex;
    static list<WINDOW_PROPERTY_ST> m_window_list;
    static RECT_ST m_central_show_rect;

    QButtonGroup *buttonGroup;
    QPropertyAnimation *loginUIAnimation;
    LocalMonitorMenu *localMonitorMenu=nullptr;
    IntercomUi *intercomUi;
    int lastBtnId;
};

#endif // MAINWIDGET_H
