#include "listwidgetitem.h"

ListWidgetItem::ListWidgetItem(QListWidget *parent, int type)
    :QListWidgetItem(parent, type) //要调用基类构造函数
{

}

ListWidgetItem::ItemInfoType& ListWidgetItem::itemInfo()
{
    return m_itemInfo;
}

