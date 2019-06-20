#include "videomeetingui.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QStringListModel>
#include <QScrollBar>
#include <QScrollArea>

VideoMeetingUi::VideoMeetingUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
}

VideoMeetingUi::~VideoMeetingUi()
{

}

//初始化
void VideoMeetingUi::init()
{
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    //setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QWidget{background: #040b17;}");

    //中间会议列表显示框
    QFrame *meetingListFrame = new QFrame(this);
    meetingListFrame->setStyleSheet(".QFrame{background-color: rgba(6, 32, 70, 80%); border-radius:10px;}");
    QRect rect;
    rect = QRect((width()-469)/2,
                200,
                469,
                449);

    qDebug() << "meeting rect:" << rect;
    meetingListFrame->setGeometry(rect);

    QLabel *meetingListNameLabel = new QLabel(tr("视频会议列表"));
    meetingListNameLabel->setAlignment(Qt::AlignCenter);
    meetingListNameLabel->setStyleSheet("QLabel{font: 24px; color: #649bf1; background-color: transparent}");

    meetingListWidget = new QListWidget;
    meetingListWidget->setStyleSheet(".QListWidget{background-color: transparent; border: none; color: white; font: 21px;}\
                                      .QListWidget::item{margin: 10px;}\
                                      ");
    //meetingListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem); //默认项滚动
    meetingListWidget->verticalScrollBar()->setStyleSheet(".QScrollBar{background-color: rgba(6, 32, 70, 80%); width:10px; border:none; border-radius:5px;}\
                                        .QScrollBar::handle{background: gray; border:2px solid gray; border-radius:5px;}\
                                        .QScrollBar::sub-line{background:transparent; width: 0px; height: 0px;}\
                                        .QScrollBar::add-line{background:transparent; width: 0px; height: 0px;}");

    connect(meetingListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClickedSlot(QListWidgetItem*)));


    QList<ListWidgetItem *> list;
    for(qint32 i=0; i < 20; i++){
        ListWidgetItem *item = new ListWidgetItem(meetingListWidget);
        item->setText(tr("会议%1").arg(i));
        //ListWidgetItem::ItemInfoType itemInfo = item->itemInfo();
        item->itemInfo().id = i;
        list.append(item);
    }


    QVBoxLayout *meetingListVBoxLayout = new QVBoxLayout;
    meetingListVBoxLayout->setContentsMargins(0, 30, 0, 10);
    meetingListVBoxLayout->setSpacing(10);
    meetingListVBoxLayout->addWidget(meetingListNameLabel);
    meetingListVBoxLayout->addWidget(meetingListWidget);

    meetingListFrame->setLayout(meetingListVBoxLayout);

    //
    manager = Manager::instance();
    connect(manager.data(), SIGNAL(loadMeetingList(meetingListType&)),
            this, SLOT(loadMeetingList(meetingListType&)));
}

//重载paintEvent事件
void VideoMeetingUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

//加载视频列表
void VideoMeetingUi::loadMeetingList(meetingListType &meeting)
{
    //清空
    meetingListWidget->clear();

    //加载
    for(qint32 i=0; i < meeting.total; i++){
        ListWidgetItem *item = new ListWidgetItem(meetingListWidget);
        item->setText(meeting.items.at(i).name);
        item->itemInfo().id = meeting.items.at(i).id;
        item->itemInfo().categoryId = meeting.items.at(i).group_category_id;
        item->itemInfo().groupId = meeting.items.at(i).group_id;
        item->itemInfo().name = meeting.items.at(i).name;
    }
}

//项选择处理(选择具体的视频会议)
void VideoMeetingUi::itemClickedSlot(QListWidgetItem *item)
{
    ListWidgetItem *myItem = dynamic_cast<ListWidgetItem*>(item);
    qDebug() << "item clicked" << myItem->text() << myItem->itemInfo().id << myItem->itemInfo().groupId;

    NetworkManager::instance()->getMeetingMemberRequest(myItem->itemInfo().id);
}
