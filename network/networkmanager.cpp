#include "networkmanager.h"
#include <QDebug>
#include <QTextCodec>
#include <QFile>

NetworkManager *NetworkManager::NetworkManagerInstance = new NetworkManager();

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
{
    initNetWorkManager();
}

NetworkManager::~NetworkManager()
{
    qDebug() << "~NetworkManager";
}

//创建实例
NetworkManager *NetworkManager::instance()
{
     return NetworkManagerInstance;
}

//销毁实例
void NetworkManager::destroy()
{
    if(NetworkManagerInstance)
        delete NetworkManagerInstance;
    NetworkManagerInstance = nullptr;
}

//初始化
void NetworkManager::initNetWorkManager()
{
    netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished(QNetworkReply *)),this, SLOT(networkReplyFinished(QNetworkReply *)));
    //connect(this, SIGNAL(userLoginStatus(qint8)), SLOT(userLoginStatusHandler(qint8)));//登录状态
}

//用户登录操作
void NetworkManager::login(QString name, QString password)
{
    postGetCategory = PostGetCategory::postUserLogin;

    QUrl url(QString(HTTP_ADDRESS).append(LOGIN_PART_ADDRESS));
    Json::Value user;
    user["name"] = Json::Value(name.toStdString());
    user["password"] = Json::Value(password.toStdString());

    std::string data = user.toStyledString();
    httpPost(url, data);
}

//登录用户退出
void NetworkManager::logout()
{
    postGetCategory = PostGetCategory::postUserLogout;

    QUrl url(QString(HTTP_ADDRESS).append(LOGIN_PART_ADDRESS));
    std::string data = "";
    httpPost(url, data);
}

//查询用户详情
void NetworkManager::getUserDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getUserDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询用户列表
void NetworkManager::getUserListInfoRequest(qint32 page_index, qint32 page_size, qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getUserListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
     httpGet(url);
}

//查询对讲详情
void NetworkManager::getIntercomDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getIntercomDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(USER_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询对讲列表
void NetworkManager::getIntercomListInfoRequest(qint32 page_index, qint32 page_size,
                                     qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getIntercomListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(INTERCOM_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询组织详情
void NetworkManager::getGroupDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getGroupDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询组织列表
void NetworkManager::getGroupListInfoRequest(qint32 page_index, qint32 page_size)
{
    postGetCategory = PostGetCategory::getGroupListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size));*/;
    httpGet(url);
}

//查询组织分类列表
void NetworkManager::getGroupCategoryListInfoRequest(qint32 id, qint32 page_index, qint32 page_size)
{
    postGetCategory = PostGetCategory::getGroupCategoryListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(GROUP_CATEGORY_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id))
            .append(tr("&page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size));*/;
    httpGet(url);
}

//查询会议详情
void NetworkManager::getMeetingDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getMeetingDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(MEETING_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询会议列表
void NetworkManager::getMeetingListInfoRequest(qint32 page_index, qint32 page_size,
                                    qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getMeetingListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(MEETING_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询设备详情
void NetworkManager::getDeviceDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getDeviceDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(DEVICE_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询设备列表
void NetworkManager::getDeviceListInfoRequest(qint32 page_index, qint32 page_size,
                                   qint32 group_id, qint32 group_category_id)
{
    postGetCategory = PostGetCategory::getDeviceListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(DEVICE_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&group_id=%1").arg(group_id))
            .append(tr("&group_category_id=%1").arg(group_category_id));*/;
    httpGet(url);
}

//查询报警详情
void NetworkManager::getAlarmDetailInfoRequest(qint32 id)
{
    postGetCategory = PostGetCategory::getAlarmDetailInfo;
    QUrl url = QString(HTTP_ADDRESS).append(ALARM_DETAIL_PART_ADDRESS)/*.append("?")
            .append(tr("id=%1").arg(id));*/;
    httpGet(url);
}

//查询报警列表
void NetworkManager::getAlarmListInfoRequest(qint32 page_index, qint32 page_size,
                                  qint32 type, quint64 from_time, quint64 to_time)
{
    postGetCategory = PostGetCategory::getAlarmListInfo;
    QUrl url = QString(HTTP_ADDRESS).append(ALARM_LIST_PART_ADDRESS)/*.append("?")
            .append(tr("page_index=%1").arg(page_index))
            .append(tr("&page_size=%1").arg(page_size))
            .append(tr("&type=%1").arg(type))
            .append(tr("&from_time=%1").arg(from_time))
            .append(tr("&to_time=%1").arg(to_time));*/;
    httpGet(url);
}

//查询配置
void NetworkManager::getConfigInfoRequest()
{
    postGetCategory = PostGetCategory::getConfigInfo;
    QUrl url(QString(HTTP_ADDRESS).append(CONFIG_PART_ADDRESS));
    httpGet(url);
}

//http post请求
void NetworkManager::httpPost(QUrl &url, string &str)
{
    QNetworkRequest request;
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Platform", "5");
    request.setRawHeader("Client-Type", "2");

    request.setUrl(QUrl(url));
    netReply = netManager->post(request, QString::fromStdString(str).toUtf8());
    connect(netReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(netReply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(networkReplyError(QNetworkReply::NetworkError)));

}

//http get请求
void NetworkManager::httpGet(QUrl &url)
{
    QNetworkRequest netRequest;
    netRequest.setRawHeader(QString(AUTHORIZATION).toUtf8(), httpRequestHeader.toUtf8());
    netRequest.setUrl(url);

    netReply = netManager->get(netRequest);
    connect(netReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    connect(netReply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
}

//请求错误时错误处理
void NetworkManager::networkReplyError(QNetworkReply::NetworkError error)
{
    qDebug() << "NetworkReply error:" << error;
}

//获取各数据列表.依次获取
void NetworkManager::getListInfo()
{
    switch (postGetCategory) {
        case PostGetCategory::postUserLogin:
             getUserListInfoRequest();
            break;
        case PostGetCategory::getUserListInfo:
            getIntercomListInfoRequest();
           break;
        case PostGetCategory::getIntercomListInfo:
            getGroupListInfoRequest();
            break;
        case PostGetCategory::getGroupListInfo:
            getGroupCategoryListInfoRequest();
           break;
        case PostGetCategory::getGroupCategoryListInfo:
           getMeetingListInfoRequest();
           break;
        case PostGetCategory::getMeetingListInfo:
            getDeviceListInfoRequest();
            break;
        case PostGetCategory::getDeviceListInfo:
            getAlarmListInfoRequest();
            break;
        case PostGetCategory::getAlarmListInfo:
            getConfigInfoRequest();
            break;
        case PostGetCategory::getConfigInfo:
            //jointUserInfo();
            disconnect(this, SIGNAL(getListInfoSuccessed()), this, SLOT(getListInfo()));
            emit userLoginStatus(true);
            break;
        default: break;
    }
}

//reply finish
void NetworkManager::networkReplyFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    reply = nullptr;

    PostGetReplyData.clear(); //清空数据
    emit getListInfoSuccessed();
}

//获取数据的经过
void NetworkManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << "---recv:" <<bytesReceived << "---total:" << bytesTotal;

    //数据量大时，一次接收不完全,需要多次接收
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    PostGetReplyData += reply->read(reply->bytesAvailable());

    //接收完成
    if(bytesReceived == bytesTotal)
    {
        //qDebug() << PostGetReplyData;
        Json::Reader reader;
        Json::Value root;

        std::string totalData = QString::fromUtf8(PostGetReplyData).toStdString();
        if(reader.parse(totalData, root) && !root.isNull()){
            if(root["code"].asInt() == 0) //数据成功,解析数据
                parseJson(root["data"], postGetCategory);
            qDebug() << QString::fromStdString(root["msg"].asString());

            //当登录成功时,获取请求的头信息,以便用于后续的get请求功能
            if(postGetCategory == PostGetCategory::postUserLogin){
                httpRequestHeader = QString(AUTHORIZATION).append(":")+ QString(reply->rawHeader(QString(AUTHORIZATION).toUtf8()));
                connect(this, SIGNAL(getListInfoSuccessed()), this, SLOT(getListInfo()));
            }
        }else{
            qDebug() << QString::fromStdString(reader.getFormatedErrorMessages());
        }
    }
}

//分类解析请求的数据
void NetworkManager::parseJson(Json::Value &jsonValue, PostGetCategory category)
{
    switch (category) {
        case PostGetCategory::postUserLogin:
             parseJsonUserDetailInfo(jsonValue, m_userDetailInfo);
            break;
        case PostGetCategory::postUserLogout:
            break;
        case PostGetCategory::getUserDetailInfo:break;
        case PostGetCategory::getUserListInfo:
            parseJsonUserListInfo(jsonValue, m_userListInfo);
            break;
        case PostGetCategory::getIntercomDetailInfo:break;
        case PostGetCategory::getIntercomListInfo:
            parseJsonIntercomListInfo(jsonValue, m_intercomListInfo);
            break;
        case PostGetCategory::getGroupDetailInfo:break;
        case PostGetCategory::getGroupListInfo:
           parseJsonGroupListInfo(jsonValue, m_groupListInfo);
           break;
        case PostGetCategory::getGroupCategoryListInfo:
           parseJsonGroupCategoryListInfo(jsonValue, m_categoryListInfo);
           break;
        case PostGetCategory::getMeetingDetailInfo:break;
        case PostGetCategory::getMeetingListInfo:
            parseJsonMeetingListInfo(jsonValue, m_meetingListInfo);
            break;
        case PostGetCategory::getDeviceDetailInfo:break;
        case PostGetCategory::getDeviceListInfo:
            parseJsonDeviceListInfo(jsonValue, m_deviceListInfo);
            break;
        case PostGetCategory::getAlarmDetailInfo:break;
        case PostGetCategory::getAlarmListInfo:
            parseJsonAlarmListInfo(jsonValue, m_alarmListInfo);
            break;
        case PostGetCategory::getConfigInfo:
            parseJsonConfigInfo(jsonValue, m_configInfo);
           break;
        default: break;
    }
}

//解析用户详情
void NetworkManager::parseJsonUserDetailInfo(const Json::Value& object, userDetailType& userDetail)
{
    userDetail.id = object["id"].asInt();
    userDetail.nick = QString(object["nick"].asCString());
    userDetail.name = QString(object["name"].asCString());
    userDetail.phone = QString(object["phone"].asCString());
    userDetail.avatar = QString(object["avatar"].asCString());
    userDetail.group_id = object["group_id"].asInt();
    userDetail.group_category_id = object["group_category_id"].asInt();
    userDetail.im_name = QString(object["im_name"].asCString());
    userDetail.im_password = QString(object["im_password"].asCString());
    userDetail.sip_name = QString(object["sip_name"].asCString());
    userDetail.sip_password = QString(object["sip_password"].asCString());
    userDetail.live_id = object["live_id"].asInt();
    userDetail.live_push_url = QString(object["live_push_url"].asCString());
    userDetail.live_play_url = QString(object["live_play_url"].asCString());
    userDetail.live_rtmp_url = QString(object["live_rtmp_url"].asCString());
    userDetail.live_hls_url = QString(object["live_hls_url"].asCString());

    Json::Value jsonArray = object["roles"];
    for(const auto var: jsonArray){
        roleType role;
        role.id = var["id"].asInt();
        role.name = QString(var["name"].asCString());
        role.display_name = QString(var["display_name"].asCString());
        userDetail.roles.append(role);
        //qDebug() << role.display_name << role.name;
    }

    jsonArray = object["permissions"];
    for(const auto var: jsonArray){
        permissionType permisson;
        permisson.id = var["id"].asInt();
        permisson.name = QString(var["name"].asCString());
        permisson.display_name = QString(var["display_name"].asCString());
        userDetail.permissions.append(permisson);
        qDebug() << permisson.display_name << permisson.name;
    }
    qDebug() << "解析用户详情完成";
}

//解析get用户列表
void NetworkManager::parseJsonUserListInfo(const Json::Value& object, userListType& userList)
{
    userList.clear();
    userList.total = object["items"].size();
    //qDebug() << "items size" << userList.total;
    userDetailType userDetail;
    //Json::Value jsonArray = object["items"];
    for(const auto var: object["items"]){
        parseJsonUserDetailInfo(var, userDetail);
        userList.items.append(userDetail);
    }
    qDebug() << "解析用户列表完成";
}

//get解析组织列表
void NetworkManager::parseJsonGroupListInfo(const Json::Value& object, groupListType& groupList)
{
    groupList.clear();
    groupList.total = object["items"].size();
    for(const auto var: object["items"]){
        groupDetailType groupDetail;
        groupDetail.id = var["id"].asInt();
        groupDetail.name = QString::fromStdString(var["name"].asString());
        //groupDetail.created_at = var["created_at"].asInt();
        //groupDetail.updated_at = var["updated_at"].asInt();
        groupList.items.append(groupDetail);
    }
    qDebug() << "解析组织列表完成";
}

//get解析组织分类列表
void NetworkManager::parseJsonGroupCategoryListInfo(const Json::Value& object, categoryListType& categoryList)
{
    categoryList.clear();
    categoryList.total = object["items"].size();
    for(const auto var: object["items"]){
        groupCategoryDetailType groupCategoryDetail;
        groupCategoryDetail.id = var["id"].asInt();
        groupCategoryDetail.name = QString::fromStdString(var["name"].asString());
        groupCategoryDetail.group_id = var["group_id"].asInt();
        groupCategoryDetail.parent_id = var["parent_id"].asInt();
        //groupCategoryDetail.created_at = var["created_at"].asInt();
        //groupCategoryDetail.updated_at = var["updated_at"].asInt();
        categoryList.items.append(groupCategoryDetail);
    }
    qDebug() << "解析组织分类列表完成";
}

//get解析对讲详情
void NetworkManager::parseJsonIntercomDetailInfo(const Json::Value& object, intercomDetaiType& intercomDetail)
{
    intercomDetail.id = object["id"].asInt();
    intercomDetail.name = QString::fromStdString(object["name"].asString());
    intercomDetail.description = QString::fromStdString(object["description"].asString());
    //intercomDetail.created_at = object["created_at"].asInt();
    //intercomDetail.updated_at = object["updated_at"].asInt();
    intercomDetail.group_id = object["group_id"].asInt();
    intercomDetail.group_category_id = object["group_category_id"].asInt();
    //intercomDetail.scene_type_id = object["scene_type_id"].asInt();
    //intercomDetail.im_group_name = QString::fromStdString(object["im_group_name"].asString());

    qDebug() << "解析对讲详情完成";
}

//get解析对讲列表
void NetworkManager::parseJsonIntercomListInfo(const Json::Value& object, intercomListType& intercomList)
{
    intercomList.clear();
    intercomDetaiType intercomDetail;
    intercomList.total = object["items"].size();
    for(const auto var: object["items"])
    {
        parseJsonIntercomDetailInfo(var, intercomDetail);
        intercomList.items.append(intercomDetail);
    }

    qDebug() << "解析对讲列表完成";
}

//get解析会议详情
void NetworkManager::parseJsonMeetingDetailInfo(const Json::Value& object, meetingDetailType& meetingDetail)
{
    meetingDetail.id = object["id"].asInt();
    meetingDetail.name = QString(object["name"].asCString());
    //meetingDetail.description = QString(object["description"].asCString());
    //meetingDetail.created_at = object["created_at"].asInt();
    //meetingDetail.updated_at = object["updated_at"].asInt();
    meetingDetail.group_id = object["group_id"].asInt();
    meetingDetail.group_category_id = object["group_category_id"].asInt();
    meetingDetail.im_group_name = QString(object["im_group_name"].asCString());
    //meetingDetail.start_time = object["start_time"].asInt();
    //meetingDetail.end_time = object["end_time"].asInt();
    //meetingDetail.meeting_type_id = object["meeting_type_id"].asInt();
    //meetingDetail.business_type_id = object["business_type_id"].asInt();
    //meetingDetail.scene_type_id = object["scene_type_id"].asInt();
    meetingDetail.group_name = QString(object["group_name"].asCString());

    meetingDetail.video.code = QString::fromStdString(object["video"]["code"].asString());
    //meetingDetail.video.common_name = QString::fromStdString(object["video"]["common_name"].asString());
    meetingDetail.video.im_name = QString::fromStdString(object["video"]["im_name"].asString());
    meetingDetail.video.sip_name = QString::fromStdString(object["video"]["sip_name"].asString());
    meetingDetail.video.camera_id = object["video"]["camera_id"].asInt();
    meetingDetail.video.live_push_url = QString::fromStdString(object["video"]["live_push_url"].asString());
    meetingDetail.video.live_play_url = QString::fromStdString(object["video"]["live_play_url"].asString());
    meetingDetail.video.live_rtmp_url = QString::fromStdString(object["video"]["live_rtmp_url"].asString());
    meetingDetail.video.live_hls_url =  QString::fromStdString(object["video"]["live_hls_url"].asString());
    //meetingDetail.video.protocol_type_id = object["video"]["protocol_type_id"].asInt();
    //meetingDetail.video.video_type_id = object["video"]["video_type_id"].asInt();
    //meetingDetail.video.gb_device_type_id = object["video"]["gb_device_type_id"].asInt();

    //qDebug() << "video" << meetingDetail.video.code;

    if(!object["video"]["gb"].empty()){
        meetingDetail.video.gb.device_id = QString::fromStdString(object["video"]["gb"]["device_id"].asString());
        meetingDetail.video.gb.parent_id = QString::fromStdString(object["video"]["gb"]["parent_id"].asString());
    }

    qDebug() << "解析会议详情完成";
}

//get解析会议列表
void NetworkManager::parseJsonMeetingListInfo(const Json::Value& object, meetingListType& meetingList)
{
    meetingList.clear();
    meetingDetailType meetingDetail;
    meetingList.total = object["items"].size();
    qDebug() << "meeting list size:" << meetingList.total;
    for(const auto var: object["items"])
    {
        parseJsonMeetingDetailInfo(var, meetingDetail);
        meetingList.items.append(meetingDetail);
    }

    qDebug() << "解析会议列表完成";
}

//get解析设备详情
void NetworkManager::parseJsonDeviceDetailInfo(const Json::Value& object, deviceDetailType& deviceDetail)
{
    deviceDetail.id = object["id"].asInt();
    deviceDetail.code = QString(object["code"].asCString());
    deviceDetail.name = QString(object["name"].asCString());
    deviceDetail.is_active = object["is_active"].asBool();
    //deviceDetail.created_at = object["created_at"].asInt();
    //deviceDetail.updated_at = object["updated_at"].asInt();
    deviceDetail.device_type_id = object["device_type_id"].asInt();
    deviceDetail.device_type_name = QString(object["device_type_name"].asCString());
    deviceDetail.protocol_type_id = object["protocol_type_id"].asInt();
    deviceDetail.protocol_type_name = QString(object["protocol_type_name"].asCString());
    for(const auto var: object["group_ids"])
        deviceDetail.group_ids.append(var.asInt());
    for(const auto var: object["group_category_ids"])
        deviceDetail.group_category_ids.append(var.asInt());
    //deviceDetail.common_name = QString(object["common_name"].asCString());
    //deviceDetail.common_password = QString(object["common_password"].asCString());
    deviceDetail.im_name = QString(object["im_name"].asCString());
    deviceDetail.im_password = QString(object["im_password"].asCString());
    deviceDetail.sip_name = QString(object["sip_name"].asCString());
    deviceDetail.sip_password = QString(object["sip_password"].asCString());
    deviceDetail.live_id = QString(object["live_id"].asCString());
    deviceDetail.live_push_url = QString(object["live_push_url"].asCString());
    deviceDetail.live_play_url = QString(object["live_play_url"].asCString());
    deviceDetail.live_rtmp_url = QString(object["live_rtmp_url"].asCString());
    deviceDetail.live_hls_url = QString(object["live_hls_url"].asCString());
    //deviceDetail.longitude = object["longitude"].asDouble();
    //deviceDetail.latitude = object["latitude"].asDouble();
    //deviceDetail.address = QString(object["address"].asCString());
    deviceDetail.camera_id = object["camera_id"].asInt();
    deviceDetail.is_online = object["is_online"].asInt();
    //deviceDetail.show_location = object["show_location"].asInt();
    deviceDetail.gb_device_type_id = object["gb_device_type_id"].asInt();
    if(!object["gb"].empty()){
        deviceDetail.gb.device_id = QString::fromStdString(object["gb"]["device_id"].asString());
        deviceDetail.gb.parent_id = QString::fromStdString(object["gb"]["parent_id"].asString());
    }
    deviceDetail.group_names = QString(object["group_names"].asCString());
    //deviceDetail.ext_live_play = QString(object["ext_live_play"].asCString());
    //deviceDetail.video_type_name = QString(object["video_type_name"].asCString());

    qDebug() << "解析设备详情完成";
}

//get解析设备列表
void NetworkManager::parseJsonDeviceListInfo(const Json::Value& object, deviceListType& deviceList)
{
    deviceList.clear();
    deviceDetailType deviceDetail;
    deviceList.total = object["items"].size();
    for(const auto var: object["items"]){
        parseJsonDeviceDetailInfo(var, deviceDetail);
        deviceList.items.append(deviceDetail);
    }

    qDebug() << "解析设备列表完成";
}

//get解析报警详情
void NetworkManager::parseJsonAlarmDetailInfo(const Json::Value& object, alarmDetailType& alarmDetail)
{
    alarmDetail.id = object["id"].asInt();
    alarmDetail.platform = object["platform"].asInt();
    alarmDetail.platform_name = QString(object["platform_name"].asCString());
    alarmDetail.type = object["type"].asInt();
    alarmDetail.is_active = object["is_active"].asBool();
    alarmDetail.type_name = QString(object["type_name"].asCString());
    alarmDetail.reporting_mode_id = object["reporting_mode_id"].asInt();
    alarmDetail.reporting_mode_name = QString(object["reporting_mode_name"].asCString());
    for(const auto var: object["photos"]){
        alarmPhotoType photo;
        photo.photoName = QString::fromStdString(var.asString());
        alarmDetail.photos.append(photo);
    }
    //alarmDetail.common_name = QString(object["common_name"].asCString());
    //alarmDetail.name = QString(object["name"].asCString());
    //alarmDetail.code = QString(object["code"].asCString());
    //alarmDetail.published_at = object["published_at"].asInt();
    alarmDetail.address = QString(object["address"].asCString());
    alarmDetail.message = QString(object["message"].asCString());
    //alarmDetail.content.camera_id = object["camera_id"]["camera_id"].asInt();
    //alarmDetail.content.camera_ip = QString::fromStdString(object["camera_ip"]["camera_ip"].asString());
    //alarmDetail.content.camera_location = QString::fromStdString(object["camera_location"]["camera_location"].asString());
    //alarmDetail.content.rule = object["content"]["rule"].asInt();
    //alarmDetail.content.direction = object["content"]["direction"].asInt();
    alarmDetail.url = QString(object["url"].asCString());
    alarmDetail.im_group_name = QString(object["im_group_name"].asCString());
    //alarmDetail.concluded = object["concluded"].asBool();
    //alarmDetail.scene = QString(object["scene"].asCString());
    //alarmDetail.basic = QString(object["basic"].asCString());
    //alarmDetail.evidence = QString(object["evidence"].asCString());
    //alarmDetail.analysis = QString(object["analysis"].asCString());
    //alarmDetail.investigation_no = object["investigation_no"].asInt();
    qDebug() << "解析报警详情完成";
}

//get解析报警列表
void NetworkManager::parseJsonAlarmListInfo(const Json::Value& object, alarmListType& alarmList)
{
    alarmList.clear();
    alarmDetailType alarmDetail;
    alarmList.total = object["items"].size();
    for(const auto var: object["items"]){
        parseJsonAlarmDetailInfo(var, alarmDetail);
        alarmList.items.append(alarmDetail);
    }

    qDebug() << "解析报警列表完成";
}

//解析获取配置信息
void NetworkManager::parseJsonConfigInfo(const Json::Value& object, ConfigType& configDetail)
{
    configDetail.enable_sip = object["enable_sip"].asBool();
    configDetail.enable_agora = object["enable_agora"].asBool();
    configDetail.http_api_host = QString(object["http_api_host"].asCString());
    configDetail.http_api_port = object["http_api_port"].asInt();
    configDetail.https_api_host = QString(object["https_api_host"].asCString());
    configDetail.https_api_port = object["https_api_port"].asInt();
    configDetail.im_host = QString(object["im_host"].asCString());
    configDetail.im_port = object["im_port"].asInt();
    configDetail.sip_host = QString(object["sip_host"].asCString());
    configDetail.sip_port = object["sip_port"].asInt();
    configDetail.file_host = QString(object["file_host"].asCString());
    configDetail.file_port = object["file_port"].asInt();
    configDetail.ftp_host = QString(object["ftp_host"].asCString());
    configDetail.ftp_port = object["ftp_port"].asInt();
    configDetail.ftp_name = QString(object["ftp_name"].asCString());
    configDetail.ftp_pass = QString(object["ftp_pass"].asCString());
    configDetail.map_host = QString(object["map_host"].asCString());
    configDetail.map_port = object["map_port"].asInt();
    configDetail.templet_host = QString(object["templet_host"].asCString());
    configDetail.templet_port = object["templet_port"].asInt();
    configDetail.help_url = QString(object["help_url"].asCString());
    configDetail.treaty_url = QString(object["treaty_url"].asCString());
    configDetail.download_url = QString(object["download_url"].asCString());
    //configDetail.android_update
    //configDetail.ios_update;
    qDebug() << "解析配置详情完成";
}

////拼接用户信息
//void NetworkManager::jointUserInfo()
//{
//    m_groupListNode.total = 0;
//    m_groupListNode.groups.clear();

//    //所有组
//    QVector<groupNodeType> groupNodeVector;
//    for(int groupIndex=0; groupIndex < m_groupList.items.size(); groupIndex++){
//        groupDetailType data = m_groupList.items.at(groupIndex);
//        groupNodeType groupNode;
//        groupNode.id = data.id;
//        groupNode.name = data.name;
//        groupNodeVector.append(groupNode);
//    }

//    //所有分组
//    //QVector<categoryNodeType> *categoryNodeVector = new QVector<categoryNodeType>;
//    QVector<categoryNodeType> categoryNodeVector;
//    for(int categoryIndex=0; categoryIndex < m_categoryList.items.size(); categoryIndex++){
//        groupCategoryDetailType data = m_categoryList.items.at(categoryIndex);
//        categoryNodeType categoryNode;
//        categoryNode.id = data.id;
//        categoryNode.name = data.name;
//        categoryNode.groupid = data.group_id;
//        categoryNode.parentid = data.parent_id;
//        categoryNodeVector.append(categoryNode);
//    }

//    //所有用户
//    QVector<userNodeType> userNodeVector;// = new QVector<userNodeType>;
//    for(int userIndex=0; userIndex < m_userList.items.size(); userIndex++){
//        userDetailType data = m_userList.items.at(userIndex);
//        userNodeType userNode;
//        userNode.id = data.id;
//        userNode.name = data.name;
//        userNode.categoryid = data.group_category_id;
//        userNode.groupid = data.group_id;
//        userNodeVector.append(userNode);
//    }

//    //所有对讲
////    QVector<intercomNodeType> *intercomNodeVector = new QVector<intercomNodeType>;
////    qDebug() << "m_intercomList size=" << m_intercomList.items.size();
////    for(int intercomIndex=0; intercomIndex < m_intercomList.items.size(); intercomIndex++){
////        intercomDetaiType data = m_intercomList.items.at(intercomIndex);
////        intercomNodeType intercomNode; //将详细信息中的关键信息赋予节点信息中.
////        intercomNode.id = data.id;
////        intercomNode.name = data.name;
////        intercomNode.categoryid = data.group_category_id;
////        intercomNode.groupid = data.group_id;
////        intercomNodeVector->append(intercomNode);
////    }

//    //所有会议
////    QVector<meetingNodeType> *meetingNodeVector = new QVector<meetingNodeType>;
////    qDebug() << "m_meetingList size=" << m_meetingList.items.size();
////    for(int meetingIndex=0; meetingIndex < m_meetingList.items.size(); meetingIndex++){
////        meetingDetailType data = m_meetingList.items.at(meetingIndex);
////        meetingNodeType meetingNode; //将详细信息中的关键信息赋予节点信息中.
////        meetingNode.id = data.id;
////        meetingNode.name = data.name;
////        meetingNode.categoryid = data.group_category_id;
////        meetingNode.groupid = data.group_id;
////        meetingNodeVector->append(meetingNode);
////    }

//    //所有设备
//    QVector<deviceNodeType> deviceNodeVector;// = new QVector<meetingNodeType>;
//    //qDebug() << "m_deviceList size=" << m_deviceList.items.size();
//    for(int deviceIndex=0; deviceIndex < m_deviceList.items.size(); deviceIndex++){
//        deviceDetailType data = m_deviceList.items.at(deviceIndex);
//        deviceNodeType deviceNode; //将详细信息中的关键信息赋予节点信息中.
//        deviceNode.id = data.id;
//        deviceNode.name = data.name;
//        //qDebug() << "group_ids.size()=" << data.group_ids.size();
//        for(int i=0; i<data.group_ids.size(); i++){
//            //qDebug() << "data.group_ids.at(i)=" << data.group_ids.at(i);
//            deviceNode.groupid.append(data.group_ids.at(i));
//        }
//        for(int i=0; i<data.group_category_ids.size(); i++){
//            deviceNode.categoryid.append(data.group_category_ids.at(i));
//        }
//        deviceNodeVector.append(deviceNode);
//    }

//    for(int categoryIndex=0; categoryIndex < categoryNodeVector.size(); categoryIndex++){
//        //用户放入分组里面
//        //QVector<categoryNodeType>::Iterator categoryNodePtr = &categoryNodeVector->data()[categoryIndex];
//        categoryNodeType *categoryNodePtr= &categoryNodeVector.data()[categoryIndex];
//        for(int userIndex=0; userIndex < userNodeVector.size(); userIndex++)
//        {
//            userNodeType *userNodePtr = &userNodeVector.data()[userIndex];
//            if(userNodePtr->groupid == categoryNodePtr->groupid
//            && userNodePtr->categoryid == categoryNodePtr->id)
//            {
//                categoryNodePtr->users.append(userNodePtr);
//                //userNodeVector->remove(userIndex);
//            }
//        }

//        //对讲放入分组
////        for(int intercomIndex=0; intercomIndex < intercomNodeVector->size(); intercomIndex++)
////        {
////            intercomNodeType *intercomNodePtr = &intercomNodeVector->data()[intercomIndex];
////            if(intercomNodePtr->groupid == categoryNodePtr->groupid
////            && intercomNodePtr->categoryid == categoryNodePtr->id)
////            {
////                categoryNodePtr->intercoms.append(intercomNodePtr);
////            }
////        }

//        //会议放入分组中
////        qDebug() << "meetingNodeVector size=" << meetingNodeVector->size();
////        for(int meetingIndex=0; meetingIndex < meetingNodeVector->size(); meetingIndex++){
////            meetingNodeType *meetingNodePtr = &meetingNodeVector->data()[meetingIndex];
////            if(meetingNodePtr->groupid == categoryNodePtr->groupid
////            && meetingNodePtr->categoryid == categoryNodePtr->id)
////            {
////                categoryNodePtr->meetings.append(meetingNodePtr);
////            }
////        }

//        //设备放入分组里面
//        //qDebug() << "deviceNodeVector size=" << deviceNodeVector.size();
//        for(int deviceIndex=0; deviceIndex < deviceNodeVector.size(); deviceIndex++){
//            deviceNodeType *deviceNodePtr = &deviceNodeVector.data()[deviceIndex];
//            if(deviceNodePtr->groupid.at(0) == categoryNodePtr->groupid
//            && deviceNodePtr->categoryid.at(0) == categoryNodePtr->id)
//            {
//                categoryNodePtr->devices.append(*deviceNodePtr);
//            }
//        }

//        categoryNodePtr = nullptr;
//    }

//    //分组放入分组里面
//    for(int i = 0; i < categoryNodeVector.size(); i++){
//        categoryNodeType *parentPtr = &categoryNodeVector.data()[i];
//        for(int j=i+1; j < categoryNodeVector.size(); j++)
//        {
//           categoryNodeType *childPtr = &categoryNodeVector.data()[j];
//           if(parentPtr->groupid==childPtr->groupid
//              && parentPtr->id == childPtr->parentid)
//           {
//               parentPtr->categorys.append(childPtr);
//           }
//           childPtr = nullptr;
//        }
//        parentPtr = nullptr;
//    }

//    //用户放入组里面，分组放入组里面
////    for(int groupIndex=0; groupIndex < groupNodeVector->size(); groupIndex++){
////        groupNodeType *groupNodePtr = &groupNodeVector->data()[groupIndex];

//    for(int groupIndex=0; groupIndex < groupNodeVector.size(); groupIndex++){
//        groupNodeType *groupNodePtr = &groupNodeVector.data()[groupIndex];

//        //用户放入组里面
//        for(int userIndex=0; userIndex < userNodeVector.size(); userIndex++)
//        {
//            userNodeType *userNodePtr = &userNodeVector.data()[userIndex];
//            if(groupNodePtr->id == userNodePtr->groupid
//                    && userNodePtr->categoryid == 0)
//            {
//               groupNodePtr->users.append(*userNodePtr);
//               //userNodeVector->remove(userIndex);
//            }
//            userNodePtr = nullptr;
//        }

//        //对讲放入组
////        for(int intercomIndex=0; intercomIndex < intercomNodeVector->size(); intercomIndex++)
////        {
////            intercomNodeType *intercomNodePtr = &intercomNodeVector->data()[intercomIndex];
////            if(groupNodePtr->id == intercomNodePtr->groupid
////                    && intercomNodePtr->categoryid == 0)
////            {
////                groupNodePtr->intercoms.append(*intercomNodePtr);
////            }
////        }

//        //会议放入组里面
////        for(int meetingIndex=0; meetingIndex < meetingNodeVector->size(); meetingIndex++)
////        {
////            meetingNodeType *meetingNodePtr = &meetingNodeVector->data()[meetingIndex];
////            if(groupNodePtr->id == meetingNodePtr->groupid
////                    && meetingNodePtr->categoryid == 0)
////            {
////               groupNodePtr->meetings.append(*meetingNodePtr);
////            }
////            meetingNodePtr = nullptr;
////        }

//        //设备放入组里面
//        for(int deviceIndex=0; deviceIndex < deviceNodeVector.size(); deviceIndex++){
//            deviceNodeType *deviceNodePtr = &deviceNodeVector.data()[deviceIndex];
//            if( groupNodePtr->id ==deviceNodePtr->groupid.at(0)
//            && deviceNodePtr->categoryid.at(0) == 0)
//            {
//                groupNodePtr->devices.append(*deviceNodePtr);
//            }
//        }

//        //分组放入组里面
//        for(int categoryIndex=0; categoryIndex < categoryNodeVector.size(); categoryIndex++)
//        {
//            categoryNodeType *categoryNodePtr = &categoryNodeVector.data()[categoryIndex];
//            if(groupNodePtr->id == categoryNodePtr->groupid
//               && categoryNodePtr->parentid == 0)
//            {
//                groupNodePtr->categorys.append(*categoryNodePtr);
//            }
//            categoryNodePtr = nullptr;
//        }

//        m_groupListNode.total++;
//        m_groupListNode.groups.append(*groupNodePtr);
//    }

//    meetingListModel->deleteNode();
//    intercomListModel->deleteNode();
//    userListModel->deleteNode();
//    deviceListModel->deleteNode();

//    createMeetingListNode();
//    createIntercomListNode();
//    dealUserInfo(userListModel);
//    dealUserInfo(deviceListModel);
//    //qDebug() << "@3. m_groupListNode.total=" << m_groupListNode.total;
//}

//void NetworkManager::dealUserInfo(TreeModel *model)
//{
//     Node *rootNode = model->rootNode();
//     Node::nodeInfoType nodeInfo;

//    //qDebug() << "grouplist size:" << m_groupListNode.total;
//    for(int groupIndex=0; groupIndex < m_groupListNode.total; groupIndex++)
//    {
//        groupNodeType groupNode = m_groupListNode.groups.at(groupIndex);
////        qDebug() << "---group name:" << groupNode.name
////                 << "---group id:" << groupNode.id;
////        qDebug() << "---group user size:" << groupNode.users.size();

//        //创建组节点
//        //Node *groupParentNode = model->creatNode(groupNode.name, rootNode);
//        nodeInfo.clear();
//        nodeInfo.nodeType = Node::groupNode;
//        nodeInfo.id = groupNode.id;
//        nodeInfo.name = groupNode.name;
//        Node *groupParentNode = model->creatNode(nodeInfo, rootNode);

//        if(model == userListModel){
//            //组下面的用户节点
//            for(int userindex=0; userindex < groupNode.users.size(); userindex++)
//            {
//                userNodeType userNode = groupNode.users.at(userindex);
////                qDebug() <<"----usergroupid:" << userNode.groupid
////                         <<"-name:" << userNode.name
////                         <<"-id:" << userNode.id;
//                //组下面的用户节点
//                //model->creatNode(userNode.name, groupParentNode);
//                nodeInfo.clear();
//                nodeInfo.nodeType = Node::userNode;
//                nodeInfo.id = userNode.id;
//                nodeInfo.name = userNode.name;
//                nodeInfo.categoryid = userNode.categoryid;
//                nodeInfo.groupid = userNode.groupid;
//                model->creatNode(nodeInfo, groupParentNode);
//            }
//        }

//        /*
//        if(model == intercomListModel){
//            //组下面的对讲节点
//            for(int intercomindex=0; intercomindex < groupNode.intercoms.size(); intercomindex++)
//            {
//                intercomNodeType intercomNode = groupNode.intercoms.at(intercomindex);
//                qDebug() <<"----usergroupid:" << intercomNode.groupid
//                         <<"-name:" << intercomNode.name
//                         <<"-id:" << intercomNode.id;
//                //组下面的用户节点
//                //model->creatNode(userNode.name, groupParentNode);
//                nodeInfo.clear();
//                nodeInfo.nodeType = Node::userNode;
//                nodeInfo.id = intercomNode.id;
//                nodeInfo.name = intercomNode.name;
//                nodeInfo.categoryid = intercomNode.categoryid;
//                nodeInfo.groupid = intercomNode.groupid;
//                model->creatNode(nodeInfo, groupParentNode);
//            }
//        }
//        */
//        /*
//        if(model == meetingListModel){
//            //组下面的会议节点
//            for(int meetingIndex=0; meetingIndex < groupNode.meetings.size(); meetingIndex++)
//            {
//                meetingNodeType meetingNode = groupNode.meetings.at(meetingIndex);
//                qDebug() <<"----meetinggroupid:" << meetingNode.groupid
//                         <<"-name:" << meetingNode.name
//                         <<"-id:" << meetingNode.id;

//                //userListModel->creatNode(meetingNode.name, groupParentNode);
//                //model->creatNode(meetingNode.name, groupParentNode);
//                nodeInfo.clear();
//                nodeInfo.nodeType = Node::userNode;
//                nodeInfo.id = meetingNode.id;
//                nodeInfo.name = meetingNode.name;
//                nodeInfo.categoryid = meetingNode.categoryid;
//                nodeInfo.groupid = meetingNode.groupid;
//                model->creatNode(nodeInfo, groupParentNode);
//            }
//        }
//        */
//        if(model == deviceListModel){
//            //组下面的设备节点
//            for(int deviceIndex=0; deviceIndex < groupNode.devices.size(); deviceIndex++)
//            {
//                deviceNodeType deviceNode = groupNode.devices.at(deviceIndex);
////                qDebug() <<"----devicegroupid:" << deviceNode.groupid.at(0)
////                         <<"-name:" << deviceNode.name
////                         <<"-id:" << deviceNode.id;
//                nodeInfo.clear();
//                nodeInfo.nodeType = Node::userNode;
//                nodeInfo.id = deviceNode.id;
//                nodeInfo.name = deviceNode.name;
//                nodeInfo.categoryid = deviceNode.categoryid.at(0);
//                nodeInfo.groupid = deviceNode.groupid.at(0);
//                model->creatNode(nodeInfo, groupParentNode);
//            }
//        }

//        //组下面的分组节点
//        Node *categoryParentNode = groupParentNode;
//        for(int categoryindex=0; categoryindex < groupNode.categorys.size(); categoryindex++)
//        {
//            categoryNodeType *categorynodePtr = &groupNode.categorys.data()[categoryindex];
//            //分组节点轮训
//            creatCategoryNode(categorynodePtr, categoryParentNode, model);
//        }
//    }

//    qDebug() << "dealUserInfo end";
//}

//void NetworkManager::creatCategoryNode(categoryNodeType *node, Node* parentNode, TreeModel *model)
//{
//    Node::nodeInfoType nodeInfo;
//    categoryNodeType *categoryNodePtr = node;
////    qDebug() << "---categorygroupid" << categoryNodePtr->groupid
////             << "parent id" << categoryNodePtr->parentid
////             <<"category id:" << categoryNodePtr->id
////             << "category name:" << categoryNodePtr->name;

//    //分组节点
//    //Node *categoryParentNode = model->creatNode(categoryNodePtr->name, parentNode);
//    nodeInfo.clear();
//    nodeInfo.nodeType = Node::categoryNode;
//    nodeInfo.id = categoryNodePtr->id;
//    nodeInfo.name = categoryNodePtr->name;
//    nodeInfo.categoryid = categoryNodePtr->id;
//    nodeInfo.groupid = categoryNodePtr->groupid;
//    Node *categoryParentNode = model->creatNode(nodeInfo, parentNode);

//    if(categoryNodePtr->users.size() == 0
//       && categoryNodePtr->categorys.size() == 0){
//        categoryNodePtr = nullptr;
//        return;
//    }

//    if(model == userListModel){
//        //分组下面的用户节点
//        Node *userParentNode=categoryParentNode;
//        for(int i=0; i < categoryNodePtr->users.size(); i++)
//        {
////            qDebug() << "---categoryusercategoryid" << categoryNodePtr->users.at(i)->categoryid
////                     << "---categoryusername:" << categoryNodePtr->users.at(i)->name;
//            nodeInfo.clear();
//            nodeInfo.nodeType = Node::userNode;
//            nodeInfo.id = categoryNodePtr->users.at(i)->id;
//            nodeInfo.name = categoryNodePtr->users.at(i)->name;
//            nodeInfo.categoryid = categoryNodePtr->users.at(i)->categoryid;
//            nodeInfo.groupid = categoryNodePtr->users.at(i)->groupid;
//            model->creatNode(nodeInfo, userParentNode);
//        }
//    }

//    /*
//    if(model == userListModel){
//        //分组下面的对讲节点
//        for(int i=0; i < categoryNodePtr->intercoms.size(); i++)
//        {
//            qDebug() << "---categoryintercomcategoryid" << categoryNodePtr->intercoms.at(i)->categoryid
//                     << "---categoryintercomname:" << categoryNodePtr->intercoms.at(i)->name;
//            //model->creatNode(categoryNodePtr->users.at(i)->name, userParentNode);
//            nodeInfo.clear();
//            nodeInfo.nodeType = Node::userNode;
//            nodeInfo.id = categoryNodePtr->intercoms.at(i)->id;
//            nodeInfo.name = categoryNodePtr->intercoms.at(i)->name;
//            nodeInfo.categoryid = categoryNodePtr->intercoms.at(i)->categoryid;
//            nodeInfo.groupid = categoryNodePtr->intercoms.at(i)->groupid;
//            model->creatNode(nodeInfo, categoryParentNode);
//        }
//    }
//    */
//    /*
//    if(model == meetingListModel){
//        //分组下面的会议节点
//        for(int i=0; i < categoryNodePtr->meetings.size(); i++)
//        {
//            qDebug() << "---category meeting categoryid" << categoryNodePtr->meetings.at(i)->categoryid
//                     << "---category meeting name:" << categoryNodePtr->meetings.at(i)->name;
//            //model->creatNode(categoryNodePtr->meetings.at(i)->name, categoryParentNode);
//            nodeInfo.clear();
//            nodeInfo.nodeType = Node::userNode;
//            nodeInfo.id = categoryNodePtr->meetings.at(i)->id;
//            nodeInfo.name = categoryNodePtr->meetings.at(i)->name;
//            nodeInfo.categoryid = categoryNodePtr->meetings.at(i)->categoryid;
//            nodeInfo.groupid = categoryNodePtr->meetings.at(i)->groupid;
//            model->creatNode(nodeInfo, categoryParentNode);
//        }
//    }
//    */
//    if(model == deviceListModel){
//        //分组下面的设备节点
//        for(int i=0; i < categoryNodePtr->devices.size(); i++)
//        {
////            qDebug() << "---categorydevicecategoryid" << categoryNodePtr->devices.at(i).categoryid.at(0)
////                     << "---categorydevicename:" << categoryNodePtr->devices.at(i).name;

//            nodeInfo.clear();
//            nodeInfo.nodeType = Node::userNode;
//            nodeInfo.id = categoryNodePtr->devices.at(i).id;
//            nodeInfo.name = categoryNodePtr->devices.at(i).name;
//            nodeInfo.categoryid = categoryNodePtr->devices.at(i).categoryid.at(0);
//            nodeInfo.groupid = categoryNodePtr->devices.at(i).groupid.at(0);
//            model->creatNode(nodeInfo, categoryParentNode);
//        }
//    }

//    for(int i=0; i < categoryNodePtr->categorys.size(); i++){
//        categoryNodeType *ptr = categoryNodePtr->categorys.data()[i];
//        creatCategoryNode(ptr, categoryParentNode, model);
//        ptr = nullptr;
//    }
//    categoryNodePtr = nullptr;
//}


////创建会议的列表节点
//void NetworkManager::createMeetingListNode()
//{
//    Node *rootNode = meetingListModel->rootNode();
//    Node::nodeInfoType nodeInfo;
//    for(int i=0; i < m_meetingList.total; i++)
//    {
//        nodeInfo.clear();
//        nodeInfo.nodeType = Node::userNode;
//        nodeInfo.id = m_meetingList.items.at(i).id;
//        nodeInfo.name = m_meetingList.items.at(i).name;
//        nodeInfo.categoryid = m_meetingList.items.at(i).group_category_id;
//        nodeInfo.groupid = m_meetingList.items.at(i).group_id;
//        meetingListModel->creatNode(nodeInfo, rootNode);
//    }
//}

////创建对讲的列表节点
//void NetworkManager::createIntercomListNode()
//{
//    Node *rootNode = intercomListModel->rootNode();
//    Node::nodeInfoType nodeInfo;
//    for(int i=0; i < m_intercomList.total; i++)
//    {
//        nodeInfo.clear();
//        nodeInfo.nodeType = Node::userNode;
//        nodeInfo.id = m_intercomList.items.at(i).id;
//        nodeInfo.name = m_intercomList.items.at(i).name;
//        nodeInfo.categoryid = m_intercomList.items.at(i).group_category_id;
//        nodeInfo.groupid = m_intercomList.items.at(i).group_id;
//        intercomListModel->creatNode(nodeInfo, rootNode);
//    }
//}

////查询列表里面节点信息
//void NetworkManager::querySelectedNodeInfo(QString modelName, Node::nodeInfoType node, qint32 type)
//{
//    if(modelName == "userListModel")
//        queryUserListNodeInfo(node);
//    else if(modelName == "meetingListModel")
//        queryMeetingListNodeInfo(node);
//    else if(modelName == "intercomListModel")
//        queryIntercomListNodeInfo(node);
//    else if(modelName == "deviceListModel")
//        queryDeviceListNodeInfo(node);
//}

////会议列表内查找会议信息
//void NetworkManager::queryMeetingListNodeInfo(Node::nodeInfoType node)
//{
//    meetingDetailType meetingDetail;
//    for(int meetingListIndex=0; meetingListIndex < m_meetingList.total; meetingListIndex++)
//    {
//        meetingDetail = m_meetingList.items.at(meetingListIndex);
//        if(meetingDetail.group_id == node.groupid
//           && meetingDetail.group_category_id ==  node.categoryid
//           && meetingDetail.id == node.id)
//        {

//        }
//    }
//}

////对讲列表里面查找对讲组信息
//void NetworkManager::queryIntercomListNodeInfo(Node::nodeInfoType node)
//{
//    intercomDetaiType intercomDetail;
//    for(int intercomListIndex=0; intercomListIndex < m_intercomList.total; intercomListIndex++)
//    {
//        intercomDetail = m_intercomList.items.at(intercomListIndex);
//        if(intercomDetail.group_id == node.groupid
//           && intercomDetail.group_category_id ==  node.categoryid
//           && intercomDetail.id == node.id)
//        {

//        }
//    }
//}

////用户列表内查找用户信息
//void NetworkManager::queryUserListNodeInfo(Node::nodeInfoType node)
//{
//    userDetailType userDetail;
//    for(int userListIndex=0; userListIndex < m_userList.total; userListIndex++)
//    {
//        userDetail = m_userList.items.at(userListIndex);
//        if(userDetail.group_id == node.groupid
//           && userDetail.group_category_id ==  node.categoryid
//           && userDetail.id == node.id)
//        {

//        }
//    }
//}

////设备列表里面查找设备信息
//void NetworkManager::queryDeviceListNodeInfo(Node::nodeInfoType node)
//{
//    deviceDetailType deviceDetail;
//    for(int deviceListIndex=0; deviceListIndex < m_deviceList.total; deviceListIndex++)
//    {
//        deviceDetail = m_deviceList.items.at(deviceListIndex);
//        if(deviceDetail.group_ids.data()[0] == node.groupid
//           && deviceDetail.group_category_ids.at(0) == node.categoryid
//           && deviceDetail.id == node.id)
//        {

//        }
//    }
//}






