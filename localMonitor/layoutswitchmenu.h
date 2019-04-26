#ifndef LAYOUTSWITCHMENU_H
#define LAYOUTSWITCHMENU_H

#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class LayoutSwitchMenu : public QFrame
{
    Q_OBJECT
public:
    LayoutSwitchMenu(QRect rect);

    void init();
    void paintEvent(QPaintEvent *);
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
};

#endif // LAYOUTSWITCHMENU_H
