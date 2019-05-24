#include "videofullscreen.h"
#include <QImage>

VideoFullScreen::VideoFullScreen(QWidget *parent) : QWidget(parent)
{
    //
    setWindowFlags((Qt::FramelessWindowHint));
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);

    QImage image;
    image.load(":/statusLog/resource/icon/退出（选中）.png");
    exitButton = new QPushButton(tr("退出全屏"), this);
    exitButton->setFixedSize(image.size());
    exitButton->setStyleSheet(tr("QPushButton{background: transparent url(%1); color: white; font:21px;}")
                            .arg(":/statusLog/resource/icon/退出（选中）.png"));



    connect(exitButton, SIGNAL(clicked(bool)), SIGNAL(exitFullScreenSignal()));
}


void VideoFullScreen::init()
{
    exitButton->setGeometry(width()-exitButton->width()-20,
                            20,
                            exitButton->width(),
                            exitButton->height());
}

