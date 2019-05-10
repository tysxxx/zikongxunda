#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QThread>
#include <QModelIndex>
#include "json/json.h"
#include "type.h"

using namespace std;
//各请求信息的分地址
const QString HTTP_ADDRESS("http://106.14.93.204/api");
const QString LOGIN_PART_ADDRESS("/v1/auth/login");
const QString LOGOUT_PART_ADDRESS("/v1/auth/logout");
const QString USER_DETAIL_PART_ADDRESS("/v1/user/show");
const QString USER_LIST_PART_ADDRESS("/v1/user/index");
const QString INTERCOM_DETAIL_PART_ADDRESS("/v1/intercom/show");
const QString INTERCOM_LIST_PART_ADDRESS("/v1/intercom/index");
const QString GROUP_DETAIL_PART_ADDRESS("/v1/group/show");
const QString GROUP_LIST_PART_ADDRESS("/v1/group/index");
const QString GROUP_CATEGORY_PART_ADDRESS("/v1/group/category/index");
const QString MEETING_DETAIL_PART_ADDRESS("/v1/meeting/show");
const QString MEETING_LIST_PART_ADDRESS("/v1/meeting/index");
const QString DEVICE_DETAIL_PART_ADDRESS("/v1/device/show");
const QString DEVICE_LIST_PART_ADDRESS("/v1/device/index");
const QString ALARM_DETAIL_PART_ADDRESS("/v1/alarm/index");
const QString ALARM_LIST_PART_ADDRESS("/v1/alarm/index");
const QString CONFIG_PART_ADDRESS("/v1/config");

//令牌
const QString AUTHORIZATION("Authorization");


//数据请求类型
enum class PostGetCategory{
    postGetUndefined = 0,
    postUserLogin,
    postUserLogout,
    getUserDetailInfo,
    getUserListInfo,
    getIntercomDetailInfo,
    getIntercomListInfo,
    getGroupDetailInfo,
    getGroupListInfo,
    getGroupCategoryListInfo,
    getMeetingDetailInfo,
    getMeetingListInfo,
    getDeviceDetailInfo,
    getDeviceListInfo,
    getAlarmDetailInfo,
    getAlarmListInfo,
    getConfigInfo,
};

//http json格式时去掉"//u"里面的一个'/'
static inline QString httpReceiveDateHandler(QString string)
{
    do{
        int idx = string.indexOf("\\u");
        QString strHex = string.mid(idx, 6);
        strHex = strHex.replace("\\u", QString());
        int nHex = strHex.toInt(nullptr, 16);
        string.replace(idx, 6, QChar(nHex));
    }while (string.indexOf("\\u") != -1);

    return string;
}

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = nullptr);
    ~NetworkManager();

    static NetworkManager *NetworkManagerInstance;
    void initNetWorkManager();
public:
//    QVariantMap configInfoObject() const;
//    void setConfigInfoObject(QVariantMap configInfoObject);
    static NetworkManager* instance();
    void destroy();
    //post请求
    void login(QString name, QString password);
    void logout();
    //get请求操作
    void getUserDetailInfoRequest(qint32 id = 0);
    void getUserListInfoRequest(qint32 page_index = 0, qint32 page_size = 0, qint32 group_id = 0, qint32 group_category_id = 0);
    void getIntercomDetailInfoRequest(qint32 id = 0);
    void getIntercomListInfoRequest(qint32 page_index = 0, qint32 page_size = 0, qint32 group_id = 0, qint32 group_category_id = 0);
    void getGroupDetailInfoRequest(qint32 id = 0);
    void getGroupListInfoRequest(qint32 page_index = 0, qint32 page_size = 0);
    void getGroupCategoryListInfoRequest(qint32 id = 0, qint32 page_index = 0, qint32 page_size = 0);
    void getMeetingDetailInfoRequest(qint32 id = 0);
    void getMeetingListInfoRequest(qint32 page_index = 0, qint32 page_size = 0, qint32 group_id = 0, qint32 group_category_id = 0);
    void getDeviceDetailInfoRequest(qint32 id = 0);
    void getDeviceListInfoRequest(qint32 page_index = 0, qint32 page_size = 0, qint32 group_id = 0, qint32 group_category_id = 0);
    void getAlarmDetailInfoRequest(qint32 id = 0);
    void getAlarmListInfoRequest(qint32 page_index = 0, qint32 page_size = 0, qint32 type = 0, quint64 from_time = 0, quint64 to_time = 0);
    void getConfigInfoRequest();

    void httpPost(QUrl &url, string &str);
    void httpGet(QUrl &url);
    //解析请求数据
    void parseJson(Json::Value &jsonValue, PostGetCategory category);
    void parseJsonUserDetailInfo(const Json::Value& object, userDetailType& userDetail);
    void parseJsonUserListInfo(const Json::Value& object, userListType& userList);
    void parseJsonGroupListInfo(const Json::Value& object, groupListType& groupList);
    void parseJsonGroupCategoryListInfo(const Json::Value& object, categoryListType& categoryList);
    void parseJsonIntercomDetailInfo(const Json::Value& object, intercomDetaiType& intercomDetail);
    void parseJsonIntercomListInfo(const Json::Value& object, intercomListType& intercomList);
    void parseJsonMeetingDetailInfo(const Json::Value& object, meetingDetailType& meetingDetail);
    void parseJsonMeetingListInfo(const Json::Value& object, meetingListType& meetingList);
    void parseJsonDeviceDetailInfo(const Json::Value& object, deviceDetailType& deviceDetail);
    void parseJsonDeviceListInfo(const Json::Value& object, deviceListType& deviceList);
    void parseJsonAlarmDetailInfo(const Json::Value& object, alarmDetailType& alarmDetail);
    void parseJsonAlarmListInfo(const Json::Value& object, alarmListType& alarmList);
    void parseJsonConfigInfo(const Json::Value& objec, ConfigType& configDetail);

//    void creatCategoryNode(categoryNodeType *node, Node* parentNode, MeetingListModel *model);
//    Q_INVOKABLE void jointUserInfo();

//    void createMeetingListNode();
//    void createIntercomListNode();

//    void queryMeetingListNodeInfo(Node::nodeInfoType node);
//    void queryIntercomListNodeInfo(Node::nodeInfoType node);
//    void queryUserListNodeInfo(Node::nodeInfoType node);
//    void queryDeviceListNodeInfo(Node::nodeInfoType node);
signals:
    void getListInfoSuccessed();
    void userLoginStatus(bool status);
//    void loginUserNameChanged();
//    void loginUserPasswordChanged();
//    void platfromServerAddressChanged();
//    void platfromServerPortChanged();
//    void imServerAddressChanged();
//    void imServerPortChanged();
//    void loginRequestSuccess();
//    void configInfoObjectChanged();
//    void dealUserInfoSignal(MeetingListModel *model);

//    void loginStatus(QString status);
//    void getUserDetailSignal();
//    void getUserListSignal(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id);
//    void getIntercomDetailSignal(qint32 id);
//    void getIntercomListSignal(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id);
//    void getGroupDetailSignal(qint32 id);
//    void getGroupListSignal(qint32 page_index, qint32 page_size);
//    void getGroupCategoryListSignal(qint32 id, qint32 page_index, qint32 page_size);
//    void getMeetingDetailSignal(qint32 id);
//    void getMeetingListSignal(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id);
//    void getDeviceDetailSignal(qint32 id);
//    void getDeviceListSignal(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id);
//    void getAlarmDetailSignal(qint32 id);
//    void getAlarmListSignal(qint32 page_index, qint32 page_size, qint32 type, quint64 from_time, quint64 to_time);
public slots:
    void networkReplyFinished(QNetworkReply *reply);
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void getListInfo();
    void networkReplyError(QNetworkReply::NetworkError error);


//    void dealUserInfo(MeetingListModel *model);
//    void dealUserLogin(QString status);
//    void querySelectedNodeInfo(QString modelName, Node::nodeInfoType node, qint32 type);
private:
    QNetworkAccessManager *netManager = nullptr;
    QNetworkReply *netReply; //不是自己手动分配空间，不需要在析构函数中判断释放
    PostGetCategory postGetCategory; //请求分类

//    QString httpCommonAddress;
    QString httpRequestHeader; //请求数据要求使用的头信息
    QByteArray PostGetReplyData;
//    qint32 m_pageIndex;
//    qint32 m_pageSize;
//    qint32 m_groupID;
//    qint32 m_groupCategoryID;

    userDetailType m_userDetailInfo;
    userListType m_userListInfo;
    categoryListType m_categoryListInfo;
    groupListType m_groupListInfo;
    intercomListType m_intercomListInfo;
    meetingListType m_meetingListInfo;
    deviceListType m_deviceListInfo;
    alarmListType m_alarmListInfo;
    ConfigType m_configInfo;

//    groupListNodeType m_groupListNode;


//    QThread *parseJsonWork;
//    HttpJson *httpJson;
};

#endif // NETWORKMANAGER_H
