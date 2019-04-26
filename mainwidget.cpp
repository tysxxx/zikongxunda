#include "mainwidget.h"


QStackedWidget* MainWidget::m_stackedWidget_central_show = NULL;
int MainWidget::m_curScreen = 0;
long long MainWidget::m_winFd = 10000;
list<WINDOW_PROPERTY_ST> MainWidget::m_window_list;
RECT_ST MainWidget::m_central_show_rect;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->frame_menu->setFixedWidth(185);
    setWindowFlags((Qt::FramelessWindowHint));//设置窗体无边框
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    m_curScreen = FOURSCREENSHOW;
    m_curFuncIdex = FOURSCREENSHOW;

    this->setAttribute(Qt::WA_TranslucentBackground);
    QWSServer::setBackground(QColor(0, 0, 0, 0));

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(ui->localMonitorBtn);
    buttonGroup->addButton(ui->intercomBtn);
    buttonGroup->addButton(ui->videoMeetingBtn);
    buttonGroup->addButton(ui->mapBtn);
    buttonGroup->addButton(ui->videoConsultBtn);
    buttonGroup->addButton(ui->videoConsultBtn);
    buttonGroup->addButton(ui->settingBtn);
    lastBtnId = buttonGroup->id(ui->localMonitorBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    for(auto button: buttonGroup->buttons()){
        button->setStyleSheet("QPushButton{background-color:transparent; color: rgba(255, 255, 255, 64%);}");
    }
    ui->localMonitorBtn->setStyleSheet("QPushButton{background-color:#64bbf1; color: rgba(255, 255, 255, 64%);}");

    m_stackedWidget_central_show = new QStackedWidget(ui->widget_central_show);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_stackedWidget_central_show->sizePolicy().hasHeightForWidth());
    m_stackedWidget_central_show->setSizePolicy(sizePolicy);
    m_stackedWidget_central_show->addWidget(&m_onescreen);
    m_stackedWidget_central_show->addWidget(&m_twoscreen);
    m_stackedWidget_central_show->addWidget(&m_fourscreen);
    m_stackedWidget_central_show->addWidget(&m_ninescreen);
    m_stackedWidget_central_show->addWidget(&m_sixteenscreen);


    //在中央显示窗口ui->widget_central_show添加m_stackedWidget_central_show的布局，使得能够随窗口自适应
    m_gridLayout_stack_central = new QGridLayout(ui->widget_central_show);
    m_gridLayout_stack_central->setSpacing(0);
    m_gridLayout_stack_central->setContentsMargins(0, 0, 0, 0);
    m_gridLayout_stack_central->addWidget(m_stackedWidget_central_show, 0, 0);


    m_stackedWidget_central_show->setCurrentIndex(FOURSCREENSHOW);
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(login_btn_clicked_slot()));
    connect(NetworkManager::instance(), SIGNAL(userLoginStatus(bool)), this, SLOT(userLoginStatusHandler(bool)));
}

//析构
MainWidget::~MainWidget()
{
    if(loginUiInstance){
        loginUiInstance->close();
        delete loginUiInstance;
    }
    loginUiInstance = nullptr;
}

//初始化
void MainWidget::init()
{
    update_central_show_rect();
    //设备初始化
    zkCarDevEngine::instance()->device_init();
    setScreenModel(4);//默认四分屏
    zkCarDevEngine::instance()->get_dev_list(&m_dev_list);
    show_all_device();

    intercomUi = new IntercomUi();
    m_vedioMeetting = new vedioMeeting();
    m_electronicMap = new electronicMap();
    m_vedioSearch = new vedioSearch();
    m_stackedWidget_central_show->addWidget(intercomUi);
    m_stackedWidget_central_show->addWidget(m_vedioMeetting);
    m_stackedWidget_central_show->addWidget(m_electronicMap);
    m_stackedWidget_central_show->addWidget(m_vedioSearch);

}

void MainWidget::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    //QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");//dddd代表周几
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_time->setText(str);
    //qDebug()<<str;
}

//登录界面调用
void MainWidget::login_btn_clicked_slot()
{
    if(!loginUiInstance){
        loginUiInstance = new LoginUi();
        connect(loginUiInstance, SIGNAL(loginUiClose()), SLOT(loginUiCloseSlot()));
        loginUiInstance->open();
    }
}

//登录状态(成功/失败)处理
void MainWidget::userLoginStatusHandler(bool status)
{
    if(status){ //成功
        ui->loginBtn->setText(loginUiInstance->loginUserName());
        if(loginUiInstance){
            loginUiInstance->close();
        }
        loginUiInstance = nullptr;
    }
}

void MainWidget::loginUiCloseSlot()
{
    loginUiInstance = nullptr;
}


//按键组处理
void MainWidget::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setStyleSheet("QPushButton{background-color:transparent; color: rgba(255, 255, 255, 64%);}");
    button->setStyleSheet("QPushButton{background-color:#64bbf1; color: rgba(255, 255, 255, 64%);}");
    lastBtnId = buttonGroup->id(button);

    if(button == ui->localMonitorBtn){
         localMonitorBtnClickedSlot();
    }else if(button == ui->intercomBtn){
        intercomBtnClickedSlot();
    }else if(button == ui->videoMeetingBtn){
        videoMeetingBtnClickedSlot();
    }else if(button == ui->mapBtn){
        mapBtnClickedSlot();
    }else if(button == ui->videoConsultBtn){
        videoConsultBtnClickedSlot();
    }else if(button == ui->settingBtn){

    }
}

//本地监控
void MainWidget::localMonitorBtnClickedSlot()
{
    if(m_curFuncIdex == ONESCREENSHOW || m_curFuncIdex == FOURSCREENSHOW || m_curFuncIdex == NINESCREENSHOW || m_curFuncIdex == SIXTEENSCREENSHOW)
    {
        QRect rect;
        rect.setRect(ui->localMonitorBtn->geometry().x()+ui->localMonitorBtn->geometry().width()+2+4,
                    ui->localMonitorBtn->geometry().y()+ui->frame_status->geometry().height()+2,
                    250,
                    264);
        if(localMonitorMenu){
            localMonitorMenu->close();
            localMonitorMenu->deleteLater();
            localMonitorMenu = nullptr;
        }else{
            localMonitorMenu = new LocalMonitorMenu(rect);
            localMonitorMenu->setGeometry(rect);
            localMonitorMenu->show();
        }

    }else
        {
            m_vedioSearch->goToInitStatu();//这里也要透明显示视频窗口，因此要确保播放器的显示窗口关闭，不然用户会看到窗口重叠显示
            m_curFuncIdex = m_curScreen;
            m_stackedWidget_central_show->setCurrentIndex(m_curFuncIdex);
        }
}

//互动
void MainWidget::intercomBtnClickedSlot()
{
    if(m_curFuncIdex != INTERACTIONFUN)
    {
        m_curFuncIdex = INTERACTIONFUN;
        m_stackedWidget_central_show->setCurrentIndex(m_curFuncIdex);
    }
}

//视频会议
void MainWidget::videoMeetingBtnClickedSlot()
{
    if(m_curFuncIdex != VEDIOMEETFUN)
    {
        m_vedioSearch->goToInitStatu();//这里也要透明显示视频窗口，因此要确保播放器的显示窗口关闭，不然用户会看到窗口重叠显示

        m_curFuncIdex = VEDIOMEETFUN;
        m_stackedWidget_central_show->setCurrentIndex(m_curFuncIdex);
    }
}

//地图
void MainWidget::mapBtnClickedSlot()
{
    if(m_curFuncIdex != MAPFUN)
    {
        m_curFuncIdex = MAPFUN;
        m_stackedWidget_central_show->setCurrentIndex(m_curFuncIdex);
    }
}

//录像查阅
void MainWidget::videoConsultBtnClickedSlot()
{
    if(m_curFuncIdex != CONSULTRECORDFUN)
    {
        m_curFuncIdex = CONSULTRECORDFUN;
        m_stackedWidget_central_show->setCurrentIndex(m_curFuncIdex);
    }
}

bool MainWidget::setScreenModel(int num)
{
    int square = 1;
    int index = -1;
    switch(num)
    {
        case 1:
            square = 1;
            index = ONESCREENSHOW;
            break;
        case 2:
            square = 1;
            index = TWOSCREENSHOW;
            break;
        case 4:
            square = 2;
            index = FOURSCREENSHOW;
            break;
        case 9:
            square = 3;
            index = NINESCREENSHOW;
            break;
        case 16:
            square = 4;
            index = SIXTEENSCREENSHOW;
            break;
        default:
            return false;
    }
    m_curScreen = index;
    m_stackedWidget_central_show->setCurrentIndex(index);
    setWindowSize(num,square);

    return true;
}

bool MainWidget::setWindowSize(int winNum,int square)
{
    int x = m_central_show_rect.s32X;
    int y = m_central_show_rect.s32Y;
    int width = m_central_show_rect.u32Width;
    int height = m_central_show_rect.u32Height;
    zkCarDevEngine::instance()->zkCleanStandardWindow();
    WINDOW_PROPERTY_ST winProperty;
    m_window_list.clear();qDebug()<<"x:"<<x<<",y:"<<y<<",width"<<width<<",height"<<height;
    if(winNum == 2)
    {//二分屏比较特殊，不适用标准计算公式，单独写
        winProperty.rect.s32X = ALIGN_FUNC(x,2);
        winProperty.rect.s32Y = ALIGN_FUNC(y,2);
        winProperty.rect.u32Width = ALIGN_FUNC(width/2, 2);
        winProperty.rect.u32Height = ALIGN_FUNC(height, 2);
        winProperty.winfd = ++m_winFd;
        winProperty.statu = false;
        //winProperty.user_devType = OTHER_VEDIO;
        winProperty.user_devId = -1;
        zkCarDevEngine::instance()->zkSetOneWindow(winProperty.winfd,&winProperty.rect);
        m_window_list.push_back(winProperty);
        if(width%2 == 0)
            winProperty.rect.s32X = ALIGN_FUNC(x,2) + winProperty.rect.u32Width;
        else
            winProperty.rect.s32X = ALIGN_FUNC(x,2) + winProperty.rect.u32Width + 1;
        winProperty.rect.s32Y = ALIGN_FUNC(y,2);
        winProperty.rect.u32Width = ALIGN_FUNC(width/2, 2);
        winProperty.rect.u32Height = ALIGN_FUNC(height, 2);
        winProperty.winfd = ++m_winFd;
        winProperty.statu = false;
        //winProperty.user_devType = OTHER_VEDIO;
        winProperty.user_devId = -1;
        zkCarDevEngine::instance()->zkSetOneWindow(winProperty.winfd,&winProperty.rect);
        m_window_list.push_back(winProperty);
        return true;
    }
    for (int i=0; i<winNum; i++)
    {
        winProperty.rect.s32X = ALIGN_FUNC(x,2) + ALIGN_FUNC((width/square) * (i%square), 2);
        winProperty.rect.s32Y = ALIGN_FUNC(y,2) + ALIGN_FUNC((height/square) * (i/square), 2);
        winProperty.rect.u32Width = ALIGN_FUNC(width/square, 2);
        winProperty.rect.u32Height = ALIGN_FUNC(height/square, 2);
        winProperty.winfd = ++m_winFd;
        winProperty.statu = false;
        //winProperty.user_devType = OTHER_VEDIO;
        winProperty.user_devId = -1;
        zkCarDevEngine::instance()->zkSetOneWindow(winProperty.winfd,&winProperty.rect);
        m_window_list.push_back(winProperty);
    }
    return true;
}

bool MainWidget::show_all_device()
{
    long long winfd = -1;
    list<DEVICEINFO_S>::iterator it = m_dev_list.begin();
    for(;it!=m_dev_list.end();++it)
    {
        if((winfd = apply_one_winFd()) == -1)
            break;DEBUGLOG("(*it).devType:%d,(*it).devId:%d,winfd:%d\n",(*it).devType,(*it).devId,winfd);
        if(zkCarDevEngine::instance()->zkShowVedio((*it).devType,(*it).devId,winfd))
        {
            window_user_regist(winfd,(*it).devType,(*it).devId);
        }
    }
    return true;
}

long long MainWidget::apply_one_winFd()
{
    long long ret = -1;
    list<WINDOW_PROPERTY_ST>::iterator it = m_window_list.begin();
    for(;it!=m_window_list.end();++it)
    {
        if(!(*it).statu)
        {
            ret = (*it).winfd;
            break;
        }
    }
    return ret;
}

bool MainWidget::window_user_regist(long long winFd,INPUT_DEV_TYPE_E user_devType,int user_devId)
{
    bool ret = false;
    list<WINDOW_PROPERTY_ST>::iterator it = m_window_list.begin();
    for(;it!=m_window_list.end();++it)
    {
        if((*it).winfd == winFd)
        {
            (*it).user_devType = user_devType;
            (*it).user_devId = user_devId;
            (*it).statu = true;
            ret = true;
            break;
        }
    }
    return ret;
}

bool MainWidget::window_user_cancel(long long winFd)
{
    bool ret = false;
    list<WINDOW_PROPERTY_ST>::iterator it = m_window_list.begin();
    for(;it!=m_window_list.end();++it)
    {
        if((*it).winfd == winFd)
        {
            //(*it).user_devType = OTHER_VEDIO;
            (*it).user_devId = -1;
            (*it).statu = false;
            ret = true;
            break;
        }
    }
    return ret;
}

bool MainWidget::update_central_show_rect()
{
    m_central_show_rect.s32X = ui->widget_central_show->geometry().x();
    m_central_show_rect.s32Y = ui->widget_central_show->geometry().y();
    m_central_show_rect.u32Width = ui->widget_central_show->geometry().width();
    m_central_show_rect.u32Height = ui->widget_central_show->geometry().height();
    return true;
}

