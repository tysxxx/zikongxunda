#include "layoutswitchmenu.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QIcon>
#include <QImage>
#include "mainwidget.h"

LayoutSwitchMenu::LayoutSwitchMenu(QRect rect)
{
    setGeometry(rect);
    init();
}

//初始化
void LayoutSwitchMenu::init()
{
    //窗口设置背景和形状
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QFrame{border-radius:10px; background:rgba(4, 11, 23, 80%);}"); //必须使用%,只对QFrame起作用
    //setStyleSheet("border-radius:10px; background:rgba(4, 11, 23, 80%);"); //包括子控件都起作用

    //标题
    titleLabel = new QLabel(tr("布局切换"));
    titleLabel->setStyleSheet("color: #649bf1; background-color: transparent; font-size: 16px; text-align:left; padding-left: 29px");

    //按键
    oneBtn = new QPushButton(tr("一分屏"));
    QLabel *oneBtnLabel = new QLabel;
    oneBtnLabel->setStyleSheet("background-color: transparent");
    oneBtnLabel->setPixmap(QPixmap(":/statusLog/resource/icon/一分屏.png"));
    QHBoxLayout  *oneBtnHBoxLayout = new QHBoxLayout;
    oneBtnHBoxLayout->setContentsMargins(29, 0, 0, 0);
    oneBtnHBoxLayout->addWidget(oneBtnLabel);
    oneBtn->setLayout(oneBtnHBoxLayout);

    twoBtn = new QPushButton(tr("二分屏"));
    QLabel *twoBtnLabel = new QLabel;
    twoBtnLabel->setStyleSheet("background-color: transparent");
    twoBtnLabel->setPixmap(QPixmap(":/statusLog/resource/icon/二分屏.png"));
    QHBoxLayout  *twoBtnHBoxLayout = new QHBoxLayout;
    twoBtnHBoxLayout->setContentsMargins(29, 0, 0, 0);
    twoBtnHBoxLayout->addWidget(twoBtnLabel);
    twoBtn->setLayout(twoBtnHBoxLayout);

    fourBtn = new QPushButton(tr("四分屏"));
    QLabel *fourBtnLabel = new QLabel;
    fourBtnLabel->setStyleSheet("background-color: transparent");
    fourBtnLabel->setPixmap(QPixmap(":/statusLog/resource/icon/四分屏.png"));
    QHBoxLayout  *fourBtnHBoxLayout = new QHBoxLayout;
    fourBtnHBoxLayout->setContentsMargins(29, 0, 0, 0);
    fourBtnHBoxLayout->addWidget(fourBtnLabel);
    fourBtn->setLayout(fourBtnHBoxLayout);

    nineBtn = new QPushButton(tr("九分屏"));
    QLabel *nineBtnLabel = new QLabel;
    nineBtnLabel->setStyleSheet("background-color: transparent");
    nineBtnLabel->setPixmap(QPixmap(":/statusLog/resource/icon/九分屏.png"));
    QHBoxLayout  *nineBtnHBoxLayout = new QHBoxLayout;
    nineBtnHBoxLayout->setContentsMargins(29, 0, 0, 0);
    nineBtnHBoxLayout->addWidget(nineBtnLabel);
    nineBtn->setLayout(nineBtnHBoxLayout);

    sixteenBtn = new QPushButton(tr("十六分屏"));
    QLabel *sixteenBtnLabel = new QLabel;
    sixteenBtnLabel->setStyleSheet("background-color: transparent");
    sixteenBtnLabel->setPixmap(QPixmap(":/statusLog/resource/icon/十六分屏.png"));
    QHBoxLayout  *sixteenBtnHBoxLayout = new QHBoxLayout;
    sixteenBtnHBoxLayout->setContentsMargins(29, 0, 0, 0);
    sixteenBtnHBoxLayout->addWidget(sixteenBtnLabel);
    sixteenBtn->setLayout(sixteenBtnHBoxLayout);

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(oneBtn);
    buttonGroup->addButton(twoBtn);
    buttonGroup->addButton(fourBtn);
    buttonGroup->addButton(nineBtn);
    buttonGroup->addButton(sixteenBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(oneBtn);
    for(auto button: buttonGroup->buttons()){
        button->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white; "
                              "font: 21px; text-align:left; padding-left: 69px}");
    }
    oneBtn->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white; "
                          "font: 21px; text-align:left; padding-left: 69px}");
    //控件布局
    QVBoxLayout *btnLayout = new QVBoxLayout;
    btnLayout->setMargin(0);
    btnLayout->addSpacing(10);
    btnLayout->addWidget(titleLabel);
    btnLayout->addWidget(oneBtn);
    btnLayout->addWidget(twoBtn);
    btnLayout->addWidget(fourBtn);
    btnLayout->addWidget(nineBtn);
    btnLayout->addWidget(sixteenBtn);
    btnLayout->addStretch(10);

    setLayout(btnLayout);
}

//重载paintEvent事件
void LayoutSwitchMenu::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//按键处理
void LayoutSwitchMenu::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white;"
                                                  " font: 21px; text-align:left; padding-left: 69px}");
    button->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white;"
                          "font: 21px; text-align:left; padding-left: 69px}");
    lastBtnId = buttonGroup->id(button);
    if(lastBtnId == buttonGroup->id(oneBtn)){
         oneBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(twoBtn)){
        twoBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(fourBtn)){
        fourBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(nineBtn)){
        nineBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(sixteenBtn)){
        sixteenBtnClickedSlot();
    }
}

//一分屏按键处理
void LayoutSwitchMenu::oneBtnClickedSlot()
{
    MainWidget::m_curScreen = ONESCREENSHOW;
    MainWidget::setScreenModel(1);
}

//二分屏按键处理
void LayoutSwitchMenu::twoBtnClickedSlot()
{
    MainWidget::m_curScreen = TWOSCREENSHOW;
    MainWidget::setScreenModel(2);
}

//四分屏按键处理
void LayoutSwitchMenu::fourBtnClickedSlot()
{
    MainWidget::m_curScreen = FOURSCREENSHOW;
    MainWidget::setScreenModel(4);
}

//九分屏按键处理
void LayoutSwitchMenu::nineBtnClickedSlot()
{
    MainWidget::m_curScreen = NINESCREENSHOW;
    MainWidget::setScreenModel(9);
}

//十六分屏按键处理
void LayoutSwitchMenu::sixteenBtnClickedSlot()
{
    MainWidget::m_curScreen = SIXTEENSCREENSHOW;
    MainWidget::setScreenModel(16);
}






























