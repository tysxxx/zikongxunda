#include "screenModeMenu.h"

screenModeMenu* screenModeMenu::m_instance = NULL;
screenModeMenu::screenModeMenu()
{
    init();
}

screenModeMenu::~screenModeMenu()
{

}

void screenModeMenu::init()
{
    m_rect.setRect(438,90,217,308);
    m_widget = new QWidget();
    m_widget->setWindowFlags((Qt::FramelessWindowHint));//设置窗体无边框
    m_widget->setGeometry(m_rect);
    //m_widget->setStyleSheet("QWidget{background-color:gray;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");
    m_widget->setStyleSheet("QWidget{background-color:black;border-radius:10px;}");//四个角都设置为圆角，半径10px
    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
    m_widget->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.8);

    m_font_size = 23;
    m_curr_item = 0;//光标默认停留在第一个item处
    m_font.setPointSize(m_font_size);
    m_unit_cnt = 0;qDebug()<<"afag xa";
    set_lists();qDebug()<<"afag b";
    m_showStatu = false;

}

screenModeMenu* screenModeMenu::instance()
{
    if(m_instance == NULL)
    {
        m_instance = new screenModeMenu();
        qDebug()<<"new screenModeMenu success";
    }
    return m_instance;
}

bool screenModeMenu::show_screenModeMenu()
{
    m_widget->show();
    m_showStatu = true;
    return true;
}

bool screenModeMenu::hide_screenModeMenu()
{
    m_widget->hide();
    m_showStatu = false;
    return true;
}

bool screenModeMenu::change_screenModeMenu_show_statu()
{
    if(m_showStatu)
    {
        //m_widget->hide();
        //m_showStatu = false;
        hide_screenModeMenu();
    }else
        {
            //m_widget->show();
            //m_showStatu = true;
            show_screenModeMenu();
        }
    return true;
}

bool screenModeMenu::set_widget_rect(QRect* rect)
{
    if(rect == NULL)
        return false;
    m_rect = *rect;
    qDebug()<<"screenModeMenu"<<m_rect.x()<<" "<<m_rect.y()<<" "<<m_rect.width()<<" "<<m_rect.height();
    m_widget->setGeometry(m_rect);qDebug()<<"screenModeMenu"<<"setGeometry success";
    return true;
}

void screenModeMenu::set_lists()
{qDebug()<<"afag c";
    add_one_unit("image: url(:/statusLog/resource/icon/一分屏.png);","一分屏");
    QObject::connect(m_unit_list[0].p_button,SIGNAL(clicked()),this,SLOT(pushButton0_click_slot()));qDebug()<<"afag d";
    add_one_unit("image: url(:/statusLog/resource/icon/二分屏.png);","二分屏");
    QObject::connect(m_unit_list[1].p_button,SIGNAL(clicked()),this,SLOT(pushButton1_click_slot()));
    add_one_unit("image: url(:/statusLog/resource/icon/四分屏.png);","四分屏");
    QObject::connect(m_unit_list[2].p_button,SIGNAL(clicked()),this,SLOT(pushButton2_click_slot()));
    add_one_unit("image: url(:/statusLog/resource/icon/九分屏.png);","九分屏");
    QObject::connect(m_unit_list[3].p_button,SIGNAL(clicked()),this,SLOT(pushButton3_click_slot()));
    add_one_unit("image: url(:/statusLog/resource/icon/十六分屏.png);","十六分屏");
    QObject::connect(m_unit_list[4].p_button,SIGNAL(clicked()),this,SLOT(pushButton4_click_slot()));
qDebug()<<"afag e";
    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);
    m_verticalSpacer0 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);qDebug()<<"afag f";
    verticalLayout->addItem(m_verticalSpacer0);
    verticalLayout->addLayout(m_unit_list[0].horizontalLayout);
    m_verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer1);
    verticalLayout->addLayout(m_unit_list[1].horizontalLayout);
    m_verticalSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer2);
    verticalLayout->addLayout(m_unit_list[2].horizontalLayout);
    m_verticalSpacer3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer3);
    verticalLayout->addLayout(m_unit_list[3].horizontalLayout);
    m_verticalSpacer4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(m_verticalSpacer4);
    verticalLayout->addLayout(m_unit_list[4].horizontalLayout);
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

    m_gridLayout = new QGridLayout(m_widget);qDebug()<<"afag g";
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addLayout(verticalLayout,0,0);
    //m_unit_list[0].p_button->setStyleSheet("QPushButton{text-align : left;background-color:rgb(0, 0, 205);color: rgb(255, 255, 255);}");
}

bool screenModeMenu::add_one_unit(const char* iconPath,const char* name)
{
    QLabel* label = new QLabel(m_widget);
    QPushButton* button = new QPushButton(m_widget);
    QHBoxLayout* hboxLayout = new QHBoxLayout();
    SCREEN_MENU_UNIT_ST unit_st;
    if(iconPath != NULL)
        label->setStyleSheet(QString::fromUtf8(iconPath));
    if(name != NULL)
        button->setText(QObject::tr(name));
    else
        button->setText(QObject::tr("NULL"));
    button->setFont(m_font);
    //pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
    button->setStyleSheet("QPushButton{text-align : left;color: rgb(255, 255, 255);}");
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHeightForWidth(button->sizePolicy().hasHeightForWidth());
    button->setSizePolicy(sizePolicy);//设置允许其大小自适应窗口
    label->setSizePolicy(sizePolicy);

    QSpacerItem* verticalSpacer0 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    hboxLayout->addItem(verticalSpacer0);
    hboxLayout->addWidget(label);
    QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    hboxLayout->addItem(verticalSpacer1);
    hboxLayout->addWidget(button);
    hboxLayout->setStretch(0, 1);
    hboxLayout->setStretch(1, 4);
    hboxLayout->setStretch(2, 1);
    hboxLayout->setStretch(3, 8);
    hboxLayout->setContentsMargins(0, 0, 0, 0);
    unit_st.horizontalLayout = hboxLayout;
    unit_st.p_button = button;
    unit_st.p_lable = label;

    m_unit_list[m_unit_cnt] = unit_st;
    ++m_unit_cnt;
    return true;
}


void screenModeMenu::pushButton0_click_slot()
{
    qDebug()<<"一分屏";
    MainWidget::m_curScreen = ONESCREENSHOW;
    //MainWidget::m_stackedWidget_central_show->setCurrentIndex(ONESCREENSHOW);
    MainWidget::setScreenModel(1);
}

void screenModeMenu::pushButton1_click_slot()
{
    qDebug()<<"二分屏";
    MainWidget::m_curScreen = TWOSCREENSHOW;
    //MainWidget::m_stackedWidget_central_show->setCurrentIndex(TWOSCREENSHOW);
    MainWidget::setScreenModel(2);
}

void screenModeMenu::pushButton2_click_slot()
{
    qDebug()<<"四分屏";
    MainWidget::m_curScreen = FOURSCREENSHOW;
    //MainWidget::m_stackedWidget_central_show->setCurrentIndex(FOURSCREENSHOW);
    MainWidget::setScreenModel(4);
}

void screenModeMenu::pushButton3_click_slot()
{
    qDebug()<<"九分屏";
    MainWidget::m_curScreen = NINESCREENSHOW;
    //MainWidget::m_stackedWidget_central_show->setCurrentIndex(NINESCREENSHOW);
    MainWidget::setScreenModel(9);
}

void screenModeMenu::pushButton4_click_slot()
{
    qDebug()<<"十六分屏";
    MainWidget::m_curScreen = SIXTEENSCREENSHOW;
    //MainWidget::m_stackedWidget_central_show->setCurrentIndex(SIXTEENSCREENSHOW);
    MainWidget::setScreenModel(16);
}
