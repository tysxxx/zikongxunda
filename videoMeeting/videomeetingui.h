#ifndef VIDEOMEETINGUI_H
#define VIDEOMEETINGUI_H

#include <QWidget>
#include <QListWidget>
#include <QListView>
#include <QLabel>
#include <QSharedPointer>
#include <QListWidgetItem>
#include "videomeetinglistitem.h"
#include <QStringList>
#include "meetingModel.h"
#include "manager/manager.h"
#include "listwidgetitem.h"

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
    void loadMeetingList(meetingListType &meeting);
    void itemClickedSlot(QListWidgetItem *item);
private:
    QListView *meetingListView;
    VideoMeetingListItem *meetingListItemDelegete;
    MeetingListModel *meetingListModel;

    QListWidget *meetingListWidget;
    QSharedPointer<Manager> manager;
};

#endif // VIDEOMEETINGUI_H
