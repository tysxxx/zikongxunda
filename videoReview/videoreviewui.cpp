#include "videoreviewui.h"
#include <QStyleOption>
#include <QPainter>
#include <QDate>

VideoReviewUi::VideoReviewUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
    init();
}

VideoReviewUi::~VideoReviewUi()
{

}


//初始化
void VideoReviewUi::init()
{
    //界面设置
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QWidget{background-color: transparent;}");

    //上端
        //@.按键
    videoInfoBtn = new QPushButton(tr("录像下载"));
    videoInfoBtn->setProperty("valid", true);
    videoInfoBtn->setStyleSheet("QPushButton{border: 2px solid white; border-right:none;"
                                   "border-top-left-radius: 10px; border-bottom-left-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px; width: 137px; font:21px}"
                                   "QPushButton[valid=true]{background-color: #649bf1;}");

    videoPlayBtn = new QPushButton(tr("实时回放"));
    videoPlayBtn->setProperty("valid", false);
    videoPlayBtn->setStyleSheet("QPushButton{border: 2px solid white; border-left:none; "
                                   "border-top-right-radius: 10px; border-bottom-right-radius: 10px;"
                                   "background-color: transparent; color: white; height: 46px; width:137px; font:21px}"
                                   "QPushButton[valid=true]{background-color: #649bf1;}");

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(videoInfoBtn);
    buttonGroup->addButton(videoPlayBtn);
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(btnClickedSlot(QAbstractButton*)));
    lastBtnId = buttonGroup->id(videoInfoBtn);

    QHBoxLayout *btnChooseHBoxLayout = new QHBoxLayout;
    btnChooseHBoxLayout->setMargin(0);
    btnChooseHBoxLayout->setSpacing(0);
    btnChooseHBoxLayout->addWidget(videoInfoBtn);
    btnChooseHBoxLayout->addWidget(videoPlayBtn);
    btnChooseHBoxLayout->addStretch();

        //@.通道
    channelLabel = new QLabel(tr("通道"));
    channelLabel->setStyleSheet("QLabel{font:21px; color: white; padding-left: 0px}");
    videoChannel = new QComboBox;
    videoChannel->setFixedSize(213, 40);
    videoChannel->setStyleSheet("QComboBox{background-color: transparent; border: 2px solid white; border-radius: 10px;}");
    QHBoxLayout *videoChannelHBoxLayout = new QHBoxLayout;
    videoChannelHBoxLayout->setMargin(0);
    videoChannelHBoxLayout->setSpacing(30);
    videoChannelHBoxLayout->addWidget(channelLabel);
    videoChannelHBoxLayout->addWidget(videoChannel);
    videoChannelHBoxLayout->addStretch();

        //@.日期
    QLabel *dateLabel = new QLabel(tr("日期"));
    dateLabel->setStyleSheet("font:21px; color: white;");
    videoDate = new QLabel(QDate::currentDate().toString("yyyy-MM-dd"));
    videoDate->setAlignment(Qt::AlignCenter);
    videoDate->setFixedSize(180, 40);
    videoDate->setStyleSheet("font: 21px;color: white;border: 2px solid white;border-radius: 10px; background-color: transparent;");
    dateBtn = new QPushButton;
    dateBtn->adjustSize();
    dateBtn->setStyleSheet(tr("background-image: url(%1); background-origin: content; background-position: center;").arg(":/recordImg/resource/recordImg/日历（选中）.png"));

    QHBoxLayout *dateHBoxLayout = new QHBoxLayout;
    dateHBoxLayout->setMargin(0);
    dateHBoxLayout->addWidget(dateLabel);
    dateHBoxLayout->addSpacing(30);
    dateHBoxLayout->addWidget(videoDate);
    dateHBoxLayout->addSpacing(15);
    dateHBoxLayout->addWidget(dateBtn);
    dateHBoxLayout->addStretch();

        //@.查询
    queryBtn = new QPushButton(tr("查询"));
    queryBtn->setFixedSize(105, 42);
    queryBtn->setStyleSheet("font: 21px; color: white; border: 2px solid white;border-radius:\
                            10px;background-color: transparent;");

    QHBoxLayout *topHBoxLayout = new QHBoxLayout;
    topHBoxLayout->setMargin(0);
    topHBoxLayout->addLayout(videoChannelHBoxLayout);
    topHBoxLayout->addSpacing(80);
    topHBoxLayout->addLayout(dateHBoxLayout);
    topHBoxLayout->addSpacing(120);
    topHBoxLayout->addWidget(queryBtn);
    topHBoxLayout->addStretch();

    QVBoxLayout *topVBoxLayout = new QVBoxLayout;
    topVBoxLayout->addSpacing(20);
    topVBoxLayout->setSpacing(30);
    topVBoxLayout->addLayout(btnChooseHBoxLayout);
    topVBoxLayout->addLayout(topHBoxLayout);
    topVBoxLayout->addSpacing(20);

     QFrame *topFrame = new QFrame;
     topFrame->setStyleSheet("QFrame{background-color: #040b17; padding-left: 70px;}");
     topFrame->setLayout(topVBoxLayout);

    //
    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->setMargin(0);
    mainVBoxLayout->addWidget(topFrame);
    mainVBoxLayout->addStretch();
    setLayout(mainVBoxLayout);
}

//重载paintEvent事件
void VideoReviewUi::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//按键处理
void VideoReviewUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);
    if(button == videoInfoBtn){

    }else if(button == videoPlayBtn){

    }
}

