#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H

#include <QListWidget>
#include <QListWidgetItem>
#include "network/networkmanager.h"

class ListWidgetItem : public QListWidgetItem
{
public:
    ListWidgetItem(QListWidget *parent=nullptr, int type=UserType+1);

    typedef struct itemInfo{
        qint32 id;
        QString name;
        qint32 groupId;
        qint32 categoryId;
    }ItemInfoType;

    ItemInfoType& itemInfo();
private:
   ItemInfoType m_itemInfo;
};

#endif // LISTWIDGETITEM_H
