#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QSharedPointer>
#include "hisiInterface/hisiinterface.h"
#include "common/common.h"

class Manager : public QObject
{
    Q_OBJECT

public:
    explicit Manager(QObject *parent = 0);
    ~Manager();

    static void destroyInstance(Manager * instance);
    static QSharedPointer<Manager> instance();
    void init();

    void localVideoWinShow(qint8 row, qint8 column, QVector<LayoutWindowInfoType> &winInfo);
    void setLayoutWindowInfo();
signals:
    void layoutSwitchChanged(LayoutMode layoutMode);
public slots:

private:
    //Q_DISABLE_COPY(Manager)
    static QSharedPointer<Manager> m_instance;
    HisiDeviceInfoType hisiDeviceInfo;
};

#endif // MANAGER_H
