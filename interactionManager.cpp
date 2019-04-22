#include "interactionManager.h"


interactionUserUnit::interactionUserUnit(const char* name)
{
    this->setStyleSheet(QString::fromUtf8("background-color: rgb(4, 11, 23);"));
    m_font_size = 24;
    m_font.setPointSize(m_font_size);
    if(name != NULL)
        m_label.setText(QObject::tr(name));
    else
        m_label.setText(QObject::tr("NULL"));
    m_label.setStyleSheet("QLabel{text-align : left;color: rgb(255, 255, 255);}");
    m_label.setFont(m_font);
    m_audioButton.setText(QObject::tr("对讲"));
    m_audioButton.setFont(m_font);
    //m_audioButton.setStyleSheet("QPushButton{text-align:left;color:rgb(255, 255, 255);}");
    m_audioButton.setStyleSheet("QPushButton{background-color:black;color: white;\
                                                                    border-radius:10px;border:2px white;\
                                                                    border-style: outset;}"
                                                                   "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                 );
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHeightForWidth(m_audioButton.sizePolicy().hasHeightForWidth());
    m_audioButton.setSizePolicy(sizePolicy);//设置允许其大小自适应窗口
    m_vedioButton.setText(QObject::tr("视频"));
    m_vedioButton.setFont(m_font);
    //m_vedioButton.setStyleSheet("QPushButton{text-align:left;color:rgb(255, 255, 255);}");
    m_vedioButton.setStyleSheet("QPushButton{background-color:black;color: white;\
                                                                    border-radius:10px;border:2px white;\
                                                                    border-style: outset;}"
                                                                   "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                 );
    sizePolicy.setHeightForWidth(m_vedioButton.sizePolicy().hasHeightForWidth());
    m_vedioButton.setSizePolicy(sizePolicy);
    m_label.setSizePolicy(sizePolicy);

    m_hboxLayout.addWidget(&m_label);
    m_spacerItem0 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_hboxLayout.addItem(m_spacerItem0);
    m_hboxLayout.addWidget(&m_audioButton);
    m_spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_hboxLayout.addItem(m_spacerItem1);
    m_hboxLayout.addWidget(&m_vedioButton);
    m_spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_hboxLayout.addItem(m_spacerItem2);
    m_hboxLayout.setStretch(0, 2);
    m_hboxLayout.setStretch(1, 1);
    m_hboxLayout.setStretch(2, 2);
    m_hboxLayout.setStretch(3, 1);
    m_hboxLayout.setStretch(4, 2);
    m_hboxLayout.setStretch(5, 2);
    m_hboxLayout.setContentsMargins(0, 0, 0, 0);
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(15, 0, 0, 15);
    m_gridLayout->addLayout(&m_hboxLayout,0,0);
}

interactionManager::interactionManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interactionManager)
{
    ui->setupUi(this);
    ui->widget_right->setStyleSheet(QString::fromUtf8("background-color: rgba(6, 32, 70, 204);border-radius:10px;"));
    ui->pushButton_over_speak->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,255,204);color: rgba(255,255,255,204);border-radius:10px;"));;
    ui->pushButton_interaction_speak->setStyleSheet("QPushButton{background-color:black;color: white;\
                                                                border-top-left-radius:10px;border-bottom-left-radius:10px;\
                                                                border-top-width:2px white;border-left-width:2px white;border-bottom-width:2px white;\
                                                                border-style: outset;}"
                                                               "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                               );
    ui->pushButton_group_speak->setStyleSheet("QPushButton{background-color:black;color: white;\
                                               border-top-right-radius:10px;border-bottom-right-radius:10px;\
                                               border-top-width:2px white;border-right-width:2px white;border-bottom-width:2px white;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(0, 0, 255);}"
                                              );

    m_stackedWidget_left_userList = new QStackedWidget(ui->widget);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_stackedWidget_left_userList->sizePolicy().hasHeightForWidth());
    m_stackedWidget_left_userList->setSizePolicy(sizePolicy);
    m_gridLayout = new QGridLayout(ui->widget);
    m_gridLayout->setSpacing(0);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->addWidget(m_stackedWidget_left_userList,0,0);

    m_interaction_list = new QListWidget;
    m_interaction_list->setWindowFlags((Qt::FramelessWindowHint));//设置窗体无边框
    m_group_list = new QListWidget;
    m_group_list->setWindowFlags((Qt::FramelessWindowHint));
    m_stackedWidget_left_userList->addWidget(m_interaction_list);
    m_stackedWidget_left_userList->addWidget(m_group_list);
    m_stackedWidget_left_userList->setCurrentIndex(0);
    add_one_interaction_user("admin0");
    add_one_interaction_user("admin1");
    add_one_interaction_user("admin2");
    add_one_interaction_user("admin3");
}

bool interactionManager::add_one_interaction_user(const char* userName)
{
    interactionUserUnit* p_interactionUserUnit;
    if(userName != NULL)
        p_interactionUserUnit = new interactionUserUnit(userName);
    else
        p_interactionUserUnit = new interactionUserUnit("NULL");
    QListWidgetItem *widgetItem = new QListWidgetItem(m_interaction_list);
    widgetItem->setBackground(QColor(0,0,0,255));
    widgetItem->setTextColor(QColor(255,255,255,255));//设置字体颜色
    widgetItem->setTextAlignment(Qt::AlignLeft);
    widgetItem->setSizeHint(QSize(400,60));//设置每行item的间距
    m_interaction_list->setItemWidget(widgetItem,p_interactionUserUnit);
}


void interactionManager::delete_one_interaction_user()
{
    if(0 == m_interaction_list->count())    //获取items数量，当QListWidget中没有item时返回
        return;
    QListWidgetItem* itemlist = m_interaction_list->currentItem();
    QString str = itemlist->text();     //获取当前选中item字符串
    int i=0;
    QListWidgetItem* itemlist1 = m_interaction_list->item(i);
    QString str1 = itemlist1->text();   //获取索引为0的item字符串
    while(str1 != "")       //删除选中的item
    {
        itemlist1 = m_interaction_list->item(i);
        str1= itemlist1->text();
        if(str == str1)
        {
            m_interaction_list->removeItemWidget(itemlist1);
            delete itemlist1;
            return;
        }
        ++i;
    }
}


void interactionManager::clearInteractionListWidget()
{
    m_interaction_list->clear();    //清空items
}
