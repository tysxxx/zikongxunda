#ifndef UI_H
#define UI_H

#include <QObject>
#include <QSharedPointer>
#include "mainUI/mainui.h"
#include "localMonitor/localmonitormenu.h"
#include "intercom/intercomui.h"
#include "login/loginui.h"
#include "videoMeeting/videomeetingui.h"
#include "videoReview/videoreviewui.h"
#include "localMonitor/localmonitorui.h"

class UI : public QObject
{
    Q_OBJECT
public:
    explicit UI(QObject *parent = 0);
    ~UI();

    void initUi();
signals:

public slots:

private:
    MainUi *mainUi;
    VideoMeetingUi *videoMeetingUi;
    //electronicMap *MapUi;
    VideoReviewUi *videoReviewUi;
    IntercomUi *intercomUi;
    QStackedLayout *stackedLayout;
    LocalMonitorUi *localMonitorUi;
    QSharedPointer<Manager> manager;
};

#endif // UI_H
