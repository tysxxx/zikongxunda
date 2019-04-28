#include "intercomui.h"
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QDebug>

IntercomUi::IntercomUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
    init();
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
    setStyleSheet("QWidget{background-color: transparent;}");

    //左侧窗口
        //@.按键
    userInteractBtn = new QPushButton(tr("互动对讲"));
    userInteractBtn->setProperty("valid", true);
    userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none;"
                                   "border-top-left-radius: 10px; border-bottom-left-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px; width: 137px; font:21px}"
                                   "QPushButton[valid=true]{background-color: #649bf1;}");

    groupInteractBtn = new QPushButton(tr("群组对讲"));
    groupInteractBtn->setProperty("valid", false);
    groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; "
                                   "border-top-right-radius: 10px; border-bottom-right-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px; width:137px; font:21px}"
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
        //@.布局
    QVBoxLayout *leftMainUiVBoxLayout = new QVBoxLayout;
    leftMainUiVBoxLayout->addSpacing(20);
    leftMainUiVBoxLayout->setSpacing(20);
    leftMainUiVBoxLayout->addLayout(interactHBoxLayout);
    leftMainUiVBoxLayout->addWidget(userInteractList);

    QFrame *leftFrame = new QFrame;
    leftFrame->setStyleSheet("QFrame{background-color: #040b17; padding-left: 70px;}");
    leftFrame->setLayout(leftMainUiVBoxLayout);

    //右侧窗口
    QFrame *rightFrame = new QFrame;
    rightFrame->setStyleSheet("QFrame{background-color: transparent}");

//    QRect rect;
////    QFrame *intercomShow = new QFrame(rightFrame);
////    intercomShow->setStyleSheet("QFrame{border-radius:10px; background-color: rgba(6, 32, 70, 80%); width: 397px; height: 544px}");
////    rect.setX(rightFrame->x()+rightFrame->width()-);
////    rect.setY(rightFrame->y());
////    rect.setWidth(rightFrame->width());

//    QFrame *topRect = new QFrame(rightFrame);
//    topRect->setStyleSheet("QFrame{background-color: #040b17;}");

//    rect.setX(rightFrame->x());
//    rect.setY(rightFrame->y());
//    rect.setWidth(rightFrame->width());
//    int height = (rightFrame->height() - 544)/2;
//    rect.setHeight(height);
//    topRect->setGeometry(rect);
//    qDebug() << "top rect" << rect;
//    QFrame *bottomRect = new QFrame(rightFrame);
//    QFrame *leftRect = new QFrame(rightFrame);
//    QFrame *rightRect = new QFrame(rightFrame);



    //QVBoxLayout *rightMainUiVBoxLayout = new QVBoxLayout;
    //rightMainUiVBoxLayout->addWidget(intercomShow);
    //rightMainUiVBoxLayout->addStretch();
    //rightFrame->setLayout(rightMainUiVBoxLayout);

    //总布局
    QHBoxLayout *mainUiHBoxLayout = new QHBoxLayout;
    mainUiHBoxLayout->setMargin(0);
    mainUiHBoxLayout->setSpacing(2);
    mainUiHBoxLayout->addWidget(leftFrame, 5); //均分
    mainUiHBoxLayout->addWidget(rightFrame, 5);

    setLayout(mainUiHBoxLayout);
}

//重载paintEvent事件
void IntercomUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

//按键处理
void IntercomUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);
    if(button == userInteractBtn){


    }else if(button == groupInteractBtn){

    }
}

