#ifndef VIDEOMEETINGUI_H
#define VIDEOMEETINGUI_H

#include <QWidget>
#include <QListWidget>
#include <QListView>
#include <QLabel>
#include "videomeetinglistitem.h"
#include <QStringList>
#include "meetingModel.h"

class VideoMeetingUi : public QWidget
{
    Q_OBJECT
public:
    VideoMeetingUi(QRect rect = QRect(), QWidget *parent = 0);
    ~VideoMeetingUi();

    void init();
    void paintEvent(QPaintEvent *);
signals:

public slots:

private:
    QListView *meetingListView;
    VideoMeetingListItem *meetingListItemDelegete;
    MeetingListModel *meetingListModel;
};

#endif // VIDEOMEETINGUI_H
