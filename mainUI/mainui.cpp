#include "mainui.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QStyleOption>
#include <QPainter>

MainUi::MainUi(QRect rect, QWidget *parent) : QWidget(parent)
{

}

MainUi::~MainUi()
{

}

//初始化
void MainUi::init()
{
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);

    //顶部窗口
    QLabel *logoIcon = new QLabel;
    logoIcon->setPixmap(QPixmap(":/statusLog/resource/icon/logo.png"));

    loginBtn = new QPushButton(tr("admin"));
    loginBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    loginBtn->setStyleSheet("color:#17ee49; font: 21px; background-color: transparent;");
    connect(loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnClickedSlot()));

    timeLabel = new QLabel(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    timeLabel->setStyleSheet("color:#ffffff; font: 21px");

    mobileLabel =  new QLabel(tr("中国移动"));
    mobileLabel->setStyleSheet("color:#ffffff; font: 21px");

    signalLabel =  new QLabel;
    signalLabel->setPixmap(QPixmap(":/statusLog/resource/icon/信号.png"));

    batteryLabel = new QLabel;
    batteryLabel->setPixmap(QPixmap(":/statusLog/resource/icon/电量.png"));

    QHBoxLayout *topHBoxLayout = new QHBoxLayout;
    topHBoxLayout->setMargin(0);
    topHBoxLayout->setSpacing(40);
    topHBoxLayout->addSpacing(20);
    topHBoxLayout->addWidget(logoIcon);
    topHBoxLayout->addWidget(loginBtn);
    topHBoxLayout->addStretch();
    topHBoxLayout->addWidget(timeLabel);
    topHBoxLayout->addWidget(mobileLabel);
    topHBoxLayout->addWidget(signalLabel);
    topHBoxLayout->addWidget(batteryLabel);
    topHBoxLayout->addSpacing(20);

    topFrame = new QFrame(this);
    topFrame->setGeometry(0, 0, width(), 57);
    topFrame->setStyleSheet(tr(".QFrame{background-color: #040b17;}"));
    topFrame->setLayout(topHBoxLayout);

    //左侧窗口
        //@.按键
    localMonitorBtn = new QPushButton(tr("本地监控"));
    intercomBtn = new QPushButton(tr("互动调度"));
    videoMeetingBtn = new QPushButton(tr("视频会议"));
    mapBtn = new QPushButton(tr("电子地图"));
    videoReviewBtn = new QPushButton(tr("录像查询"));
    settingBtn = new QPushButton("设置");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(localMonitorBtn);
    buttonGroup->addButton(intercomBtn);
    buttonGroup->addButton(videoMeetingBtn);
    buttonGroup->addButton(mapBtn);
    buttonGroup->addButton(videoReviewBtn);
    buttonGroup->addButton(settingBtn);
    lastBtnId = buttonGroup->id(localMonitorBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    for(auto button: buttonGroup->buttons()){
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        button->setProperty("valid", false);
        button->setStyleSheet("QPushButton{background-color:transparent; color: rgba(255, 255, 255, 64%);"
                              "height: 50px; font: 24px}"
                              "QPushButton[valid=true]{background-color: #649bf1}");
    }
    localMonitorBtn->setProperty("valid", true);

    QVBoxLayout *leftVBoxLayout = new QVBoxLayout;
    leftVBoxLayout->setMargin(0);
    leftVBoxLayout->setSpacing(40);
    leftVBoxLayout->addSpacing(100);
    leftVBoxLayout->addWidget(localMonitorBtn);
    leftVBoxLayout->addWidget(intercomBtn);
    leftVBoxLayout->addWidget(videoMeetingBtn);
    leftVBoxLayout->addWidget(mapBtn);
    leftVBoxLayout->addWidget(videoReviewBtn);
    leftVBoxLayout->addWidget(settingBtn);
    leftVBoxLayout->addStretch();

    leftFrame = new QFrame(this);
    leftFrame->setGeometry(0, topFrame->height()+1, 184, height()-(topFrame->height()+1));
    leftFrame->setStyleSheet(tr(".QFrame{background-color: #040b17;}"));
    leftFrame->setLayout(leftVBoxLayout);

    //中间窗口
    centerFrame = new QFrame(this);
    centerFrame->setGeometry(leftFrame->width()+1, topFrame->height()+1, width()-leftFrame->width(), height()-topFrame->height());
    centerFrame->setStyleSheet(tr(".QFrame{background-color: transparent;}"));
    stackedLayout = new QStackedLayout(centerFrame);

    //更新时间
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

//向中间区域添加窗口
void MainUi::addCenterWidget(QWidget *widget, MainMenuUi menuUi)
{
    currMenuUi[menuUi] = widget;
    stackedLayout->addWidget(widget);
}

//设置当前中间窗口
void MainUi::setCenterWidget(MainMenuUi menuUi)
{
    mainMenuUi = menuUi;
    stackedLayout->setCurrentWidget(currMenuUi[menuUi]);
}

//登录
void MainUi::loginBtnClickedSlot()
{
    if(loginUi)
        return;
    loginUi = new LoginUi(this);
    loginUi->open();
}

//按键组处理
void MainUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->unpolish(button);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);

    //关闭本地监控菜单框
    if(button != localMonitorBtn)
        if(localMonitorMenu) localMonitorMenu->close();

    if(button == localMonitorBtn){ localMonitorBtnClickedSlot(); return;}
    else if(button == intercomBtn) mainMenuUi = MainMenuUi::intercomUi;
    else if(button == videoMeetingBtn) mainMenuUi = MainMenuUi::videoMeetingUi;
    else if(button == mapBtn) mainMenuUi = MainMenuUi::mapUi;
    else if(button == videoReviewBtn) mainMenuUi = MainMenuUi::videoReviewUi;
    else if(button == settingBtn) mainMenuUi = MainMenuUi::settingUi;

    stackedLayout->setCurrentWidget(currMenuUi[mainMenuUi]);
}

//本地监控
void MainUi::localMonitorBtnClickedSlot()
{
    if(mainMenuUi != MainMenuUi::localMonitorUi){
        mainMenuUi = MainMenuUi::localMonitorUi;
        stackedLayout->setCurrentWidget(currMenuUi[mainMenuUi]);
        return;
    }
        //计算窗口放置的位置
        QRect rect(leftFrame->width()+2,
                   localMonitorBtn->y()+topFrame->height(),
                   250,
                   264);

        if(!localMonitorMenu){
            localMonitorMenu = new LocalMonitorMenu(rect);
            localMonitorMenu->setGeometry(rect);
            connect(localMonitorMenu, SIGNAL(layoutSwitchChanged(LayoutMode)), this, SLOT(layoutSwitchMode(LayoutMode)));
            localMonitorMenu->show();
        }else
            localMonitorMenu->close();

}

//时间更新
void MainUi::timerUpdate()
{
    timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}
