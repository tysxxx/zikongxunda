#include "localmonitormenu.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QDir>
#include "windowdefine.h"

LocalMonitorMenu::LocalMonitorMenu(QRect rect)
{
    qDebug() << "localMonitorMenu: " << rect.x() << rect.y() << rect.width() << rect.height();
    //setGeometry(rect);
    init();
}

LocalMonitorMenu::~LocalMonitorMenu()
{
    if(layoutSwitchMenu)
        layoutSwitchMenu->close();
    layoutSwitchMenu = nullptr;
}

//初始化
void LocalMonitorMenu::init()
{
    //窗口设置背景和形状
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);
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
        button->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white;"
                              " font: 21px; text-align:left; padding-left: 29px}");
    }
    grabBtn->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white;"
                           "font: 21px; text-align:left; padding-left: 29px}");

    //控件布局
    QVBoxLayout *btnLayout = new QVBoxLayout;
    btnLayout->setMargin(0);
    btnLayout->addSpacing(10);
    btnLayout->addWidget(grabBtn);
    btnLayout->addWidget(layoutSwitchBtn);
    btnLayout->addWidget(videoRecordBtn);
    btnLayout->addWidget(grabDirBtn);
    btnLayout->addWidget(videoRecordDirBtn);
    btnLayout->addSpacing(10);

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

//光标事件
void LocalMonitorMenu::focusInEvent(QFocusEvent *focusEvent)
{
    qDebug() << "focus in";
    QFrame::focusInEvent(focusEvent);
}

void LocalMonitorMenu::focusOutEvent(QFocusEvent *focusEvent)
{
    QFrame::focusInEvent(focusEvent);
    qDebug() << "focus out";
}

//按键处理
void LocalMonitorMenu::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setStyleSheet("QPushButton{height: 40px; background-color: transparent; color: white;"
                                                  " font: 21px; text-align:left; padding-left: 29px}");
    button->setStyleSheet("QPushButton{height: 40px; background-color: #649bf1; color: white; font: 21px; text-align:left;"
                          " padding-left: 29px}");
    lastBtnId = buttonGroup->id(button);

    //先关闭
    if(button != layoutSwitchBtn)
    {
        if(layoutSwitchMenu)
            layoutSwitchMenu->close();
        layoutSwitchMenu = nullptr;
    }

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

//抓拍按键处理
void LocalMonitorMenu::grapBtnClickedSlot()
{
    list<DEVICEINFO_S> dev_list;
    zkCarDevEngine::instance()->get_dev_list(&dev_list); //获取设备列表

    list<DEVICEINFO_S>::iterator it = dev_list.begin();
    for(;it != dev_list.end();++it)
    {
        zkCarDevEngine::instance()->zkTakePicture((*it).devType,(*it).devId);
    }
}

//布局按键处理
void LocalMonitorMenu::layoutSwitchBtnClickedSlot()
{
    qDebug() << "layoutSwitchBtnClickedSlot";
    if(layoutSwitchMenu)
        return;

    //设置窗口的位置
    QRect rect(geometry().x() + geometry().width() + 5,
               geometry().y(),
               217,
               308);

    layoutSwitchMenu = new LayoutSwitchMenu(rect);
    layoutSwitchMenu->setGeometry(rect);
    connect(layoutSwitchMenu, SIGNAL(layoutSwitchChanged(LayoutMode)), this, SIGNAL(layoutSwitchChanged(LayoutMode)));
    layoutSwitchMenu->show();
}

//本地录像处理
void LocalMonitorMenu::videoRecordBtnClickedSlot()
{

}

//打开抓拍文件目录
void LocalMonitorMenu::grabDirBtnClickedSlot()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("抓拍文件目录"), "/tys", tr("图片文件(*png *jpg *jpeg);;"));
    if(fileName.isEmpty())
        return;
    qDebug() << "file name: " << fileName;
    grabFileWin = new QDialog;
    grabFileWin->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setPixmap(QPixmap(fileName));

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(scrollArea);

    grabFileWin->setLayout(layout);
    grabFileWin->open();
}

//打开录像文件目录
void LocalMonitorMenu::videoRecordDirBtnClickedSlot()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("录像文件目录"),"/tys", tr("图片文件(*png *jpg *jpeg);;"));
}





















































