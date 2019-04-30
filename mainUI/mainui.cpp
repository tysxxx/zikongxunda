#include "mainui.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QStyleOption>
#include <QPainter>

QStackedLayout *MainUi::stackedLayout = nullptr;

MainUi::MainUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    //setGeometry(rect);
    //setGeometry(100, 100, 500, 500);
    //init();
}

MainUi::~MainUi()
{

}

//初始化
void MainUi::init()
{
    qDebug() << "mainUi: " << geometry();

    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet(".QWidget{background-color: transparent;}");

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
    topFrame->setStyleSheet(tr("QFrame{background-color: #040b17;}"));
    topFrame->setLayout(topHBoxLayout);

    //左侧窗口
        //@.按键
    localMonitorBtn = new QPushButton(tr("本地监控"));
    intercomBtn = new QPushButton(tr("互动调度"));
    videoMeetingBtn = new QPushButton(tr("视频会议"));
    mapBtn = new QPushButton(tr("电子地图"));
    videoConsultBtn = new QPushButton(tr("录像查询"));
    settingBtn = new QPushButton("设置");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(localMonitorBtn);
    buttonGroup->addButton(intercomBtn);
    buttonGroup->addButton(videoMeetingBtn);
    buttonGroup->addButton(mapBtn);
    buttonGroup->addButton(videoConsultBtn);
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
    leftVBoxLayout->setContentsMargins(0, 0, 0, 0);
    leftVBoxLayout->setSpacing(40);
    leftVBoxLayout->addSpacing(100);
    leftVBoxLayout->addWidget(localMonitorBtn);
    leftVBoxLayout->addWidget(intercomBtn);
    leftVBoxLayout->addWidget(videoMeetingBtn);
    leftVBoxLayout->addWidget(mapBtn);
    leftVBoxLayout->addWidget(videoConsultBtn);
    leftVBoxLayout->addWidget(settingBtn);
    leftVBoxLayout->addStretch();

    leftFrame = new QFrame(this);
    leftFrame->setGeometry(0, topFrame->height()+1, 184, height()-(topFrame->height()+1));
    leftFrame->setStyleSheet(tr("QFrame{background-color: #040b17;}"));
    leftFrame->setLayout(leftVBoxLayout);

    //中间窗口
    centerFrame = new QFrame(this);
    centerFrame->setGeometry(leftFrame->width()+1, topFrame->height()+1, width()-leftFrame->width(), height()-topFrame->height());
    centerFrame->setStyleSheet(tr("QFrame{background-color: transparent;}"));

    intercomUi = new IntercomUi(centerFrame->rect());
    intercomUi->init();
    videoMeetingUi = new VideoMeetingUi(centerFrame->rect());
    MapUi = new electronicMap();
    videoSearchUi = new vedioSearch();

    stackedLayout = new QStackedLayout(centerFrame);
    stackedLayout->addWidget(&oneScreenUi);
    stackedLayout->addWidget(&twoScreenUi);
    stackedLayout->addWidget(&fourScreenUi);
    stackedLayout->addWidget(&nineScreenUi);
    stackedLayout->addWidget(&sixteenScreenUi);
    stackedLayout->addWidget(intercomUi);
    stackedLayout->addWidget(videoMeetingUi);
    stackedLayout->addWidget(MapUi);
    stackedLayout->addWidget(videoSearchUi);

    stackedLayout->setCurrentWidget(&fourScreenUi);

    //其他
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

}

//重载paintEvent事件
void MainUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//登录
void MainUi::loginBtnClickedSlot()
{
    loginUiInstance = new LoginUi(this);
    loginUiInstance->open();
    loginUiInstance = nullptr;
}

//按键组处理
void MainUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);

    if(button == localMonitorBtn){
         localMonitorBtnClickedSlot();
    }else if(button == intercomBtn){
        intercomBtnClickedSlot();
    }else if(button == videoMeetingBtn){
        videoMeetingBtnClickedSlot();
    }else if(button == mapBtn){
        mapBtnClickedSlot();
    }else if(button == videoConsultBtn){
        videoConsultBtnClickedSlot();
    }else if(button == settingBtn){

    }
}

//布局分屏模式
void MainUi::layoutSwitchMode(LayoutMode layoutMode)
{

    switch (layoutMode) {
    case LayoutMode::one:
        stackedLayout->setCurrentIndex(0);
        break;
    case LayoutMode::two:
        stackedLayout->setCurrentIndex(1);
        break;
    case LayoutMode::four:
        stackedLayout->setCurrentIndex(2);
        break;
    case LayoutMode::nine:
        stackedLayout->setCurrentIndex(3);
        break;
    case LayoutMode::sixteen:
        stackedLayout->setCurrentIndex(4);
        break;
    default:
        break;
    }
}

//本地监控
void MainUi::localMonitorBtnClickedSlot()
{
    //计算窗口放置的位置
    QRect rect(leftFrame->width()+2,
               localMonitorBtn->y()+topFrame->height(),
                250,
                264);

    if(localMonitorMenu){
        localMonitorMenu->close();
        localMonitorMenu = nullptr;
    }else{
        localMonitorMenu = new LocalMonitorMenu(rect);
        localMonitorMenu->setGeometry(rect);
        localMonitorMenu->show();
    }
}

//互动
void MainUi::intercomBtnClickedSlot()
{
    stackedLayout->setCurrentWidget(intercomUi);
}

//视频会议
void MainUi::videoMeetingBtnClickedSlot()
{
    stackedLayout->setCurrentWidget(videoMeetingUi);
}

//地图
void MainUi::mapBtnClickedSlot()
{
    stackedLayout->setCurrentWidget(MapUi);
}

//录像查询
void MainUi::videoConsultBtnClickedSlot()
{
    stackedLayout->setCurrentWidget(videoSearchUi);
}

//时间更新
void MainUi::timerUpdate()
{
    timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}
