#include "localVedioMenu.h"

localVedioMenu* localVedioMenu::m_instance = NULL;

localVedioMenu::localVedioMenu()
{
    init();
}

localVedioMenu::~localVedioMenu()
{
    if(m_widget != NULL)
    {
        delete m_widget;
        m_widget = NULL;
    }
}

void localVedioMenu::init()
{
    m_rect.setRect(180,90,250,264);
    m_widget = new QFrame();
    m_widget->setWindowFlags((Qt::FramelessWindowHint));//设置窗体无边框
    //m_widget->setAttribute(Qt::WA_TranslucentBackground);
    m_widget->setGeometry(m_rect);
    m_widget->setStyleSheet("QFrame{border-radius:10px; background-color:rgb(4, 11, 23);}");//四个角都设置为圆角，半径10px
//    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
//    m_widget->setGraphicsEffect(opacityEffect);
//    opacityEffect->setOpacity(0.8);

    m_widget->setWindowOpacity(0.8);
    m_font_size = 23;
    m_curr_item = 0;//光标默认停留在第一个item处
    m_font.setPointSize(m_font_size);
    m_button_cnt = 0;
    set_lists();
    m_showStatu = false;



}

void localVedioMenu::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }

localVedioMenu* localVedioMenu::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new localVedioMenu();

    }
    return m_instance;
}

bool localVedioMenu::change_localVedioMenu_show_statu()
{
    if(m_showStatu)
    {
        screenModeMenu::instance()->hide_screenModeMenu();
        m_widget->hide();
        m_showStatu = false;
    }else
        {
            set_button_backGround(0);
            m_widget->show();
            m_showStatu = true;
        }
    return true;
}

bool localVedioMenu::set_widget_rect(QRect* rect)
{
//    if(rect == NULL)
//        return false;
    m_rect = *rect;
    qDebug()<<m_rect.x()<<" "<<m_rect.y()<<" "<<m_rect.width()<<" "<<m_rect.height();
//    m_widget->setGeometry(m_rect);

    if(localMonitorMenu){
        localMonitorMenu->close();
        localMonitorMenu->deleteLater();
        localMonitorMenu = nullptr;
    }else{
        localMonitorMenu = new LocalMonitorMenu(*rect);
        localMonitorMenu->setGeometry(*rect);
        localMonitorMenu->show();
    }
    return true;
}

void localVedioMenu::set_lists()
{
    add_one_pushbutton("    本地抓拍");
    QObject::connect(m_button_list[0],SIGNAL(clicked()),this,SLOT(pushButton0_click_slot()));
    add_one_pushbutton("    布局切换");
    QObject::connect(m_button_list[1],SIGNAL(clicked()),this,SLOT(pushButton1_click_slot()));
    add_one_pushbutton("    取消本地录像");
    QObject::connect(m_button_list[2],SIGNAL(clicked()),this,SLOT(pushButton2_click_slot()));
    add_one_pushbutton("    打开抓拍文件目录");
    QObject::connect(m_button_list[3],SIGNAL(clicked()),this,SLOT(pushButton3_click_slot()));
    add_one_pushbutton("    打开本地录像文件目录");
    QObject::connect(m_button_list[4],SIGNAL(clicked()),this,SLOT(pushButton4_click_slot()));
#if 0
    BTN_MENU_LAOUT_PARA_ST para_st;
    para_st.bottomSize = 2;
    para_st.buttonCnt = 5;
    para_st.buttonSize = 4;
    para_st.leftOffset = 30;
    para_st.p_button_list = &m_button_list[0];
    para_st.p_qwidget = m_widget;
    para_st.spaceSize = 2;
    para_st.topSize = 2;
    pushButtonMenu::set_layout(&para_st);

#endif
    m_button_list[0]->setStyleSheet("QPushButton{text-align : left;background-color:rgb(0, 0, 205);color: rgb(255, 255, 255);}");
#if 1
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);
    m_verticalSpacer0 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer0);
    verticalLayout->addWidget(m_button_list[0]);
    m_verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer1);
    verticalLayout->addWidget(m_button_list[1]);
    m_verticalSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer2);
    verticalLayout->addWidget(m_button_list[2]);
    m_verticalSpacer3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer3);
    verticalLayout->addWidget(m_button_list[3]);
    m_verticalSpacer4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer4);
    verticalLayout->addWidget(m_button_list[4]);
    m_verticalSpacer5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer5);

    verticalLayout->setStretch(0, 2);
    verticalLayout->setStretch(1, 4);
    verticalLayout->setStretch(2, 1);
    verticalLayout->setStretch(3, 4);
    verticalLayout->setStretch(4, 1);
    verticalLayout->setStretch(5, 4);
    verticalLayout->setStretch(6, 1);
    verticalLayout->setStretch(7, 4);
    verticalLayout->setStretch(8, 1);
    verticalLayout->setStretch(9, 4);
    verticalLayout->setStretch(10, 2);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    m_gridLayout = new QGridLayout(m_widget);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addLayout(verticalLayout,0,0);
#endif
}

bool localVedioMenu::add_one_pushbutton(const char* name)
{
    QPushButton* pushButton = new QPushButton(m_widget);
    if(name != NULL)
        pushButton->setText(QObject::tr(name));
    else
        pushButton->setText(QObject::tr("NULL"));
    pushButton->setFont(m_font);
    //pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
    pushButton->setStyleSheet("QPushButton{text-align : left;color: rgb(255, 255, 255);}");
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
    pushButton->setSizePolicy(sizePolicy);
    m_button_list[m_button_cnt] = pushButton;
    ++m_button_cnt;
    return true;
}

void localVedioMenu::pushButton0_click_slot()
{
    qDebug()<<"本地抓拍";
    set_button_backGround(0);
    list<DEVICEINFO_S> dev_list;
    zkCarDevEngine::instance()->get_dev_list(&dev_list);
    list<DEVICEINFO_S>::iterator it = dev_list.begin();

    for(;it != dev_list.end();++it)
    {
        zkCarDevEngine::instance()->zkTakePicture((*it).devType,(*it).devId);

    }

}

void localVedioMenu::pushButton1_click_slot()
{
    qDebug()<<"布局切换";
    set_button_backGround(1);
    QRect rect;
    rect.setRect(m_widget->geometry().x()+m_widget->geometry().width()+4,m_widget->geometry().y(),WIDTH/7,HEIGHT/3+20);
    screenModeMenu::instance()->set_widget_rect(&rect);
    screenModeMenu::instance()->change_screenModeMenu_show_statu();
}

void localVedioMenu::pushButton2_click_slot()
{
    qDebug()<<"取消本地录像";
    set_button_backGround(2);
}

void localVedioMenu::pushButton3_click_slot()
{
    qDebug()<<"打开抓拍文件目录";
    set_button_backGround(3);
}

void localVedioMenu::pushButton4_click_slot()
{
    qDebug()<<"打开本地录像文件目录";
    set_button_backGround(4);
}

bool localVedioMenu::set_button_backGround(int item)
{
    if(item != m_curr_item)
    {
        m_button_list[m_curr_item]->setStyleSheet("QPushButton{text-align : left;background-color:rgb(0, 0, 0);color: rgb(255, 255, 255);}");//之前的恢复为黑色背景
        m_button_list[item]->setStyleSheet("QPushButton{text-align : left;background-color:rgb(0, 0, 205);color: rgb(255, 255, 255);}");//当前的设置为蓝色背景
        m_curr_item = item;
    }
    return true;
}
