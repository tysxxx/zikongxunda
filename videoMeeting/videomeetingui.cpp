#include "videomeetingui.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>

VideoMeetingUi::VideoMeetingUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
    init();
}

VideoMeetingUi::~VideoMeetingUi()
{

}

//初始化
void VideoMeetingUi::init()
{
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QWidget{background-color: #040b17;}");

    //中间会议列表显示框
    QFrame *meetingListFrame = new QFrame(this);
    meetingListFrame->setStyleSheet("QWidget{background-color: rgba(6, 32, 70, 80%); border-radius:10px;}");
    QRect rect;
    rect = QRect((width()-469)/2,
                200,
                469,
                449);
    meetingListFrame->setGeometry(rect);

    QLabel *meetingListName = new QLabel(tr("视频会议列表"));
    meetingListName->setAlignment(Qt::AlignCenter);
    meetingListName->setStyleSheet("QLabel{font: 24px; color: #649bf1; background-color: transparent}");

    meetingList = new QListWidget;
    meetingList->setStyleSheet("QListWidget{background-color: transparent}");

    QVBoxLayout *meetingListVBoxLayout = new QVBoxLayout;
    meetingListVBoxLayout->setContentsMargins(0, 30, 0, 10);
    meetingListVBoxLayout->addWidget(meetingListName);
    meetingListVBoxLayout->addWidget(meetingList);

    meetingListFrame->setLayout(meetingListVBoxLayout);
}

//重载paintEvent事件
void VideoMeetingUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

