#ifndef LAYOUTSWITCHMENU_H
#define LAYOUTSWITCHMENU_H

#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "common/common.h"
#include "manager/manager.h"

class LayoutSwitchMenu : public QFrame
{
    Q_OBJECT
public:
    LayoutSwitchMenu(QRect rect = QRect());

    void init();
    void paintEvent(QPaintEvent *);
signals:
    void layoutSwitchChanged(LayoutMode layoutMode);

private slots:
    void oneBtnClickedSlot();
    void twoBtnClickedSlot();
    void fourBtnClickedSlot();
    void nineBtnClickedSlot();
    void sixteenBtnClickedSlot();
    void btnClickedSlot(QAbstractButton* button);
private:
    QLabel *titleLabel;
    QPushButton *oneBtn;
    QPushButton *twoBtn;
    QPushButton *fourBtn;
    QPushButton *nineBtn;
    QPushButton *sixteenBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;

    QSharedPointer<Manager> manager;
};

#endif // LAYOUTSWITCHMENU_H
