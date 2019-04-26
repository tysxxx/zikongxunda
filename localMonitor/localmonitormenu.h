#ifndef LOCALMONITORMENU_H
#define LOCALMONITORMENU_H

#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QFocusEvent>
#include <QFileDialog>
#include <QScrollArea>
#include "layoutswitchmenu.h"

class LocalMonitorMenu : public QFrame
{
    Q_OBJECT
public:
    LocalMonitorMenu(QRect rect);
    ~LocalMonitorMenu();

    void init();
    void paintEvent(QPaintEvent *);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
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

    LayoutSwitchMenu *layoutSwitchMenu=nullptr;
    QDialog *grabFileWin;

};

#endif // LOCALMONITORMENU_H
