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

    QFrame *playToolFrame = new QFrame(this);
    playToolFrame->setStyleSheet(".QFrame{padding: 0px;}");
    playToolFrame->setLayout(btnProgressHBoxLayout);
    playToolFrame->move(playArea.x(), playArea.y() + playArea.height() + 1);
    playToolFrame->setFixedWidth(playArea.width());
}


//重载paintEvent事件
void VideoPlayUi::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    painter.fillRect(playArea, QBrush(Qt::transparent));
}
