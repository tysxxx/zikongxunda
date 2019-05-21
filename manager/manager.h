#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QSharedPointer>
#include "hisiInterface/hisiinterface.h"
#include "common/common.h"
#include "network/networkmanager.h"

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

    void login(QString &name, QString &password);
    void logout();   
signals:
    void layoutSwitchChanged(LayoutMode layoutMode);
    void loadUserInteractList(groupListType &group, categoryListType &groupCategory, userListType &user);
    void loadGroupInteractList(intercomListType &intercom);
    void loadMeetingList(meetingListType &meeting);
public slots:
    void allListInfoHandler();
private:
    //Q_DISABLE_COPY(Manager)
    static QSharedPointer<Manager> m_instance;
    HisiDeviceInfoType hisiDeviceInfo;

    NetworkManager networkManager;
};

#endif // MANAGER_H
