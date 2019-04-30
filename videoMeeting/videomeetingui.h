#ifndef VIDEOMEETINGUI_H
#define VIDEOMEETINGUI_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>

class VideoMeetingUi : public QWidget
{
    Q_OBJECT
public:
    explicit VideoMeetingUi(QRect rect, QWidget *parent = 0);
    ~VideoMeetingUi();

    void init();
    void paintEvent(QPaintEvent *);
signals:

public slots:

private:
    QListWidget *meetingList;
};

#endif // VIDEOMEETINGUI_H
