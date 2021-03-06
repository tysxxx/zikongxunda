#ifndef INTERCOMUI_H
#define INTERCOMUI_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QTreeView>
#include <QTreeWidget>
#include <QListWidget>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QRect>
#include <QStackedLayout>
#include <QLayout>
#include <QSharedPointer>
#include "manager/manager.h"
#include "qflowlayout.h"
#include <QLabel>
#include "network/type.h"
#include "treewidgetitem.h"
#include "videoMeeting/listwidgetitem.h"

class IntercomUi : public QWidget
{
    Q_OBJECT
public:
    IntercomUi(QRect rect = QRect(), QWidget *parent = nullptr);
    ~IntercomUi();

    void init();
    void paintEvent(QPaintEvent *);

signals:

private slots:
    void btnClickedSlot(QAbstractButton* button);
    void loadUserInteractList(groupListType &group, categoryListType &groupCategory, userListType &user);
    void loadGroupInteractList(intercomListType &intercom);
    void userInteractItemClickedSlot(QTreeWidgetItem *item, int column);
    void groupInteractItemClickedSlot(QListWidgetItem *item);
private:
    QPushButton *userInteractBtn;
    QPushButton *groupInteractBtn;
    QButtonGroup *buttonGroup;
    int lastBtnId;

    QTreeWidget *userInteractTreeWidget;
    QListWidget *groupInteractListWidget;
    QStackedLayout *listStackedLayout;
    QFrame *userIntercomShow;
    QFrame *groupIntercomShow;
    QStackedLayout *intercomShowStackedLayout;

    QFlowLayout *userFlowLayout;
    QFlowLayout *groupFlowLayout;
    QLabel *intercomStatusLabel;
    QPushButton *intercomExitBtn;

    QSharedPointer<Manager> manager;
};

#endif // INTERCOMUI_H
