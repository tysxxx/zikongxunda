#ifndef VIDEOPLAYUI_H
#define VIDEOPLAYUI_H

#include <QWidget>
#include <QRect>
#include <QPushButton>
#include <QProgressBar>

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
    QProgressBar *playProgressBar;
    QPushButton *fullScreenBtn;
};

#endif // VIDEOPLAYUI_H
