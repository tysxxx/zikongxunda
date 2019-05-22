#include "treewidgetitem.h"

TreeWidgetItem::TreeWidgetItem(int type)
    :QTreeWidgetItem(type)
{

}

TreeWidgetItem::TreeWidgetItem(QTreeWidget *parent, int type)
    :QTreeWidgetItem(parent, type)
{

}

TreeWidgetItem::TreeWidgetItem(QTreeWidgetItem *parent, int type)
    :QTreeWidgetItem(parent, type)
{

}


ItemInfoType& TreeWidgetItem::itemInfo()
{
    return m_itemInfo;
}


