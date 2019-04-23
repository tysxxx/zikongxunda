#include "localmonitormenu.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

LocalMonitorMenu::LocalMonitorMenu(QRect rect)
{
    qDebug() << rect.x() << rect.y() << rect.width() << rect.height();
    //setGeometry(rect);
    init();
}

//初始化
void LocalMonitorMenu::init()
{
    //窗口设置背景和形状
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QFrame{border-radius:10px; background:rgba(4, 11, 23, 80%);}"); //必须使用%

    //按键
    grabBtn = new QPushButton(tr("本地抓拍"));
    layoutSwitchBtn = new QPushButton(tr("布局切换"));
    videoRecordBtn = new QPushButton(tr("取消本地录像"));
    grabDirBtn = new QPushButton(tr("打开抓拍文件目录"));
    videoRecordDirBtn = new QPushButton(tr("打开本地录像文件目录"));

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(grabBtn);
    buttonGroup->addButton(layoutSwitchBtn);
    buttonGroup->addButton(videoRecordBtn);
    buttonGroup->addButton(grabDirBtn);
    buttonGroup->addButton(videoRecordDirBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(grabBtn);
    for(auto button: buttonGroup->buttons()){
        button->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white; font: 21px; text-align:left}");
    }
    grabBtn->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white; font: 21px; text-align:left}");

    //控件布局
    QVBoxLayout *btnLayout = new QVBoxLayout;
    btnLayout->setMargin(0);
    btnLayout->addWidget(grabBtn);
    btnLayout->addWidget(layoutSwitchBtn);
    btnLayout->addWidget(videoRecordBtn);
    btnLayout->addWidget(grabDirBtn);
    btnLayout->addWidget(videoRecordDirBtn);

    setLayout(btnLayout);
}

//重载paintEvent事件
void LocalMonitorMenu::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }

//抓拍按键处理
void LocalMonitorMenu::grapBtnClickedSlot()
{
    qDebug() << "grapBtnClickedSlot";
}

//布局按键处理
void LocalMonitorMenu::layoutSwitchBtnClickedSlot()
{
    qDebug() << "layoutSwitchBtnClickedSlot";
}

//本地录像处理
void LocalMonitorMenu::videoRecordBtnClickedSlot()
{
    qDebug() << "videoRecordBtnClickedSlot";
}

//打开抓拍文件目录
void LocalMonitorMenu::grabDirBtnClickedSlot()
{
    qDebug() << "grabDirBtnClickedSlot";
}

//打开录像文件目录
void LocalMonitorMenu::videoRecordDirBtnClickedSlot()
{
    qDebug() << "videoRecordDirBtnClickedSlot";
}

//
void LocalMonitorMenu::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white; font: 21px; text-align:left}");
    button->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white; font: 21px; text-align:left}");
    lastBtnId = buttonGroup->id(button);
    if(lastBtnId == buttonGroup->id(grabBtn)){
         grapBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(layoutSwitchBtn)){
        layoutSwitchBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(videoRecordBtn)){
        videoRecordBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(grabDirBtn)){
        grabDirBtnClickedSlot();
    }else if(lastBtnId == buttonGroup->id(videoRecordDirBtn)){
        videoRecordDirBtnClickedSlot();
    }
}



















































