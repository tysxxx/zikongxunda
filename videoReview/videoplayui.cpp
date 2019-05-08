#include "videoplayui.h"
#include <QPainter>
#include <QDebug>
#include <QHBoxLayout>

VideoPlayUi::VideoPlayUi(QWidget *parent) : QWidget(parent)
{
}

void VideoPlayUi::init()
{
    //视频显示区域
    playArea.setRect((width()-598)/2, 0, 598, 320);

    QImage backgroundImage;
    //按键
        //@播放暂停
    playPauseBtn = new QPushButton;
    backgroundImage.load(":/recordImg/resource/recordImg/暂停（选中）.png");
    playPauseBtn->setFixedSize(backgroundImage.size());
    playPauseBtn->setProperty("playing", "false");
    playPauseBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}\
                                    QPushButton[playing=true]{background-image:url(%2)}\
                                    QPushButton:hover[border: 1px solid white; border-radius: 5px;}")
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
    backgroundImage.load(":/recordImg/resource/recordImg/播放（选中）.pngg");
    fastBackwardBtn->setFixedSize(backgroundImage.size());
    fastBackwardBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/播放（选中）.png"));

        //@.停止
    stopBtn = new QPushButton;
    backgroundImage.load(":/recordImg/resource/recordImg/播放（选中）.pngg");
    stopBtn->setFixedSize(backgroundImage.size());
    stopBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/播放（选中）.png"));
        //@.播放进度条
    playProgressBar = new QProgressBar;

        //@.全屏
    fullScreenBtn = new QPushButton;
    backgroundImage.load(":/recordImg/resource/recordImg/播放（选中）.pngg");
    fullScreenBtn->setFixedSize(backgroundImage.size());
    fullScreenBtn->setStyleSheet(tr("QPushButton{padding: 0px; margin: 0px; background-image:url(%1); background-color: transparent;}")
                                    .arg(":/recordImg/resource/recordImg/全屏（选中）.png"));

    QHBoxLayout *btnProgressHBoxLayout = new QHBoxLayout;
    btnProgressHBoxLayout->setMargin(0);
    btnProgressHBoxLayout->setSpacing(5);
    btnProgressHBoxLayout->addWidget(fastBackwardBtn);
    btnProgressHBoxLayout->addWidget(playPauseBtn);
    btnProgressHBoxLayout->addWidget(stopBtn);
    btnProgressHBoxLayout->addWidget(fastForwardBtn);
    btnProgressHBoxLayout->addWidget(playProgressBar);
    btnProgressHBoxLayout->addWidget(fullScreenBtn);

   QFrame *playToolFrame = new QFrame(this);
   playToolFrame->setStyleSheet(".QFrame{padding: 0px; border: 1px solid white;}");
   playToolFrame->setLayout(btnProgressHBoxLayout);
   playToolFrame->setGeometry(QRect(playArea.x(),
                                    playArea.y() + playArea.height() + 10,
                                    playArea.width(),
                                    100));

}


//重载paintEvent事件
void VideoPlayUi::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    painter.fillRect(playArea, QBrush(Qt::transparent));
}
