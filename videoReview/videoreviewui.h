#ifndef VIDEOREVIEWUI_H
#define VIDEOREVIEWUI_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QStackedLayout>
#include <QTableWidget>
#include <QCalendarWidget>
#include <QPointer>
#include <QDate>
#include <QSharedPointer>
#include "videoplayui.h"
#include "videoinfotableui.h"
#include "hisiInterface/hisiinterface.h"
#include "manager/manager.h"

class VideoReviewUi : public QWidget
{
    Q_OBJECT
public:
    VideoReviewUi(QRect rect = QRect(), QWidget *parent = nullptr);
    ~VideoReviewUi();

    void init();
signals:

private slots:
    void videoInfoBtnClickedSlot();
    void videoPlayBtnClickedSlot();
    void btnClickedSlot(QAbstractButton* button);
    void queryBtnClickedSlot();
    void dateBtnClickedSlot();
    void setVideoDate(const QDate &date);
    void setVideoChannel(QList<DEVICEINFO_S> &localVideoDeviceList);
    void videoChannelChanged(int index);
private:
    QPushButton *videoInfoBtn;
    QPushButton *videoPlayBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
    QComboBox *videoChannel;
    QLabel *videoDate;
    QPushButton *dateBtn;
    QPushButton *queryBtn;
    QPointer<QCalendarWidget> calender;

    VideoInfoTableUi *videoInfoTableUi;
    VideoPlayUi *videoPlayUi;
    QStackedLayout *bottomFrameStackedLayout;
    QFrame *bottomFrame;

    QSharedPointer<Manager> manager;
    QList<FILE_PROPERTY_ST> videoFileList;
};

#endif // VIDEOREVIEWUI_H
