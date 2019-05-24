#ifndef VIDEOPLAYUI_H
#define VIDEOPLAYUI_H

#include <QWidget>
#include <QRect>
#include <QPushButton>
#include <QSlider>
#include <QFrame>
#include <QTimer>
#include "zkCarDevEnginge.h"
#include "zkdevdefine.h"

class VideoPlayUi : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayUi(QWidget *parent = 0);

    void init();
    void paintEvent(QPaintEvent *);

    QRect videoPlayShowArea();
    QWidget& videoShowAreaWiget();
    void setVideoPlayStatus(bool);
signals:
    void videoFullScreenSignal();
public slots:
    void videoPlayPause();
    void videoStop();
    void videoFastForward();
    void videoBackForward();
    void timeUpSlot();
    void videoFullScreen();
private:
    QRect playArea;
    QPushButton *playPauseBtn;
    QPushButton *fastForwardBtn;
    QPushButton *fastBackwardBtn;
    QPushButton *stopBtn;
    QSlider *playProgressBar;
    QPushButton *fullScreenBtn;

    QWidget *videoPlayShowAreaWiget;
    QTimer *timer;

    bool videoplaying = false;
    bool videoPlayMode;  //0:单文件播放 1:多文件播放
private:
};

#endif // VIDEOPLAYUI_H
