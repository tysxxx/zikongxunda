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
    void btnClickedSlot(QAbstractButton* button);
private:
    QPushButton *videoInfoBtn;
    QPushButton *videoPlayBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
    QComboBox *videoChannel;
    QLabel *videoDate;
    QPushButton *dateBtn;
    QPushButton *queryBtn;

    QLabel *channelLabel;
};

#endif // VIDEOREVIEWUI_H
