#ifndef LOCALMONITORMENU_H
#define LOCALMONITORMENU_H

#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>

class LocalMonitorMenu : public QFrame
{
    Q_OBJECT
public:
    LocalMonitorMenu(QRect rect);

    void init();
    void paintEvent(QPaintEvent *);
private slots:
    void grapBtnClickedSlot();
    void layoutSwitchBtnClickedSlot();
    void videoRecordBtnClickedSlot();
    void grabDirBtnClickedSlot();
    void videoRecordDirBtnClickedSlot();

    void btnClickedSlot(QAbstractButton* button);
private:
    QPushButton *grabBtn;
    QPushButton *layoutSwitchBtn;
    QPushButton *videoRecordBtn;
    QPushButton *grabDirBtn;
    QPushButton *videoRecordDirBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;
};

#endif // LOCALMONITORMENU_H
