#include "intercomui.h"
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>

IntercomUi::IntercomUi(QWidget *parent) : QWidget(parent)
{
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
    setStyleSheet("QWidget{background-color: #040b17;}");

    //按键
    userInteractBtn = new QPushButton(tr("互动对讲"));
    userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none; "
                                   "border-top-left-radius: 10px; border-bottom-left-radius: 10px;"
                                   "background-color: #649bf1; color: white; height: 46px}");
    groupInteractBtn = new QPushButton(tr("群组对讲"));
    groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; "
                                   "border-top-right-radius: 10px; border-bottom-right-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px}");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(userInteractBtn);
    buttonGroup->addButton(groupInteractBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(userInteractBtn);

    QHBoxLayout *interactHBoxLayout = new QHBoxLayout;
    interactHBoxLayout->setMargin(0);
    interactHBoxLayout->addSpacing(70);
    interactHBoxLayout->setSpacing(0);
    interactHBoxLayout->addWidget(userInteractBtn);
    interactHBoxLayout->addWidget(groupInteractBtn);

    QVBoxLayout *leftMainUiVBoxLayout = new QVBoxLayout;
    leftMainUiVBoxLayout->setMargin(20);
    leftMainUiVBoxLayout->addLayout(interactHBoxLayout);

    QHBoxLayout *mainUiHBoxLayout = new QHBoxLayout;
    mainUiHBoxLayout->addLayout(leftMainUiVBoxLayout);

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
    lastBtnId = buttonGroup->id(button);
    if(button == userInteractBtn){
        groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; "
                                   "border-top-right-radius: 10px; border-bottom-right-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px}");

        userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none; "
                                   "border-top-left-radius: 10px; border-bottom-left-radius: 10px;"
                                   "background-color: #649bf1; color: white; height: 46px}");
    }else if(button == groupInteractBtn){
        groupInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; "
                                   "border-top-right-radius: 10px; border-bottom-right-radius: 10px;"
                                   "background-color: #649bf1; color: white; height: 46px}");

        userInteractBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none; "
                                   "border-top-left-radius: 10px; border-bottom-left-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px}");
    }
}

