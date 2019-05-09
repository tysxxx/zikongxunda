#ifndef VIDEOPLAYUI_H
#define VIDEOPLAYUI_H

#include <QWidget>
#include <QRect>
#include <QPushButton>
#include <QSlider>
#include <QFrame>

class VideoPlayUi : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayUi(QWidget *parent = 0);

    void init();
    void paintEvent(QPaintEvent *);
signals:

public slots:
private:
    QRect playArea;
    QPushButton *playPauseBtn;
    QPushButton *fastForwardBtn;
    QPushButton *fastBackwardBtn;
    QPushButton *stopBtn;
    QSlider *playProgressBar;
    QPushButton *fullScreenBtn;
};

#endif // VIDEOPLAYUI_H
