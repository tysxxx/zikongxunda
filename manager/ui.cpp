#include "ui.h"
#include <QApplication>
#include <QDesktopWidget>

UI::UI(QObject *parent) : QObject(parent)
{

}

UI::~UI()
{
    if(mainUi)
        delete mainUi;
    mainUi = nullptr;
}

void UI::initUi()
{
    //获取屏幕尺寸
    QRect rect;
    QDesktopWidget *desktopWidget = QApplication::desktop();
    if(desktopWidget){
        rect = desktopWidget->availableGeometry();
        qDebug() << "availableGeometry: " << rect;
    }

    //主界面
    mainUi = new MainUi;
    mainUi->setGeometry(rect);
    mainUi->init();

    //各分界面
        //@.本地监控界面
    localMonitorUi = new LocalMonitorUi(mainUi->getCenterFrame());
    localMonitorUi->init();
        //@.互动交互
    intercomUi = new IntercomUi(mainUi->getCenterFrame());
    intercomUi->setGeometry(mainUi->getCenterFrame());
    //intercomUi->init();
        //@.视频会议
    videoMeetingUi = new VideoMeetingUi(mainUi->getCenterFrame());
    videoMeetingUi->init();
        //@.地图
    mapUi = new MapUi(mainUi->getCenterFrame());
    mapUi->init();
        //@.视频查询
    videoReviewUi = new VideoReviewUi(mainUi->getCenterFrame());
    videoReviewUi->init();
        //@.设置
    settingUi = new SettingUi(mainUi->getCenterFrame());
    settingUi->init();

    mainUi->addCenterWidget(localMonitorUi, MainUi::MainMenuUi::localMonitorUi);
    mainUi->addCenterWidget(intercomUi, MainUi::MainMenuUi::intercomUi);
    mainUi->addCenterWidget(videoMeetingUi, MainUi::MainMenuUi::videoMeetingUi);
    mainUi->addCenterWidget(mapUi, MainUi::MainMenuUi::mapUi);
    mainUi->addCenterWidget(videoReviewUi, MainUi::MainMenuUi::videoReviewUi);

    //设置当前中间要显示的窗口
    mainUi->setCenterWidget(MainUi::MainMenuUi::localMonitorUi);

    //管理实例
    manager = Manager::instance();
    manager->init();

    //信号槽链接
    connect(manager.data(), SIGNAL(layoutSwitchChanged(LayoutMode)), localMonitorUi, SLOT(layoutSwitchHandler(LayoutMode)));

    //设置初始分屏
    localMonitorUi->layoutSwitchHandler(LayoutMode::four);

    //界面显示
    mainUi->show();
}

