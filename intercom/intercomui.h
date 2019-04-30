#ifndef INTERCOMUI_H
#define INTERCOMUI_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QTreeView>
#include <QTreeWidget>
#include <QListWidget>
#include <QTreeWidgetItem>
#include <QRect>
#include <QStackedLayout>
#include <QLayout>
#include "qflowlayout.h"
#include <QLabel>

class IntercomUi : public QWidget
{
    Q_OBJECT
public:
    explicit IntercomUi(QRect rect, QWidget *parent = nullptr);
    ~IntercomUi();

    void init();
    void paintEvent(QPaintEvent *);
signals:

private slots:
    void btnClickedSlot(QAbstractButton* button);
private:
    QPushButton *userInteractBtn;
    QPushButton *groupInteractBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;

    QTreeWidget *userInteractList;
    QListWidget *groupInteractList;
    QStackedLayout *listStackedLayout;
    QFrame *userIntercomShow;
    QFrame *groupIntercomShow;
    QStackedLayout *intercomShowStackedLayout;

    QFlowLayout *userFlowLayout;
    QFlowLayout *groupFlowLayout;
    QLabel *intercomStatusLabel;
    QPushButton *intercomExitBtn;
};

#endif // INTERCOMUI_H
