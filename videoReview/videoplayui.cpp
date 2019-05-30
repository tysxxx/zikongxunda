#include "videoplayui.h"
#include <QPainter>
#include <QDebug>
#include <QHBoxLayout>
#include <QTransform>
#include <QImage>
#include <QPalette>
#include <QTransform>
#include <QMatrix>

VideoPlayUi::VideoPlayUi(QWidget *parent) : QWidget(parent)
{
}

void VideoPlayUi::init()
{
    //视频显示区域
    videoplaying = false;
    //playArea.setRect((width()-598)/2, 0, 598, 320);
    playArea.setRect(226, 0, 598, 320);
    qDebug() << "width() "<< width() <<"play area" << playArea;

    QImage backgroundImage;
    //按键
        //@播放暂停
    playPauseBtn = new QPushButton;
    playPauseBtn->setToolTip("play");
    backgroundImage.load(":/recordImg/resource/recordImg/暂停（选中）.png");
    playPauseBtn->setFixedSize(backgroundImage.size());
    playPauseBtn->setProperty("playing", "false");
    playPauseBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}\
                                    QPushButton[playing=true]{background-image:url(%2)}\
                                    QPushButton:hover{border: 1px solid white; border-radius: 5px;}")
                                    .arg(":/recordImg/resource/recordImg/暂停（选中）.png")
                                    .arg(":/recordImg/resource/recordImg/播放（选中）.png"));

        //@.快进
    fastForwardBtn = new QPushButton;
    backgroundImage.load(":/recordImg/resource/recordImg/播放（选中）.pngg");
    fastForwardBtn->setFixedSize(backgroundImage.size());
    fastForwardBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/播放（选中）.png"));

        //@.快退
    fastBackwardBtn = new QPushButton;
    QMatrix transfrom;
    transfrom.rotate(-180);
    backgroundImage.load(":/recordImg/resource/recordImg/播放（选中）.png");
    backgroundImage = backgroundImage.transformed(transfrom, Qt::FastTransformation);
    fastBackwardBtn->setFixedSize(backgroundImage.size());
    QPalette palette;
    palette.setBrush(QPalette::Button, QBrush(backgroundImage));
    fastBackwardBtn->setPalette(palette);
    fastBackwardBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px;}"));

        //@.停止
    stopBtn = new QPushButton;
    stopBtn->setToolTip("stop");
    backgroundImage.load(":/recordImg/resource/recordImg/暂停（选中）.png");
    stopBtn->setFixedSize(backgroundImage.size());
    stopBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/暂停（选中）.png"));

        //@.播放进度条
    playProgressBar = new QSlider;
    playProgressBar->setOrientation(Qt::Horizontal);
    playProgressBar->setRange(0, 100);
    playProgressBar->setValue(50);
    playProgressBar->setFixedSize(400, 60);
    playProgressBar->setStyleSheet("\
                     .QSlider{background-color: transparent;}\
                     .QSlider::groove:horizontal{background-color: white; height: 10px; border-radius: 5px;}\
                     .QSlider::handle:horizontal{background-color: #649bf1; border-radius: 10px; width: 20px;\
                                                 margin-top:-5px; margin-bottom: -5px;}\
                     .QSlider::sub-page:horizontal{background-color: #649bf1; border-radius: 5px;}");

        //@.全屏
    fullScreenBtn = new QPushButton;
    backgroundImage.load(":/recordImg/resource/recordImg/全屏（选中）.png");
    fullScreenBtn->setFixedSize(backgroundImage.size());
    fullScreenBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/全屏（选中）.png"));

    QHBoxLayout *btnProgressHBoxLayout = new QHBoxLayout;
    btnProgressHBoxLayout->setMargin(0);
    btnProgressHBoxLayout->setSpacing(1);
    btnProgressHBoxLayout->addWidget(fastBackwardBtn, Qt::AlignHCenter);
    btnProgressHBoxLayout->addWidget(playPauseBtn, Qt::AlignHCenter);
    btnProgressHBoxLayout->addWidget(stopBtn, Qt::AlignHCenter);
    btnProgressHBoxLayout->addWidget(fastForwardBtn, Qt::AlignHCenter);
    btnProgressHBoxLayout->addWidget(playProgressBar, Qt::AlignHCenter);
    btnProgressHBoxLayout->addWidget(fullScreenBtn, Qt::AlignHCenter);

    //视频按键操作区域
    QFrame *playToolFrame = new QFrame(this);
    playToolFrame->setStyleSheet(".QFrame{padding: 0px;}");
    playToolFrame->setLayout(btnProgressHBoxLayout);
    playToolFrame->move(playArea.x(), playArea.y() + playArea.height() + 1);
    playToolFrame->setFixedWidth(playArea.width());

    //视频播放显示区域
    videoPlayShowAreaWiget = new QWidget(this);
    videoPlayShowAreaWiget->setGeometry(playArea);
    //videoPlayShowAreaWiget->setStyleSheet("background-color: gray;");
    qDebug() << "videoPlayShowAreaWiget" << videoPlayShowAreaWiget->geometry();

    //定时器
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), SLOT(timeUpSlot()));
    timer->start(1000);

    connect(playPauseBtn, SIGNAL(clicked(bool)), SLOT(videoPlayPause()));
    connect(stopBtn, SIGNAL(clicked(bool)), SLOT(videoStop()));
    connect(fastForwardBtn, SIGNAL(clicked(bool)), SLOT(videoFastForward()));
    connect(fastBackwardBtn, SIGNAL(clicked(bool)), SLOT(videoBackForward()));
    connect(fullScreenBtn, SIGNAL(clicked(bool)), SLOT(videoFullScreen()));
}


//重载paintEvent事件
void VideoPlayUi::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(videoplaying){
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillRect(playArea, QBrush(Qt::transparent));
        }
    else
        painter.fillRect(playArea, QBrush(Qt::gray));
}

//返回视频显示区域的窗口部件
QWidget& VideoPlayUi::videoShowAreaWiget()
{
    return *videoPlayShowAreaWiget;
}

//返回视频播放的区域
QRect VideoPlayUi::videoPlayShowArea()
{
    QPoint point(videoPlayShowAreaWiget->rect().x(), videoPlayShowAreaWiget->rect().y());
    point = videoPlayShowAreaWiget->mapToGlobal(point);
    qDebug() << "point " << point;
    return QRect(point.x(),
                 point.y(),
                 videoPlayShowAreaWiget->width(),
                 videoPlayShowAreaWiget->height());
}

//视频播放暂停
void VideoPlayUi::videoPlayPause()
{
    qDebug() << "video pause";
    if(videoPlayMode == PlayMode::singleFilePlay)
        zkCarDevEngine::instance()->zkStopPlayMedias();
    else
        zkCarDevEngine::instance()->zkStopPlayMedia();

    setVideoPlayStatus(true);
}

//单个视频停止
void VideoPlayUi::videoStop()
{
    qDebug() << "video stop";
    if(videoPlayMode == PlayMode::singleFilePlay)
        zkCarDevEngine::instance()->zkEndPlayMedias();
    else
        zkCarDevEngine::instance()->zkEndPlayMedia();

    setVideoPlayStatus(false);
}

//单个视频快进
void VideoPlayUi::videoFastForward()
{
    if(videoPlayMode == PlayMode::singleFilePlay)
        zkCarDevEngine::instance()->zkPlayMediasAhead(5);
    else
        zkCarDevEngine::instance()->zkPlayMediaAhead(5);
}

//单个视频快退
void VideoPlayUi::videoBackForward()
{
    if(videoPlayMode == PlayMode::singleFilePlay)
        zkCarDevEngine::instance()->zkPlayMediasBack(5);
    else
        zkCarDevEngine::instance()->zkPlayMediaBack(5);
}

//视频播放时,更新视频播放的进度
void VideoPlayUi::timeUpSlot()
{
   if(videoPlayMode == PlayMode::singleFilePlay){
       quint32 playSec = zkCarDevEngine::instance()->zkGetMediasPlayTime();
       quint32 videoSumPlayTime = 60;
       qint32 value = playSec*100/videoSumPlayTime;
       playProgressBar->setValue(value);
   }else{
       quint32 playSec = zkCarDevEngine::instance()->zkGetMediaPlayTime();
       quint32 videoSumPlayTime = 60;
       qint32 value = playSec*100/videoSumPlayTime;
       playProgressBar->setValue(value);
   }
}

//点击全屏显示
void VideoPlayUi::videoFullScreen()
{
    videoFullScreenSignal();
}

//视频播放状态
void VideoPlayUi::setVideoPlayStatus(bool status)
{
    videoplaying = status;
    update();
}

//视频播放模式: 单文件,多文件
void VideoPlayUi::setVideoPlayMode(PlayMode mode)
{
    videoPlayMode = mode;
}

























