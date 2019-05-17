#include "intercomui.h"
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QDebug>

IntercomUi::IntercomUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    qDebug() << "IntercomUi: " << rect;
    resize(rect.width(), rect.height());
    //init();
}

IntercomUi::~IntercomUi()
{

}

//初始化
void IntercomUi::init()
{
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    //setStyleSheet(".QWidget{background-color: transparent;}");

    //左侧窗口
        //@.按键
    userInteractBtn = new QPushButton(tr("互动对讲"));
    userInteractBtn->setProperty("valid", true);
    userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none; \
                                                border-top-left-radius: 10px; border-bottom-left-radius: 10px; \
                                                background-color: transparent; color: white; height: 46px; width: 137px; font:21px}"
                                   "QPushButton[valid=true]{background-color: #649bf1;}");

    groupInteractBtn = new QPushButton(tr("群组对讲"));
    groupInteractBtn->setProperty("valid", false);
    groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; \
                                                 border-top-right-radius: 10px; border-bottom-right-radius: 10px; \
                                                 background-color: transparent; color: white; height: 46px; width:137px; font:21px}"
                                    "QPushButton[valid=true]{background-color: #649bf1;}");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(userInteractBtn);
    buttonGroup->addButton(groupInteractBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(userInteractBtn);

    QHBoxLayout *interactHBoxLayout = new QHBoxLayout;
    interactHBoxLayout->setMargin(0);
    interactHBoxLayout->setSpacing(0);
    interactHBoxLayout->addWidget(userInteractBtn);
    interactHBoxLayout->addWidget(groupInteractBtn);
    interactHBoxLayout->addStretch();

        //@.用户列表
    userInteractList = new QTreeWidget;
    userInteractList->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    userInteractList->insertTopLevelItems(0, items);

        //@.组织列表
    groupInteractList = new QListWidget;

    listStackedLayout = new QStackedLayout;
    listStackedLayout->addWidget(userInteractList);
    listStackedLayout->addWidget(groupInteractList);
    listStackedLayout->setCurrentWidget(userInteractList);
        //@.布局
    QVBoxLayout *leftMainUiVBoxLayout = new QVBoxLayout;
    leftMainUiVBoxLayout->addSpacing(20);
    leftMainUiVBoxLayout->setSpacing(20);
    leftMainUiVBoxLayout->addLayout(interactHBoxLayout);
    leftMainUiVBoxLayout->addLayout(listStackedLayout);

    QFrame *leftFrame = new QFrame;
    leftFrame->resize(width()/2, height());
    //leftFrame->setFixedSize(width()/2-4, height());
    leftFrame->setStyleSheet("QFrame{background-color: #040b17; padding-left: 70px;}");
    leftFrame->setLayout(leftMainUiVBoxLayout);

    //右侧窗口
    QFrame *rightFrame = new QFrame;
    rightFrame->resize(width()/2, height());
    //rightFrame->setFixedSize(width()/2, height());
    rightFrame->setStyleSheet("QFrame{background-color: transparent}");

    qDebug() << "rightFrame: " << rightFrame->size();
    QRect rect;
        //@.上端小矩形框
    QFrame *topRect = new QFrame(rightFrame);
    topRect->setStyleSheet("QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 0,
                 rightFrame->width(),
                 (rightFrame->height() - 544)/2
                 );
    topRect->setGeometry(rect);

        //@.底部小矩形框
    QFrame *bottomRect = new QFrame(rightFrame);
    bottomRect->setStyleSheet("QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 topRect->height()+544,
                 rightFrame->width(),
                 (rightFrame->height() - 544)/2
                 );
    bottomRect->setGeometry(rect);

        //@.左小矩形框
    QFrame *leftRect = new QFrame(rightFrame);
    leftRect->setStyleSheet("QFrame{background-color: #040b17;}");
    rect = QRect(0,
                 topRect->height(),
                 (rightFrame->width()-397)/2,
                 rightFrame->height()-topRect->height() - bottomRect->height()
                 );
    leftRect->setGeometry(rect);

        //@.右小矩形框
    QFrame *rightRect = new QFrame(rightFrame);
    rightRect->setStyleSheet("QFrame{background-color: #040b17;}");
    rect = QRect(leftRect->width()+397,
                 topRect->height(),
                 (rightFrame->width()-397)/2,
                 rightFrame->height()-topRect->height() - bottomRect->height()
                 );
    rightRect->setGeometry(rect);

        //@.中间小矩形框
            //@.用户显示
    userIntercomShow = new QFrame(rightFrame);
    userIntercomShow->setStyleSheet("QFrame{background-color: rgba(6, 32, 70, 80%);}");
    rect = QRect(leftRect->width(),
                 topRect->height(),
                 397,
                 544
                 );
    userIntercomShow->setGeometry(rect);

    QLabel *userIcon = new QLabel;
    userIcon->setAlignment(Qt::AlignCenter);
    userIcon->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon1 = new QLabel;
    userIcon1->setAlignment(Qt::AlignCenter);
    userIcon1->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon1->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon2 = new QLabel;
    userIcon2->setAlignment(Qt::AlignCenter);
    userIcon2->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon2->setStyleSheet("QLabel{background-color: transparent;}");

    QLabel *userIcon3 = new QLabel;
    userIcon3->setAlignment(Qt::AlignCenter);
    userIcon3->setPixmap(QPixmap(":/statusLog/resource/icon/头像.png"));
    userIcon3->setStyleSheet("QLabel{background-color: transparent;}");


    QLabel *userName = new QLabel;
    userName->setAlignment(Qt::AlignCenter);
    userName->setText("admin1");
    userName->setStyleSheet("QLabel{background-color: transparent; color: white; font:21px;}");

    QVBoxLayout *userInfoVBoxLayout = new QVBoxLayout;
    userInfoVBoxLayout->setMargin(0);
    userInfoVBoxLayout->addSpacing(5);
    userInfoVBoxLayout->addWidget(userIcon);
    userInfoVBoxLayout->addWidget(userName);
    userInfoVBoxLayout->addSpacing(50);

    userFlowLayout = new QFlowLayout;
    userFlowLayout->setContentsMargins(30, 0, 0, 0);
    userFlowLayout->setAlignment(Qt::AlignCenter);
    userFlowLayout->addWidget(userIcon);
    //userFlowLayout->addChildLayout(userInfoVBoxLayout);
//    userFlowLayout->addWidget(userIcon1);
//    userFlowLayout->addWidget(userIcon2);
//    userFlowLayout->addWidget(userIcon3);

    intercomStatusLabel = new QLabel(tr("通话中"));
    intercomStatusLabel->setAlignment(Qt::AlignCenter);
    intercomStatusLabel->setStyleSheet("QLabel{font:21px; background-color:transparent; color:#0dee44;}");

    intercomExitBtn = new QPushButton(tr("退出"));
    intercomExitBtn->setFixedSize(150, 50);
    intercomExitBtn->setStyleSheet("QPushButton{font: 24px; background-color:#649bf1;}");

    QHBoxLayout *intercomExitBtnHBoxLayout = new QHBoxLayout;
    intercomExitBtnHBoxLayout->addWidget(intercomExitBtn, Qt::AlignCenter);

    QVBoxLayout *userIntercomVBoxLayout = new QVBoxLayout;
    userIntercomVBoxLayout->setMargin(0);
    userIntercomVBoxLayout->setSpacing(20);
    userIntercomVBoxLayout->addSpacing(20);
    //userIntercomVBoxLayout->addLayout(userInfoVBoxLayout);
    userIntercomVBoxLayout->addLayout(userFlowLayout);
    userIntercomVBoxLayout->addWidget(intercomStatusLabel);
    userIntercomVBoxLayout->addLayout(intercomExitBtnHBoxLayout);
    userIntercomVBoxLayout->addSpacing(30);

    userIntercomShow->setLayout(userIntercomVBoxLayout);

            //@.组织显示
    groupIntercomShow = new QFrame(rightFrame);
    groupIntercomShow->setStyleSheet("QFrame{background-color: rgba(6, 32, 70, 80%);}");
    groupIntercomShow->setGeometry(rect);

            //@.
    intercomShowStackedLayout = new QStackedLayout;
    intercomShowStackedLayout->addWidget(userIntercomShow);
    intercomShowStackedLayout->addWidget(groupIntercomShow);
    intercomShowStackedLayout->setCurrentWidget(userIntercomShow);

    //总布局
    QHBoxLayout *mainUiHBoxLayout = new QHBoxLayout;
    mainUiHBoxLayout->setMargin(0);
    mainUiHBoxLayout->setSpacing(2);
    mainUiHBoxLayout->addWidget(leftFrame, 1); //均分
    mainUiHBoxLayout->addWidget(rightFrame, 1);

    setLayout(mainUiHBoxLayout);
}

//重载paintEvent事件
//void IntercomUi::paintEvent(QPaintEvent *)
//{
//    QStyleOption opt;
//    opt.init(this);
//    QPainter painter(this);
//    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
//}

//按键处理
void IntercomUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);
    if(button == userInteractBtn){
        listStackedLayout->setCurrentWidget(userInteractList);
        intercomShowStackedLayout->setCurrentWidget(userIntercomShow);
    }else if(button == groupInteractBtn){
        listStackedLayout->setCurrentWidget(groupInteractList);
        intercomShowStackedLayout->setCurrentWidget(groupIntercomShow);
    }
}

