#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H

#include <QListWidget>
#include <QListWidgetItem>
#include "network/networkmanager.h"
#include "common/common.h"

class ListWidgetItem : public QListWidgetItem
{
public:
    ListWidgetItem(QListWidget *parent=nullptr, int type=UserType+1);

    ItemInfoType& itemInfo();
private:
    ItemInfoType m_itemInfo;
};

#endif // LISTWIDGETITEM_H
