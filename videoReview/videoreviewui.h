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
#include "videoplayui.h"
#include "videoinfotableui.h"

class VideoReviewUi : public QWidget
{
    Q_OBJECT
public:
    explicit VideoReviewUi(QRect rect, QWidget *parent = nullptr);
    ~VideoReviewUi();

    void init();
    void paintEvent(QPaintEvent *);
signals:

private slots:
    void videoInfoBtnClickedSlot();
    void videoPlayBtnClickedSlot();
    void btnClickedSlot(QAbstractButton* button);
    void queryBtnClickedSlot();
private:
    QPushButton *videoInfoBtn;
    QPushButton *videoPlayBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
    QComboBox *videoChannel;
    QLabel *videoDate;
    QPushButton *dateBtn;
    QPushButton *queryBtn;

    VideoInfoTableUi *videoInfoTableUi;
    VideoPlayUi *videoPlayUi;
    QStackedLayout *bottomFrameStackedLayout;
};

#endif // VIDEOREVIEWUI_H
