#ifndef COMMON_H
#define COMMON_H

#include <QtGlobal>

enum class LayoutMode{
        one,
        two,
        four,
        nine,
        sixteen,
};

typedef struct itemInfo{
        qint32 id;
        QString name;
        qint32 groupId;
        qint32 categoryId;
}ItemInfoType;


#endif // COMMON_H

