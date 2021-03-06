#include "videoreviewui.h"
#include <QStyleOption>
#include <QPainter>
#include <QDate>
#include <QDebug>
#include <QTextCharFormat>

VideoReviewUi::VideoReviewUi(QRect rect, QWidget *parent) : QWidget(parent)
{
    resize(rect.width(), rect.height());
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
    connect(videoChannel, SIGNAL(activated(int)), this, SLOT(videoChannelChanged(int)));
    for(int i=0; i< 40; i++){
    videoChannel->addItem("channel1", "hello");
    videoChannel->addItem("channel2", "world");
    videoChannel->addItem("channel3", "!!!");
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
    connect(dateBtn, SIGNAL(clicked()), this, SLOT(dateBtnClickedSlot()));

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
    bottomFrame = new QFrame;
    bottomFrame->setFixedWidth(width());
    bottomFrame->setProperty("play", "false");
    bottomFrame->setStyleSheet(".QFrame{background-color: #040b17; padding-left: 70px;} \
                                .QFrame[play=true]{background-color: transparent;}");

    videoInfoTableUi = new VideoInfoTableUi(QRect(0, 0, 981, 420));
    videoInfoTableUi->setFixedSize(1050, 420);

    videoPlayUi = new VideoPlayUi;
    videoPlayUi->setFixedWidth(bottomFrame->width());
    videoPlayUi->init();

    bottomFrameStackedLayout = new QStackedLayout(bottomFrame);
    bottomFrameStackedLayout->setMargin(0);
    bottomFrameStackedLayout->addWidget(videoInfoTableUi);
    bottomFrameStackedLayout->addWidget(videoPlayUi);
    bottomFrameStackedLayout->setCurrentWidget(videoInfoTableUi);

    //总布局
    QVBoxLayout *mainVBoxLayout = new QVBoxLayout(this);
    mainVBoxLayout->setMargin(0);
    mainVBoxLayout->setSpacing(0);
    mainVBoxLayout->addWidget(topFrame);
    mainVBoxLayout->addWidget(bottomFrame);

    //
    manager = Manager::instance();
    connect(manager.data(), SIGNAL(updateVideoChannel(QList<DEVICEINFO_S>&)), this, SLOT(setVideoChannel(QList<DEVICEINFO_S>&)));

    connect(videoInfoTableUi, SIGNAL(playSingleVideoFile(QString)), this, SLOT(playSingleVideoFile(QString)));
    connect(videoPlayUi, SIGNAL(videoFullScreenSignal()), SLOT(videoPlayFullScreen()));
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
    qDebug() << "查询" << videoChannel->count() << videoChannel->currentIndex();

    //查询文件列表
    if(!videoChannel->currentText().isEmpty()){
        QMap<QString, QVariant> deviceInfoMap = videoChannel->itemData(videoChannel->currentIndex()).toMap();
        INPUT_DEV_TYPE_E type = static_cast<INPUT_DEV_TYPE_E>(deviceInfoMap["type"].toInt());
        //list<FILE_PROPERTY_ST> fileList;

        qDebug() << "type:" << type << deviceInfoMap["id"].toInt() << videoDate->text().toUtf8().data();
        zkCarDevEngine::instance()->zkGetMp4FileList(type, deviceInfoMap["id"].toInt(),
                                    videoDate->text().toUtf8().data(), &videoFileList);

       QList<FILE_PROPERTY_ST> videoFileListTmp = QList<FILE_PROPERTY_ST>::fromStdList(videoFileList);

        if(videoFileListTmp.size())
        {
            //清空列表
            videoInfoTableUi->clearContents();
            qint32 rowCount = videoInfoTableUi->rowCount();
            for(qint32 i = 0; i < rowCount; i++)
                videoInfoTableUi->removeRow(0);
        }

        //更新表格文件信息
        for(auto fileInfo: videoFileListTmp){
            qDebug() << "fileName" << fileInfo.fileName;
            videoInfoTableUi->appendOneRow(QString(fileInfo.fileName), fileInfo.size,
                                           QString(fileInfo.time), QString::number(fileInfo.cnt));
        }
    }
}

//日期选择按键
void VideoReviewUi::dateBtnClickedSlot()
{
    if(calender){
        calender->close();
    }else{
        //QDate date = QDate::fromString(videoDate->text(), "yyyy-MM-dd");

        QPoint point = dateBtn->mapToGlobal(QPoint(dateBtn->rect().x(), dateBtn->rect().y()));
        QRect calenderRect = QRect(point.x()+dateBtn->size().width(),
                               point.y()+dateBtn->size().height()+25,
                               320,
                               300);
        //日历
        calender = new QCalendarWidget;
        calender->setGeometry(calenderRect);
        calender->setAttribute(Qt::WA_DeleteOnClose);
        connect(calender.data(), SIGNAL(clicked(QDate)), this, SLOT(setVideoDate(QDate)));
//        QTextCharFormat format;
//        format = calender->dateTextFormat(date);
//        calender->setDateTextFormat(date, format);
        calender->show();
    }
}

//设置查询的日期
void VideoReviewUi::setVideoDate(const QDate &date)
{
    videoDate->setText(date.toString("yyyy-MM-dd"));
}


//设置本地视频的通道名称
void VideoReviewUi::setVideoChannel(QList<DEVICEINFO_S> &localVideoDeviceList)
{
    qDebug() << "setVideoChannel";
    //删除
    if(localVideoDeviceList.size())
        videoChannel->clear();

    //更新
    for(auto device: localVideoDeviceList){
        QMap<QString, QVariant> deviceInfoMap;
        deviceInfoMap["id"] = device.devId;
        deviceInfoMap["name"] = device.devName;
        deviceInfoMap["status"] = device.devStatu;
        deviceInfoMap["type"] = device.devType;
        videoChannel->addItem(deviceInfoMap["name"].toString(), deviceInfoMap);
    }
}

//选择不同的通道视频
void VideoReviewUi::videoChannelChanged(int index)
{
    qDebug() << "vidoe channel changed: " << videoChannel->itemData(index);
}

//选择播放视频文件
void VideoReviewUi::playSingleVideoFile(QString fileName)
{
    qDebug() << "fileName: " << fileName;

    //切换到视频播放的界面
    videoPlayBtnClickedSlot();
    videoPlayUi->setVideoPlayStatus(true);
    videoPlayUi->setVideoPlayMode(VideoPlayUi::PlayMode::singleFilePlay);

    RECT_ST rect;
    rect.s32X = videoPlayUi->videoPlayShowArea().x();
    rect.s32Y = videoPlayUi->videoPlayShowArea().y();
    rect.u32Width = videoPlayUi->videoPlayShowArea().width();
    rect.u32Height = videoPlayUi->videoPlayShowArea().height();

    if(rect.s32X%2 !=0 ) rect.s32X--;
    if(rect.s32Y%2 !=0 ) rect.s32Y--;
    if(rect.u32Width%2 !=0) rect.u32Width--;
    if(rect.u32Height%2 !=0) rect.u32Height--;

    qDebug() << "area: " << videoPlayUi->videoPlayShowArea() << QRect(rect.s32X, rect.s32Y, rect.u32Width, rect.u32Height);
    zkCarDevEngine::instance()->zkStartMediaPlayer(2, &rect);
    zkCarDevEngine::instance()->zkPlayMedia(fileName.toUtf8().data());
}

//播放多文件
void VideoReviewUi::playMultVideoFiles()
{
    if(bottomFrameStackedLayout->currentWidget() == videoPlayUi){
        zkCarDevEngine::instance()->zkPlayMedias(&videoFileList);
        videoPlayUi->setVideoPlayMode(VideoPlayUi::PlayMode::multFilesPlay);
    }
}

//设置全屏播放
void VideoReviewUi::videoPlayFullScreen()
{
    if(videoFullScreenUi)
        return;

    QPoint point(this->rect().x(), this->rect().y());
    point = this->mapToGlobal(point);

    videoFullScreenUi = new VideoFullScreen;
    videoFullScreenUi->setGeometry(point.x(), point.y(), geometry().width(), geometry().height());
    videoFullScreenUi->init();
    connect(videoFullScreenUi, SIGNAL(exitFullScreenSignal()), SLOT(exitVideoPlayFullScreen()));
    videoFullScreenUi->show();
    setVisible(false);

    RECT_ST rect;
    rect.s32X = videoFullScreenUi->geometry().x();
    rect.s32Y = videoFullScreenUi->geometry().y();
    rect.u32Width = videoFullScreenUi->geometry().width();
    rect.u32Height = videoFullScreenUi->geometry().height();
    zkCarDevEngine::instance()->zkStartMediaPlayer(2, &rect);

    //qDebug() << "geometry: " << geometry() << point;
}

//退出全屏
void VideoReviewUi::exitVideoPlayFullScreen()
{
    if(videoFullScreenUi){
        setVisible(true);
        videoFullScreenUi->close();
    }
}
