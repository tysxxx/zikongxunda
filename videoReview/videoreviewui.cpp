#include "videoreviewui.h"
#include <QStyleOption>
#include <QPainter>
#include <QDate>
#include <QDebug>

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

    //顶部
        //@.按键
    videoInfoBtn = new QPushButton(tr("录像下载"));
    videoInfoBtn->setProperty("valid", true);
    videoInfoBtn->setStyleSheet(".QPushButton{border: 2px solid white; border-right:none;\
                                             border-top-left-radius: 10px; border-bottom-left-radius: 10px;\
                                             background-color: transparent; color: white; height: 46px; width: 137px; font:21px}\
                                 .QPushButton[valid=true]{background-color: #649bf1;}");

    videoPlayBtn = new QPushButton(tr("实时回放"));
    videoPlayBtn->setProperty("valid", false);
    videoPlayBtn->setStyleSheet(".QPushButton{border: 2px solid white; border-left:none;\
                                            border-top-right-radius: 10px; border-bottom-right-radius: 10px;\
                                            background-color: transparent; color: white; height: 46px; width:137px; font:21px}\
                                 .QPushButton[valid=true]{background-color: #649bf1;}");

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
    QLabel *channelLabel = new QLabel(tr("通道"));
    channelLabel->setStyleSheet(".QLabel{font: 21px; color: white; padding: 0px; margin: 0px;}");
    videoChannel = new QComboBox;
    videoChannel->setEditable(false);
    for(int i=0; i< 40; i++){
    videoChannel->addItem("channel1");
    videoChannel->addItem("channel2");
    videoChannel->addItem("channel3");
    }
    videoChannel->setFixedSize(213, 40);
    videoChannel->setStyleSheet(".QComboBox{padding-left: 10px; background-color: transparent; color: white; font: 21px; border: 2px solid white; border-radius: 10px;} \
                                 .QComboBox::down-arrow{width: 20px; height:20px; background: white;} \
                                 .QComboBox::drop-down{border: none; width: 50px;} \
                                 .QComboBox QListView{ \
                                            background-color: #040b17; border: 2px solid white; border-radius: 5px;\
                                            color: white; selection-background-color: #649bf1; margin-top: 1px;}\
                                  .QComboBox QAbstractItemView::item{left: 10px;}\
                                  .QScrollBar::vertical{background: transparent; margin: 0px; width: 10px;}\
                                  .QScrollBar::add-line:vertical{background:transparent; height: 0px; width: 0px;}\
                                  .QScrollBar::sub-line:vertical{background:transparent; height: 0px; width: 0px;}\
                                  .QScrollBar::handle:vertical{background: gray; border-radius:5px; height: 20px;}\
                                 ");

    QHBoxLayout *videoChannelHBoxLayout = new QHBoxLayout;
    videoChannelHBoxLayout->setMargin(0);
    videoChannelHBoxLayout->setSpacing(30);
    videoChannelHBoxLayout->addWidget(channelLabel);
    videoChannelHBoxLayout->addWidget(videoChannel);

        //@.日期
    QLabel *dateLabel = new QLabel(tr("日期"));
    dateLabel->setStyleSheet(".QLabel{font:21px; color: white; padding: 0px; margin: 0px;}");
    videoDate = new QLabel(QDate::currentDate().toString("yyyy-MM-dd"));
    videoDate->setAlignment(Qt::AlignCenter);
    videoDate->setFixedSize(180, 40);
    videoDate->setStyleSheet(".QLabel{font: 21px;color: white; border: 2px solid white; border-radius: 10px;\
                              background-color: transparent; padding: 0px; margin: 0px;}");
    dateBtn = new QPushButton;
    QImage backgroundImage(":/recordImg/resource/recordImg/日历（选中）.png");
    dateBtn->setFixedSize(backgroundImage.size());
    dateBtn->setStyleSheet(tr(".QPushButton{background: transparent url(%1); background-position: center;}").arg(":/recordImg/resource/recordImg/日历（选中）.png"));

    QHBoxLayout *dateHBoxLayout = new QHBoxLayout;
    dateHBoxLayout->setMargin(0);
    dateHBoxLayout->setSpacing(30);
    dateHBoxLayout->addWidget(dateLabel);
    dateHBoxLayout->addWidget(videoDate);
    dateHBoxLayout->addWidget(dateBtn);

        //@.查询
    queryBtn = new QPushButton(tr("查询"));
    queryBtn->setFixedSize(105, 42);
    queryBtn->setStyleSheet(".QPushButton{font: 21px; color: white; border: 2px solid white;border-radius: 10px;background-color: transparent;}");
    connect(queryBtn, SIGNAL(clicked()), SLOT(queryBtnClickedSlot()));

    QHBoxLayout *topHBoxLayout = new QHBoxLayout;
    topHBoxLayout->setMargin(0);
    topHBoxLayout->addLayout(videoChannelHBoxLayout);
    topHBoxLayout->addSpacing(80);
    topHBoxLayout->addLayout(dateHBoxLayout);
    topHBoxLayout->addSpacing(100);
    topHBoxLayout->addWidget(queryBtn);
    topHBoxLayout->addStretch();

    QVBoxLayout *topVBoxLayout = new QVBoxLayout;
    topVBoxLayout->addSpacing(20);
    topVBoxLayout->setSpacing(30);
    topVBoxLayout->addLayout(btnChooseHBoxLayout);
    topVBoxLayout->addLayout(topHBoxLayout);
    topVBoxLayout->addSpacing(20);

    QFrame *topFrame = new QFrame;
    topFrame->setStyleSheet(".QFrame{background-color: #040b17; padding-left: 70px;}");
    topFrame->setLayout(topVBoxLayout);

    //底部
    videoInfoTableUi = new VideoInfoTableUi(QRect(0, 0, 981, 420));
    videoInfoTableUi->setFixedSize(1050, 420);
    videoPlayUi = new VideoPlayUi;
    videoPlayUi->setFixedWidth(1050);
    videoPlayUi->init();

    bottomFrame = new QFrame;
    bottomFrame->setProperty("play", "false");
    bottomFrame->setStyleSheet(".QFrame{background-color: #040b17; padding-left: 70px;} \
                                .QFrame[play=true]{background-color: transparent;}");
    bottomFrameStackedLayout = new QStackedLayout(bottomFrame);
    bottomFrameStackedLayout->setMargin(0);
    bottomFrameStackedLayout->addWidget(videoInfoTableUi);
    bottomFrameStackedLayout->addWidget(videoPlayUi);
    bottomFrameStackedLayout->setCurrentWidget(videoInfoTableUi);

    //总布局
    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->setMargin(0);
    mainVBoxLayout->setSpacing(0);
    mainVBoxLayout->addWidget(topFrame);
    mainVBoxLayout->addWidget(bottomFrame);

    setLayout(mainVBoxLayout);        
}


//按键处理
void VideoReviewUi::btnClickedSlot(QAbstractButton* button)
{
    buttonGroup->button(lastBtnId)->setProperty("valid", false);
    buttonGroup->button(lastBtnId)->style()->polish(buttonGroup->button(lastBtnId));
    button->setProperty("valid", true);
    button->style()->unpolish(button);
    button->style()->polish(button);

    lastBtnId = buttonGroup->id(button);
    if(button == videoInfoBtn){
        videoInfoBtnClickedSlot();
    }else if(button == videoPlayBtn){
        videoPlayBtnClickedSlot();
    }
}

//录像信息界面
void VideoReviewUi::videoInfoBtnClickedSlot()
{
    bottomFrameStackedLayout->setCurrentWidget(videoInfoTableUi);
}

//录像播放界面
void VideoReviewUi::videoPlayBtnClickedSlot()
{
    bottomFrameStackedLayout->setCurrentWidget(videoPlayUi);
}

//查询按键
void VideoReviewUi::queryBtnClickedSlot()
{
    qDebug() << "查询";
}

