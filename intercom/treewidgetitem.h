#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "common/common.h"

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    TreeWidgetItem(int type=UserType+1);
    TreeWidgetItem(QTreeWidget *parent, int type=UserType+1);
    TreeWidgetItem(QTreeWidgetItem *parent, int type=UserType+1);

    ItemInfoType& itemInfo();
private:
    ItemInfoType m_itemInfo;
};

#endif // TREEWIDGETITEM_H
