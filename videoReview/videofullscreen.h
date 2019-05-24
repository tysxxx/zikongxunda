#ifndef VIDEOFULLSCREEN_H
#define VIDEOFULLSCREEN_H

#include <QWidget>
#include <QPushButton>

class VideoFullScreen : public QWidget
{
    Q_OBJECT
public:
    explicit VideoFullScreen(QWidget *parent = 0);

    void init();
signals:
    void exitFullScreenSignal();
public slots:

private:
    QPushButton *exitButton;
};

#endif // VIDEOFULLSCREEN_H
